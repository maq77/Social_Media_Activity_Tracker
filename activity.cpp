#include "activity.h"

Activity::Activity(){};
Activity::Activity(int id,string type){Type = type; ID = id;};
ostream& operator<<(ostream& os,const Activity &A) {
         return os <<"\n\t\t\tActivity ID : "<<A.ID <<"\n\t\t\tActivity Type : "<< A.Type;
};


istream& operator>>(istream& in, Activity &A) {

          cout<<"\n\t\t\tEnter Activity ID : ";
          in >>A.ID;
          cout<<"\n\t\t\tEnter Activity Type : ";
          in >>A.Type;


          return in;
};

int Activity::getID(){return ID;};
string Activity::getType(){return Type;};
