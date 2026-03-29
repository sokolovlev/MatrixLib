#include "library.h"

#include <iostream>

namespace MatrixLib
{
    VectorClass::VectorClass(const int *array)
    {
        memcpy(vec,array,4 * sizeof(int));
    }

    VectorClass& VectorClass::operator=(const VectorClass& other)
    {
        memcpy(vec,other.vec,4 * sizeof(int));
        return *this;
    }

    VectorClass operator+(const VectorClass& first, const VectorClass& second)
    {
        VectorClass res;
        memcpy(res.vec,first.vec,4 * sizeof(int));

        res.vec[0] += second.vec[0];
        res.vec[1] += second.vec[1];
        res.vec[2] += second.vec[2];
        res.vec[3] += second.vec[3];

        return res;
    }

    VectorClass operator-(const VectorClass& first, const VectorClass& second)
    {
        VectorClass res;
        memcpy(res.vec,first.vec,4 * sizeof(int));

        res.vec[0] -= second.vec[0];
        res.vec[1] -= second.vec[1];
        res.vec[2] -= second.vec[2];
        res.vec[3] -= second.vec[3];

        return res;
    }

    VectorClass operator*(const VectorClass& first, const int& num)
    {
        VectorClass res;
        memcpy(res.vec,first.vec,4 * sizeof(int));

        res.vec[0] *= num;
        res.vec[1] *= num;
        res.vec[2] *= num;
        res.vec[3] *= num;

        return res;
    }

    VectorClass operator*(const int& num, const VectorClass& second)
    {
        VectorClass res;
        memcpy(res.vec,second.vec, 4 * sizeof(int));

        res.vec[0] *= num;
        res.vec[1] *= num;
        res.vec[2] *= num;
        res.vec[3] *= num;

        return res;
    }

    VectorClass operator/(const VectorClass& first,const int& num)
    {
        VectorClass res;
        memcpy(res.vec,first.vec, 4 * sizeof(int));

        res.vec[0] /= num;
        res.vec[1] /= num;
        res.vec[2] /= num;
        res.vec[3] /= num;

        return res;
    }



}

#endif // MATRIXLIB_LIBRARY_H