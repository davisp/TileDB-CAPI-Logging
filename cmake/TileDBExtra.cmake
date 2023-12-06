# This file is included by libtiledb's CMake run
# to setup custom dependencies.

find_package(tdb_capi_logging REQUIRED)

message(STATUS "Adding tdb_capi_logging dependencies.")

target_link_libraries(
  baseline
  INTERFACE
    tdb_capi_logging::tdb_capi_logging)

target_link_libraries(
  tiledb_shared
  PUBLIC
    tdb_capi_logging::tdb_capi_logging)
