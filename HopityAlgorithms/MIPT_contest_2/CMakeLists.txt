cmake_minimum_required(VERSION 3.20)

set(TARGET "2")
project(${TARGET} LANGUAGES CXX)
add_executable(
    ${TARGET}
    2.cpp
    ${LIB_DIR}/data_structures/naive_tree.cpp
    ${LIB_DIR}/data_structures/treap.cpp
)

install(TARGETS ${TARGET})