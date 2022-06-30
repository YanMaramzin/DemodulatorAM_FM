cmake_minimum_required(VERSION 3.5)

project(DemodulatorAmFm LANGUAGES CXX)

if(UNITTEST)
	add_subdirectory(googletests/)
endif()

add_subdirectory(TestTask/libs/Demodulator)
add_subdirectory(TestTask/libs/FileManager)
add_subdirectory(TestTask/libs/Filter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(DemodulatorAmFm main.cpp)

target_link_libraries(${PROJECT_NAME} Demodulator)
target_link_libraries(${PROJECT_NAME} FileManager)
target_link_libraries(${PROJECT_NAME} Filter)
