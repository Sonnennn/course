cmake_minimum_required(VERSION 3.15)
project(course C)

set(CMAKE_C_STANDARD 99)

add_executable(course main.c sourse/work_with_file.c sourse/work_with_data_and_memory.c sourse/work_with_list.c sourse/menu.c sourse/output.c
        header/work_with_data_and_memory.h header/work_with_file.h header/work_with_list.h header/struct.h header/menu.h header/output.h)