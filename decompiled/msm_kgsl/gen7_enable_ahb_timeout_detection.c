__int64 __fastcall gen7_enable_ahb_timeout_detection(__int64 result)
{
  unsigned int v1; // w19
  __int64 v2; // x21

  if ( *(_DWORD *)(result + 24048) )
  {
    v1 = *(_DWORD *)(result + 24048) & 0x1F | 0x1B00;
    v2 = result;
    kgsl_regmap_write(result + 13200, v1);
    kgsl_regmap_write(v2 + 13200, v1);
    kgsl_regmap_write(v2 + 13200, v1);
    kgsl_regmap_write(v2 + 13200, v1);
    return kgsl_regmap_write(v2 + 13200, v1);
  }
  return result;
}
