#include <iostream>
#include <chrono>
using namespace std;

const int N = 10;

int med (int a, int b, int c)
{
  if (a > b) { 
    if (c > a) 
      return a;
    return (b > c) ? b : c;
  } 
  
  if (c > b) 
    return b;
  return (a > c) ? a : c; 
}


void QuickSort(int mas[], int left, int right) {
	if (left == right) return;
	//int pivot = med(mas[left], mas[right], mas[(right+left)/2]); //с помощью медианы трёх
	int pivot = mas[(left + right) / 2];
	cout << "///" << endl;
	cout << "pivot: "<< pivot << endl;
	cout << "///" << endl;
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
		mass[k] = rand() % 7;
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
	
	return 0;
	
}
