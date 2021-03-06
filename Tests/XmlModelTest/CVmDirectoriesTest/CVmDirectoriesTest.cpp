/*
 * @file CVmDirectoriesTest.cpp
 * 
 * Tests fixture class for testing CVmDirectories class functionality
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

#include "CVmDirectoriesTest.h"

#include <QDomDocument>

CVmDirectoriesTest::CVmDirectoriesTest() : m_pVmDirectories(NULL), m_pFile(NULL) {
}

#define INITIALIZE_CONFIG(sConfigFileName)	m_pFile = new QFile(sConfigFileName);\
	QVERIFY(m_pFile->open(QIODevice::ReadOnly));\
	m_pVmDirectories = new CVmDirectories(m_pFile);

void CVmDirectoriesTest::testIsValidOnValidDirectory() {
	INITIALIZE_CONFIG("./CVmDirectoriesTest_valid_vm_dir.xml")
	QCOMPARE(m_pVmDirectories->m_uiRcInit, PRL_ERR_SUCCESS);
}

void CVmDirectoriesTest::testInitializeFromString() {
	QFile _file("./CVmDirectoriesTest_valid_vm_dir.xml");
	QVERIFY(_file.open(QIODevice::ReadOnly));
	QDomDocument _xmldoc;
	QVERIFY(_xmldoc.setContent(&_file));
	_file.close();
	m_pVmDirectories = new CVmDirectories();
	PRL_RESULT rc = m_pVmDirectories->fromString( _xmldoc.toString() );
	QCOMPARE( rc , PRL_ERR_SUCCESS);
	QCOMPARE(m_pVmDirectories->m_uiRcInit, PRL_ERR_SUCCESS);
}

void CVmDirectoriesTest::cleanup() {
	delete m_pVmDirectories;
	m_pVmDirectories = NULL;
	delete m_pFile;
	m_pFile = NULL;
}

QTEST_MAIN(CVmDirectoriesTest)
