#ifndef STATE_HPP
#define STATE_HPP

#include <vector>
#include <array>
using namespace std;

#include "car.hpp"
#include "action.hpp"

class State {
public:

    vector<Car> cars;
    vector<Action> actions;
    array<array<int,6>,6> occ; // occupied squares, -1 if empty, otherwise the car index
    bool failed = false;

    State(vector<Car> const& v1, vector<Action> const& v2);
    State(State const& S);
    State(bool f);

    bool isGoalState();
    bool isLegalAction(Action const& a);
    vector<Action> expandState();
    State performAction(Action const& a);

    int carsBlockingExit();

};

ostream& operator<<(ostream& os, State const& st);

const State FAILED_STATE(true);

#endif