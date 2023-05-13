#include<iostream>
#include "person.h"
#pragma once

using namespace std; 

class Doctor : public person
{
private: 
	int counter = 0;
	appointment apps[100];
public:

	Doctor();
	Doctor(int id, string name, int age);
	bool isAvailable(appointment a);
	void setAppointments(appointment app);
	int getCounter();
	appointment getAppointment();
};
