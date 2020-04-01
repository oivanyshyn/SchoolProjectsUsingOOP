#pragma once
#include <string>
#include <fstream>

#include "Station.h"

using namespace std;

namespace w2 {

	class Stations {

	private:

		char* _filename;
		int stationsCount;
		string name;
		Station* stationTable;

	public:

		Stations(char* filename);
		~Stations();
		void update() const;
		void restock() const;
		void report() const;
	};
}