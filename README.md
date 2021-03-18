# Nokia Academy: Unit Tests and Test Driven Development exercises

This repository contains two exercises which will be performed during NA lectures.

## Requirements:
* CMake 3.10+
* Compiler compatible with CMake (gcc, clang, etc...)
* Git

## Compilation:
1. mkdir <build_folder>; cd <build_folder>
2. cmake <path_to_unpacked_projects>
3. make

Binaries for each exercise will be stored in <path_to_unpacked_projects>/project1 and <build_folder>/project2.
First compilation will take some time, because it will download and compile GTest/GMock framework.

## Running
Example:

$ <build_folder>/project1/tests_for_legacy

# One line to rule them all
If you create a folder alongside project1 and project2 folders then you can use a one-liner like this:

$ cmake .. && make && ./project1/tests_for_legacy

## Project2 specific:
Header files should be placed in 'include' folder.
