function(vix_fs_add_test test_name test_source)
  add_executable(${test_name}
    ${test_source}
  )

  target_compile_features(${test_name}
    PRIVATE
      cxx_std_20
  )

  target_link_libraries(${test_name}
    PRIVATE
      vix::fs
  )

  if (VIX_ENABLE_SANITIZERS AND NOT MSVC)
    target_compile_options(${test_name}
      PRIVATE
        -fno-omit-frame-pointer
        -fsanitize=address,undefined
    )

    target_link_options(${test_name}
      PRIVATE
        -fsanitize=address,undefined
    )
  endif()

  add_test(
    NAME ${test_name}
    COMMAND ${test_name}
  )
endfunction()

vix_fs_add_test(vix_fs_exists_test exists_test.cpp)
vix_fs_add_test(vix_fs_list_directory_test list_directory_test.cpp)
vix_fs_add_test(vix_fs_read_file_test read_file_test.cpp)
vix_fs_add_test(vix_fs_remove_test remove_test.cpp)
vix_fs_add_test(vix_fs_write_file_test write_file_test.cpp)
