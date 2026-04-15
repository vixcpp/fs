# Vix FS

The **fs module** provides a simple, modern, and cross-platform API
for interacting with the filesystem in C++.

It is designed to be:

- simple to use
- consistent across platforms
- safe with structured error handling
- familiar for developers coming from Node.js, Deno, or Bun

## Philosophy

Filesystem APIs in Vix follow strict principles:

- simple functions, no boilerplate
- explicit error handling (`Result<T>`)
- consistent naming across operations
- minimal surprises
- portable behavior

The goal is to give C++ a **modern developer experience**.

## Install

Using Vix:

```bash
vix add @vix/fs
```

## Quick Start

```cpp
#include <vix/fs/Fs.hpp>

int main()
{
  vix::fs::write_text("hello.txt", "Hello Vix");

  auto content = vix::fs::read_text("hello.txt");

  if (content)
  {
    std::cout << content.value() << "\n";
  }

  vix::fs::remove("hello.txt");
}
```

## Core Features

### File operations

```cpp
vix::fs::write_text("file.txt", "hello");
vix::fs::append_file("file.txt", " world");

auto text = vix::fs::read_text("file.txt");
auto bytes = vix::fs::read_file("file.bin");
```

### Directory operations

```cpp
vix::fs::create_directory("data");
vix::fs::create_directories("data/cache/images");

vix::fs::ensure_directory("logs");
```

### File system queries

```cpp
vix::fs::exists("file.txt");
vix::fs::is_file("file.txt");
vix::fs::is_directory("data");

auto size = vix::fs::size("file.txt");
```

### Path & environment

```cpp
auto cwd = vix::fs::current_path();
auto tmp = vix::fs::temp_directory();
```

### Copy / Move / Remove

```cpp
vix::fs::copy("a.txt", "b.txt");
vix::fs::move("b.txt", "c.txt");
vix::fs::rename("c.txt", "final.txt");

vix::fs::remove("file.txt");
vix::fs::remove_all("build/");
```

### Directory listing

```cpp
auto result = vix::fs::list_directory(".");

if (result)
{
  for (const auto &entry : result.value())
  {
    std::cout << entry.name << "\n";
  }
}
```

## Error Handling

All operations return a `Result<T>`.

```cpp
auto result = vix::fs::read_text("file.txt");

if (!result)
{
  std::cerr << result.error().message() << "\n";
  return;
}

std::cout << result.value();
```

## Types

### Bytes

```cpp
using Bytes = std::vector<std::uint8_t>;
```

Used for binary operations.

### FsEntry

Used in directory listing:

```cpp
struct FsEntry
{
  std::string path;
  std::string name;
  FsEntryType type;
  std::uintmax_t size;
  bool hidden;
};
```

## Examples

See the `examples/` directory:

- basic.cpp
- read_write.cpp
- filesystem.cpp
- list.cpp
- copy_move.cpp
- advanced.cpp

## Design Notes

- `path` module handles lexical operations
- `fs` module interacts with the real filesystem
- errors are structured and explicit
- no exceptions required
- consistent API across all platforms

## Why Vix FS?

Traditional C++ filesystem code is often:

- verbose
- inconsistent
- exception-heavy

Vix FS provides:

- simple APIs
- predictable behavior
- clean error handling
- modern developer experience

## License

MIT License

