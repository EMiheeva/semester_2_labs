#include <iostream>
#include <chrono>
using namespace std;

double f(double x) {
	return x - 10;
}

int main()
{
	int a = 0, b = 100;
	double right = b, left = a;
	for (int i = 1; i <= 100; i++) {
		while (right - left > 1e-4) {
			double middle = (right + left) / 2;
			if (f(middle) < 0)
				left = middle;
			else
				right = middle;
		}
	}
	//cout << (right + left) / 2;
	cout << right << " " << left << endl;
}
