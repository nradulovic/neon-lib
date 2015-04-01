# Neon Lib Quick-start guide

Neon is a collection of software components for real-time applications.

# Using Lib

## Configuration

Configuration is done in `neon_app_config.h` header file. The file is included
by `base/include/shared/config.h` file, which is in included in all other Neon
components.

## Building

### Include paths

- `lib/include` - standard Neon include path

### Source files

- `lib/source/string/num_conv.c` - BCD conversion helper functions

### Project dependencies

Neon Eds does depend on the following components:
- base


