#include <iostream>
using namespace std;

void PrintArr(int arr[], int size)
{

for (int i = 0; i < size; i++)
{
cout << arr[i] <<  ;
}
cout << endl;
return;
}



//1.Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер. 
//Вызвать эту функцию из main.

void PrintArr(double arr[], int size)
{

for (int i = 0; i < size; i++)
{
cout << arr[i] <<  ;
}
cout << endl;
return;
}



//2.Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. 
//Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.

void PermutationArr(int arr[], int size)
{
for (int i = 0; i < size; i++)
{
if (arr[i] == 1)
{
arr[i] = 0;
}
else
{
arr[i] = 1;
}
}
return;
}



//3.Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его
//значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.

void InitIntArr(int arr[], int size)
{
arr[0] = 1;
for (int i = 1; i < size; i ++)
{
arr[i] = arr[i - 1] + 3;
}
return;
}



int main()
{
//К заданию 1---------------------------------------
const int Msize = 10;
double MyArr[Msize] = { 5.7, 4.9, 6.2, 1.55, 2, 3, 700, 9, 2.2, 4 };
PrintArr(MyArr, Msize);
//--------------------------------------------------

//К заданию 2---------------------------------------
int IArr[Msize] = { 1,0,1,1,1,0,0,1,1,0 };
PrintArr(IArr, Msize);
PermutationArr(IArr, Msize);
PrintArr(IArr, Msize);
//--------------------------------------------------


//К заданию 3---------------------------------------
int IArr8[8];
InitIntArr(IArr8, 8);
PrintArr(IArr8, 8);
//--------------------------------------------------


return 0;
}
