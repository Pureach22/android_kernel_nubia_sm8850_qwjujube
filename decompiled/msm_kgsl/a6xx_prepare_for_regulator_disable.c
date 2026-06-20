__int64 __fastcall a6xx_prepare_for_regulator_disable(__int64 result)
{
  if ( **(_DWORD **)(result + 14264) == 611 )
  {
    kgsl_regmap_write(result + 13200, 1);
    __dsb(0xEu);
    return _const_udelay(429500);
  }
  return result;
}
