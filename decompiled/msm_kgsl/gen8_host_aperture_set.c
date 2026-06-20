__int64 __fastcall gen8_host_aperture_set(__int64 result, char a2, char a3, char a4)
{
  unsigned int v4; // w19
  __int64 v5; // x21

  v4 = ((a2 & 0xF) << 12) | ((a3 & 7) << 16) & 0xFF7FFFFF | ((a4 & 1) << 23);
  if ( *(_DWORD *)(result + 24544) != v4 )
  {
    v5 = result;
    result = kgsl_regmap_write(result + 13200, v4);
    __dsb(0xFu);
    *(_DWORD *)(v5 + 24544) = v4;
  }
  return result;
}
