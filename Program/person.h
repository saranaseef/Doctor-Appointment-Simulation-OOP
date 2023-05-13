#pragma once
#include<string>
#include<iostream>

using namespace std;

struct appointment {
	int hours, minutes;
};
class person 
{
private:
	string name;
	int id, age;
public:
	person();
	person(int id, string name, int age);
	void setName(string n);
	void setId(int i);
	void setAge(int a);
	string getName();
	int getId();
	int getAge(person p);
	void print();

};