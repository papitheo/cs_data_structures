#include "./Iterator.h"
#include "../ListNode/Node.h"
#include "../source/MyList.h"

// The default iterator constructor is left empty because it is required for 
// compatibility and flexibility, but usually, there is nothing that needs to be initialized at that point
template <class Type>
kofi::Iterator<Type>::Iterator(){}

template <class Type>
kofi::Iterator<Type>::Iterator(const MyList<Type> *prnt, Node<Type> *pos) :
 parent(prnt), current(pos) {}

// This implementation of the (*) operator is meant to return  a reference
// the data in a node
// Using * returns a reference to the data value in the node
template <class Type>
Type &kofi::Iterator<Type>::operator*() const
{
    if (current == NULL)
    {
        throw std::invalid_argument("Attempt to dereference NULL iterator");
    }
    return current->data;
}

// Using -> returns a pointer to the data value (reference) in the node
template <class Type>
Type *kofi::Iterator<Type>::operator->() const
{
    if (current == NULL)
    {
        throw std::invalid_argument("Attempt to dereference NULL iterator");
    }
    return &(current->data);
}

// This is a postfix implementation and it should return the initial node
// before incrementing to the next node
template<typename Type>
kofi::Iterator<Type> kofi::Iterator<Type>::operator++(int){
    if(current == NULL){
        throw std::invalid_argument("attempt to advance past end()");
    }
    kofi::Iterator<Type> temp = *this;
    current = current->next;
    return temp;
} 

// Prefix 
template <class Type>
kofi::Iterator<Type> &kofi::Iterator<Type>::operator++()
{
    if (current == NULL)
    {
        throw std::invalid_argument("attempt to advance past end()");
    }
    current = current->next;
    return *this;
}

template<typename Type>
kofi::Iterator<Type> kofi::Iterator<Type>::operator--(int){
    if(current == NULL){
        throw std::invalid_argument("attempt to decrement past begin()");
    }

    kofi::Iterator<Type> temp = *this;
    current = current->prev;
    return temp;
}

template <class Type>
kofi::Iterator<Type> &kofi::Iterator<Type>::operator--()
{
    if (current == NULL)
    {
        throw std::invalid_argument("attempt to decrement past begin()");
    }
    current = current->prev;
    return *this;
}

// Checks if the two iterators point to the same node and they belong to 
// the same parent list 
// Or you can say it checks if two iterators are equal
template <class Type>
bool kofi::Iterator<Type>::operator==(const Iterator &i)
{
    return (current == i.current) && (parent == i.parent);
}

// Checks if two iterators are not equal
// If the == returns false, meaning they are not equal,
// != returns true. 
template <class Type>
bool kofi::Iterator<Type>::operator!=(const Iterator &i)
{
    return !(this->operator==(i));
}
