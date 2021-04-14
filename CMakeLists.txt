cmake_minimum_required(VERSION 3.0.0)
project(drogon_subdirectory VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
add_subdirectory( http_server )
add_executable(drogon_subdirectory main.cpp)
target_link_libraries(drogon_subdirectory http_server)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
