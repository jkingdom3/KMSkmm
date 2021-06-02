file(GLOB SRC_LIST CONFIGURE_DEPENDS "*.cc")
add_library(KMSkmm-${KMSkmm_VERSION} SHARED ${SRC_LIST})
target_link_libraries(KMSkmm-${KMSkmm_VERSION}
        KMSdata-1.0)
