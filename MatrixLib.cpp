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

    MatrixClass::MatrixClass(const std::initializer_list<std::initializer_list<int>>& matrix)
    {
        memcpy(&mtrx,matrix.begin() -> begin(),16 * sizeof(int));
    }

    MatrixClass::MatrixClass(const std::initializer_list<int>& matrix)
    {
        memcpy(&mtrx,matrix.begin(),16 * sizeof(int));
    }

    MatrixClass::MatrixClass(const int *matrix)
    {
        memcpy(mtrx,matrix,16 * sizeof(int));
    }

    MatrixClass::MatrixClass(const MatrixClass& matrix)
    {
        memcpy(&mtrx,matrix.mtrx,16 * sizeof(int));
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

        __m256i mtrx0_str01 = _mm256_load_si256((__m256i*)first.mtrx[0]);
        __m256i mtrx0_str23 = _mm256_load_si256((__m256i*)first.mtrx[2]);

        __m256i mtrx1_str01 = _mm256_load_si256((__m256i*)second.mtrx[0]);
        __m256i mtrx1_str23 = _mm256_load_si256((__m256i*)second.mtrx[2]);

        __m256i res01 = _mm256_add_epi32(mtrx0_str01,mtrx1_str01);
        __m256i res23 = _mm256_add_epi32(mtrx0_str23,mtrx1_str23);

        _mm256_store_si256((__m256i*)res.mtrx[0],res01);
        _mm256_store_si256((__m256i*)res.mtrx[2],res23);

        return res;
    }

    MatrixClass operator+(const MatrixClass& first, const int& num)
    {
        MatrixClass res;

        __m256i str01 = _mm256_load_si256((__m256i*)first.mtrx[0]);
        __m256i str23 = _mm256_load_si256((__m256i*)first.mtrx[2]);

        __m256i scalar = _mm256_set1_epi32(num);

        __m256i res01 = _mm256_add_epi32(str01,scalar);
        __m256i res23 = _mm256_add_epi32(str23,scalar);

        _mm256_store_si256((__m256i*)res.mtrx[0],res01);
        _mm256_store_si256((__m256i*)res.mtrx[2],res23);

        return res;
    }

    MatrixClass operator+(const int& num, const MatrixClass& second)
    {
        MatrixClass res;

        __m256i str01 = _mm256_load_si256((__m256i*)second.mtrx[0]);
        __m256i str23 = _mm256_load_si256((__m256i*)second.mtrx[0]);

        __m256i scalar = _mm256_set1_epi32(num);

        __m256i res01 = _mm256_add_epi32(str01,scalar);
        __m256i res23 = _mm256_add_epi32(str23,scalar);

        _mm256_store_si256((__m256i*)res.mtrx[0],res01);
        _mm256_store_si256((__m256i*)res.mtrx[0],res23);

        return res;
    }

    MatrixClass operator-(const MatrixClass& first, const MatrixClass& second)
    {
        MatrixClass res;

        __m256i mtrx0_str01 = _mm256_load_si256((__m256i*)first.mtrx[0]);
        __m256i mtrx0_str23 = _mm256_load_si256((__m256i*)first.mtrx[2]);

        __m256i mtrx1_str01 = _mm256_load_si256((__m256i*)second.mtrx[0]);
        __m256i mtrx1_str23 = _mm256_load_si256((__m256i*)second.mtrx[2]);

        __m256i res01 = _mm256_sub_epi32(mtrx0_str01,mtrx1_str01);
        __m256i res23 = _mm256_sub_epi32(mtrx0_str23,mtrx1_str23);

        _mm256_store_epi32((__m256i*)res.mtrx[0],res01);
        _mm256_store_epi32((__m256i*)res.mtrx[2],res23);

        return res;
    }

    MatrixClass operator-(const MatrixClass& first, const int& num)
    {
        MatrixClass res;

        __m256i str01 = _mm256_load_si256((__m256i*)first.mtrx[0]);
        __m256i str23 = _mm256_load_si256((__m256i*)first.mtrx[2]);

        __m256i scalar = _mm256_set1_epi32(num);

        __m256i res01 = _mm256_sub_epi32(str01,scalar);
        __m256i res23 = _mm256_sub_epi32(str23,scalar);

        _mm256_store_si256((__m256i*)res.mtrx[0],res01);
        _mm256_store_si256((__m256i*)res.mtrx[2],res23);

        return res;
    }

    MatrixClass operator-(const int& num, const MatrixClass& second)
    {
        MatrixClass res;

        __m256i str01 = _mm256_load_si256((__m256i*)second.mtrx[0]);
        __m256i str23 = _mm256_load_si256((__m256i*)second.mtrx[2]);

        __m256i scalar = _mm256_set1_epi32(num);

        __m256i res01 = _mm256_sub_epi32(str01,scalar);
        __m256i res23 = _mm256_sub_epi32(str23,scalar);

        _mm256_store_si256((__m256i*)res.mtrx[0],res01);
        _mm256_store_si256((__m256i*)res.mtrx[0],res23);

        return res;
    }

    MatrixClass operator*(const MatrixClass& first,const MatrixClass& second)
    {
        MatrixClass res;

        __m256i mtrx1_str01 = _mm256_load_si256((__m256i*)&first.mtrx[0]);
        __m256i mtrx1_str23 = _mm256_load_si256((__m256i*)&first.mtrx[2]);

        __m256i mtrx2_str01 = _mm256_load_si256((__m256i*)&second.mtrx[0]);
        __m256i mtrx2_str23 = _mm256_load_si256((__m256i*)&second.mtrx[2]);

        __m256i tmp0 = _mm256_unpacklo_epi32(mtrx2_str01,mtrx2_str23);
        __m256i tmp1 = _mm256_unpackhi_epi32(mtrx2_str01,mtrx2_str23);

        __m256i mtrx2t_str01 = _mm256_permute4x64_epi64(tmp0,0b11011000);
        __m256i mtrx2t_str23 = _mm256_permute4x64_epi64(tmp1,0b11011000);

        //__m256i res_str01 = _mm256_add_epi32(first_str_01,second_column_01);
        //__m256i res_str23 = _mm256_add_epi32(first_str_23,second_column_23);

        //_mm256_store_si256((__m256i*)&res.mtrx[0],res_str01);
        //_mm256_store_si256((__m256i*)&res.mtrx[2],res_str23);

        return res;
    }

}
