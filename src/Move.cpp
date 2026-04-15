/**
 *
 *  @file Move.cpp
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
#include <vix/fs/Move.hpp>

namespace vix::fs
{

  FsBoolResult move(std::string_view from, std::string_view to)
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

      std::filesystem::rename(source_path, destination_path);
      return true;
    }
    catch (const std::filesystem::filesystem_error &e)
    {
      return make_fs_error(
          FsErrorCode::MoveFailed,
          std::string("failed to move path: ") + e.what());
    }
    catch (const std::exception &e)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          std::string("unexpected error while moving path: ") + e.what());
    }
    catch (...)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          "unknown error while moving path");
    }
  }

} // namespace vix::fs
