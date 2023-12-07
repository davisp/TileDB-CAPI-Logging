
#include <fstream>
#include <iostream>
#include <string>

#include "tdb_capi_logging.h"

namespace tiledb::internal::logging {

TileDBCAPILogger::TileDBCAPILogger() {
  out_.open("tdb_capi.log");
  if (!out_.is_open()) {
    throw std::runtime_error("Error opening tdb_capi.log");
  }
}

TileDBCAPILogger& TileDBCAPILogger::get() {
  static TileDBCAPILogger singleton;
  return singleton;
}

void TileDBCAPILogger::log(const TileDBCAPILoggerTokens& tokens, const char* function_name, const std::string& args) {
  std::lock_guard lock(mtx_);
  out_ << "[trace_id:" << tokens.token() << "] ";
  out_ << function_name << args << std::endl;
}

} // namespace tiledb::internal::logging

void tiledb_capi_log(const tiledb::internal::logging::TileDBCAPILoggerTokens& tokens, const char* function_name, const std::string& args) {
  tiledb::internal::logging::TileDBCAPILogger::get().log(tokens, function_name, args);
}
