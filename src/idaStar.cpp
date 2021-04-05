#include "searches.hpp"

#include <iostream>
using namespace std;

#include "state.hpp"

State idaStar(State initState, int &expandedNodes, int &maxNodes){ 

    int cost = 0;
    State retState = aStar(initState, cost, expandedNodes, maxNodes);

    while(retState.failed) {
        ++cost;
        retState = aStar(initState, cost, expandedNodes, maxNodes);
    }

    return retState;

}