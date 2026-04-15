/**
 *
 *  @file EnsureDirectory.hpp
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
#ifndef VIX_FS_ENSUREDIRECTORY_HPP
#define VIX_FS_ENSUREDIRECTORY_HPP

#include <string_view>

#include <vix/fs/FsResult.hpp>

namespace vix::fs
{

  /**
   * @brief Ensure that a directory exists on the real filesystem.
   *
   * Returns:
   * - true if the directory exists after the operation
   *
   * This function succeeds both when:
   * - the directory already exists
   * - the directory had to be created
   */
  [[nodiscard]] FsBoolResult ensure_directory(std::string_view path);

} // namespace vix::fs

#endif // VIX_FS_ENSUREDIRECTORY_HPP
