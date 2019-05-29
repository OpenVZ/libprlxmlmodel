/*
 * @file CHwFileSystemInfoTest.cpp
 * 
 * Tests fixture class for testing CHwFileSystemInfo class functionality
 * 
 * @author aleksandera
 * 
 * Copyright (c) 2006-2017, Parallels International GmbH
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

#include "CHwFileSystemInfoTest.h"

#include "HostHardwareInfo/CHwFileSystemInfo.h"

void CHwFileSystemInfoTest::testInitializingFromEmptyBuffer() {
	CHwFileSystemInfo _fs_info;
	QVERIFY(_fs_info.fromString(QString()) != HostHwInfoParser::RcSuccess);
	QCOMPARE(size_t(_fs_info.m_lstFileSystemItems.size()), size_t(0));
}

QTEST_MAIN(CHwFileSystemInfoTest)
