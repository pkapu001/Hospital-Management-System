#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include "doctor.h"
#include "diagnosis.h"
#include <windows.h>
#include "date_time.h"
#include "appointment.h"
#include "slot.h"

using namespace std;
class doctor;
class appointment;
class slot;
class date_time;
class patient
{
    string id, doctor_id, record_id, diagnosis_id  ;
    string name, email, phone ;
    char gender ;
    string blood_type ;
public:
    patient();
    patient(ifstream &in);
    patient(istream & in,vector<patient>&p, const vector<doctor>&d);
/// getters_______________________________
    string getid() const    {        return id;    }
    string getdoctor_id() const    {        return doctor_id;    }
    string getrecord_id()   const    {        return record_id;    }
    string getdiagnosis_id()   const    {        return diagnosis_id;    }
    string getphone() const    {        return phone;    }
    string getname() const    {        return name;    }
    string getemail() const    {        return email;    }
    string getblood_type() const    {        return blood_type;    }
    char getgender() const    {        return gender;    }
///________________________________________
/// setters___________________________________
    void setid( string n )    {        id =n;    }
    void setd_id( string n )    {        doctor_id=n;    }
    void setr_id( string n )    {        record_id=n;    }
    void setde_id( string  n )    {        diagnosis_id=n;    }
    void setphone( string s )    {        phone=s;    }
    void setname( string s )    {        name=s;    }
    void setemail( string s)    {        email=s;    }
    void setblood_type( string s)    {        blood_type=s;    }
    void setgender(char c)    {        gender=c;    }
///_____________________________________________

    void print(const vector<diagnosis>&de)const; /// prints patient
    void print()const;/// prints patient
    void print(const doctor&d,const vector<diagnosis>&de) const ;/// prints patient
    void print(const vector<doctor>&d,const vector<diagnosis>&de) const ;/// prints patient
    void update(const vector<patient>&p, const vector<doctor>&d,const vector<diagnosis>&de);/// updates patient
};

template <class t >
int search_by_id(const vector<t>&a,const string&s)  /// gets the index by id
{
    for(int i =0 ; i < a.size() ; i++)
    {
        if(s==a[i].getid())
        {            return i;        }
    }
    return -1;
}

template <class t1, class t2>
int search_by_d_id(const vector<t1>&a, const vector<t2>&d, const string s, int j=-1  )  ///  -0 to print all with the id  ... get the index by doctor id
{
    int index;
    for(int i =0 ; i < a.size() ; i++)
    {
        if(s==a[i].getdoctor_id())
        {
            if(j>-1)
            {
                index=search_by_id(d, a[i].getdoctor_id());
                a[i].print(d[index]);
                j++;
            }
            else
                return i;
        }
    }
    if(j>0)
    {        return -2;    }
    else
    {        cout<< "\n  not found" << endl;        return -1;    }
}

template <class t1, class t2>
int search_by_d_id(const vector<t1>&a, const vector<t2>&d,const vector<diagnosis>&de, const string s, int j=-1  )  ///  -0 to print all with the id  /// searches by doctor id and prints
{
    int index;
    for(int i =0 ; i < a.size() ; i++)
    {
        if(s==a[i].getdoctor_id())
        {
            if(j>-1)
            {
                index=search_by_id(d, a[i].getdoctor_id());
                a[i].print(d[index],de);
                j++;
            }
            else
                return i;
        }
    }
    if(j>0)
    {        return -2;    }
    else
    {        cout<< "\n  not found" << endl;        return -1;    }
}

template <class t>
int search_by_name(const vector<t>&a, const string s, int j=-1 )   /// search by name and prints
{
    for(int i =0 ; i < a.size() ; i++)
    {
        if(s==a[i].getname())
        {
            if(j>-1)
            {                a[i].print();                j++;            }
            else
                return i;
        }
    }
    if(j>0)
    {        return -2;    }
    else
    {        cout<< "\n  not found" << endl;        return -1;    }
}

template <class t1, class t2>
int search_by_name(const vector<t1>&a, const vector<t2>&d, const string s, int j=-1  ) /// searches by name and prints
{
    int index;
    for(int i =0 ; i < a.size() ; i++)
    {
        if(s==a[i].getname())
        {
            if(j>-1)
            {
                index=search_by_id(d, a[i].getdoctor_id());
                a[i].print(d[index]);
                j++;
            }
            else
                return i;
        }
    }
    if(j>0)
    {        return -2;    }
    else
    {        cout<< "\n  not found" << endl;        return -1;    }

}

template <class t1, class t2>
int search_by_name(const vector<t1>&a, const vector<t2>&d,const vector<diagnosis>&de, const string s, int j=-1  ) /// searches by name and prints
{
    int index;
    for(int i =0 ; i < a.size() ; i++)
    {
        if(s==a[i].getname())
        {
            if(j>-1)
            {
                index=search_by_id(d, a[i].getdoctor_id());
                a[i].print(d[index],de);
                j++;
            }
            else
                return i;
        }
    }
    if(j>0)
    {        return -2;    }
    else
    {        cout<< "\n  not found" << endl;        return -1;    }
}

template <class t>
int search_by_email( const vector<t>&a, const string s, int j=-1) /// searches by email and prints
{
    for(int i =0 ; i < a.size() ; i++)
    {
        if(s==a[i].getemail())
        {
            if(j>-1)
            {                a[i].print();                j++;            }
            else
                return i;
        }
    }
    if(j>0)    {        return -2;    }
    else    {        cout<< "\n patient not found" << endl;        return -1;    }
}
template <class t1,class t2>
int search_by_email( const vector<t1>&a, const vector<t2>&d,const vector<diagnosis>&de, const string s, int j=-1)/// searches by email and prints
{
    int index;
    for(int i =0 ; i < a.size() ; i++)
    {
        if(s==a[i].getemail())
        {
            if(j>-1)
            {
                index=search_by_id(d, a[i].getdoctor_id());
                a[i].print(d[index],de);
                j++;
            }
            else
                return i;
        }
    }
    if(j>0)    {        return -2;    }
    else    {        cout<< "\n patient not found" << endl;        return -1;    }
}

void addpatient(vector<patient>&p,const vector<doctor>&d); ///=== adds patients
void read(vector<patient>&a, ifstream &in); /// reads patients from file
void printall(const vector<patient>&p,const vector<diagnosis>&de ); /// prints all patients
void printall(const vector<patient>&p, const vector<doctor>&d,const vector<diagnosis>&de );  ///=== prints all patients
void update_patient(vector<patient> &p, const vector<doctor>&d); ///=== updates a patient
void deleat(vector<patient>&p ); ///=== deletes patient
void print_by_name(const vector<patient>&p, const vector<doctor>&d,const vector<diagnosis>&de); ///=== prints my name
void print_by_id(const vector<patient>&p, const vector<doctor>&d,const vector<diagnosis>&de); ///=== prints by id
void print_by_email( const vector<patient>&p,const vector<doctor>&d,const vector<diagnosis>&de); ///=== prints my email
void print_p_by_d_n(const vector<patient>&p, const vector<doctor>&d,const vector<diagnosis>&de);  ///===== prints by doctor name
void manage_patents(vector<patient>&p, const vector<doctor>&d,vector<appointment>&a, vector<slot>&s, vector<date_time>&t,const vector<diagnosis>&de); /// manages patients

#endif // PATIENT_H_INCLUDED
