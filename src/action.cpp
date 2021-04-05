#include "action.hpp"

#include <ostream>
using namespace std;

Action::Action(int a, int b, int c)
    : ind(a), row(b), col(c) { }

ostream& operator<<(ostream& os, Action const& ac){
    os << "Car " << ac.ind << " to (" << ac.row << "," << ac.col << ")";
    return os;
}