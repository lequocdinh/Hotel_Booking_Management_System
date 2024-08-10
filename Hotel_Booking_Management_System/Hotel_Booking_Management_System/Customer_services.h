#ifndef _CUSTOMER_SERVICE_HEADER_
#define _CUSTOMER_SERVICE_HEADER_

#include <string>
#include <iostream>
#include "Customer.h"

using namespace std;

class Customer_services : public Customer {

private:
	long long IDcoupon;

public:
	Customer_services();
	Customer_services& operator=(const Customer_services& mat);
	void add1(int k);
	void add2();
	void print() const;
	void save() const;
	void getfile(ifstream& filein);
	long long getIDcoupon() const;
	void IDcase(int k);
};

#endif


