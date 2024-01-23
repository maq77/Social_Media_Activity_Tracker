#ifndef SOCIALMEDIASYSTEM_H
#define SOCIALMEDIASYSTEM_H
#include <bits/stdc++.h>
#include <chrono>
#include "user.h"
#include "AVL.h"

using namespace std;

class SocialMediaSystem
{
    public:
        AVL<User> t;
        SocialMediaSystem();
        void AddUser();
        void ShowUsers();
        void SearchUser(int User_ID);
        void DeleteUser(int User_ID);
        void AddActivity_User(int User_ID);
        void ShowActivities_User(int User_ID);
        void EditUser(int User_ID);
        void EditActivity(int User_ID,int Activity_ID);
        void DeleteActivity(int User_ID,int Activity_ID);

    private:
};

#endif // SOCIALMEDIASYSTEM_H
