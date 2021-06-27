#ifndef ISTATES_h
#define ISTATES_h

class IStates {
public:
    virtual ~IStates() = 0;
    virtual void Set() = 0;
};

#endif