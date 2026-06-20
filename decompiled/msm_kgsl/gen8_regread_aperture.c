__int64 __fastcall gen8_regread_aperture(__int64 a1, __int64 a2, _DWORD *a3, char a4, char a5, char a6)
{
  unsigned int v8; // w21
  __int64 result; // x0

  v8 = ((a4 & 0xF) << 12) | ((a5 & 7) << 16) & 0xFF7FFFFF | ((a6 & 1) << 23);
  if ( *(_DWORD *)(a1 + 24544) != v8 )
  {
    kgsl_regmap_write(a1 + 13200, v8);
    __dsb(0xFu);
    *(_DWORD *)(a1 + 24544) = v8;
  }
  result = kgsl_regmap_read(a1 + 13200);
  *a3 = result;
  return result;
}
