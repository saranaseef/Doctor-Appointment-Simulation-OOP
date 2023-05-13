#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <string>
using namespace std;
const int CAPACITY = 1000;

template<class T>
class Queue
{
	int back;
	T container[CAPACITY];
public:
	Queue();
	bool enqueue(T);
	T dequeue();
	bool empty();
	void print();
};


template<class T>
Queue<T>::Queue() {
	back = -1;
}
template<class T>
bool Queue<T>::enqueue(T x)
{
	if (back >= (CAPACITY - 1))
		return false;
	else
	{
		back++;
		container[back] = x;
		return true;
	}
}
template<class T>
T Queue<T>::dequeue()
{
	if (back < 0)
		return T();
	else
	{
		T x = container[0];
		for (int i = 1; i <= back; i++)
			container[i - 1] = container[i];
		back--;
		return x;
	}
}
template<class T>
bool Queue<T>::empty()
{
	return (back < 0);
}

template<class T>
void Queue<T>::print()
{
	for (int i = 0; i <= back; i++)
		cout << container[i] << " ";
	cout << endl;
}




#endif // QUEUE_H 