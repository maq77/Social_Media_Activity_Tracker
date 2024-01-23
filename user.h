#ifndef USER_H
#define USER_H
#include <iostream>
#include <stdexcept>
#include <limits.h>
#include "Activity.h"
#include "queue.h"

using namespace std;

class User
{
    public:
        int ID;
        int hash_val;
        string username;
        Queue<Activity> Activities;
        int Activity_count = 0;
        User();
        int getID();
        string getUserName();
        void set_hash_val(int new_hash);
        int get_hash_val();
        void Add_Activity();
        void print_Activities();
        void replace_user(User & U){
        this->ID = U.ID;
        this->username = U.username;
        this->hash_val = U.hash_val;

        }
        friend ostream& operator<<(ostream& os,const User &U);
        friend istream& operator>>(istream& in, User &U);



};

#endif // USER_H
