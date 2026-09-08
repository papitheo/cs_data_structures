#include "../header/myVector.h"
#include <iostream>

using namespace std;
using namespace kofi;


int main(){

    cout<<endl;
    cout<<"Program Starts: "<<endl;
    kofi::myVector<int> nums1;
    kofi::myVector<int> nums2;

    nums1.pushBack(1);
    nums1.pushBack(2);
    nums1.pushBack(3);
    nums1.pushBack(4);
    nums1.pushBack(5);
    nums1.pushBack(6);

    nums2.pushBack(7);
    nums2.pushBack(8);
    nums2.pushBack(9);
    nums2.pushBack(10);
    nums2.pushBack(11);
    nums2.pushBack(12);
    
    cout<<"nums1: ";
    for(int i=0; i<nums1.size(); i++){
        cout<<nums1[i]<<",";
    }

    cout<<endl;
    
    cout<<"Current Size: "<<nums1.size()<<endl;
    cout<<"Current capacity: "<<nums1.capacity()<<endl;

    cout<<endl;

    //nums2 = kofi::myVector<int>(nums1);

    // cout<<"nums2: ";
    // for(int i=0; i<nums2.size(); i++){
    //     cout<<nums2[i]<<",";
    // }

    //cout<<endl;
        
    // cout<<"Current Size: "<<nums1.size()<<endl;
    // cout<<"Current capacity: "<<nums1.capacity()<<endl;

    //cout<<endl;
    cout<<"nums2: ";
    
    for(int i=0; i<nums2.size(); i++){
        cout<<nums2[i]<<",";
    }

    cout<<endl;

    nums2 = nums1;

    cout<<endl;

    cout<<"nums2 = nums1: ";
    for(int i=0; i<nums2.size(); i++){
        cout<<nums2[i]<<",";
    }

    cout<<endl;

    cout<<"Current Size: "<<nums2.size()<<endl;
    cout<<"Current capacity: "<<nums2.capacity()<<endl;

    cout<<endl;
    // Testing const operator[]
    int firstNumber = nums1[0];
    cout<<"const Operator[] for '0': "<<firstNumber;
    
    cout<<endl;
    //Testing operator[]
    int val = 100;
    nums1[0] = val;
    cout<<"operator[] for 0: "<<nums1[0]<<endl;

    cout<<endl;
    //Testing const at()
    int atNum = nums1.at(0);
    cout<<"const at() number at '0': "<<atNum<<endl;
    
    cout<<endl;
    //Testing at()
    nums1.at(0) = 200;
    cout<<"at() number inserted at '0': "<<nums1[0]<<endl;



    return 0;
}

