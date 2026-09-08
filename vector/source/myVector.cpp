#include "../header/myVector.h"

// Because we have the template signature (template <typename ItemType>)
// in our header file, the template signature in this cpp file must also
// be the same
template <typename ItemType>
kofi::myVector<ItemType>::myVector():currentCapacity(INITIAL_CAPACITY), 
    numOfItems(0), items(new ItemType[INITIAL_CAPACITY]){}

template <typename ItemType>
kofi::myVector<ItemType>::myVector(const myVector& otherVector):
// member initialization list (only valid for constructors)
currentCapacity(otherVector.currentCapacity), 
numOfItems(otherVector.numOfItems), 
items(new ItemType[otherVector.currentCapacity]){
    for(int i=0; i<numOfItems; i++){
        items[i] = otherVector.items[i];
    }
}

template<typename ItemTtype>
kofi::myVector<ItemTtype>::~myVector(){
    delete[] items;
}

// Kofi:: (::) is need to resolve the scope
// (kofi::myVector<ItemType>&) represents the type being returned and 
// (kofi::myVector<ItemType>) represents the class 
// (operator=(const myVector<ItemType>& otherVector)) is in.
template <typename ItemType>
kofi::myVector<ItemType>& kofi::myVector<ItemType>::
    operator=(const myVector<ItemType>& otherVector){
//References are not addresses, they are alias. Pointers are adresses. So 
// to do the comparison, you need to preceed otherVector with &
        if(this == &otherVector){
            return *this;
        }

        delete[] items;

        currentCapacity = otherVector.currentCapacity;
        numOfItems = otherVector.numOfItems;
        items = new ItemType[otherVector.currentCapacity];

        for(int i=0; i<numOfItems; i++){
            items[i] = otherVector.items[i];
        }

        return *this;
    }

template <typename ItemType>
ItemType& kofi::myVector<ItemType>::operator[](sizeType index){
    // Here (index < 0) is unnecessary because index is size_t which is 
    // unsigned
    if(index < 0 || index >= numOfItems){
        throw std::out_of_range ("index to operator[] is out of range");
    }
    
    return items[index];
}

template <typename ItemType>
const ItemType& kofi::myVector<ItemType>::operator[]
( sizeType index)const{
    if(index >= numOfItems){
        throw std::out_of_range("index to operator[] is out of range");
    }

    return items[index];
}

template <typename ItemType>
ItemType& kofi::myVector<ItemType>::at(sizeType index){
    if(index >= numOfItems){
        throw std::out_of_range("index to at() is out of range");
    }

    return items[index];
}

template <typename ItemType>
const ItemType& kofi::myVector<ItemType>::at(sizeType index) const {
    if(index >= numOfItems){
        throw std::out_of_range("index to at() is out of range");
    }

    return items[index];
}

template <typename ItemType>
void kofi::myVector<ItemType>::reSize(sizeType newSize){

    if(newSize < numOfItems){
        numOfItems = newSize;
    }

    else {

        if(newSize > currentCapacity){
            ItemType* newVector = new ItemType[newSize];

            for(int i=0; i<numOfItems; i++){
                newVector[i] = items[i];
            }
            
            delete[] items;
            items = newVector;
            currentCapacity = newSize;
        }

        
        for(int i=numOfItems; i<newSize; i++){
            items[i] = ItemType();
        }
        
        numOfItems = newSize;
    }

}

template <typename ItemType>
void kofi::myVector<ItemType>::reSize(sizeType newSize, ItemType value){
    if(newSize < numOfItems){
        numOfItems = newSize;  
    }
    else if(newSize > numOfItems){
        if(newSize > currentCapacity){
            ItemType* newItems = new ItemType[newSize];
            for(int i=0; i<numOfItems; i++){
                newItems[i] = items[i];
            }
            delete[] items;
            items = newItems;
            currentCapacity = newSize;
        }


        for(int i=numOfItems; i<newSize; i++){
            items[i] = value;
        }
        numOfItems = newSize;
    }
   
}

template <typename ItemType>
int kofi::myVector<ItemType>::size() const{
    return numOfItems;
}

template <typename ItemType>
int kofi::myVector<ItemType>::capacity() const{
    return currentCapacity;
}

template <typename ItemType>
void kofi::myVector<ItemType>::assign(sizeType count, const ItemType& item)
{
    if(count == 0){
        delete[] items;
        items = nullptr;
        currentCapacity = 0;
        numOfItems = 0;

    }
    else if(count > currentCapacity){
        ItemType* newItems = new ItemType[count];
        delete[] items;
        items = newItems;
        currentCapacity = count;
        for(int i = 0; i<count; i++){
            items[i] = item;
        }
        numOfItems = count;
    }
    else{
        for(int i = 0; i<count; i++){
            items[i] = item;
        }
        numOfItems = count;
    }
    
}

template <typename ItemType>
void kofi::myVector<ItemType>::insert(int index, const ItemType& item){

    if( index < 0 || index > numOfItems ){
        throw std::out_of_range("The index is out or range");
    }
    else if(numOfItems == currentCapacity){
        
        sizeType newCapacity = (currentCapacity == 0) ? 1 : 
        (currentCapacity * 2);

        ItemType* vectorItems = new ItemType[newCapacity];

        for(int i = 0; i<index; i++){
            vectorItems[i] = items[i];
        }

        vectorItems[index] = item;

        for(int i=index; i<numOfItems; i++){
            vectorItems[i+1] = items[i];
        }

        delete[] items;
        items = vectorItems;
        currentCapacity = newCapacity;
    }
    else{

        for(int i = numOfItems; i>index; i--){
            items[i] = items[i-1];
        }
        items[index] = item;

}
}

template <typename ItemType>
void kofi::myVector<ItemType>::pushBack(const ItemType& item){
    if(numOfItems == currentCapacity){
        sizeType newCapacity = (currentCapacity == 0) ? 1 : 
        (currentCapacity*2);
        ItemType* newItems = new ItemType[newCapacity];
        for(int i=0; i<numOfItems; i++){
            newItems[i] = items[i];
        }
        newItems[numOfItems] = item;
        delete[] items;
        items = newItems;
        currentCapacity = newCapacity;
        numOfItems+=1;
    }
    else{
        items[numOfItems] = item;
        numOfItems+=1;
    }
}
template <typename ItemType>
void kofi::myVector<ItemType>::popBack(){
    if(numOfItems == 0 ){
        throw std::out_of_range("Container is empty");
    }
    else{
         numOfItems-=1;
    }
}

template <typename ItemType>
void kofi::myVector<ItemType>::erase(int index){
    if(index >= numOfItems || index < 0){
        throw std::out_of_range("Index is out of scope");
    }
    for(int i =index; i<numOfItems-1;i++){
        items[i] = items[i+1];
    }
    numOfItems-=1;
}

template <typename ItemType>
void kofi::myVector<ItemType>::swap(myVector<ItemType>& otherVector){
    ItemType* tempItems = items;
    items = otherVector.items;
    otherVector.items = tempItems;
    
    sizeType tempCapacity = currentCapacity;
    currentCapacity = otherVector.currentCapacity;
    otherVector.currentCapacity = tempCapacity;

    sizeType tempSize = numOfItems;
    numOfItems = otherVector.numOfItems;
    otherVector.numOfItems = tempSize;
    

}


