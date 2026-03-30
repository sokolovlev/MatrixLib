#include "library.h"


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

        __m128i simd_vec_1 = _mm_load_si128((__m128i*)first.vec);
        __m128i simd_vec_2 = _mm_load_si128((__m128i*)second.vec);
        __m128i simd_vec_res = _mm_add_epi32(simd_vec_1,simd_vec_2);
        _mm_store_si128((__m128i*)res.vec,simd_vec_res);

        return res;
    }

    VectorClass operator-(const VectorClass& first, const VectorClass& second)
    {
        VectorClass res;

        __m128i simd_vec_1 = _mm_load_si128((__m128i*)first.vec);
        __m128i simd_vec_2 = _mm_load_si128((__m128i*)second.vec);
        __m128i simd_vec_res = _mm_sub_epi32(simd_vec_1,simd_vec_2);
        _mm_store_si128((__m128i*)res.vec,simd_vec_res);

        return res;
    }

    VectorClass operator*(const VectorClass& first, const int& num)
    {
        VectorClass res;

        __m128i simd_vec = _mm_load_si128((__m128i*)first.vec);
        __m128i scalar_vec = _mm_set1_epi32(num);
        __m128i vec_res = _mm_mullo_epi32(simd_vec,scalar_vec);
        _mm_store_si128((__m128i*)res.vec,vec_res);

        return res;
    }

    VectorClass operator*(const int& num, const VectorClass& second)
    {
        VectorClass res;

        __m128i scalar_vec = _mm_set1_epi32(num);
        __m128i simd_vec = _mm_load_si128((__m128i*)second.vec);
        __m128i vec_res = _mm_mullo_epi32(scalar_vec,simd_vec);
        _mm_store_si128((__m128i*)res.vec,vec_res);

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
