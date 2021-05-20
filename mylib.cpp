#include<iostream>

#define SwapINT(element1,element2) {int x = element1; element1 = element2; element2 = x;}

namespace mylib
{

	void sortArrascendingOrder(int arr[], int size)
	{
		for (int startIndex = 0; startIndex < size-1; ++startIndex)
		{
			// ¬ переменной smallestIndex хранитс€ индекс наименьшего значени€, которое мы нашли в этой итерации.
			// Ќачинаем с того, что наименьший элемент в этой итерации - это первый элемент (индекс 0)
			int smallestIndex = startIndex;

			// «атем ищем элемент поменьше в остальной части массива
			for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
			{
				// ≈сли мы нашли элемент, который меньше нашего наименьшего элемента,
				if (arr[currentIndex] < arr[smallestIndex])
					// то запоминаем его
					smallestIndex = currentIndex;
			}

			// smallestIndex теперь наименьший элемент. 
					// ћен€ем местами наше начальное наименьшее число с тем, которое мы обнаружили
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