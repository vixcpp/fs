/**
 *
 *  @file Copy.cpp
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

#include <vix/fs/Copy.hpp>
#include <vix/fs/FsError.hpp>

namespace vix::fs
{

  FsBoolResult copy(std::string_view from, std::string_view to)
  {
    if (from.empty())
    {
      return make_fs_error(FsErrorCode::EmptyPath, "source path cannot be empty");
    }

    if (to.empty())
    {
      return make_fs_error(FsErrorCode::EmptyPath, "destination path cannot be empty");
    }

    try
    {
      const std::filesystem::path source_path(from);
      const std::filesystem::path destination_path(to);

      if (!std::filesystem::exists(source_path))
      {
        return make_fs_error(FsErrorCode::NotFound, "source path does not exist");
      }

      if (std::filesystem::is_directory(source_path))
      {
        std::filesystem::copy(
            source_path,
            destination_path,
            std::filesystem::copy_options::recursive |
                std::filesystem::copy_options::overwrite_existing);
      }
      else
      {
        std::filesystem::copy_file(
            source_path,
            destination_path,
            std::filesystem::copy_options::overwrite_existing);
      }

      return true;
    }
    catch (const std::filesystem::filesystem_error &e)
    {
      return make_fs_error(
          FsErrorCode::CopyFailed,
          std::string("failed to copy path: ") + e.what());
    }
    catch (const std::exception &e)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          std::string("unexpected error while copying path: ") + e.what());
    }
    catch (...)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          "unknown error while copying path");
    }
  }

} // namespace vix::fs
