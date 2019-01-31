#include "appointment.h"
#include <windows.h>

appointment::appointment(istream &in,vector<appointment>&a, vector<patient>&p, const  vector<doctor>&d, vector<slot>&s,const  vector<date_time>&t,const vector<diagnosis>&de, int lab_check )  /// creates a new appointment
{
start:
    cout<< "\n ENTER THE PATIENT ID THAT U WANT TO BOOK APPOINTMENT FOR : ";
    in>> patient_id;
    int index;
    index = search_by_id(p, patient_id);
    if(index>-1)
        doctor_id = p[index].getdoctor_id();
    else
    {
        cout << "\n INVALID PATIENT ID !!! "<<endl;
        goto start;
    }
    if(lab_check==0)
    {   print_s_by_d_id(s,d,t,doctor_id);  }
    string temp;
slotid:
    if(lab_check==0)
    {
        cout << "\n ENTER SLOT ID : ";    /// normal appointmenst
    }
    else
    {
        cout << "\n ENTER SLOT ID ( BETWEEN 30 AND 40 FOR LAB : ";
    }

    in>> temp;
    index=search_by_id(s,temp);
    if(lab_check==0)
    {
        if(index>-1 && s[index].getavalable() && s[index].getdoctor_id()==doctor_id )
        {
            slot_id=temp;
        }
        else
        {
            cout<< " INVALIED SLOT ID   | OR |  APPOINTMENT WITH WRONG DOCTOR | OR | SLOT ALRADY FILLED "<<endl;
            goto  slotid;
        }
    }
    else
    {
        if(index>-1 && s[index].getavalable() && !lab_date_check(a,s, t, index)  && (index>=30 && index<40) )
        {
            slot_id=temp;
        }
        else
        {
            cout<< " INVALIED SLOT ID   | OR |  APPOINTMENT WITH WRONG DOCTOR | OR | SLOT ALRADY FILLED "<<endl;
            goto  slotid;
        }
    }
    cout << "\n REASON : ";
    in.ignore();
    getline(in, reason);
    cout<<"\n PRESCRIBED MEDICATION : ";
    getline(cin, prescribed_medication);
    cout<<"\n"<<endl;
dia:
    printall(de);
    cout<< "\n ENTER THE DIAGNOSIS ID : ";
    cin>>temp;
    if(search_by_id(de,temp)!=-1)
    {
        diagnosis_id=temp;
        int p_i;
        p_i=search_by_id(p,patient_id);
        p[p_i].setde_id(diagnosis_id);
    }
    else
    {
        system("CLS");
        cout << "\n\n\t\t INVALID DIAGNOSIS ID!!";
        Sleep(1.5*1000);
        system("CLS");
        goto dia;
    }
    index=search_by_id(s,slot_id);
    s[index].setavalable(false);
    if(lab_check!=0)
    {
        lab=true;
    }
    stringstream ss;
    ss <<  ++app_id;
    id = ss.str();
    system("CLS");
    cout<< "\n\n \t\t APPOINTMENT CREATED !";
    cout<< "\n\n \t\t YOUR APPOINTMENT ID IS : " << id<< endl;
    Sleep(2*1000);
    system("CLS");
}

void appointment::update( vector<patient>&p, const vector<doctor>&d, vector<slot>&s,const vector<date_time>&t, const vector<diagnosis>&de) /// updates appointments : changes slot, reason , prescribed medication and diagnosis
{
start:
    int index, choice;
    cout<< "\n 1. RESCHEDULE APPOINTMENT (CHANGE SLOT) "
        << "\n 2. UPDATE REASON "
        << "\n 3. UPDATE PESCRIBED MEDICATION "
        << "\n 4. UPDATE DIAGNOSIS "
        << "\n 0. GO BACK "
        << "\n\n ENTER CHOICE : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
    {
        cout<< "  ALL AVALIBLE SLOTS ================="<<endl;

        print_s_by_d_id(s,d,t,doctor_id);
        cout<< "  ================== ================="<<endl;
        string temp;
slotid:
        cout << "\n ENTER SLOT ID : ";
        cin>> temp;
        index=search_by_id(s,temp);
        if(index>-1 && s[index].getavalable() && s[index].getdoctor_id()==doctor_id )
        {
            int n;
            n=search_by_id(s,slot_id);
            s[n].setavalable(true);
            slot_id=temp;
            n=search_by_id(s,slot_id);
            s[n].setavalable(false);
        }
        else if (index==-1, temp!="0")
        {
            cout<< " INVALIED SLOT ID   | OR |  APPOINTMENT WITH WRONG DOCTOR | OR | SLOT ALRADY FILLED "<<endl;
            goto  slotid;
        }
        system("CLS");
        cout<< "\n\n\t\t RESCHEDULE SUCESSFUL!!!";
        Sleep(1*1000);
        system("CLS");
        goto start;
    }
    case 2:
    {
        cout << "\n REASON : ";
        cin.ignore();
        getline(cin, reason);
        system("CLS");
        cout<< "\n\n\t\t REASON UPDATED!!!";
        Sleep(1*1000);
        system("CLS");
        goto start;
    }
    case 3:
    {
        cout<<"\n PRESCRIBED MEDICATION : ";
        cin.ignore();
        getline(cin, prescribed_medication);
        cout<<"\n"<<endl;
        system("CLS");
        cout<< "\n\n\t\t PRESCRIBED MEDICATION UPDATED!!!";
        Sleep(1*1000);
        system("CLS");
        goto start;
    }
    case 4:
    {
dia:
        string temp;
        printall(de);
        cout<< "\n ENTER THE DIAGNOSIS ID : ";
        cin>>temp;
        if(search_by_id(de,temp)!=-1)
        {
            diagnosis_id=temp;
            int p_i;
            p_i=search_by_id(p,patient_id);
            p[p_i].setde_id(diagnosis_id);
        }
        else
        {
            system("CLS");
            cout << "\n\n\t\t INVALID DIAGNOSIS ID!!";
            Sleep(1.5*1000);
            system("CLS");
            goto dia;

        }
        goto start;
    }
    case 0:
    {
        system("CLS");
        break ;
    }
    default:
    {
        system("CLS");
        cout<< " \n\n\t\t INVALID CHOICE!!!";
    }
    }
}

void update_appointment(vector<patient>&p, vector<appointment>&a, const vector<doctor>&d, vector<slot>&s,const vector<date_time>&t,const vector<diagnosis>&de)  /// updates appointments : changes slot, reason , prescribed medication and diagnosis
{
    string temp;
start:
    cout << " ENTER APPOINTMENT ID : ";
    cin >> temp;
    int index= search_by_id(a,temp);
    if(index ==-1 && temp!="0")
    {
        goto start;
    }
    if(index !=-1 )
    {
        if(a[index].getlab())
        {
            cout<< "\n\n\t\t LABS CANT BE UPDATED !!";
            Sleep(1*1000);
            system("CLS");

        }
        else
        { a[index].update(p,d,s,t,de);}
    }
}

void appointment::print( const vector<patient>&p, const vector<doctor>&d,const vector<slot>&s,const vector<date_time>&t,const vector<diagnosis>&de)const /// prints appointments ... member function.
{
    int index = search_by_id(s,slot_id);
    cout<<"_______________________________________________________________________ "<<endl;
    cout<<" APPOINTMENT ID : "<< id;
    cout<<"\n PATIENT NAME : "<< getname_by_id(p,patient_id)<< "\t PATIENT ID : " << patient_id;
    s[index].print(d,t);
    cout<<"\n REASON : " << reason;
    cout<<"\n PESCRIBED MEDICATION : " << prescribed_medication;
    index=search_by_id(de,diagnosis_id);
    cout<<"\n DIAGNOSIS ID : " << diagnosis_id << "\t DISEASE NAME : " << de[index].getdisease_name();
    cout<<"\n_______________________________________________________________________\n\n"<<endl;
}

void printall(const vector<appointment>&a, const vector<patient>&p, const vector<doctor>&d,const vector<slot>&s, const vector<date_time>&t,const vector<diagnosis>&de,int lab_check) /// prints all appointments
{
    cout<< " APPOINTMENTS =================================================\n"<<endl;
    for(int i =0 ; i<a.size(); i++)
    {
        if(lab_check==0)
        {
            if(!a[i].getlab())
                a[i].print(p,d,s,t,de);
        }
        else
        {
            if(a[i].getlab())
                a[i].print(p,d,s,t,de);
        }
    }
    cout<< "\n\n==========================================================="<<endl;
}
void printall_d_n(const vector<appointment>&a, const vector<patient>&p, const vector<doctor>&d,const vector<slot>&s, const vector<date_time>&t,const vector<diagnosis>&de) /// prints all appointments by doctor name
{
    string temp;
start:
    cout << " ENTER THE DOCTOR NAME : ";
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
        cout<< " APPOINTMENTS =================================================\n"<<endl;
        for(int i =0 ; i<a.size(); i++)
        {
            if(a[i].getdoctor_id()== getid_by_name(d,temp) )
            {
                if(!a[i].getlab())
                    a[i].print(p,d,s,t,de);
            }
        }
        cout<< "\n\n==========================================================="<<endl;
    }
}

void printall_p_n(const vector<appointment>&a, const vector<patient>&p, const vector<doctor>&d,const vector<slot>&s, const vector<date_time>&t,const vector<diagnosis>&de)  /// prints all appointments by patients name
{
    string temp;
start:
    cout << " ENTER THE PATIENT NAME : ";
    cin >> temp;
    if("-1"== getid_by_name(p,temp) && temp !="0")
    {
        system("CLS");
        cout << "\n\n\t\t     INAVALID PATIENT NAME!\n\t\t  ENTER  VALIED  PATIENT  NAME !!" ;
        Sleep(2*1000);
        system("CLS");
        goto start ;
    }
    if("-1"!= getid_by_name(p,temp) && temp !="0")
    {
        cout<< " APPOINTMENTS =================================================\n"<<endl;
        for(int i =0 ; i<a.size(); i++)
        {
            if(a[i].getpatient_id()== getid_by_name(p,temp) )
            {
                if(!a[i].getlab())
                    a[i].print(p,d,s,t,de);
            }
        }
        cout<< "\n\n==========================================================="<<endl;
    }
}

void printall_p_e(const vector<appointment>&a, const vector<patient>&p, const vector<doctor>&d,const vector<slot>&s, const vector<date_time>&t,const vector<diagnosis>&de)  /// prints all appointments by patient name
{
    string temp;
    int index;
start:
    cout << " ENTER THE PATIENT E-MAIL : ";
    cin >> temp;
    index=search_by_email(p,temp);
    if(-1== index && temp !="0")
    {
        system("CLS");
        cout << "\n\n\t\t     INAVALID PATIENT E-MAIL!\n\t\t  ENTER  VALIED  PATIENT  E-MAIL !!" ;
        Sleep(2*1000);
        system("CLS");
        goto start ;
    }
    if(-1!= index && temp !="0")
    {
        cout<< " APPOINTMENTS =================================================\n"<<endl;
        for(int i =0 ; i<a.size(); i++)
        {
            if(a[i].getpatient_id()== p[index].getid() )
            {
                if(!a[i].getlab())
                    a[i].print(p,d,s,t,de);
            }
        }
        cout<< "\n\n==========================================================="<<endl;
    }
}

void deleat_appointment(vector<appointment>&a, vector <slot>&s, int lab_check)  /// deletes appointments
{
    string temp;
    int i_a, i_s;
start:
    cout << " ENTER THE APPOINTMENT ID YOU WANT TO DELETE : ";
    cin >>temp;
    i_a=search_by_id(a,temp);
    if( (i_a!=-1) && ( (lab_check==0 && !a[i_a].getlab()) || (lab_check!=0 && a[i_a].getlab()) ) )
    {
        i_s=search_by_id(s,a[i_a].getslot_id()) ;
        s[i_s].setavalable(true);
        a.erase(a.begin()+i_a);
    }
    else if ( !( (i_a!=-1) && ( (lab_check==0 && !a[i_a].getlab()) || (lab_check!=0 && a[i_a].getlab()) ) ) && temp!="0")
    {
        cout << "INVALID APPOINTMENT ID !!!"<<endl;
        goto start;
    }
}

bool lab_date_check(vector<appointment>&a,vector<slot>&s,const  vector<date_time>&t,const int s_i  )  /// checks whether the a slot with same date is booked for lab or not
{
    const int  di1=search_by_id( t, s[s_i].getdate_id() );
    int di2, si2;
    for(int i = 0 ; i<a.size(); i++)
    {
        if(a[i].getlab())
        {
            si2=search_by_id(s,a[i].getslot_id());
            di2=search_by_id(t,s[si2].getdate_id());

            if( t[di1].day==t[di2].day &&
                    t[di1].month==t[di2].month &&
                    t[di1].year==t[di2].year )
            {
                return true;
            }
        }
    }
    return false;
}

void manage_appointments(vector<appointment>&a, vector<patient>&p, const vector<doctor>&d, const vector<date_time>&t, vector<slot>&s, const vector<diagnosis>&de) /// menu to manage the appointments and there functionalities
{
    int choice;
sub_menu:
    cout<< "\n 1. SCHEDULE A NEW APPOINTMENT"
        << "\n 2. SHOW ALL APPOINTMENTS "
        << "\n 3. SHOW ALL APPOINTMENTS OF A DOCTOR "
        << "\n 4. SHOW ALL APPOINTMENTS OF A PATIENT BY NAME"
        << "\n 5. SHOW ALL APPOINTMENTS OF A PATIENT BY EMAIL"
        << "\n 6. MODIFY/RESCHEDULE AN EXISTING APPOINTMENT "
        << "\n 7. REMOVE AN APPOINTMENT "
        << "\n 0. EXIT TO MAIN MENU "
        << "\n\n ENTER YOUR CHOICE : ";
    cin>> choice;
    system("CLS");
    switch(choice)
    {
    case 1:
    {
        a.push_back(appointment(cin,a, p,d, s, t,de));
        goto sub_menu;
    }
    case 2:
    {
        printall(a,p,d,s,t,de);
        goto sub_menu;
    }
    case 3:
    {
        printall_d_n(a,p,d,s,t,de);
        goto sub_menu;
    }
    case 4:
    {
        printall_p_n(a,p,d,s,t,de);
        goto sub_menu;
    }
    case 5:
    {
        printall_p_e(a,p,d,s,t,de);
        goto sub_menu;
    }
    case 6:
    {
        update_appointment(p,a,d,s,t,de);
        system("CLS");
        cout<< "\n\n \t\t UPDATED !";
        Sleep(1*1000);
        system("CLS");
        goto sub_menu;
    }
    case 7:
    {
        deleat_appointment(a,s);
        system("CLS");
        cout<< "\n\n \t\t DELEATED !";
        Sleep(1*1000);
        system("CLS");
        goto sub_menu;
    }
    case 0:
    {
        system("CLS");
        break;
    }
    default:
    {
        cout << " \n INVALID CHOICE ENTER YOUR CHOICE AGAIN !!!!"<<endl;
        Sleep(2*1000);
        system("CLS");
        goto sub_menu;
    }
    }
}

void manage_labs(vector<appointment>&a, vector<patient>&p, const vector<doctor>&d, const vector<date_time>&t, vector<slot>&s, const vector<diagnosis>&de )  /// manages
{
    int choice;
sub_menu:
    cout<< "\n 1. CREATE A LAB APPOINTMENT "
        << "\n 2. VIEW ALL LAB APPOINTMENTS "
        << "\n 3. DELEAT LAB APPOINTMENT "
        << "\n 0. EXIT TO MAIN MENY "
        << "\n\n ENTER YOUR CHOICE : ";
    cin >> choice;
    system("CLS");
    switch(choice)
    {
    case 1:
    {
        a.push_back(appointment(cin,a, p,d, s, t,de,1));
        goto sub_menu;
    }
    case 2:
    {
        printall(a,p,d,s,t,de,1);
        goto sub_menu;
    }
    case 3:
    {
        deleat_appointment(a,s,1);
        system("CLS");
        cout<< "\n\n \t\t DELEATED !";
        Sleep(1*1000);
        system("CLS");
        goto sub_menu;
    }
    case 0:
    {
        system("CLS");
        break;
    }
    default:
    {
        cout << " \n INVALID CHOICE ENTER YOUR CHOICE AGAIN !!!!"<<endl;
        Sleep(2*1000);
        system("CLS");
        goto sub_menu;
    }
    }
}
appointment::appointment()
{
}
