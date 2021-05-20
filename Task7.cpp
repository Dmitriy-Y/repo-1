#include<iostream>
#include"mylib.h"

#define rangeZeroToLimit(arg, limit) if( (arg >= 0) && (arg <= limit)) {std:: cout << "TRUE" << std::endl;} else { std::cout << "FALSE" << std::endl;}
#define ARRAY_SIZE 5

/*
struct Employee //36 bytes
{
	int age; //4 bytes
	std::string name; //28 bytes
	short departmentNumber; //2 bytes

};
*/

#pragma pack(push,1) 

struct Employee //34 bytes
{
	int age; //4 bytes
	std::string name; //28 bytes
	short departmentNumber; //2 bytes

};

#pragma pack(pop)


int main()
{

	//Task1(5)
	const int size = 20;
	int count = 0;
	float arrFloat[size];
	mylib::initArr(arrFloat, size);
	mylib::printArr(arrFloat, size);
	count = mylib::countNumberPositive(arrFloat, size);
	std::cout << "Positive : " << count << std::endl << "Negetive : " << (size - count) << std::endl;

	//Task2
	rangeZeroToLimit(5, 4);

	//Task3
	int arrInt[ARRAY_SIZE];
	mylib::initArr(arrInt, ARRAY_SIZE);
	mylib::sortArrascendingOrder(arrInt, ARRAY_SIZE);
	std::cout << "Sorted array : ";
	mylib::printArr(arrInt, ARRAY_SIZE);

	//Task4
	Employee emp = {25, "Ivan", 10};
	std::cout << emp.age << std::endl << emp.name << std::endl << emp.departmentNumber << std::endl << sizeof(emp);
	
	return 0;
}


