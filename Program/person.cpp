#pragma once
#include"person.h"


person::person(int id, string name, int age)  //default constructor
{
	setName(name);
	setAge(age);
	setId(id);
}
person::person()
{

}
void person::setName(string n)  //setters
{
	name = n;
}
void person::setId(int i) {
	id = i;
}
void person::setAge(int a) {
	age = a;
}
string person::getName() //getters
{
	return name;
}
int person::getId() {
	return id;
}
int person::getAge(person p) {
	return p.age;
}
void person::print() //Print function
{
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
	cout << "Age: " << age << endl;
}


