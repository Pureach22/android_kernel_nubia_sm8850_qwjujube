__int64 __fastcall adreno_coresight_disable(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x22
  unsigned int v4; // w23

  v1 = *(_QWORD *)(a1 + 208);
  v3 = *(_QWORD *)(v1 + 8);
  v2 = *(_QWORD *)(v1 + 16);
  rt_mutex_lock(v2 + 11088);
  if ( *(_BYTE *)(v1 + 24) == 1 )
  {
    if ( !(unsigned int)adreno_active_count_get(v2) )
    {
      if ( *(_DWORD *)(v3 + 8) )
      {
        v4 = 0;
        do
          kgsl_regmap_write(v2 + 13200, 0, *(_DWORD *)(*(_QWORD *)v3 + 12LL * (int)v4++));
        while ( v4 < *(_DWORD *)(v3 + 8) );
      }
      adreno_active_count_put(v2);
    }
    *(_BYTE *)(v1 + 24) = 0;
  }
  return rt_mutex_unlock(v2 + 11088);
}
