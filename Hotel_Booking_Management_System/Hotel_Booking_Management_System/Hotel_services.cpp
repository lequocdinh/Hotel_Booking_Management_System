#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include "Customer.h"
#include "Customer_services.h"
#include "Hotel.h"

using namespace std;

string setbaform1(string B) {
    string res = "";
    stringstream ss(B);
    string token;
    while (ss >> token) {
        res += toupper(token[0]);
        for (int i = 1; i < token.length(); i++) {
            res += tolower(token[i]);
        }
        res += " ";
    }
    res.erase(res.length() - 1);
    B = res;

    return B;
}

void fileconstructor1() {
    ofstream fileout;
    fileout.open("Hotel_Services.txt", ios::out | ios::app);
    fileout.close();
}

int countline1() {
    int n = 0;
    string line;
    ifstream filein;
    filein.open("Hotel_Services.txt", ios::in);
    while (!filein.eof()) {
        getline(filein, line);
        n++;
    }
    n--;
    filein.close();
    return n;
}

void getinfor1(int n, Customer_services* B) {
    n = countline1();

    ifstream filein;
    filein.open("Hotel_Services.txt", ios::in);
    for (int i = 0; i < n; i++) {
        B[i].getfile(filein);
    }
    filein.close();
}

void checkIDcoupon(int n, Customer_services* B) {
    cout << "\nChecking Services available!" << endl << endl;
    int co1 = 0; int co2 = 0; int co3 = 0; int co4 = 0;
    for (int i = 0; i < n; i++) {
        if (1001000 < B[i].getIDcoupon() && B[i].getIDcoupon() <= 1001400) {
            co1++;
        }
        else if (2002000 < B[i].getIDcoupon() && B[i].getIDcoupon() <= 2002300) {
            co2++;
        }
        else if (3003000 < B[i].getIDcoupon() && B[i].getIDcoupon() <= 3003600) {
            co3++;
        }
        else {
            co4++;
        }
    }
    cout << " + Swimming pool register: " << co1 << "\t\t\t + Empty for Swimming pool registration: " << 400 - co1 << endl;
    cout << " + Gym register: " << co2 << "\t\t\t\t + Empty for Gym registration: " << 300 - co2 << endl;
    cout << " + Buffet register: " << co3 << "\t\t\t\t + Empty for Buffet registration: " << 600 - co3 << endl;
    cout << " + Massage & Kara register: " << co4 << "\t\t\t + Empty for Massage & Kara registration: " << 500 - co3 << endl << endl;
}

void IDcouponreal(int found, long long newIDcoupon, int n) {
    int co1 = 0; int co2 = 0; int co3 = 0; int co4 = 0;
    if (found == n && 1001000 < newIDcoupon && newIDcoupon <= 1001400) {
        cout << "\nThis IDcoupon for [Swimming pool]-Service is not in using!" << endl;
        co1++;
    }
    else if (found == n && 2002000 < newIDcoupon && newIDcoupon <= 2002300) {
        cout << "\nThis IDcoupon for [Gym]-Service is not in using!" << endl;
        co2++;
    }
    else if (found == n && 3003000 < newIDcoupon && newIDcoupon <= 3003600) {
        cout << "\nThis IDcoupon for [Buffet]-Service is not in using!" << endl;
        co3++;
    }
    else if (found == n && 4004000 < newIDcoupon && newIDcoupon <= 4004500) {
        cout << "\nThis IDcoupon for [Massage & Kara]-Service is not in using!" << endl;
        co4++;
    }
    else if (found == n && co1 == 0 && co2 == 0 && co3 == 0 && co4 == 0) {
        cout << "\nIDcoupon dosen't exit in the admin system!" << endl;
        cout << "Please, checking it again!" << endl;
        cout << endl << endl;
    }
    else {
        cout << endl << endl;
    }
}

void sortname1(int n, Customer_services* B) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            string teni = B[i].cutname(2);
            string tenj = B[j].cutname(2);
            if (_stricmp(tenj.c_str(), teni.c_str()) < 0) {
                Customer_services E;
                E = B[i];
                B[i] = B[j];
                B[j] = E;
            }
            else if (_stricmp(tenj.c_str(), teni.c_str()) == 0) {
                string hoi = B[i].cutname(1);
                string hoj = B[j].cutname(1);
                if (_stricmp(hoj.c_str(), hoi.c_str()) < 0) {
                    Customer_services F;
                    F = B[i];
                    B[i] = B[j];
                    B[j] = F;
                }
            }
        }
    }
}

void sortIDcoupon(int n, Customer_services* B) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (B[i].getIDcoupon() > B[j].getIDcoupon()) {
                Customer_services k;
                k = B[i];
                B[i] = B[j];
                B[j] = k;
            }
        }
    }
}

void printtitle1() {
    cout << left << setw(10) << "IDcoupon" << "\t" << left << setw(22) << "Name" << "\t" << left << setw(6) << "Sex"
        << "\t" << left << setw(15) << "ID" << "\t" << left << setw(15) << "Phone" << "\t" << left << setw(15) << "Birthdate"
        << "\t" << left << setw(15) << "Services" << "\t" << left << setw(15) << "Cost" << endl;
}

long long y[600];

void Hotel_services() {
    int options = 0;
    int i = 0;
    int n;
    Customer_services* B = new Customer_services[1000];
    fileconstructor1();
    n = countline1();
    getinfor1(n, B);

    while (options != 7) {
        system("cls");
        cout << "\n\n\t\t\t\t\t\tHOTEL SERVICES MANAGEMENT SYSTEM" << endl;
        cout << "\n\t\t\t\t\tMENU OPTIONS:" << endl;
        cout << "\n\t\t\t\t\t1. Check-In using services" << endl;
        cout << "\n\t\t\t\t\t2. Checking number of IDcoupon available" << endl;
        cout << "\n\t\t\t\t\t3. Checking customers" << endl;
        cout << "\n\t\t\t\t\t4. Checking for IDcoupon" << endl;
        cout << "\n\t\t\t\t\t5. Modify infor of a customer" << endl;
        cout << "\n\t\t\t\t\t6. Delete IDcoupon of a customer" << endl;
        cout << "\n\t\t\t\t\t7. Exit" << endl;

        cout << "\n\t\t\t\t\tENTER OPTION: ";
        cin >> options;
        cout << endl;

        switch (options) {
        case 1:
        {
            system("cls");
            n = countline1();
            getinfor1(n, B);
            for (int i = 0; i < n; i++) {
                y[i] = B[i].getIDcoupon();
            }

            n++;
            B[n].add1(n);
            B[n].setform1();
            B[n].setform2();
            B[n].save();

            _getch();
            break;
        }

        case 2:
        {
            system("cls");

            n = countline1();
            getinfor1(n, B);

            checkIDcoupon(n, B);

            printtitle1();
            for (i = 0; i < n; i++) {
                B[i].print();
            }
            cout << endl << endl;
            int option;
            cout << "Types of ordering option!" << endl;
            cout << " + 1: Sort by customer's name!" << endl;
            cout << " + 2: Sort by IDcoupons!" << endl;
            cout << " + 3: Just ignore Sort function!" << endl;
            cout << "\nEnter ordering option: ";
            cin >> option;
            cout << endl;

            switch (option) {
            case 1:
            {
                system("cls");
                sortname1(n, B);
                //ofstream fileout;
                //fileout.open("Hotel_Services.txt", ios::out | ios::trunc);
                //fileout.close();
                printtitle1();
                for (i = 0; i < n; i++) {
                    B[i].print();
                    //B[i].save();
                }
                cout << endl << endl;
                _getch();
                break;
            }

            case 2:
            {
                system("cls");
                sortIDcoupon(n, B);
                //ofstream fileout;
                //fileout.open("Hotel_Services.txt", ios::out | ios::trunc);
                //fileout.close();
                printtitle1();
                for (i = 0; i < n; i++) {
                    B[i].print();
                    //B[i].save();
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

            n = countline1();
            getinfor1(n, B);

            string namefind;
            cout << " + Checking for customer!" << endl;
            cout << " + Enter a name of Customer: ";
            cin.ignore();
            getline(cin, namefind);
            cout << endl;

            for (i = 0; i < n; i++) {
                if (setbaform1(namefind) == B[i].getname()) {
                    printtitle1();
                    B[i].print(); cout << endl;
                    up++;
                }
                else
                    count++;
            }

            if (up > 1) {
                cout << "\nEnter ID searching: "; cin >> newID;
                cout << endl;
                for (i = 0; i < n; i++) {
                    if (newID == B[i].getID()) {
                        printtitle1();
                        B[i].print(); cout << endl;
                        b = 1;
                    }
                }
                if (b != 1) {
                    cout << "\nID of the customer dosen't exit in the admin system!" << endl;
                    cout << "Please, checking it again!" << endl;
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
                cout << "Name of the customer dosen't exit in the admin system!" << endl;
                cout << "Please, checking it again!" << endl;
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
            n = countline1();
            getinfor1(n, B);

            int found = 0;
            long long newIDcoupon = 0;
            cout << "Enter IDcoupon searching: "; cin >> newIDcoupon;
            cout << endl;
            for (i = 0; i < n; i++) {
                if (newIDcoupon == B[i].getIDcoupon()) {
                    printtitle1();
                    B[i].print(); cout << endl;
                }
                else
                    found++;
            }
            IDcouponreal(found, newIDcoupon, n);
            _getch();
            break;
        }

        case 5:
        {
            system("cls");
            n = countline1();
            getinfor1(n, B);

            char a;
            int found = 0;
            int cancel = 0;
            long long newIDcoupon = 0;
            cout << "Enter IDcoupon searching: "; cin >> newIDcoupon;
            for (i = 0; i < n; i++) {
                if (newIDcoupon == B[i].getIDcoupon()) {
                    cout << endl;
                    printtitle1();
                    B[i].print(); cout << endl;
                    cout << "\nDo you want to modify the information of this customer!\n" << "Yes(y) or No(n): ";
                    cin >> a;
                    system("cls");
                    if (a == 'y') {
                        found = 1;
                        B[i].add2();
                        B[i].setform1();
                        B[i].setform2();
                        cout << "\nIDcoupon of this Customer " << newIDcoupon << " has been edited! " << endl << endl;
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
                fileout.open("Hotel_Services.txt", ios::out | ios::trunc);
                fileout.close();

                system("cls");
                printtitle1();
                for (i = 0; i < n; i++) {
                        B[i].print();
                        B[i].save();
                }
                cout << endl << endl;
            }

            IDcouponreal(found, newIDcoupon, 0);

            _getch();
            break;
        }

        case 6:
        {
            system("cls");
            n = countline1();
            getinfor1(n, B);

            char a;
            int found = 0;
            int cancel = 0;
            long long newIDcoupon = 0;
            cout << "Enter IDcoupon searching: "; cin >> newIDcoupon;
            for (i = 0; i < n; i++) {
                if (newIDcoupon == B[i].getIDcoupon()) {
                    cout << endl;
                    printtitle1();
                    B[i].print(); cout << endl;
                    cout << "\nDo you want to delete this customer!\n" << "Yes(y) or No(n): ";
                    cin >> a;
                    system("cls");
                    if (a == 'y') {
                        found = 1;
                        for (int j = i; j < n; j++) {
                            B[j] = B[j + 1];
                        }
                        cout << "\nIDcoupon of the Customer " << newIDcoupon << " has been deleted! " << endl << endl;
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
                fileout.open("Hotel_Services.txt", ios::out | ios::trunc);
                fileout.close();

                printtitle1();
                for (i = 0; i < n; i++) {
                        B[i].print();
                        B[i].save();
                }
                cout << endl << endl;
            }

            IDcouponreal(found, newIDcoupon, 0);

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
