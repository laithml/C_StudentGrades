cmake_minimum_required(VERSION 3.21)
project(C_StudentGrades C)

set(CMAKE_C_STANDARD 99)

add_executable(C_StudentGrades main.c GradesOperations.c GradesOperations.h StudentList.c StudentList.h)
