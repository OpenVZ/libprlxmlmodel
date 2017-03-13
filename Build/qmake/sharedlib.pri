#
# sharedlib.pri
#
# Copyright (c) 1999-2017, Parallels International GmbH
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
# Our contact details: Parallels International GmbH, Vordergasse 59, 8200
# Schaffhausen, Switzerland.
#

#message(static::: $$SUBDIRS)
CONFIG += _sharedlib
include(commonlib.pri)
CONFIG -= _sharedlib

isEqual(TEMPLATE, subdirs) {
	# loaded_shared_libs controls includeing deps of each shared lib
	# only once. This optimization is possible since our shared libs
	# are "fully linked" and don't require to add anyting else to linker
	# command line.
	!contains(loaded_shared_libs, $$LIBTARGET) {
		!contains(SKIP_BUILD, $$LIBTARGET) {
			loaded_shared_libs *= $$LIBTARGET
			# Push target
			_prev_target += $$TARGET
			_deps_file = $$PROJ_FILE
			_deps_file ~= s,.pro$,.pri,
			TARGET = $$LIBTARGET
			NON_SUBDIRS = yes
			include($$_deps_file)
			clear(NON_SUBDIRS)
			# Pop target
			# Because we include each shared lib only once
			# _prev_target list contains only single item
			# of each saved target
			TARGET = $$last(_prev_target)
			_prev_target -= $$TARGET
		}
	}
} else {
	isEqual(TEMPLATE, app) | contains(CONFIG, shared) | contains(CONFIG, dll) {
		# will add pre_targetdeps only to apps and shared libs
		# no pre_targetdeps for static libs!
		isEmpty(_DONT_LINK_LIBTARGET) {
			linux-*: LIBTARGET_NAME = lib$${LIBTARGET}.so
			macx: LIBTARGET_NAME = lib$${LIBTARGET}.dylib
			win32: LIBTARGET_NAME = $${LIBTARGET}.dll
			PRE_TARGETDEPS += $$LIB_BUILD_DIR/$$LIBTARGET_NAME
		}
	}
}
