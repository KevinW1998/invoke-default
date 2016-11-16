include(../cmake/load_catch.cmake)

include_directories (${CMAKE_SOURCE_DIR}/include
                     ${CATCH_INCLUDE_DIR}
                     )

add_executable (InvokeDefaultTest 
                TestMain.cpp
                )

set_target_properties(InvokeDefaultTest PROPERTIES COMPILE_DEFINITIONS "GSL_THROW_ON_CONTRACT_VIOLATION")                       

add_test (NAME InvokeDefaultTestProj COMMAND InvokeDefaultTest)
