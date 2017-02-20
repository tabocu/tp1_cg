#include <iostream>
#include "../matrix.h"

using namespace std;
using namespace math;

int main()
{
    int r = 3, c = 3;
    int k = 0;

    math::matrix <int> m1(r,c);
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            m1[i][j] = ++k;
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            cout << m1[i][j] << " ";
        }
        cout << endl;
    }

    char * buffer = (char*) m1.to_buffer();
    for(int i = 0; i < r*c*4; ++i)
        cout << (int)buffer[i] << " ";
}
