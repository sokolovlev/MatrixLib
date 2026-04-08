#include "MatrixLib.h"


namespace MatrixLib
{
    VectorClass::VectorClass(const std::initializer_list<int>& array)
    {
        memcpy(vec,array.begin(),4 * sizeof(int));
    }

    VectorClass::VectorClass(const int *newVector)
    {
        memcpy(vec,newVector,4 * sizeof(int));
    }

    VectorClass::VectorClass(const VectorClass& newVector)
    {
        memcpy(vec,newVector.vec,4 * sizeof(int));
    }

    VectorClass& VectorClass::operator=(const int* newVector)
    {
        memcpy(vec,newVector,4 * sizeof(int));
        return *this;
    }

    VectorClass& VectorClass::operator=(const VectorClass& newVector)
    {
        memcpy(vec,newVector.vec,4 * sizeof(int));
        return *this;
    }

    VectorClass operator+(const VectorClass& first, const VectorClass& second)
    {
        VectorClass res;

        __m128i vec1 = _mm_load_si128((__m128i*)first.vec);
        __m128i vec2 = _mm_load_si128((__m128i*)second.vec);
        __m128i vec_res = _mm_add_epi32(vec1,vec2);
        _mm_store_si128((__m128i*)res.vec,vec_res);

        return res;
    }

    VectorClass operator+(const VectorClass& first, const int* second)
    {
        VectorClass res;

        __m128i vec1 = _mm_load_si128((__m128i*)first.vec);
        __m128i vec2 = _mm_load_si128((__m128i*)second);
        __m128i vec_res = _mm_add_epi32(vec1,vec2);
        _mm_store_si128((__m128i*)res.vec,vec_res);

        return res;
    }

    VectorClass operator+(const int* first,const VectorClass& second)
    {
        VectorClass res;

        __m128i vec1 = _mm_load_si128((__m128i*)first);
        __m128i vec2 = _mm_load_si128((__m128i*)second.vec);
        __m128i vec_res = _mm_add_epi32(vec1,vec2);
        _mm_store_si128((__m128i*)res.vec,vec_res);

        return res;
    }

    VectorClass operator-(const VectorClass& first, const VectorClass& second)
    {
        VectorClass res;

        __m128i vec1 = _mm_load_si128((__m128i*)first.vec);
        __m128i vec2 = _mm_load_si128((__m128i*)second.vec);
        __m128i vec_res = _mm_sub_epi32(vec1,vec2);
        _mm_store_si128((__m128i*)res.vec,vec_res);

        return res;
    }

    VectorClass operator-(const VectorClass& first, const int* second)
    {
        VectorClass res;

        __m128i vec1 = _mm_load_si128((__m128i*)first.vec);
        __m128i vec2 = _mm_load_si128((__m128i*)second);
        __m128i vec_res = _mm_sub_epi32(vec1,vec2);
        _mm_store_si128((__m128i*)res.vec,vec_res);

        return res;
    }

    VectorClass operator-(const int* first,const VectorClass& second)
    {
        VectorClass res;

        __m128i vec1 = _mm_load_si128((__m128i*)first);
        __m128i vec2 = _mm_load_si128((__m128i*)second.vec);
        __m128i vec_res = _mm_sub_epi32(vec1,vec2);
        _mm_store_si128((__m128i*)res.vec,vec_res);

        return res;
    }

    VectorClass operator*(const VectorClass& first, const int& num)
    {
        VectorClass res;

        __m128i vec1 = _mm_load_si128((__m128i*)first.vec);
        __m128i vec2 = _mm_set1_epi32(num);
        __m128i vec_res = _mm_mullo_epi32(vec1,vec2);
        _mm_store_si128((__m128i*)res.vec,vec_res);

        return res;
    }

    VectorClass operator*(const int& num, const VectorClass& second)
    {
        VectorClass res;

        __m128i vec1 = _mm_set1_epi32(num);
        __m128i vec2 = _mm_load_si128((__m128i*)second.vec);
        __m128i vec_res = _mm_mullo_epi32(vec1,vec2);
        _mm_store_si128((__m128i*)res.vec,vec_res);

        return res;
    }

    VectorClass operator*(const VectorClass& first, const VectorClass& second)
    {
        VectorClass res;

        __m128i vec_1 = _mm_load_si128((__m128i*)first.vec);
        __m128i vec_2 = _mm_load_si128((__m128i*)second.vec);
        __m128i vec_res = _mm_mullo_epi32(vec_1,vec_2);
        _mm_store_si128((__m128i*)res.vec,vec_res);

        return res;
    };

    int dot(const VectorClass& first, const int* second)
    {
        VectorClass res;

        __m128i vec1 = _mm_load_si128((__m128i*)first.vec);
        __m128i vec2 = _mm_load_si128((__m128i*)second);
        __m128i vec_res = _mm_mullo_epi32(vec1,vec2);

        int a = _mm_extract_epi32(vec_res,0);      //-msse4.1
        int b = _mm_extract_epi32(vec_res,1);
        int c = _mm_extract_epi32(vec_res,2);

        return a + b + c;
    }

    int dot(const int* first, const VectorClass& second)
    {
        VectorClass res;

        __m128i vec1 = _mm_load_si128((__m128i*)first);
        __m128i vec2 = _mm_load_si128((__m128i*)second.vec);
        __m128i vec_res = _mm_mullo_epi32(vec1,vec2);

        int a = _mm_extract_epi32(vec_res,0);      //-msse4.1
        int b = _mm_extract_epi32(vec_res,1);
        int c = _mm_extract_epi32(vec_res,2);

        return a + b + c;
    }

    int dot(const VectorClass& first,const VectorClass& second)
    {
        __m128i vec_1 = _mm_load_si128((__m128i*)first.vec);
        __m128i vec_2 = _mm_load_si128((__m128i*)second.vec);
        __m128i vec_res = _mm_mullo_epi32(vec_1,vec_2);    //

        int a = _mm_extract_epi32(vec_res,0);      //-msse4.1
        int b = _mm_extract_epi32(vec_res,1);
        int c = _mm_extract_epi32(vec_res,2);

        return a + b + c;
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

    MatrixClass& MatrixClass::operator=(const int* matrix)
    {
        memcpy(mtrx,matrix,16 * sizeof(int));
        return *this;
    }

    MatrixClass& MatrixClass::operator=(const MatrixClass& matrix)
    {
        memcpy(mtrx,matrix.mtrx,16 * sizeof(int));
        return *this;
    }

    MatrixClass operator+(const MatrixClass& first, const MatrixClass& second)
    {
        MatrixClass res;

        __m128i mtrx_0_str_0 = _mm_load_si128((__m128i*)first.mtrx[0]);
        __m128i mtrx_0_str_1 = _mm_load_si128((__m128i*)first.mtrx[1]);
        __m128i mtrx_0_str_2 = _mm_load_si128((__m128i*)first.mtrx[2]);
        __m128i mtrx_0_str_3 = _mm_load_si128((__m128i*)first.mtrx[3]);

        __m128i mtrx_1_str_0 = _mm_load_si128((__m128i*)second.mtrx[0]);
        __m128i mtrx_1_str_1 = _mm_load_si128((__m128i*)second.mtrx[1]);
        __m128i mtrx_1_str_2 = _mm_load_si128((__m128i*)second.mtrx[2]);
        __m128i mtrx_1_str_3 = _mm_load_si128((__m128i*)second.mtrx[3]);

        __m128i mtrx_res_str_0 = _mm_add_epi32(mtrx_0_str_0,mtrx_1_str_0);
        __m128i mtrx_res_str_1 = _mm_add_epi32(mtrx_0_str_1,mtrx_1_str_1);
        __m128i mtrx_res_str_2 = _mm_add_epi32(mtrx_0_str_2,mtrx_1_str_2);
        __m128i mtrx_res_str_3 = _mm_add_epi32(mtrx_0_str_3,mtrx_1_str_3);

        _mm_store_si128((__m128i*)res.mtrx[0],mtrx_res_str_0);
        _mm_store_si128((__m128i*)res.mtrx[1],mtrx_res_str_1);
        _mm_store_si128((__m128i*)res.mtrx[2],mtrx_res_str_2);
        _mm_store_si128((__m128i*)res.mtrx[3],mtrx_res_str_3);

        return res;
    }

    MatrixClass operator+(const MatrixClass& first, const int& num)
    {
        MatrixClass res;

        __m128i str_0 = _mm_load_si128((__m128i*)first.mtrx[0]);
        __m128i str_1 = _mm_load_si128((__m128i*)first.mtrx[1]);
        __m128i str_2 = _mm_load_si128((__m128i*)first.mtrx[2]);
        __m128i str_3 = _mm_load_si128((__m128i*)first.mtrx[3]);

        __m128i scalar = _mm_set1_epi32(num);

        __m128i res_str_0 = _mm_add_epi32(str_0,scalar);
        __m128i res_str_1 = _mm_add_epi32(str_1,scalar);
        __m128i res_str_2 = _mm_add_epi32(str_2,scalar);
        __m128i res_str_3 = _mm_add_epi32(str_3,scalar);

        _mm_store_si128((__m128i*)res.mtrx[0],res_str_0);
        _mm_store_si128((__m128i*)res.mtrx[1],res_str_1);
        _mm_store_si128((__m128i*)res.mtrx[2],res_str_2);
        _mm_store_si128((__m128i*)res.mtrx[3],res_str_3);

        return res;
    }

    MatrixClass operator+(const int& num, const MatrixClass& second)
    {
        MatrixClass res;

        __m128i str_0 = _mm_load_si128((__m128i*)second.mtrx[0]);
        __m128i str_1 = _mm_load_si128((__m128i*)second.mtrx[1]);
        __m128i str_2 = _mm_load_si128((__m128i*)second.mtrx[2]);
        __m128i str_3 = _mm_load_si128((__m128i*)second.mtrx[3]);

        __m128i scalar = _mm_set1_epi32(num);

        __m128i res_str_0 = _mm_add_epi32(str_0,scalar);
        __m128i res_str_1 = _mm_add_epi32(str_1,scalar);
        __m128i res_str_2 = _mm_add_epi32(str_2,scalar);
        __m128i res_str_3 = _mm_add_epi32(str_3,scalar);

        _mm_store_si128((__m128i*)res.mtrx[0],res_str_0);
        _mm_store_si128((__m128i*)res.mtrx[1],res_str_1);
        _mm_store_si128((__m128i*)res.mtrx[2],res_str_2);
        _mm_store_si128((__m128i*)res.mtrx[3],res_str_3);

        return res;
    }

    MatrixClass operator-(const MatrixClass& first, const MatrixClass& second)
    {
        MatrixClass res;

        __m128i mtrx_0_str_0 = _mm_load_si128((__m128i*)first.mtrx[0]);
        __m128i mtrx_0_str_1 = _mm_load_si128((__m128i*)first.mtrx[1]);
        __m128i mtrx_0_str_2 = _mm_load_si128((__m128i*)first.mtrx[2]);
        __m128i mtrx_0_str_3 = _mm_load_si128((__m128i*)first.mtrx[3]);

        __m128i mtrx_1_str_0 = _mm_load_si128((__m128i*)second.mtrx[0]);
        __m128i mtrx_1_str_1 = _mm_load_si128((__m128i*)second.mtrx[1]);
        __m128i mtrx_1_str_2 = _mm_load_si128((__m128i*)second.mtrx[2]);
        __m128i mtrx_1_str_3 = _mm_load_si128((__m128i*)second.mtrx[3]);

        __m128i mtrx_res_str_0 = _mm_sub_epi32(mtrx_0_str_0,mtrx_1_str_0);
        __m128i mtrx_res_str_1 = _mm_sub_epi32(mtrx_0_str_1,mtrx_1_str_1);
        __m128i mtrx_res_str_2 = _mm_sub_epi32(mtrx_0_str_2,mtrx_1_str_2);
        __m128i mtrx_res_str_3 = _mm_sub_epi32(mtrx_0_str_3,mtrx_1_str_3);

        _mm_store_si128((__m128i*)res.mtrx[0],mtrx_res_str_0);
        _mm_store_si128((__m128i*)res.mtrx[1],mtrx_res_str_1);
        _mm_store_si128((__m128i*)res.mtrx[2],mtrx_res_str_2);
        _mm_store_si128((__m128i*)res.mtrx[3],mtrx_res_str_3);

        return res;
    }

    MatrixClass operator-(const MatrixClass& first, const int& num)
    {
        MatrixClass res;

        __m128i str_0 = _mm_load_si128((__m128i*)first.mtrx[0]);
        __m128i str_1 = _mm_load_si128((__m128i*)first.mtrx[1]);
        __m128i str_2 = _mm_load_si128((__m128i*)first.mtrx[2]);
        __m128i str_3 = _mm_load_si128((__m128i*)first.mtrx[3]);

        __m128i scalar = _mm_set1_epi32(num);

        __m128i res_str_0 = _mm_sub_epi32(str_0,scalar);
        __m128i res_str_1 = _mm_sub_epi32(str_1,scalar);
        __m128i res_str_2 = _mm_sub_epi32(str_2,scalar);
        __m128i res_str_3 = _mm_sub_epi32(str_3,scalar);

        _mm_store_si128((__m128i*)res.mtrx[0],res_str_0);
        _mm_store_si128((__m128i*)res.mtrx[1],res_str_1);
        _mm_store_si128((__m128i*)res.mtrx[2],res_str_2);
        _mm_store_si128((__m128i*)res.mtrx[3],res_str_3);

        return res;
    }

    MatrixClass operator-(const int& num, const MatrixClass& second)
    {
        MatrixClass res;

        __m128i str_0 = _mm_load_si128((__m128i*)second.mtrx[0]);
        __m128i str_1 = _mm_load_si128((__m128i*)second.mtrx[1]);
        __m128i str_2 = _mm_load_si128((__m128i*)second.mtrx[2]);
        __m128i str_3 = _mm_load_si128((__m128i*)second.mtrx[3]);

        __m128i scalar = _mm_set1_epi32(num);

        __m128i res_str_0 = _mm_sub_epi32(str_0,scalar);
        __m128i res_str_1 = _mm_sub_epi32(str_1,scalar);
        __m128i res_str_2 = _mm_sub_epi32(str_2,scalar);
        __m128i res_str_3 = _mm_sub_epi32(str_3,scalar);

        _mm_store_si128((__m128i*)res.mtrx[0],res_str_0);
        _mm_store_si128((__m128i*)res.mtrx[1],res_str_1);
        _mm_store_si128((__m128i*)res.mtrx[2],res_str_2);
        _mm_store_si128((__m128i*)res.mtrx[3],res_str_3);

        return res;
    }

}
