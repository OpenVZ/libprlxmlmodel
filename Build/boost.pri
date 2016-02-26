# Distribution specific boost dependency - we want to link with
# multithreaded version where possible
BOOST_FILESYSTEM = -lboost_filesystem
exists(/usr/lib64/libboost_filesystem-mt*) : BOOST_FILESYSTEM = -lboost_filesystem-mt
BOOST_SYSTEM = -lboost_system
exists(/usr/lib64/libboost_system-mt*) : BOOST_SYSTEM = -lboost_system-mt

LIBS += $${BOOST_FILESYSTEM} $${BOOST_SYSTEM}
