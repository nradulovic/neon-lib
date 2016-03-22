# Neon Lib Quick-start guide

Neon is a collection of software components for real-time applications.

# Using Neon Lib

## Configuration

Configuration is done in `neon_lib_app_config.h` header file. The file is included
by `lib/config.h` file.

## Building

### Include paths

- `lib/include` - standard Neon include path

### Source files

- `lib/source/string/num_bcd_conv.c` - BCD conversion helper functions
- `lib/source/bits.c` - bit and logic operations
- `lib/source/checksum.c` - checksum calculation

### Project dependencies

Neon Lib does depend on the following components:
- Neon EDS


