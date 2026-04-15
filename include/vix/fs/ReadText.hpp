/**
 *
 *  @file ReadText.hpp
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
#ifndef VIX_FS_READTEXT_HPP
#define VIX_FS_READTEXT_HPP

#include <string_view>

#include <vix/fs/FsResult.hpp>

namespace vix::fs
{

  /**
   * @brief Read a file as text.
   *
   * This function reads the real filesystem.
   */
  [[nodiscard]] FsStringResult read_text(std::string_view path);

} // namespace vix::fs

#endif // VIX_FS_READTEXT_HPP
