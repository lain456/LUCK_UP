cmake_minimum_required(VERSION 3.30)
project(LUCK_UP C)

set(CMAKE_C_STANDARD 11)

# Find SDL and related libraries
find_package(SDL REQUIRED)
find_package(SDL_ttf REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_mixer REQUIRED)

# Include directories for SDL and gameplay headers
include_directories(
        ${SDL_INCLUDE_DIR}
        ${SDL_TTF_INCLUDE_DIR}
        ${SDL_IMAGE_INCLUDE_DIR}
        ${SDL_MIXER_INCLUDE_DIR}
        ${CMAKE_SOURCE_DIR}/gameplay/include
        ${CMAKE_SOURCE_DIR}/src/code
)

# Add executable with all necessary source files
add_executable(LUCK_UP
        COOKED.c
        src/code/game/game.h
        src/code/game/game.c
        src/code/tools/tools.h
        src/code/tools/tools.c
        src/code/Player/player.h
        src/code/Player/player.c
        src/code/Background/background.h
        src/code/Background/background.c
        src/code/button/button.h
        src/code/button/button.c
        src/code/enemy/enemy.h
        src/code/enemy/enemy.c
        src/code/text/txt.h
        src/code/text/txt.c
        src/code/menu/menu.h
        src/code/menu/menu.c
        src/code/load_menus/load_menus.c
        src/code/load_menus/load_menus.h
        src/code/slider/slider.h
        src/code/slider/slider.c
        gameplay/src/bullet.c
        gameplay/src/collision.c
        gameplay/src/enemy.c
        #gameplay/src/player.c
        gameplay/src/utils.c
        src/code/slider/slider.c
)

# Link libraries
target_link_libraries(LUCK_UP
        ${SDL_LIBRARY}
        ${SDL_TTF_LIBRARY}
        ${SDL_IMAGE_LIBRARY}
        ${SDL_MIXER_LIBRARY}
        -lm
)