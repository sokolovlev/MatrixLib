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

        _mm256_store_si256((__m256i*)res.mtrx[0],res01);
        _mm256_store_si256((__m256i*)res.mtrx[2],res23);

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
        _mm256_store_si256((__m256i*)res.mtrx[2],res23);

        return res;
    }

    MatrixClass operator*(const MatrixClass& first,const MatrixClass& second)
    {
        MatrixClass res;

        __m256i first01 = _mm256_load_si256((__m256i*)&first.mtrx[0]);
        __m256i first23 = _mm256_load_si256((__m256i*)&first.mtrx[2]);

        __m256i second01 = _mm256_load_si256((__m256i*)&second.mtrx[0]);
        __m256i second23 = _mm256_load_si256((__m256i*)&second.mtrx[2]);

        __m256i tmp0 = _mm256_unpacklo_epi32(second01, second23);
        __m256i tmp1 = _mm256_unpackhi_epi32(second01, second23);
        __m256i col01 = _mm256_permute4x64_epi64(tmp0, 0b11011000);
        __m256i col23 = _mm256_permute4x64_epi64(tmp1, 0b11011000);

        __m256i row0_perm = _mm256_permute4x64_epi64(first01, 0b00000000);
        __m256i row1_perm = _mm256_permute4x64_epi64(first01, 0b01010101);
        __m256i row2_perm = _mm256_permute4x64_epi64(first23, 0b00000000);
        __m256i row3_perm = _mm256_permute4x64_epi64(first23, 0b01010101);

        __m256i res0 = _mm256_mullo_epi32(row0_perm, col01);
        __m256i res1 = _mm256_mullo_epi32(row1_perm, col01);
        __m256i res2 = _mm256_mullo_epi32(row2_perm, col01);
        __m256i res3 = _mm256_mullo_epi32(row3_perm, col01);

        __m256i row0_perm2 = _mm256_permute4x64_epi64(first01, 0b10101010);
        __m256i row1_perm2 = _mm256_permute4x64_epi64(first01, 0b11111111);
        __m256i row2_perm2 = _mm256_permute4x64_epi64(first23, 0b10101010);
        __m256i row3_perm2 = _mm256_permute4x64_epi64(first23, 0b11111111);

        res0 = _mm256_add_epi32(res0, _mm256_mullo_epi32(row0_perm2, col23));
        res1 = _mm256_add_epi32(res1, _mm256_mullo_epi32(row1_perm2, col23));
        res2 = _mm256_add_epi32(res2, _mm256_mullo_epi32(row2_perm2, col23));
        res3 = _mm256_add_epi32(res3, _mm256_mullo_epi32(row3_perm2, col23));

        __m128i r0 = _mm_add_epi32(_mm256_castsi256_si128(res0), _mm256_extracti128_si256(res0, 1));
        __m128i r1 = _mm_add_epi32(_mm256_castsi256_si128(res1), _mm256_extracti128_si256(res1, 1));
        __m128i r2 = _mm_add_epi32(_mm256_castsi256_si128(res2), _mm256_extracti128_si256(res2, 1));
        __m128i r3 = _mm_add_epi32(_mm256_castsi256_si128(res3), _mm256_extracti128_si256(res3, 1));

        r0 = _mm_add_epi32(r0, _mm_srli_si128(r0, 8));
        r0 = _mm_add_epi32(r0, _mm_srli_si128(r0, 4));
        r1 = _mm_add_epi32(r1, _mm_srli_si128(r1, 8));
        r1 = _mm_add_epi32(r1, _mm_srli_si128(r1, 4));
        r2 = _mm_add_epi32(r2, _mm_srli_si128(r2, 8));
        r2 = _mm_add_epi32(r2, _mm_srli_si128(r2, 4));
        r3 = _mm_add_epi32(r3, _mm_srli_si128(r3, 8));
        r3 = _mm_add_epi32(r3, _mm_srli_si128(r3, 4));

        __m256i res01 = _mm256_set_m128i(r1, r0);
        __m256i res23 = _mm256_set_m128i(r3, r2);

        _mm256_store_si256((__m256i*)res.mtrx[0],res01);
        _mm256_store_si256((__m256i*)res.mtrx[2],res23);

        return res;
    }

    VectorClass operator*(const MatrixClass& matrix,const VectorClass& vector)
    {
        VectorClass res;

        __m256i mtrx01 = _mm256_load_si256((__m256i*)matrix.mtrx[0]);
        __m256i mtrx23 = _mm256_load_si256((__m256i*)matrix.mtrx[2]);

        __m128i data = _mm_load_si128((__m128i*)vector.vec);
        __m256i vec = _mm256_broadcastsi128_si256(data);

        __m256i res0 = _mm256_mullo_epi32(mtrx01,vec);
        __m256i res1 = _mm256_mullo_epi32(mtrx23,vec);

        __m256i sum0 = _mm256_hadd_epi32(res0,res0);
        __m256i sum1 = _mm256_hadd_epi32(sum0,sum0);
        __m128i row0 = _mm256_castsi256_si128(sum1);
        __m128i row1 = _mm256_extracti128_si256(sum1, 1);

        sum0 = _mm256_hadd_epi32(res1,res1);
        sum1 = _mm256_hadd_epi32(sum0,sum0);
        __m128i row2 = _mm256_castsi256_si128(sum1);
        __m128i row3 = _mm256_extracti128_si256(sum1, 1);

        __m128i result = _mm_blend_epi32(row0, row1, 0b0010);
        result = _mm_blend_epi32(result, row2, 0b0100);
        result = _mm_blend_epi32(result, row3, 0b1000);

        _mm_store_si128((__m128i*)res.vec, result);
        return res;
    }

}
