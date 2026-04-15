/**
 *
 *  @file AppendFile.cpp
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

#include <vix/fs/AppendFile.hpp>
#include <vix/fs/FsError.hpp>

namespace vix::fs
{

  FsBoolResult append_file(std::string_view path, const Bytes &data)
  {
    if (path.empty())
    {
      return make_fs_error(FsErrorCode::EmptyPath, "file path cannot be empty");
    }

    std::ofstream file(std::string(path), std::ios::binary | std::ios::app);
    if (!file)
    {
      return make_fs_error(FsErrorCode::WriteFailed, "failed to open file for appending");
    }

    if (!data.empty())
    {
      file.write(reinterpret_cast<const char *>(data.data()),
                 static_cast<std::streamsize>(data.size()));

      if (!file)
      {
        return make_fs_error(FsErrorCode::WriteFailed, "failed to append file content");
      }
    }

    return true;
  }

  FsBoolResult append_file(std::string_view path, std::string_view content)
  {
    if (path.empty())
    {
      return make_fs_error(FsErrorCode::EmptyPath, "file path cannot be empty");
    }

    std::ofstream file(std::string(path), std::ios::app);
    if (!file)
    {
      return make_fs_error(FsErrorCode::WriteFailed, "failed to open text file for appending");
    }

    file.write(content.data(), static_cast<std::streamsize>(content.size()));
    if (!file)
    {
      return make_fs_error(FsErrorCode::WriteFailed, "failed to append text file content");
    }

    return true;
  }

} // namespace vix::fs
