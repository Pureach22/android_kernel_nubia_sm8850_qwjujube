__int64 __fastcall tmc_etr_get_buffer(__int64 a1, int a2, __int64 a3)
{
  __int64 result; // x0
  __int64 aux; // x0
  __int64 v5; // x8

  if ( a2 != 2 )
  {
    if ( a2 == 1 )
      return tmc_etr_get_sysfs_buffer();
    return -22;
  }
  aux = perf_get_aux(a3);
  if ( !aux || (v5 = *(_QWORD *)(aux + 48)) == 0 || (result = *(_QWORD *)(v5 + 8)) == 0 )
  {
    __break(0x800u);
    return -22;
  }
  return result;
}
