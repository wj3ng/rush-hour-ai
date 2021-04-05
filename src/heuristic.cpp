#include "heuristic.hpp"

HContainer::HContainer(State const& a)
    : s(a) {
    h = getCost(s);
}

bool HComp::operator()(HContainer const& lhs, HContainer const& rhs) {
    return lhs.h > rhs.h;
}

int getCost(State const& s){
    return s.actions.size() + blockingHeuristic(s);
}

int blockingHeuristic(State const& s){
    int ret = 0;
    for(int i=s.cars[0].col+s.cars[0].len; i<6; ++i)
        ret += (s.occ[2][i]!=-1);
    return ret;
}