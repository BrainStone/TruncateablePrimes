#! /bin/sh

## Variables
# Settings
version="mpir-3.0.0"

# Paths
base_path="$(realpath $(dirname "$0"))/lib/mpir"
install_path="$base_path"
build_path="$base_path/build"
source_path="$build_path/$version"
file="$version.tar.bz2"
url="http://mpir.org/$file"

## Script
# Go to build dir
mkdir -p "$build_path"
cd "$build_path"

# Download file (with fallback)
curl -o "$file" "$url" || \
wget -O "$file" "$url"

# Untar
tar -xvjf "$file"
rm "$file"

# Build it
cd "$source_path"
./configure --enable-cxx --disable-shared --prefix="$install_path"
make
make install

# Cleanup
cd "$base_path"
rm -rf "$install_path/info"
rm -rf "$build_path"
