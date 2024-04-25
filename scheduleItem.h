#pragma once
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <utility>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
class scheduleItem
{
private:
	string subject;
	int catalog;
	string section;
	string component;
	string session;
	int units;
	int totEnrl;
	int capEnrl;
	string instructor;
	string instructorLast;
	string key = subject + to_string(catalog) + section;
public:
	//constructors
	scheduleItem()
	{
		string subject = "";
		int catalog = 0;
		string section = "";
		string component = "";
		string session = "";
		int units = 0;
		int totEnrl = 0;
		int capEnrl = 0;
		string instructor = "";
		string instructorLast = "";
	}
	scheduleItem(string sub, int cat, string sec , string com, string ses,
		int uni, int totE, int capE, string inst, string instL)
	{
		subject = sub;
		catalog = cat;
		section = sec;
		component = com;
		session = ses;
		units = uni;
		totEnrl = totE;
		capEnrl = capE;
		instructor = inst;
		instructorLast = instL;
	}
	//Precondition: none
	//Postcondition: subject is returned
	string getSubject();
	//Precondition: none
	//Postcondition: catalog is returned
	int getCatalog();
	//Precondition: none
	//Postcondition: section is returned
	string getSection();
	//Precondition: none
	//Postcondition: component is returned
	string getComponent();
	//Precondition: none
	//Postcondition: Session is returned
	string getSession();
	//Precondition: none
	//Postconditions: units is returned
	int getUnits();
	//Precondition: none
	//Postcondition: totEnrl is returned
	int getTotEnrl();
	//Precondition: none
	//Postcondition:capEnrl is returned
	int getCapEnrl();
	//Precondition: none
	//Postcondition: instructor is returned
	string getInstructor();
	//Precondition: none
	//Postcondition: instructorlast is returned
	string getInstructorLast();

	//operator overloads
	//Precondition: none
	//Postcondition: provides an equal to operator for the scheduleItems class
	bool operator==(string);
	//Precondition: none
	//Postcondition: provides an not operator for the scheduleItems class
	bool operator!=(string);
	//Precondition: none
	//Postcondition: provides an greater than or equal to operator for the scheduleItems class
	bool operator>=(string);
	
	//Precondition: private variables all have been initialized
	//Postcondition: variables are print in correct order
	void print();

};

class schedule
{
private:
	//map created for storing scheduleItems
	map<string, scheduleItem> sMap;
public:
	//Precondition: A data file to be read has been opened and provided to the user
	//Postcondition: The sMap has been initialized with he scheduleItems 
	void initSchedule(ifstream& datafile);
	//Preconditions: initSchedule has been called and passes a scheduleItem item to this function
	//Postcondition: the item has been added to sMap
	void addEntry(scheduleItem);
	//Precondition: Map has been initialized
	//Postcondition: All entries in the map are printed to client
	void print();
	//Precondition: none
	//Postcondition: Prints out all of the headers of the schedule
	void printHeader();
	//Precondition: Map has been initialized
	//Postcondition: returns all map entries that have the listed subject
	void findSubject(string);
	//Precondition: Map has been initalized
	//Postcondition: returns all map entries that have the listed subject and catalog number
	void findSubandCat(string, int);
	//Precondition: Map has been initalized
	//Postcondition: returns all map entries that have the listed instructor
	void findIns(string);
};

