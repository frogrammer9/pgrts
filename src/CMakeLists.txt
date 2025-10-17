file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS *.hpp)

add_executable(pgrts ${SOURCES} ${HEADERS})

target_compile_options(pgrts PRIVATE -Wall -Wextra)
target_link_libraries(pgrts PRIVATE SDL2)

include_directories(.)

set_target_properties(pgrts PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
