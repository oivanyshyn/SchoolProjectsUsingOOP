#include "Notifications.h"

namespace w5 {

	Notifications& Notifications::operator=(const Notifications& rhs)
	{
		if (this != &rhs) {
			message_manager = rhs.message_manager;
		}
		return *this;
	}

	Notifications::Notifications(Notifications&& rhs) 
	{
		message_manager = rhs.message_manager;
		rhs.message_manager.clear();
	}

	Notifications&& Notifications::operator=(Notifications&& rhs)
	{
		if (this != &rhs) {
			message_manager = move(rhs.message_manager);
		}
		return move(*this);
	}

	
	void Notifications::display(ostream& os) const
	{
		for (auto m = message_manager.begin(); m != message_manager.end(); m++) {
			m->display(os);
			cout << endl;
		}

	}

	Notifications::~Notifications() 
	{
		message_manager.clear();
	}

}