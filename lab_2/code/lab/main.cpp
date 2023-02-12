#include <iostream>
#include <chrono>
using namespace std;

const int N = 1000;

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
	auto start_time = std::chrono::steady_clock::now();
	QuickSort(mass, 0, N - 1);
	BubbleSort(mass);

	for (int k = 0; k < N; k++) {
		cout << mass[k] << " ";
	}
	return 0;

	auto end_time = std::chrono::steady_clock::now();
	auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
	cout << elapsed_ns.count() << " ns\n";
	cout << endl;
}
