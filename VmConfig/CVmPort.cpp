/*
 * CVmPort.cpp: Implementation of the CVmPort class. This class
 * implements a generic-type port.
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
#include "CVmPort.h"


CVmPort::CVmPort()
{
	setDeviceType( PDE_GENERIC_PORT );
}

CVmPort::CVmPort( const CVmPort& rhs )
 : CVmClusteredDevice( rhs )
{
}

CVmPort::~CVmPort()
{
}

CVmPort& CVmPort::operator=( const CVmPort& rhs )
{
	if ( this != &rhs )
	{
		CVmClusteredDevice::operator=( rhs );
	}
	return *this;
}

bool CVmPort::operator==( const CVmPort& cVmPort )
{
	return CVmClusteredDevice::operator==( cVmPort );
}
