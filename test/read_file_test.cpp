#include <cassert>
#include <string>

#include <vix/fs/CreateDirectories.hpp>
#include <vix/fs/ReadFile.hpp>
#include <vix/fs/ReadText.hpp>
#include <vix/fs/RemoveAll.hpp>
#include <vix/fs/WriteFile.hpp>
#include <vix/fs/WriteText.hpp>

namespace
{
  void test_read_text_returns_error_for_empty_path()
  {
    auto result = vix::fs::read_text("");
    assert(!result);
  }

  void test_read_file_returns_error_for_empty_path()
  {
    auto result = vix::fs::read_file("");
    assert(!result);
  }

  void test_read_text_reads_written_text()
  {
    const std::string dir = "fs_test_tmp/read_text";
    const std::string path = dir + "/hello.txt";
    const std::string expected = "hello world";

    auto created = vix::fs::create_directories(dir);
    assert(created);

    auto written = vix::fs::write_text(path, expected);
    assert(written);
    assert(written.value());

    auto read = vix::fs::read_text(path);
    assert(read);
    assert(read.value() == expected);

    auto removed = vix::fs::remove_all(dir);
    assert(removed);
  }

  void test_read_file_reads_written_bytes()
  {
    const std::string dir = "fs_test_tmp/read_file";
    const std::string path = dir + "/data.bin";
    const vix::fs::Bytes expected{0x10, 0x20, 0x30, 0x40};

    auto created = vix::fs::create_directories(dir);
    assert(created);

    auto written = vix::fs::write_file(path, expected);
    assert(written);
    assert(written.value());

    auto read = vix::fs::read_file(path);
    assert(read);
    assert(read.value() == expected);

    auto removed = vix::fs::remove_all(dir);
    assert(removed);
  }
} // namespace

int main()
{
  test_read_text_returns_error_for_empty_path();
  test_read_file_returns_error_for_empty_path();
  test_read_text_reads_written_text();
  test_read_file_reads_written_bytes();
  return 0;
}
