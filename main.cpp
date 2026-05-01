#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"
using namespace std;

void displaymenu();
void read_from_file(BST& instance, string filename);

int main() {
    BST hospital_appointment;
    int choice;

    cout << "\n|                FCAI Hospital Appointment System                     |" << endl;
    cout << "|    Hospital Appointment System to manage patients appointments      |" << endl;



    do {
        displaymenu();
        cin >> choice;
        while (choice < 1 || choice > 8) {
            cout << "Please make a choice in range of 1 through 8 " << endl;
            cin >> choice;
        }


        switch (choice) {
            case 1: {
                cout << "Please Enter your file name: " << endl;
                cout << "\n!!!!!!! BE CAREFULL !!!!!!!" << endl;
                cout << "1- YOUR FILE NEED TO HAVE .txt EXTENTION           " << endl;
                cout << "2- YOU NEED TO ENTER THE PRECISE NAME OF THE FILE IT IS CASE SENSITIVE" << endl;
                cout << "3- YOUR FILE NEED TO BE SAVED IN THE SAME DIRECTORY OF THE .EXE FILE    " << endl;
                string file_text_name;
                cin.ignore(10, '\n');
                getline(cin, file_text_name);
                read_from_file(hospital_appointment, file_text_name);
                break;
            }
            case 2: {
                cout <<"Please Enter your priority level: "<< endl;
                int priority;
                cin >> priority;

                cout <<"Please Enter your full name: "<< endl;
                string patient_name;
                cin.ignore();
                getline(cin, patient_name);

                cout <<"Please enter your department: "<< endl;
                string department;
                cin.ignore();
                getline(cin, department);

                hospital_appointment.insert_appoint(priority ,patient_name,department);

                break;
            }


            case 3: {
                hospital_appointment.display_all();
                break;
            }


            case 4: {
                cout << "Please enter the patient priority level for search " << endl;
                int priority;
                cin >> priority;
                hospital_appointment.search_all(priority);
                break;
            }


            case 5:{
                cout << "Please enter the patient priority level for canceling his/her appointment " << endl;
                int priority;
                cin >> priority;
                hospital_appointment.cancel_appoint(priority);
                break;
            }

            case 6: {
                cout << "Please enter the priority level " << endl;
                int priority;
                cin >> priority;
                hospital_appointment.display_more_urgent(priority);
                break;
            }

            case 7: {
                cout << "Please enter the priority level " << endl;
                int priority;
                cin >> priority;
                hospital_appointment.display_less_urgent(priority);
                break;
            }

            case 8: {
                exit(0);
            }

        }

    } while (choice != 8);


    return 0;
}

void displaymenu(){
    cout << "\n***************************************************\n";
    cout << "1- insert appointment data through file.txt \n";
    cout << "2- Schedule an appointment \n";
    cout << "3- Display all appointments \n";
    cout << "4- Search for an appointment \n";
    cout << "5- Cancel an appointment \n";
    cout << "6- Display appointment more urgent than a specific priority level \n";
    cout << "7- Display appointment less urgent than specific priority level \n";
    cout << "8- Exit The Program\n";
    cout << "****************************************************\n";
    cout << "ENTER YOUR CHOICE\n";
}

void read_from_file(BST& instance, string filename) {
    ifstream file_name(filename); // this for making the user dynamically chooses the file name

    string name, department;
    int priority;
    if (file_name) {
        int count;
        file_name >> count;
        file_name.ignore(10, '\n');

        for (int i = 0; i < count; i++) {

            getline(file_name, name);

            file_name >> priority;
            file_name.ignore(10, '\n');

            getline(file_name, department);
            instance.insert_appoint(priority, name, department);
        }
        file_name.close();
        cout << "appointments loaded successfully" << endl;
    }
    else {
        cout << "Error cant open file" << endl;
    }

}