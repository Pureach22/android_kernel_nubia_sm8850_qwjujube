__int64 __fastcall gen8_gmu_snapshot_dtcm(_QWORD *a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v6; // x8
  unsigned int v7; // w8
  __int64 v8; // x23
  __int64 v9; // x20

  if ( (unsigned __int64)*(unsigned int *)(a1[1028] + 52LL) + 28 <= a3 )
  {
    *(_QWORD *)(a2 + 4) = 0;
    *(_DWORD *)a2 = 5;
    v6 = *(unsigned int *)(a1[1028] + 48LL);
    *(_QWORD *)(a2 + 20) = 0;
    *(_QWORD *)(a2 + 12) = v6;
    kgsl_regmap_write(a1 + 1650, 2148532224LL);
    v7 = *(_DWORD *)(a1[1028] + 52LL);
    if ( v7 >= 4 )
    {
      v8 = 0;
      v9 = a2 + 28;
      do
      {
        *(_DWORD *)(v9 + 4 * v8++) = kgsl_regmap_read(a1 + 1650);
        v7 = *(_DWORD *)(a1[1028] + 52LL);
      }
      while ( (unsigned int)v8 < v7 >> 2 );
    }
    return v7 + 28LL;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen8_gmu_snapshot_dtcm__rs, "gen8_gmu_snapshot_dtcm") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "GMU DTCM Memory");
    return 0;
  }
}
