#include "slot.h"

slot::slot()
{
}
void read(vector<slot>&a, ifstream &in)  ///READS DATA FROM FILE TO VECTOR
{
    int num;
    in>>num;
    for(int i=0 ; i<num ; i++)
    {
        a.push_back(slot(in));
    }
    in.close();
}

slot::slot(ifstream &in) /// READS SLOTS FROM FILE
{
    int n;
    in>> id >> n;
    stringstream ss;
    ss << n ;
    date_id = ss.str();
    in >> doctor_id;
    string s ;
    in>>s;
    if(s[0]=='a')
        avalable=true;
    else
        avalable=false;
}

slot::slot(istream &in,const vector<doctor>&d, vector<date_time>&t) /// CREATES SLOTS WITH USER INPUT
{
    t.push_back(date_time(cin));
    stringstream ss;
    ss<<t.size();
    t[t.size()-1].setid(ss.str());
    date_id=t[t.size()-1].getid();
    string temp;
    int index;
start:
    cout<< "\n ENTER DOCTOR ID : ";
    cin>> temp;
    index=search_by_id(d,temp);
    if(index==-1)
    {
        cout << "\n INVALID DOCTOR ID !!! ";
        Sleep(1*1500);
        goto start;
    }
    else
    {        doctor_id=temp;    }
    ss.str("");
    ss.clear();
    ss <<  ++start_slot_id;
    id = ss.str();
    avalable=true;
}

void slot::update(const vector<doctor>&d,  vector<date_time>&t) /// updates slots
{
    int index ;
    index= search_by_id(t,date_id);
    t.push_back(date_time(cin,1));
    date_id=t[t.size()-1].getid();
}

void update_slots(vector<slot>&s, const vector <doctor>&d,  vector<date_time>&t  ) /// updates slots
{
    string temp;
    int index;
start:
    cout << " ENTER THE SLOT ID U WANT TO UPDATE : ";
    cin >> temp;
    index= search_by_id(s,temp);
    if(index!=-1)
    {        s[index].update(d,t);    }
    else
    {
        system("CLS");
        cout << "\n\n \t\t SLOT NOT FOUND! \n\n\t   INVALID SLOT ID !!";
        Sleep(1.5*1000);
        goto start;
    }
    system("CLS");
    cout<< " \n\n \t\t  SLOT UPDATED SUCESSFULLY !!!";
    Sleep(1*1000);
    system("CLS");
}

void deleat_slot(vector<slot>&s,int index=-1) /// deletes slots
{
    string temp;
    if(index==-1)
    {
start:
        cout << "\n ENTER SLOT ID U WANT TO DELEAT :";
        cin >> temp;
        index=search_by_id(s,temp);
    }
    if(index==-1)
    {
        cout<< " \n\n\t\t  INVALID SLOT ID ";
        Sleep(1*1000);
        goto start;
    }
    else
    {
        if(s[index].getavalable())
        {
            s.erase(s.begin()+index);
        }
        else
        {
            cout<< " \n SLOT IS BOOKED IT CANT BE DELEATED !!";
            Sleep(1*1000);
            system("CLS");
            goto start;
        }
    }
}

void deleat_slots(vector<slot>&s,const string& d_id) /// deletes slots
{
    for(int i=s.size()-1; i>=0; i--)
    {
        if(s[i].getdoctor_id()==d_id)
        {
            s.erase(s.begin()+i);
        }
    }
}
void slot::print(const vector<doctor>&d,const vector<date_time>&t )const /// prints slots
{
    int t_i=0, d_i=0;
    d_i=search_by_id(d,doctor_id);
    cout << " \n- - - - - - - - - - - -";
    cout<< "\n SLOT ID : " <<  id <<"\n" ;
    cout << "\n DATE ID : " << date_id;
    print_date_by_id(t, date_id);
    if(d_i!=-1)
    {        cout << "\n DOCTOR NAME : " << d[d_i].getname() << "\t DOCTOR ID : " << doctor_id ;    }
    cout<< " \n AVAILABILITY : " << avalable ;
    cout << "\n- - - - - - - - - - - - ";
}

void printall(const vector<slot>&s,const vector<doctor>&d,const vector<date_time>&t ) /// prints all slots
{
    for(int i=0; i<s.size(); i++)
    {        cout<<"\n";        s[i].print(d,t);    }
}
void printall_a(const vector<slot>&s,const vector<doctor>&d,const vector<date_time>&t ) /// prints all available slots
{
    for(int i=0; i<s.size(); i++)
    {
        if(s[i].getavalable())
        {            cout<<"\n";            s[i].print(d,t);        }
    }
}
void printall_u(const vector<slot>&s,const vector<doctor>&d,const vector<date_time>&t )/// prints all unavailable slots
{
    for(int i=0; i<s.size(); i++)
    {
        if(!s[i].getavalable())
        {            cout<<"\n";            s[i].print(d,t);        }
    }
}

void a_slots_d_n(const vector<slot>&s,const vector<doctor>&d,const vector<date_time>&t ) /// prints all available slots by doctor name
{
    string temp;
start:
    cout << " ENTER THE DOCTOR NAME ; ";
    cin >> temp;
    if("-1"== getid_by_name(d,temp) && temp !="0")
    {
        system("CLS");
        cout << "\n\n\t\t     INAVALID DOCTOR NAME!\n\t\t  ENTER  VALIED  DOCTOR  NAME !!" ;
        Sleep(2*1000);
        system("CLS");
        goto start ;
    }
    if("-1"!= getid_by_name(d,temp) && temp !="0")
    {
        for(int i=0; i<s.size(); i++)
        {
            if(s[i].getdoctor_id()== getid_by_name(d,temp) && s[i].getavalable())
            {                cout<<"\n";                s[i].print(d,t);            }
        }
    }
}

void a_slots_t_r(const vector<slot>&s,const vector<doctor>&d,const vector<date_time>&t )  /// prints all available slots within a time range
{
    date_time t1(cin);
    cout << "\n"<<endl;
    date_time t2(cin);
    int t_i;
    for(int i=0; i<s.size(); i++)
    {
        t_i= search_by_id(t,s[i].getdate_id());
        if(s[i].getavalable() && (t1<t[t_i] ||t1==t[t_i]) && (t2 > t[t_i]|| t2 == t[t_i]) )
        {            cout<<"\n";            s[i].print(d,t);        }
    }
}

void print_s_by_d_id(const vector<slot>&s,const vector<doctor>&d,const vector<date_time>&t, const string &d_id ) /// prints all available slots by doctor id
{
    for(int i=0; i<s.size(); i++)
    {
        if(s[i].getdoctor_id()==d_id && s[i].getavalable())
            s[i].print(d,t);
    }
}

void manage_slots(vector<slot>&s,const vector<doctor>&d,vector<date_time>&t) /// manage slots
{
    int choice;
sub_menu:
    cout<< "\n 1. VIEW ALL SLOTS "
        << "\n 2. VIEW ALL AVAILABLE SLOTS "
        << "\n 3. VIEW ALL UNAVAILABLE SLOTS "
        << "\n 4. SEARCH AVAILABLE SLOTS BY DOCTOR NAME"
        << "\n 5. SEARCH SLOTS BETWEEN TIME RANGE "
        << "\n 6. UPDATE SLOT "
        << "\n 7. DELEAT SLOT "
        << "\n 8. ADD NEW SLOT"
        << "\n 0. EXIT TO MAIN MENU "
        << "\n\n ENTER CHOICE : ";
    cin>>choice;
    system("CLS");
    switch(choice)
    {
    case 1:
    {
        printall(s,d,t);
        goto sub_menu;

    }
    case 2:
    {
        printall_a(s,d,t);
        goto sub_menu;
    }
    case 3:
    {
        printall_u(s,d,t);
        goto sub_menu;
    }
    case 4:
    {
        a_slots_d_n(s,d,t);
        goto sub_menu;
    }
    case 5:
    {
        a_slots_t_r(s,d,t);
        goto sub_menu;
    }
    case 6:
    {
        update_slots(s,d,t);
        goto sub_menu;
    }
    case 7:
    {
        deleat_slot(s);
        goto sub_menu;
    }
    case 8:
    {
        s.push_back(slot(cin, d, t ));
        goto sub_menu;
    }
    case 0:
    {        break;    }
    default:
    {
        cout<<"\n\n\t\t INVALID CHOICE !";
        Sleep(1*1000);
        goto sub_menu;
    }
    }
}
