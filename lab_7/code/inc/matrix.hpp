#include <iostream>

class Matrix
{
public:
	Matrix(int n, int m)
	{
		std::cout << "Constructor matrix is worked" << std::endl;
		m_n = n;
		m_m = m;
		m_mat = new double* [m_n];
		for (int i = 0; i < m_n; i++)
		{
			m_mat[i] = new double[m_m];
		}
	}

	Matrix(const Matrix& mat)
	{
		std::cout << "Constructor Copy" << std::endl;
		m_n = mat.m_n;
		m_m = mat.m_m;
		m_mat = new double* [m_n];
		for (int i = 0; i < m_n; i++)
		{
			m_mat[i] = new double[m_m];
		}
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				m_mat[i][j] = mat.m_mat[i][j];
			}
		}
	}
	// Operator assignment 
	Matrix& operator=(const Matrix& mat)
	{	
		std::cout << "Operator= is worked" << std::endl;
		m_n = mat.m_n;
		m_m = mat.m_m;
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				m_mat[i][j] = mat.m_mat[i][j];
			}
		}
		return *this;
	}
	// Addition operator
	Matrix operator+(const Matrix& mat)
	{
		Matrix tmp(m_n, m_m);
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
			}
		}
		return tmp;
	}

	// Task 1: Multiplication operator
	Matrix operator*(const Matrix& mat)
	{
		Matrix tmp(m_n, m_m);
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < mat.m_m; j++)
			{
				tmp.m_mat[i][j] = 0;
				for (int k = 0; k < m_m; k++)
				{
					tmp.m_mat[i][j] += m_mat[i][k] * mat.m_mat[k][j];
				}
			}
		}
		return tmp;
	}
	// Task 2: Subtraction operator
	Matrix operator-(const Matrix& mat)
	{
		Matrix tmp(m_n, m_m);
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				tmp.m_mat[i][j] = m_mat[i][j] - mat.m_mat[i][j];
			}
		}
		return tmp;
	}

	// Task 3: Matrix determinant operator
	int determinant()
	{
		if (m_n != m_m)
		{
			std::cout << "The matrix is not square. The operation is not supported." << std::endl;
			return -1;
		}
		else {
			if (m_n == 2)
			{
				std::cout << "The matrix is square. The operation is supported." << std::endl;
				return m_mat[0][0] * m_mat[1][1] - m_mat[0][1] * m_mat[1][0];
			}

			if (m_n == 3)
			{
				std::cout << "The matrix is square. The operation is supported." << std::endl;
				return m_mat[0][0] * m_mat[1][1] * m_mat[2][2] + m_mat[0][1] * m_mat[1][2] * m_mat[2][0]
					+ m_mat[1][0] * m_mat[2][1] * m_mat[0][2] - (m_mat[2][0] * m_mat[1][1] * m_mat[0][2] +
						m_mat[2][1] * m_mat[1][2] * m_mat[0][0] + m_mat[1][0] * m_mat[0][1] * m_mat[2][2]);
			}

			if (m_n > 3) {
				std::cout << "The matrix is square, but " << m_n << "x" << m_m << std::endl;
				std::cout << "The operation is not supported." << std::endl;
				return -1;
			}
			return -1;
		}
	}

	// Task 4: Transpose matrix operator
	Matrix transpose()
	{
		Matrix tr_mat(m_m, m_n);
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				tr_mat.m_mat[i][j] = m_mat[j][i];
			}
		}
		return tr_mat;
	}

	// Task 5: Inverse matrix operator
	Matrix inversion()
	{
		int reverse = determinant();
		Matrix tmp(m_n, m_m);
		if (m_n == m_m)
		{
			if (reverse == 0)
			{
				std::cout << "The determinant is zero. The matrix is degenerate." << std::endl;
				std::cout << "She doesn't have a reverse. The operation is not supported." << std::endl;
				//return -1;
			}
			else
			{
				std::cout << "The determinant is not zero. The matrix is generate. She have a reverse." << std::endl;
				if (m_n == 2)
				{
					tmp.m_mat[0][0] = m_mat[1][1] / reverse;
					tmp.m_mat[0][1] = -m_mat[0][1] / reverse;
					tmp.m_mat[1][0] = -m_mat[1][0] / reverse;
					tmp.m_mat[1][1] = m_mat[0][0] / reverse;
					return tmp;
				}
				if (m_n == 3)
				{
					tmp.m_mat[0][0] = (m_mat[1][1] * m_mat[2][2] - m_mat[2][1] * m_mat[1][2]) / reverse;
					tmp.m_mat[1][0] = -(m_mat[1][0] * m_mat[2][2] - m_mat[2][0] * m_mat[1][2]) / reverse;
					tmp.m_mat[2][0] = (m_mat[1][0] * m_mat[2][1] - m_mat[2][0] * m_mat[1][1]) / reverse;
					tmp.m_mat[0][1] = -(m_mat[0][1] * m_mat[2][2] - m_mat[2][1] * m_mat[0][2]) / reverse;
					tmp.m_mat[1][1] = (m_mat[0][0] * m_mat[2][2] - m_mat[2][0] * m_mat[0][2]) / reverse;
					tmp.m_mat[2][1] = -(m_mat[0][0] * m_mat[2][1] - m_mat[2][0] * m_mat[0][1]) / reverse;
					tmp.m_mat[0][2] = (m_mat[0][1] * m_mat[1][2] - m_mat[1][1] * m_mat[0][2]) / reverse;
					tmp.m_mat[1][2] = -(m_mat[0][0] * m_mat[1][2] - m_mat[1][0] * m_mat[0][2]) / reverse;
					tmp.m_mat[2][2] = (m_mat[0][0] * m_mat[1][1] - m_mat[1][0] * m_mat[0][1]) / reverse;
					return tmp;
				}
				if (m_n > 3) {
					std::cout << "The operation is not supported for higher order matrixes." << std::endl;
					//return -1;
				}
			}
		}
		else {
			std::cout << "This operation is only available for square matrixes." << std::endl;
			//return -1;
		}
	}

	// Destructor
	~Matrix()
	{
		std::cout << "Destructor" << std::endl;
		for (int i = 0; i < m_n; i++)
		{
			delete[] m_mat[i];
		}
		delete m_mat;
	}
	friend std::istream& operator>>(std::istream& in, Matrix& mat);
	friend std::ostream& operator<<(std::ostream& out, const Matrix& mat);
private:
	int m_n, m_m;
	double** m_mat;
};

// Overloading the input operator
std::istream& operator>>(std::istream& in, Matrix& mat)
{
	for (int i = 0; i < mat.m_n; i++)
	{
		for (int j = 0; j < mat.m_m; j++)
		{
			in >> mat.m_mat[i][j];
		}
	}
	return in;
}

// Overloading the output operator
std::ostream& operator<<(std::ostream& out, const Matrix& mat)
{
	out << "Matrix " << mat.m_n << "x" << mat.m_m << std::endl;
	for (int i = 0; i < mat.m_n; i++)
	{
		for (int j = 0; j < mat.m_m; j++)
		{
			out << mat.m_mat[i][j] << " ";
		}
		out << std::endl;
	}
	return out;
}

void introduction(){
	std::cout << "Welcome to the math library. Create your matrix right now!" << std::endl;
}

void ending(){
	std::cout << "The program has finished working out!" << std::endl;
}
