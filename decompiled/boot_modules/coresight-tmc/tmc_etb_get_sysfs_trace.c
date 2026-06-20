__int64 __fastcall tmc_etb_get_sysfs_trace(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v4; // x8
  __int64 v5; // x8

  v4 = *(unsigned int *)(a1 + 128);
  if ( a3 + a2 <= v4 )
    v5 = a3;
  else
    v5 = v4 - a2;
  if ( v5 >= 1 )
    *a4 = *(_QWORD *)(a1 + 120) + a2;
  return v5;
}
