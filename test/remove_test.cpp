#include <cassert>
#include <string>

#include <vix/fs/CreateDirectories.hpp>
#include <vix/fs/Exists.hpp>
#include <vix/fs/Remove.hpp>
#include <vix/fs/RemoveAll.hpp>
#include <vix/fs/WriteText.hpp>

namespace
{
  void test_remove_returns_error_for_empty_path()
  {
    auto result = vix::fs::remove("");
    assert(!result);
  }

  void test_remove_returns_false_for_missing_path()
  {
    auto result = vix::fs::remove("fs_test_tmp/remove/missing.txt");
    assert(result);
    assert(result.value() == false);
  }

  void test_remove_deletes_file()
  {
    const std::string dir = "fs_test_tmp/remove_file";
    const std::string path = dir + "/file.txt";

    auto created = vix::fs::create_directories(dir);
    assert(created);

    auto written = vix::fs::write_text(path, "hello");
    assert(written);
    assert(written.value());

    auto removed = vix::fs::remove(path);
    assert(removed);
    assert(removed.value() == true);

    auto exists = vix::fs::exists(path);
    assert(exists);
    assert(exists.value() == false);

    auto cleanup = vix::fs::remove_all(dir);
    assert(cleanup);
  }

  void test_remove_all_deletes_directory_tree()
  {
    const std::string dir = "fs_test_tmp/remove_all";
    const std::string nested = dir + "/a/b";
    const std::string file1 = dir + "/root.txt";
    const std::string file2 = nested + "/leaf.txt";

    auto created = vix::fs::create_directories(nested);
    assert(created);

    auto w1 = vix::fs::write_text(file1, "root");
    auto w2 = vix::fs::write_text(file2, "leaf");
    assert(w1 && w1.value());
    assert(w2 && w2.value());

    auto removed = vix::fs::remove_all(dir);
    assert(removed);
    assert(removed.value() >= 3);

    auto exists = vix::fs::exists(dir);
    assert(exists);
    assert(exists.value() == false);
  }
} // namespace

int main()
{
  test_remove_returns_error_for_empty_path();
  test_remove_returns_false_for_missing_path();
  test_remove_deletes_file();
  test_remove_all_deletes_directory_tree();
  return 0;
}
