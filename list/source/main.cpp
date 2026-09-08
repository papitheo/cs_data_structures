#include <iostream>
#include "MyList.h"
#include "../ListIterator/Iterator.h"
#include "../ListNode/Node.h"

using namespace std;

int main(){

    kofi::MyList<int> intList;

    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
    intList.push_back(4);
    intList.push_back(5);

    for(auto it=intList.begin(); it != intList.end(); ++it){
        cout<<*it<<endl;
    }

    return 0;
}