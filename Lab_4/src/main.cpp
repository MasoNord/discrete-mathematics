#include "C:/Users/trotf/University/DiscreteMath/Lab_4/Lab_4/header/functions.h"

using namespace std;



int main()
{
	int *graph[s];

	for (int i = 0; i < s; i++)
		graph[i] = new int[s];

	CreateGraph(graph);

	cout << "Relations between vertices in graph\n\n";

	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	cout << "\n\n";
	
	primMST(graph);

	cout << "\n\n";

	cout << "Resulting weight of graph is " << ResultingWeight << endl;
	
}