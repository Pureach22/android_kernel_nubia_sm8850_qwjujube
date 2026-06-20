__int64 __fastcall gen8_periph_regread64(__int64 a1, __int64 a2, unsigned int a3, unsigned __int64 *a4, char a5)
{
  unsigned int v5; // w22
  unsigned int v9; // w23
  unsigned int v10; // w23
  __int64 result; // x0

  v5 = (a5 & 0xF) << 12;
  if ( *(_DWORD *)(a1 + 24544) != v5 )
  {
    v9 = a2;
    kgsl_regmap_write(a1 + 13200, v5);
    __dsb(0xFu);
    a2 = v9;
    *(_DWORD *)(a1 + 24544) = v5;
  }
  kgsl_regmap_write(a1 + 13200, a2);
  __dsb(0xFu);
  v10 = kgsl_regmap_read(a1 + 13200);
  if ( *(_DWORD *)(a1 + 24544) != v5 )
  {
    kgsl_regmap_write(a1 + 13200, v5);
    __dsb(0xFu);
    *(_DWORD *)(a1 + 24544) = v5;
  }
  kgsl_regmap_write(a1 + 13200, a3);
  __dsb(0xFu);
  result = kgsl_regmap_read(a1 + 13200);
  *a4 = v10 | (unsigned __int64)(result << 32);
  return result;
}
