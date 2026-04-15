/**
 *
 *  @file CurrentPath.cpp
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

#include <vix/fs/CurrentPath.hpp>
#include <vix/fs/FsError.hpp>

namespace vix::fs
{

  FsPathResult current_path()
  {
    try
    {
      return std::filesystem::current_path().string();
    }
    catch (const std::filesystem::filesystem_error &e)
    {
      return make_fs_error(
          FsErrorCode::InvalidOperation,
          std::string("failed to get current path: ") + e.what());
    }
    catch (const std::exception &e)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          std::string("unexpected error while getting current path: ") + e.what());
    }
    catch (...)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          "unknown error while getting current path");
    }
  }

} // namespace vix::fs
