#include "doctor.h"

doctor::doctor()
{
}
void read(vector<doctor>&a, ifstream &in)  /// reads data from file to vector
{
    int num;
    in>>num;
    for(int i=0 ; i<num ; i++)
    {
        a.push_back(doctor(in));
    }
    in.close();
}

doctor::doctor(ifstream &in)/// constructor to create object by reading data from file
{
    in >>id >> username >> password >> name >> phone >> skill;
}

doctor::doctor(istream &in, vector<doctor>&d) /// constructor to create new doctor with user input
{
    string temp;
    int match;
start:
    cout<< "\n ID : ";
    in >>temp;
    match=search_by_id(d,temp);
    if(match==-1)
    {        id=temp;    }
    else
    {
        cout<< "ID ALREADY EXIST !" <<endl;
        cout<< "\n LIST OF ALRADY EXISTING ID'S -->"<<endl;
        for(int i = 0 ; i<d.size() ; i++)
        {
            cout<< d[i].getid()<<endl;
        }
        goto start;
    }
    cout<< " USERNAME :";
    in >> username;
    cout<< " PASSWORD :";
    in >> password;
    cout<<" NAME : ";
    in >> name ;
    cout<< " PHONE : ";
    in >> phone;
    cout<< " SKILL : ";
    in >> skill;
}

void doctor::print()const /// prints doctor member function
{
    cout<< " - - - - - - - - - - - - - - \n"<< endl;
    cout    << "\n ID : " << id<< " \n USERNAME : " << username<< "\n PASSWORD : " << password << "\n NAME : " << name
            << "\n PHONE : " << phone << "\n SKILL : " << skill << endl;
    cout<< "\n - - - - - - - - - - - - - - "<< endl;
}

void printall(const vector<doctor>&d  )  /// prints all doctors
{
    cout << "DOCTORS : ========================================\n\n";
    for(int i=0 ; i < d.size() ; i++ )
    {
        cout << d[i];
    }
    cout << "==================================================\n\n";
}

void print_by_name(const vector<doctor>&d)  /// prints doctor by his name
{
    string temp;
    int n;
start:
    cout<<"ENTER THE NAME OF THE DOCTOR U WANT TO SEARCH : ";
    cin>>temp;
    n=search_by_name(d,temp,0);
    if(n==-1 && temp !="0")
        goto start;
}

void update_doctor(vector<doctor>&d)  /// updates a doctor information
{
    int index ;
    string s_id;
    cout<< " ENTER THE ID OF THE DOCTOR YOU WANT TO UPDATE : ";
again:
    cin >> s_id;
    index= search_by_id(d, s_id);
    if(index==-1)
    {
        cout << "\n PATIENT NOT FOUND !  ENTER VALIED ID :\n";
        goto again;
    }
    else
    {
        cout << "\n current details ->";
        d[index].print();
        cout << "\n\n";
        d[index].update();
    }
}

void doctor::update() /// updates a doctor information
{
menu:
    cout<< "\n 1. UPDATE NAME\n"
        << " 2. UPDATE USERNAME \n"
        << " 3. UPDATE PASSWORD \n"
        << " 4. UPDATE PHONE \n"
        << " 5. UPDATE SKILL \n"
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
        print();
        goto menu;
    }
    case 2:
    {
        cout << "ENTER DOCTOR USERNAME : ";
        cin >> username;
        system("CLS");
        print();
        goto menu;
    }
    case 3:
    {
pass:
        cout << "ENTER OLD PASSWORD : ";
        string temp;
        cin >> temp;
        if(temp==password)
        {
            cout << "\n ENTER NEW PASSWORD : ";
            cin>>temp;
            password=temp;
        }
        else
        {
            cout<< " \n  INCORRECT PASSWORD \n ENTER THE CORRECT TO CHANGE THE PASSWORD.\n";
            Sleep(1*1000);
            system("CLS");
            goto pass;
        }
        system("CLS");
        print();
        goto menu;
    }
    case 4:
    {
        cout << "ENTER PHONE : ";
        cin >> phone;
        system("CLS");
        print();
        goto menu;
    }
    case 5:
    {
        cout << "ENTER SKILL : ";
        cin >> skill;
        system("CLS");
        print();
        goto menu;
    }
    case 0:
    {
        break;
    }
    default :
    {
        cout << " INVALID CHOISE . \n";
        goto menu;
    }
    }
}

void add_doctor(vector<doctor>&d)  /// adds new doctor
{
    cout << "\n Please enter the following details of the patient :\n";
    d.push_back(doctor(cin,d));
}

void deleat_doctor(vector<doctor>&d, vector<slot>&s,const vector<appointment>&a)  ///deletes a doctor
{
    string temp;
    int choice;
sub_menue:
    cout<< " \n 1. DELEAT BY ID  "
        << " \n 2. DELEAT MY NAME "
        << " \n ENTER YOUR CHOICE : ";
    cin >> choice;
    switch(choice)
    {
    case 1:
    {
        string temp;
        int index;
start1:
        cout<< " \n ENTER THE DOCTOR ID: ";
        cin >> temp;
        index= search_by_id(d,temp);
        if(index!=-1)
        {
            if( !d[index].check_appointment(a) )
            {
                d.erase(d.begin()+index);
                deleat_slots(s,temp);
                system("CLS");
                cout << " \n\n\t\t DOCTOR IS DELEATED !";
                Sleep(1*1000);
                system("CLS");
                break;
            }
            else
            {
                cout << "\n\n\t\t DOCTOR CANT BE DELATED !!\n\n\t\t HE IS HAVING APPOINTMENTS !\n\n\t\t";
                system("PAUSE");
                system("CLS");
                break;
            }
        }
        else
        {
            system("CLS");
            cout << "\n\n\t\t INVALID DOCTOR ID";
            Sleep(1.5*1000);
            system("CLS");
            goto start1;
        }
    }
    case 2:
    {
        string temp;
        int index;
start2:
        cout<< " \n ENTER DOCTOR NAME : ";
        cin >> temp;
        index= search_by_name(d,temp);
        if(index!=-1)
        {
            if( !d[index].check_appointment(a) )
            {
                temp=getid_by_name(d,temp);
                d.erase(d.begin()+index);
                system("CLS");
                //string t;
                cout << " \n\n\t\t DOCTOR IS DELEATED !";
                //temp=getid_by_name(d,temp);
                deleat_slots(s,temp);
                Sleep(1*1000);
                system("CLS");
                break;
            }
            else
            {
                cout << "\n\n\t\t DOCTOR CANT BE DELATED !!\n\n\t\t HE IS HAVING APPOINTMENTS !\n\n\n\t\t";
                system("PAUSE");
                system("CLS");
                break;
            }
        }
        else
        {
            system("CLS");
            cout << "\n\n\t\t INVALID DOCTOR NAME";
            Sleep(1.5*1000);
            system("CLS");
            goto start2;
        }
    }
    case 0:
    {   system("CLS");    break;    }
    default :
    {
        cout << " \n\n \t INVALID CHOICE !";
        Sleep(1*700);
        system("CLS");
        goto sub_menue;
    }
    }
}

bool doctor::check_appointment(const vector<appointment>&a)  /// checks if the doctor has appointments or not
{
    for(int i =0 ; i < a.size(); i++)
    {
        if(id==a[i].getdoctor_id() )
        {            return true;        }
    }
    return false;
}

void manage_doctors(vector<doctor>&d,vector<slot>&s,const vector<appointment>&a)  /// manages doctors
{
    int choice;
sub_menu:
    cout<< "\n 1. VIEW ALL DOCTORS"
        << "\n 2. SEARCH DOCTOR BY HIS NAME"
        << "\n 3. UPDATE DOCTOR INFO"
        << "\n 4. DELEAT DOCTOR"
        << "\n 0. EXIT "
        << "\n ENTER CHOICE : ";
    cin>>choice;
    system("CLS");
    switch(choice)
    {
    case 1:
    {
        cout<<d;
        goto sub_menu;
    }
    case 2:
    {
        print_by_name(d);
        goto sub_menu;
    }
    case 3 :
    {
        update_doctor(d);
        system("CLS");
        goto sub_menu;
    }
    case 4:
    {
        deleat_doctor(d,s,a);
        goto sub_menu;
    }
    case 0:
    {
        break;
    }
    default:
    {
        cout<< "\n\n\t\t    INVALID CHOICE !!!";
        Sleep(1*1000);
        system("CLS");
        goto sub_menu;
    }
    }
}

ostream& operator<<(ostream& os, const  doctor& d  ) /// overriding operator to print
{
    d.print();
    return os;
}
ostream& operator<<(ostream& os, const vector<doctor>&d  )/// overriding operator to print
{
    printall(d );
    return os;
}
