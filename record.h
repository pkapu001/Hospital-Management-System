#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include "patient.h"

using namespace std;
class record
{
    static int start_r_id;
    string id, patient_id;
    string notes;
public:
    record(const patient&);
///getters____________________________
    string getid()const    {        return id;    }
    string getpatient_id()const    {        return patient_id;    }
    string getnotes()const    {        return notes;    }
///___________________________________
///setters______________________________
    void setid(string n )    {        id=n;    }
    void setpatient_id(string n )    {        patient_id=n;    }
    void setnotes(string s)    {        notes=s;    }
///______________________________________
    void update(); /// updates record
    void print()const; /// prints records
};
void update_record(vector<record>&r,const vector<patient>&p); /// updates records
void print_all(const vector<record>&r); /// print all records
void search_record(const vector<record>&r); /// searches record
void manage_records(vector<record>&r,const vector<patient>&p); /// manages record
void deleat_record(vector<record>&r);  /// deletes record
#endif // RECORD_H_INCLUDED
