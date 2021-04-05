#ifndef ACTION_HPP
#define ACTION_HPP

#include <ostream>
using namespace std;

class Action {
public: 
    int ind;
    int row;
    int col;
    Action(int a, int b, int c);
};

ostream& operator<<(ostream& os, Action const& ac);

#endif