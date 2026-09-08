#pragma once

#include <stdexcept>

namespace kofi{

// pull references to the Node class
template<typename Type>
class Node;

// pull refernces to the iterator inside the list class
template<typename Type>
class Iterator;

template<typename Type>
class MyList{
    // Since we are building the list using linked list, we do  not need
    // CurrentCapacity and INITIAL_CAPACITY unlike vectors
    // also, in linked list, the list shrink and grow dynamically so no 
    // need to reserve blocks of memory to track capacity. No need for a 
    // contigiuos memory block
    // Arrays/vectors demands that you allocate blocks of memory upfront
    // which may need constant resize but linked list allocate memory
    // for each element added
    private:
    Node<Type>* head;
    Node<Type>* tail; // Optional. It is necessary for push_back

    size_t numberOfItems;
    // In building a linked list, you dont need Type* listItems. 
    // This is because we are not dealing with dynamic arrays anymore but
    // rather we need a node, which will hold a value and reference/pointer
    // to the next node
    
    public:
    ////////////////////////////////////
    //MyList();
    MyList():numberOfItems(0),head(nullptr),tail(nullptr){}
    //////////////////////////////////////

    /////////////////////////////////////////
    //MyList(const MyList<Type>& otherList);
    MyList(const MyList<Type>& otherList):numberOfItems(0),
    head(nullptr){
    Node<Type>* current = otherList.head;
    Node<Type>* last = nullptr;

    while(current != nullptr){
        Node<Type>* newNode = new Node<Type>(current->data);

        if(head == nullptr){
            head = newNode;
        }
        else{
            last->next = newNode;
        }

        last = newNode;
        current = current->next;
        ++numberOfItems;
    }
}
    ////////////////////////////////////////

    ///////////////////////////////////////////
    //~MyList();
    ~MyList(){

    Node<Type>* current = head;

    while(current != nullptr){
        Node<Type>* next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    tail = nullptr;
    numberOfItems = 0;
    }
    ///////////////////////////////////////

    ///////////////////////////////////////////////
    //MyList<Type>& operator=(const MyList<Type>& otherList);
    kofi::MyList<Type>& operator=(const MyList<Type>& otherList){
    //& is added to otherList because we need the address to compare it
    // to this which is a pointer
    //** Important: otherList is just a reference (alias) to the object
    // but & is an address/ pointer to the object. They are different

    //step 1: check for self assignment
    if(this == &otherList){
        return *this;
    }

    //stage 2: Delete all the current nodes
    Node<Type>* current = head;
    
    while(current != nullptr){
        Node<Type>* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    numberOfItems = 0;

    //stage 3: deep copy of the otherList
    Node<Type>* otherCurrent = otherList.head;
    Node<Type>* last = nullptr;

    while(otherCurrent != nullptr){
        Node<Type>* newNode = new Node<Type>(otherCurrent->data);

        if(head == nullptr){
            head = newNode;
        }else{
            last->next = newNode; 
        }
        last = newNode;
        otherCurrent = otherCurrent->next;
        ++numberOfItems;

    }
    tail = last;

    // Stage 4: Return this object
    return *this;

}

    //////////////////////////////////////////////////

    //////////////////////////////////////////////
    // This would return the numberOfItems
    //size_t size() const;
    size_t size() const{
    return numberOfItems;
    }
    //////////////////////////////////////////////

    //////////////////////////////////////////
    //void push_back(const Type& item);
    void push_back(const Type& item){
    Node<Type>* newNode = new Node<Type>(item, nullptr);
    newNode->next = nullptr;

    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }

    ++numberOfItems;

    }
    //////////////////////////////////////////

    ////////////////////////////////
    //void pop_back();
    void pop_back(){
    // Check for empty list
    if(head == nullptr){
        throw std::out_of_range("The list is empty");
    }
    // Check for one Node list
    else if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        --numberOfItems;
    }
    // delete the last node
    else{
        Node<Type>* current = head;

        // Traverses trhe nodes until the tail is reached 
        while(current->next != tail){
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
        --numberOfItems;
    }
    

    }
    ///////////////////////////////

    /////////////////////////////////////
    //void push_front(const Type& item);
    void push_front(const Type& item){
    // create a new Node
    Node<Type>* newNode = new Node<Type>(item);
    newNode->next =  head;

    // Check for empty list
    if(head == nullptr){
        tail = newNode;
    }

    //new Node next should point to the first node
    
    head = newNode;
    ++numberOfItems;

    }
    //////////////////////////////////

    ////////////////////////////////////////////////
    //void pop_front();
    void pop_front(){
    // Check for empty list
    if(head == nullptr){
        throw std::out_of_range("List is empty");
    }
    // check for a single item
    else if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        --numberOfItems;
    }
    else{
        Node<Type>* current = head->next;
        delete head;
        head = current;
        --numberOfItems;
    }
}
    ///////////////////////////////////////////

    //////////////////////////////////////////
    //void swap(MyList<Type>& otherList);
    void swap(MyList<Type>& otherList){
    // Swap head pointer
    Node<Type>* tempHead = head;
    head = otherList.head;
    otherList.head = tempHead;

    // Swap tail pointer
    Node<Type>* tempTail = tail;
    tail = otherList.tail;
    otherList.tail = tempTail;

    //swap size counters
    size_t tempNum = numberOfItems;
    numberOfItems = otherList.numberOfItems;
    otherList.numberOfItems = tempNum;
    }
    /////////////////////////////////////////////////////////



    /////////////////////////////////////////////
    //Iterator<Type> begin() const;
    kofi::Iterator<Type> begin() const{
    return Iterator<Type>(this, head);
    }
    //////////////////////////////////////////////



    //////////////////////////////////
    //Iterator<Type> end() const;
    kofi::Iterator<Type> end() const{
    return Iterator<Type>(this,nullptr);
    }
    /////////////////////////////////////////

    ///////////////////////////////////////////////////
    //Iterator<Type> insert(Iterator<Type> position, const Type& item);
    kofi::Iterator<Type> insert(Iterator<Type> position, const Type& item){
          Node<Type>* posNode  = position.current;

    // Check if the node pointed to by the position iterator is the same 
    // node pointed to by the head pointer. This check is for empty list
    if(posNode == head){
        push_front(item);
        return begin();
    }
    //Checks if there is just one item in the list
    // If there is,put the node after that node
    else if(posNode == nullptr){
        push_back(item);
        return Iterator<Type>(this, tail);
    }
    // traverse the list. Check if prev exist, next, check if prev != 
    // position specified in the function
    else{
        Node<Type>* prev = head;

        while(prev && prev->next != posNode){
            prev = prev->next;
        }
        // Check if a node was found, specificcally, the previous node.
        // If a node wasn't found, return the end() iterator, which is null
        if(!prev){
            return end();
        }
        

        Node<Type>* newNode = new Node<Type>(item);
        newNode->next = posNode;
        prev->next = newNode;
        ++numberOfItems;

        return Iterator<Type>(this, newNode);

    }
    }
///////////////////////////////////////////////
    Iterator<Type> erase(Iterator<Type> position);


};
}

//#include "../source/MyList.cpp"