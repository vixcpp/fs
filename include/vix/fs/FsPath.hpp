/**
 *
 *  @file FsPath.hpp
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
#ifndef VIX_FS_FSPATH_HPP
#define VIX_FS_FSPATH_HPP

#include <string>

namespace vix::fs
{

  /**
   * @brief Public filesystem path type.
   *
   * For the developer-facing API, Vix keeps paths simple and uses std::string
   * as the primary path representation.
   *
   * Internally, the fs module may rely on more advanced handling, including
   * lexical normalization, platform-specific conversions, and integration with
   * the vix::path module.
   */
  using FsPath = std::string;

} // namespace vix::fs

#endif // VIX_FS_FSPATH_HPP
