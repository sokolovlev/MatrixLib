WARNING: For stable working, USE compilation flag -msse4.1 (or /arch:AVX  if you are using MSVC)  FOR compile static MathLib
It is important because MathLib need "_mm_extract_epi32" from <smmintrin.h>
