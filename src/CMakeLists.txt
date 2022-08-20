# shared objects needed by all game targets
link_libraries(
    m
    GL
    dl
    rt
    X11
    openal
    raylib
    glog::glog
)

# add directories for specific targets
add_subdirectory("wallbreaker")
