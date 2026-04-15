/**
 *
 *  @file FsError.hpp
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
#ifndef VIX_FS_FSERROR_HPP
#define VIX_FS_FSERROR_HPP

#include <string>

#include <vix/error/Error.hpp>
#include <vix/error/ErrorCategory.hpp>
#include <vix/error/ErrorCode.hpp>

namespace vix::fs
{

  /**
   * @enum FsErrorCode
   * @brief Filesystem-specific semantic error codes.
   *
   * These codes describe common failures that can happen while interacting
   * with the real filesystem.
   *
   * The goal is to keep the public API simple for developers while still
   * preserving enough structure internally for diagnostics and debugging.
   */
  enum class FsErrorCode
  {
    None = 0,
    EmptyPath,
    InvalidPath,
    NotFound,
    AlreadyExists,
    NotAFile,
    NotADirectory,
    PermissionDenied,
    ReadFailed,
    WriteFailed,
    CreateFailed,
    RemoveFailed,
    CopyFailed,
    MoveFailed,
    ListFailed,
    OpenFailed,
    CloseFailed,
    InvalidOperation,
    Unknown
  };

  /**
   * @brief Return the default filesystem error category.
   */
  [[nodiscard]] inline constexpr vix::error::ErrorCategory fs_error_category() noexcept
  {
    return vix::error::ErrorCategory("fs");
  }

  /**
   * @brief Convert an FsErrorCode to a generic Vix ErrorCode.
   *
   * This keeps the fs module aligned with the shared Vix error model.
   */
  [[nodiscard]] inline constexpr vix::error::ErrorCode to_error_code(FsErrorCode code) noexcept
  {
    using vix::error::ErrorCode;

    switch (code)
    {
    case FsErrorCode::None:
      return ErrorCode::Ok;

    case FsErrorCode::EmptyPath:
    case FsErrorCode::InvalidPath:
    case FsErrorCode::InvalidOperation:
      return ErrorCode::InvalidArgument;

    case FsErrorCode::NotFound:
      return ErrorCode::NotFound;

    case FsErrorCode::AlreadyExists:
      return ErrorCode::AlreadyExists;

    case FsErrorCode::NotAFile:
    case FsErrorCode::NotADirectory:
      return ErrorCode::InvalidState;

    case FsErrorCode::PermissionDenied:
      return ErrorCode::PermissionDenied;

    case FsErrorCode::ReadFailed:
    case FsErrorCode::WriteFailed:
    case FsErrorCode::OpenFailed:
    case FsErrorCode::CloseFailed:
      return ErrorCode::IoError;

    case FsErrorCode::CreateFailed:
    case FsErrorCode::RemoveFailed:
    case FsErrorCode::CopyFailed:
    case FsErrorCode::MoveFailed:
    case FsErrorCode::ListFailed:
      return ErrorCode::FilesystemError;

    case FsErrorCode::Unknown:
      return ErrorCode::Unknown;
    }

    return ErrorCode::Unknown;
  }

  /**
   * @brief Convert an FsErrorCode to a stable human-readable name.
   */
  [[nodiscard]] inline const char *to_string(FsErrorCode code) noexcept
  {
    switch (code)
    {
    case FsErrorCode::None:
      return "none";
    case FsErrorCode::EmptyPath:
      return "empty_path";
    case FsErrorCode::InvalidPath:
      return "invalid_path";
    case FsErrorCode::NotFound:
      return "not_found";
    case FsErrorCode::AlreadyExists:
      return "already_exists";
    case FsErrorCode::NotAFile:
      return "not_a_file";
    case FsErrorCode::NotADirectory:
      return "not_a_directory";
    case FsErrorCode::PermissionDenied:
      return "permission_denied";
    case FsErrorCode::ReadFailed:
      return "read_failed";
    case FsErrorCode::WriteFailed:
      return "write_failed";
    case FsErrorCode::CreateFailed:
      return "create_failed";
    case FsErrorCode::RemoveFailed:
      return "remove_failed";
    case FsErrorCode::CopyFailed:
      return "copy_failed";
    case FsErrorCode::MoveFailed:
      return "move_failed";
    case FsErrorCode::ListFailed:
      return "list_failed";
    case FsErrorCode::OpenFailed:
      return "open_failed";
    case FsErrorCode::CloseFailed:
      return "close_failed";
    case FsErrorCode::InvalidOperation:
      return "invalid_operation";
    case FsErrorCode::Unknown:
      return "unknown";
    }

    return "unknown";
  }

  /**
   * @brief Build a structured Vix error from an FsErrorCode.
   *
   * @param code Filesystem-specific error code.
   * @param message Human-readable message.
   */
  [[nodiscard]] inline vix::error::Error make_fs_error(FsErrorCode code, std::string message)
  {
    return vix::error::Error(
        to_error_code(code),
        fs_error_category(),
        std::move(message));
  }

} // namespace vix::fs

#endif // VIX_FS_FSERROR_HPP
