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
		getline(datafile, component, ','); //ignore
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
	//sMap.insert(pair<string,scheduleItem>(key,addItem));
	hMap.insert(key, addItem);
}

void schedule::print()
{
	/*for (auto& mapEntry : sMap)
	{
		mapEntry.second.print();
	}*/
	hMap.display();
}

void schedule::printHeader()
{
	cout << "Subejct" << " " << "Catalog" << " " << "Section" << " " << "Component" << " "
		<< "Session" << " " << "Unit" << " " << "TotEnrl" << " " << "CapEnrl" << " " << "Instructor" << endl;
}

void schedule::findSubject(string sub)
{
	//for (auto& mapEntry : sMap)
	//{
	//	if (mapEntry.second.getSubject() == sub) 
	//		mapEntry.second.print();
	//		//cout << mapEntry.second.getSubject() << endl;
	//}
	hMap.findSubject(sub);
}



void schedule::findSubandCat(string sub, int cat)
{
	//for (auto& mapEntry : sMap)
	//{
	//	if (mapEntry.second.getSubject() == sub && mapEntry.second.getCatalog() == cat)
	//		mapEntry.second.print();
	//		//cout << mapEntry.second.getSubject() << " " << mapEntry.second.getCatalog() << endl;
	//}
	hMap.findSubandCat(sub, cat);
}

void schedule::findIns(string ins)
{
	//for (auto& mapEntry : sMap)
	//{
	//	if (mapEntry.second.getInstructor() == ins || mapEntry.second.getInstructorLast() == ins)
	//		mapEntry.second.print();
	//		//cout << mapEntry.second.getInstructor() << endl;
	//}

	/*for (size_t i = 0; i < hMap.size(); i++) {
		std::cout << "Bucket " << i << ": ";
		for (const auto& pair : table[i]) {
			std::cout << "(" << pair.first << ") ";
		}
		std::cout << std::endl;
	}

	for (size_t i = 0; i < hMap.getSize(); i++)
	{
		for (auto& pair : hMap.getByIndex(i))
		{
			if (ins == hMap.)
		}
	}*/
	hMap.findIns(ins);
}

void schedule::setHashFunction(std::function<size_t(const std::string&)> hashFunc)
{
	hMap.setHashFunction(hashFunc);
}

void schedule::statistics()
{
	cout << "This is the size" << " " << hMap.getSize() << endl;;
	cout << "This is the number of buckets" << " " << hMap.getBuckets() << endl;
	cout << "These are the number of collisions" << " " << hMap.countCollisions() << endl;
	cout << "These are the max number of buckets" << " " << hMap.maxBucketSize() << endl;
	cout << "This is the load factor " << " " << hMap.getLoadFactor() << endl;
}

