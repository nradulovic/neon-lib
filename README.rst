
.. contents:: Table of contents
   :backlinks: top
   :local:

Neon Library
============

Neon is a collection of software components for real-time applications.

Using Neon Library
==================

Configuration
-------------

Configuration is done in ``neon_lib_app_config.h`` header file. The file is
included by `lib/config.h` file.

Building
--------

**Include paths**

- ``lib/include`` - standard Neon include path

**Source files**

- ``lib/source/string/num_bcd_conv.c`` - BCD conversion helper functions
- ``lib/source/bits.c`` - bit and logic operations
- ``lib/source/checksum.c`` - checksum calculation

**Project dependencies**

Neon Lib does depend on the following components:

- Neon EDS

Support
=======

If you've found an error, please `file an issue
<https://github.com/nradulovic/neon-lib/issues/new/>`_.

Patches are encouraged, and may be submitted by `forking this project 
<https://github.com/nradulovic/neon-lib/fork/>`_ and submitting
a pull request through GitHub. Please see `CONTRIBUTING.rst
<https://github.com/nradulovic/neon-lib/blob/master/CONTRIBUTING.rst/>`_ for
more details.
