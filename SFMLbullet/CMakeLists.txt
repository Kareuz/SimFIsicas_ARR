cmake_minimum_required(VERSION 3.26)
project(SFMLbullet)

set(CMAKE_CXX_STANDARD 17)

add_executable(SFMLbullet main.cpp)

find_package(box2d CONFIG REQUIRED)
target_link_libraries(SFMLbullet PRIVATE box2d::box2d)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(SFMLbullet PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
