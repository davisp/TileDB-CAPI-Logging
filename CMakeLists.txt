cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20 CACHE STRING "C++ Standard")

project(
  tdb_capi_logging
  VERSION 0.0.1
  LANGUAGES CXX
)

include(CMakePackageConfigHelpers)
include(GenerateExportHeader)
include(GNUInstallDirs)

option(BUILD_SHARED_LIBS "Build shared library" OFF)

add_library(
  tdb_capi_logging
    STATIC
      include/capi_function_override.h
      include/tdb_capi_logging.h
      src/main.cc
)

add_library(
  tdb_capi_logging::tdb_capi_logging
  ALIAS
    tdb_capi_logging
)

target_include_directories(
  tdb_capi_logging
  PRIVATE
    "include"
    "${CMAKE_CURRENT_BINARY_DIR}/include"
)

set(PUBLIC_HEADERS
  "include/tdb_capi_logging.h"
  "include/capi_function_override.h"
  "${CMAKE_BINARY_DIR}/include/tiledb_capi_logging_export.h"
)

set_target_properties(
  tdb_capi_logging
  PROPERTIES
    PUBLIC_HEADER
      "${PUBLIC_HEADERS}"
)

generate_export_header(tdb_capi_logging
    EXPORT_MACRO_NAME TILEDB_CAPI_LOGGING_EXPORT
    EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/include/tiledb_capi_logging_export.h
)

configure_package_config_file(
    cmake/tdb_capi_logging-config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/tdb_capi_logging-config.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_DATADIR}/tdb_capi_logging/cmake"
)

install(TARGETS tdb_capi_logging
    EXPORT tdb_capi_logging_targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    EXPORT tdb_capi_logging_targets
    FILE tdb_capi_logging_targets.cmake
    DESTINATION "${CMAKE_INSTALL_DATADIR}/tdb_capi_logging/cmake"
    NAMESPACE tdb_capi_logging::
)

install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/tdb_capi_logging-config.cmake"
    DESTINATION "${CMAKE_INSTALL_DATADIR}/tdb_capi_logging/cmake"
)
