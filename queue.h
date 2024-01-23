#ifndef QUEUE_H
#define QUEUE_H
#include "linkedlist.h"
#include <bits/stdc++.h>
using namespace std;
template <class T>
class Queue : public LinkedList<T>
{
    public:
        Queue();
        T& getfirst();


};
////////////////////////////constructor
template <class T>
Queue<T>::Queue(){

}


template <class T>
T& Queue<T>::getfirst(){
return LinkedList<T>::head->data;

}

#endif // QUEUE_H
