/**
 *
 *  @file Rename.hpp
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
#ifndef VIX_FS_RENAME_HPP
#define VIX_FS_RENAME_HPP

#include <string_view>

#include <vix/fs/FsResult.hpp>

namespace vix::fs
{

  /**
   * @brief Rename a file or directory.
   *
   * Returns:
   * - true on success
   */
  [[nodiscard]] FsBoolResult rename(std::string_view from,
                                    std::string_view to);

} // namespace vix::fs

#endif // VIX_FS_RENAME_HPP
