#include "searches.hpp"

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <array>
using namespace std;

#include "state.hpp"

State bfs(State initState, int &expandedNodes, int &maxNodes){

    queue<State> qu;
    qu.push(initState);
    map<array<array<int,6>,6>,int> ex; // explored set

    while(!qu.empty()){

        maxNodes = max(maxNodes, (int)qu.size());

        State curState = qu.front();
        qu.pop();

        if(curState.isGoalState())
            return curState;

        // check if in explored set
        auto *i = &ex[curState.occ];
        if(*i && *i <= (int)curState.actions.size() + 1) continue;
        *i = (int)curState.actions.size() + 1;

        // expand frontier
        vector<Action> acts = curState.expandState();
        for(auto i : acts)
            qu.push(curState.performAction(i));
        ++expandedNodes;

    }
    
    return FAILED_STATE;

}
