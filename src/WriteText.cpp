/**
 *
 *  @file WriteText.cpp
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
#include <string>

#include <vix/fs/FsError.hpp>
#include <vix/fs/WriteText.hpp>

namespace vix::fs
{

  FsBoolResult write_text(std::string_view path, std::string_view content)
  {
    if (path.empty())
    {
      return make_fs_error(FsErrorCode::EmptyPath, "file path cannot be empty");
    }

    std::ofstream file(std::string(path), std::ios::trunc);
    if (!file)
    {
      return make_fs_error(FsErrorCode::WriteFailed, "failed to open text file for writing");
    }

    file.write(content.data(), static_cast<std::streamsize>(content.size()));
    if (!file)
    {
      return make_fs_error(FsErrorCode::WriteFailed, "failed to write text file content");
    }

    return true;
  }

} // namespace vix::fs
