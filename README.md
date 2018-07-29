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

    $ cp -v .hooks/* .git/hooks/

## Building

This project uses gradle for building. The nice thing about gradle is that you only need to have Java (and a C++ compiler of your choice) installed.  
Building is super straight forward:

    $ ./gradlew build

This will build the project and all its dependencies.

### GMP

This program depends on the GMP library (libgmp) and its C++ Wrapper (libgmpxx). Due to the complexity I cannot include GMP here directly.  
In general you have two options:

- Install it system wide. The library files should be in `/usr/lib/x86_64-linux-gnu` **(Linux only)**
- Provide the files yourself:
  - Put the `gmp.h` and `gmpxx.h` in the `lib/gmp/include` dir
  - Put the library files in the `lib/gmp/lib` dir *(`libgmp.a` and `libgmpxx.a` on Linux and OSX, `gmp.lib` and `gmpxx.lib` on Windows)*

### Documentation

This project comes with a Doxyfile. You can either generate the documentation manually by using Doxygen from the command line, or by running this gradle task:

    $ ./gradlew doc

## License

This is project is licensed under the GPLv3 license.
