/**
 *
 *  @file WriteFile.cpp
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
#include <vix/fs/WriteFile.hpp>

namespace vix::fs
{

  FsBoolResult write_file(std::string_view path, const Bytes &data)
  {
    if (path.empty())
    {
      return make_fs_error(FsErrorCode::EmptyPath, "file path cannot be empty");
    }

    std::ofstream file(std::string(path), std::ios::binary | std::ios::trunc);
    if (!file)
    {
      return make_fs_error(FsErrorCode::WriteFailed, "failed to open file for writing");
    }

    if (!data.empty())
    {
      file.write(reinterpret_cast<const char *>(data.data()),
                 static_cast<std::streamsize>(data.size()));

      if (!file)
      {
        return make_fs_error(FsErrorCode::WriteFailed, "failed to write file content");
      }
    }

    return true;
  }

} // namespace vix::fs
