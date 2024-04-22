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
bool scheduleItem::operator==(scheduleItem item)
{

}
bool scheduleItem::operator!=(scheduleItem item)
{

}
bool scheduleItem::operator>=(scheduleItem item)
{

}