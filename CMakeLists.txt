cmake_minimum_required (VERSION 3.0)
project (OLOG)

file (GLOB LIB_SRC "lib/src/*.cpp" "lib/src/*/*.cpp" "lib/include/OLOG/*.hpp" "lib/include/OLOG/*/*.hpp" "lib/include/OLOG/*.h")

add_library (OLOG SHARED ${LIB_SRC})

target_include_directories (OLOG PUBLIC "lib/include")

add_executable (OLOG_DEMO "test/src/main.cpp")
target_link_libraries (OLOG_DEMO OLOG)

install (TARGETS OLOG DESTINATION "lib/")
install (DIRECTORY lib/include/ DESTINATION "include/")
