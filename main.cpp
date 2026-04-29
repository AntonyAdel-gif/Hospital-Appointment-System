#include <iostream>
#include <string>
using namespace std;

void displaymenu();

int main() {

    cout << "\n           " << endl;
    cout << "   " << endl;



    do {
        displaymenu();
        cin >> choice;
        while (choice < 1 || choice > 7) {
            cout << "Please make a choice in range of 1 through 7 " << endl;
            cin >> choice;
        }


        switch (choice) {
            case 1: {

                break;
            }


            case 2: {

                break;
            }


            case 3: {

                break;
            }


            case 4:{

                break;
            }

            case 5: {

                break;
            }

            case 6: {
                exit(0);
            }

        }

    } while (choice != 7);


    return 0;
}

void displaymenu(){
    cout << "\n***************************************************\n";
    cout << "1- Schedule an appointment \n";
    cout << "2- Display all appointments \n";
    cout << "3- Search for an appointment \n";
    cout << "4- Cancel an appointment \n";
    cout << "5- Display more urgent than \n";
    cout << "6- Display less urgent than \n";
    cout << "7- Exit The Program\n";
    cout << "****************************************************\n";
    cout << "ENTER YOUR CHOICE\n";
}