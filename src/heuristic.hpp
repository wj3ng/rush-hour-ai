#ifndef HEURISTIC_HPP
#define HEURISTIC_HPP

#include "state.hpp"

class HContainer {
public:
    State s;
    int h;
    HContainer(State const& a);
};

class HComp {
public:
    bool operator()(HContainer const& lhs, HContainer const& rhs);
};

int getCost(State const& s);

int blockingHeuristic(State const& s);

#endif