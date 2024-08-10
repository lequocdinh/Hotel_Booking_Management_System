#ifndef _CUSTOMER_HEADER_
#define _CUSTOMER_HEADER_

#include <string>
#include <iostream>

using namespace std;

class Customer {

protected:
	string sex;
	string name, birthdate;
	long long ID, phone;

public:
	Customer();
	Customer& operator=(const Customer& mat);
	virtual ~Customer();
	virtual void add();
	virtual void print() const;
	virtual void save() const;
	virtual void getfile(ifstream& filein);
	string setform1();
	string setform2();
	string getname() const;
	string cutname(int k);
	long long getID() const;
};

#endif

