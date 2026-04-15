/**
 *
 *  @file Touch.hpp
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
#ifndef VIX_FS_TOUCH_HPP
#define VIX_FS_TOUCH_HPP

#include <string_view>

#include <vix/fs/FsResult.hpp>

namespace vix::fs
{

  /**
   * @brief Create an empty file if it does not exist.
   *
   * If the file already exists, this function attempts to update its
   * modification time by opening it in append mode.
   *
   * Returns:
   * - true on success
   */
  [[nodiscard]] FsBoolResult touch(std::string_view path);

} // namespace vix::fs

#endif // VIX_FS_TOUCH_HPP
