/**
 *
 *  @file CreateDirectories.cpp
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

#include <vix/fs/CreateDirectories.hpp>
#include <vix/fs/FsError.hpp>

namespace vix::fs
{

  FsBoolResult create_directories(std::string_view path)
  {
    if (path.empty())
    {
      return make_fs_error(FsErrorCode::EmptyPath, "directory path cannot be empty");
    }

    try
    {
      const std::filesystem::path fs_path(path);

      if (std::filesystem::exists(fs_path))
      {
        if (std::filesystem::is_directory(fs_path))
        {
          return false;
        }

        return make_fs_error(
            FsErrorCode::AlreadyExists,
            "path already exists and is not a directory");
      }

      return std::filesystem::create_directories(fs_path);
    }
    catch (const std::filesystem::filesystem_error &e)
    {
      return make_fs_error(
          FsErrorCode::CreateFailed,
          std::string("failed to create directories: ") + e.what());
    }
    catch (const std::exception &e)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          std::string("unexpected error while creating directories: ") + e.what());
    }
    catch (...)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          "unknown error while creating directories");
    }
  }

} // namespace vix::fs
