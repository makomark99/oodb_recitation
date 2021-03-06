// FileHandling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <list>

// Memory leak detection
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

class Person
{
private:
	const std::string first_name;
	const std::string last_name;
	unsigned int age;
	double height;
	double weight;
public:
	Person(const std::string fist_name, const std::string last_name, 
		unsigned int age, double height, double weight) :
		first_name(first_name), last_name(last_name), age(age),
		height(height), weight(weight)
	{}

	Person(const Person& p) : first_name(p.first_name), last_name(p.last_name),
		age(p.age), height(p.height), weight(p.weight) {}

	

	double getHeight() const
	{
		return height;
	}

	double getWeight() const
	{
		return weight;
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	std::ifstream f("Names.txt");
	if (!f.is_open())
	{
		std::cerr << "Could not open file" << std::endl;
		return -1;
	}
	std::string line;
	std::list<Person> persons;
	while (std::getline(f, line))
	{
		std::istringstream ss(line);
		std::string first_name;
		std::string last_name;
		unsigned int age;
		double height;
		double weight;
		ss >> last_name; 
		ss >> first_name;		
		ss >> age;
		ss >> height;
		ss >> weight;
		std::cout << first_name << " " << last_name << " " << age << std::endl;
		Person p(first_name, last_name, age, height, weight);
		persons.push_back(p);
	}
	std::vector<Person> sorted_persons(persons);
	for (unsigned int i = 0; i < sorted_persons.size(); i++)
	{
		for (unsigned int j = i; j < sorted_persons.size(); j++)
		{
			if (sorted_persons[i].getHeight() < sorted_persons[j].getHeight())
			{
				// Swap
				std::swap(sorted_persons[i], sorted_persons[j]);
			}
		}
	}
	for (unsigned int i = 0; i < sorted_persons.size(); i++)
	{
		std::cout << sorted_persons[i].getHeight() << std::endl;
	}
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
