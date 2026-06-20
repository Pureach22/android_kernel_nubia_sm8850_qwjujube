__int64 __fastcall gen8_periph_regread(__int64 a1, __int64 a2, _DWORD *a3, char a4)
{
  unsigned int v4; // w21
  unsigned int v7; // w23
  __int64 result; // x0

  v4 = (a4 & 0xF) << 12;
  if ( *(_DWORD *)(a1 + 24544) != v4 )
  {
    v7 = a2;
    kgsl_regmap_write(a1 + 13200, v4);
    __dsb(0xFu);
    a2 = v7;
    *(_DWORD *)(a1 + 24544) = v4;
  }
  kgsl_regmap_write(a1 + 13200, a2);
  __dsb(0xFu);
  result = kgsl_regmap_read(a1 + 13200);
  *a3 = result;
  return result;
}
