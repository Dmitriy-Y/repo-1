#include<iostream>
#include<fstream>
using namespace std;

void initArrBin(int* ptr,int size)
{
	
	ptr[0] = 1;

	for (size_t i = 1; i < size; i++)
	{

		ptr[i] = 2 * ptr[i - 1];

	}

}

void initArrRand(int* ptr, int size)
{


	for (size_t i = 0; i < size; i++)
	{

		ptr[i] = rand() % 100 + 10;

	}

}

void readArr(int* ptr, int size, string info="" )
{


	for (size_t i = 0; i < size; i++)
	{

		cout << info << i << " = " << ptr[i] << " ";

	}

	cout << endl;
}

void creatFile(string name)
{

	const size_t size = 6;
	int array[size] = { 10, 20, 70, -90, 50, 80 };
	ofstream fout(name);
	int i = 0;
	for (int i = 0; i < size; i++)
	{
		fout << "elem[" << i++ << "]=" << array[i] << endl;
	}
	fout.close();
	
}
void readFile(string name)
{
	const size_t size = 6;
	int array[size];
	ifstream fin(name);
	if (fin.is_open())
	{
		for (int i = 0; i < size; i++)
		{
			fin >> array[i];
			cout << array[i] << " ";
		}
		fin.close();
	}
	else
	{
		cout << "Error. Can not open file.";
	}


}

void Task1()
{

	int* ptrArr;
	int n = 0;
	cout << "Enter size of your array: ";
	cin >> n;

	if (n > 0)
	{
		ptrArr = new (std::nothrow) int[n];

		if (ptrArr != nullptr)
		{

			initArrBin(ptrArr, n);
			readArr(ptrArr, n, "2^");
			delete[] ptrArr;
			ptrArr = nullptr;

		}

		else
		{
			cout << "Error! Can not allocate memory!";

		}
	}

}

void Task2()
{

	int** ptrArr;
	int* ptrStr;
	const size_t m = 4; 
	const size_t n = 4;
	ptrArr = new int * [m]; 
	for (size_t i = 0; i < m; i++) 
	{
		ptrArr[i] = new int[n]; 
	}
	
	for (size_t i = 0; i < m; i++)
	{
		ptrStr = &ptrArr[i][0];
		initArrRand(ptrStr, n);
		readArr(ptrStr, n );
			
	}
	
	for (size_t i = 0; i < m; i++) 
	{
		delete [] ptrArr[i]; 
	}
	delete[] ptrArr;   
	ptrArr = nullptr;

}

void Task3()
{

	string name;
	cout << "Enter file name: ";
	cin >> name;
	creatFile(name);
	readFile(name);

	cout << "Enter file name";
	cin >> name;
	creatFile(name);
	readFile(name);
}
int main()

{
	Task1();
	Task2();
	Task3();
	return 0;
}
