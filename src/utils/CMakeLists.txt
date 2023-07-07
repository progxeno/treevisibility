# Build application
if(TREE_VISIBILITY_BUILD_APP)
  target_sources(${PROJECT_NAME} PRIVATE man.cpp map.cpp tree.cpp
                                         treeVisibilitySolver.cpp)
endif() # TREE_VISIBILITY_BUILD_APP

if(TREE_VISIBILITY_BUILD_TEST)
  find_package(GTest CONFIG REQUIRED)

  # Add Test Target
  add_executable(${PROJECT_NAME}-test)

  # Set target specific directories
  set_target_properties(
    ${PROJECT_NAME}-test PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                    "${PROJECT_SOURCE_DIR}/cmd/bin")

  # Add source files to target
  target_sources(
    ${PROJECT_NAME}-test PRIVATE man_test.cpp map_test.cpp tree_test.cpp
                                 treeVisibilitySolver_test.cpp)

  # Link the static libraries to this target
  target_link_libraries(${PROJECT_NAME}-test GTest::gtest GTest::gtest_main
                        ${PROJECT_NAME})
endif() # UTILITYC_BUILD_TEST
