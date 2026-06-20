__int64 __fastcall a6xx_clear_pending_transactions(__int64 a1)
{
  __int64 result; // x0

  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a1 + 11168) + 760LL)) )
  {
    kgsl_regmap_write(a1 + 13200, 480);
    result = adreno_wait_for_halt_ack(a1, 533, 240);
    if ( (_DWORD)result )
      return result;
    return a6xx_halt_gbif(a1);
  }
  kgsl_regmap_write(a1 + 13200, 1);
  result = adreno_wait_for_halt_ack(a1, 23, 1);
  if ( !(_DWORD)result )
    return a6xx_halt_gbif(a1);
  return result;
}
