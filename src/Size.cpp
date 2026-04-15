/**
 *
 *  @file Size.cpp
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

#include <exception>
#include <filesystem>
#include <string>

#include <vix/fs/FsError.hpp>
#include <vix/fs/Size.hpp>

namespace vix::fs
{

  FsSizeResult size(std::string_view path)
  {
    if (path.empty())
    {
      return make_fs_error(FsErrorCode::EmptyPath, "path cannot be empty");
    }

    try
    {
      const std::filesystem::path fs_path(path);

      if (!std::filesystem::exists(fs_path))
      {
        return make_fs_error(FsErrorCode::NotFound, "path does not exist");
      }

      if (!std::filesystem::is_regular_file(fs_path))
      {
        return make_fs_error(FsErrorCode::NotAFile, "path is not a regular file");
      }

      return std::filesystem::file_size(fs_path);
    }
    catch (const std::filesystem::filesystem_error &e)
    {
      return make_fs_error(
          FsErrorCode::ReadFailed,
          std::string("failed to get file size: ") + e.what());
    }
    catch (const std::exception &e)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          std::string("unexpected error while getting file size: ") + e.what());
    }
    catch (...)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          "unknown error while getting file size");
    }
  }

} // namespace vix::fs
