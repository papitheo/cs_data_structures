#pragma once

// defines size_t. GCC adds implcicitly in <iostream> but dont rely on 
//implicit includes
#include <cstddef>
#include <stdexcept>



namespace kofi{
    // when added globally, it poluutes global namespace. 
    // Evevry file including .h file sees sizeType, risking name conflit
    // This is called Alias. It is for the entire namespace
    using sizeType = std::size_t;

template <typename ItemType>
class myVector{
    private:
        static const sizeType INITIAL_CAPACITY = 10;
        sizeType currentCapacity;
        sizeType numOfItems; 
        // Raw pointer; used to dynamically manage memory. 
        //(stack (fixed) vrs Heap (dynamic) memory)
        // Since we are managing dynamic memory with this pointer, 
        // we need a destructor, and since we need destructor, 
        // the rule of 3 applies (Destructor, copy constructor, 
        // assignment operator)
        ItemType* items;
    public:
        myVector();
        // Copy comstructor. Called when a new object is being created as 
        // a copy of an existing object,
        // when an object is returned by value from a function, and when 
        // an obejct is passed by value to a function
        myVector(const myVector& otherVector);
        ~myVector();
        // Assignment operator is called when you want to assign content 
        // of one obejct to another. 
        // It deals with freeing old memory for the new content. The STL 
        // swap function uses assignment operator internally
        myVector<ItemType>& operator=(const myVector<ItemType>& otherVector);
        // for modifying elements in the vector. vec2[5] = 6;
        ItemType& operator[](sizeType index);
        // only for reading elements in the vector. x = vec[2];
        // One reason why we have the const version is because we want to 
        // able to use it with a const object
        const ItemType& operator[](sizeType index) const;
        ItemType& at(sizeType index);
        const ItemType& at(sizeType index) const;
        void reSize(sizeType newSize);
        void reSize(sizeType newSize, ItemType value);
        // Best practice to make them const cus they dont modify the value
        // also allows you to call them on the const instances of your fnx
        // More importantly, making it const will make it possible to call
        // it on 
        int size() const;
        int capacity() const;
        // Assigns new values to the vector, destroys old values. 
        // assign(5,10) means, fill 5 spaces with 10 
        void assign(sizeType count, const ItemType& newItem);
        // Pass by reference when you intend on modifying the original 
        // value being passed or 
        // conserving space by avoiding unecessary copying
        // const ItemType& element because, the element being added can 
        // very large, so parsing by ref. is best pratice
        // * This is different than the STL. STL uses iterators. Implement 
        // That in your list class
        void insert(int index, const ItemType& item);
        void pushBack(const ItemType& item);
        void popBack();
        // * this is different from the STL. STL uses iterators. 
        // That is fine.
        void erase(int index);
        // The parameter doesn't have const because we will be modfying 
        // both of the vectors
        // std Swap works by simply exchanging 
        void swap(myVector<ItemType>& otherVector);

};
}

// For template classes the compiler needs to see the full implementation. 
// So because we have decided to implement .h and .cpp differently, we need 
// to add the cpp file in header
// also, we are adding this include because the the implementation must be 
// visible to the compiler 
// whenever the template is instantiated.
#include "../source/myVector.cpp"

