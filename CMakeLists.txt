cmake_minimum_required(VERSION 2.8)

set(target_name opencv_draw_text_sample)
set(src main.cpp)

set(CMAKE_CXX_FLAGS "-Wall -g")
set(CMAKE_C_FLAGS "-Wall -g")

project( ${target_name} )

find_package( OpenCV REQUIRED )

add_executable(${target_name} ${src})
target_link_libraries(${target_name} ${OpenCV_LIBS})
install(TARGETS ${target_name} RUNTIME DESTINATION bin)
