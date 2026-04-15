/**
 *
 *  @file WriteFile.hpp
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
#ifndef VIX_FS_WRITEFILE_HPP
#define VIX_FS_WRITEFILE_HPP

#include <string_view>

#include <vix/fs/FsResult.hpp>

namespace vix::fs
{

  /**
   * @brief Write raw binary bytes to a file.
   *
   * Existing content is overwritten.
   */
  [[nodiscard]] FsBoolResult write_file(std::string_view path,
                                        const Bytes &data);

} // namespace vix::fs

#endif // VIX_FS_WRITEFILE_HPP
