#ifndef DATE_TIME_H_INCLUDED
#define DATE_TIME_H_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include <sstream>
#include "slot.h"
#include "appointment.h"

using namespace std;
class appointment;
class slot;
class date_time
{
    string id ;
    int day, month, year, hours, minutes ;
    char am_pm ;
    static int start_date_id;
public:
    date_time();
    date_time(ifstream &in);        /// constructors to read and create date and time
    date_time(istream &in);
    date_time(istream &in, int i);
///getters____________________________
    string getid()const    {        return id;    }
    int getday() const    {        return day;    }
    int getmonth() const    {        return month;    }
    int getyear() const    {        return year;    }
    int gethour() const    {        return hours;    }
    int getmin() const    {        return minutes;    }
    char getam_pm() const    {        return am_pm;    }
///_____________________________________
///setters__________________________________
    void setid( string n )    {        id=n;    }
    void setday(int n )    {        day=n;    }
    void setmonth(int n )    {        month=n;    }
    void setyear(int n )    {        year=n;    }
    void sethour(int n )    {        hours=n;    }
    void setmin(int n )    {        minutes=n;    }
    void setam_pm(char c)    {        am_pm=c;    }
///____________________________________________________
    void print()const;/// prints date and time
    void update();/// updates date and time
    friend bool operator==(const date_time&t1, const date_time&t2); ///overlooding operator
    friend bool lab_date_check(vector<appointment>&a,vector<slot>&s,const  vector<date_time>&t,const int s_i  ); /// friend function to check the date match for labs
};
void print_date_by_id(const vector<date_time>&t, string s); /// prints dates by id
void read(vector<date_time>&a, ifstream &in); /// reads data from the file to vector

inline
ostream& operator<<(ostream &os, const date_time &t) {    t.print();    return os;}/// overriding operator to print

inline
bool operator>(const date_time&t1, const date_time&t2) /// over riding greater than operator
{
    if(t1.getyear() > t2.getyear())    {   return true ; }
    else if(t1.getyear() != t2.getyear())  {  return false ;  }
    if(t1.getmonth()> t2.getmonth() )   {    return true;  }
    else if(t1.getmonth()!= t2.getmonth())  {    return false; }
    if(t1.getday() >t2.getday() )   {     return true;  }
    else if(t1.getday() != t2.getday() )    {     return false;  }
    if (t1.getam_pm() == t2.getam_pm())
    {
        if(t1.gethour() > t2.gethour() )   {       return true;    }
        else if(t1.gethour() != t2.gethour() )    {  return false;  }
        if(t1.getmin() > t2.getmin())      {      return true;    }
        else if(t1.getmin() != t2.getmin())  {      return false;  }
    }
    else if (t1.getam_pm()=='p')    {        return true;    }
    return false;
}

inline
bool operator<(const date_time&t1, const date_time&t2) /// over riding less than operator
{    return ! ( t1>t2  );}
inline
bool operator==(const date_time&t1, const date_time&t2)
{
    if( t1.year==t2.year && t1.month==t2.month && t1.day==t2.day&&
            t1.am_pm==t2.am_pm && t1.hours==t2.hours &&t1.minutes==t2.minutes    )
    {        return true;    }
    else    {        return false;    }
}
#endif // DATE_TIME_H_INCLUDED
