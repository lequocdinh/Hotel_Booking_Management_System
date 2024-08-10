#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include "Hotel.h"

using namespace std;

int main() {
    int bigoption = 0;

    while (bigoption != 3) {
        system("cls");
        cout << "\n\t\t\t\t\t\tHOTEL MANAGEMENT SYSTEM" << endl;
        cout << "\n\t\t\t\t\tMenu options:" << endl;
        cout << "\n\t\t\t\t\t1. Hotel Rooms" << endl;
        cout << "\n\t\t\t\t\t2. Hotel Services" << endl;
        cout << "\n\t\t\t\t\t3. Exit" << endl;

        cout << "\n\t\t\t\t\tEnter option: ";
        cin >> bigoption;
        cout << endl;

        switch (bigoption) {
        case 1:
        {
            Hotel_rooms();
            break;
        }

        case 2:
        {
            Hotel_services();
            break;
        }

        case 3:
            cout << "\n\t\t\t\t\t\tThanks for using!" << endl;
            break;

        default:
            cout << "\n\t\t\t\t\tInvalid!" << endl;
            cout << "\n\t\t\t\t\tPress any key to continue!!" << endl;
            _getch();
            break;
        }
    }
    return 0;
}