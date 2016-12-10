/*
 Use nested classes with Vehicle class.
 Design a class for Brand of car.
 Brand is going to store:
	make and model of a car.
 You also mileage and price as part of the Vehicle class.
 
 After you modify and TEST the class by using individual variables, you are
 going to instantiate an array of 3 Vehicle objects. Read in and display data
 for the objects in the array.
 */

#include <iostream>
#include <string>
using namespace std;

class Brand
{
public:
	string make;	//company
	string model;	//corola
};

class Vehicle
{
public:
	Brand car;
	int year;
	int mileage;
	double price;
};

void readIn		(Vehicle &);
void display	(Vehicle);
const int NUM = 3;

int main ()
{
	
	Vehicle drive[NUM];
	
	int elts = 3;
	
	for (int i = 0; i < elts; i++)
	{
		cout << "Car " << i+1 << ":\n";
		readIn(drive[i]);
		cout << endl;
	}
	
	for (int i = 0; i < NUM; i++)
	{
		cout << "Car " << i+1 << ":\n";
		display(drive[i]);
		cout << endl;
	}
	
	return 0;
}

void readIn (Vehicle &arr)
{
	//cout << "Enter the make and model: ";
	cout << "Enter the make: ";
	getline(cin, arr.car.make);
	
	//cin >> arr.car.make >> arr.car.model;
	cout << "Enter the model: ";
	getline(cin, arr.car.model);
	
	cout << "Enter the year, mileage, and price: ";
	cin >>  arr.year >> arr.mileage >> arr.price;
	cin.ignore();
	
	return;
}

void display (Vehicle arr)
{
	cout	<< "Make: "		<< arr.car.make		<< endl
			<< "Model: "		<< arr.car.model		<< endl
			<< "Year: "		<< arr.year			<< endl
			<< "Mileage: "	<< arr.mileage		<< endl
			<< "Price: "		<< arr.price			<< endl;
	return;
}
