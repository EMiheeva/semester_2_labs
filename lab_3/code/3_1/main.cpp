#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;
const int N = 10000;

void BinarySearch(int mas[], int goal) {
	int left = -1;
	int right = N;

	while (right - left > 1) {
		int middle = (right + left) / 2;
		if (mas[middle] >= goal)
			right = middle;
		else
			left = middle;
	}
	return;
}

void Cycle(int mas[], int goal) {
	for (int i = 0; i < N; i++) {
		if (mas[i] == goal)
			return; 
	}
}

void QuickSort(int mas[], int left, int right) {
	if (left == right) return;
	int pivot = mas[(left + right) / 2];
	int i = left;
	int j = right;
	while (i <= j) {
		while (mas[i] < pivot)
			i++;
		while (mas[j] > pivot)
			j--;
		if (i >= j)
			break;
		swap(mas[i++], mas[j--]);
	}
	QuickSort(mas, left, j);
	QuickSort(mas, j + 1, right);
}

int main()
{
	auto mass = new int[N];

	for (int k = 0; k < N; k++) {
		mass[k] = rand() % 30;
	}
	for (int k = 0; k < N; k++) {
		cout << mass[k] << " ";
	}
	cout << "///" << endl;
	QuickSort(mass, 0, N - 1);
	for (int k = 0; k < N; k++) {
		cout << mass[k] << " ";
	}
	cout << "///" << endl;
	auto start_time = std::chrono::steady_clock::now();

	for (int k = 0; k < N; k++) {
		BinarySearch(mass, rand() % 30);
	}
	return 0;
	for (int k = 0; k < N; k++) {
		Cycle(mass, rand()%30);
	}
	return 0;

	auto end_time = std::chrono::steady_clock::now();
	auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
	cout << elapsed_ns.count() << " ns\n";
	cout << endl;
} 
