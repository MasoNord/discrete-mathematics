#include "C:\Users\trotf\University\DiscreteMath\Lab_5\header\Header.h"


using namespace std;

int main()
{
	int SIZE = 0;
	int count = 0;
	bool ColorPass = false;

	struct Degree
	{
		int number = 0;
		int degree = 0;
	};
	
	int** a;
	int** colored;
	Degree* d;
	bool* pass;

	string colors[] = { "red", "blue", "green", "yellow", "orange", "violet"};
	
	cout << "Enter size of your matrix: ";
	cin >> SIZE;

	a = CreateMatrix(SIZE);
	colored = CreateMatrix(SIZE);
	d = new Degree[SIZE];
	pass = new bool[SIZE];
	
	
	cout << "\nCreate you graph: \n";

	CreateGraph(a, SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (a[i][j] > 0)
				count++;
		}
		d[i].degree = count;
		d[i].number = i;
		count = 0;
	}
	
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (d[i].degree <  d[j].degree)
				swap(d[i], d[j]);
		}
	}

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			colored[i][j] = 0;
	
	for (int i = 0; i < SIZE; i++)
		pass[i] = false;

	for (int i = 0, c = 0; i < SIZE; i++)
	{
		if (pass[d[i].number] == false)
		{
			for (int j = 0 ; j < SIZE; j++)
			{
				if (a[d[i].number][j] == 0 && pass[j] == false)
				{
					colored[d[i].number][j] = c + 1;
					pass[j] = true;
					ColorPass = true;
				}

			}
			pass[d[i].number] = true;
			if (ColorPass == true)
				c++;
			ColorPass = false;
		}
		
	}

	cout << "Your graph: \n";

	OutputArray(a, SIZE);

	cout << endl;

	cout << "Degree of edges: \n";

	for (int i = 0; i < SIZE; i++)
		cout << d[i].number << "-" << d[i].degree << "\n";
		
	
	cout << endl;

	cout << "Colored edges of graph: \n";
	
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << colored[d[i].number][j] << " ";
		}
		cout << "\n";
	}

	cout << "\nEdge			Color \n";

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (colored[i][j] != 0)
			{
				cout << j << " - " << colors[colored[i][j]];
				cout << "\n";
			}
		}
	}

	DeletingMatrix(a, SIZE);
	DeletingMatrix(colored, SIZE);
	delete[] d;
	delete[] pass;

}