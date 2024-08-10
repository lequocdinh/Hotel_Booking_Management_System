#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <cstdio>
#include "Customer.h"

using namespace std;

Customer::Customer() {
	this->ID = 0;
	this->phone = 0;
	this->name = "none";
	this->sex = "none";
	this->birthdate = "none";
}

Customer::~Customer() {
	// do nothing here:
}

Customer& Customer::operator=(const Customer& mat) {
	this->name = mat.name;
	this->sex = mat.sex;
	this->ID = mat.ID;
	this->phone = mat.phone;
	this->birthdate = mat.birthdate;

	return *this;
}

void Customer::add() {
	cout << "\n\n\t\t\t\tCUSTOMER INFOMATION"<< endl;
	cout << "\n\t\t\t\t+ Full Name: ";
	cin.ignore();
	getline(cin, name);
	cout << "\n\t\t\t\t+ Sex [Male/Female]: ";
	getline(cin, sex);
	cout << "\n\t\t\t\t+ ID number: ";
	cin >> ID;
	cout << "\n\t\t\t\t+ Phone number: ";
	cin >> phone;
	cout << "\n\t\t\t\t+ BirthDate [dd/mm/yy]: ";
	cin.ignore();
	getline(cin, birthdate);
}


void Customer::print() const {
	cout << "\t" << left << setw(22) << name;
	cout << "\t" << left << setw(6) << sex;
	cout << "\t" << left << setw(15) << ID;
	cout << "\t" << left << setw(15) << phone;
	cout << "\t" << left << setw(15) << birthdate;
}

void Customer::save() const {
	ofstream fileout;
	fileout.open("Hotel.txt", ios::out | ios::app);
	fileout << name << ", " << sex << ", " << ID << ", " << phone << ", " << birthdate << ", " << endl;
	fileout.close();
}

void Customer::getfile(ifstream& filein) {
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
}

string Customer::setform1() {
	string res = "";
	stringstream ss(name);
	string token;
	while (ss >> token) {
		res += toupper(token[0]);
		for (int i = 1; i < token.length(); i++) {
			res += tolower(token[i]);
		}
		res += " ";
	}
	res.erase(res.length() - 1);
	name = res;
	return name;
}

string Customer::setform2() {
	string res = "";
	stringstream ss(sex);
	string token;
	while (ss >> token) {
		res += toupper(token[0]);
		for (int i = 1; i < token.length(); i++) {
			res += tolower(token[i]);
		}
		res += " ";
	}
	res.erase(res.length() - 1);
	sex = res;

	return sex;
}

long long Customer::getID() const {
	return this->ID;
}

string Customer::getname() const {
	return this->name;
}

string Customer::cutname(int k) {
	int count = 0;
	string ten = "";
	string s = this->name;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			count++;
		}
	}
	if (count != 0) {
		while (s[s.length() - 1] != ' ') {
			ten.insert(ten.begin() + 0, s[s.length() - 1]);
			s.pop_back();
		}
		s.pop_back();

		if (k == 1) {
			return s;
		}
		else
			return ten;
	}
	else
		return s;
}



