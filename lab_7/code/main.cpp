#include <iostream>
#include "inc/matrix.hpp"

using namespace std;
int main()
{	
	introduction();
	int i = 0;
	int j = 0;
	std::cout << "Number of matrix rows: " << std::endl;
	std::cin >> i;
	std::cout << "Number of matrix columns:" << std::endl;
	std::cin >> j;
	Matrix A(i, j);
	std::cout << "Elements of your matrix: " << std::endl;
	std::cin >> A;
	std::cout << "Your matrix: " << std::endl;
	std::cout << A;
	std::cout << "transpose is: " << A.transpose() << std::endl;
	std::cout << "determinant is: " << A.determinant() << std::endl;
	std::cout << "inversion is: " << A.inversion() << std::endl;
	ending();
	
	return 0;
}
