/**
 *
 *  @file Rename.cpp
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

#include <vix/fs/Move.hpp>
#include <vix/fs/Rename.hpp>

namespace vix::fs
{

  FsBoolResult rename(std::string_view from, std::string_view to)
  {
    return move(from, to);
  }

} // namespace vix::fs
