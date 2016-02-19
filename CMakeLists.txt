cmake_minimum_required(VERSION 2.6)


# Project declaration
project(Math)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(LIBRARY_OUTPUT_PATH lib/${CMAKE_BUILD_TYPE})


# Include publics headfiles
include_directories(include)


# Library declaration
file(

  GLOB_RECURSE
  source_files
  src/*
  )

add_library(
  math
  SHARED
  ${source_files}
  )
