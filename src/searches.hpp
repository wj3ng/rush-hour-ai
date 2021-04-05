#ifndef SEARCHES_HPP
#define SEARCHES_HPP

#include "state.hpp"

State bfs(State initState, int &expandedNodes, int &maxNodes);

State dfs(State initState, int &expandedNodes, int &maxNodes);
State dfs(State initState, int maxDepth, int &expandedNodes, int &maxNodes);

State ids(State initState, int &expandedNodes, int &maxNodes);

State aStar(State initState, int &expandedNodes, int &maxNodes);
State aStar(State initState, int maxCost, int &expandedNodes, int &maxNodes);

State idaStar(State initState, int &expandedNodes, int &maxNodes);

#endif