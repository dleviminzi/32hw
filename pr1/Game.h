//
// Created by dminzi-ldt on 1/11/20.
//

#ifndef HW1_GAME_H
#define HW1_GAME_H
#include <string>
using namespace std;

class Arena;

class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nVampires);
    ~Game();

    // Mutators
    void play();

private:
    Arena* m_arena;

    // Helper functions
    string takePlayerTurn();
};

#endif //HW1_GAME_H
