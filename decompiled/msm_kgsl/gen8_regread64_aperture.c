__int64 __fastcall gen8_regread64_aperture(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int64 *a4,
        char a5,
        char a6,
        char a7)
{
  unsigned int v9; // w22
  unsigned int v10; // w22
  __int64 result; // x0

  v9 = ((a5 & 0xF) << 12) | ((a6 & 7) << 16) & 0xFF7FFFFF | ((a7 & 1) << 23);
  if ( *(_DWORD *)(a1 + 24544) != v9 )
  {
    kgsl_regmap_write(a1 + 13200, v9);
    __dsb(0xFu);
    *(_DWORD *)(a1 + 24544) = v9;
  }
  v10 = kgsl_regmap_read(a1 + 13200);
  result = kgsl_regmap_read(a1 + 13200);
  *a4 = v10 | (unsigned __int64)(result << 32);
  return result;
}
