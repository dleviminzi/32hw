//
// Created by dminzi-ldt on 1/11/20.
//

#ifndef HW1_PLAYER_H
#define HW1_PLAYER_H
#include <string>
using namespace std;

class Arena;

class Player
{
public:
    // Constructor
    Player(Arena* ap, int r, int c);

    // Accessors
    int  row() const;
    int  col() const;
    bool isDead() const;

    // Mutators
    string dropPoisonVial();
    string move(int dir);
    void   setDead();

private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    bool   m_dead;
};

#endif //HW1_PLAYER_H
