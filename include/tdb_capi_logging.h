/**
 * @file include/tdb_capi_logging.h
 *
 * @section LICENSE
 *
 * The MIT License
 *
 * @copyright Copyright (c) 2023 TileDB, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @section DESCRIPTION
 *
 * Helper functions for TileDB CAPI Logging
 */

#ifndef TILEDB_CAPI_LOGGING
#define TILEDB_CAPI_LOGGING

#include <fstream>
#include <mutex>
#include <optional>
#include <string>

#include "tiledb_capi_logging_export.h"

namespace tiledb::internal::logging {

class TileDBCAPILoggerTokens {
 public:
  TileDBCAPILoggerTokens() {}
  TileDBCAPILoggerTokens(const std::optional<std::string>& token) : token_(token.value_or("")) {}

  inline const std::string& token() const {
    return token_;
  }

 private:
  std::string token_;
};

class TileDBCAPILogger {
 public:
  /* ********************************* */
  /*     CONSTRUCTORS & DESTRUCTORS    */
  /* ********************************* */

  TileDBCAPILogger();
  TileDBCAPILogger(const TileDBCAPILogger&) = delete;
  TileDBCAPILogger(TileDBCAPILogger&&) = delete;

  ~TileDBCAPILogger() = default;

  TileDBCAPILogger& operator=(const TileDBCAPILogger&) = delete;
  TileDBCAPILogger& operator=(TileDBCAPILogger&&) = delete;


  /* ********************************* */
  /*                API                */
  /* ********************************* */

  static TileDBCAPILogger& get();

  void log(const TileDBCAPILoggerTokens& tokens, const char* function_name, const std::string& args);

 private:
  /* ********************************* */
  /*         PRIVATE ATTRIBUTES        */
  /* ********************************* */

  std::mutex mtx_;
  std::ofstream out_;
};

}

TILEDB_CAPI_LOGGING_EXPORT void tiledb_capi_log(const tiledb::internal::logging::TileDBCAPILoggerTokens& tokens, const char* function_name, const std::string& args);

#endif // TILEDB_CAPI_LOGGING
