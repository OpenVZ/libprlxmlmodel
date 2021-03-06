/*
 * CVmStartupOptions.cpp: Implementation of the CVmStartupOptions
 * class. This class implements a collection of VM startup
 * parameters.
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


#include <QVariant>

#include "CVmStartupOptions.h"
#include <prlcommon/Interfaces/VirtuozzoDomModel.h>

// Standard class constructor
CVmStartupOptions::CVmStartupOptions()
: m_lstBootDeviceList(*((QList<CVmBootDevice* >* )&m_lstBootingOrder[0]->m_lstBootDevice))
{
}


// Copy constructor
CVmStartupOptions::CVmStartupOptions(CVmStartupOptions *other)
 : CVmStartupOptionsBase((CVmStartupOptionsBase* )other),
  m_lstBootDeviceList(*((QList<CVmBootDevice* >* )&m_lstBootingOrder[0]->m_lstBootDevice))
{
}

void CVmStartupOptions::cleanupClassProperties()
{
	m_lstBootingOrder[0]->ClearLists();
	m_lstBootingOrder[0]->InitLists();
	m_lstBootingOrder[0]->setDefaults();

	setDefaults();
}

// Class destructor
CVmStartupOptions::~CVmStartupOptions()
{
} // CVmStartupOptions::~CVmStartupOptions()


// Get boot device list
QList<CVmStartupOptions::CVmBootDevice*> CVmStartupOptions::getBootDeviceList () const
{
    return m_lstBootDeviceList;

} // CVmStartupOptions::getBootingOrder()


// Set boot device list
void CVmStartupOptions::setBootDeviceList(
                                    QList<CVmStartupOptions::CVmBootDevice*> list)
{
    m_lstBootDeviceList = list;

} // CVmStartupOptions::setBootingOrder()

bool CVmStartupOptions::operator==( const CVmStartupOptions& cVmStartupOptions )
{
	if (
		(getAutoStart() == cVmStartupOptions.getAutoStart()) &&
		(getWindowMode() == cVmStartupOptions.getWindowMode())
		)
	{
		if (cVmStartupOptions.getBootDeviceList().size() == this->getBootDeviceList().size())
		{
			for (int i = 0 ; i < cVmStartupOptions.getBootDeviceList().size() ; i++)
				if(!(*(cVmStartupOptions.getBootDeviceList().at(i)) ==
					*(this->getBootDeviceList().at(i))))
					return false;

			return true;
		}
		else
			return false;
	}
	return false;

}
