#include <iostream>

#include "observer.h"

#include "../states/istates.h"
#include "../states/npc_state.h"
#include "../states/gg_state.h"

Observer::Observer() {}

Observer::~Observer() {}

void Observer::Start() {
    std::cout << "watcher is starting" << std::endl;
    this->producer.StartProducing();

    for (;;) {
        if (this->wState == Stopped) {
            break;
        }
        if (!this->producer.IsNewEventsExist()) {
            continue;
        }
        Events events = this->producer.Get();
        // if sizeof(events)
        IStates* state = this->map.Get("");
        state->Set();
    }

    this->producer.StopProducing();
    std::cout << "watcher is stopped" << std::endl;
}

void Observer::Stop() {
    this->wState = Stopped;
}

void Observer::initStates() {
    IStates* npcstate = new NPCState();
    this->map.Add("npcstate", npcstate);
    
    IStates* ggstate = new GGState();
    this->map.Add("ggstate", ggstate);
}