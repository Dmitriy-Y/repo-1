#include<iostream>

#define SwapINT(element1,element2) {int x = element1; element1 = element2; element2 = x;}

namespace mylib
{

	void sortArrascendingOrder(int arr[], int size)
	{
		for (int startIndex = 0; startIndex < size-1; ++startIndex)
		{
			// � ���������� smallestIndex �������� ������ ����������� ��������, ������� �� ����� � ���� ��������.
			// �������� � ����, ��� ���������� ������� � ���� �������� - ��� ������ ������� (������ 0)
			int smallestIndex = startIndex;

			// ����� ���� ������� �������� � ��������� ����� �������
			for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
			{
				// ���� �� ����� �������, ������� ������ ������ ����������� ��������,
				if (arr[currentIndex] < arr[smallestIndex])
					// �� ���������� ���
					smallestIndex = currentIndex;
			}

			// smallestIndex ������ ���������� �������. 
					// ������ ������� ���� ��������� ���������� ����� � ���, ������� �� ����������
			SwapINT(arr[startIndex], arr[smallestIndex]);
		}
	}

	void initArr(float arr[], int size)
	{
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = 50 - rand() % 100;
		}
	}

	void initArr(int arr[], int size)
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cout <<  "element-" << i << " = ";
			std::cin >> arr[i];
		}
	}

	void printArr(float arr[], int size)
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

	void printArr(int arr[], int size)
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;

	}

	int countNumberPositive(float arr[], int size)
	{
		int countPositive = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] > 0)
			{
				countPositive++;
			}
		}
		return countPositive;

	}

}