#pragma once
#include<fstream>
#include <iostream>
#include<string>

namespace w3
{
	class Text {
		size_t count = 0;                //C++14
		std::string* dataTable = nullptr; //C++14
	public:
		~Text()
		{
			delete[] dataTable;
		}
		Text(char* filename)
		{
			//open file 
			std::fstream in(filename, std::ios::in);

			if (in.is_open()) {

				//count the number of line in the file
				std::string line;
				while (getLine(in, line))
					count++;
				std::cout << "file '" << filename << "' contains " << count << "\n";
				//allocate a table to hold the data
				dataTable = new string[count];
				//read the data
				in.clear(); // clear the end-of-file (EOF) error state 
				in.seekp(0) //position the file at the beginning
					for (size_t i = 0; i < count; i++)
						getLine(in, dataTable[i]);
				//close the file
				in.close();
			}
			else {
				std::cerr << "Cannot open the file '" << filename << "'\n";
				exit(99);
			}
			Text& operator = (const Text& rhs) // copy assignment operator
			{
				std::cout << "copy assignment operator";
				if (this != &rhs) {
					delete[] dataTable;
					dataTable = nullptr;
					count = 0;

					if (rhs.dataTable) {
						count = rhs.count;
						dataTable = new::std:string[count];
						for (size_t i = 0; i < count; i++)
							dataTable[i] = rhs.dataTable[i];
					}
					else {
						std::cout << "copy assignment operator --- self assignment \n";
					}
					return this*;
				}
				Text&& operator = (Text&& rhs) // move assignment operator
				{
					std::cout << "move assignment operator\n";
					if (this != &rhs) {
						delete[] datatTable;
						dataTable = rhs.dataTable;
						count = rhs.count;
						rhs.dataTable = nullptr;
						rhs.count = 0;

					}
					else {
						std::cout << "move assignment operator --- self-assignment \n";
						return std::move(*this);
					}

					Text(const text& rhs) //copy constructor
					{
						*this = rhs;
					}
					Text(text&& rhs) //move constructor
					{
						*this = std::move(rhs);

					}
					size_t size()
					{
						return count;
					}
				};
			}