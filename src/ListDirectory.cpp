/**
 *
 *  @file ListDirectory.cpp
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

#include <exception>
#include <filesystem>
#include <string>
#include <vector>

#include <vix/fs/FsError.hpp>
#include <vix/fs/ListDirectory.hpp>

namespace vix::fs
{

  namespace
  {
    [[nodiscard]] bool is_hidden_path(const std::filesystem::path &path)
    {
      const std::string name = path.filename().string();
      return !name.empty() && name.front() == '.';
    }

    [[nodiscard]] FsEntryType to_entry_type(const std::filesystem::directory_entry &entry)
    {
      try
      {
        if (entry.is_regular_file())
        {
          return FsEntryType::File;
        }

        if (entry.is_directory())
        {
          return FsEntryType::Directory;
        }

        if (entry.is_symlink())
        {
          return FsEntryType::Symlink;
        }
      }
      catch (...)
      {
        return FsEntryType::Unknown;
      }

      return FsEntryType::Unknown;
    }

    [[nodiscard]] std::uintmax_t get_entry_size(const std::filesystem::directory_entry &entry)
    {
      try
      {
        if (entry.is_regular_file())
        {
          return entry.file_size();
        }
      }
      catch (...)
      {
        return 0;
      }

      return 0;
    }

    [[nodiscard]] FsEntry build_entry(const std::filesystem::directory_entry &entry)
    {
      FsEntry out;
      out.path = entry.path().string();
      out.name = entry.path().filename().string();
      out.type = to_entry_type(entry);
      out.size = get_entry_size(entry);
      out.hidden = is_hidden_path(entry.path());
      return out;
    }
  } // namespace

  FsEntryListResult list_directory(std::string_view path, const FsOptions &options)
  {
    if (path.empty())
    {
      return make_fs_error(FsErrorCode::EmptyPath, "directory path cannot be empty");
    }

    try
    {
      const std::filesystem::path fs_path(path);

      if (!std::filesystem::exists(fs_path))
      {
        return make_fs_error(FsErrorCode::NotFound, "directory path does not exist");
      }

      if (!std::filesystem::is_directory(fs_path))
      {
        return make_fs_error(FsErrorCode::NotADirectory, "path is not a directory");
      }

      std::vector<FsEntry> entries;

      if (options.recursive || options.list_mode == DirectoryListMode::Recursive)
      {
        for (const auto &entry : std::filesystem::recursive_directory_iterator(fs_path))
        {
          const bool hidden = is_hidden_path(entry.path());
          if (!options.include_hidden && hidden)
          {
            continue;
          }

          entries.push_back(build_entry(entry));
        }
      }
      else
      {
        for (const auto &entry : std::filesystem::directory_iterator(fs_path))
        {
          const bool hidden = is_hidden_path(entry.path());
          if (!options.include_hidden && hidden)
          {
            continue;
          }

          entries.push_back(build_entry(entry));
        }
      }

      return entries;
    }
    catch (const std::filesystem::filesystem_error &e)
    {
      return make_fs_error(
          FsErrorCode::ListFailed,
          std::string("failed to list directory: ") + e.what());
    }
    catch (const std::exception &e)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          std::string("unexpected error while listing directory: ") + e.what());
    }
    catch (...)
    {
      return make_fs_error(
          FsErrorCode::Unknown,
          "unknown error while listing directory");
    }
  }

} // namespace vix::fs
