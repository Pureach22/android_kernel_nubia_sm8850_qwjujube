__int64 __fastcall adreno_coresight_enable(__int64 a1)
{
  __int64 v1; // x22
  __int64 v2; // x19
  __int64 v3; // x20
  unsigned int v4; // w8
  __int64 v5; // x10
  unsigned int v6; // w20
  __int64 v7; // x20
  unsigned int v8; // w22

  v1 = *(_QWORD *)(a1 + 208);
  v3 = *(_QWORD *)(v1 + 8);
  v2 = *(_QWORD *)(v1 + 16);
  rt_mutex_lock(v2 + 11088);
  if ( (*(_BYTE *)(v1 + 24) & 1) != 0 )
  {
LABEL_13:
    v6 = 0;
    goto LABEL_14;
  }
  *(_BYTE *)(v1 + 24) = 1;
  if ( *(_DWORD *)(v3 + 8) )
  {
    v4 = 0;
    do
    {
      v5 = *(_QWORD *)v3 + 12LL * (int)v4++;
      *(_DWORD *)(v5 + 8) = *(_DWORD *)(v5 + 4);
    }
    while ( v4 < *(_DWORD *)(v3 + 8) );
  }
  v6 = adreno_active_count_get(v2);
  if ( !v6 )
  {
    if ( *(_QWORD *)v1 )
    {
      if ( *(_QWORD *)v1 <= 0xFFFFFFFFFFFFF000LL && *(_BYTE *)(v1 + 24) == 1 )
      {
        v7 = *(_QWORD *)(v1 + 8);
        if ( *(_DWORD *)(v7 + 8) )
        {
          v8 = 0;
          do
          {
            kgsl_regmap_write(
              v2 + 13200,
              *(_DWORD *)(*(_QWORD *)v7 + 12LL * (int)v8 + 8),
              *(_DWORD *)(*(_QWORD *)v7 + 12LL * (int)v8));
            ++v8;
          }
          while ( v8 < *(_DWORD *)(v7 + 8) );
        }
      }
    }
    adreno_active_count_put(v2);
    goto LABEL_13;
  }
LABEL_14:
  rt_mutex_unlock(v2 + 11088);
  return v6;
}
