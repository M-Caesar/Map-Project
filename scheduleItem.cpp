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

string scheduleItem::getInstructorLast()
{
	return instructorLast;
}

//check formatting later
void scheduleItem::print()
{
	cout << subject << " " << catalog << " " << section << " " << component << " " <<
		session << " " << units << " " << totEnrl << " " << capEnrl << " " << instructor + "," + instructorLast << endl;
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
	//string input;
	getline(datafile, header);

	string subject;
	string catalog; //int
	string section;
	string component;
	string session;
	string units; //int
	string totEnrl; //int
	string capEnrl; //int
	string instructor;
	string instructorLast;
	string trash;

	while (getline(datafile, subject,','))
	{
		getline(datafile, catalog, ',');
		getline(datafile, section, ',');
		getline(datafile, trash, ','); //ignore
		getline(datafile, session, ',');
		getline(datafile, trash, ','); //ignore
		getline(datafile, units, ',');
		getline(datafile, totEnrl, ',');
		getline(datafile, capEnrl, ',');
		getline(datafile, trash, '"'); //ignore
		getline(datafile, instructor, ',');
		getline(datafile, instructorLast, '"');
		scheduleItem newItem(subject, stoi(catalog), section, component, session, stoi(units), stoi(totEnrl), stoi(capEnrl), instructor, instructorLast);
		addEntry(newItem);

		getline(datafile, trash);

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
		<< "Session" << " " << "Unit" << " " << "TotEnrl" << " " << "CapEnrl" << " " << "Instructor" << endl;
}

void schedule::findSubject(string sub)
{
	for (auto& mapEntry : sMap)
	{
		if (mapEntry.second.getSubject() == sub) 
			mapEntry.second.print();
			//cout << mapEntry.second.getSubject() << endl;
	}

}

void schedule::findSubandCat(string sub, int cat)
{
	for (auto& mapEntry : sMap)
	{
		if (mapEntry.second.getSubject() == sub && mapEntry.second.getCatalog() == cat)
			mapEntry.second.print();
			//cout << mapEntry.second.getSubject() << " " << mapEntry.second.getCatalog() << endl;
	}
}

void schedule::findIns(string ins)
{
	for (auto& mapEntry : sMap)
	{
		if (mapEntry.second.getInstructor() == ins || mapEntry.second.getInstructorLast() == ins)
			mapEntry.second.print();
			//cout << mapEntry.second.getInstructor() << endl;
	}
}