__int64 __fastcall gen7_gmu_itcm_shadow(__int64 a1)
{
  __int64 *v1; // x20
  __int64 v4; // x2
  unsigned int v5; // w20
  __int64 v6; // x22

  v1 = (__int64 *)(a1 - 688);
  if ( !*(_QWORD *)(a1 - 688) )
  {
    v4 = vzalloc_noprof(*(unsigned int *)(*(_QWORD *)(a1 + 8224) + 4LL));
    *v1 = v4;
    if ( !v4 )
      return 4294967284LL;
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 8224) + 4LL) >= 4u )
    {
      v5 = 0;
      do
      {
        v6 = v4 + 4;
        gmu_core_regread(a1, v5 + 111616, v4);
        ++v5;
        v4 = v6;
      }
      while ( v5 < *(_DWORD *)(*(_QWORD *)(a1 + 8224) + 4LL) >> 2 );
    }
  }
  return 0;
}
