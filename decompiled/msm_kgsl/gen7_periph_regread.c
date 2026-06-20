__int64 __fastcall gen7_periph_regread(__int64 result, __int64 a2, _DWORD *a3, int a4)
{
  __int64 v5; // x22

  if ( (unsigned int)(a4 - 1) <= 2 )
  {
    v5 = result;
    kgsl_regmap_write(result + 13200, a2);
    __dsb(0xFu);
    result = kgsl_regmap_read(v5 + 13200);
    *a3 = result;
  }
  return result;
}
