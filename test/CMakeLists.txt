add_executable(vix_fs_test
  fs_test.cpp
)

target_compile_features(vix_fs_test PRIVATE cxx_std_20)

target_link_libraries(vix_fs_test
  PRIVATE
    vix::fs
)

add_test(NAME vix_fs_test COMMAND vix_fs_test)
