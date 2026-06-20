__int64 __fastcall gen7_host_aperture_set(__int64 result, char a2)
{
  unsigned int v2; // w19
  __int64 v3; // x21

  v2 = (a2 & 3) << 12;
  if ( *(_DWORD *)(result + 24544) != v2 )
  {
    v3 = result;
    result = kgsl_regmap_write(result + 13200, v2);
    __dsb(0xFu);
    *(_DWORD *)(v3 + 24544) = v2;
  }
  return result;
}
