cmake_minimum_required(VERSION 3.14)
project(Sort)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sort main.cpp SelectionSort.h SortTestHelper.h InsertSort.h MergeSort.h QuickSort.h Heap.h)