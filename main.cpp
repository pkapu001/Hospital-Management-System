#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include "appointment.h"
#include "date_time.h"
#include "diagnosis.h"
#include "doctor.h"
#include "patient.h"
#include "record.h"
#include "slot.h"

using namespace std;
/// using static variables to id's
int appointment::app_id=0;
int slot::start_slot_id = 40;
int date_time::start_date_id=10;
int record::start_r_id=0;

int main()
{
    vector<patient>patients;
    vector<doctor>doctors;
    vector<slot>slots;
    vector<date_time>time;
    vector<appointment>appointments;
    vector<record>records;
    vector<diagnosis>diseases;
    ifstream in ;
    in.open("Patients.txt");
    read(patients, in);
    in.open("Doctors.txt");
    read(doctors, in);
    in.open("Slots.txt");
    read(slots, in);
    in.open("Diagnosis.txt");
    read(diseases, in);
    in.open("Date_Time.txt");
    read(time,in);

    int choice;
start:
    cout<< "\n\n\t\t WELCOME TO H.M.S\n\n "
        << "\n 1. MANAGE APPOINTMENTS"
        << "\n 2. MANAGE SLOTS"
        << "\n 3. MANAGE DOCTORS"
        << "\n 4. MANAGE PATIENTS"
        << "\n 5. MANAGE PATIENT'S RECORDS "
        << "\n 6. MANAGE LABS "
        << "\n 0. QUIT."
        << "\n\n ENTER YOUR CHOICE : ";
    cin>>choice;
    system("CLS");
    switch(choice)
    {
    case 1:
    {
        manage_appointments(appointments,patients,doctors,time,slots,diseases);
        system("CLS");
        goto start;
    }
    case 2:
    {
        manage_slots(slots,doctors,time);
        system("CLS");
        goto start;
    }
    case 3:
    {
        manage_doctors( doctors,slots, appointments);
        system("CLS");
        goto start;
    }
    case 4:
    {
        manage_patents(patients, doctors,appointments,slots,time,diseases);
        system("CLS");
        goto start;
    }
    case 5:
    {
        manage_records(records,patients);
        system("CLS");
        goto start;
    }
    case 6:
    {
        manage_labs(appointments,patients,doctors,time,slots,diseases);
        system("CLS");
        goto start;
    }
    case 0:
    { cout<< "\n\n\t\tBYE BYE!\n\n\n";      break;    }
    default:
    {
        goto start;
    }
    }
    return 0;
}
