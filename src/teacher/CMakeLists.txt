set(LIB_NAME "teacher_lib")
set(SRC_FILES "teacher.cpp")
set(INCLUDE_DIR "teacher")

add_library(${LIB_NAME} SHARED ${SRC_FILES})

target_include_directories(${LIB_NAME} 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/inc/${INCLUDE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include/${INCLUDE_DIR}>
)
