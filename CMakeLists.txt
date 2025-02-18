
cmake_minimum_required(VERSION 3.14)  # Минимальная требуемая версия CMake
project(kuzmina_kv_oop)  # Название проекта
set(CMAKE_CXX_STANDARD 20)  # стандарт языка
include_directories(src)
add_subdirectory(src)
#add_executable(kuzmina_kv_oop main.cpp utils.cpp)  # исполняемые файлы 