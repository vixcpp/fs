# ----------------------------------------------------
# Vix.fs — Examples
# ----------------------------------------------------

file(GLOB FS_EXAMPLES
  CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

foreach(EXAMPLE_SRC ${FS_EXAMPLES})
  get_filename_component(EXAMPLE_NAME ${EXAMPLE_SRC} NAME_WE)

  add_executable(fs_example_${EXAMPLE_NAME} ${EXAMPLE_SRC})

  target_link_libraries(fs_example_${EXAMPLE_NAME}
    PRIVATE
      vix::fs
  )

  target_compile_features(fs_example_${EXAMPLE_NAME} PRIVATE cxx_std_20)

  set_target_properties(fs_example_${EXAMPLE_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/examples
  )
endforeach()
