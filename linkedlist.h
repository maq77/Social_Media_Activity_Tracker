#ifndef LinkedList_H
#define LinkedList_H
#ifndef Node_H
#define Node_H
#include<bits/stdc++.h>
using namespace std;


template <class T>
class Node{ //// Class Node with Template
public:
T data;
Node<T>* next;
Node<T>* prev;
Node(T data);
Node();
};
template<class T>
Node<T>::Node(){
next = NULL;
prev = NULL;

};
template<class T>
Node<T>::Node(T data){

this->data = data;
next = NULL;
prev = NULL;

};

/////////////////////////////////////////////////End of Class Node with Template
template <class T>
class LinkedList{ ///////////////////////Class Linked List with Template
public:
    class Node<T>;
    Node<T> *head,*tail;
    LinkedList();
    int size_=0;
    int top = -1;
    int getsize();
    void addsize();
    void push(T data);
    void print();
    void pop();
    T &at(int n);
    void delete_node(int index);
    Node<T>* Node_at(int n);
    void push_at(T data, int index);
    bool is_Empty();
    //~LinkedList();


};
////////////////Constructor
template <class T>
LinkedList<T>::LinkedList(){
head = NULL;
tail = NULL;

}
//////////////////////return size

template <class T>
int LinkedList<T>::getsize(){
return size_;
}

template <class T>
void LinkedList<T>::addsize(){
size_++;
}

template <class T>
////////////////////////////// Insertation
void LinkedList<T>::push(T data){

        Node<T> *tmp = new Node<T>(data);
        tmp->data = data;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
        size_++;
        top++;

}
////////////////////////////// Insert At Specific Location
template <class T>
void LinkedList<T>::push_at(T data, int index ){
Node<T> *temp = new Node<T>;
temp->data = data;
if(index == 0){
    temp->next = head;
    head = temp;
    size_++;
}
else if(index > 0 && index < size_-1){
    Node<T> *temp_prev=Node_at(index-1);
    temp->next = temp_prev->next;
    temp_prev->next = temp;
    size_++;
}
else if(index == size_-1){
    Node<T> *temp_last=tail;
    temp_last->next = temp;
    temp->next = NULL;
    tail = temp;
    size_++;
}


}

////////////////////////////// Printing All LinkedList
template <class T>
void  LinkedList<T>::print(){

         Node<T> *tmp;
         tmp = head;
         while(tmp != NULL){
            cout<<tmp->data<<endl;
            tmp = tmp->next;
         }
}
////////////////////////////// return Data of Node ///copy constructor
template <class T>
T &LinkedList<T>::at(int n){
        Node<T> *temp = head;
         if(n==0){
            return temp->data;
         }
         try{
         if(n>size_-1){
            throw (n);
         }
         }
         catch(int num){
         cout<<"Out of Range !"<<endl;
         cout<<"Size of Linked List is "<<size_<<endl;
         }


         for(int i=0;i<n;i++){
            temp = temp->next;
         }
         return temp->data;

       }
///////////////////////////////// Deletion of a Node
template <class T>
void LinkedList<T>::delete_node(int index){
       Node<T> *temp = Node_at(index);
       Node<T> *temp_next = temp->next;
       Node<T> *temp_prev = Node_at(index-1);
       if(index==0){
        head = temp->next;
        return;
       }
       else if(index == size_-1){
        tail = temp_prev;
        temp_prev->next = NULL;
        return;
       }
       else{
       temp_prev->next = temp_next;
       }
       delete temp;
       size_--;
       }
//////////////////////////////// Check if LL is Empty
template<class T>
bool LinkedList<T>::is_Empty(){
if(head){
    return false;
}
else{
    return true;
}

}


////////////////////////////////Return Node
template<class T>
Node<T>*  LinkedList<T>::Node_at(int n){
          Node<T>* temp = head;
         if(n==0){
            return temp;
         }
         try{
         if(n>size_-1){
            throw (n);
         }
         }
         catch(int num){
         cout<<"Out of Range !"<<endl;
         cout<<"Size of Linked List is "<<size_<<endl;
         }


         for(int i=0;i<n;i++){
            temp = temp->next;
         }
         return temp;



       }
template <class T>
void  LinkedList<T>::pop(){

         Node<T> *tmp,*newtail;
         tmp = tail;
         newtail = tail->prev;
         delete tmp;
         tail = newtail;

}

///////////////////////////////////Destructor
/*template <class T>
LinkedList<T>::~LinkedList(){
Node<T>* temp=head;
Node<T>* prev;
while(temp->next !=NULL){
    prev = temp;
    temp = temp->next;
    head = temp;
    delete prev;
}

}*/
///////////////////////////////End of Linked List with Template
#endif
#endif



