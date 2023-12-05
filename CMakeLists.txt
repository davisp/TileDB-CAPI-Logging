cmake_minimum_required(VERSION 3.10)
project(
  tdb_capi_logging
  VERSION 0.0.1
  LANGUAGES CXX
)

include(GenerateExportHeader)
include(GNUInstallDirs)

option(BUILD_SHARED_LIBS "Build shared library" ON)

add_library(
  tdb_capi_logging
    include/capi_function_override.h
    src/main.cc
)

add_library(
  tdb_capi_logging::tdb_capi_logging
  ALIAS
    tdb_capi_logging
)

set(PUBLIC_HEADERS
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

install(TARGETS tdb_capi_logging
    EXPORT tdb_capi_logging-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
