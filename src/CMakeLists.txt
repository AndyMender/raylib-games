# shared objects needed by all game targets
link_libraries(
    m
    GL
    pthread
    dl
    rt
    X11
    raylib
)
# link_libraries(-lm -lGL -lpthread -ldl -lrt -lX11)

# add directories for specific targets
add_subdirectory("wallbreaker")
