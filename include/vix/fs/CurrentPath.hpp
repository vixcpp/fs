/**
 *
 *  @file CurrentPath.hpp
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
#ifndef VIX_FS_CURRENTPATH_HPP
#define VIX_FS_CURRENTPATH_HPP

#include <vix/fs/FsResult.hpp>

namespace vix::fs
{

  /**
   * @brief Return the current working directory of the process.
   */
  [[nodiscard]] FsPathResult current_path();

} // namespace vix::fs

#endif // VIX_FS_CURRENTPATH_HPP
