cmake_minimum_required(VERSION 3.17)
project(vdrs)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Vulkan REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

set(VDRS_LIBRARIES Vulkan::Vulkan glfw)

if(WIN32)
    message("-- VDRS_WIN32")
elseif(LINUX)
    message("-- VDRS_LINUX")

    find_package(X11 REQUIRED)

    set(VDRS_LIBRARIES ${VDRS_LIBRARIES} X11::X11 X11::xcb)
endif()

add_executable(${PROJECT_NAME}
    Source/vdrs.hpp
    Source/vdrs.cpp
)

target_precompile_headers(${PROJECT_NAME} PUBLIC Source/vdrspch.hpp Source/vdrspch.cpp)
target_compile_definitions(${PROJECT_NAME} PUBLIC $<$<CONFIG:Debug>:VDRS_DEBUG> $<$<CONFIG:RelWithDebInfo>:VDRS_DEBUG>)
target_link_libraries(${PROJECT_NAME} PUBLIC ${VDRS_LIBRARIES})

file(COPY Resource/Vertex.spv DESTINATION Resource/)
file(COPY Resource/Fragment.spv DESTINATION Resource/)
