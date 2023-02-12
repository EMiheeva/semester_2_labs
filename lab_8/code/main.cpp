#include <iostream>
#include <cassert>
#include "inc/matrix.hpp"

using em::math::Mat22d;
using em::math::Mat33d;
using em::math::Vec2d;

int main()
{
	introduction();
	std::cout << "=== Test 0 ===" << std::endl;
	std::cout << "=== Checking for finding the inverse matrix ===" << std::endl;

	{
		Mat22d A({{
			 {1,2},
			 {3,4}
		} });

		std::cout << "Func inverse matrix demonstrates the following algorithm: " << std::endl;

		auto R = A.inverse();

		//(строка, столбец)
		assert(R.get(0, 0) == -2);
		assert(R.get(1, 0) == 1.5); 
		assert(R.get(0, 1) == 1);
		assert(R.get(1, 1) == -0.5);

		std::cout << "Done!" << std::endl;
		std::cout << "inverse matrix is: " << R << std::endl;
	}
	

	std::cout << "=== Test 1 ===" << std::endl;
	std::cout << "=== Checking the multiplication of two matrices ===" << std::endl;
	{
		Mat22d A({ {
			 {1,2},
			 {3,4}
		} });

		Vec2d X({ {
			{1},
			{1}
		} });

		auto B = A * X;

		assert(B.get(0, 0) == 3);
		assert(B.get(1, 0) == 7);

		std::cout << "Done!" << std::endl;
		std::cout << "The product of two matrices is: " << B << std::endl;
	}

	std::cout << "=== Test 2 ===" << std::endl;
	std::cout << "=== Checking determinant, transpose, and inverse matrix operators ===" << std::endl;

	{
		Mat22d A({ {
			 {1,1},
			 {1,1}
		} });
		Mat33d B({ {
			{1,2,0},
			{1,3,0},
			{2,1,1}
		} });

		std::cout << "Determinant matrix A is: " << A.determinant() << std::endl;
		std::cout << "Determinant matrix B is: " << B.determinant() << std::endl;
		std::cout << "Transpose matrix A is: " << A.transpose() << std::endl;
		std::cout << "Transpose matrix B is: " << B.transpose() << std::endl;
		std::cout << "Inverse matrix A is: " << A.inverse() << std::endl;
		std::cout << "Inverse matrix A is: " << B.inverse() << std::endl;
		
		std::cout << "Done!" << std::endl;
	}
	ending();
	return 0;
}
