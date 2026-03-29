#ifndef MATRIXLIB_LIBRARY_H
#define MATRIXLIB_LIBRARY_H

#include <cstring>

namespace MatrixLib
{

    class VectorClass
    {
        int vec[4] = {0};

    public:
        VectorClass(const int *array);
        VectorClass();
        VectorClass& operator=(const VectorClass& other);

        friend VectorClass operator+(const VectorClass& first, const VectorClass& second);
        friend VectorClass operator-(const VectorClass& first, const VectorClass& second);

        friend VectorClass operator*(const VectorClass& first, const int& num);
        friend VectorClass operator*(const int& num, const VectorClass& second);

        friend VectorClass operator/(const VectorClass& first,const int& num);
    };

    class Matrix
    {
        int mtrx[][]

    };

}

#endif // MATRIXLIB_LIBRARY_H