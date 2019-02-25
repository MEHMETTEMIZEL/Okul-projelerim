//
// Created by student on 09.11.2018.
//

#include "OptimizedAirport.h"
#include <queue>
#include <algorithm>

OptimizedAirport:: OptimizedAirport(int _numOfPeople, int _numOfLuggCounter, int _numOfSecCounter){
    this->numOfPeople=_numOfPeople;
    this->numOfLuggCounter=_numOfLuggCounter;
    this->numOfSecCounter=_numOfSecCounter;
    time=0;
    numOfPeopleEnterSystem=0;
    numOfPeopleLeaveSystem=0;
    totSpendTime=0;
    avgSpendTime=0;
    latePeople=0;
    avg1=0, avg2=0, avg3=0, avg4=0, avg5=0, avg6=0, avg7=0, avg8=0;
    late1=0, late2=0, late3=0, late4=0, late5=0, late6=0, late7=0, late8=0;

    int x;
    for(x=0;x<numOfLuggCounter; x++){
        LuggCounter[x]= nullptr;
    }
    for(x=0;x<numOfSecCounter; x++){
        SecCounter[x]= nullptr;
    }

}
OptimizedAirport::OptimizedAirport(const OptimizedAirport& optimizedAirport){
    this->numOfPeople=optimizedAirport.numOfPeople;
    this->numOfLuggCounter=optimizedAirport.numOfLuggCounter;
    this->numOfSecCounter=optimizedAirport.numOfSecCounter;
}
OptimizedAirport& OptimizedAirport::operator=(const OptimizedAirport& optimizedAirport){
    this->numOfPeople=optimizedAirport.numOfPeople;
    this->numOfLuggCounter=optimizedAirport.numOfLuggCounter;
    this->numOfSecCounter=optimizedAirport.numOfSecCounter;
    return *this;
}

OptimizedAirport::~OptimizedAirport() {
    int a;
    for(a=0; a < numOfPeople; a++){
        delete people[a];
    }
}

void OptimizedAirport::resetStatistics(){

    totSpendTime=0;
    avgSpendTime=0;
    latePeople=0;

    time=0;
    numOfPeopleEnterSystem=0;
    numOfPeopleLeaveSystem=0;
    int i;
    for(i=0; i<numOfPeople; i++){
        people[i]->spendLuggTime=0;
        people[i]->spendSecTime=0;
    }
}


void OptimizedAirport::startSimulation(bool fFfS, bool vipOrNot, bool onlineTicket){

    queue<Person> qNormalLugg;
    queue<Person> qNormalSec;

    priority_queue<Person,vector<Person>, greater<Person> > pqForLugg;
    priority_queue<Person,vector<Person>, greater<Person> > pqForSec;


    while (true){

        int nextArrivalTime;
        if(numOfPeopleEnterSystem==numOfPeople){
            nextArrivalTime=100000;
        } else{
            nextArrivalTime=people[numOfPeopleEnterSystem]->arrTime- time;
        }

        int minLuggTime=100000;
        int i;
        for(i=0; i< numOfLuggCounter; i++){
            if(LuggCounter[i]!= nullptr){
                if(minLuggTime > LuggCounter[i]->LuggTime-LuggCounter[i]->spendLuggTime){
                    minLuggTime = LuggCounter[i]->LuggTime-LuggCounter[i]->spendLuggTime;
                }
            }
        }
        int minSecTime=100000;
        for(i=0; i< numOfSecCounter; i++){
            if(SecCounter[i]!= nullptr){

                if(minSecTime > SecCounter[i]->SecTime - SecCounter[i]->spendSecTime){
                    minSecTime = SecCounter[i]->SecTime - SecCounter[i]->spendSecTime;
                }
            }
        }




        int timeIncrease=0;

        if(minSecTime<=minLuggTime && minSecTime<= nextArrivalTime){
            timeIncrease=minSecTime;
        }else if(minLuggTime<=minSecTime && minLuggTime<= nextArrivalTime){
            timeIncrease=minLuggTime;
        }else{
            timeIncrease=nextArrivalTime;
        }


        /*
        cout<<minLuggTime<<endl;
        cout<<minSecTime<<endl;
        cout<<nextArrivalTime<<endl;
        cout<<timeIncrease;
*/

        time+=timeIncrease;

       // cout<<time<<endl;


        //UPDATES

        for(i=0;i<numOfLuggCounter;i++){
            if(LuggCounter[i]!= nullptr){
                LuggCounter[i]->spendLuggTime+=timeIncrease;
            }
        }

        for(i=0;i<numOfSecCounter;i++){
            if(SecCounter[i]!= nullptr){
                SecCounter[i]->spendSecTime+=timeIncrease;
            }
        }



        //out of security

     //   priority_queue<Person> pqSec;


        for(i=0;i<numOfSecCounter;i++){
            if(SecCounter[i]!= nullptr && SecCounter[i]->spendSecTime==SecCounter[i]->SecTime){
               totSpendTime+=time-SecCounter[i]->arrTime;
               if(SecCounter[i]->flightTime < time){
                   latePeople++;

               }
                SecCounter[i]= nullptr;
                numOfPeopleLeaveSystem++;
            }
        }

        //First Flight First Serve control
        if(fFfS){
            if(!pqForSec.empty()){
                for(i=0;i<numOfSecCounter; i++){
                    if(SecCounter[i]== nullptr && !pqForSec.empty()){
                        Person gadirli =pqForSec.top();
                        SecCounter[i] =new Person(gadirli);
                        pqForSec.pop();
                    }
                }
            }
        }

        else{
            if(!qNormalSec.empty()){
                for(i=0;i<numOfSecCounter; i++){
                    if(SecCounter[i]== nullptr && !qNormalSec.empty()){
                        Person gadirli =qNormalSec.front();
                        SecCounter[i] =new Person(gadirli);
                        qNormalSec.pop();
                    }
                }
            }
        }

        // out of Luggage
        priority_queue<Person> pqForOutLugg;

        for(i=0; i < numOfLuggCounter; i++){
            if(LuggCounter[i]!= nullptr && LuggCounter[i]->spendLuggTime==LuggCounter[i]->LuggTime){
                pqForOutLugg.push(*LuggCounter[i]);
                LuggCounter[i]= nullptr;
            }
        }

        while (!pqForOutLugg.empty()){

            if(pqForOutLugg.top().vip && vipOrNot) {
                totSpendTime += time - pqForOutLugg.top().arrTime;
                numOfPeopleLeaveSystem++;
                if (pqForOutLugg.top().flightTime < time) {
                    latePeople++;
                }
                pqForOutLugg.pop();
            } else{

                bool whetherPersonInSec= false;
                for(i=0; i< numOfSecCounter; i++){
                    if(SecCounter[i]== nullptr){
                        SecCounter[i]=new Person(pqForOutLugg.top());
                        pqForOutLugg.pop();
                        whetherPersonInSec=true;
                        break;
                    }

                }

                if(!whetherPersonInSec){
                    if(fFfS){
                        pqForSec.push(pqForOutLugg.top());
                        pqForOutLugg.pop();
                    }else{
                        qNormalSec.push(pqForOutLugg.top());
                        pqForOutLugg.pop();
                    }

                }

            }


        }


        if(fFfS){
            if(!pqForLugg.empty()){
                for(i=0;i<numOfLuggCounter; i++){
                    if(LuggCounter[i]== nullptr && !pqForLugg.empty()){
                        Person gadirli =pqForLugg.top();
                        LuggCounter[i] =new Person(gadirli);
                        pqForLugg.pop();
                    }
                }
            }
        }

        else{
            if(!qNormalLugg.empty()){
                for(i=0;i<numOfLuggCounter; i++){
                    if(LuggCounter[i]== nullptr && !qNormalLugg.empty()){
                        Person gadirli =qNormalLugg.front();
                        LuggCounter[i] =new Person(gadirli);
                        qNormalLugg.pop();
                    }
                }
            }
        }




        //FOR ARRİVAL PEOPLE

        if(numOfPeopleEnterSystem!=numOfPeople){

            if(people[numOfPeopleEnterSystem]->arrTime==time){
                if(onlineTicket && !people[numOfPeopleEnterSystem]->hasLugg){
                    if(vipOrNot && people[numOfPeopleEnterSystem]->vip){
                        if(people[numOfPeopleEnterSystem]->flightTime < time){
                            latePeople++;
                        }
                        numOfPeopleLeaveSystem++;
                    }else{
                        bool whetherPersonInSec= false;
                        for(i=0; i< numOfSecCounter; i++){
                            if(SecCounter[i]== nullptr){
                               SecCounter[i]= new Person(*people[numOfPeopleEnterSystem]);
                                whetherPersonInSec=true;
                                break;
                            }

                        }

                        if(!whetherPersonInSec){
                            if(fFfS){
                                pqForSec.push(*people[numOfPeopleEnterSystem]);
                            }else{
                                qNormalSec.push(*people[numOfPeopleEnterSystem]);
                            }

                        }
                    }
                }else{
                    bool whetherPersonInLugg= false;
                    for(i=0; i< numOfLuggCounter; i++){
                        if(LuggCounter[i]== nullptr){
                            LuggCounter[i]= new Person(*people[numOfPeopleEnterSystem]);
                            whetherPersonInLugg=true;
                            break;
                        }

                    }

                    if(!whetherPersonInLugg){
                        if(fFfS){
                            pqForLugg.push(*people[numOfPeopleEnterSystem]);
                        }else{
                            qNormalLugg.push(*people[numOfPeopleEnterSystem]);
                        }

                    }
                }

                numOfPeopleEnterSystem++;

            }



        }


        if(numOfPeople<=numOfPeopleLeaveSystem){

            avgSpendTime=(double)totSpendTime/numOfPeople;
            break;

        }

    }
}






