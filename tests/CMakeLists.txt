function(add_gtest name src)
  	add_executable(${name} ${src})
	target_link_libraries(${name} gtest_main)
	target_include_directories(${name} PRIVATE ${PROJECT_SOURCE_DIR}/include)
  	add_test(NAME ${name} COMMAND ${name})
endfunction()

add_gtest(test_course test_course.cpp)
