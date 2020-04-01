#pragma once
#include <fstream>
#include <iostream>

using namespace std;

namespace w5 {

	class Message {

	private:
		string username_;
		string reply_to_;
		string message_;

	public:

		Message(ifstream& in, char c);
		bool empty() const { return username_.empty() || message_.empty(); }
		void display(ostream& os) const;
	};
}