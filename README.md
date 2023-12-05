TileDB Log Testing
===

A small test repository for logging API calls.

To Test
===

```bash
git clone https://github.com/TileDB-Inc/TileDB
cd TileDB
git checkout pd/sc-37906/pluggable-capi-logging

# Setup logging integration

git clone https://github.com/davisp/TileDB-CAPI-Logging internal
./internal/scripts/add-dependency.py vcpkg.json
export VCPKG_OVERLAY_PORTS=/path/to/cloned/TileDB/internal/ports

# Notice the new --extra-cmake-include is necessary
# We also need to enable verbose just so we see our log messages.

mkdir build
cd build
../bootstrap \
  --enable=ccache,serialization,debug,verbose \
  --extra-cmake-include=internal/cmake/TileDBExtra.cmake

