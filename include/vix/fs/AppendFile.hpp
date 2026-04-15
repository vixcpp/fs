/**
 *
 *  @file AppendFile.hpp
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
#ifndef VIX_FS_APPENDFILE_HPP
#define VIX_FS_APPENDFILE_HPP

#include <string_view>

#include <vix/fs/FsResult.hpp>

namespace vix::fs
{

  /**
   * @brief Append raw binary bytes to a file.
   *
   * The file is created if it does not exist.
   */
  [[nodiscard]] FsBoolResult append_file(std::string_view path,
                                         const Bytes &data);

  /**
   * @brief Append text content to a file.
   *
   * The file is created if it does not exist.
   */
  [[nodiscard]] FsBoolResult append_file(std::string_view path,
                                         std::string_view content);

} // namespace vix::fs

#endif // VIX_FS_APPENDFILE_HPP
