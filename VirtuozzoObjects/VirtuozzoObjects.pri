#
# VirtuozzoObjects.pri
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

DIR_HEADERS += $$PWD/CXmlModelHelper.h \
           $$PWD/CVmProfileHelper.h

HEADERS += $${DIR_HEADERS}

SOURCES += $$PWD/CXmlModelHelper.cpp \
           $$PWD/CVmProfileHelper.cpp

headers_VirtuozzoObjects.files = $${DIR_HEADERS}
headers_VirtuozzoObjects.path = $${PREFIX}/include/prlxmlmodel/VirtuozzoObjects
INSTALLS += headers_VirtuozzoObjects

