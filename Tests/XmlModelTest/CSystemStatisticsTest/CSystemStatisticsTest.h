/*
 * @file CSystemStatisticsTest.h
 * 
 * Tests fixture class for testing CSystemStatistics class functionality
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

#ifndef CSystemStatisticsTest_H
#define CSystemStatisticsTest_H

#include <QtTest/QtTest>

class CSystemStatisticsTest : public QObject
{

Q_OBJECT

private slots:
	void testFormingCpusStatistics();
	void testFormingCpusStatisticsBoundValues();
	void testFormingDisksStatistics();
	void testFormingDisksStatisticsBoundValues();
	void testFormingMemoryStatistics();
	void testFormingMemoryStatisticsBoundValues();
	void testFormingSwapStatistics();
	void testFormingSwapStatisticsBoundValues();
	void testFormingUptimeStatistics();
	void testFormingUptimeStatisticsBoundValues();
	void testFormingProcInfoStatistics();
	void testFormingProcInfoStatisticsBoundValues();
	void testFormingNetIfacesStatistics();
	void testFormingNetIfacesStatisticsBoundValues();
	void testFormingUsersStatistics();
	void testFormingUsersStatisticsBoundValues();
};

#endif
