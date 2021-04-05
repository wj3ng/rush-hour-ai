#include "state.hpp"

#include <vector>
#include <array>
#include <ostream>
using namespace std;

#include "car.hpp"
#include "action.hpp"


State::State(vector<Car> const& v1, vector<Action> const& v2)
    : cars(v1), actions(v2) {
    for(int i=0; i<6; ++i)
        for(int j=0; j<6; ++j)
            occ[i][j] = -1;
    for(auto i : cars){
        for(int j=0; j<i.len; ++j){
            if(i.ori == 1) occ[i.row][i.col+j] = i.ind;
            else occ[i.row+j][i.col] = i.ind;
        }
    }
}

State::State(State const& S)
    : cars(S.cars), actions(S.actions), failed(S.failed) {
    for(int i=0; i<6; ++i)
        for(int j=0; j<6; ++j)
            occ[i][j] = S.occ[i][j];
}

State::State(bool f)
    : failed(f) { }

bool State::isGoalState() {
    return (cars[0].row == 2 && cars[0].col == 4);
}

bool State::isLegalAction(Action const& a) {

    const Car *cc = &cars[a.ind]; // current car
    int p1,p2;
    if(cc->ori == 1)
        p1 = cc->col, p2 = a.col;
    else 
        p1 = cc->row, p2 = a.row;
    if(p1 > p2) swap(p1,p2);
    p2 += cc->len - 1;


    for(int i=p1; i<=p2; ++i){
        if(cc->ori == 1 && (occ[a.row][i]!=-1
            && occ[a.row][i]!=a.ind))
            return false;
        if(cc->ori == 2 && (occ[i][a.col]!=-1
            && occ[i][a.col]!=a.ind))
            return false;
    }

    return true;

}

vector<Action> State::expandState() {

    vector<Action> ret;

    for(auto i : cars) {
        if(!actions.empty() && actions.back().ind == i.ind) continue;
        for(int j=0; j<7-i.len; ++j){
            int tr, tc;
            if(i.ori == 1){
                if(j == i.col) continue;
                tr = i.row, tc = j;
            } else {
                if(j == i.row) continue;
                tr = j, tc = i.col;
            }
            Action tmpAct(i.ind,tr,tc);
            if(isLegalAction(tmpAct))
                ret.push_back(tmpAct);
        }
    }

    return ret;

}

State State::performAction(Action const& a) {

    State ret(*this);

    Car* cc = &ret.cars[a.ind]; // current car
    for(int i=0; i<cc->len; ++i){
        if(cc->ori == 1) ret.occ[cc->row][cc->col+i] = -1;
        else ret.occ[cc->row+i][cc->col] = -1;
    }
    cc->row = a.row;
    cc->col = a.col;
    for(int i=0; i<cc->len; ++i){
        if(cc->ori == 1) ret.occ[cc->row][cc->col+i] = a.ind;
        else ret.occ[cc->row+i][cc->col] = a.ind;
    }
    ret.actions.push_back(a);

    return ret;
}

int State::carsBlockingExit() {

    int ret = 0;
    for(int i=cars[0].col+cars[0].len; i<6; ++i)
        ret += occ[2][i];
    return ret;

} 

ostream& operator<<(ostream& os, State const& st){

    for(int i=0; i<6; ++i, os << "\n")
        for(int j=0; j<6; ++j){
            if(st.occ[i][j] == -1) os << " . ";
            else os << (st.occ[i][j]<10&&st.occ[i][j]>=0?" ":"") << st.occ[i][j] << " ";
        }
    for(auto i:st.actions)
        os << i << "\n";

    return os;

}