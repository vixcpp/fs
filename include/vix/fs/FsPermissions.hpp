/**
 *
 *  @file FsPermissions.hpp
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
#ifndef VIX_FS_FSPERMISSIONS_HPP
#define VIX_FS_FSPERMISSIONS_HPP

#include <cstdint>

namespace vix::fs
{

  /**
   * @enum FsPermission
   * @brief Simple permission flags for filesystem entries.
   *
   * This abstraction keeps the public API easy to understand while still
   * allowing Vix internals to map to platform-specific permission models.
   */
  enum class FsPermission : std::uint32_t
  {
    None = 0,
    Read = 1u << 0,
    Write = 1u << 1,
    Execute = 1u << 2
  };

  /**
   * @brief Bitwise OR for FsPermission flags.
   */
  [[nodiscard]] constexpr FsPermission operator|(FsPermission lhs,
                                                 FsPermission rhs) noexcept
  {
    return static_cast<FsPermission>(
        static_cast<std::uint32_t>(lhs) |
        static_cast<std::uint32_t>(rhs));
  }

  /**
   * @brief Bitwise AND for FsPermission flags.
   */
  [[nodiscard]] constexpr FsPermission operator&(FsPermission lhs,
                                                 FsPermission rhs) noexcept
  {
    return static_cast<FsPermission>(
        static_cast<std::uint32_t>(lhs) &
        static_cast<std::uint32_t>(rhs));
  }

  /**
   * @brief Bitwise OR assignment for FsPermission flags.
   */
  constexpr FsPermission &operator|=(FsPermission &lhs,
                                     FsPermission rhs) noexcept
  {
    lhs = lhs | rhs;
    return lhs;
  }

  /**
   * @brief Bitwise AND assignment for FsPermission flags.
   */
  constexpr FsPermission &operator&=(FsPermission &lhs,
                                     FsPermission rhs) noexcept
  {
    lhs = lhs & rhs;
    return lhs;
  }

  /**
   * @brief Return true if all requested permission flags are present.
   */
  [[nodiscard]] constexpr bool has_permission(FsPermission value,
                                              FsPermission expected) noexcept
  {
    return (static_cast<std::uint32_t>(value) &
            static_cast<std::uint32_t>(expected)) ==
           static_cast<std::uint32_t>(expected);
  }

} // namespace vix::fs

#endif // VIX_FS_FSPERMISSIONS_HPP
