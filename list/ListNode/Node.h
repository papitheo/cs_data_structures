#ifndef NODE_H_
#define NODE_H_

namespace kofi
{

    template <typename Type>
    class Node
    {
    public:
        Type data;        // data to hold
        // Returning a pointer makes you be able to use * to see what is 
        // beneath the the refernce being return.
        // this is because, even though a pointer is being returned 
        // but in actual sence a return is being returned (return &p).
        // it could be an object, a number of anything at all.
        // but if you return an object and that object has a field in
        // it that contains some data or a method that return some value
        // that is when you can use -> to deference and at the same time 
        // access the field or the method in that object

        // In short, if something returning a pointer and you deference it 
        // it return an object but by reference (though not always a refence)
        //  because pointers return 
        // references. If it is returning a refence , it returns the value 
        // itself but in refence form. if it is returning a pointer and you 
        // want access the methods and fields in that pointer, you use -> 
        //followed by the method or the field  
        Node<Type> *next; // pointer to the next node
        Node<Type> *prev; // pointer to the previous node

        //Node();
        //Node() : Node(nullptr, nullptr, nullptr) {}
        Node(): data(Type{}), prev(nullptr), next(nullptr) {}
        //Node(Type data, Node<Type> *next);
        Node(Type data, Node<Type> *next) : data(data), prev(nullptr), next(next) {}
        //Node(Type data, Node<Type> *previous, Node<Type> *next);
        Node(Type data, Node<Type> *previous, Node<Type> *next): data(data),
        prev(previous), next(next){}
    };
}
#endif