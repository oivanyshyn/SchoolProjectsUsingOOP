#pragma once
#include <string>
#include <fstream>

using namespace std;

namespace w2 {

	enum PassType {
		STUDENT_PASS,
		ADULT_PASS,
		PASS_COUNT
	};

	class Station {

	private:

		string _stationName;
		int passes[PASS_COUNT];

	public:

		Station();
		void set(const string & stationName, unsigned studentPass, unsigned adultPass);
		void update(PassType pt, int qty);
		unsigned inStock(PassType) const;
		const string & getName() const;
		~Station();

	};

}