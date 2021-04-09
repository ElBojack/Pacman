#Cmake version
cmake_minimum_required(VERSION 2.8.12)

# set up project name and version
project(Pacman)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# find SFML package
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

set(SRC
    src/main.cpp
)

# add the executable
add_executable(Pacman ${SRC})

# target link
target_link_libraries(Pacman sfml-graphics sfml-audio)