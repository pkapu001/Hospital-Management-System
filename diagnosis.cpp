#include "diagnosis.h"
#include <sstream>

diagnosis::diagnosis()
{
}

void read(vector<diagnosis>&a, ifstream &in)  /// reads data from file to vector
{
    int num;
    in>>num;
    string temp;
    for(int i=0 ; i<num ; i++)
    {
        getline(in,temp);
        a.push_back(diagnosis(in,i));
    }
    in.close();
}

diagnosis::diagnosis(ifstream &in, int i) /// constructor to read data from file to object
{
    getline(in,disease_name);
    stringstream ss;
    ss<<++i;
    id=ss.str();
}

void diagnosis::print()const {    cout<< "\n DIAGNOSIS ID : " << id<< "\tDESEASE NAME : " << disease_name<<endl;  }  ///prints diagnosis
void printall(const vector<diagnosis>&de) /// prints all diagnosis
{
    cout<<"==========DIAGNOSIS============\n";
    for(int i =0 ; i < de.size(); i++)
    {
        cout<<" - - - - - - - - - - - - - - - - - - \n";
        de[i].print();
        cout<<" - - - - - - - - - - - - - - - - - - \n";
    }
    cout<<"===============================\n";
}
