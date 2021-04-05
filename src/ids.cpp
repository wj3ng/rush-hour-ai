#include "searches.hpp"

#include <iostream>
using namespace std;

#include "state.hpp"

State ids(State initState, int &expandedNodes, int &maxNodes){

    int depth = 1;
    State retState = dfs(initState, depth, expandedNodes, maxNodes);

    while(retState.failed){
        ++depth;
        retState = dfs(initState, depth, expandedNodes, maxNodes);
    }

    return retState;

}