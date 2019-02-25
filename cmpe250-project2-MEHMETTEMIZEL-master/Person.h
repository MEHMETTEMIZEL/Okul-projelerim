//
// Created by student on 08.11.2018.
//


#ifndef PROJECT2_PERSON_H
#define PROJECT2_PERSON_H

#include <iostream>
using namespace std;

class Person {
public:
	int arrTime;
	int flightTime;
	int LuggTime;
	int SecTime;
	bool vip;
	bool hasLugg;

    int spendLuggTime;
    int spendSecTime;



    Person();
	Person(int _arrTime, int _flightTime, int _LuggTime, int _SecTime, bool _vip,bool _hasLugg );
    Person(const Person& person);
    bool operator<(const Person& person) const ;
    bool operator>(const Person& person) const ;
    Person&operator=(const Person& person);

    ~Person();
    
};


#endif //PROJECT2_PERSON_H
