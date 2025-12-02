# raylib-games
A set of simple games in C17/C++17 (enforced by cmake) using the [raylib](https://github.com/raysan5/raylib) game framework.

# Build
## CI/CD
Covered in [github actions workflows](./github/workflows/).

## Manual
```shell
cmake -S . -B build
```

# Requirements
- a C/C++17-compliant compiler
- cmake `>3.21`
- [glog](https://github.com/google/glog) `=0.6.0`
- [raylib](https://github.com/raysan5/raylib) `=4.2.0`
- [sqlite3](https://github.com/sqlite/sqlite) `=3.31.1`
