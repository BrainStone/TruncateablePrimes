#! /bin/sh
#
# Copyright (c) 2018 Yannick Schinko. All rights reserved.
# Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
#

## Variables
# Settings
version="3.0.0"

# Paths
name="mpir-$version"
base_path="$(realpath $(dirname "$0"))/lib/mpir"
install_path="$base_path"
build_path="$base_path/build"
source_path="$build_path/$name"
file="$name.tar.bz2"
url="http://mpir.org/$file"

# Script variables
verbose=true
echo_spacing="\n\n"
curl_params=""
wget_params=""
tar_params="-v"
configure_params=""
make_params=""
tune=false
check=true
keep=false

## Flags
usage="Usage:
$(basename "$0") [-h] [-kqst]
Downloads and builds MPIR v$version for this project.
The static library files will be stored in ./lib/mpir.

Flags:
    -h  show this \e[1mh\e[0melp text
    -k  \e[1mk\e[0meep the build files (files in ./lib/mpir/build)
    -m  \e[1mm\e[0messages only (No command output except errors and show progress
          messages)
    -q  \e[1mq\e[0muiet (No output except errors)
    -s  \e[1ms\e[0mkip the unit tests (make check)
    -t  run the \e[1mt\e[0muneup program before building (will optize MPIR for your local
          system)"

while getopts ":hkmqst" opt; do
  case $opt in
    h)
      echo -e "$usage" >&2
      exit
      ;;
    k)
      keep=true
      ;;
    q)
      verbose=false
      echo_spacing=""
      curl_params="-s"
      wget_params="-q"
      tar_params=""
      configure_params="-q"
      make_params="-s"
      ;;
    m)
      echo_spacing=""
      curl_params="-s"
      wget_params="-q"
      tar_params=""
      configure_params="-q"
      make_params="-s"
      ;;
    s)
      check=false
      ;;
    t)
      tune=true
      ;;
    \?)
      echo -e "Invalid option: -$OPTARG\n\n$usage" >&2
      exit 1
      ;;
    :)
      echo -e "Option -$OPTARG requires an argument.\n\n$usage" >&2
      exit 1
      ;;
  esac
done

## Script
# Go to build dir
mkdir -p "$build_path"
cd "$build_path"

# Download file (with fallback)
    $verbose && echo -e "\e[1mDownloading $url...\e[0m$echo_spacing"
curl $curl_params -o "$file" "$url" || \
wget $wget_params -O "$file" "$url"

# Untar
    $verbose && echo -e "$echo_spacing\e[1mUnpacking $file...\e[0m$echo_spacing"
tar $tar_params -xjf "$file"
rm "$file"

# Build it
cd "$source_path"

    $verbose && echo -e "$echo_spacing\e[1mConfiguring build...\e[0m$echo_spacing"
./configure $configure_params --enable-cxx --disable-shared --prefix="$install_path"

    $verbose && echo -e "$echo_spacing\e[1mBuilding...\e[0m$echo_spacing"
make $make_params

if $tune; then
      $verbose && echo -e "$echo_spacing\e[1mOptimizing MPIR for your local computer...\e[0m$echo_spacing"
  cd tune
  make $make_params tuneup
  ./tuneup > gmp-mparam.h 2> tuneup.log
  mv -f gmp-mparam.h "$source_path$(head -n1 tuneup.log | sed 's/^Parameters for \.//')"
  rm tuneup.log
  cd ..

    $verbose && echo -e "$echo_spacing\e[1mBuilding optimized version...\e[0m$echo_spacing"
  make $make_params
fi

if $check; then
      $verbose && echo -e "$echo_spacing\e[1mRunning Tests...\e[0m$echo_spacing"
  make $make_params check
fi

    $verbose && echo -e "$echo_spacing\e[1mCopying files...\e[0m$echo_spacing"
make $make_params install

# Cleanup
    $verbose && echo -e "$echo_spacing\e[1mCleanup...\e[0m$echo_spacing"
cd "$base_path"
rm -rf "$install_path/info"
$keep || rm -rf "$build_path"
