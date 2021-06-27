#include "decl.h"
#include <string>

struct Hashing {
    int operator(const std::string& stateName, const size_t tableSize, const size_t key) const {
        int hash = 0;
        for (size_t i = 0; i < stateName.size(); ++i) {
            hash = (key * hash + stateName[i]) % tableSize
        }
        return hash;
    }
}

StateNode::~StateNode() {
    delete state;
}

ObserverMap::ObserverMap (const size_t bufferSize = 200) {
    this->buffer_size = bufferSize;
    stateNodes = new StateNode*[buffer_size];
}

ObserverMap::~ObserverMap () {
    delete[] stateNodes
}

void ObserverMap::Add(const std::string stateName, IStates*& state) {
    // this->
}

IStates*& ObserverMap::Get(const std::string stateName) {
    return this->stateNodes[0]->state;
}
