/**
 *
 *  @file FsEntry.hpp
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
#ifndef VIX_FS_FSENTRY_HPP
#define VIX_FS_FSENTRY_HPP

#include <cstdint>
#include <string>

namespace vix::fs
{

  /**
   * @enum FsEntryType
   * @brief High-level filesystem entry type.
   *
   * This keeps the public API simple and predictable for developers.
   */
  enum class FsEntryType
  {
    Unknown = 0,
    File,
    Directory,
    Symlink
  };

  /**
   * @struct FsEntry
   * @brief A simple filesystem entry returned by listing APIs.
   *
   * This structure is intentionally lightweight and developer-friendly.
   * More advanced metadata can be added later without complicating the
   * first public version of the fs module.
   */
  struct FsEntry
  {
    /**
     * @brief Full entry path.
     */
    std::string path;

    /**
     * @brief Entry name only.
     *
     * Example:
     * `main.cpp`
     */
    std::string name;

    /**
     * @brief Entry type.
     */
    FsEntryType type{FsEntryType::Unknown};

    /**
     * @brief Entry size in bytes when known.
     *
     * For directories, this is typically 0 in the public API.
     */
    std::uintmax_t size{0};

    /**
     * @brief Whether the entry is hidden.
     */
    bool hidden{false};
  };

} // namespace vix::fs

#endif // VIX_FS_FSENTRY_HPP
