#include <iostream>
#include <vector>
#include <time.h>

void BubbleSort(std::vector<int>& numbers) {

	for (int i = 0; i < numbers.size() - 1; i++) {

		for (int j = 0; j < numbers.size() - i - 1; j++) {

			if (numbers[j] > numbers[j + 1]) {

				int number = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = number;

			}
		}
	}
}


	void InsertionSort(std::vector<int>& numbers) {

		for (int i = 0; i < numbers.size(); i++) {
				int key = numbers[i];
				int j = i - 1;

				while (j >= 0 && numbers[j] > key) {
					numbers[j + 1] = numbers[j];
					j -= 1;

				}
				numbers[j + 1] = key;
			}
		}

int Index(std::vector<int>& numbers, int begin, int end){
	int numberPivot = numbers[end];
	int i = begin;

	for (int j = begin; j <= end - 1; j++){
		if (numbers[j] < numberPivot){
			i++;

			int number = numbers[j];
			numbers[j] = numbers[j + 1];
			numbers[j + 1] = number;
		}
	}	
	int number = numbers[end];
	numbers[end] = numbers[end + 1];
	numbers[end + 1] = number;

	return (i + 1);
}

void QuickSort(std::vector<int>& numbers, int begin, int end){
	int PartitionIndex = 0;

	if (begin < end){
		PartitionIndex = Index(numbers, begin, end);
		QuickSort(numbers, begin, PartitionIndex - 1);
		QuickSort(numbers, PartitionIndex + 1, end);
	}
}


int main(){
	int nb_aleatoire = rand();
	std::vector<int> numbers;
	srand((unsigned)time(NULL));

	int integer;
	int ChooseSort;

	std::cout << "write down the numbers of integer whate you want ? :";
	std::cin >> integer;

	for (int i = 0; i < integer; i++) {
		int b = rand() % 1000 + 1;
		numbers.push_back(b);
		std::cout << numbers[i] << " ";
	}
	int begin = 0;
	int end = numbers.size();
	std::cout << "\n";
	std::cout << "Choise the sort with : 1 for Bubble sort, 2 for insertion sort, 3 for Quick sort : ";

	std::cin >> ChooseSort;

	std::cout << "\n";
	std::cout << "The sorted numbers is: ";

	switch (1){

	case 1: BubbleSort(numbers);

		for (int i = 0; i < numbers.size(); i++) {
			std::cout << numbers[i] << " ";
		}
		break;
	
	case 2:InsertionSort(numbers);

		for (int i = 0; i < numbers.size(); i++) {
			std::cout << numbers[i] << " ";
		}
		break;

	case 3: QuickSort(numbers, begin, end);

			for (int i = 0; i < numbers.size(); i++) {
			std::cout << numbers[i] << " ";
			}
			break;
	}
	std::cout << "\n";

	system("pause");
	return 0;

}
