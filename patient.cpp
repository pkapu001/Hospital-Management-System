#include "patient.h"

patient::patient()
{
    gender = ' ';
}

void read(vector<patient>&a, ifstream &in) /// reads data from file to vector
{
    int num;
    in>>num;
    for(int i=0 ; i<num ; i++)
    {
        a.push_back(patient(in));
    }
    in.close();
}

patient::patient(ifstream &in)  /// reads data from file to vector ... construcor
{    in>>id >> doctor_id >> record_id >> name >> phone >> gender >> email >> blood_type  ;  }

bool check_r_id(string s, const vector<patient>&p)  ///checks record it already exists
{
    for(int i =0 ; i< p.size() ; i++)
    {
        if(s==p[i].getrecord_id())
        {
            return true;
        }
    }
    return false;
}

patient::patient(istream &in,vector<patient>&p, const vector<doctor>&d) /// creates new patient with use input
{
    string temp;
    cout<< " ID : ";
    in>>temp;
    int match=search_by_id(p,temp);
    if(match==-1)
    {        id=temp;    }
    else
    {
        cout<< "list of already existing id's ->"<<endl;
        for(int i = 0 ; i<p.size() ; i++)
        {
            cout<< p[i].getid()<<endl;
        }
        do
        {
            cout<< "id already exist" <<endl;
            cout<< " enter new id :";
            cin>>temp;
            match=search_by_id(p,temp);
        }
        while(match!=-1);
        id=temp;
    }
    cout << " DOCTOR ID : ";
    in>> temp ;
    match=search_by_id(d,temp);
    if(match!=-1)
    {        doctor_id=temp;    }
    else
    {
        cout<< "list of doctors id's ->"<<endl;
        for(int i = 0 ; i<d.size() ; i++)
        {
            cout<< d[i].getid()<<endl;
        }
        do
        {
            cout<< "doctor with given id not found" <<endl;
            cout<< " enter valid doctor id :";
            cin>>temp;
            match=search_by_id(d,temp);
        }
        while(match==-1);
        doctor_id=temp;
    }
startr:
    cout << " RECORD ID : ";
    in>> temp;
    if (!check_r_id(temp,p))
    {        record_id=temp ;    }
    else
    {
        cout << "\n RECORD ID ALRADY EXISTS !!\n"<<endl;
        goto startr;
    }
    cout << " NAME : ";
    in>> name ;
    cout << " GENDER : ";
    in>> gender;
    cout << " PHONE : ";
    in>> phone ;
    cout << " E-MAIL : ";
    in>> email ;
    cout << " BLOOD TYPE : ";
    in>> blood_type  ;
}

void patient::update(const vector<patient>&p, const vector<doctor>&d,const vector<diagnosis>&de)  /// updates patients info
{
menu:
    cout << "\n 1. UPDATE NAME\n"
         << " 2. UPDATE DOCTOR ID \n"
         << " 3. UPDATE PHONE \n"
         << " 4. UPDATE GENDER \n"
         << " 5. UPDATE E-MAIL \n"
         << " 6. UPDATE BLOOD TYPE \n"
         << " 0. EXIT OUT OF MENU \n";
    int n;
    cin>> n;
    switch(n)
    {
    case 1:
    {
        cout << "ENTER NAME : ";
        cin >> name;
        system("CLS");
        print(d,de);
        goto menu;
    }
    case 2:
    {
        string temp;
        cout << "ENTER DOCTOR ID : ";
        cin >> temp;
        int match=search_by_id(d,temp);
        if(match!=-1 || doctor_id==temp)
        {            id=temp;        }
        else
        {
            cout<< "list of doctors id's ->"<<endl;
            for(int i = 0 ; i<d.size() ; i++)
            {                cout<< d[i].getid()<<endl;            }
            do
            {
                cout<< "doctor with given id not found" <<endl;
                cout<< " enter valid doctor id :";
                cin>>temp;
                match=search_by_id(d,temp);
            }
            while(match==-1&& doctor_id!=temp);
            doctor_id=temp;
        }
        system("CLS");
        print(d,de);
        goto menu;
    }
    case 3:
    {
        cout << "ENTER PHONE : ";
        cin >> phone;
        system("CLS");
        print(d,de);
        goto menu;
    }
    case 4:
    {
        cout << "ENTER GENDER : ";
        cin >> gender;
        system("CLS");
        print(d,de);
        goto menu;
    }
    case 5:
    {
        cout << "ENTER E-MAIL : ";
        cin >> email;
        system("CLS");
        print(d,de);
        goto menu;
    }
    case 6:
    {
        cout << "ENTER BLOOD TYPE : ";
        cin >> blood_type;
        system("CLS");
        print(d,de);
        goto menu;
    }
    case 0:
    {        break;    }
    default :
    {
        cout << " INVALID CHOISE . \n";
        goto menu;
    }
    }
}

void addpatient(vector<patient> &p, const vector<doctor>&d) /// adds new patient
{
    cout << "\n Please enter the following details of the patient :\n";
    p.push_back(patient(cin,p,d));
}

void patient::print(const vector<diagnosis>&de)const /// prints patient
{
    cout << "- - - - - - - - - - - - - - -"<<endl;
    cout << "\n\n ID : " << id  << "\n DOCTOR ID : " << doctor_id << "\tDOCTOR ASSOISIATED WITH PATIENT DELEATED !"   << "\n RECORD ID : "  << record_id <<endl;
    cout << " NAME : " << name << "\n GENDER : " << gender << "\n PHONE : " << phone << endl ;
    cout << " E-MAIL : " << email << "\n BLOOD TYPE : " << blood_type<< endl;
    int de_i=search_by_id(de,diagnosis_id);
    de[de_i].print();
    cout << "- - - - - - - - - - - - - - -"<<endl;
}

void patient::print()const /// prints patient
{
    cout << "- - - - - - - - - - - - - - -"<<endl;
    cout << "\n\n ID : " << id  << "\n DOCTOR ID : " << doctor_id << "\tDOCTOR ASSOISIATED WITH PATIENT DELEATED !"   << "\n RECORD ID : "  << record_id <<endl;
    cout << " NAME : " << name << "\n GENDER : " << gender << "\n PHONE : " << phone << endl ;
    cout << " E-MAIL : " << email << "\n BLOOD TYPE : " << blood_type<< endl;
    cout << "- - - - - - - - - - - - - - -"<<endl;
}

void patient::print(const doctor&d,const vector<diagnosis>&de)const /// prints patient
{
    cout << "- - - - - - - - - - - - - - -"<<endl;
    cout << "\n\n ID : " << id  << "\n DOCTOR ID : " << doctor_id << "\t DOCTOR NAME : " << d.getname()  << "\n RECORD ID : "  << record_id <<endl;
    cout << " NAME : " << name << "\n GENDER : " << gender << "\n PHONE : " << phone << endl ;
    cout << " E-MAIL : " << email << "\n BLOOD TYPE : " << blood_type<< endl;
    int de_i=search_by_id(de,diagnosis_id);
    if(de_i!=-1)
        de[de_i].print();
}

void patient::print(const vector<doctor>&d,const vector<diagnosis>&de)const /// prints patient
{
    int index;
    index=search_by_id(d, doctor_id);
    if(index!=-1)
        print(d[index],de) ;
    else
    {
        print();
    }
}

void printall(const vector<patient>&p, const vector<doctor>&d,const vector<diagnosis>&de )/// prints all patients
{
    int index;
    cout << "PATIENTS : ========================================\n\n";
    for(int i=0 ; i < p.size() ; i++ )
    {        p[i].print(d,de) ;    }
    cout << "==================================================\n\n";
}

void update_patient( vector<patient>&p, const vector<doctor>&d,const vector<diagnosis>&de)  ///updates a patient
{
    int index ;
    string s_id;
start:
    int choice;
    cout    << "\n 1. SEARCH BY ID. "
            << "\n 2. SEARCH BY NAME. "
            << "\n 0. TO EXIT."
            << "\n\n ENTER CHOICE : ";
    cin >> choice;
    switch(choice)
    {
    case 1:
    {
        cout<< " ENTER THE ID OF THE PATENT YOU WANT TO UPDATE : ";
again1:
        cin >> s_id;
        index= search_by_id(p, s_id);
        if(index==-1)
        {
            cout << "\n PATIENT NOT FOUND !  ENTER VALIED ID :";
            goto again1;
        }
        else
        {
            cout << "\n current details ->";
            p[index].print(d,de) ;
            cout << "\n\n";
            p[index].update(p,d,de);
        }
        break;
    }
    case 2:
    {
        cout<< " ENTER THE NAME OF THE PATENT YOU WANT TO UPDATE : ";
again2:
        cin >> s_id;
        index= search_by_name(p, s_id);
        if(index==-1)
        {
            cout << "\n PATIENT NOT FOUND !  ENTER VALIED NAME :";
            goto again2;
        }
        else
        {
            cout << "\n current details ->";
            p[index].print(d,de) ;
            cout << "\n\n";
            p[index].update(p,d,de);
        }
        break;
    }
    case 0:
    {
        break;
    }
    default:
    {
        cout <<"\n INVALIED CHOICE ! \n ENTER A VALID CHOICE :" <<endl;
        goto start;
    }
    }
}

void deleat(vector<patient>&p )  /// deletes patient
{
    int index ;
    string s_id;
    cout<< " enter the id of the patent u want to delete  : ";
again:
    cin >> s_id;
    index= search_by_id(p, s_id);
    if(index==-1)
    {
        cout << "\n PATIENT NOT FOUND !  ENTER VALIED ID :\n";
        goto again;
    }
    else
    {        p.erase(p.begin()+index);    }
}

void print_by_name(const vector<patient>&p, const vector<doctor>&d,const vector<diagnosis>&de)  ///prints patients by his name
{
    string temp;
    int n;
start:
    cout<<"ENTER THE NAME OF THE PATENT U WANT TO SEARCH : ";
    cin>>temp;
    system("CLS");
    n=search_by_name(p,d,de,temp,0);
    if(n==-1 && temp !="0")
        goto start;
}

void print_by_id(const vector<patient>&p, const vector<doctor>&d,const vector<diagnosis>&de)  /// prints patients by his id
{
    string temp;
    int n;
start:
    cout<<"ENTER THE ID OF THE PATENT U WANT TO SEARCH : ";
    cin>>temp;
    n=search_by_id(p, temp);
    if(n==-1 && temp !="0")
    {        goto start;    }
    else
    {
        system("CLS");
        p[n].print(d,de);
    }
}

void print_by_email(const vector<patient>&p,const vector<doctor>&d,const vector<diagnosis>&de)  /// prints patients by his  user-name
{
    string temp;
    int n;
start:
    cout << " ENTER THE EMAIL OF THE PATENT YOU WANT TO SEARCH : " ;
    cin >> temp;
    system("CLS");
    n=search_by_email(p,d,de,temp,0);
    if(n==-1 && temp !="0")
        goto start;
}

void print_p_by_d_n(const vector<patient>&p, const vector<doctor>&d,const vector<diagnosis>&de)  ///======prints patients by doctors name
{
    string d_name, d_id;
start:
    cout << "\n Enter the doctor name you want to search : " ;
    cin >> d_name;
    d_id=getid_by_name(d,d_name);
    if(d_id!="-1")
    {
        system("CLS");
        search_by_d_id(p,d,de,d_id,0);
    }
    else
    {        goto start;    }
}

void patients_t_r(const vector<patient>&p, const vector<doctor>&d, const vector<appointment>&a,const vector<slot>&s, const vector<date_time>&t,const vector<diagnosis>&de ) /// prints patients who are having appointment between a time range
{
    date_time t1(cin);
    cout << "\n"<<endl;
    date_time t2(cin);
    int t_i,s_i,p_i;
    for(int i=0; i<a.size(); i++)
    {
        s_i = search_by_id(s,a[i].getslot_id());
        t_i = search_by_id(t,s[s_i].getdate_id());
        if( (t1<t[t_i] ||t1==t[t_i]) && (t2 > t[t_i]|| t2 == t[t_i]) )
        {
            p_i=search_by_id(p,a[i].getpatient_id());
            cout<<"\n";
            p[p_i].print(d,de) ;
        }
    }
}

void manage_patents(vector<patient>&p, const vector<doctor>&d,vector<appointment>&a, vector<slot>&s, vector<date_time>&t,const vector<diagnosis>&de) /// manages patients
{
    int choice;
menu:
    cout<< "\n 1. PRINT ALL PATIENTS"
        << "\n 2. PRINT PATIENTS ASSIGNED TO A DOCTOR "
        << "\n 3. SEARCH PATIENT BY NAME "
        << "\n 4. SEARCH PATIENT BY E-MAIL "
        << "\n 5. SEARCH PATIENT BY ID "
        << "\n 6. UPDATE PATIENT "
        << "\n 7. ADD NEW PATIENT "
        << "\n 8. DELEAT A PATIENT "
        << "\n 9. VIEW PATIENTS WHO ARE HAVING APPOINTMENT BETWEEN THE TIME RANGE "
        << "\n 0. EXIT TO MAIN MENU "
        << "\n ENTER YOUR CHOICE : ";
    cin>>choice;
    system("CLS");
    switch (choice)
    {
    case 1:
    {
        printall(p, d,de);
        goto menu;
    }
    case 2:
    {
        print_p_by_d_n(p,d,de);
        goto menu;
    }
    case 3:
    {
        print_by_name(p,d,de);
        goto menu;
    }
    case 4:
    {
        print_by_email(p,d,de);
        goto menu;
    }
    case 5:
    {
        print_by_id(p,d,de);
        goto menu;
    }
    case 6:
    {
        update_patient(p,d,de);
        system("CLS") ;
        goto menu;
    }
    case 7:
    {
        addpatient(p,d);
        system("CLS") ;
        goto menu;
    }
    case 8:
    {
        deleat(p);
        system("CLS") ;
        goto menu;
    }
    case 9:
    {
        patients_t_r(p,d, a,s, t,de );
        goto menu;
    }
    case 0:
    {
        break;
    }
    default:
    {
        cout << "  INVALIED CHOICE ! ENTER VALID CHOICE.\n"<<endl;
        goto menu;
    }
    }
}
