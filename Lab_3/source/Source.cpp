#include "C:\Users\trotf\University\DiscreteMath\Lab_3\header\Source.h"

#define SIZE 5

int main(void)
{
	std::vector<int> Array (SIZE);
	short answer = 12;

	while (answer != 0)
	{
		std::cout << "\n---------------------------------------\n";
		
		std::cout << "1) Fill (refill) array by hand\n"
			<< "2) New generation of numbers in array\n3) First taks\n4) Second task\n0) Exit\n";
		
		std::cout << "---------------------------------------\n";

		std::cout << "Enter your choise: ";
		std::cin >> answer;

		switch (answer)
		{
		case 1:
			for (int i = 0; i < SIZE; i++)
			{
				std::cout << "\nElement [" << i + 1 << "] = ";
				std::cin >> Array[i];
			}
			
			std::cout << "\nDone!\n";
			
			system("pause");
			system("cls");

			break;
		case 2:
			Randomize(Array);
			
			std::cout << "\nDone!\n";
			
			system("pause");
			system("cls");
			
			break;
		case 3:
			Output(Array);
			
			First(Array, &Relation);
			
			system("pause");
			system("cls");
			
			break;
		case 4:
			Output(Array);
			Second(Array, &Relation_2);
			
			system("pause");
			system("cls");

			break;
		case 0:
			
			break;
		default:
			std::cerr << "You've chosen incorrect digit\n";

			break;
		}
	}

	return 0;
}
