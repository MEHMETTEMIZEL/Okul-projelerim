    #include "LinkedList.h"


LinkedList::LinkedList(){
    length=0;
    // pointer to the first element of LinkedList
    Node *head = 0;
    // pointer to the last element of LinkedList
    Node *tail = 0;
}

LinkedList::LinkedList(const LinkedList& list){
    this->length=list.length;
    if(list.head){
        this->head=new Node(*(list.head));
    }
    Node *curr= this->head;
    while(curr->next) {
        curr->next;
    }
        this->tail=curr;

}

LinkedList&LinkedList ::operator=(const LinkedList& list){
    this->length=list.length;
    if(list.head){
        delete this->head;
        this->head=new Node(*(list.head));
    }
    if(list.tail){
        delete this->tail;
        this->tail=new Node(*(list.tail));
    }
    return *this;
}

LinkedList::LinkedList(LinkedList&& list){
    this->length=move(list.length);
    this->head=move(list.head);
    this->tail=move(list.tail);

    list.length=0;
    list.head=NULL;
    list.tail=NULL;
}

LinkedList&LinkedList ::operator=(LinkedList&& list){
    this->length=move(list.length);
    this->head=move(list.head);
    this->tail=move(list.tail);

    delete this->head;
    this->head=new Node(*(list.head));

    delete this->tail;
    this->tail=new Node(*(list.tail));

    list.length=0;
    list.head=NULL;
    list.tail=NULL;
    return *this;
}

// add a new element to the back of LinkedList
void LinkedList::pushTail(string _name, float _amount){

    tail->next=new Node(_name,_amount);

}

// update an existing element
void LinkedList::updateNode(string _name, float _amount){
    Node* current=head;
    while (current){
        if(current->name==_name){
            current->amount=_amount;
            break;
        }
        current=current->next;

    }
}
LinkedList::~LinkedList(){
    if(head) {
        delete head;
    }

}
