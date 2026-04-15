/**
 *
 *  @file Remove.cpp
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
#include <vix/fs/Remove.hpp>

namespace vix::fs
{

  FsBoolResult remove(std::string_view path)
  {
    if (path.empty())
    {
      return make_fs_error(FsErrorCode::EmptyPath, "path cannot be empty");
    }

    try
    {
      return std::filesystem::remove(std::filesystem::path(path));
    }
    catch (const std::filesystem::filesystem_error &e)
    {
      return make_fs_error(
          FsErrorCode::RemoveFailed,
          std::string("failed to remove path: ") + e.what());
    }
    catch (const std::exception &e)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          std::string("unexpected error while removing path: ") + e.what());
    }
    catch (...)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          "unknown error while removing path");
    }
  }

} // namespace vix::fs
