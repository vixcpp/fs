/**
 *
 *  @file EnsureDirectory.cpp
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

#include <vix/fs/EnsureDirectory.hpp>
#include <vix/fs/FsError.hpp>

namespace vix::fs
{

  FsBoolResult ensure_directory(std::string_view path)
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
          return true;
        }

        return make_fs_error(
            FsErrorCode::AlreadyExists,
            "path already exists and is not a directory");
      }

      std::filesystem::create_directories(fs_path);
      return true;
    }
    catch (const std::filesystem::filesystem_error &e)
    {
      return make_fs_error(
          FsErrorCode::CreateFailed,
          std::string("failed to ensure directory: ") + e.what());
    }
    catch (const std::exception &e)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          std::string("unexpected error while ensuring directory: ") + e.what());
    }
    catch (...)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          "unknown error while ensuring directory");
    }
  }

} // namespace vix::fs
