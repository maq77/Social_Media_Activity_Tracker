#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <chrono>
#include "socialmediasystem.h"
/*

This Project was Made BY Mohammed Amin Helal


Have a Nice DAY !!!!!


*/
using namespace std;

int main()
{
  SocialMediaSystem Sys;
  int n;

do{
    cout<<"\t\t\t\t\t--[    Social Media Activity Tracker    ]--\n"<<endl;
    cout<<"\t\t\t"<<endl;
    cout<<"\t\t\t\t\t[    User Functions Section   ]"<<endl;
    cout<<"\t\t\t"<<endl;
    cout<<"\t\t\t1-Add User"<<endl;
    cout<<"\t\t\t2-Show Users"<<endl;
    cout<<"\t\t\t3-Search User"<<endl;
    cout<<"\t\t\t4-Edit User"<<endl;
    cout<<"\t\t\t5-Delete User"<<endl;
    cout<<"\t\t\t"<<endl;
    cout<<"\t\t\t\t\t[    Activity Functions Section   ]"<<endl;
    cout<<"\t\t\t"<<endl;
    cout<<"\t\t\t6-Add Activity for User BY User ID"<<endl;
    cout<<"\t\t\t7-Show Activity for User BY User ID"<<endl;
    cout<<"\t\t\t8-Edit Activity for User BY User ID"<<endl;
    cout<<"\t\t\t9-Delete Activity for User BY User ID"<<endl;
    cout<<"\t\t\t0-Exit"<<endl;
    cout<<"\t\t\t"<<endl;
    cout<<"\t\t\t>>>> ";cin>>n;

    switch(n){
case 0:
    {

           exit(0);
           break;
    }
case 1:{
        Sys.AddUser();
        cout<<"\n\t\t\tWait for 2 Seconds ! "<<endl;
        sleep(2);
        system ("CLS");
        break;
}
case 2:{
        Sys.ShowUsers();
        break;
}
case 3:{
        int ID;
        cout<<"\t\t\tEnter ID : ";
        cin>>ID;
        Sys.SearchUser(ID);
        cout<<"\n\t\t\tWait for 2 Seconds ! "<<endl;
        sleep(2);
        system ("CLS");
        break;
}
case 4:
    {
        int ID;
        cout<<"\t\t\tEnter ID : "; cin>>ID;
        Sys.EditUser(ID);
        sleep(2);
        system ("CLS");
        break;



    }
case 5:{
        int ID;
        cout<<"\t\t\tEnter ID : "; cin>>ID;
        Sys.DeleteUser(ID);
        cout<<"\n\t\t\tWait for 2 Seconds ! "<<endl;
        sleep(2);
        system ("CLS");
        break;
 }

case 6:
        {

        int ID;
        cout<<"\t\t\tEnter ID : "; cin>>ID;
        Sys.AddActivity_User(ID);
        cout<<"\n\t\t\tWait for 2 Seconds ! "<<endl;
        sleep(2);
        system ("CLS");
        break;

         }


case 7:
    {
        int ID;
        cout<<"\t\t\tEnter ID : "; cin>>ID;
        Sys.ShowActivities_User(ID);
        sleep(2);
        system ("CLS");
        break;



    }
case 8:
    {
        int User_ID,Activity_ID;
        cout<<"\t\t\tEnter User ID : "; cin>>User_ID;
        cout<<"\t\t\tEnter Activity ID : "; cin>>Activity_ID;
        Sys.EditActivity(User_ID,Activity_ID);
        sleep(2);
        system ("CLS");
        break;



    }
case 9:
    {
        int User_ID,Activity_ID;
        cout<<"\t\t\tEnter User ID : "; cin>>User_ID;
        cout<<"\t\t\tEnter Activity ID : "; cin>>Activity_ID;
        Sys.DeleteActivity(User_ID,Activity_ID);
        sleep(2);
        system ("CLS");
        break;



    }


 //     default:
//      break;


    }
    }while(n != 0);
    return 0;



    return 0;
}
