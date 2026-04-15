/**
 *
 *  @file WriteText.hpp
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
#ifndef VIX_FS_WRITETEXT_HPP
#define VIX_FS_WRITETEXT_HPP

#include <string_view>

#include <vix/fs/FsResult.hpp>

namespace vix::fs
{

  /**
   * @brief Write text content to a file.
   *
   * Existing content is overwritten.
   */
  [[nodiscard]] FsBoolResult write_text(std::string_view path,
                                        std::string_view content);

} // namespace vix::fs

#endif // VIX_FS_WRITETEXT_HPP
