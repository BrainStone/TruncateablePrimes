# TruncateablePrimes [![Build Status](https://travis-ci.org/BrainStone/TruncateablePrimes.svg?branch=master)](https://travis-ci.org/BrainStone/TruncateablePrimes)

TruncateablePrimes is a project designed to calculate left and right truncatable primes in C++.

Inspired by https://www.youtube.com/watch?v=azL5ehbw_24

Contributions are always welcome!

## Cloning

Since this repo is recursive, you need to clone it recursively

    $ git clone --recursive https://github.com/BrainStone/TruncateablePrimes.git

If you forgot to do that, you can download the submodules later by running

    $ git submodule update --init --recursive

### Hooks

This repo also provides a few simple hooks to make working with submodules easier. While it is not necessary to do this step, it is recommended.

    $ cp -va .hooks/* .git/hooks/

## Building

This project uses gradle for building. The nice thing about gradle is that you only need to have Java (and a C++ compiler of your choice) installed.  
Building is super straight forward:

    $ ./gradlew build

This will build the project and all its dependencies.

### Compiler version

For this project to build properly, you need an up to date version of your compiler:

| Compiler | Required Version |
| --- | --- |
| Clang | 5+ |
| GCC | 6+ |
| Visual Studio | 2015+ |

*(If you find that it compiles on different versions than stated here, open an issue stating on which compiler version it compiled successfully. (Including the
tests!))*

### MPIR

This program depends on the MPIR library (libmpir) and its C++ Wrapper (libmpirxx). Due to the complexity I cannot include MPIR here directly.

You sadly need to build it yourself. Downloads can be found here: http://mpir.org/downloads.html  
Be sure to use the version 3.0.0. Building instructions can be found in the documentation.

In general you have three options:

- **Recommended *(for Unix)***: Run the provided `./build-mpir.sh` script.  
  For most cases the invocation `./build-mpir.sh -t` is the best choice.  
  Run `./build-mpir.sh -h` to get an overview and explanation of all flags.
- Install it system wide. The library files should be in `/usr/local/lib/` **(Unix only)**
- Provide the files yourself:
  - Put the `mpir.h` and `mpirxx.h` in the `lib/mpir/include` dir
  - Put the library files in the `lib/mpir/lib` dir *(`libmpir.a` and `libmpirxx.a` on Linux and OSX, `mpir.lib` and `mpirxx.lib` on Windows)*

### Documentation

This project comes with a Doxyfile. You can either generate the documentation manually by using Doxygen from the command line, or by running this gradle task:

    $ ./gradlew doc

## License

This is project is licensed under the GPLv3 license.

Projects included in this project through submodules or other means are licensed under their respective licenses.
