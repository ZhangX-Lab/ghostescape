#include "core/game.h"
#include <iostream>
int main(int, char**) {
    auto& game = Game::GetInstance();
    std::cout << "GhostEscape running" << std::endl;
    game.init("GhostEscape", 1280, 720);
    game.run();
    return 0;
}