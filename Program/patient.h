#pragma once
#include"person.h"

class patient : public person //inherited Patient class from Person
{
	appointment app;
	int doctorId;
public:
	patient();
	patient(int id, string name, int age);
	void setDoctorId(int id);
	void setAppointment(appointment ap);
	int getDoctorId();
	bool operator>(const patient& p);
	appointment getAppointment();
};