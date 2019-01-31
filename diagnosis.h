#ifndef DIAGNOSIS_H_INCLUDED
#define DIAGNOSIS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
using namespace std;
class diagnosis
{
    string id ;
    string disease_name;
public:
    diagnosis();                        /// constructors to create diagnosis
    diagnosis(ifstream &in,int i);
///getters______________________
    string getid()const    {        return id;    }
    string getdisease_name()const    {        return disease_name;    }
///___________________________________
///setters____________________________________
    void setid(string n)    {        id=n;    }
    void setdisease_name(string s)    {        disease_name=s;    }
///___________________________________________
    void print()const; /// prints diagnosis
};
void printall(const vector<diagnosis>&de);  /// prints all diagnosis
void read(vector<diagnosis>&a, ifstream &in); /// reads data from file to vector;

#endif // DIAGNOSIS_H_INCLUDED
