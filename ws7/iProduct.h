#pragma once
#include <iostream>
#include <fstream>

using namespace std;
namespace w7 {

	class iProduct {

	public:
		virtual double getCharge() const = 0;
		virtual void display(ostream&) const = 0;
	};

	ostream& operator<< (ostream&, const iProduct*);
	iProduct* readProduct(ifstream&);

}