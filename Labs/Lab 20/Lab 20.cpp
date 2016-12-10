/*
 Define a class Vehicle. It has year, mileage, price. Instantiate 2 objects, read in 1 object, print 1 object.
 */

#include <iostream>
using namespace std;


int main() {
	
	class Vehicle {
	public:
		int year;
		int mileage;
		double price;
	};
	
	Vehicle car1,
	car2;
	
	cout << "Enter the year, mileage, and price: ";
	cin >>  car1.year >> car1.mileage >> car1.price;
	
	cout	<< "Car 1:"		<< endl
			<< "Year: "		<< car1.year
			<< " Mileage: " << car1.mileage
			<< " Price: "	<< car1.price	<< endl;
	
	car2 = car1;
	
	cout	<< "Car 2:"		<< endl
			<< "Year: "		<< car2.year
			<< " Mileage: " << car2.mileage
			<< " Price: "	<< car2.price	<< endl;
	
}

