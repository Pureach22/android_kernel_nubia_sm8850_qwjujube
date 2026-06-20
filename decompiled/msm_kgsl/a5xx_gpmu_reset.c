__int64 __fastcall a5xx_gpmu_reset(__int64 result)
{
  __int64 v1; // x19
  int v2; // w8

  if ( (*(_QWORD *)(result - 6360) & 0x800) == 0 )
  {
    v1 = result;
    v2 = *(_DWORD *)(result - 9480);
    if ( v2 == 32 || v2 == 2 )
    {
      rt_mutex_lock(result - 9512);
      if ( !(unsigned int)a5xx_regulator_enable((_QWORD *)(v1 - 20600)) )
      {
        kgsl_regmap_write(v1 - 7400, 0x10000);
        if ( (*(_BYTE *)(*(_QWORD *)(v1 - 6336) + 32LL) & 2) == 0 )
          kgsl_regmap_write(v1 - 7400, 0);
        a5xx_gpmu_init(v1 - 20600);
      }
      return rt_mutex_unlock(v1 - 9512);
    }
  }
  return result;
}
