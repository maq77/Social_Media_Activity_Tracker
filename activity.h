#ifndef ACTIVITY_H
#define ACTIVITY_H
#include <iostream>
#include <stdexcept>
#include <limits.h>

using namespace std;

class Activity
{
    public:
        Activity();
        Activity(int id,string type);
        friend ostream& operator<<(ostream& os,const Activity &A);
        friend istream& operator>>(istream& in, Activity &A);
        int getID();
        string getType();
    private:
        int ID;
        string Type;
};

#endif // ACTIVITY_H
