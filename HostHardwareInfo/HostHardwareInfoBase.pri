#
# HostHardwareInfoBase.pri
#
# Copyright (C) 1999-2014 Parallels IP Holdings GmbH
#
# This file is part of Parallels SDK. Parallels SDK is free
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
# Our contact details: Parallels IP Holdings GmbH, Vordergasse 59, 8200
# Schaffhausen, Switzerland.
#

DIR_HEADERS = \
	$$PWD/CSystemStatistics.h \
	$$PWD/CHostHardwareInfo.h \
	$$PWD/CHwGenericDevice.h

HEADERS += $${DIR_HEADERS}

SOURCES += \
	$$PWD/CSystemStatistics.cpp \
	$$PWD/CHwGenericDevice.cpp \
	$$PWD/CHostHardwareInfo.cpp

headers_HostHardwareInfoBase.files = $${DIR_HEADERS}
headers_HostHardwareInfoBase.path = $${PREFIX}/include/prlxmlmodel/HostHardwareInfo
INSTALLS += headers_HostHardwareInfoBase

include(HostHardwareInfo.pri)
include(FileSystemInfo.pri)

headers_FileSystemInfo.path = $${PREFIX}/include/prlxmlmodel/HostHardwareInfo
