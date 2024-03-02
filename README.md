Calypsi board support for F256 Foenix
=====================================

This project is a [Calypsi C compiler](https://www.calypsi.cc/)  65816
compiler board support for the F256 series computers from Foenix Retro
Systems.

Usage
-----

This module is normally built together with Calypsi and becomes
available by specifying `--target=f256`. Additional link support
is automatically provided with a linker control file if the filename
starts with `f256-`. Such linker files are provided in this board
support, but you can also provide your own such file.

Startup module
--------------

This project contains a startup module for F256 that is suitable for
starting an application in this envionment. The default startup module
provided by the Calypsi tools is intended for a standalone system
running from a flash.

Stub interface
--------------

There is currently no stub functionality provided in this board
support due to lack of a ready kernel to interface to.
