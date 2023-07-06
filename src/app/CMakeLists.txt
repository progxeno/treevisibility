# Build application
if(TREE_VISIBILITY_BUILD_APP)
add_executable(${PROJECT_NAME}-app main.cpp)

target_link_libraries(${PROJECT_NAME}-app PRIVATE ${PROJECT_NAME})

 # Set target specific directories
 set_target_properties(
   ${PROJECT_NAME}-app PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                   "${PROJECT_SOURCE_DIR}/cmd/bin")

endif() # TREE_VISIBILITY_BUILD_APP
