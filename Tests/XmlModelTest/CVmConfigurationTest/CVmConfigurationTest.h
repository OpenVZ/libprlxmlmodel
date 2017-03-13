/*
 * @file CVmConfigurationTest.h
 * 
 * Tests fixture class for testing CVmConfiguration class functionality
 * 
 * @author aleksandera
 * 
 * Copyright (c) 2006-2017, Parallels International GmbH
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
 * Our contact details: Parallels International GmbH, Vordergasse 59, 8200
 * Schaffhausen, Switzerland.
 */

#ifndef CVmConfigurationTest_H
#define CVmConfigurationTest_H

#include <QtTest/QtTest>
#include <QFile>
#include "VmConfig/CVmConfiguration.h"
#include "VmConfig/CVaConfig.h"

class CVmConfigurationTest : public QObject {

Q_OBJECT

public:
	CVmConfigurationTest();

private slots:
	void init();
	void cleanup();
	void testIsValidOnValidConfiguration();
	void testIsValidVaConfig();
	void testIsValidOnIdentificationNotPresent();
	void testIsValidOnSettingsNotPresent();
	void testIsValidOnHwInfoNotPresent();
	void testIsValidOnThirdPartyXmlFile();
	void testInitializeFromString();
	void testInitializeFromStringWithXmlns();
	void testFloppyDeviceConvertation();
	void testSharedAppInDockDefaultValue();
	void testEnableSpotlightDefaultValue();
	void testValidateSignalsMech();
	void testValidateMergeMechForField();
	void testValidateMergeMechForList();
	void testValidateRestrictMergeMech();
	void testValidateFixedFieldMergeMech();
	void testThrowOffMilisecondsInTimeFields();
	void testValidateDiffMech();
	void testParallelPortWithOldVmConfig();
	void testSoundComparisonOperator();
	void testConfigureWithDhcpFlagOnPostRead();
	void testPatchMechViaPropertyCall();
	void testAssignOperator();
	void testTransformationDevicesPathsInsideVmBundle();
	void testTransformationDevicesPathsOnExtDir();

private slots:
	void testVmName(QString v);
	void testAutoStop(PRL_VM_AUTOSTOP_OPTION v);

private:

	void testAssignOperatorOptimization();

	CVmConfiguration *m_pVmConfiguration;

	QString m_qsVmName;
	PRL_VM_AUTOSTOP_OPTION m_ctAutoStop;

	// Virtual Appliance configuration
	CVaConfig *m_pVaConfig;
	QFile *m_pFile;

	QString m_qsTestPath;
};

#endif
