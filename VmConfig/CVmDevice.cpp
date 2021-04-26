/*
 * CVmDevice.cpp: Implementation of the CVmDevice class. This class
 * implements the basic VM device. All the devices, which can be
 * included into the VM hardware list, inherit from this class.
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


#include <QTextStream>

#include <prlcommon/Interfaces/VirtuozzoDomModel.h>
#include "CVmHardware.h"
#include <QDir>
#include <QFileInfo>
#include <prlcommon/Std/PrlAssert.h>
#include <prlcommon/PrlUuid/PrlUuid.h>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/variant/variant.hpp>

#define SERIAL_PREFIX "vm-serial"

CVmDevice::CVmDevice()
{
	static bool first_time = true;
	if (first_time)
	{
		qRegisterMetaType<PRL_DEVICE_TYPE >("PRL_DEVICE_TYPE");
		first_time = false;
	}

	setDeviceType( PDE_GENERIC_DEVICE );
	Init();
}

CVmDevice::CVmDevice( const CVmDevice& rhs )
: CBaseNodeSignals()
{
	setDeviceType( rhs.getDeviceType() );
	setIndex( rhs.getIndex() );
	setEnabled( rhs.getEnabled() );
	setConnected( rhs.getConnected() );
	setEmulatedType( rhs.getEmulatedType() );
	setSystemName( rhs.getSystemName() );
	setUserFriendlyName( rhs.getUserFriendlyName() );
	setRemote( rhs.isRemote() );
	setDescription( rhs.getDescription() );
	setAlias( rhs.getAlias() );
}

void CVmDevice::Init()
{
	setEmulatedType( PVE::RealGenericDevice );
	setIndex();
	setEnabled();
	setConnected();
	setRemote();
}

CVmDevice::~CVmDevice()
{
}

CVmDevice& CVmDevice::operator=( const CVmDevice& rhs )
{
	if ( this != &rhs )
	{
		setDeviceType( rhs.getDeviceType() );
		setIndex( rhs.getIndex() );
		setEnabled( rhs.getEnabled() );
		setConnected( rhs.getConnected() );
		setEmulatedType( rhs.getEmulatedType() );
		setSystemName( rhs.getSystemName() );
		setUserFriendlyName( rhs.getUserFriendlyName() );
		setRemote( rhs.isRemote() );
		setDescription( rhs.getDescription() );
		setAlias( rhs.getAlias() );
	}

	return *this;
}

bool CVmDevice::operator==( const CVmDevice& cVmDevice )
{
	return (
		(getDeviceType() == cVmDevice.getDeviceType()) &&
		(getEnabled() == cVmDevice.getEnabled()) &&
		(getConnected() == cVmDevice.getConnected()) &&
		(getEmulatedType() == cVmDevice.getEmulatedType()) &&
		(getSystemName() == cVmDevice.getSystemName()) &&
		(getUserFriendlyName() == cVmDevice.getUserFriendlyName()) &&
		(isRemote() == cVmDevice.isRemote()) &&
		(getIndex() == cVmDevice.getIndex())
		);
}

QString CVmDevice::getObjectId() const
{
	return QString("%1 %2").arg((unsigned int )getDeviceType()).arg(getIndex());
}

void CVmDevice::setDeviceType(PRL_DEVICE_TYPE value)
{
	bool bValueChanged = (m_uiDeviceType != value);
	m_uiDeviceType = value;
	if (isSignalsEnabled() && bValueChanged)
	{
		emit signalDeviceTypeChanged(value, getObjectId());
	}
}

void CVmDevice::slotChangeDeviceType(PRL_DEVICE_TYPE value)
{
	setDeviceType(value);
}

PRL_DEVICE_TYPE CVmDevice::getDeviceType() const
{
	return m_uiDeviceType;
}

void CVmDevice::setEnabled(unsigned int value)
{
	bool bValueChanged = (m_uiEnabled != value);
	m_uiEnabled = value;
	if (isSignalsEnabled() && bValueChanged)
	{
		emit signalEnabledChanged(value, getObjectId());
		emit signalEnabledChanged(value == PVE::DeviceEnabled, getObjectId());
	}
}

void CVmDevice::slotChangeEnabled(unsigned int value)
{
	setEnabled(value);
}

void CVmDevice::slotChangeEnabled(bool value)
{
	setEnabled(value ? PVE::DeviceEnabled : PVE::DeviceDisabled);
}

PVE::DeviceEnabledState CVmDevice::getEnabled() const
{
	return (PVE::DeviceEnabledState )m_uiEnabled;
}

void CVmDevice::setConnected(unsigned int value)
{
	bool bValueChanged = (m_uiConnected != value);
	m_uiConnected = value;
	if (isSignalsEnabled() && bValueChanged)
	{
		emit signalConnectedChanged(value, getObjectId());
	}
}

void CVmDevice::slotChangeConnected(unsigned int value)
{
	setConnected(value);
}

PVE::DeviceConnectedState CVmDevice::getConnected() const
{
	return (PVE::DeviceConnectedState )m_uiConnected;
}

void CVmDevice::setEmulatedType(unsigned int value)
{
	bool bValueChanged = (m_uiEmulatedType != value);
	m_uiEmulatedType = value;
	if (isSignalsEnabled() && bValueChanged)
	{
		emit signalEmulatedTypeChanged(value, getObjectId());
	}
}

void CVmDevice::slotChangeEmulatedType(unsigned int value)
{
	setEmulatedType(value);
}

unsigned int CVmDevice::getEmulatedType() const
{
	return m_uiEmulatedType;
}

void CVmDevice::setIndex(unsigned int value)
{
	bool bValueChanged = (m_uiIndex != value);
	m_uiIndex = value;
	if (isSignalsEnabled() && bValueChanged)
	{
		emit signalIndexChanged(value, getObjectId());
	}
}

void CVmDevice::slotChangeIndex(unsigned int value)
{
	setIndex(value);
}

unsigned int CVmDevice::getIndex() const
{
	return m_uiIndex;
}

void CVmDevice::setSystemName(QString value)
{
	bool bValueChanged = (m_qsSystemName != value);
	m_qsSystemName = value;
	if (isSignalsEnabled() && bValueChanged)
	{
		emit signalSystemNameChanged(value, getObjectId());
	}
}

void CVmDevice::slotChangeSystemName(QString value)
{
	setSystemName(value);
}

QString CVmDevice::getSystemName() const
{
	return m_qsSystemName;
}

void CVmDevice::setUserFriendlyName(QString value)
{
	bool bValueChanged = (m_qsUserFriendlyName != value);
	m_qsUserFriendlyName = value;
	if (isSignalsEnabled() && bValueChanged)
	{
		emit signalUserFriendlyNameChanged(value, getObjectId());
	}
}

void CVmDevice::slotChangeUserFriendlyName(QString value)
{
	setUserFriendlyName(value);
}

QString CVmDevice::getUserFriendlyName() const
{
	return m_qsUserFriendlyName;
}

void CVmDevice::setRemote(bool value)
{
	bool bValueChanged = (m_bRemote != value);
	m_bRemote = value;
	if (isSignalsEnabled() && bValueChanged)
	{
		emit signalRemoteChanged(value, getObjectId());
	}
}

void CVmDevice::slotChangeRemote(bool value)
{
	setRemote(value);
}

bool CVmDevice::isRemote() const
{
	return m_bRemote;
}

void CVmDevice::setDescription(QString value)
{
	bool bValueChanged = (m_qsDeviceDescription != value);
	m_qsDeviceDescription = value;
	if (isSignalsEnabled() && bValueChanged)
	{
		emit signalDescriptionChanged(value, getObjectId());
	}
}

void CVmDevice::slotChangeDescription(QString value)
{
	setDescription(value);
}

QString CVmDevice::getDescription() const
{
	return m_qsDeviceDescription;
}

void CVmDevice::setAlias(QString value)
{
	bool bValueChanged = (m_qsAlias != value);
	m_qsAlias = value;
	if (isSignalsEnabled() && bValueChanged)
	{
		emit signalAliasChanged(value, getObjectId());
	}
}

void CVmDevice::slotChangeAlias(QString value)
{
	setAlias(value);
}

QString CVmDevice::getAlias() const
{
	return m_qsAlias;
}

//////////////////////////////////////////////////////////////////////////////

namespace {
namespace Path {
namespace Flavor {

//////////////////////////////////////////////////////////////////////////////
// struct Absolute

struct Absolute
{
	static QString convert(const QString& home_, const QString& path_)
	{
		boost::filesystem::path p(path_.toStdString());
		return QDir::cleanPath(QString::fromStdString(
			boost::filesystem::absolute(p,
				QDir::cleanPath(home_).toStdString()).string()));
	}
};

//////////////////////////////////////////////////////////////////////////////
// struct Relative

struct Relative
{
	static QString convert(const QString& home_, const QString& path_)
	{
		namespace fs = boost::filesystem;
		boost::system::error_code e;
		fs::path h(fs::canonical(home_.toStdString(), e)), p;
		if (e)
		{
			h = fs::path(QDir::cleanPath(home_).toStdString());
			p = fs::path(QDir::cleanPath(path_).toStdString());
		}
		else
		{
			fs::path x(path_.toStdString());
			p = fs::canonical(x, e);
			if (boost::system::errc::no_such_file_or_directory == e)
				p = fs::canonical(x.parent_path(), e) / x.filename();
			if (e)
				p = fs::path(QDir::cleanPath(path_).toStdString());
		}
		std::pair<fs::path::const_iterator, fs::path::const_iterator> i =
			std::mismatch(h.begin(), h.end(), p.begin());
		if (i.first == h.end() && i.second != p.begin())
		{
			fs::path x;
			while (i.second != p.end())
			{
				x /= *i.second;
				++i.second;
			}
			return QString::fromStdString(x.string());
		}
		return path_;
	}
};

} // namespace Flavor

namespace Mode {

//////////////////////////////////////////////////////////////////////////////
// struct Both

struct Both
{
	explicit Both(CVmDevice& device_) : m_device(&device_)
	{
	}

	void operator()(const QString& path_) const
	{
		m_device->setSystemName(path_);
		m_device->setUserFriendlyName(path_);
	}

private:
	CVmDevice *m_device;
};

//////////////////////////////////////////////////////////////////////////////
// struct System

struct System
{
	explicit System(CVmDevice& device_) : m_device(&device_)
	{
	}

	void operator()(const QString& path_) const
	{
		m_device->setSystemName(path_);
	}

private:
	CVmDevice *m_device;
};

} // namespace Mode

//////////////////////////////////////////////////////////////////////////////
// struct Inspector

struct Inspector
{
	typedef boost::variant<boost::blank, Mode::Both, Mode::System> mode_type;

	explicit Inspector(CVmDevice& object_): m_object(&object_)
	{
	}

	QString getName() const;
	mode_type getMode() const;

private:
	CVmDevice* m_object;
};

QString Inspector::getName() const
{
	QString output = m_object->getSystemName();
	if (PDE_HARD_DISK == m_object->getDeviceType() &&
		(m_object->getEmulatedType() == PDT_USE_FILE_SYSTEM ||
		::PrlUuid::isUuid(m_object->getSystemName().toStdString())))
		output = m_object->getUserFriendlyName();

	return output;
}

Inspector::mode_type Inspector::getMode() const
{
	uint e = m_object->getEmulatedType();
	switch (m_object->getDeviceType())
	{
	case PDE_FLOPPY_DISK:
	case PDE_OPTICAL_DISK:
	case PDE_PARALLEL_PORT:
		if (e == PDT_USE_IMAGE_FILE || e == PDT_USE_OUTPUT_FILE)
			return Mode::Both(*m_object);
		break;
	case PDE_HARD_DISK:
		switch (e)
		{
		case PDT_USE_REAL_HDD:
		case PDT_USE_BOOTCAMP:
			return Mode::System(*m_object);

		case PDT_USE_IMAGE_FILE:
		case PDT_USE_OUTPUT_FILE:
		case PDT_USE_FILE_SYSTEM:
			return Mode::Both(*m_object);
		}
		break;

	case PDE_SERIAL_PORT:
		if (e == PDT_USE_IMAGE_FILE || e == PDT_USE_OUTPUT_FILE
			|| e == PDT_USE_SERIAL_PORT_SOCKET_MODE)
		{
			return Mode::Both(*m_object);
		}
		break;
	default:
		break;
	}

	return boost::blank();
}

//////////////////////////////////////////////////////////////////////////////
// struct Visitor

template<class T>
struct Visitor : public boost::static_visitor<void>
{
	Visitor(CVmDevice& device_, const QString& home_, const QString& path_)
		: boost::static_visitor<void>(), m_device(&device_),
		  m_home(home_), m_path(path_)
	{
	}

	void operator()(const boost::blank&) const
	{
	}

	void operator()(const Mode::System& mode_) const
	{
		mode_(T::convert(m_home, m_path));
	}

	void operator()(const Mode::Both& mode_) const;

private:
	QString getHome() const
	{
		return (PDE_SERIAL_PORT == m_device->getDeviceType()
				&& PDT_USE_SERIAL_PORT_SOCKET_MODE == m_device->getEmulatedType()) ?
				QDir::tempPath() : m_home;
	}

	CVmDevice *m_device;
	QString m_home;
	QString m_path;
};

template<>
void Visitor<Flavor::Absolute>::operator()(const Mode::Both& mode_) const
{
	if (!QFileInfo(m_device->getUserFriendlyName()).isAbsolute())
	{
		QString path = m_path;
		if (PDE_SERIAL_PORT == m_device->getDeviceType()
				&& PDT_USE_SERIAL_PORT_SOCKET_MODE == m_device->getEmulatedType()
				&& !path.startsWith(SERIAL_PREFIX))
		{
			path = QString("%1-%2.%3").arg(SERIAL_PREFIX).arg(m_path).arg(QDir(m_home).dirName());
			// UNIX_PATH_MAX   108
			path.truncate(108 - getHome().length() -1);
		}

		mode_(Flavor::Absolute::convert(getHome(), path));
	}
}

template<>
void Visitor<Flavor::Relative>::operator()(const Mode::Both& mode_) const
{
	if (QFileInfo(m_device->getUserFriendlyName()).isAbsolute())
		mode_(Flavor::Relative::convert(getHome(), m_path));
}

} // namespace Path
} // anonymous namespace

void CVmDevice::setRelativeSystemName(const QString& strVmDirectory)
{
	Path::Inspector i(*this);
	QString s = i.getName();
	if (s.isEmpty() || !QFileInfo(s).isAbsolute() || isRemote())
		return;

	Path::Inspector::mode_type m = i.getMode();
	boost::apply_visitor(Path::Visitor<Path::Flavor::Relative>(*this, strVmDirectory, s), m);
}

QString CVmDevice::RevertToInitialSystemName(const QString& strVmDirectory)
{
	if (getSystemName().isEmpty() || getUserFriendlyName().isEmpty())
		return QString();

	Path::Inspector i(*this);
	QString s = i.getName();
	if (QFileInfo(s).isAbsolute() || strVmDirectory.isEmpty() || isRemote())
		return s;

	Path::Inspector::mode_type m = i.getMode();
	boost::apply_visitor(Path::Visitor<Path::Flavor::Absolute>(*this, strVmDirectory, s), m);
	return getSystemName();
}

int CVmDevice::readXml(QDomElement *parent_element, QString /*ext_tag_name*/, bool /*unite_with_loaded*/)
{
	if (parent_element->tagName() == XML_VM_CONFIG_EL_FLOPPY_DISK)
		m_uiDeviceType = PDE_FLOPPY_DISK;
	else if (parent_element->tagName() == XML_VM_CONFIG_EL_HARD_DISK)
		m_uiDeviceType = PDE_HARD_DISK;
	else if (parent_element->tagName() == XML_VM_CONFIG_EL_OPTICAL_DISK)
		m_uiDeviceType = PDE_OPTICAL_DISK;
	else if (parent_element->tagName() == XML_VM_CONFIG_EL_PARALLEL_PORT
				|| parent_element->tagName() == "Printer")
		m_uiDeviceType = PDE_PARALLEL_PORT;
	else if (parent_element->tagName() == XML_VM_CONFIG_EL_SERIAL_PORT)
		m_uiDeviceType = PDE_SERIAL_PORT;
	else if (parent_element->tagName() == XML_VM_CONFIG_EL_USB_DEVICE)
		m_uiDeviceType = PDE_USB_DEVICE;
	else if (parent_element->tagName() == XML_VM_CONFIG_EL_SOUND_DEVICE)
		m_uiDeviceType = PDE_SOUND_DEVICE;
	else if (parent_element->tagName() == XML_VM_CONFIG_EL_GEN_NET_ADAPTER)
		m_uiDeviceType = PDE_GENERIC_NETWORK_ADAPTER;
	else if (parent_element->tagName() == "GenericPciDevice")
		m_uiDeviceType = PDE_GENERIC_PCI_DEVICE;
	else if (parent_element->tagName() == "GenericScsiDevice")
		m_uiDeviceType = PDE_GENERIC_SCSI_DEVICE;
	else if (parent_element->tagName() == "PciVideoAdapter")
		m_uiDeviceType = PDE_PCI_VIDEO_ADAPTER;
	else if (parent_element->tagName() == "GenericDevice")
		m_uiDeviceType = PDE_GENERIC_DEVICE;
	else
		return PRL_ERR_PARSE_VM_CONFIG;

	return (PRL_ERR_SUCCESS);
}

CVmDevice * CVmDevice::getDeviceInstanceFromString( const QString & strDevice )
{
	CVmDevice cDevice;
	cDevice.fromString( strDevice );
	if ( PRL_FAILED( cDevice.m_iParseRc ) )
		return NULL;


	CVmDevice * pDevToReturn = NULL;
	switch( cDevice.getDeviceType() )
	{
		case PDE_FLOPPY_DISK:
			pDevToReturn = new CVmFloppyDisk( );
			break;

		case PDE_ATTACHED_BACKUP_DISK:
		case PDE_HARD_DISK:
			pDevToReturn = new CVmHardDisk( );
			break;

		case PDE_OPTICAL_DISK:
			pDevToReturn = new CVmOpticalDisk( );
			break;

		case PDE_PARALLEL_PORT:
			pDevToReturn = new CVmParallelPort( );
			break;

		case PDE_SERIAL_PORT:
			pDevToReturn = new CVmSerialPort( );
			break;

		case PDE_USB_DEVICE:
			pDevToReturn = new CVmUsbDevice( );
			break;

		case PDE_SOUND_DEVICE:
		case PDE_MIXER_DEVICE:
			pDevToReturn = new CVmSoundDevice( );
			break;

		case PDE_GENERIC_NETWORK_ADAPTER:
			pDevToReturn = new CVmGenericNetworkAdapter( );
			break;

		case PDE_GENERIC_DEVICE:
			pDevToReturn = new CVmGenericDevice( );
			break;

		case PDE_GENERIC_PCI_DEVICE:
			pDevToReturn = new CVmGenericPciDevice( );
			break;

		case PDE_PCI_VIDEO_ADAPTER:
			pDevToReturn = new CVmPciVideoAdapter( );
			break;
		case PDE_GENERIC_SCSI_DEVICE:
			pDevToReturn = new CVmGenericScsiDevice( );
			break;
		case PDE_PRINTER:
		case PDE_CLUSTERED_DEVICE:
		case PDE_STORAGE_DEVICE:
		case PDE_VIRTUAL_SNAPSHOT_DEVICE:
		default:
			PRL_ASSERT( pDevToReturn );
			// Unknown Device Type
			break;
	}

	if ( pDevToReturn )
	{
		pDevToReturn->fromString( strDevice );
		if ( PRL_FAILED( pDevToReturn->m_iParseRc ) )
			return NULL;
	}

	return pDevToReturn;
}

