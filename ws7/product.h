#pragma once
#include "iProduct.h"

namespace w7 {

	class Product : public iProduct {

	private:
		int num_;
		double cost_;

	public:
		Product(int num, double cost) : num_(num), cost_(cost) { }
		double getCharge() const { return cost_; }
		void display(ostream&) const;
	};

}