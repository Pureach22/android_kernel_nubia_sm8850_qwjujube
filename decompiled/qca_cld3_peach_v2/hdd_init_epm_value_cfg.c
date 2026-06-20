__int64 __fastcall hdd_init_epm_value_cfg(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  __int64 v13; // x21

  result = (__int64)_cds_get_context(54, (__int64)"hdd_init_epm_value_cfg", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v13 = result;
    result = wma_is_epm_supported_cfg();
    if ( (result & 1) != 0 )
    {
      result = wma_is_epm_supported_fw(v13);
      if ( (result & 1) != 0 )
      {
        result = cfg_psoc_get_values(a2);
        *(_QWORD *)(a1 + 184) = *(unsigned int *)(result + 4004);
      }
    }
  }
  return result;
}
