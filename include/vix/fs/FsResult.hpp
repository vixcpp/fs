/**
 *
 *  @file FsResult.hpp
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
#ifndef VIX_FS_FSRESULT_HPP
#define VIX_FS_FSRESULT_HPP

#include <cstdint>
#include <string>
#include <vector>

#include <vix/error/Result.hpp>
#include <vix/fs/FsEntry.hpp>

namespace vix::fs
{

  /**
   * @brief Standard binary buffer type used by filesystem APIs.
   *
   * This is suitable for read_file(), write_file(), append_file(), etc.
   */
  using Bytes = std::vector<std::uint8_t>;

  /**
   * @brief Standard result type for filesystem operations returning success only.
   *
   * Example use cases:
   * - create_directory()
   * - remove()
   * - copy()
   * - move()
   */
  using FsBoolResult = vix::error::Result<bool>;

  /**
   * @brief Standard result type for filesystem operations returning a path.
   *
   * Example use cases:
   * - current_path()
   * - temp_directory()
   */
  using FsPathResult = vix::error::Result<std::string>;

  /**
   * @brief Standard result type for filesystem operations returning text content.
   *
   * Example use cases:
   * - read_text()
   */
  using FsStringResult = vix::error::Result<std::string>;

  /**
   * @brief Standard result type for filesystem operations returning binary content.
   *
   * Example use cases:
   * - read_file()
   */
  using FsBytesResult = vix::error::Result<Bytes>;

  /**
   * @brief Standard result type for filesystem operations returning a list of paths.
   *
   * Example use cases:
   * - simple directory listing APIs returning paths only
   */
  using FsPathListResult = vix::error::Result<std::vector<std::string>>;

  /**
   * @brief Standard result type for filesystem operations returning a list of entries.
   *
   * Example use cases:
   * - list_directory()
   */
  using FsEntryListResult = vix::error::Result<std::vector<FsEntry>>;

  /**
   * @brief Standard result type for filesystem operations returning a file size.
   *
   * Example use cases:
   * - size()
   * - remove_all()
   */
  using FsSizeResult = vix::error::Result<std::uintmax_t>;

} // namespace vix::fs

#endif // VIX_FS_FSRESULT_HPP
