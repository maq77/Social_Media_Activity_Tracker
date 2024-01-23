#include "user.h"

User::User(){
        ID = 0;
        username = "";
};
int User::getID(){ return ID; };
string User::getUserName(){ return username; };
void User::set_hash_val(int new_hash){ hash_val = new_hash; };
int User::get_hash_val(){ return hash_val; };
void  User::Add_Activity(){
        Activity new_Activity;
        cin>>new_Activity;
        Activities.push(new_Activity);
        Activity_count++;
        cout<<Activities.getsize();
};
void User::print_Activities(){
        cout<<Activities.getsize();
        for(int i=0;i<Activity_count;i++){
            cout<<"\n\t\t\tActivity [ No. "<<i+1<<" ]  "<<endl;
            cout<<Activities.at(i);
        }
};
ostream& operator<<(ostream& os,const User &U) {
         return os <<"\n\t\t\tUser ID : "<<U.ID <<"\n\t\t\tUser Name : "<< U.username <<"\n\t\t\tHash Value : "<<U.hash_val;
};
istream& operator>>(istream& in,User &U) {
          cin.exceptions(std::ios_base::failbit);
          try{
          cout<<"\n\t\t\tEnter User ID : ";
          in >>U.ID;
          cout<<"\n\t\t\tEnter User Name : ";
          in >>U.username;
          }
        catch (const std::ios_base::failure &) {
            cout  << "\n\t\t\tPlease enter numbers only!" << std::endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
          return in;
};



