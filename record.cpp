#include "record.h"
#include <sstream>
#include <windows.h>
#include <istream>

record::record(const patient &p) /// CREATES A NEW RECORD;
{
    id=p.getrecord_id();
    patient_id=p.getid();
    cout<< " NOTES : ";
    string temp;
    cin.ignore();
    getline(cin,notes);
}

void update_record(vector<record>&r,const vector<patient>&p) /// UPDATES RECORD IF EXISTING IF NOT CREATES A NEW ONE
{
    string temp;
start:
    cout<< " ENTER PATIENT ID : ";
    cin>>temp;
    int p_i, r_i;
    p_i=search_by_id(p,temp);
    if(search_by_id(p,temp)==-1)
    {
        cout<< "\n\n\t\t PATIENT DOSENT EXIST!!";
        Sleep(1*1000);
        system("CLS");
        goto start;
    }
    else
    {
        r_i=search_by_id(r,p[p_i].getrecord_id());
        if(-1==r_i)
        {            r.push_back(record(p[p_i]));        }
        else
        {            r[r_i].update();        }
    }
}

void record::update()  /// UPDATES A RECORD
{
    cout<< " NOTES : ";
    cin.ignore();
    getline(cin,notes);
}

void record::print()const  /// PRINTS RECORD
{
    cout<<"\n- - - - - - - - - - - - - - - - - -\n";
    cout<< "RECORD ID  : " << id<<endl;
    cout<< "PATIENT ID : " << patient_id<<endl;
    cout<< "NOTES      : " << notes<<endl;
    cout<<"\n- - - - - - - - - - - - - - - - - -\n";
}

void print_all(const vector<record>&r) /// PRINTS ALL RECORDS
{
    cout<<"==============RECORDS====================\n"<<endl;
    for(int i=0; i<r.size(); i++)
    {        r[i].print();    }
    cout<<"=========================================\n"<<endl;
}

void search_record(const vector<record>&r)  /// SEARCHS RECORD BY ID
{
    string temp;
    int r_i;
start:
    cout<< "ENTER THE RECORD ID : ";
    cin >> temp;
    r_i=search_by_id(r,temp);
    if(r_i==-1)
    {
        cout<< "\n\n\t\t RECORD DOSENT EXIST!!";
        Sleep(1*1000);
        system("CLS");
        goto start;
    }
    else
    {
        r[r_i].print();
    }
}

void deleat_record(vector<record>&r)  /// DELEARS RECORD
{
    string temp;
start:
    cout << " ENTER THE RECORD ID YOU WANT TO DELEAT :";
    cin >> temp;
    int r_i=search_by_id(r,temp);
    if(r_i==-1)
    {
        cout<< "\n\n\t\t RECORD DOSENT EXIST!!";
        Sleep(1*1000);
        system("CLS");
        goto start;
    }
    else
    {        r.erase(r.begin()+r_i);    }
}

void manage_records(vector<record>&r,const vector<patient>&p)
{
    int choice;
sub_menu:
    cout<< " 1. PRINT ALL RECORDS \n"
        << " 2. ADD/UPDATE RECORD \n"
        << " 3. SEARCH RECORD \n"
        << " 4. DELEAT RECORD\n"
        << " 0. EXIT TO MENU \n"
        << " \n ENTER YOUR CHOICE : ";
    cin>> choice;
    system("CLS");
    switch(choice)
    {
    case 1:
    {        print_all(r);        goto sub_menu;    }
    case 2:
    {
        update_record(r,p);
        cout<<"\n\n\t\t RECORD UPDATED !!!";
        Sleep(1.5*1000);
        system("CLS");
        goto sub_menu;
    }
    case 3:
    {        search_record(r);        goto sub_menu;    }
    case 4:
    {
        deleat_record(r);
        cout<<"\n\n\t\t RECORD DELEATED !!!";
        Sleep(1.5*1000);
        system("CLS");
        goto sub_menu;
    }
    case 0:
    {       break;    }
    default:
    {
        cout << "\n\n\t\t INVAILD CHOICE !";
        Sleep(1.5*1000);
        system("CLS");
        goto sub_menu;
    }
    }
}
