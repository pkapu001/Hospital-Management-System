#ifndef DOCTOR_H_INCLUDED
#define DOCTOR_H_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include <stdlib.h>
#include "appointment.h"

using namespace std;
class appointment;
class slot;
class doctor
{
    string id ;
    string name, username, password, skill, phone;
    friend ostream& operator<<(ostream& os, const  doctor& d  );
    friend ostream& operator<<(ostream& os, const vector<doctor>&d  );
public:
    doctor();
    doctor(ifstream &in);
    doctor (istream &in, vector<doctor>&d);    /// constructors to create doctors
///getters___________________________________
    string getid() const    {        return id;    }
    string getphone() const    {        return phone;    }
    string getname() const     {        return name;    }
    string getusername() const    {        return username;    }
    string getpassword() const    {        return password;    }
    string getskill() const    {        return skill;    }
///__________________________________________
///setters_____________________________________

    void setid( string n )    {        id=n;    }
    void setphone( string s )    {        phone=s;    }
    void setname( string s )    {        name=s;    }
    void setusername(string s)    {        username=s;    }
    void setpassword(string s)    {        password=s;    }
    void setskill(string s)    {        skill=s;    }
///___________________________________________
    void print()const;  /// prints doctors
    void update(); /// updates doctors
    bool check_appointment(const vector< appointment > &a);  /// checks if doctor has appointments
};
template < class t>
string getid_by_name(const vector<t>&a,const string s )   /// template which get id by name
{
    for(int i =0 ; i<a.size() ; i++)
    {
        if(s==a[i].getname())
        {            return a[i].getid();        }
    }
    return "-1";
}
template < class t>
string getname_by_id(const vector<t>&a,const string s )  /// template gets id by name
{
    for(int i =0 ; i<a.size() ; i++)
    {
        if(s==a[i].getid())
        {            return a[i].getname();        }
    }
    return "-1";
}

void printall(const vector<doctor>&d); /// prints all doctors
void read(vector<doctor>&a, ifstream &in); /// reads data from file to vector
void print_by_name(const vector<doctor>&d); /// prints doctor by name
void update_doctor( vector<doctor>&d); /// updates doctors info
void add_doctor(vector<doctor>&d); /// creates a new doctor;
void deleat_doctor(vector<doctor>&d,vector<slot>&s, const vector<appointment>&a); /// deletes doctor if he dosnt have and upcoming appointments
void manage_doctors(vector<doctor>&d,vector<slot>&s,const vector<appointment>&a); /// manges doctors

#endif // DOCTOR_H_INCLUDED
