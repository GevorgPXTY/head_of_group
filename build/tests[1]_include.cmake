if(EXISTS "C:/IT/Repos/head_of_group_fork/build/tests[1]_tests.cmake")
  include("C:/IT/Repos/head_of_group_fork/build/tests[1]_tests.cmake")
else()
  add_test(tests_NOT_BUILT tests_NOT_BUILT)
endif()
