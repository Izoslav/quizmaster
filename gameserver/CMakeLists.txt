cmake_minimum_required(VERSION 3.10)
project(gameserver)

set(CMAKE_CXX_STANDARD 17)

# libraries
find_package(Pistache REQUIRED)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)
find_package(prometheus-cpp REQUIRED)

# includes
include_directories(inc)

set(REST_INC)

set(UTILITIES_INC
    inc/utilities/Timer.h)

set(INC
    ${REST_INC}
    ${UTILITIES_INC})

# sources
set(REST_SRC
    src/rest/RestServer.cpp)

set(UTILITIES_SRC)

set(SRC
    ${REST_SRC}
    ${UTILITIES_SRC})

add_executable(gameserver
    main.cpp
    ${SRC}
    ${INC})

target_link_libraries(gameserver
    pistache
    fmt
    prometheus-cpp
    pthread)