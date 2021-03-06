CONFIG += qtestlib testcase
QT = xml core network

INCLUDEPATH += /usr/share /usr/include/prlsdk

include(CHostHardwareInfoTest.deps)

HEADERS += CHostHardwareInfoTest.h

SOURCES += CHostHardwareInfoTest.cpp

# It is important to have "File Info" embedded in the
# windows binaries - which means we need windows resource file
win32: RC_FILE = $$SRC_LEVEL/Tests/UnitTests.rc

QMAKE_POST_LINK += $(COPY) *.xml $$DESTDIR
