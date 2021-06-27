#ifndef _DECL_H_
#define _DECL_H_

#include <string>
#include "../states/istates.h"

struct StateNode {
    ~StateNode();
    int hashSum;
    std::string stateName;
    IStates* state;
};

class ObserverMap {
public:
    ObserverMap(const size_t bufferSize = 200);
    ~ObserverMap();
public:
    void Add(const std::string stateName, IStates*& state);
    IStates*& Get(const std::string stateName);
private:
    size_t buffer_size;
    size_t allocated_size;
    size_t live_rows_size;
    StateNode** stateNodes;
};

#endif _DECL_H_