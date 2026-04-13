#ifndef MATRIXLIB_LIBRARY_H
#define MATRIXLIB_LIBRARY_H

#include <cstring>
#include <smmintrin.h>
#include <immintrin.h>
#include <initializer_list>

namespace MatrixLib
{
    class MatrixClass;

    class VectorClass
    {
        alignas(16) int vec[4] = {0};

    public:
        VectorClass() = default;
        VectorClass(const std::initializer_list<int>& array);
        VectorClass(const int *array);
        VectorClass(const VectorClass& array);

        VectorClass& operator=(const VectorClass& other);
        VectorClass& operator=(const int* other);

        friend VectorClass operator+(const VectorClass& first, const VectorClass& second);
        friend VectorClass operator+(const VectorClass& first, const int* second);
        friend VectorClass operator+(const int* first, const VectorClass& second);

        friend VectorClass operator-(const VectorClass& first, const VectorClass& second);
        friend VectorClass operator-(const VectorClass& first, const int* second);
        friend VectorClass operator-(const int* first, const VectorClass& second);

        friend VectorClass operator*(const VectorClass& first, const int& num);
        friend VectorClass operator*(const int& num, const VectorClass& second);
        friend VectorClass operator*(const VectorClass& first, const VectorClass& second);

        friend int dot(const VectorClass& first,const VectorClass& second);
        friend int dot(const int* first, const VectorClass& second);
        friend int dot(const VectorClass& first,const int* second);

        friend VectorClass operator/(const VectorClass& first,const int& num);

        friend VectorClass operator*(const MatrixClass& mtrx,const VectorClass& vec);
    };

    int dot(const VectorClass& first, const VectorClass& second);
    int dot(const int* first, const VectorClass& second);
    int dot(const VectorClass& first,const int* second);

    VectorClass operator*(const MatrixClass& mtrx,const VectorClass& vec);

    class MatrixClass
    {
        alignas(32) int mtrx[4][4] = {0};

    public:
        MatrixClass() = default;
        MatrixClass(const std::initializer_list<std::initializer_list<int>>& matrix);
        MatrixClass(const std::initializer_list<int>& matrix);
        MatrixClass(const int *matrix);
        MatrixClass(const MatrixClass& matrix);

        MatrixClass& operator=(const int* matrix);
        MatrixClass& operator=(const MatrixClass& matrix);

        friend MatrixClass operator+(const MatrixClass& first, const MatrixClass& second);
        friend MatrixClass operator+(const MatrixClass& first, const int& num);
        friend MatrixClass operator+(const int& num, const MatrixClass& second);

        friend MatrixClass operator-(const MatrixClass& first, const MatrixClass& second);
        friend MatrixClass operator-(const MatrixClass& first, const int& num);
        friend MatrixClass operator-(const int& num, const MatrixClass& second);

        friend MatrixClass operator*(const MatrixClass& first,const MatrixClass& second);

        friend VectorClass operator*(const MatrixClass& mtrx,const VectorClass& vec);

    };

}

#endif // MATRIXLIB_LIBRARY_H