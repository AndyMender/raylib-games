# raylib-games
A set of simple games in C17/C++17 (enforced by cmake) using the [raylib](https://github.com/raysan5/raylib) game framework.

# Build
Refer to the `.travis.yml` Travis CI YAML config for build instructions.
Instructions for individual cmake targets will be added later.

# Requirements
- `raylib` SO file available in `/usr/lib`, `/usr/lib64` or `/usr/local/lib`
- `raylib` headers available in `/usr/include` or `/usr/local/include`
- `cmake` accessible in `$PATH`
- a C/C++ compiler with support for additional `#pragma`s and "safer" function variants like `strnlen`
- cmake `>3.21`
