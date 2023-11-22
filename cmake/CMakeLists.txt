cmake_minimum_required(VERSION 3.27.0)
    
# here we specify that the project is C language only, so the default
# C compiler on the system will be used
project(calculator C)

set(SOURCE_DIR ../src)
set(BIN_DIR ../bin)
set(LIB_DIR ../lib)

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})


file(GLOB LIBS ${LIB_DIR}/*)

add_executable(${PROJECT_NAME} ${SOURCE_DIR}/calculator.c)

foreach(LIB ${LIBS})
    if(IS_DIRECTORY ${LIB})
        # Get the name of the subdirectory (library name)
        get_filename_component(LIB_NAME ${LIB} NAME)

        target_include_directories(${PROJECT_NAME} PUBLIC ${LIB_DIR}/${LIB_NAME})

        # Define the target for the library
        file(GLOB LIB_SOURCE_FILES ${LIB}/*)
        add_library(${LIB_NAME} SHARED ${LIB_SOURCE_FILES})

        # Set the output directory for the DLL
        set_target_properties(${LIB_NAME} PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIR}
            LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR}
            RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
        )

        target_link_libraries(${PROJECT_NAME} ${LIB_NAME})

    endif()
endforeach()