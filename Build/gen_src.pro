#
# gen_src.pro
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

include(../../Virtuozzo.pri)

include(XmlModelSrc.pri)
QMAKE_CLEAN += $$GEN_HEADERS $$GEN_SOURCES
clear(HEADERS)
clear(SOURCES)
QMAKE_LINK = echo
clear(QMAKE_POST_LINK)

xmlmodel_py_cmd.commands = $$PWD/gen_src.py
#CONFIG(release, debug|release) {
#	xmlmodel_py_cmd.commands += ' release'
#} else {
#	xmlmodel_py_cmd.commands += ' debug'
#}

QMAKE_EXTRA_TARGETS += xmlmodel_py_cmd
PRE_TARGETDEPS += xmlmodel_py_cmd
