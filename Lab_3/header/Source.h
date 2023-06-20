#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <Windows.h>
#include <functional>
#include <math.h>

using namespace std;

//------------------- Supporting functions -------------------

void Randomize(vector<int>& A)
{
	srand(time(NULL));

	for (int i = 0; i < A.size(); i++)
		A[i] = rand() % 300 - 50;
}

void Output(vector <int> A)
{
	cout << "\n{ ";
	
	for (int i : A)
		cout << i << " ";
	
	cout << "}";
}

//------------------------------------------------------------

//-------------Reflection, symmetric, transitive--------------
bool Relation(int a, int b)
{
	if ((2 * a) + (7 * b) <= 1900)
		return true;
	else
		return false;
}

bool Relation_2(int a, int b)
{
	if (a * b > 0)
		return true;
	else
		return false;
}


bool Reflection(int x, int y, function<int(int, int)> func)
{
	// 2x + 7y <= 1900;
	if (func(x, y))
		return true;
	else  return false;
}

bool Symmetric(int x, int y, function<int(int, int)> func)
{
	if (func(x, y))
	{
		if (func(y, x))
			return true;
		else return false;

	}
}
bool Transitive(int x, int y, int z, function<int(int, int)> func)
{
	if (func(x, y))
		if (func(z, y))
		{
			if (func(x, z))
				return true;
			else
				return false;
		}
}
//------------------------------------------------------------

void First(vector<int> A, function<int(int, int)>func)
{
	cout << "\n2x + 7y <= 1900\n";

	bool pass = true;

	for (int i = 0; i < A.size(); i++)
	{
		if (Reflection(A[i], A[i], func) == false)
		{
			pass = false;
			break;
		}
	}
	if (pass == true)
		cout << "\nRelation is reflective\n";
	else
		cout << "\nRelation is not reflective\n";

	pass = true;

	for (int i = 0; i < A.size(); i++)
	{
		for (int j = i + 1; j < A.size(); j++)
		{
			if (Symmetric(A[i], A[j], func) == false)
			{
				pass = false;
				break;
			}
		}
	}

	if (pass == true)
		cout << "\nRelation is symmetric\n";
	else
		cout << "\nRelation is not symmetric\n";

	pass = true;
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = i + 1; j < A.size(); j++)
		{
			for (int k = 0; k < A.size(); k++)
			{
				if (Transitive(A[i], A[j], A[k], func) == false)
				{
					pass = false;
					break;
				}
			}
		}
	}

	if (pass == true)
		cout << "\nRelation is transitive\n";
	else
		cout << "\nRelation is not transitive\n";

}

void Second(vector<int> A, function<int(int, int)> func)
{
	cout << "\nxy > 0\nfor unsign integers\n";
	
	int count = 0;
	vector<vector<int>> result;
	vector<int> temp;

	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A.size(); j++)
		{
			if (func(A[i], A[j]))
			{
				temp.push_back(A[i]);
				temp.push_back(A[j]);
				result.push_back(temp);
				
				temp.erase(temp.begin(), temp.end());
				
				count++;
			}
		}
	}
	
	if (count > pow(A.size(), (3 / 2)))
		cout << "\nGood!\n";
	else
		cout << "\nBad\n";

	for (int i = 0; i < result.size(); i++)
	{
		cout << "( ";
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << ")\n";
	}
}