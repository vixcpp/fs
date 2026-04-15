/**
 *
 *  @file TempDirectory.hpp
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
#ifndef VIX_FS_TEMPDIRECTORY_HPP
#define VIX_FS_TEMPDIRECTORY_HPP

#include <vix/fs/FsResult.hpp>

namespace vix::fs
{

  /**
   * @brief Return the system temporary directory path.
   */
  [[nodiscard]] FsPathResult temp_directory();

} // namespace vix::fs

#endif // VIX_FS_TEMPDIRECTORY_HPP
