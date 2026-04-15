/**
 *
 *  @file FsOptions.hpp
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
#ifndef VIX_FS_FSOPTIONS_HPP
#define VIX_FS_FSOPTIONS_HPP

namespace vix::fs
{

  /**
   * @enum WriteMode
   * @brief File writing mode.
   */
  enum class WriteMode
  {
    Overwrite,
    Append
  };

  /**
   * @enum CopyMode
   * @brief Copy behavior when destination already exists.
   */
  enum class CopyMode
  {
    SkipExisting,
    OverwriteExisting
  };

  /**
   * @enum DirectoryListMode
   * @brief Directory listing mode.
   */
  enum class DirectoryListMode
  {
    Shallow,
    Recursive
  };

  /**
   * @struct FsOptions
   * @brief Common options reused by filesystem operations.
   *
   * The goal is to keep the public API easy to use while still allowing
   * Vix internals to support more explicit behavior when needed.
   */
  struct FsOptions
  {
    /**
     * @brief Whether parent directories should be created automatically.
     *
     * Useful for write operations such as write_file() or write_text().
     */
    bool create_parents{false};

    /**
     * @brief Whether existing targets may be overwritten.
     *
     * Useful for write/copy/move style operations.
     */
    bool overwrite_existing{true};

    /**
     * @brief Whether directory traversal should be recursive.
     *
     * Useful for list_directory() and remove_all()-style logic.
     */
    bool recursive{false};

    /**
     * @brief Whether hidden entries should be included.
     */
    bool include_hidden{true};

    /**
     * @brief Whether symbolic links should be followed when relevant.
     *
     * This is kept simple at the API level.
     */
    bool follow_symlinks{false};

    /**
     * @brief File writing mode.
     */
    WriteMode write_mode{WriteMode::Overwrite};

    /**
     * @brief Copy behavior when destination already exists.
     */
    CopyMode copy_mode{CopyMode::OverwriteExisting};

    /**
     * @brief Directory listing strategy.
     */
    DirectoryListMode list_mode{DirectoryListMode::Shallow};
  };

} // namespace vix::fs

#endif // VIX_FS_FSOPTIONS_HPP
