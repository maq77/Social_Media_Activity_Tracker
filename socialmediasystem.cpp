#include "socialmediasystem.h"

SocialMediaSystem::SocialMediaSystem()
{
    //ctor
}

void SocialMediaSystem::AddUser(){

        User newUser;
        cin>>newUser;
        auto t1 = std::chrono::high_resolution_clock::now();
        cout<<"\n\t\t\t[    Adding User   ]    "<<endl;
        t.insert(newUser);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        cout<<"\n\t\t\tUser Added !"<<endl;
        cout<<"\n\t\t\tTime taken for this function to Excute is ---> "<<duration<<" Micro Seconds."<<endl;

}
void SocialMediaSystem::ShowUsers(){

        auto t1 = std::chrono::high_resolution_clock::now();
        t.inOrder();
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        cout<<"\n\t\t\tTime taken for this function to Excute is ---> "<<duration<<" Micro Seconds."<<endl;


}
void SocialMediaSystem::SearchUser(int User_ID){

        auto t1 = std::chrono::high_resolution_clock::now();
        cout<<"\n\t\t\t[    Search User   ]    "<<endl;
        t.Search(User_ID);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        cout<<"\n\t\t\tTime taken for this function to Excute is ---> "<<duration<<" Micro Seconds."<<endl;



}
void SocialMediaSystem::DeleteUser(int User_ID){

        auto t1 = std::chrono::high_resolution_clock::now();
        cout<<"\n\t\t\t[    Delete User   ]    "<<endl;
        t.Delete(User_ID);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();


}
void SocialMediaSystem::AddActivity_User(int User_ID){
        int n;
        try{
        bool flag = t.Search_bool(User_ID);
        if(flag){
        Activity newActivity;
        cout<<"\n\t\t\t[    Adding Activity    ]    "<<endl;
        cin>>newActivity;
        t.insert_Activity(User_ID,newActivity);
        }
        else{
            throw (n);
        }
        }
        catch(...){
          cout<<"\n\t\t\tNot Found !"<<endl;
        }

}
void SocialMediaSystem::ShowActivities_User(int User_ID){

        auto t1 = std::chrono::high_resolution_clock::now();
        bool flag = t.Search_bool(User_ID);
        if(flag){
        cout<<"\n\t\t\t[    Activities   ]    "<<endl;
        t.Show_User_Activity(User_ID);
        }
        else{
            cout<<"\n\t\t\tNot Found ! ... Try Again !"<<endl;
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        cout<<"\n\t\t\tTime taken for this function to Excute is ---> "<<duration<<" Micro Seconds."<<endl;


}
void SocialMediaSystem::EditUser(int User_ID){

        auto t1 = std::chrono::high_resolution_clock::now();
        bool flag = t.Search_bool(User_ID);
        if(flag){
        cout<<"\n\t\t\t[    Edit User   ]    "<<endl;
        t.Edit(User_ID);
        }
        else{
            cout<<"\n\t\t\tNot Found ! ... Try Again !"<<endl;
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        cout<<"\n\t\t\tTime taken for this function to Excute is ---> "<<duration<<" Micro Seconds."<<endl;


}
void SocialMediaSystem::EditActivity(int User_ID, int Activity_ID){

        auto t1 = std::chrono::high_resolution_clock::now();
        bool flag = t.Search_bool(User_ID);
        if(flag){
        cout<<"\n\t\t\t[    Edit Activity   ]    "<<endl;
        t.Edit_Activity(User_ID , Activity_ID);
        }
        else{
            cout<<"\n\t\t\tNot Found ! ... Try Again !"<<endl;
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        cout<<"\n\t\t\tTime taken for this function to Excute is ---> "<<duration<<" Micro Seconds."<<endl;


}
void SocialMediaSystem::DeleteActivity(int User_ID, int Activity_ID){

        auto t1 = std::chrono::high_resolution_clock::now();
        bool flag = t.Search_bool(User_ID);
        if(flag){
        cout<<"\n\t\t\t[    Delete Activity   ]    "<<endl;
        t.Delete_Activity(User_ID , Activity_ID);
        }
        else{
            cout<<"\n\t\t\tNot Found ! ... Try Again !"<<endl;
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        cout<<"\n\t\t\tTime taken for this function to Excute is ---> "<<duration<<" Micro Seconds."<<endl;


}

