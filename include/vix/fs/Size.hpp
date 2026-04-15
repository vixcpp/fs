/**
 *
 *  @file Size.hpp
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
#ifndef VIX_FS_SIZE_HPP
#define VIX_FS_SIZE_HPP

#include <string_view>

#include <vix/fs/FsResult.hpp>

namespace vix::fs
{

  /**
   * @brief Return the size of a regular file in bytes.
   *
   * This function checks the real filesystem.
   */
  [[nodiscard]] FsSizeResult size(std::string_view path);

} // namespace vix::fs

#endif // VIX_FS_SIZE_HPP
