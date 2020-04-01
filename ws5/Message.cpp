#include <string>
#include <sstream>
#include "Message.h"

namespace w5 {

	Message::Message(ifstream& in, char c) {
		string line;
		getline(in, line, c);
		istringstream is(line);

		if (username_.empty()) {
			is >> username_;
			if (!(int)username_.find('@')) {
				username_.clear();
			}
		}
		if (reply_to_.empty()) {
			is >> reply_to_;
			if ((int)reply_to_.find('@')) {
				message_ = reply_to_;
				reply_to_.clear();
			}
		}
		if (message_.empty()) {
			getline(is, message_);
		}
		is.clear();
	}

	void Message::display(ostream &os) const
	{
		os << "Message" << endl << "User : " << username_ << endl;

		if (!this->reply_to_.empty()) {
			os << "Reply : " << reply_to_ << endl;
		}
		os << "Tweet : " << message_ << endl;

	}

}