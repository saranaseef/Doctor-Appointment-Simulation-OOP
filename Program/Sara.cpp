#include<iostream>
#include<fstream>
#include<string>
#include"person.h"
#include"doctor.h"
#include"patient.h"
#include"Queue.h"

#pragma once

using namespace std; 

int main()
{
	int numberOfPatients= 0, numberOfDoctors=0;

	cout << "enetr the number of patients" << endl;
	cin >> numberOfPatients;
	cout << "enetr the number of doctors" << endl;
	cin >> numberOfDoctors;
	patient *p = new patient[numberOfPatients];
	Doctor *d = new Doctor[numberOfDoctors];
	
	cout << "do you want to read from file or initialized values? F/I"<< endl;
	char choise;
	cin >> choise;


	if (choise == 'i'||choise == 'I')
	{

		for (int i = 0; i < numberOfDoctors; i++)
		{
			int x, z;
			string y;
			cout << "enter doctor's age:";
			cin >> x;
			d[i].setAge(x);
			cout << "enter doctor's name:";
			cin >> y;
			d[i].setName(y);

			cout << "enter the number of appointments:";
			cin >> z;
			for (int j = 0; j < z; j++)
			{
				int hour, min;
				cout << "Enter the hour\n";
				cin >> hour;
				cout << "enter the min \n";
				cin >> min;
				appointment app;
				app.hours = hour;
				app.minutes = min;
				d[i].setAppointments(app);

			}

		}

		for (int i = 0; i < numberOfPatients; i++)
		{
			int x, z;
			string y;
			cout << "enter patient's age:";
			cin >> x;
			p[i].setAge(x);
			cout << "enter patient's name:";
			cin >> y;
			p[i].setName(y);

			int hour, minute;
			cout << "Enter the hour\n";
			cin >> hour;
			cout << "enter the min \n";
			cin >> minute;
			appointment app;
			app.hours = hour;
			app.minutes = minute;
			p[i].setAppointment(app);
		}
	}
	else if (choise == 'f' || choise == 'F')
	{
// file name for patients
		ifstream in;
		cout << "Enter file name for patients: ";
		string fileName;
		cin >> fileName;
		in.open(fileName);
		for (int i = 0; i < numberOfPatients; i++)                                               // read file by line
		{
			string name;
			int id, age, hour, minutes;
			in >> name >> id >> age >> hour >> minutes;
			
			p[i].setName(name);
			//setters;
		}
		in.close();
// file name for doctors 
		ifstream inp;
		cout << "Enter file name for doctors: ";
		string fileName2;
		cin >> fileName2;
		inp.open(fileName2);
		string* d = new string[numberOfPatients];
		for (int i = 0; i < numberOfPatients; i++)                                               // read file by line
		{
			getline(inp, d[i]);
		}
		in.close();
		
	}
	else
	{
		cout << "Wrong entry!";
	}
//bubble sort 
	Queue<patient> Q;        	//object from Queue
	appointment ap; 
	for (int i = 0; i < numberOfPatients; i++)
	{
		for (int j = 0; j < numberOfPatients - i - 1; j++)
		{
			if (p[j] > p[j + 1])
			{ 
				patient temp;
				temp = p[j+1];
				p[j+1] = p[j];
				p[j] = temp;

			}
		}
	}
	for (int i = 0; i < numberOfPatients; i++)
	{
		Q.enqueue(p[i]);
		cout << p[i].getName() << endl;
	}

	int counter = 0;
	for (int i = 0; i < numberOfPatients; i++)                                                                  
	{
		bool assign = false;
		patient p = Q.dequeue();	
		while (assign == false)
		{
			
			if (d[counter].isAvailable(p.getAppointment()))
			{
				d[counter].setAppointments(p.getAppointment());
				appointment app = p.getAppointment();
				cout <<"Doctor" << d[counter].getName() << " is assigned to the patient " << p.getName() << " at: " << app.hours << ":" << app.minutes<<endl;
				cout << "================================================================="<<endl;
				assign = true;
			}

			counter++;
			if (counter >= numberOfDoctors)
			{
				counter = 0;
			}
		}
	}
	delete[] d;
	delete[] p;
	return 0;












}