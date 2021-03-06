cmake_minimum_required(VERSION 2.6)
project(SYLPH)

# Definitions
set( SYLPH_VERSION "0.1" )
set( SYLPH_ABI 1 ) # update when abi changes
set( SYLPH_DEP_LINK gc icuuc ) # dependent libraries
set( SYLPH_DEP_INCLUDE "" ) # for future use

# Compile options
option(SYLPH_DEBUG "Enable assertions and exception line info")
set(SYLPH_CONFIG_DEFS "" CACHE STRING "Add extra preprocessor definitions")
option(SYLPH_COMPILER_SUFFICIENT "Set a manual override to make your compiler pass all tests")
set(SYLPH_CXXFLAGS "" CACHE STRING "Add a manual override to the C++ flags needed to activate C++0x and other stuff")

#Version & platform checks...
macro (get_gcc_version version)
    if (CMAKE_COMPILER_IS_GNUCC)
        exec_program( ${SYLPH_SOURCE_DIR}/gccver.sh ARGS ${CMAKE_CXX_COMPILER} OUTPUT_VARIABLE ${version})
    endif(CMAKE_COMPILER_IS_GNUCC)
endmacro (get_gcc_version)

#Yea, I know *BSD, Irix, HP-UX, Solaris, ... != Linux, but for simplicity...
if( UNIX AND NOT APPLE )
    set(LINLIKE 1)
endif ( UNIX AND NOT APPLE )

# Get Versions
get_gcc_version ( S_GCC_VERSION )

# Check if compiler supports all constructs
if ( NOT SYLPH_COMPILER_SUFFICIENT ) # manual override
    SET( SYLPH_COMPILER_SUFFICIENT 0 )

    # GCC >= 4.4.0 will do the job
    if ( CMAKE_COMPILER_IS_GNUCC AND S_GCC_VERSION STRGREATER "4.4.0" )
        SET( SYLPH_COMPILER_SUFFICIENT 1 )
        SET( CXX_GCC 1 )
    endif ( CMAKE_COMPILER_IS_GNUCC AND S_GCC_VERSION STRGREATER "4.4.0" )

    # No compiler found
    if ( NOT SYLPH_COMPILER_SUFFICIENT )
        message ( FATAL_ERROR "Your compiler does not support C++0x. Please install a compliant compiler. G++ > 4.4.0 supports the required constructs. Use the -DCMAKE_CXX_COMPILER flag to set a compiler." )
    endif ( NOT SYLPH_COMPILER_SUFFICIENT )

endif ( NOT SYLPH_COMPILER_SUFFICIENT )

# CXXFlags
if ( NOT SYLPH_CXXFLAGS )

    # GCC >= 4.4.0
    # Enable C++0x and disable some warnings
    if ( CXX_GCC )
        set( SYLPH_CXXFLAGS "-std=c++0x")

        if ( APPLE )
            # disable warning for 4-param main
            set ( SYLPH_CXXFLAGS "${SYLPH_CXXFLAGS} -Wno-main" )
        endif ( APPLE )

        # Enable all warnings
        set ( SYLPH_CXXFLAGS "${SYLPH_CXXFLAGS} -Wall -Werror" )
    endif ( CXX_GCC )

    if ( NOT SYLPH_CXXFLAGS )
    endif ( NOT SYLPH_CXXFLAGS )

endif ( NOT SYLPH_CXXFLAGS )

# platform extras
set(SYLPH_PLATFORM_INCLUDE "")
set(SYLPH_PLATFORM_SRC "")
set(SYLPH_PLATFORM_LINK "" )

if ( LINLIKE )
    # linlike extras (binreloc)
    set(SYLPH_PLATFORM_INCLUDE "${SYLPH_SOURCE_DIR}/deps/binreloc")
    set(SYLPH_PLATFORM_SRC "${SYLPH_SOURCE_DIR}/deps/binreloc/binreloc.cpp" )
endif ( LINLIKE )

set(SYLPH_LINK ${SYLPH_PLATFORM_LINK} ${SYLPH_DEP_LINK})
set(SYLPH_INCLUDE ${SYLPH_PLATFORM_INCLUDE} ${SYLPH_DEP_INCLUDE})

add_subdirectory(src)
add_subdirectory(test)

configure_file( bin/sylphparams.in bin/sylphparams )

install( PROGRAMS ${SYLPH_BINARY_DIR}/bin/sylphparams DESTINATION bin )
install( PROGRAMS ${SYLPH_SOURCE_DIR}/bin/sylo DESTINATION bin )
