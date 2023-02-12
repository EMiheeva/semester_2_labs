#include <iostream>
#include <chrono>
using namespace std;

class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now())
    {
    }

    void reset()
    {
        m_beg = clock_t::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};


int main(){

    Timer t;
    srand(time(0));
    int N = 10;
    const int S = 100;
    double A[S][S];
    double B[S][S];
    double C[S][S];
    
    cout<<"Matrix A:"<<endl;
    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++)
            A[i][j] = rand()%5+1;
    
    
    cout << "Matrix B:" << endl;
    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++)
            B[i][j] = rand()%5+1;
    
	cout << "Matrix C=AB:" << endl;
    
    for(int i=0; i < N; i++){   
        for(int j=0; j < N; j++){
            C[i][j]=0;
            for(int k=0; k < N; k++)
            C[i][j]+=A[i][k]*B[k][j];
            //check
			//cout << C[i][j] << " ";
        }
     //cout << endl;
    }

    std::cout << "Time elapsed: " << t.elapsed() << std::endl;

return 0;
}
