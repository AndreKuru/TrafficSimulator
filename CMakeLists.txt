cmake_minimum_required(VERSION 3.8)
project(TrafficSimulator)

set(CMAKE_CXX_STANDARD 11)

include_directories("${PROJECT_BINARY_DIR}")

set(SOURCE_FILES main.cpp linked_queue.h array_list.h Track.cpp Track.h Clock.cpp Clock.h linked_List.h Car.cpp Car.h Semaphore.cpp Semaphore.h System.cpp System.h EventOccurrence.cpp EventOccurrence.h)
add_executable(TrafficSimulator ${SOURCE_FILES})