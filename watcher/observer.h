#ifndef OBSERVER_H
#define OBSERVER_H

#include "../decls/decl.h"
#include "../producer/producer.h"

enum WorkStates {
    Working = 0,
    Stopped,
};

class Observer {
public:
    Observer();
    ~Observer();
private:
    WorkStates wState;
public:
    void Start();
    void Stop();
private:
    void initStates();
    ObserverMap map;
private:
    Producer producer;
};

#endif OBSERVER_H