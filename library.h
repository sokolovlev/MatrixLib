#ifndef MATRIXLIB_LIBRARY_H
#define MATRIXLIB_LIBRARY_H

#include <cstring>
#include <immintrin.h>

namespace MatrixLib
{

    class VectorClass
    {
        alignas(16) int vec[4] = {0};

    public:
        VectorClass() = default;
        explicit VectorClass(const int *array);
        VectorClass& operator=(const VectorClass& other);

        friend VectorClass operator+(const VectorClass& first, const VectorClass& second);
        friend VectorClass operator-(const VectorClass& first, const VectorClass& second);

        friend VectorClass operator*(const VectorClass& first, const int& num);
        friend VectorClass operator*(const int& num, const VectorClass& second);

        friend VectorClass operator*(const VectorClass& first, const VectorClass& second);

        friend VectorClass operator/(const VectorClass& first,const int& num);
    };

}

#endif // MATRIXLIB_LIBRARY_H