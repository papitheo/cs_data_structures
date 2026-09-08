// #include "../header/MyList.h"
// #include "../ListIterator/Iterator.h"
//#include "../ListNode/Node.h"

// template <typename Type>
// kofi::MyList<Type>::MyList():numberOfItems(0),head(nullptr),tail(nullptr){}

// template <typename Type>
// kofi::MyList<Type>::MyList(const MyList<Type>& otherList):numberOfItems(0),
// head(nullptr){
//     Node<Type>* current = otherList.head;
//     Node<Type>* last = nullptr;

//     while(current != nullptr){
//         Node<Type>* newNode = new Node<Type>(current->data);

//         if(head == nullptr){
//             head = newNode;
//         }
//         else{
//             last->next = newNode;
//         }

//         last = newNode;
//         current = current->next;
//         ++numberOfItems;
//     }
// }

// template<typename Type>
// kofi::MyList<Type>::~MyList(){

//     Node<Type>* current = head;

//     while(current != nullptr){
//         Node<Type>* next = current->next;
//         delete current;
//         current = next;
//     }

//     head = nullptr;
//     tail = nullptr;
//     numberOfItems = 0;
// }

//To implement the assignment operator for your custom linked list, you need to:
//Check for self-assignment (i.e., if (this == &otherList) return *this;)
//Delete the current list’s nodes to avoid memory leaks.
//Deep copy the nodes from otherList into the current list.
//Return *this (a reference to the current object).
// template<typename Type>
// kofi::MyList<Type>& kofi::MyList<Type>::
// operator=(const MyList<Type>& otherList){
//     //& is added to otherList because we need the address to compare it
//     // to this which is a pointer
//     //** Important: otherList is just a reference (alias) to the object
//     // but & is an address/ pointer to the object. They are different

//     //step 1: check for self assignment
//     if(this == &otherList){
//         return *this;
//     }

//     //stage 2: Delete all the current nodes
//     Node<Type>* current = head;
    
//     while(current != nullptr){
//         Node<Type>* next = current->next;
//         delete current;
//         current = next;
//     }
//     head = nullptr;
//     tail = nullptr;
//     numberOfItems = 0;

//     //stage 3: deep copy of the otherList
//     Node<Type>* otherCurrent = otherList.head;
//     Node<Type>* last = nullptr;

//     while(otherCurrent != nullptr){
//         Node<Type>* newNode = new Node<Type>(otherCurrent->data);

//         if(head == nullptr){
//             head = newNode;
//         }else{
//             last->next = newNode; 
//         }
//         last = newNode;
//         otherCurrent = otherCurrent->next;
//         ++numberOfItems;

//     }
//     tail = last;

//     // Stage 4: Return this object
//     return *this;

// }

// template<typename Type>
// size_t kofi::MyList<Type>::size() const{
//     return numberOfItems;
// }

// template<typename Type>
// void kofi::MyList<Type>::push_back(const Type& item){
//     Node<Type>* newNode = new Node<Type>(item);
//     newNode->next = nullptr;

//     if(head == nullptr){
//         head = newNode;
//         tail = newNode;
//     }else{
//         tail->next = newNode;
//         tail = newNode;
//     }

//     ++numberOfItems;

// }

// template<typename Type>
// void kofi::MyList<Type>::pop_back(){
//     // Check for empty list
//     if(head == nullptr){
//         throw std::out_of_range("The list is empty");
//     }
//     // Check for one Node list
//     else if(head == tail){
//         delete head;
//         head = nullptr;
//         tail = nullptr;
//         --numberOfItems;
//     }
//     // delete the last node
//     else{
//         Node<Type>* current = head;

//         // Traverses trhe nodes until the tail is reached 
//         while(current->next != tail){
//             current = current->next;
//         }
//         delete tail;
//         tail = current;
//         tail->next = nullptr;
//         --numberOfItems;
//     }
    

// }

// template <typename Type>
// void kofi::MyList<Type>::push_front(const Type& item){
//     // create a new Node
//     Node<Type>* newNode = new Node<Type>(item);
//     newNode->next =  head;

//     // Check for empty list
//     if(head == nullptr){
//         tail = newNode;
//     }

//     //new Node next should point to the first node
    
//     head = newNode;
//     ++numberOfItems;

// }

// template <typename Type>
// void kofi::MyList<Type>::pop_front(){
//     // Check for empty list
//     if(head == nullptr){
//         throw std::out_of_range("List is empty");
//     }
//     // check for a single item
//     else if(head == tail){
//         delete head;
//         head = nullptr;
//         tail = nullptr;
//         --numberOfItems;
//     }
//     else{
//         Node<Type>* current = head->next;
//         delete head;
//         head = current;
//         --numberOfItems;
//     }
// }

//Non-Type Return Values (e.g., void, int)
//kofi:: appears once:
//You only need the namespace to specify the class (MyList<Type>) where the 
//function swap is defined.
//The return type (void) is a built-in type and doesn’t require a namespace.
// template <typename Type>
// void kofi::MyList<Type>::swap(MyList<Type>& otherList){
//     // Swap head pointer
//     Node<Type>* tempHead = head;
//     head = otherList.head;
//     otherList.head = tempHead;

//     // Swap tail pointer
//     Node<Type>* tempTail = tail;
//     tail = otherList.tail;
//     otherList.tail = tempTail;

//     //swap size counters
//     size_t tempNum = numberOfItems;
//     numberOfItems = otherList.numberOfItems;
//     otherList.numberOfItems = tempNum;
// }

//In the begin function, the return type is a type nested inside the class 
// (MyList<ItemType>::iterator).
// template<typename Type>
// kofi::Iterator<Type> kofi::MyList<Type>::begin() const{
//     return Iterator<Type>(this, head);
// }

//If tail is the last node, iterating from begin() (head) to end() (tail) 
//would exclude the last node:
//for (auto it = list.begin(); it != list.end(); ++it) {
    // Loop stops at the node *before* tail
//}
// template <typename Type>
// kofi::Iterator<Type> kofi::MyList<Type>::end() const{
//     return Iterator<Type>(this,nullptr);
// }

// template <typename Type>
// kofi::Iterator<Type> kofi::MyList<Type>::insert(kofi::Iterator<Type> position, const Type& item) {
//     Node<Type>* posNode  = position.current;


//     // Check if the node pointed to by the position iterator is the same 
//     // node pointed to by the head pointer. This check is for empty list
//     if(posNode == head){
//         push_front(item);
//         return begin();
//     }
//     //Checks if there is just one item in the list
//     // If there is,put the node after that node
//     else if(posNode == nullptr){
//         push_back(item);
//         return Iterator<Type>(this, tail);
//     }
//     // traverse the list. Check if prev exist, next, check if prev != 
//     // position specified in the function
//     else{
//         Node<Type>* prev = head;
//         While(prev && prev->next != posNode){
//             prev = prev->next;
//         }
//         // Check if a node was found, specificcally, the previous node.
//         // If a node wasn't found, return the end() iterator, which is null
//         if(!prev){
//             return end();
//         }
        

//         Node<Type>* newNode = new Node<Type>(item);
//         newNode->next = posNode;
//         prev->next = newNode;
//         ++numberOfItems;

//         return Iterator<Type>(this, newNode);

//     }

// }