#include <immintrin.h>
#include <stdio.h>

int main() {
    __m128 v128f1 = _mm_set_ps(1.0f, 2.0f, 3.0f, 4.0f);
    __m128 v128f2 = _mm_set1_ps(10.0f);
    __m128 v128f_add = _mm_add_ps(v128f1, v128f2);
    __m128 v128f_mul = _mm_mul_ps(v128f1, v128f2);

    float out128[4];
    _mm_storeu_ps(out128, v128f_add);
    printf("v128f add: ");
    for (int i = 0; i < 4; i++) printf("%.0f ", out128[i]);
    printf("\n");

    _mm_storeu_ps(out128, v128f_mul);
    printf("v128f mul: ");
    for(int i = 0; i < 4; i++) printf("%.0f ", out128[i]);
    printf("\n");

    __m256 v256f1 = _mm256_set_ps(1,2,3,4,5,6,7,8);      
    __m256 v256f2 = _mm256_set1_ps(10.0f);              
    __m256 v256f_add = _mm256_add_ps(v256f1, v256f2);    
    __m256 v256f_mul = _mm256_mul_ps(v256f1, v256f2);    

    float out256[8];
    _mm256_storeu_ps(out256, v256f_add);
    printf("v256f add: ");
    for(int i = 0; i < 8; i++) printf("%.0f ", out256[i]);
    printf("\n");

    _mm256_storeu_ps(out256, v256f_mul);
    printf("v256f mul: ");
    for(int i = 0; i < 8; i++) printf("%.0f ", out256[i]);
    printf("\n");

    __m512 v512f1 = _mm512_set_ps(
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
    );
    __m512 v512f2 = _mm512_set1_ps(10.0f);
    __m512 v512f_add = _mm512_add_ps(v512f1, v512f2);
    __m512 v512f_mul = _mm512_mul_ps(v512f1, v512f2);

    float out512[16];
    _mm512_storeu_ps(out512, v512f_add);
    printf("v512f add: ");
    for(int i = 0; i < 16; i++) printf("%.0f ", out512[i]);
    printf("\n");

    _mm512_storeu_ps(out512, v512f_mul);
    printf("v512f mul: ");
    for(int i = 0; i < 16; i++) printf("%.0f ", out512[i]);
    printf("\n");

    return 0;
}