AUTOMAKE_OPTIONS = foreign

AM_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/../eds/include \
	-I$(top_srcdir)/../eds/port/x86-64-linux-gcc

noinst_LIBRARIES = libneonlib.a
libneonlib_a_SOURCES = \
	source/bits.c \
	source/argparse.c \
	source/checksum.c \
	source/string/num_conv.c
