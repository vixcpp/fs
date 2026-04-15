/**
 *
 *  @file ReadFile.cpp
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
#include <vector>

#include <vix/fs/FsError.hpp>
#include <vix/fs/ReadFile.hpp>

namespace vix::fs
{

  FsBytesResult read_file(std::string_view path)
  {
    if (path.empty())
    {
      return make_fs_error(FsErrorCode::EmptyPath, "file path cannot be empty");
    }

    std::ifstream file(std::string(path), std::ios::binary);
    if (!file)
    {
      return make_fs_error(FsErrorCode::ReadFailed, "failed to open file for reading");
    }

    file.seekg(0, std::ios::end);
    const std::streampos end = file.tellg();
    if (end < 0)
    {
      return make_fs_error(FsErrorCode::ReadFailed, "failed to determine file size");
    }

    Bytes data(static_cast<std::size_t>(end));
    file.seekg(0, std::ios::beg);

    if (!data.empty())
    {
      file.read(reinterpret_cast<char *>(data.data()),
                static_cast<std::streamsize>(data.size()));

      if (!file)
      {
        return make_fs_error(FsErrorCode::ReadFailed, "failed to read file content");
      }
    }

    return data;
  }

} // namespace vix::fs
