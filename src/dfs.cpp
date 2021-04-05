#include "searches.hpp"

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <array>
using namespace std;

#include "state.hpp"

State dfs(State initState, int &expandedNodes, int &maxNodes) {
    return dfs(initState, -1, expandedNodes, maxNodes);
}

State dfs(State initState, int maxDepth, int &expandedNodes, int &maxNodes){ // infinite depth if maxDepth = -1

    stack<State> st;
    st.push(initState);
    map<array<array<int,6>,6>,int> ex; // explored set, value is the depth

    while(!st.empty()){

        maxNodes = max(maxNodes, (int)st.size());

        State curState = st.top();
        st.pop();

        if(maxDepth != -1 && (int)curState.actions.size() + 1 > maxDepth) continue;

        if(curState.isGoalState())
            return curState;

        // check if in explored set
        auto *i = &ex[curState.occ];
        if(*i && *i <= (int)curState.actions.size() + 1) continue;
        *i = (int)curState.actions.size() + 1;

        // expand frontier
        vector<Action> acts = curState.expandState();
        for(auto i : acts)
            st.push(curState.performAction(i));
        ++expandedNodes;

    }
    
    return FAILED_STATE;

}
