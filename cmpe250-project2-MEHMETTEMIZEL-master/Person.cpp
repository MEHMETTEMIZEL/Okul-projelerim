//
// Created by student on 08.11.2018.
//

#include "Person.h"

Person::Person(){}
//Constructor
Person::Person(int _arrTime, int _flightTime, int _LuggTime, int _SecTime, bool _vip,bool _hasLugg ){
		this->arrTime=_arrTime;
		this->flightTime=_flightTime;
		this->LuggTime=_LuggTime;
		this->SecTime=_SecTime;
		this->vip=_vip;
		this->hasLugg=_hasLugg;

        this->spendLuggTime=0;
        this->spendSecTime=0;

	}
    //Copy constructor
    Person::Person(const Person& person){
    	this->arrTime=person.arrTime;
    	this->flightTime=person.flightTime;
    	this->LuggTime=person.LuggTime;
    	this->SecTime=person.SecTime;
    	this->vip=person.vip;
    	this->hasLugg=person.hasLugg;

        this->spendLuggTime=person.spendLuggTime;
        this->spendSecTime=person.spendSecTime;
    }
    // this is a minHeap priority queue
    bool Person::operator<(const Person& person) const {

            return this->arrTime > person.arrTime;

    }
    // this is also a minHeap priority queue
    bool Person::operator>(const Person& person) const {

        if(this->flightTime==person.flightTime){
            return this->arrTime > person.arrTime;
        }
        return this->flightTime > person.flightTime;
    }
    Person& Person::operator=(const Person& person){
       	this->arrTime=person.arrTime;
    	this->flightTime=person.flightTime;
    	this->LuggTime=person.LuggTime;
    	this->SecTime=person.SecTime;
    	this->vip=person.vip;
    	this->hasLugg=person.hasLugg;

        this->spendLuggTime=person.spendLuggTime;
        this->spendSecTime=person.spendSecTime;

    }
    Person::~Person(){

    }