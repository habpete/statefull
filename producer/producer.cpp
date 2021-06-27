#include <thread>
#include <iostream>

#include "producer.h"

Producer::Producer () {}
Producer::~Producer () {}

void Producer::StartProducing() {
    std::thread thr(producing);
    thr.detach();
}

void Producer::producing() {
    for (;;) {
        if (this->workState == Stopped) {
            break;
        }

        std::cout << "generate some event" << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}