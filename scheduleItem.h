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
	string key = subject + to_string(catalog) + section;
public:
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
	}
	scheduleItem(string sub, int cat, string sec , string com, string ses,
		int uni, int totE, int capE, string inst)
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
	}
	string getSubject();
	int getCatalog();
	string getSection();
	string getComponent();
	string getSession();
	int getUnits();
	int getTotEnrl();
	int getCapEnrl();
	string getInstructor();

	bool operator==(string);
	bool operator!=(string);
	bool operator>=(string);

	void print();

};

class schedule
{
private:
	map<string, scheduleItem> sMap;
public:
	void initSchedule(ifstream& datafile);
	void addEntry(scheduleItem);
	void print();
	void printHeader();
	void findSubject(string);
	void findSubandCat(string, int);
	void findIns(string);
	void customSplit(string, char);
};

