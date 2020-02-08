#include <iostream>
#include <string>
#include <stack>

class Coord {
    public:
        Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
        int r() const { return m_r; }
        int c() const { return m_c; }
    private:
        int m_r;
        int m_c;
};


bool pathExists(std::string maze[], int nRows, int nCols, int sr, int sc, 
        int er, int ec) {
    bool result(false);
    // int i(0);
    // initialize coordinate stack and push starting position
    std::stack<Coord> coords;
    coords.push(Coord(sr, sc));
    Coord end_coord(er, ec);
    maze[sr][sc] = 'V';

    // loop through possible positions to add to the stack
    while (!coords.empty()) {

        // get the current coordinate
        Coord curr_coord = coords.top();
        coords.pop();

        /*if (i < 12) 
            std::cout << "(" << curr_coord.r() << ", " << curr_coord.c() 
                << ")" << std::endl;*/

        // check if it is the end point
        if (curr_coord.r() == end_coord.r() && 
                curr_coord.c() == end_coord.c()) {
            result = true;
            break;
        }

        // check EAST
        if (maze[curr_coord.r()][curr_coord.c()+1] == '.') {
            // push the coords to the stack and mark as visited
            coords.push(Coord(curr_coord.r(), curr_coord.c()+1));
            maze[curr_coord.r()][curr_coord.c()+1] = 'V';
        }
        
        // check SOUTH
        if (maze[curr_coord.r()+1][curr_coord.c()] == '.') {
            // push the coords to the stack and mark as visited
            coords.push(Coord(curr_coord.r()+1, curr_coord.c()));
            maze[curr_coord.r()+1][curr_coord.c()] = 'V';
        }

        // check WEST
        if (maze[curr_coord.r()][curr_coord.c()-1] == '.') {
            // push the coords to the stack and mark as visited
            coords.push(Coord(curr_coord.r(), curr_coord.c()-1));
            maze[curr_coord.r()][curr_coord.c()-1] = 'V';
        }

        // check NORTH
        if (maze[curr_coord.r()-1][curr_coord.c()] == '.') {
            // push the coords to the stack and mark as visited
            coords.push(Coord(curr_coord.r()-1, curr_coord.c()));
            maze[curr_coord.r()-1][curr_coord.c()] = 'V';
        }
        // i++;
    }
    // std::cout << i << std::endl;
    return result;
}
