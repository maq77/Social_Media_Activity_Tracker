#ifndef AVL_H
#define AVL_H
#ifndef TreeNode_H
#define TreeNode_H
#define CAPACITY 100 // Size of the HashTable.
#define Max_Activity_Size 10
#include "Activity.h"
#include<bits/stdc++.h>
using namespace std;
/////////////////////////////////////////AVL Node

template<class T>
class TreeNode
{

public:
    T data;
    Queue<Activity> Activities;
    int hash_val;
    int collision;
    int height;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode<T>* parent;
    TreeNode<T>* next;
    TreeNode(T& data);
    TreeNode();

};
template<class T>
TreeNode<T>::TreeNode(){
        parent = next = left = right = nullptr;
        collision = height = 0;
        this->hash_val = 0;

};
template<class T>
TreeNode<T>::TreeNode(T& data){
        this->data = data;
        this->hash_val = 0;
        this->parent = this->next = this->left = this->right = nullptr;
        this->collision = this->height = 0;

};


////////////////////////////////////////// AVL Tree

template<class T>
class AVL{
public:
    //class TreeNode;
    TreeNode<T>* root;
    int height(TreeNode<T>* n);
    int getBalanceF(TreeNode<T>* n);
    TreeNode<T>* RightRotation(TreeNode<T>* head);
    TreeNode<T>* LeftRotation(TreeNode<T>* head);
    TreeNode<T>* insertRec(TreeNode<T>* r ,T& data );
    TreeNode<T>* DeleteRec(TreeNode<T>* r , T& data);
    TreeNode<T>* findmin(TreeNode<T>* r);
    TreeNode<T>* minValueNode(TreeNode<T>* node);
    void inOrder(TreeNode<T>* r);
    AVL();
    void Delete(int User_ID);
    void insert(T &data);
    void Edit(int User_ID);
    void Edit_Activity(int User_ID, int Activity_ID);
    void Delete_Activity(int User_ID, int Activity_ID);
    void insert_Activity(int User_ID ,Activity &data);
    TreeNode<T>* Search_Node(TreeNode<T>* r , int User_ID);
    T& Search_data(TreeNode<T>* r , int User_ID);
    bool Search_bool(TreeNode<T>* r , int User_ID);
    bool Search_bool(int User_ID);
    void SearchRec(TreeNode<T>* r , int User_ID);
    void Search(int User_ID);
    void Add_User_Activity(int User_ID);
    void Show_User_Activity(int User_ID);
    void inOrder();
    int hash_func(T& data);
    int hash_func_ID(int ID);
    void pass_hash_to_Node(TreeNode<T>* r, T& data);
    unsigned long hash_func_UserName_V2(T& data);




};

template <class T>
int AVL<T>::height(TreeNode<T>* n)
    {
        if(n != nullptr){
            return n->height;
        }
    };
template <class T>
int AVL<T>::getBalanceF(TreeNode<T>* n)
    {
        if(n != nullptr){
            return height(n->left) - height(n->right);
        }
    };
template <class T>
TreeNode<T>* AVL<T>::RightRotation(TreeNode<T>* head)
    {
        TreeNode<T>* newHead = head->left;
        head->left = newHead->right;
        newHead->right = head;
        // update height
        head->height = 1 + max(height(head->left),height(head->right));
        newHead->height = 1 + max(height(newHead->left),height(newHead->right));
        // return new root;
        return newHead;
    }
template <class T>
TreeNode<T>* AVL<T>::LeftRotation(TreeNode<T>* head)
    {
        TreeNode<T>* newHead = head->right;
        head->right = newHead->left;
        newHead->left = head;
        // update height
        head->height = 1 + max(height(head->left),height(head->right));
        newHead->height = 1 + max(height(newHead->left),height(newHead->right));
        // return new root;
        return newHead;
    }
template <class T>
int AVL<T>::hash_func(T& data){
    int hash_val = (data.getID()) % CAPACITY;
    data.set_hash_val(hash_val);
    return hash_val;
}
template <class T>
unsigned long AVL<T>::hash_func_UserName_V2(T& data){  ///////////////improved Hashing Function integration
    unsigned long count = 0;
    string str = data.getUserName();
    int length = str.size();
    for (int j = 0; j<length ; j++){
        count += 1;
    }
    count += int(str[0]);
    unsigned long hash_val = count % CAPACITY ;
    data.set_hash_val(hash_val);
    return hash_val;
}
template <class T>
int AVL<T>::hash_func_ID(int User_ID){
    int hash_val = User_ID % CAPACITY;
    return hash_val;
}
template <class T>
void AVL<T>::pass_hash_to_Node(TreeNode<T>* r, T& data){
int hash_val = hash_func_ID(data.getID());
r->hash_val = hash_val;

}
template <class T>
TreeNode<T>* AVL<T>::insertRec(TreeNode<T>* r ,T &data)
    {
        int n;
        int hash_val = hash_func(data);
        if(r==nullptr)
        {

            TreeNode<T>* newnode= new TreeNode<T>(data);
            newnode->parent = r;
            pass_hash_to_Node(newnode, data);
            r = newnode;


        }
        else if(hash_val < (r->data).hash_val){
            r->left = insertRec(r->left , data);
        }
        else if(hash_val > (r->data).hash_val){
            r->right = insertRec(r->right , data);
        }
        else if(hash_val == (r->data).hash_val){
            try{
            if(data.getID() < (r->data).getID()){
                r->left = insertRec(r->left , data);
            }
            else if(data.getID() > (r->data).getID()){
                r->right = insertRec(r->right , data);
            }
            else{ throw (n); }
            }
            catch(...){
            cout<<"\n\t\t\tThey have the Same ID ... Try Again! "<<endl;
            }
        }

        r->height = 1 + max(height(r->left),height(r->right));
        int BF = getBalanceF(r);
        if(BF > 1)
        {
            if(hash_val < (r->left->data).hash_val)
                return RightRotation(r);
            else
            {
                r->left = LeftRotation(r->left);
                return RightRotation(r);
            }
        }
        else if (BF < -1)
        {
            if(hash_val > (r->right->data).hash_val)
                return LeftRotation(r);
            else
            {
                r->right = RightRotation(r->right);
                return LeftRotation(r);
            }
        }
        return r ;
    };

template <class T>
TreeNode<T>* AVL<T>::Search_Node(TreeNode<T>* r ,int User_ID)
{
int n;
try{
           int hash_val = hash_func_ID(User_ID);
           if(r == nullptr){
               // throw (n);
               return nullptr;
           }
           else if(hash_val > r->hash_val){
            Search_Node(r->right , User_ID);
           }
           else if(hash_val < r->hash_val){
            Search_Node(r->left , User_ID);
           }
           else{
            if( User_ID == (r->data).getID()){
                 return r;
             }
            else if( User_ID > (r->data).getID()){
                 Search_Node(r->right , User_ID);
             }
            else if( User_ID < (r->data).getID()){
                 Search_Node(r->left , User_ID);
             }
            else{
                throw (n);
                return nullptr;
            }

           }
}
catch(...){
cout<<"\n\t\t\tNot Found ! "<<endl;
}

};
template <class T>
bool AVL<T>::Search_bool(TreeNode<T>* r, int User_ID)
{
           int hash_val = hash_func_ID(User_ID);
           if(r == nullptr){
                return false;
           }
           if(hash_val > r->hash_val){
            Search_bool(r->right , User_ID);
           }
           else if(hash_val < r->hash_val){
            Search_bool(r->left , User_ID);
           }
           else{
            if( User_ID == (r->data).getID()){
                 return true;
             }
            else if( User_ID > (r->data).getID()){
                 Search_bool(r->right , User_ID);
             }
            else if( User_ID < (r->data).getID()){
                 Search_bool(r->left , User_ID);
             }
           }



};
template <class T>
bool AVL<T>::Search_bool(int User_ID)
{
           bool flag = Search_bool(root,User_ID);
           return flag;

};
template <class T>
T& AVL<T>::Search_data(TreeNode<T>* r ,int User_ID)
{
    int n;
    int hash_val = hash_func_ID(User_ID);
try{
           if(r == nullptr){
               throw (n);
           }
           if(hash_val > r->hash_val){
            Search_data(r->right , User_ID);
           }
           else if(hash_val < r->hash_val){
            Search_data(r->left , User_ID);
           }
           else{
            if( User_ID == (r->data).getID()){
                 return r->data;
             }
            else if( User_ID > (r->data).getID()){
                 Search_data(r->right , User_ID);
             }
            else if( User_ID < (r->data).getID()){
                 Search_data(r->left , User_ID);
             }
            else{
               throw (n);
            }

           }
}
catch(...){
cout<<"\n\t\t\tNot Found ! "<<endl;
}

};
template <class T>
void AVL<T>::SearchRec(TreeNode<T>* r ,int User_ID)
{
           int hash_val = hash_func_ID(User_ID);
           if(r == nullptr){
               return;
           }
           else if(hash_val > r->hash_val){
            SearchRec(r->right , User_ID);
           }
           else if(hash_val < r->hash_val){
            SearchRec(r->left , User_ID);
           }
           else{
            if( User_ID == (r->data).getID()){
                 cout<<"\n\t\t\tFound Successfully ! "<<r->data<<endl;
             }
            else if( User_ID > (r->data).getID()){
                 SearchRec(r->right , User_ID);
             }
            else if( User_ID < (r->data).getID()){
                 SearchRec(r->left , User_ID);
             }
            else{
                return;
            }

           }


};
template <class T>
TreeNode<T>* AVL<T>::minValueNode(TreeNode<T>* node)
{
    TreeNode<T>* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
};

template <class T>
TreeNode<T>* AVL<T>::DeleteRec(TreeNode<T>* r ,T &data)
     {
        if(r == nullptr)
            return nullptr;
        else if(data.hash_val > r->hash_val)
            r->right = DeleteRec(r->right , data);
        else if(data.hash_val < r->hash_val)
            r->left = DeleteRec(r->left , data);
        else
        {

            // node with only one child or no child
            if (r -> left == NULL)
            {
                TreeNode<T>* temp = r -> right;
                delete r;
                return temp;
            }
            else if (r -> right == NULL)
            {
                TreeNode<T>* temp = r -> left;
                delete r;
                return temp;
            }
            else
            {

                TreeNode<T>* temp = minValueNode(r->right);
                //r->data = temp->data;
                cout<<temp->hash_val;
                cout<<r->hash_val;
                (r->data).replace_user(temp->data);
                r->right = DeleteRec(r->right , temp->data);

            }
        }
        if(r == nullptr)
            return r;
        r->height = 1 + max(height(r->left),height(r->right));
        int BF = getBalanceF(r);
        if(BF > 1)
        {
            if(data.hash_val < r->left->hash_val)
                return RightRotation(r);
            else
            {
                r->left = LeftRotation(r->left);
                return RightRotation(r);
            }
        }
        else if (BF < -1)
        {
            if(data.hash_val > r->right->hash_val)
                return LeftRotation(r);
            else
            {
                r->right = RightRotation(r->right);
                return LeftRotation(r);
            }
        }
        return r ;
    };
template <class T>
TreeNode<T>* AVL<T>::findmin(TreeNode<T>* r)
   {
        if(r != nullptr)
            return findmin(r->left);
        return r;
    };

template <class T>
void AVL<T>::inOrder(TreeNode<T>* r)
   {
        if(r != NULL)
        {
            inOrder(r->left);
            cout<<r->data<<" " ;
            //inOrder(r->next);
            inOrder(r->right);
        }
    };
template <class T>
AVL<T>::AVL()
    {
        root = nullptr ;
    };
template <class T>
void AVL<T>::Delete(int User_ID)
    {
        bool flag = Search_bool(User_ID);
        if(flag){
        T data = Search_data(root,User_ID);
        root = DeleteRec(root , data);
        cout<<"\n\t\t\tDeleted Successfully ! "<<endl;
        }
        else{
            cout<<"\n\t\t\tUser ID not Found ... Try Again! "<<endl;
        }
    };
template <class T>
void AVL<T>::Edit(int User_ID)
    {
        bool flag = Search_bool(User_ID);
        if(flag){
        TreeNode<T>* r = Search_Node(root,User_ID);
        cin>>r->data;
        int hash_val = hash_func(r->data);
        r->hash_val = hash_val ;
        cout<<"\n\t\t\tEdited Successfully ! "<<endl;
        }
        else{
            cout<<"\n\t\t\tUser ID not Found ... Try Again! "<<endl;
        }
    };
template <class T>
void AVL<T>::Edit_Activity(int User_ID, int Activity_ID)
    {
        bool flag = Search_bool(User_ID);
        bool flag_2 = false;
        if(flag){
        TreeNode<T>* r = Search_Node(root,User_ID);
        int Q_size = r->Activities.getsize();
        for(int i=0;i<Q_size;i++){
        if(r->Activities.at(i).getID() == Activity_ID){
            cin>>r->Activities.at(i);
            flag_2 = true;
            break;
        }
        }
        }
        if(flag && flag_2){
            cout<<"\n\t\t\tEdited Successfully ! "<<endl;
        }
        else if(flag){
            cout<<"\n\t\t\tFound User ID but Activity ID is not found ! "<<endl;
        }
    };
template <class T>
void AVL<T>::Delete_Activity(int User_ID, int Activity_ID)
    {
        bool flag = Search_bool(User_ID);
        bool flag_2 = false;
        if(flag){
        TreeNode<T>* r = Search_Node(root,User_ID);
        int Q_size = r->Activities.getsize();
        for(int i=0;i<Q_size;i++){
        if(r->Activities.at(i).getID() == Activity_ID){
            r->Activities.delete_node(i);
            flag_2 = true;
            break;
        }
        }
        }
        if(flag && flag_2){
            cout<<"\n\t\t\tDeleted Successfully ! "<<endl;
        }
        else if(flag){
            cout<<"\n\t\t\tFound User ID but Activity ID is not found ! "<<endl;
        }
    };

template<class T>
void AVL<T>::insert(T &data)
    {
        root = insertRec(root , data);
    };
template<class T>
void AVL<T>::insert_Activity(int User_ID, Activity &data)
    {

        TreeNode<T>* r = Search_Node(root,User_ID);
        r->Activities.push(data);
        int Q_size = r->Activities.getsize();
        if(Q_size == Max_Activity_Size){ ////////////// Max Activity Size
            r->Activities.pop();
        }
    };


template<class T>

void AVL<T>::Search(int User_ID)
    {
      SearchRec(root,User_ID);
    };


template<class T>
void AVL<T>::Show_User_Activity(int User_ID)
    {
        TreeNode<T>* r = Search_Node(root,User_ID);
        r->Activities.print();
    };

template <class T>
void AVL<T>::inOrder()
    {
        cout<<"\n\t\t\t   [ Users ] "<<endl;
        inOrder(root);
    };



#endif
#endif // AVL_H

