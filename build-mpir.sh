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
base_path="$(cd $(dirname "$0") && pwd -P)/lib/mpir"
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
build_output="/dev/stdout"
tune=false
check=true
keep_info=false
keep=false

## Flags
usage="Usage:
$(basename "$0") [-h] [-ikmqst]
Downloads and builds MPIR v$version for this project.
The static library files will be stored in ./lib/mpir.

Flags:
    -h  show this \e[1mh\e[0melp text
    -i  keep the \e[1mi\e[0mnfo dir (./lib/mpir/info)
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
    i)
      keep_info=true
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
      build_output="/dev/null"
      ;;
    m)
      echo_spacing=""
      curl_params="-s"
      wget_params="-q"
      tar_params=""
      build_output="/dev/null"
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
./configure --enable-cxx --disable-shared --prefix="$install_path" > "$build_output"

    $verbose && echo -e "$echo_spacing\e[1mBuilding...\e[0m$echo_spacing"
make > "$build_output"

if $tune; then
      $verbose && echo -e "$echo_spacing\e[1mOptimizing MPIR for your local computer...\e[0m$echo_spacing"
  cd tune
  make tuneup > "$build_output"
  ./tuneup > gmp-mparam.h 2> tuneup.log
  mv -f gmp-mparam.h "$(head -n1 tuneup.log | sed 's/^.*\.\//..\//')"
  rm tuneup.log
  cd ..

    $verbose && echo -e "$echo_spacing\e[1mBuilding optimized version...\e[0m$echo_spacing"
  make > "$build_output"
fi

if $check; then
      $verbose && echo -e "$echo_spacing\e[1mRunning Tests...\e[0m$echo_spacing"
  make check > "$build_output"
fi

    $verbose && echo -e "$echo_spacing\e[1mCopying files...\e[0m$echo_spacing"
make install > "$build_output"

# Cleanup
    $verbose && echo -e "$echo_spacing\e[1mCleanup...\e[0m$echo_spacing"
cd "$base_path"
$keep_info || rm -rf "$install_path/info"
$keep || rm -rf "$build_path"
