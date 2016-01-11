#
# subbuild.pro
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

TEMPLATE = lib
CONFIG += sharedlib

NON_SUBDIRS = yes

include(../XmlModel.pri)

INCLUDEPATH += ./ParallelsObjects

linux-*:QMAKE_CXXFLAGS_RELEASE += -fno-strict-aliasing

unix {
	VERSION = $$cat(../Makefile.version)
	VERSIONS = $$split(VERSION, ".")
	VER_MAJ = $$member(VERSIONS,0)
	VER_MIN = $$member(VERSIONS,1)
	VER_PAT = $$member(VERSIONS,2)
}

include(XmlModelSrc.pri)
QMAKE_CLEAN += $$GEN_HEADERS $$GEN_SOURCES $$GEN_PRIFILES
