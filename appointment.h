#ifndef APPOINTMENT_H_INCLUDED
#define APPOINTMENT_H_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include "patient.h"
#include "slot.h"
#include "diagnosis.h"

using namespace std;
class slot;
class date_time;
class patient;
class appointment
{
    string  id, doctor_id,
            patient_id, slot_id,
            diagnosis_id;
    string  reason,
            prescribed_medication;
    bool lab=false;
    static int app_id;
public:
    appointment();
    appointment(istream &in,vector<appointment>&a, vector<patient>&p,const vector<doctor>&d, vector<slot>&s,const  vector<date_time>&t,const vector<diagnosis>&de, int lab_check =0  ); /// constructorato create appointment
///getters_________________________________
    string getid() const    {        return id;    }
    string getdoctor_id()const    {        return doctor_id;    }
    string getpatient_id()const    {        return patient_id;    }
    string getslot_id()const    {        return slot_id;    }
    string getdiagnosis_id()const    {        return diagnosis_id;    }
    string getreason() const    {        return reason;    }
    string getprescribed_medication() const    {        return prescribed_medication;    }
    bool getlab()const    {        return lab;    }
///___________________________________________

///setters_____________________________________

    void setlab(bool n)    {        lab=n;    }
    void setid( string n)    {        id=n;    }
    void setdoctor_id( string n)    {        doctor_id=n;    }
    void setpatient_id( string n)    {        patient_id=n;    }
    void setslot_id( string n)    {        slot_id=n;    }
    void setdiagnosis_id( string n)    {        diagnosis_id=n;    }
    void setreason(string s)    {        reason=s;    }
    void setprescribed_medication(string s)    {        prescribed_medication=s;    }
///__________________________________________________
    friend void patients_t_r(const vector<patient>&p, const vector<doctor>&d, const vector<appointment>&a,const vector<diagnosis>&de ); /// prints appointments within time range
    void update(vector<patient>&p, const vector<doctor>&d, vector<slot>&s,const vector<date_time>&t, const vector<diagnosis>&de); /// updates appointments
    void print(const vector<patient>&p,const vector<doctor>&d,const vector<slot>&s,const vector<date_time>&t,const vector<diagnosis>&de)const; /// prints appointment
};
void update_appointment( vector<patient>&p, vector<appointment>&a, const vector<doctor>&d, vector<slot>&s, vector<date_time>&t, const vector<diagnosis>&de);  ///==== updates appointments
void printall(const vector<appointment>&a, const vector<patient>&p, const vector<doctor>&d,const vector<slot>&s, const vector<date_time>&t,const vector<diagnosis>&de,int lab_check=0);///==== prints all appointments
void printall_d_n(const vector<appointment>&a, const vector<patient>&p, const vector<doctor>&d,const vector<slot>&s, const vector<date_time>&t,const vector<diagnosis>&de); ///=== prints all appointments by doctor name
void manage_appointments(vector<appointment>&a,  vector<patient>&p, const vector<doctor>&d, const vector<date_time>&t, vector<slot>&s, const vector<diagnosis>&de);    ///===manages appointments
void manage_labs(vector<appointment>&a, vector<patient>&p, const vector<doctor>&d, const vector<date_time>&t, vector<slot>&s, const vector<diagnosis>&de );/// manages labs
void deleat_appointment(vector<appointment>&a, vector <slot>&s,int lab_check=0);  ///==== deletes appointments

#endif // APPOINTMENT_H_INCLUDED
