cmake_minimum_required(VERSION 3.16)

# Enable debug symbols by default
# must be done before project() statement
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "generate compile_commands.json")

# Ausführliche Ausgabe der Compiler aufrufe
# set(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "enable verbose build")

# Projektnamen
project(Bruch CXX)

# Verwende alle Quelldateien im aktuellen Verzeichnis
# !! Werden neue Dateien hinzugefuegt, dann muss cmake erneut gestartet werden !!
# Siehe: https://cmake.org/cmake/help/v3.16/command/aux_source_directory.html
AUX_SOURCE_DIRECTORY(. PROJECT_SRC)

# Alternativ: Quelldateien des Projets explizit angegben
# set(PROJECT_SRC main.cpp WinAdapt.cpp WinAdapt.h)

add_executable(${PROJECT_NAME} ${PROJECT_SRC})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)

