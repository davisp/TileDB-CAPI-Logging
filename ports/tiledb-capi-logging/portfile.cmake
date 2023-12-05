# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()

get_filename_component(REPO_PATH "${CURRENT_PORT_DIR}/../../" ABSOLUTE)
get_filename_component(TILEDB_PATH "${REPO_PATH}/../" ABSOLUTE)

message("${REPO_PATH}")
message("${TILEDB_PATH}")

vcpkg_execute_build_process(
    COMMAND tar -czf tiledb-capi-logging.tar.gz internal
    WORKING_DIRECTORY ${TILEDB_PATH}
    LOGNAME "create-tarball-${TARGET_TRIPLET}"
)

vcpkg_extract_source_archive(
    SOURCE_PATH
    ARCHIVE "${TILEDB_PATH}/tiledb-capi-logging.tar.gz"
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
)

vcpkg_cmake_install()

file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")

file(
    INSTALL "${SOURCE_PATH}/LICENSE"
    DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}"
    RENAME copyright
)

configure_file(
    "${CMAKE_CURRENT_LIST_DIR}/usage"
    "${CURRENT_PACKAGES_DIR}/share/${PORT}/usage"
    COPYONLY
)
