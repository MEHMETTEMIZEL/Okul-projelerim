//
// Created by student on 09.11.2018.
//

#ifndef PROJECT2_OPTIMIZEDAIRPORT_H
#define PROJECT2_OPTIMIZEDAIRPORT_H

#include <iostream>
#include "Person.h"


using namespace std;

class OptimizedAirport {
public:

    int numOfPeople;
    int numOfLuggCounter;
    int numOfSecCounter;

    OptimizedAirport(int _numOfPeople, int _numOfLuggCounter, int _numOfSecCounter);
    OptimizedAirport(const OptimizedAirport& optimizedAirport);
    OptimizedAirport& operator=(const OptimizedAirport& optimizedAirport);
     ~OptimizedAirport();



    int time;
    int numOfPeopleEnterSystem;
    int numOfPeopleLeaveSystem;

   //  vector<int> ar[5000];
    // vector<int>::iterator ptr;

    Person* people[5000];
    //priority_queue<int > pqForLugg;
    Person* LuggCounter[20];
    Person* SecCounter[20];

 /*   //Queue for arriving passengers
    queue<Person> qForArrPerson;

    //Queue for luggage quueue
    queue<Person> qForNormalLuggOrder;


    //Queue for security queue
    queue<Person> qForNormalSecOrder;

    //List for luggage counter
    list<Person> listForLuggCounter;

    //List for security counter
    list<Person> listForSecCounter;
    //------Functions-----\\

    //Function for one cycle
    void eventLoop(){

    }*/

    void resetStatistics();

    // Last statistics that are wanted
    int totSpendTime;
    double avgSpendTime;
    int latePeople;

    double avg1, avg2, avg3, avg4, avg5, avg6, avg7, avg8;
    int late1, late2, late3, late4, late5, late6, late7, late8;


    void startSimulation(bool fFfS, bool vipOrNot, bool onlineTicket);

};


#endif //PROJECT2_OPTIMIZEDAIRPORT_H
