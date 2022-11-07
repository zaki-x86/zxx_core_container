## 
# CMake version 
##

cmake_minimum_required(VERSION 3.10)

############################################################################
############################################################################
## 
# Project info 
##

project(Structs  
    VERSION 1.0.0
    DESCRIPTION "data structus in c++"
    LANGUAGES CXX
)

############################################################################
############################################################################
## 
# Variables 
##

set(SRCS
    src/structs/structures.cpp
)

set(EXEC_SRCS
    src/main.cpp
)

set(HEADERS
    include/structs/structures.h
)

############################################################################
############################################################################
## 
# Build targets
##

if(${PROJECT_NAME}_BUILD_EXECUTABLE)

    add_executable(${PROJECT_NAME} ${EXEC_SRCS} ${SRCS})

    if(${PROJECT_NAME}_ENABLE_UNIT_TESTING)
        add_library(${PROJECT_NAME}_LIB ${HEADERS} ${SRCS})
    endif()
    
elseif(${PROJECT_NAME}_BUILD_HEADERS_ONLY)
    add_library(${PROJECT_NAME} INTERFACE)


else()
  add_library(
    ${PROJECT_NAME}
    ${HEADERS}
    ${SRCS}
  )

endif()

############################################################################
############################################################################
## 
# Including Directories 
##

target_include_directories(Structs
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

############################################################################
############################################################################
## 
# Installation 
##

############################################################################
############################################################################
## 
# Tests 
##
