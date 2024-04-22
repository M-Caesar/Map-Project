#pragma once
#include <iostream>
#include <string>
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
		string instructor = ""
	}
	/*scheduleItem(string sub, int cat, string sec , string com, string ses,
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
	}*/
	string getSubject();
	int getCatalog();
	string getSection();
	string getComponent();
	string getSession();
	int getUnits();
	int getTotEnrl();
	int getCapEnrl();
	string getInstructor();

	bool operator==(scheduleItem);
	bool operator!=(scheduleItem);
	bool operator>=(scheduleItem);

	void print();
};

class schedule
{
private:
public:
};

