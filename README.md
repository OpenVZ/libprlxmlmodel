Virtuozzo Xml Model Library
=============

Virtuozzo Xml Model Library contains a common for Virtuozzo prl\* projects
object model - classes and their Xml representations.

Major objects:
- DispConfig - prl-disp-service configuration;
- VmConfig - Virtual Environment configuration;
- NetworkConfig - Virtual Networks configuration.

How to install
--------------

Project depends on:

- [libprlsdk](https://src.openvz.org/scm/ovz/libprlsdk.git) headers.
- [libprlcommon](https://src.openvz.org/scm/ovz/libprlcommon.git)
- qt-devel
- boost-devel

To build the libraries run:

```bash
qmake-qt4
make
sudo make install
```
