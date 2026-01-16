cmake_minimum_required(VERSION 3.20)
project(FruitCatcher)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL3 REQUIRED CONFIG)
find_package(SDL3_image REQUIRED CONFIG)
find_package(SDL3_ttf REQUIRED CONFIG)

add_executable(game
    "Fruit_Catcher_Game.c"
)

target_link_libraries(game PRIVATE
    SDL3::SDL3
    SDL3_image::SDL3_image
    SDL3_ttf::SDL3_ttf
)

if (EMSCRIPTEN)
    message(STATUS "Configuring Emscripten-specific flags")

    set_target_properties(game PROPERTIES SUFFIX ".html")
    target_link_options(game PRIVATE
        "SHELL:--preload-file ${CMAKE_SOURCE_DIR}/data@/data"
        "SHELL:-s USE_SDL=2"
        "SHELL:-s USE_SDL_IMAGE=2"
        "SHELL:-s USE_SDL_TTF=2"
        "SHELL:-s SDL2_IMAGE_FORMATS=['png','jpg']"
        "SHELL:-s ALLOW_MEMORY_GROWTH=1"
        "SHELL:-s TOTAL_MEMORY=67108864"
    )
endif()
