cmake_minimum_required(VERSION 3.2)

project(tennis)

add_executable(tennis
    main.cpp
    ball.cpp
    players.cpp
)

target_link_libraries(tennis sfml-graphics sfml-window sfml-system)