#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <cstdio>
#include "Customer_room.h"

using namespace std;

extern int x[];

Customer_room::Customer_room() : Customer() {
	this->rooms = 0;
	this->hours = 0;
}

Customer_room& Customer_room::operator=(const Customer_room& mat) {
	this->name = mat.name;
	this->sex = mat.sex;
	this->ID = mat.ID;
	this->phone = mat.phone;
	this->birthdate = mat.birthdate;
	this->rooms = mat.rooms;
	this->hours = mat.hours;

	return *this;
}

void Customer_room::add1(int k) {
here:
	cout << "\n\t\t\t\t\tHOTEL ROOM BOOKING MANAGEMENT SYSTEM" << endl;
	cout << "\n\t\t\t\tROOM TYPES" << endl;
	cout << "\n\t\t\t\tTotal number of Rooms: 100" << endl;
	cout << "\n\t\t\t\t+ Ordinary Rooms: 1 - 49" << endl;
	cout << "\n\t\t\t\t+ Luxuary Rooms: 50 - 84" << endl;
	cout << "\n\t\t\t\t+ Royal Rooms: from 85 - 100" << endl;

	cout << "\n\t\t\t\tChoose Rooms that you want to stay in: ";
	cin.ignore();  cin >> rooms;

	int count = 0;
	for (int i = 0; i < k; i++) {
		if (this->rooms == x[i]) {
			cout << "\n\n\t\t\t\tRoom " << rooms << " is already in use!";
			cout << "\n\t\t\t\tPlease, choose another room! " << endl;
			cout << "\n\t\t\t\tPress any keys to continue!!";
			_getch();
			system("cls");
			goto here;
		}
		else
			count++;
	}
	if ((count == k) && (rooms > 100)) {
		cout << "\n\n\t\t\t\tRoom " << rooms << " dosen't exist in the admin system!";
		cout << "\n\t\t\t\tPlease, choose another room! " << endl;
		cout << "\n\t\t\t\tPress any keys to continue!!";
		_getch();
		system("cls");
		goto here;
	}
	Customer::add();
	Customer_room::puthours();
	cout << endl;
}

void Customer_room::add2() {
	//cout << "CUSTOMER INFORMATION" << endl;
	Customer::add();
	Customer_room::puthours();
	cout << endl;
}

void Customer_room::print() const {
	cout << left << setw(6) << rooms;
	Customer::print();
	cout << "\t" << left << setw(6) << hours;

	long long price;
	if ((1 <= rooms) && (rooms < 50)) {
		if (hours <= 9)
			price = hours * 100000;
		else if (hours == 12)
			price = hours * 80000;
		else if (hours == 24)
			price = hours * 60000;
		else if (hours >= 24 && hours % 24 == 12)
			price = (hours - 12) * 60000 + 12 * 80000;
		else
			price = hours * 60000;
		cout << "\t" << left << setw(15) << "  Ordinary";
		cout << "\t" << left << price << " VND" << endl;
	}
	else if ((50 <= rooms) && (rooms < 85)) {
		if (hours <= 9)
			price = hours * 200000;
		else if (hours == 12)
			price = hours * 160000;
		else if (hours == 24)
			price = hours * 145000;
		else if (hours >= 24 && hours % 24 == 12)
			price = (hours - 12) * 145000 + 12 * 160000;
		else
			price = hours * 145000;
		cout << "\t" << left << setw(15) << "  Luxury";
		cout << "\t" << left << price << " VND" << endl;
	}
	else {
		if (hours <= 9)
			price = hours * 300000;
		else if (hours == 12)
			price = hours * 250000;
		else if (hours == 24)
			price = hours * 200000;
		else if (hours >= 24 && hours % 24 == 12)
			price = (hours - 12) * 200000 + 12 * 250000;
		else
			price = hours * 200000;
		cout << "\t" << left << setw(15) << "  Royal";
		cout << "\t" << left << price << " VND" << endl;
	}
	//cout << endl;
}

void Customer_room::save() const {
	ofstream fileout;
	fileout.open("Hotel_Room.txt", ios::out | ios::app);
	fileout << rooms << ", " << name << ", " << sex << ", " << ID << ", " << phone << ", " << birthdate << ", " << hours << endl;
	fileout.close();
}

void Customer_room::getfile(ifstream& filein) {
	filein >> rooms;
	filein.seekg(2, 1);
	getline(filein, name, ',');
	filein.seekg(1, 1);
	getline(filein, sex, ',');
	filein.seekg(1, 1);
	filein >> ID;
	filein.seekg(1, 1);
	filein >> phone;
	filein.seekg(2, 1);
	getline(filein, birthdate, ',');
	filein.seekg(1, 1);
	filein >> hours;
}

int Customer_room::getroom() const {
	return this->rooms;
}

void Customer_room::puthours() {
	that:
	system("cls");
	cout << "\n\n\t\t\t\tChoose your time booking for using rooms: " << endl;
	cout << "\n\t\t\t\t1. Less than 10 Hours [1 -> 9 hours]" << endl;
	cout << "\n\t\t\t\t2. Half of a day: 12 hours " << endl;
	cout << "\n\t\t\t\t3. One day: 24 hours" << endl;
	cout << "\n\t\t\t\t4. More than a day" << endl;
	int option;
	cout << "\n\t\t\t\tEnter your option: "; cin >> option;
	switch (option) {
	case 1:
		there:
		system("cls");
		cout << "\n\n\t\t\t\tEnter the hours using room: ";
		cin >> hours;
		cout << endl;
		if (hours > 9) {
			cout << "\n\t\t\t\tThe entered hours is not correct, please try again!";
			cout << "\n\t\t\t\tPress any key to continue!!";
			_getch();
			goto there;
		}
		else
		{
			system("cls");
			cout << "\n\t\t\t\tRoom is booked!!" << endl;
			cout << "\n\t\t\t\tPress any key to continue!";
			_getch();
		}
		break;

	case 2:
		hours = 12;
		cout << "\n\n\t\t\t\tRoom is booked!!" << endl;
		cout << "\n\t\t\t\tPress any key to continue!";
		break;

	case 3:
		hours = 24;
		cout << "\n\n\t\t\t\tRoom is booked!!" << endl;
		cout << "\n\t\t\t\tPress any key to continue!";
		break;

	case 4:
		system("cls");
		int day;
		char xx;
		cout << "\n\t\t\t\tEnter days you want to use the room: ";
		cin >> day;
		cout << "\n\t\t\t\tDo you want to stay more in 12 hours!" << endl;
		cout << "\n\t\t\t\tYes[y] or No[n]: "; cin >> xx;
		if (xx == 'y') {
			hours = 24 * day + 12;
			cout << "\n\t\t\t\tHours using room is: " << hours << " hours" << endl;
			cout << "\n\n\t\t\t\tRoom is booked!!" << endl;
			cout << "\n\t\t\t\tPress any key to continue!";
		}
		else {
			hours = 24 * day;
			cout << "\n\t\t\t\tHours using room is: " << hours << " hours" << endl;
			cout << "\n\n\t\t\t\tRoom is booked!!" << endl;
			cout << "\n\t\t\t\tPress any key to continue!";
		}
		_getch();
		break;

	default:
		cout << "\n\n\t\t\t\tInvalid option! Press any key to continue.";
		_getch();
		goto that;
	}
}

