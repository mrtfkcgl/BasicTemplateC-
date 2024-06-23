cmake_minimum_required(VERSION 3.14)
project(MyProject VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Define libraries and their source files
set(LIBRARIES
    "student"
    "teacher"
)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(test)

# GoogleTest setup
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.tar.gz
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Create main executable
add_executable(${PROJECT_NAME} src/main.cpp)

# Link libraries to main executable
foreach(LIB ${LIBRARIES})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB}_lib)
endforeach()

# Add tests
enable_testing()

if(BUILD_TESTING)
    add_subdirectory(test)
endif()

# Install headers
install(DIRECTORY ${PROJECT_SOURCE_DIR}/inc/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${CMAKE_PROJECT_NAME})

# Install libraries
foreach(LIB ${LIBRARIES})
    install(TARGETS ${LIB}_lib
        EXPORT export_${PROJECT_NAME}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${CMAKE_PROJECT_NAME})
endforeach()

# Install executable
install(TARGETS ${PROJECT_NAME}
    DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

# Export configuration
install(EXPORT export_${PROJECT_NAME}
    NAMESPACE ${CMAKE_PROJECT_NAME}::
    FILE ${CMAKE_PROJECT_NAME}-config.cmake
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/${CMAKE_PROJECT_NAME})

# Compiler options
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()
