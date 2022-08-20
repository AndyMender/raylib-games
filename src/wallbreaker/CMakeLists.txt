# TODO: Add when some code is moved to "common"
# target_link_libraries(common)

set(APP_NAME "wallbreaker")

# specify main target
add_executable("${APP_NAME}" main.cpp)

# make sure all libraries are properly linked
get_target_property(_LINK_LIBRARIES "${APP_NAME}" LINK_LIBRARIES)
message(STATUS "${APP_NAME} LINK_LIBRARIES: ${_LINK_LIBRARIES}")
