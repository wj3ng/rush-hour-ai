#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

#include "searches.hpp"
#include "state.hpp"
#include "action.hpp"
#include "car.hpp"

string algName(int algType);

void solve(int algType, string fileName);

int main(int argc, char **argv) {
    if(argc == 1) solve(1, "L01.txt");
    else solve(stoi(argv[1]), argv[2]);
}

string algName(int algType) {
    if(algType == 1) return "BFS";
    if(algType == 2) return "DFS";
    if(algType == 3) return "IDS";
    if(algType == 4) return "A*";
    if(algType == 5) return "IDA*";
    return "";
}

void solve(int algType, string fileName) {

    cout << fileName << ", " << algName(algType) << endl;

    vector<Car> initCars;

    int a, b, c, d, e;
    ifstream fin("tests/" + fileName);
    while(fin >> a >> b >> c >> d >> e)
        initCars.push_back(Car(a,b,c,d,e));
    fin.close();

    State initState(initCars, vector<Action>());

    int expandedNodes = 0;
    int maxNodes = 0;
    State ansState = FAILED_STATE;

    auto startTime = high_resolution_clock::now();

    if(algType == 1){
        ansState = bfs(initState, expandedNodes, maxNodes);
    } else if (algType == 2) {
        ansState = dfs(initState, expandedNodes, maxNodes);
    } else if (algType == 3) {
        ansState = ids(initState, expandedNodes, maxNodes);
    } else if (algType == 4) {
        ansState = aStar(initState, expandedNodes, maxNodes);
    } else if (algType == 5) {
        ansState = idaStar(initState, expandedNodes, maxNodes);
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    if(ansState.failed) cout << "No solution found\n";
    else printf("%12d  actions in solution\n", (int)ansState.actions.size());
    printf("%12d  microseconds elapsed\n", (int)duration.count());
    printf("%12d  nodes expanded\n", expandedNodes);
    printf("%12d  nodes in memory\n", maxNodes);

}