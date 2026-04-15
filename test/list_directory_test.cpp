#include <cassert>
#include <string>

#include <vix/fs/CreateDirectories.hpp>
#include <vix/fs/ListDirectory.hpp>
#include <vix/fs/RemoveAll.hpp>
#include <vix/fs/WriteText.hpp>

namespace
{
  bool contains_name(const std::vector<vix::fs::FsEntry> &entries,
                     const std::string &name)
  {
    for (const auto &entry : entries)
    {
      if (entry.name == name)
      {
        return true;
      }
    }
    return false;
  }

  void test_list_directory_returns_error_for_empty_path()
  {
    auto result = vix::fs::list_directory("");
    assert(!result);
  }

  void test_list_directory_returns_error_for_missing_path()
  {
    auto result = vix::fs::list_directory("fs_test_tmp/list/missing");
    assert(!result);
  }

  void test_list_directory_lists_shallow_entries()
  {
    const std::string dir = "fs_test_tmp/list_shallow";
    const std::string nested = dir + "/nested";
    const std::string file = dir + "/root.txt";
    const std::string child = nested + "/child.txt";

    auto created = vix::fs::create_directories(nested);
    assert(created);

    auto w1 = vix::fs::write_text(file, "root");
    auto w2 = vix::fs::write_text(child, "child");
    assert(w1 && w1.value());
    assert(w2 && w2.value());

    auto listed = vix::fs::list_directory(dir);
    assert(listed);

    const auto &entries = listed.value();
    assert(contains_name(entries, "root.txt"));
    assert(contains_name(entries, "nested"));
    assert(!contains_name(entries, "child.txt"));

    auto removed = vix::fs::remove_all(dir);
    assert(removed);
  }

  void test_list_directory_lists_recursive_entries()
  {
    const std::string dir = "fs_test_tmp/list_recursive";
    const std::string nested = dir + "/nested";
    const std::string child = nested + "/child.txt";

    auto created = vix::fs::create_directories(nested);
    assert(created);

    auto written = vix::fs::write_text(child, "child");
    assert(written);
    assert(written.value());

    vix::fs::FsOptions options;
    options.recursive = true;

    auto listed = vix::fs::list_directory(dir, options);
    assert(listed);

    const auto &entries = listed.value();
    assert(contains_name(entries, "nested"));
    assert(contains_name(entries, "child.txt"));

    auto removed = vix::fs::remove_all(dir);
    assert(removed);
  }
} // namespace

int main()
{
  test_list_directory_returns_error_for_empty_path();
  test_list_directory_returns_error_for_missing_path();
  test_list_directory_lists_shallow_entries();
  test_list_directory_lists_recursive_entries();
  return 0;
}
