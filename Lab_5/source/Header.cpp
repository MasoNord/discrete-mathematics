#include "C:\Users\trotf\University\DiscreteMath\Lab_5\header\Header.h"


int** CreateMatrix(int SIZE)
{
	int** array = new int* [SIZE];

	for (int i = 0; i < SIZE; ++i)
		array[i] = new int[SIZE];

	return array;
}


void DeletingMatrix(int** a, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		delete[] a[i];

	delete[] a;
}

void DeletingStringMatrix(std::string** a, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		delete[] a[i];

	delete[] a;
}


void CreateGraph(int** a, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i != j)
			{
				std::cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
				std::cin >> a[i][j];
			}
			else
				a[i][j] = 0;
		}
		system("cls");
	}
}

void OutputArray(int** a, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << "\n";
	}
}
