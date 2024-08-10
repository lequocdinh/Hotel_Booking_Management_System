#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include "Customer.h"
#include "Customer_room.h"
#include "Hotel.h"

using namespace std;

string setbaform(string A) {
    string res = "";
    stringstream ss(A);
    string token;
    while (ss >> token) {
        res += toupper(token[0]);
        for (int i = 1; i < token.length(); i++) {
            res += tolower(token[i]);
        }
        res += " ";
    }
    res.erase(res.length() - 1);
    A = res;

    return A;
}

void fileconstructor() {
    ofstream fileout;
    fileout.open("Hotel_Room.txt", ios::out | ios::app);
    fileout.close();
}

int countline() {
    int n = 0;
    string line;
    ifstream filein;
    filein.open("Hotel_Room.txt", ios::in);
    while (!filein.eof()) {
        getline(filein, line);
        n++;
    }
    n--;
    filein.close();
    return n;
}

void getinfor(int n, Customer_room* A) {
    n = countline();

    ifstream filein;
    filein.open("Hotel_Room.txt", ios::in);
    for (int i = 0; i < n; i++) {
        A[i].getfile(filein);
    }
    filein.close();
}
void checkroom(int n, Customer_room* A) {
    int emptyrooms = 0;
    int rooms = 100;
    int co1 = 0; int co2 = 0; int co3 = 0;
    emptyrooms = rooms - n;
    cout << " CHECKING FOR NUMBER OF ROOMS_AVAILABLE!" << endl;
    cout << " \n + Number of rooms are in using is: " << n << endl;
    cout << " + Number of rooms are available: " << emptyrooms << endl << endl;

    for (int i = 0; i < n; i++) {
        if ((1 <= A[i].getroom()) && (A[i].getroom() < 50)) {
            co1++;
        }
        else if ((50 <= A[i].getroom()) && (A[i].getroom() < 85)) {
            co2++;
        }
        else
            co3++;
    }
    cout << " + Ordinary Rooms: " << co1 << "\t\t + Empty Ordinary Rooms: " << 49 - co1 << endl;
    cout << " + Luxury Rooms: " << co2 << "\t\t + Empty Luxury Rooms: " << 34 - co2 << endl;
    cout << " + Royal Rooms: " << co3 << "\t\t + Empty Royal Rooms: " << 15 - co3 << endl << endl;
}

void roomreal(int found, int newroom, int n) {
    if ((found == n) && (newroom <= 100)) {
        cout << "\nRoom is not in using!" << endl;
        cout << endl << endl;
    }
    else if ((found == n) && (newroom > 100)) {
        cout << "\nRoom dosen't exist in the admin system!" << endl;
        cout << "Please, checking it again!" << endl;
        cout << endl << endl;
    }
    else {
        cout << endl << endl;
    }
}

void sortname(int n, Customer_room* A) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            string teni = A[i].cutname(2);
            string tenj = A[j].cutname(2);
            if (_stricmp(tenj.c_str(), teni.c_str()) < 0) {
                Customer_room B;
                B = A[i];
                A[i] = A[j];
                A[j] = B;
            }
            else if (_stricmp(tenj.c_str(), teni.c_str()) == 0) {
                string hoi = A[i].cutname(1);
                string hoj = A[j].cutname(1);
                if (_stricmp(hoj.c_str(), hoi.c_str()) < 0) {
                    Customer_room C;
                    C = A[i];
                    A[i] = A[j];
                    A[j] = C;
                } 
            }
        }
    }
}

void sortroom(int n, Customer_room* A) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i].getroom() > A[j].getroom()) {
                Customer_room D;
                D = A[i];
                A[i] = A[j];
                A[j] = D;
            }
        }
    }
}

void printtitle() {
    cout << left << setw(6) << "Rooms" << "\t" << left << setw(22) << "Name" << "\t" << left << setw(6) << "Sex"
        << "\t" << left << setw(15) << "ID" << "\t" << left << setw(15) << "Phone" << "\t" << left << setw(15) << "Birthdate"
        << "\t" << left << setw(6) << "Hours" << "\t" << left << setw(15) << " [RoomType]"
        << "\t" << left << setw(15) << "Cost" << endl;
}

int x[200];

void Hotel_rooms() {
    int options = 0;
    int i = 0;
    int n;
    Customer_room* A = new Customer_room[1000];
    fileconstructor();
    n = countline();
    getinfor(n, A);

    while (options != 7) {
        system("cls");
        cout << "\n\t\t\t\t\tHOTEL ROOM BOOKING MANAGEMENT SYSTEM" << endl;
        cout << "\n\t\t\t\tMENU OPTIONS:" << endl;
        cout << "\n\t\t\t\t1. Check-In" << endl;
        cout << "\n\t\t\t\t2. Checking number of Rooms available" << endl;
        cout << "\n\t\t\t\t3. Checking customers" << endl;
        cout << "\n\t\t\t\t4. Checking rooms" << endl;
        cout << "\n\t\t\t\t5. Modify infor of a customer" << endl;
        cout << "\n\t\t\t\t6. Delete rooms" << endl;
        cout << "\n\t\t\t\t7. Exit" << endl;

        cout << "\n\t\t\t\tENTER OPTIONS: ";
        cin >> options;
        cout << endl;

        switch (options) {
        case 1:
        {
            system("cls");
            n = countline();
            getinfor(n, A);
            for (int i = 0; i < n; i++) {
                x[i] = A[i].getroom();
            }

            n++;
            A[n].add1(n);
            A[n].setform1();
            A[n].setform2();
            A[n].save();

            _getch();
            break;
        }

        case 2:
        {
            system("cls");
            n = countline();
            getinfor(n, A);

            checkroom(n, A);

            printtitle();
            for (i = 0; i < n; i++) {
                A[i].print();
            }
            cout << endl << endl;

            int option;
            cout << "Types of ordering option!" << endl;
            cout << " + 1: Sort by customer's name!" << endl;
            cout << " + 2: Sort by rooms!" << endl;
            cout << " + 3: Just ignore Sort function!" << endl;
            cout << "\nEnter ordering option: ";
            cin >> option;
            cout << endl;

            switch (option) {
            case 1:
            {
                system("cls");
                sortname(n, A);
                cout << "SORT BY CUSTOMER'S NAME:" << endl;
                cout << endl;
                //ofstream fileout;
                //fileout.open("Hotel.txt", ios::out | ios::trunc);
                //fileout.close();
                printtitle();
                for (i = 0; i < n; i++) {
                    A[i].print();
                    //A[i].save();
                }
                cout << endl << endl;
                _getch();
                break;
            }

            case 2:
            {
                system("cls");
                sortroom(n, A);
                cout << "SORT BY ROOMS:" << endl;
                cout << endl;
                //ofstream fileout;
                //fileout.open("Hotel.txt", ios::out | ios::trunc);
                //fileout.close();
                printtitle();
                for (i = 0; i < n; i++) {
                    A[i].print();
                    //A[i].save();
                }
                cout << endl << endl;
                _getch();
                break;
            }

            case 3:
                break;
            }
            break;

        }

        case 3:
        {
            system("cls");
            int count = 0;
            int up = 0;
            int b = 0;
            long long newID;

            n = countline();
            getinfor(n, A);

            string namefind;
            cout << "\n\t\t\t\t\tCHECKING CUSTOMERS" << endl;
            cout << "\n+ Enter a name of Customer: ";
            cin.ignore();
            getline(cin, namefind);
            cout << endl;

            for (i = 0; i < n; i++) {
                if (setbaform(namefind) == A[i].getname()) {
                    printtitle();
                    A[i].print(); cout << endl;
                    up++;
                }
                else
                    count++;
            }

            if (up > 1) {
                cout << "\n+ Enter ID searching: "; cin >> newID;
                cout << endl;
                for (i = 0; i < n; i++) {
                    if (newID == A[i].getID()) {
                        printtitle();
                        A[i].print(); cout << endl;
                        b = 1;
                        cout << "\nPress any key to continue!!";
                    }
                }
                if (b != 1) {
                    cout << "\nID of the customer dosen't exist in the admin system!" << endl;
                    cout << "Please, checking it again!" << endl;
                    cout << "\nPress any key to continue!!";
                    cout << endl << endl;
                    _getch();
                    break;
                }
                else {
                    cout << endl << endl;
                    _getch();
                    break;
                }
            }

            if (count == n) {
                cout << "Name of the customer dosen't exist in the admin system!" << endl;
                cout << "Please, checking it again!" << endl;
                cout << "\nPress any key to continue!!";
                cout << endl << endl;
                _getch();
                break;
            }
            else {
                cout << endl << endl;
                _getch();
                break;
            }
        }

        case 4:
        {
            system("cls");
            n = countline();
            getinfor(n, A);

            int found = 0;
            int newroom = 0;
            cout << "\n+ Enter Room searching: "; cin >> newroom;
            cout << endl;
            for (i = 0; i < n; i++) {
                if (newroom == A[i].getroom()) {
                    printtitle();
                    A[i].print(); cout << endl;
                    cout << "\nPress any key to continue!!";
                }
                else
                    found++;
            }
            roomreal(found, newroom, n);
            _getch();
            break;
        }

        case 5:
        {
            system("cls");
            n = countline();
            getinfor(n, A);

            char a;
            int found = 0;
            int cancel = 0;
            int newroom = 0;
            cout << "\n+ Enter Room searching: "; cin >> newroom;
            for (i = 0; i < n; i++) {
                if (newroom == A[i].getroom()) {
                    cout << endl;
                    printtitle();
                    A[i].print(); cout << endl;
                    cout << "\nDo you want to modify the information of this customer!\n" << "Yes(y) or No(n): ";
                    cin >> a;
                    system("cls");
                    if (a == 'y') {
                        found = 1;
                        A[i].add2();
                        A[i].setform1();
                        A[i].setform2();
                        cout << "\nRoom " << newroom << " has been edited! " << endl << endl;
                    }
                    else
                        cancel = 1;
                }
            }

            if (cancel == 1) {
                break;
            }
            else if (found == 1) {
                ofstream fileout;
                fileout.open("Hotel_Room.txt", ios::out | ios::trunc);
                fileout.close();

                system("cls");
                printtitle();
                for (i = 0; i < n; i++) {
                        A[i].print();
                        A[i].save();
                }
                cout << endl << endl;
            }

            roomreal(found, newroom, 0);

            _getch();
            break;
        }

        case 6:
        {
            system("cls");
            n = countline();
            getinfor(n, A);

            char a;
            int found = 0;
            int cancel = 0;
            int newroom = 0;
            cout << "\n+ Enter Room searching: "; cin >> newroom;
            for (i = 0; i < n; i++) {
                if (newroom == A[i].getroom()) {
                    cout << endl;
                    printtitle();
                    A[i].print(); cout << endl;
                    cout << "\nDo you want to delete this customer!\n" << "Yes(y) or No(n): ";
                    cin >> a;
                    system("cls");
                    if (a == 'y') {
                        found = 1;
                        for (int j = i; j < n; j++) {
                            A[j] = A[j + 1];
                        }
                        cout << "\nRoom " << newroom << " has been deleted! " << endl << endl;
                    }
                    else
                        cancel = 1;
                }
            }

            if (cancel == 1) {
                break;
            }
            else if (found == 1) {
                n = n - found;
                ofstream fileout;
                fileout.open("Hotel_Room.txt", ios::out | ios::trunc);
                fileout.close();

                printtitle();
                for (i = 0; i < n; i++) {
                        A[i].print();
                        A[i].save();
                }
                cout << endl << endl;
            }

            roomreal(found, newroom, 0);

            _getch();
            break;
        }

        case 7:
            break;

        default:
            cout << "Invalid!" << endl;
            cout << "Enter to charater to continue!!" << endl;
            _getch();
            break;
        }
    }
}
