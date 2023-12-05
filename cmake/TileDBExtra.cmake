# This file is included by libtiledb's CMake run
# to setup custom dependencies.

find_package(tdb_capi_logging REQUIRED)
target_link_libraries(
  baseline
  INTERFACE
    tdb_capi_logging::tdb_capi_logging)
