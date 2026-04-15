/**
 *
 *  @file Touch.cpp
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
#include <fstream>
#include <string>

#include <vix/fs/FsError.hpp>
#include <vix/fs/Touch.hpp>

namespace vix::fs
{

  FsBoolResult touch(std::string_view path)
  {
    if (path.empty())
    {
      return make_fs_error(FsErrorCode::EmptyPath, "file path cannot be empty");
    }

    try
    {
      const std::filesystem::path fs_path(path);

      if (std::filesystem::exists(fs_path))
      {
        if (std::filesystem::is_directory(fs_path))
        {
          return make_fs_error(
              FsErrorCode::InvalidOperation,
              "cannot touch a directory path");
        }

        std::ofstream existing(fs_path, std::ios::app);
        if (!existing)
        {
          return make_fs_error(
              FsErrorCode::WriteFailed,
              "failed to open existing file for touch");
        }

        return true;
      }

      std::ofstream created(fs_path);
      if (!created)
      {
        return make_fs_error(
            FsErrorCode::CreateFailed,
            "failed to create file");
      }

      return true;
    }
    catch (const std::filesystem::filesystem_error &e)
    {
      return make_fs_error(
          FsErrorCode::CreateFailed,
          std::string("failed to touch file: ") + e.what());
    }
    catch (const std::exception &e)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          std::string("unexpected error while touching file: ") + e.what());
    }
    catch (...)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          "unknown error while touching file");
    }
  }

} // namespace vix::fs
