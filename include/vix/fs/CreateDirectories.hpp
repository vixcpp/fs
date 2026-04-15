/**
 *
 *  @file CreateDirectories.hpp
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
#ifndef VIX_FS_CREATEDIRECTORIES_HPP
#define VIX_FS_CREATEDIRECTORIES_HPP

#include <string_view>

#include <vix/fs/FsResult.hpp>

namespace vix::fs
{

  /**
   * @brief Create a directory hierarchy on the real filesystem.
   *
   * Returns:
   * - true if at least one directory was created
   * - false if the full hierarchy already existed
   */
  [[nodiscard]] FsBoolResult create_directories(std::string_view path);

} // namespace vix::fs

#endif // VIX_FS_CREATEDIRECTORIES_HPP
