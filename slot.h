#ifndef SLOT_H_INCLUDED
#define SLOT_H_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include <sstream>
#include "doctor.h"
#include "date_time.h"
#include "appointment.h"
using namespace std;
class doctor;
class date_time;
class slot
{
    string id;
    string date_id;
    string doctor_id;
    bool avalable;
    static int start_slot_id ;
public:
    slot();
    slot(ifstream &in);                                                     /// constructors to create slots
    slot(istream &in,const vector<doctor>&d, vector<date_time>&t);
///getters___________________
    string getid() const    {        return id;    }
    string getdate_id()const    {        return date_id;    }
    string getdoctor_id() const    {        return doctor_id;    }
    bool getavalable() const    {        return avalable;    }
///________________________________________
///setters_________________________
    void setid(string n)    {        id=n;    }
    void setdate_id(string n)    {        date_id;    }
    void setdoctor_id(string n )    {        doctor_id = n ;    }
    void setavalable(bool b)    {        avalable=b;    }
///__________________________________________
    void print(const vector<doctor>&d,const vector<date_time>&t )const; /// prints slots
    void update(const vector<doctor>&d, vector<date_time>&t); /// updates slots

};
void update_slots(vector<slot>&s, const vector<doctor>&d, vector<date_time>&t  );  ///=== updates slots
void printall(const vector<slot>&s,const vector<doctor>&d,const vector<date_time>&t );  ///=== prints all slots
void printall_a(const vector<slot>&s,const vector<doctor>&d,const vector<date_time>&t );  ///=== prints all available slots
void printall_u(const vector<slot>&s,const vector<doctor>&d,const vector<date_time>&t );  ///=== prints all unavailable slots
void print_s_by_d_id(const vector<slot>&s,const vector<doctor>&d,const vector<date_time>&t,const string &d_id );   ///===prints all slots by doctor id
void a_slots_t_r(const vector<slot>&s,const vector<doctor>&d,const vector<date_time>&t );  ///=== prints slots between time range
void a_slots_d_n(const vector<slot>&s,const vector<doctor>&d,const vector<date_time>&t );  ///===  prints all available slots by doctors name
void deleat_slot(vector<slot>&s,int ); /// deletes slot
void read(vector<slot>&a, ifstream &in); /// reads data from file to vector
void manage_slots(vector<slot>&s,const vector<doctor>&d, vector<date_time>&t); /// manages slots

#endif // SLOT_H_INCLUDED
