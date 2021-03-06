// Pontok.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

int valamifuggveny(int a = 6)
{
	return a * a;
}

int main()
{
	std::cout << valamifuggveny(4) << std::endl;
	std::vector<double> list;
	std::ifstream f("Number.txt");
	if (!f.is_open())
	{
		return -1;
	}
	std::string line;
	while (!f.eof()){ // EOF = fájl vége
		std::getline(f, line);
		std::istringstream ss(line);
		double a;
		ss >> a;
		std::cout << a << std::endl;
		list.push_back(a);
	}
	// Átlag
	double sum = 0.0;
	for (int i = 0; i < list.size(); i++){
		sum += list[i];
	}
	double avg = sum / list.size();
	std::cout << "Átlag: " << avg << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
