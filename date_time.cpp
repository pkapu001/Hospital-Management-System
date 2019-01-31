#include "date_time.h"
#include <iomanip>

void read(vector<date_time>&a, ifstream &in)  /// read data from file to the vector
{
    int num;
    in>>num;
    for(int i=0 ; i<num ; i++)
    {
        a.push_back(date_time(in));
    }
    in.close();
}
date_time::date_time()
{
}
date_time::date_time(istream &in) /// creates a new date and time
{
    cout << " DAY : ";
    cin>>day;
    cout<< " MONTH : ";
    cin>> month ;
    cout<< " YEAR : ";
    cin>> year ;
    cout << " HOURS : ";
    cin>> hours ;
    cout<< " MINUTES : ";
    cin>> minutes;
    cout<< " AM or PM < a or p> : ";
    cin>>am_pm;
}

date_time::date_time(istream &in, int i)  /// creates a new date and time with an id
{
    cout << " DAY : ";
    cin>>day;
    cout<< " MONTH : ";
    cin>> month ;
    cout<< " YEAR : ";
    cin>> year ;
    cout << " HOURS : ";
    cin>> hours ;
    cout<< " MINUTES : ";
    cin>> minutes;
    cout<< " AM or PM < a or p> : ";
    cin>>am_pm;
    stringstream ss;
    ss <<  ++start_date_id;
    id = ss.str();
}

date_time::date_time(ifstream &in)  /// reads date and time from file to vector member function
{
    int n;
    in>> n ;
    stringstream ss;
    ss << n ;
    id = ss.str();
    in>>day >> month >> year >> hours >> minutes >>am_pm;
}

void date_time::print()const  /// prints date and time member function
{
    cout<< "\n DAY | MONTH | YEAR |\n "
        <<left << setw(4) <<  day << "|  "<< setw(5)<<month<< "| " << setw(5) << year;
    cout<< "\n" << right<< setw(7) <<  hours <<":" << minutes << " " << am_pm << "m" <<endl;
}

void print_date_by_id(const vector<date_time>&t, string s ="" )  /// prints date and time by its id
{
    int index;
    if(s=="")
    {
start:
        cout << "\n enter date id : ";
        cin>>s;
        index= search_by_id(t,s);
        if(index ==-1)
        {
            cout << " invalid id !\n";
            goto start;
        }
    }
    index= search_by_id(t,s);
    if(index !=-1)
    {
        cout<<t[index];
    }
    else
    {
        cerr<< " date id not found \n";
    }
}
