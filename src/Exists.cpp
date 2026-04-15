/**
 *
 *  @file Exists.cpp
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

#include <filesystem>
#include <string>

#include <vix/fs/Exists.hpp>
#include <vix/fs/FsError.hpp>

namespace vix::fs
{

  FsBoolResult exists(std::string_view path)
  {
    if (path.empty())
    {
      return make_fs_error(FsErrorCode::EmptyPath, "path cannot be empty");
    }

    try
    {
      return std::filesystem::exists(std::filesystem::path(path));
    }
    catch (const std::filesystem::filesystem_error &e)
    {
      return make_fs_error(
          FsErrorCode::InvalidPath,
          std::string("failed to check path existence: ") + e.what());
    }
    catch (const std::exception &e)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          std::string("unexpected error while checking path existence: ") + e.what());
    }
    catch (...)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          "unknown error while checking path existence");
    }
  }

} // namespace vix::fs
