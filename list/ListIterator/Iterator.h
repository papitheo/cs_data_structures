#pragma once

#include <stdexcept>

namespace kofi
{

    // Pull in reference to templated List
    template <typename ListType>
    class List;

    // Pull in reference to templated Nope
    template <typename NodeType>
    class Node;

    template <class Type>
    class Iterator
    {
        // Make sure List can access private elements of iterator
        friend class MyList<Type>;

    private:
        // The list containing the iterator. 
        // Indicates that this list owns this iterator.
        // It is named parent to refer to the list that owns this iterator
        // Basically this pointer keeps track of the specific list 
        // this iterator is associated with
        // ** A pointer to the list of which the iterator is a member
        const MyList<Type> *parent;  // Pointer to originating List
        // This pointer indicates the current node in the list that the 
        // iterator is pointing to. 
        // ** A pointer to the current item (You can also say the current Node)
        // Because the node contains the item and dereferencing it would 
        // give the value
        Node<Type> *current; // Node pointer
        // This must stay private! It needs a valid list to point to!
        // Thus may only be called from within a List
        // This emsure that the list can create iterators that are specific to 
        // that list and guarantee that the iterator always points to valid 
        // nodes within the iterator
        
        //** This iterator lets you create an iterator that points to any 
        // list and any node, but it is made private to restrict the list 
        // and node it can point to. if you have a list of integers and a 
        // list of strings, and the iterator constructor is public, a user 
        // could (by mistake or intentionally) create an iterator for the 
        // string list that points to a node from the integer list. This would 
        // be dangerous and undefined behavior—the code might compile, but 
        // it could crash or corrupt data at runtime. 
        //parsing the list as const make the itrator be bale to work with 
        //both const and non const list
        Iterator(const MyList<Type> *prnt, Node<Type> *pos);

    public:

        //Default Iterator constructor. Its called when a container object is instantiated
        Iterator();
                                                                                                                                                                                    
        // Dereference Overload
        // Returns the underlying data from the Node
        // The reason why we are returning a reference is
        // because, when you dereference an pointer, the 
        // actual object is returned, not a copy. And the 
        // refereence return can be used as if it were the value 
        // itself
        Type& operator*() const;

        // Access Overload
        // Bypass the iterator and get to the data of the Node
        // Also, it is used to access members of an object
        // which is pointed to by a pointer. Eg: 
        // MyClass* ptr = &obj
        // ptr->someFunction()
        // Basically, what this does is that, it returns a pointer
        // so that you can use the -> operator to access the memebers
        // the object the pointer points to just like you'd do
        // with the native
        // (*ptr) gives a reference
        // (*ptr).funcMember() == ptr->funcMember()
        Type* operator->() const;

        // Increment/Decrement Overload
        // Moves current pointer to the next/previous element in list
        // input: int for postfix (synatx magic)
        // output: iterator of next/previous position in list
        // The int that is passed is just there for the compiler
        // to make a difference between postfix and prefix
        // the iterators below return it++ and it--
        // It returns the current iterator and increment/ decreament to the next
        Iterator<Type> operator++(int);
        Iterator<Type>& operator++();
        Iterator<Type> operator--(int);
        Iterator<Type>& operator--();

        // Equal To / Not Equal To Overload
        // intput: iterator, other to compare
        // output==: true if equal, false if not
        // output!=: true if not equal, false if equal
        // Both of these are used to check of two iterators are
        // pointing to the same values or location.
        bool operator==(const Iterator &i);
        bool operator!=(const Iterator &i);
    };
}

#include "./Iterator.cpp"
