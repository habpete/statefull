#ifndef _PRODUCER_H_
#define _PRODUCER_H_

struct Event {
    int x;
    int y;
    int damage;
    bool exist;
};

typedef []Event Events;

enum ProducerWorkState {
    Working = 0,
    Stopped,
};

class Producer {
public:
    Producer();
    ~Producer();
private:
    ProducerWorkState workState;
public:
    void StartProducing();
    void StopProducing();
private:
    void producing();
public:
    bool IsNewEventsExist();
    Events Get();
};

#endif _PRODUCER_H_