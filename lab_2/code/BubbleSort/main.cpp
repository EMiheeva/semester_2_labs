#include <iostream>
#include <chrono>
using namespace std;

const int N = 5;

void BubbleSort(int mas[]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N-1; j++)
			if (mas[j] > mas[j + 1])
				swap(mas[j], mas[j + 1]);
}
int main()
{
	auto mass = new int[N];

	for (int k = 0; k < N; k++) {
		mass[k] = rand() % 7;
	}
	for (int k = 0; k < N; k++) {
		cout << mass[k] << " ";
	}
	cout << "///" << endl;
	BubbleSort(mass);
	for (int k = 0; k < N; k++) {
		cout << mass[k] << " ";
	}
	return 0;
	//for (int k = 0; k < N; k++)
		//delete[] &mass[k];
	//delete[] mass;
	
}
