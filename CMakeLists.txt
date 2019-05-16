project(wilson2)

cmake_minimum_required(VERSION 2.8.4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(Boost_USE_MULTITHREADED ON)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(CURL)
include_directories(${Boost_INCLUDE_DIR})
if (CURL_FOUND)
    #include_directories(${CURL_INCLUDE_DIRS})
    #add_definitions(-DHAVE_CURL)
endif()

find_package(Qt5 REQUIRED
    Core
    Widgets
    Qml
)

add_subdirectory(lib/tgbot-cpp)
add_subdirectory(src)
