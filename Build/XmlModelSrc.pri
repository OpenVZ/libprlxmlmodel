#
# XmlModelSrc.pri
#
# Copyright (c) 1999-2017, Parallels International GmbH
# Copyright (c) 2017-2019 Virtuozzo International GmbH. All rights reserved.
#
# This file is part of Virtuozzo SDK. Virtuozzo SDK is free
# software; you can redistribute it and/or modify it under the
# terms of the GNU Lesser General Public License as published by
# the Free Software Foundation; either version 2.1 of the License,
# or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library.  If not, see
# <http://www.gnu.org/licenses/>.
#
# Our contact details: Virtuozzo International GmbH, Vordergasse 59, 8200
# Schaffhausen, Switzerland.
#

include(../GuestOsInformation/GuestOsInformation.pri)
include(../VirtuozzoObjects/VirtuozzoObjects.pri)
include(../UserInformation/UserInformation.pri)
include(../VmInfo/VmInfo.pri)
include(../VmConfig/VmConfigBase.pri)
include(../DispConfig/DispConfig.pri)
include(../ProblemReport/ProblemReport.pri)
include(../VmDirectory/VmDirectory.pri)
include(../BackupTree/BackupTree.pri)
include(../DiskImageInfo/DiskImageInfo.pri)
include(../HostHardwareInfo/HostHardwareInfoBase.pri)
include(../NetworkConfig/NetworkConfig.pri)
include(../Reports/Reports.pri)
include(../Licenses/Licenses.pri)
include(../CtTemplate/CtTemplate.pri)
include(../DiskDescriptor/DiskDescriptor.pri)
include(../VmDataStatistic/VmDataStatistic.pri)
include(../CpuFeatures/CpuFeatures.pri)
include(../VtInfo/VtInfo.pri)
include(../BackupActivity/BackupActivity.pri)
include(../VcmmdConfig/VcmmdConfig.pri)

HEADERS += $$GEN_HEADERS
SOURCES += $$GEN_SOURCES
