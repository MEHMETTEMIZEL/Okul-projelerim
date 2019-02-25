#include "SurveyClass.h"


SurveyClass::SurveyClass() {
    LinkedList *members = NULL;
}

SurveyClass::SurveyClass(const SurveyClass &other) {
    if (other.members) {
        this->members = new LinkedList(*(other.members));
    }
}

SurveyClass&SurveyClass ::operator=(const SurveyClass &list) {
    if (list.members) {
        delete this->members;
        this->members = new LinkedList(*(list.members));
    }
    return *this;
}

SurveyClass::SurveyClass(SurveyClass &&other) {

    this->members = move(other.members);
    other.members = NULL;
}

SurveyClass &SurveyClass::operator=(SurveyClass &&list) {

    delete this->members;
    this->members = move(list.members);
    list.members = NULL;
    return *this;
}

SurveyClass::~SurveyClass() {
    if (members) {
        delete members;
    }

}

void SurveyClass::handleNewRecord(string _name, float _amount) {
    if (members == NULL) {
        members = new LinkedList();

        members->head = new Node(_name, _amount);
        members->tail = members->head;
        members->length++;
    } else {
        Node *curr = members->head;
        bool cont = 0;
        while (curr) {
            if (curr->name == _name) {
                members->updateNode(_name, _amount);
                cont = 1;
                break;
            }

            curr = curr->next;
        }

        if (!cont) {

            members->pushTail(_name, _amount);
            members->tail = (members->tail)->next;
            members->length++;
        }


    }

}

float SurveyClass::calculateMaximumExpense() {

    float max = members->head->amount;
    Node *curr = members->head;
    while (curr) {
        if (curr->amount > max) {
            max = curr->amount;
        }
        curr = curr->next;

    }
    int max2=max*100;
    float max3=(float)max2/100;


    return max3;


}

float SurveyClass::calculateMinimumExpense() {
    float min = members->head->amount;
    Node *curr = members->head;
    while (curr) {
        if (curr->amount < min) {
            min = curr->amount;
        }
        curr = curr->next;

    }
    int min2=min*100;
    float min3=(float)min2/100;

    return min3;

}

float SurveyClass::calculateAverageExpense() {
    float sum=0 , avg=0;
    Node *curr = members->head;
    while (curr) {
        sum += curr->amount;
        curr = curr->next;

    }
    avg=sum /members->length;


    int avg2=avg*100;
    float avg3=(float)avg2/100;

    return avg3;

}