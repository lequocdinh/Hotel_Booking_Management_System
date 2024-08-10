#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <cstdio>
#include "Customer_services.h"

using namespace std;

extern long long y[];

Customer_services::Customer_services() : Customer() {
	IDcoupon = 0;
}

Customer_services& Customer_services::operator=(const Customer_services& mat) {
	this->name = mat.name;
	this->sex = mat.sex;
	this->ID = mat.ID;
	this->phone = mat.phone;
	this->birthdate = mat.birthdate;
	this->IDcoupon = mat.IDcoupon;

	return *this;
}

void Customer_services::add1(int k) {
	Customer_services::IDcase(k);
	Customer::add();
	cout << endl;
}

void Customer_services::add2() {
	cout << "\n\n\t\t\t\tSERVICE INFORMATION" << endl;
	Customer::add();
	cout << endl;
}


void Customer_services::print() const {
	cout << left << setw(10) << IDcoupon;
	Customer::print();

	long long price;
	if (1001000 < IDcoupon && IDcoupon <= 1001400) {
		price = 100000;
		cout << "\t" << left << setw(15) << "Swimming pool";
		cout << "\t" << left << price << " VND" << endl;
	}

	else if (2002000 < IDcoupon && IDcoupon <= 2002300) {
		price = 300000;
		cout << "\t" << left << setw(15) << "Gym";
		cout << "\t" << left << price << " VND" << endl;
	}

	else if (3003000 < IDcoupon && IDcoupon <= 3003600) {
		price = 750000;
		cout << "\t" << left << setw(15) << "Buffet";
		cout << "\t" << left << price << " VND" << endl;
	}
	else {
		price = 600000;
		cout << "\t" << left << setw(15) << "Massage & Kara";
		cout << "\t" << left << price << " VND" << endl;
	}
	//cout << endl;
}

void Customer_services::save() const {
	ofstream fileout;
	fileout.open("Hotel_Services.txt", ios::out | ios::app);
	fileout << IDcoupon << ", " << name << ", " << sex << ", " << ID << ", " << phone << ", " << birthdate << endl;
	fileout.close();
}

void Customer_services::getfile(ifstream& filein) {
	filein >> IDcoupon;
	filein.seekg(2, 1);
	getline(filein, name, ',');
	filein.seekg(1, 1);
	getline(filein, sex, ',');
	filein.seekg(1, 1);
	filein >> ID;
	filein.seekg(1, 1);
	filein >> phone;
	filein.seekg(2, 1);
	getline(filein, birthdate, '\n');
}

long long Customer_services::getIDcoupon() const {
	return IDcoupon;
}

void Customer_services::IDcase(int k) {
	cout << "\n\n\t\t\t\t\t\tSERVICES INFORMATION" << endl;
	cout << "\n\t\t\t\t\t1. Swimming pool services: [1001___]" << endl;
	cout << "\n\t\t\t\t\t2. Gym services: [2002___]" << endl;
	cout << "\n\t\t\t\t\t3. Cuisine services: [3003___]" << endl;
	cout << "\n\t\t\t\t\t4. Massage & Kara services: [4004___]" << endl;

	int lastID = 0;
	int option;
	cout << "\n\t\t\t\t\tEnter your option: "; cin >> option;
	switch (option) {
	case 1:
	{
	again1:
		system("cls");
		cout << "\n\t\t\t\tSwimming pool services check_in! " << endl;
		cout << "\n\t\t\t\tEnter your 3 last IDcoupon numbers [1->400]: 1001";
		cin >> lastID;
		if (0 < lastID && lastID <= 400) {
			IDcoupon = 1001 * 1000 + lastID;
			cout << "\n\t\t\t\tYour IDcoupon number is: " << IDcoupon << endl;
			for (int i = 0; i < k; i++) {
				if (this->IDcoupon == y[i]) {
					cout << "\n\t\t\t\tIDcoupon " << IDcoupon << " is already in use!" << endl;
					cout << "\n\t\t\t\tPlease, choose another IDcoupon! ";
					cout << "\n\n\t\t\t\tPress any key to continue!!" << endl;
					_getch();
					goto again1;
				}
			}
			break;
		}
		else {
			cout << "\n\t\t\t\tYour IDnumber Entered is not correct!" << endl;
			cout << "\n\t\t\t\tPlease, checking it again!" << endl;
			cout << "\n\n\t\t\t\tPress any key to continue!!" << endl;
			_getch();
			goto again1;
		}
	}

	case 2:
	{
	again2:
		system("cls");
		cout << "\n\t\t\t\tGym services check_in! " << endl;
		cout << "\n\t\t\t\tEnter your 3 last IDcoupon numbers [1->300]: 2002";
		cin >> lastID;
		if (0 < lastID && lastID <= 300) {
			IDcoupon = 2002 * 1000 + lastID;
			cout << "\n\t\t\t\t\tYour IDcoupon number is: " << IDcoupon << endl;
			for (int i = 0; i < k; i++) {
				if (this->IDcoupon == y[i]) {
					cout << "\n\t\t\t\tIDcoupon " << IDcoupon << " is already in use!" << endl;
					cout << "\n\t\t\t\tPlease, choose another IDcoupon! ";
					cout << "\n\n\t\t\t\tPress any key to continue!!" << endl;
					_getch();
					goto again2;
				}
			}
			break;
		}
		else {
			cout << "\n\t\t\t\tYour IDnumber Entered is not correct!" << endl;
			cout << "\n\t\t\t\tPlease, checking it again!" << endl;
			cout << "\n\n\t\t\t\tPress any key to continue!!" << endl;
			_getch();
			goto again2;
		}
	}

	case 3:
	{
	again3:
		system("cls");
		cout << "\n\t\t\t\tBuffet services check_in! " << endl;
		cout << "\n\t\t\t\tEnter your 3 last IDcoupon numbers [1->600]: 3003";
		cin >> lastID;
		if (0 < lastID && lastID <= 600) {
			IDcoupon = 3003 * 1000 + lastID;
			cout << "\n\t\t\t\tYour IDcoupon number is: " << IDcoupon << endl;
			for (int i = 0; i < k; i++) {
				if (this->IDcoupon == y[i]) {
					cout << "\n\t\t\t\tIDcoupon " << IDcoupon << " is already in use!" << endl;
					cout << "\n\t\t\t\tPlease, choose another IDcoupon! ";
					cout << "\n\n\t\t\t\tPress any key to continue!!" << endl;
					_getch();
					goto again3;
				}
			}
			break;
		}
		else {
			cout << "\n\t\t\t\tYour IDnumber Entered is not correct!" << endl;
			cout << "\n\t\t\t\tPlease, checking it again!" << endl;
			cout << "\n\n\t\t\t\tPress any key to continue!!" << endl;
			_getch();
			goto again3;
		}
	}

	case 4:
	{
	again4:
		system("cls");
		cout << "\n\t\t\t\tMassage & Kara services check_in! " << endl;
		cout << "\n\t\t\t\tEnter your 3 last IDcoupon numbers [1->500]: 4004";
		cin >> lastID;
		if (0 < lastID && lastID <= 500) {
			IDcoupon = 4004 * 1000 + lastID;
			cout << "\n\t\t\t\tYour IDcoupon number is: " << IDcoupon << endl;
			for (int i = 0; i < k; i++) {
				if (this->IDcoupon == y[i]) {
					cout << "\n\t\t\t\tIDcoupon " << IDcoupon << " is already in use!" << endl;
					cout << "\n\t\t\t\tPlease, choose another IDcoupon! ";
					cout << "\n\n\t\t\t\tPress any key to continue!!" << endl;
					_getch();
					goto again4;
				}
			}
			break;
		}
		else {
			cout << "\n\t\t\t\tYour IDnumber Entered is not correct!" << endl;
			cout << "\n\t\t\t\tPlease, checking it again!" << endl;
			cout << "\n\n\t\t\t\tPress any key to continue!!" << endl;
			_getch();
			goto again4;
		}
	}

	}
}