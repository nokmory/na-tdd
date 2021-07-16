# Nokia Academy: Unit Tests and Test Driven Development exercises
This repository contains two exercises which will be performed during NA lectures.

## Requirements:
* CMake 3.10+
* Compiler compatible with CMake (gcc, clang, etc...)
* Git

## Compilation:
```bash
$ mkdir <build_folder>; cd <build_folder>
$ cmake <path_to_unpacked_projects>
$ make
```

Binaries for each exercise will be stored in `<path_to_unpacked_projects>/project1` and `<build_folder>/project2`.
First compilation will take some time, because it will download and compile GTest/GMock framework.

Custom targes are added so you can compile and run tests for project1 doing `make tests1` after cmake. There is of course `tests2` target for project2.

## Running
Example:

```bash
$ ./<build_folder>/project1/tests_for_legacy
```

## One line to rule them all
If you create a build folder on the same level as  project1 and project2 folders then you can use a one-liner like this:

```bash
cmake .. && make tests1
cmake .. && make tests2
```
