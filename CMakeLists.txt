cmake_minimum_required(VERSION 3.19)
project(learnCpp_Algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(learnCpp_Algorithm main.cpp leetcode/daily/Solution.cpp leetcode/daily/Solution.h sort/sortHelprs.h datastructure/MyHashSet.cpp datastructure/MyHashSet.h)