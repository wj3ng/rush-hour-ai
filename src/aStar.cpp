#include "searches.hpp"

#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#include "state.hpp"
#include "heuristic.hpp"

State aStar(State initState, int &expandedNodes, int &maxNodes){
    return aStar(initState, -1, expandedNodes, maxNodes);
}

State aStar(State initState, int maxCost, int &expandedNodes, int &maxNodes){  // infinite cost if -1 

    priority_queue<HContainer, vector<HContainer>, HComp> pq;
    pq.push(HContainer(initState));
    map<array<array<int,6>,6>,int> ex; // explored set, value is the depth

    while(!pq.empty()){

        maxNodes = max(maxNodes, (int)pq.size());

        HContainer curCont = pq.top();
        pq.pop();

        if(maxCost != -1 && curCont.h > maxCost) continue;

        if(curCont.s.isGoalState())
            return curCont.s;

        // check if in explored set
        auto *i = &ex[curCont.s.occ];
        if(*i && *i <= (int)curCont.s.actions.size() + 1) continue;
        *i = (int)curCont.s.actions.size() + 1;

        // expand frontier
        vector<Action> acts = curCont.s.expandState();
        for(auto i : acts){
            HContainer tmpCont(curCont.s.performAction(i));
            if(maxCost == -1 || tmpCont.h <= maxCost)
                pq.push(tmpCont);
        }
        ++expandedNodes;

    }
    
    return FAILED_STATE;

}