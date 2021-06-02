cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#==============================================================================

# set the project name and version
project(KMSkmm
        VERSION 1.0
        DESCRIPTION "A generic model class"
        LANGUAGES CXX)

# add source code
add_subdirectory(src)

# add include directories so source code can access them
target_include_directories(KMSkmm-${KMSkmm_VERSION} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>)

# install library
include(GNUInstallDirs)
install(
    TARGETS KMSkmm-${KMSkmm_VERSION}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# install package details
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/cmake/KMSkmm-${KMSkmm_VERSION}Config.cmake"
        DESTINATION "lib/cmake/KMSkmm-${KMSkmm_VERSION}")
install(TARGETS KMSkmm-${KMSkmm_VERSION}
        EXPORT KMSkmm-${KMSkmm_VERSION}-export
        DESTINATION lib)
install(EXPORT KMSkmm-${KMSkmm_VERSION}-export
        FILE KMSkmm-${KMSkmm_VERSION}Targets.cmake
        NAMESPACE KMSkmm::
        DESTINATION lib/cmake/KMSkmm-${KMSkmm_VERSION})

# install header files
file(GLOB HEADER_LIST CONFIGURE_DEPENDS
        "${KMSkmm_SOURCE_DIR}/include/*.h")
install(FILES ${HEADER_LIST}
        DESTINATION include/KMSkmm-${KMSkmm_VERSION})
