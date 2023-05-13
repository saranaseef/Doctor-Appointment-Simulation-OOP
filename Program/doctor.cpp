#include "doctor.h"
#pragma once

Doctor::Doctor()
{

}

Doctor::Doctor(int id, string name, int age) : person(id, name, age)
{
	
}

bool Doctor::isAvailable(appointment a)
{
	for (int i = 0; i < counter; i++)
	{
		if (a.hours == apps[i].hours && a.minutes == apps[i].minutes)
		{
			return false;
		}
	}
	return true;
}
void Doctor::setAppointments(appointment app)
{
	apps[++counter].hours = app.hours;
	apps[counter].minutes = app.minutes;
}
int Doctor::getCounter()
{
	return counter;
}
appointment Doctor::getAppointment()
{
	return apps[counter];
}


