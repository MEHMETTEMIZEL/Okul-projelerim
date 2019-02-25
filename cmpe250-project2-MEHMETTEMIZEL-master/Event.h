//
// Created by student on 11.11.2018.
//

#ifndef PROJECT2_EVENTS_H
#define PROJECT2_EVENTS_H

#include <iostream>
#include <queue>
#include "Person.h"
#include <vector>
using namespace std;

class Event {
public:
    int type;
    //type = 1 --> arrival
    //type = 2 --> luggage out
    //type = 3 --> security out
    int time;
    Person* person;

    Event();
    Event(const Event& event);
    bool operator<(const Event& event);
    bool operator>(const Event& event);
    bool operator=(const Event& event);
 //   Event& operator=(Event&& Event);
    virtual ~Event();





};


#endif //PROJECT2_EVENTS_H
