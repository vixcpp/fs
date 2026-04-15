/**
 *
 *  @file ReadText.cpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2025, Gaspard Kirira.
 *  All rights reserved.
 *  https://github.com/vixcpp/vix
 *
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Vix.cpp
 */

#include <fstream>
#include <sstream>
#include <string>

#include <vix/fs/FsError.hpp>
#include <vix/fs/ReadText.hpp>

namespace vix::fs
{

  FsStringResult read_text(std::string_view path)
  {
    if (path.empty())
    {
      return make_fs_error(FsErrorCode::EmptyPath, "file path cannot be empty");
    }

    std::ifstream file{std::string(path)};
    if (!file)
    {
      return make_fs_error(FsErrorCode::ReadFailed, "failed to open text file for reading");
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();

    if (!file.good() && !file.eof())
    {
      return make_fs_error(FsErrorCode::ReadFailed, "failed to read text file content");
    }

    return buffer.str();
  }

} // namespace vix::fs
