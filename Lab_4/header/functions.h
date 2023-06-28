#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>

extern const int s = 5;
extern int ResultingWeight = 0;

std::vector<char> elements = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};

void CreateGraph( int** array)
{
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			if (i != j)
			{
				std::cout << elements[i] << " - " << elements[j] << " = ";
				std::cin >> array[i][j];

				std::cout << std::endl;
			}
			else
				array[i][j] = 0;
		}
		system("cls");
	}
}

void printMST(int parent[], int** graph)
{
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < s; i++)
    {
        std::cout << parent[i] << " - " << i << " \t"
            << graph[i][parent[i]] << " \n";
        ResultingWeight += graph[i][parent[i]];
    }
  
}

int minKey(int key[], bool mstSet[])
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < s; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void primMST(int** graph)
{

    int parent[s];

    int key[s];

    bool mstSet[s];

    for (int i = 0; i < s; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1; 


    for (int count = 0; count < s - 1; count++) {

        int u = minKey(key, mstSet);

       
        mstSet[u] = true;

        for (int v = 0; v < s; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u, key[v] = graph[u][v];   
            }
        }       
    }
    
    printMST(parent, graph);
}