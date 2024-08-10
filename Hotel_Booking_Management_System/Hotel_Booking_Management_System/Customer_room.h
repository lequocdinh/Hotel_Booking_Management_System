#ifndef _CUSTOMER_ROOM_HEADER_
#define _CUSTOMER_ROOM_HEADER_

#include <string>
#include <iostream>
#include "Customer.h"

using namespace std;

class Customer_room : public Customer {

private:
	int rooms, hours;

public:
	Customer_room();
	Customer_room& operator=(const Customer_room& mat);
	void add1(int k);
	void add2();
	void print() const;
	void save() const;
	void getfile(ifstream& filein);
	int getroom() const;
	void puthours();
};

#endif

