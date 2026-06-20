bool __fastcall a5xx_hw_isidle(__int64 a1)
{
  if ( **(_DWORD **)(a1 + 14264) == 540 )
    _const_udelay(21475);
  return (unsigned int)kgsl_regmap_read(a1 + 13200) <= 1
      && (*(_DWORD *)(a1 + 20888) & (unsigned int)kgsl_regmap_read(a1 + 13200)) == 0
      && *(_DWORD *)(a1 + 20416) == 0;
}
