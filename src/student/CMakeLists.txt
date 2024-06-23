set(LIB_NAME "student_lib")
set(SRC_FILES "student.cpp")
set(INCLUDE_DIR "student")

add_library(${LIB_NAME} SHARED ${SRC_FILES})

target_include_directories(${LIB_NAME} 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/inc/${INCLUDE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include/${INCLUDE_DIR}>
)
