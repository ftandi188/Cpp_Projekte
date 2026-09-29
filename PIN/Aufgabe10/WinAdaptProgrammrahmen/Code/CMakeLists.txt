cmake_minimum_required(VERSION 3.16)

# Projektnamen anpassen
project(Code)
set(CMAKE_CXX_STANDARD 14)

# FindGTK2 aufrufen und Linker-Optionen konfigurieren
include(FindGTK2)
if (GTK2_FOUND)
    include_directories(${GTK2_INCLUDE_DIRS})
    link_directories(${GTK2_LIBRARY_DIRS})
    link_libraries(${GTK2_LIBRARIES})
endif (GTK2_FOUND)

# Alle Dateien hinzufuegen, die mitkompiliert werden sollen
add_executable(${PROJECT_NAME} main.cpp WinAdapt.cpp WinAdapt.h)