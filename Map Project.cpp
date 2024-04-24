// Map Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "scheduleItem.h"

int showMenu()
{
    int choice;
    cout << "-----------Main Menu-------------" << endl;
    cout << "Please enter a choice" << endl;
    //put in options
    cout << "Option 1: Find by Subject" << endl;
    cout << "Option 2: Find by Subject and Catagory" << endl;
    cout << "Option 3: Find by Instructor" << endl;
    cout << "Option 4: Print all" << endl;
    cout << "Enter 0 to close the program" << endl;
    cin >> choice;
    return choice;
}

int main()
{
    //std::cout << "Hello World!\n";
    ifstream inFile;
    //cout << "Please enter the file to open" << endl;
    string entry;
    cin >> entry;
    //inFile.open(entry);
    inFile.open("STEM - Summer 2022 Schedule of Classes as of 05-02-22(1).csv");
    if (!inFile.is_open())
    {
        std::cerr << "Error: Unable to open file " << endl;
        return 1;
    }

    schedule myschedule;
    int chosen;
    string subject;
    int catagory;
    string instructor;
    myschedule.initSchedule(inFile);
    do {
    chosen = showMenu();

        switch (chosen)
        {
        case 1:
            //string subject;
            cout << "You have chosen: Find by Subject" << endl;
            cout << "Enter a Subject" << endl;
            cin >> subject;
            myschedule.findSubject(subject);
            break;
        case 2:
            //string subject;
            //int catagory;
            cout << "You have chosen: Find by Subject and Catagory" << endl;
            cout << "Enter a Subject" << endl;
            cin >> subject;
            cout << "Enter a catagory" << endl;
            cin >> catagory;
            myschedule.findSubandCat(subject, catagory);
            break;
        case 3:
            //
            // string instructor;
            cout << "You have chosen: Find by Instructor" << endl;
            cout << "Enter an Instructor" << endl;
            cin >> instructor;
            myschedule.findIns(instructor);
            break;

        case 4:
            cout << "Printing all items now" << endl;
            myschedule.printHeader();
            myschedule.print();
            break;
        case 5:
            break;
        default:
            cout << "Error: inproper choice" << endl;
        }
    } while (chosen != 5);
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
