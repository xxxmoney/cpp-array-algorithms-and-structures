cmake_minimum_required(VERSION 3.28)
project(array_algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(array_algorithms main.cpp
        linked_list.cpp
        linked_list.h
        linked_list_double.cpp
        linked_list_double.h
        stack.cpp
        stack.h
        queue.cpp
        queue.h
        binary_search_tree.cpp
        binary_search_tree.h
        tree.cpp
        tree.h
        quick_sort.cpp
        quick_sort.h
        merge_sort.cpp
        merge_sort.h
        heap_sort.cpp
        heap_sort.h)
