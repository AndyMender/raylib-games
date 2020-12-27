# shared objects needed by all game targets
link_libraries(-lm -lGL -lpthread -ldl -lrt -lX11 -lraylib)

# add directories for specific targets
add_subdirectory("wallbreaker")