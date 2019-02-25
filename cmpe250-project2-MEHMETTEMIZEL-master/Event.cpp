//
// Created by student on 11.11.2018.
//

#include "Event.h"


Event::Event(){
    this->type;
    this->time;
    this->person;
}

Event::Event(const Event& event) {
    this->type=event.type;
    this->time=event.time;
    this->person=event.person;
}
    bool Event::operator>(const Event &event) {
        if(this->type==event.type){
            return this->type > event.type;
        }

    }
    bool Event::operator<(const Event &event) {
        if(this->type==event.type){
            return this->type < event.type;
        }

    }
    bool Event::operator=(const Event &event) {

    }
Event::~Event() {

}
