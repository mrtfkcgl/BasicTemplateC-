# MyProject
This project is a sample C++ project with `Student` and `Teacher` classes. The project is structured with CMake and tested using Google Test.
The framework is designed to be modular and easy to manage.

## Project Structure



<pre>├── <font color="#268BD2"><b>build</b></font>
├── CMakeLists.txt
├── <font color="#268BD2"><b>include</b></font>
│   ├── <font color="#268BD2"><b>student</b></font>
│   │   └── student.hpp
│   └── <font color="#268BD2"><b>teacher</b></font>
│       └── teacher.hpp
├── <font color="#268BD2"><b>src</b></font>
│   ├── CMakeLists.txt
│   ├── main.cpp
│   ├── <font color="#268BD2"><b>student</b></font>
│   │   ├── CMakeLists.txt
│   │   └── student.cpp
│   └── <font color="#268BD2"><b>teacher</b></font>
│       ├── CMakeLists.txt
│       └── teacher.cpp
└── <font color="#268BD2"><b>test</b></font>
    ├── CMakeLists.txt
    ├── <font color="#268BD2"><b>studentTest</b></font>
    │   ├── CMakeLists.txt
    │   └── test_student.cpp
    └── <font color="#268BD2"><b>teacherTest</b></font>
        ├── CMakeLists.txt
        └── test_teacher.cpp

</pre>
## Installation and Compilation
### Requirements
- CMake (version 3.14 or higher)
- A C++ compiler (g++ or clang++)
- Google Test (will be automatically downloaded using CMake FetchContent)

### Steps
1.Create a directory named build in the project root and navigate into it.

    $mkdir -p build && cd build

2.Generate the project build files with CMake:

    $cmake ..

3.Compile the project:

    $make 

## Compiling Only Tests

1.Compile the tests:

    $make studentTest teacherTest

2. Run the tests:


    $ctest -V


### Project Contents
#### Libraries

    Student: Contains student/student.hpp and student/student.cpp files.
    Teacher: Contains teacher/teacher.hpp and teacher/teacher.cpp files.


####  Tests

The tests are located in the test directory and are written using Google Test.

    studentTest: Contains test/studentTest/test_student.cpp file.
    teacherTest: Contains test/teacherTest/test_teacher.cpp file.

