bool __fastcall a5xx_is_hw_collapsible(__int64 a1)
{
  if ( (adreno_isidle(a1) & 1) == 0 )
    return 0;
  if ( *(_BYTE *)(a1 + 20436) == 1 )
  {
    if ( (kgsl_regmap_read(a1 + 13200) & 0x100000) == 0 )
      return (kgsl_regmap_read(a1 + 13200) & 0x100000) == 0;
    return 0;
  }
  return 1;
}
