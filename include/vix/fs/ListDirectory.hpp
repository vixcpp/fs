/**
 *
 *  @file ListDirectory.hpp
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
#ifndef VIX_FS_LISTDIRECTORY_HPP
#define VIX_FS_LISTDIRECTORY_HPP

#include <string_view>

#include <vix/fs/FsOptions.hpp>
#include <vix/fs/FsResult.hpp>

namespace vix::fs
{

  /**
   * @brief List filesystem entries inside a directory.
   *
   * By default, the listing is shallow.
   * Use FsOptions to request recursive traversal or to exclude hidden entries.
   */
  [[nodiscard]] FsEntryListResult list_directory(std::string_view path,
                                                 const FsOptions &options = {});

} // namespace vix::fs

#endif // VIX_FS_LISTDIRECTORY_HPP
