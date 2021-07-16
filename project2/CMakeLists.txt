SET(SRCS
    src/board.cpp
    src/game.cpp
    src/player.cpp
)

SET(UT_SRCS
    uts/ut.cpp
    uts/boardTest.cpp
    uts/gameTest.cpp
    uts/playerTest.cpp
)

add_library(TiTaTo ${SRCS})
target_include_directories(TiTaTo PUBLIC include)

add_executable(TiTaToTests ${UT_SRCS})
target_link_libraries(TiTaToTests TiTaTo gtest gmock_main gmock)
