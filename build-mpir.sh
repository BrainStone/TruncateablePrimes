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

## Functions
print_message() {
  $verbose && printf "$echo_spacing\e[1m$1\e[0m$echo_spacing\n"
}

dowload_mpir() {
  if command -v curl; then
    curl $curl_params -o "$file" "$url"
  elif command -v wget; then
    wget $wget_params -O "$file" "$url"
  else
    printf "Neither curl nor wget is installed. This script needs to download mpir. Install either before you run the script again." >&2
    exit 1
  fi
}

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
          system)
"

while getopts ":hkmqst" opt; do
  case $opt in
    h)
      printf "$usage" >&2
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
      printf "Invalid option: -$OPTARG\n\n$usage" >&2
      exit 1
      ;;
    :)
      printf "Option -$OPTARG requires an argument.\n\n$usage" >&2
      exit 1
      ;;
  esac
done

## Script
# Go to build dir
mkdir -p "$build_path"
cd "$build_path"

# Download file
    print_message "Downloading $url..."
dowload_mpir

# Untar
    print_message "Unpacking $file..."
tar $tar_params -xjf "$file"
rm "$file"

# Build it
cd "$source_path"

    print_message "Configuring build..."
./configure --enable-cxx --disable-shared --prefix="$install_path" > "$build_output"

    ECHO "$echo_spacing\e[1mBuilding...\e[0m$echo_spacing"
make > "$build_output"

if $tune; then
      print_message "Optimizing MPIR for your local computer..."
  cd tune
  make tuneup > "$build_output"
  ./tuneup > gmp-mparam.h 2> tuneup.log
  mv -f gmp-mparam.h "$(head -n1 tuneup.log | sed 's/^.*\.\//..\//')"
  rm tuneup.log
  cd ..

    print_message "Building optimized version..."
  make > "$build_output"
fi

if $check; then
      print_message "Running Tests..."
  make check > "$build_output"
fi

    print_message "Copying files..."
make install > "$build_output"

# Cleanup
    print_message "Cleanup..."
cd "$base_path"
$keep_info || rm -rf "$install_path/info"
$keep || rm -rf "$build_path"
