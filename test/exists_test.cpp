#include <cassert>
#include <string>

#include <vix/fs/CreateDirectories.hpp>
#include <vix/fs/Exists.hpp>
#include <vix/fs/RemoveAll.hpp>
#include <vix/fs/WriteText.hpp>

namespace
{
  void test_exists_returns_error_for_empty_path()
  {
    auto result = vix::fs::exists("");
    assert(!result);
  }

  void test_exists_returns_false_for_missing_path()
  {
    const std::string path = "fs_test_tmp/exists/missing.txt";

    auto cleanup = vix::fs::remove_all("fs_test_tmp/exists");
    (void)cleanup;

    auto result = vix::fs::exists(path);
    assert(result);
    assert(result.value() == false);
  }

  void test_exists_returns_true_for_existing_file()
  {
    const std::string dir = "fs_test_tmp/exists";
    const std::string path = dir + "/file.txt";

    auto created_dir = vix::fs::create_directories(dir);
    assert(created_dir);

    auto written = vix::fs::write_text(path, "hello");
    assert(written);
    assert(written.value());

    auto result = vix::fs::exists(path);
    assert(result);
    assert(result.value() == true);

    auto removed = vix::fs::remove_all(dir);
    assert(removed);
  }

  void test_exists_returns_true_for_existing_directory()
  {
    const std::string dir = "fs_test_tmp/exists_dir";

    auto created = vix::fs::create_directories(dir);
    assert(created);

    auto result = vix::fs::exists(dir);
    assert(result);
    assert(result.value() == true);

    auto removed = vix::fs::remove_all(dir);
    assert(removed);
  }
} // namespace

int main()
{
  test_exists_returns_error_for_empty_path();
  test_exists_returns_false_for_missing_path();
  test_exists_returns_true_for_existing_file();
  test_exists_returns_true_for_existing_directory();
  return 0;
}
