#include <cassert>
#include <string>

#include <vix/fs/AppendFile.hpp>
#include <vix/fs/CreateDirectories.hpp>
#include <vix/fs/ReadFile.hpp>
#include <vix/fs/ReadText.hpp>
#include <vix/fs/RemoveAll.hpp>
#include <vix/fs/WriteFile.hpp>
#include <vix/fs/WriteText.hpp>

namespace
{
  void test_write_text_returns_error_for_empty_path()
  {
    auto result = vix::fs::write_text("", "hello");
    assert(!result);
  }

  void test_write_file_returns_error_for_empty_path()
  {
    vix::fs::Bytes data{1, 2, 3};
    auto result = vix::fs::write_file("", data);
    assert(!result);
  }

  void test_write_text_overwrites_existing_content()
  {
    const std::string dir = "fs_test_tmp/write_text";
    const std::string path = dir + "/note.txt";

    auto created = vix::fs::create_directories(dir);
    assert(created);

    auto first = vix::fs::write_text(path, "first");
    assert(first);
    assert(first.value());

    auto second = vix::fs::write_text(path, "second");
    assert(second);
    assert(second.value());

    auto read = vix::fs::read_text(path);
    assert(read);
    assert(read.value() == "second");

    auto removed = vix::fs::remove_all(dir);
    assert(removed);
  }

  void test_append_file_appends_text_content()
  {
    const std::string dir = "fs_test_tmp/append_text";
    const std::string path = dir + "/log.txt";

    auto created = vix::fs::create_directories(dir);
    assert(created);

    auto first = vix::fs::write_text(path, "hello");
    assert(first);
    assert(first.value());

    auto second = vix::fs::append_file(path, " world");
    assert(second);
    assert(second.value());

    auto read = vix::fs::read_text(path);
    assert(read);
    assert(read.value() == "hello world");

    auto removed = vix::fs::remove_all(dir);
    assert(removed);
  }

  void test_append_file_appends_binary_content()
  {
    const std::string dir = "fs_test_tmp/append_bin";
    const std::string path = dir + "/data.bin";

    auto created = vix::fs::create_directories(dir);
    assert(created);

    auto first = vix::fs::write_file(path, vix::fs::Bytes{1, 2});
    assert(first);
    assert(first.value());

    auto second = vix::fs::append_file(path, vix::fs::Bytes{3, 4});
    assert(second);
    assert(second.value());

    auto read = vix::fs::read_file(path);
    assert(read);

    const vix::fs::Bytes expected{1, 2, 3, 4};
    assert(read.value() == expected);

    auto removed = vix::fs::remove_all(dir);
    assert(removed);
  }
} // namespace

int main()
{
  test_write_text_returns_error_for_empty_path();
  test_write_file_returns_error_for_empty_path();
  test_write_text_overwrites_existing_content();
  test_append_file_appends_text_content();
  test_append_file_appends_binary_content();
  return 0;
}
