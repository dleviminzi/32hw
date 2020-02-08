//
// Created by dminzi-ldt on 1/12/20.
//

#include "History.h"
#include <iostream>
using namespace std;

History::History(int nRows, int nCols) {
    m_rows = nRows;
    m_cols = nCols;
    for (int r = 1; r <= m_rows; r++)
        for (int c = 1; c <= m_cols; c++)
            m_grid[r][c] = EMPTY;
}

bool History::record(int r, int c) {
    bool result;
    if (r >= 1  &&  r <= m_rows  &&  c >= 1  &&  c <= m_cols){
        m_grid[r][c] += 1;
        result = true;
    }
    else {
        result = false;
    }
    return result;
}

void History::display() const {
    int r, c;

    // print the grid
    clearScreen();
    for (r = 1; r <= m_rows; r++)
    {
        for (c = 1; c <= m_cols; c++) {
            if (m_grid[r][c] != EMPTY) {
                char A = 64 + m_grid[r][c];
                cout << A;
            }
            else {
                cout << '.';
            }
        }
        cout << endl;
    }
    cout << endl;
}
