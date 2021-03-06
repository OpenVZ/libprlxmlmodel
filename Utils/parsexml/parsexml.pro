#
# parsexml.pro
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

TEMPLATE = app
TARGET = parsexml
CONFIG += console
QT += xml network
QT -= gui

LEVEL = ../../
include($$LEVEL/Build/Virtuozzo.pri)
include($$LEVEL/Build/Debug.pri)
include($$LEVEL/XmlModel.pri)
include($$LEVEL/Build/SharedQTWin.pri)

# ====================================================
# Enter the location of genxml headers and libraries:

PRL_SRC_DIR = $$LEVEL
PRL_BLD_DIR = $$LEVEL/z-Build

XMLMODEL_INCLUDES = $$PRL_SRC_DIR \
									$$PRL_SRC_DIR/Interfaces \
									$$PRL_SRC_DIR/XmlModel/VirtuozzoObjects \
									$$PRL_SRC_DIR/XmlModel/VmConfig \
									$$PRL_SRC_DIR/XmlModel/DispConfig \
									$$PRL_SRC_DIR/XmlModel/VmDirectory \
									$$PRL_SRC_DIR/XmlModel/ProblemReport \
									$$PRL_SRC_DIR/XmlModel/HostHardwareInfo \

XMLMODEL_LIBS = -lprl_xml_model

# ====================================================

isEmpty(XMLMODEL_INCLUDES): \
	error(Please specify the location of your XmlModel includes in genxml.pro)
isEmpty(XMLMODEL_LIBS): \
	error(Please specify the location of your XmlModel libraries in genxml.pro)

INCLUDEPATH += $$PWD $$XMLMODEL_INCLUDES
DEPENDPATH += $$PWD
LIBS += $$XMLMODEL_LIBS

# Using our standard logging library in the module
LIBS += -lprlcommon

SOURCES += main.cpp
HEADERS +=
