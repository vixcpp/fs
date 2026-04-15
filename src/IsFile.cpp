/**
 *
 *  @file IsFile.cpp
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
#include <vix/fs/IsFile.hpp>

namespace vix::fs
{

  FsBoolResult is_file(std::string_view path)
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
        return false;
      }

      return std::filesystem::is_regular_file(fs_path);
    }
    catch (const std::filesystem::filesystem_error &e)
    {
      return make_fs_error(
          FsErrorCode::InvalidPath,
          std::string("failed to check whether path is a file: ") + e.what());
    }
    catch (const std::exception &e)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          std::string("unexpected error while checking whether path is a file: ") + e.what());
    }
    catch (...)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          "unknown error while checking whether path is a file");
    }
  }

} // namespace vix::fs
