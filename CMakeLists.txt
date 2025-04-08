cmake_minimum_required(VERSION 3.30)
project(LUCK_UP C)

set(CMAKE_C_STANDARD 11)

find_package(SDL REQUIRED)
find_package(SDL_ttf REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_mixer REQUIRED)

include_directories(${SDL_INCLUDE_DIR} ${SDL_TTF_INCLUDE_DIR} ${SDL_IMAGE_INCLUDE_DIR} ${SDL_MIXER_INCLUDE_DIR})

add_executable(LUCK_UP main.c
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
        src/code/menu/menu.c)

target_link_libraries(LUCK_UP ${SDL_LIBRARY} ${SDL_TTF_LIBRARY} ${SDL_IMAGE_LIBRARY} ${SDL_MIXER_LIBRARY} -lm)
