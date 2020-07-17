/*
 * @file CVmEventTest.cpp
 * 
 * Tests fixture class for testing CVmEvent class functionality
 * 
 * @author van
 * 
 * Copyright (c) 2005-2017, Parallels International GmbH
 * Copyright (c) 2017-2019 Virtuozzo International GmbH. All rights reserved.
 *
 * This file is part of OpenVZ. OpenVZ is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * Lesser General Public License as published by the Free Software Foundation;
 * either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 * Our contact details: Virtuozzo International GmbH, Vordergasse 59, 8200
 * Schaffhausen, Switzerland.
 */

#include "CVmEventTest.h"

#include <QDomDocument>
#include <prlcommon/PrlUuid/Uuid.h>
#include "VmConfig/CVmConfiguration.h"
#include <prlcommon/Messaging/CVmEventParameter.h>
#include <prlcommon/Logging/Logging.h>
#include <prlcommon/PrlCommonUtilsBase/PrlStringifyConsts.h>

#define CHECK_EVENT_PARAMETER(pEvent, param_name, param_type, param_value)\
	{\
		CVmEventParameter *pParam = pEvent->getEventParameter(param_name);\
		QVERIFY(pParam != NULL);\
		QVERIFY(pParam->getParamType() == param_type);\
		QCOMPARE(param_value, pParam->getParamValue());\
	}

#define CHECK_RET_CODE_EXP(expression)\
	{\
		PRL_RESULT nExprRetCode = (expression);\
		if (PRL_FAILED(nExprRetCode))\
			WRITE_TRACE(DBG_FATAL, "Expression: '%s' nRetCode=%.8X '%s'", #expression, nExprRetCode, PRL_RESULT_TO_STRING(nExprRetCode));\
		QCOMPARE(nExprRetCode, PRL_ERR_SUCCESS);\
	}

CVmEventTest::CVmEventTest()
: m_pVmEvent(NULL)
{}

void CVmEventTest::initializeFromString(const QString &filename)
{
	QFile _file(filename);
	QVERIFY(_file.open(QIODevice::ReadOnly));
	QDomDocument _xmldoc;
	QVERIFY(_xmldoc.setContent(&_file));
	_file.close();
	m_pVmEvent = new CVmEvent();
	m_pVmEvent->fromString(_xmldoc.toString(), QString("VirtuozzoEvent"));
	QCOMPARE(m_pVmEvent->m_uiRcInit, PRL_ERR_SUCCESS);
}

void CVmEventTest::testInitializeFromString()
{
	initializeFromString(QString("./CVmEventTest_valid_vm_event.xml"));
}

void CVmEventTest::testInitializeFromStringWithEventId()
{
	// it should be OK to initialize event with and without EventId element
	initializeFromString(QString("./CVmEventTest_valid_vm_event_with_EventId.xml"));
}

void CVmEventTest::testParseVmEventWithVmConfig()
{
	QFile _file("./CVmConfigurationTest_valid_vm_config.xml");
	QVERIFY(_file.open(QIODevice::ReadOnly));
	CVmConfiguration _vm_conf(&_file);
	QVERIFY(_vm_conf.m_uiRcInit == PRL_ERR_SUCCESS);
	QString req_uuid = Uuid().createUuid().toString();
	QString vmId = Uuid().createUuid().toString();
	m_pVmEvent = new CVmEvent( (PRL_EVENT_TYPE)PVE::DspCmdVmSetConfig, Uuid().toString(), PIE_DISPATCHER,
							   PET_VM_INF_UNINITIALIZED_EVENT_CODE, PVE::EventRespRequired);

	m_pVmEvent->setInitRequestId( req_uuid );
	m_pVmEvent->addEventParameter( new CVmEventParameter( PVE::String, vmId, EVT_PARAM_VM_UUID ) );

	CVmEventParameter* vm_config_param = new CVmEventParameter();
	vm_config_param->setParamType( PVE::VmConfiguration );
	vm_config_param->setParamName( EVT_PARAM_VM_CONFIG );
	vm_config_param->setCdata(_vm_conf.toString());
	m_pVmEvent->addEventParameter( vm_config_param );

	QString request_xml = m_pVmEvent->toString();
	CVmEvent _event(request_xml);
	QVERIFY(_event.m_uiRcInit == PRL_ERR_SUCCESS);
}

void CVmEventTest::cleanup() {
	delete m_pVmEvent;
	m_pVmEvent = NULL;
}

void CVmEventTest::testParseVmEvent1()
{
	initializeFromString(QString("./CVmEventTest_test_data1.xml"));
	QCOMPARE(m_pVmEvent->m_lstEventParameters.size(), 5);
	CHECK_EVENT_PARAMETER(m_pVmEvent, "vm_message", PVE::UnsignedInt, QString("1002"))
	CHECK_EVENT_PARAMETER(m_pVmEvent, "vm_message_choice_0", PVE::UnsignedInt, QString("2002"))
	CHECK_EVENT_PARAMETER(m_pVmEvent, "vm_message_choice_1", PVE::UnsignedInt, QString("2003"))
	CHECK_EVENT_PARAMETER(m_pVmEvent, "vm_message_param_0", PVE::String,\
					QString("C:\\Virtuozzo Virtual Machines\\DOS\\lpt.txt"))
	CHECK_EVENT_PARAMETER(m_pVmEvent, "executive_server", PVE::String, QString("localhost"))
}

QTEST_MAIN(CVmEventTest)
