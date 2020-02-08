//
// Created by dminzi-ldt on 1/12/20.
//

#ifndef HW1_HISTORY_H
#define HW1_HISTORY_H
#include "globals.h"

class History {
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
private:
    int m_grid[MAXROWS][MAXCOLS]; // holds locations for the vampires
    int m_rows; // max rows
    int m_cols; // max cols
};


#endif //HW1_HISTORY_H
