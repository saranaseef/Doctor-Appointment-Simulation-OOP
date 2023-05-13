#include<iostream>
#include<string>
#include "patient.h"


patient::patient()
{
	int id = 0000, age = 18;
	string name = "patient";

}
patient::patient(int id, string name, int age) : person(id, name, age)
{
}
void patient::setDoctorId(int id)
{
	doctorId = id;
}
void patient::setAppointment(appointment ap)
{
	app.hours = ap.hours;
	app.minutes = ap.minutes;
}
int patient::getDoctorId()
{
	return doctorId;
}
appointment patient::getAppointment()
{
	return app;
}
bool patient::operator>(const patient& p)
{
	return true;
}

