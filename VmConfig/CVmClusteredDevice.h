/*
 * CVmClusteredDevice.h: Definition of the CVmClusteredDevice class.
 * This class implements a single clustered device.
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


#ifndef CVMCLUSTEREDDEVICE_H
#define CVMCLUSTEREDDEVICE_H

#include "CVmDevice.h"


/**
 * @brief This class implements a single clustered device.
 * @author SergeyM
 */
class CVmClusteredDevice : public CVmDevice
{
	Q_OBJECT
public:
	// Standard class constructor
	CVmClusteredDevice();

	CVmClusteredDevice( const CVmClusteredDevice& rhs );

	// Class destructor
	virtual ~CVmClusteredDevice();

	CVmClusteredDevice& operator=( const CVmClusteredDevice& rhs );

	virtual bool operator==( const CVmClusteredDevice& cVmDevice );

	// Set interface type
	void setInterfaceType(unsigned int value = PMS_IDE_DEVICE);
	// Get interface type
	PRL_MASS_STORAGE_INTERFACE_TYPE getInterfaceType() const;

	// Set stack index
	void setStackIndex(unsigned int value = 0);
	// Get stack index
	unsigned int getStackIndex() const;

	// Set passthrough mode
	void setPassthrough(unsigned int value = PVE::PassthroughDisabled);
	// Get passthrough mode
	PVE::DevicePassthroughMode getPassthrough() const;

	// Set sub type
	void setSubType(unsigned int value = PCD_VIRTIO_SCSI);
	// Get sub type
	PRL_CLUSTERED_DEVICE_SUBTYPE getSubType() const;

protected:

	unsigned int	m_uiInterfaceType;
	unsigned int	m_uiStackIndex;
	unsigned int	m_uiPassthrough;
	unsigned int	m_uiSubType;

signals:

	void signalInterfaceTypeChanged(unsigned int value, QString object_id = QString());
	void signalStackIndexChanged(unsigned int value, QString object_id = QString());
	void signalPassthroughChanged(unsigned int value, QString object_id = QString());
	void signalSubTypeChanged(unsigned int value, QString object_id = QString());

private slots:

	void slotChangeInterfaceType(unsigned int value);
	void slotChangeStackIndex(unsigned int value);
	void slotChangePassthrough(unsigned int value);
	void slotChangeSubType(unsigned int value);

};

#ifndef DM_4048696954
#define DM_4048696954
Q_DECLARE_METATYPE(PRL_MASS_STORAGE_INTERFACE_TYPE)
#endif
#ifndef DM_1994420962
#define DM_1994420962
Q_DECLARE_METATYPE(PVE::DevicePassthroughMode)
#endif
#ifndef DM_3680791948
#define DM_3680791948
Q_DECLARE_METATYPE(PRL_CLUSTERED_DEVICE_SUBTYPE)
#endif

#endif
