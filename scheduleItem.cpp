#include "scheduleItem.h"
string scheduleItem::getSubject()
{
	return subject;
}
int scheduleItem::getCatalog()
{
	return catalog;
}
string scheduleItem::getSection()
{
	return section;
}

string scheduleItem::getComponent()
{
	return component;
}

string scheduleItem::getSession()
{
	return session;
}

int scheduleItem::getUnits()
{
	return units;
}

int scheduleItem::getTotEnrl()
{
	return totEnrl;
}

int scheduleItem::getCapEnrl()
{
	return capEnrl;
}

string scheduleItem::getInstructor()
{
	return instructor;
}

//check formatting later
void scheduleItem::print()
{
	cout << subject << catalog << section << component <<
		session << units << totEnrl << capEnrl << instructor << endl;
}

//will implement operator overloads later
bool scheduleItem::operator==(string item)
{
	return (key == item);
}
bool scheduleItem::operator!=(string item)
{
	return !(key == item);
}
bool scheduleItem::operator>=(string item)
{
	return (key >= item);
}

void schedule::initSchedule(ifstream& datafile)
{
	string header;
	string input;
	getline(datafile, header);

	string subject;
	int catalog;
	string section;
	string component;
	string session;
	int units;
	int totEnrl;
	int capEnrl;
	string instructor;

	while (getline(datafile, input))
	{
		//getline(datafile, subject);
		for (int i = 0; i < 8; i++)
			datafile.ignore();

		datafile >> subject >> catalog >> section >> session >> units >> totEnrl >> capEnrl >> instructor;

		scheduleItem newItem(subject, catalog, section, component, session, units, totEnrl, capEnrl, instructor);
		addEntry(newItem);
	}
}

void schedule::addEntry(scheduleItem addItem)
{
	string key = addItem.getSubject() + "_" + to_string(addItem.getCatalog()) + "_" + addItem.getSection();
	sMap.insert(pair<string,scheduleItem>(key,addItem));
}

void schedule::print()
{
	for (auto& mapEntry : sMap)
	{
		mapEntry.second.print();
	}
}

void schedule::printHeader()
{
	cout << "Subejct" << " " << "Catalog" << " " << "Section" << " " << "Component" << " "
		<< "Session" << "Unit" << "TotEnrl" << " " << "CapEnrl" << " " << "Instructor" << endl;
}

void schedule::findSubject(string sub)
{
	for (auto& mapEntry : sMap)
	{
		if (mapEntry.second.getSubject() == sub) // how does this work with a conjoined key
			cout << mapEntry.second.getSubject() << endl;
	}

}

void schedule::findSubandCat(string sub, int cat)
{
	for (auto& mapEntry : sMap)
	{
		if (mapEntry.second.getSubject() == sub || mapEntry.second.getCatalog() == cat)
			cout << mapEntry.second.getSubject() << mapEntry.second.getCatalog() << endl;
	}
}

void schedule::findIns(string ins)
{
	for (auto& mapEntry : sMap)
	{
		if (mapEntry.second.getInstructor() == ins)
			cout << mapEntry.second.getInstructor() << endl;
	}
}