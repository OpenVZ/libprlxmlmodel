/*
 * CVmMassStorageDevice.cpp: Implementation of the
 * CVmMassStorageDevice class. This class implements a generic-type
 * mass storage device.
 *
 * Copyright (c) 1999-2017, Parallels International GmbH
 * Copyright (c) 2017-2019 Virtuozzo International GmbH. All rights reserved.
 *
 * This file is part of Virtuozzo SDK. Virtuozzo SDK is free
 * software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License,
 * or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/> or write to Free Software Foundation,
 * 51 Franklin Street, Fifth Floor Boston, MA 02110, USA.
 *
 * Our contact details: Virtuozzo International GmbH, Vordergasse 59, 8200
 * Schaffhausen, Switzerland.
 */


#include <prlcommon/Interfaces/VirtuozzoDomModel.h>
#include "CVmMassStorageDevice.h"


CVmMassStorageDevice::CVmMassStorageDevice()
{
	setDeviceType( PDE_MASSSTORAGE_DEVICE );
}

CVmMassStorageDevice::CVmMassStorageDevice( const CVmMassStorageDevice& rhs )
 : CVmStorageDevice( rhs )
{
}

CVmMassStorageDevice::~CVmMassStorageDevice()
{
}

CVmMassStorageDevice& CVmMassStorageDevice::operator=( const CVmMassStorageDevice& rhs )
{
	if ( this != &rhs )
	{
		CVmStorageDevice::operator=( rhs );
	}
	return *this;
}

bool CVmMassStorageDevice::operator==( const CVmMassStorageDevice& cVmMassStorageDevice )
{
	return CVmStorageDevice::operator==(cVmMassStorageDevice);
}
