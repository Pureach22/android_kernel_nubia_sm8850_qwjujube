__int64 __fastcall a6xx_gmu_snapshot_dtcm(_QWORD *a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v5; // x8
  unsigned int v6; // w8
  unsigned int v7; // w20
  __int64 v8; // x2
  __int64 v9; // x22

  if ( (unsigned __int64)*(unsigned int *)(a1[1028] + 52LL) + 28 <= a3 )
  {
    *(_QWORD *)(a2 + 4) = 0;
    *(_DWORD *)a2 = 5;
    v5 = *(unsigned int *)(a1[1028] + 48LL);
    *(_QWORD *)(a2 + 20) = 0;
    *(_QWORD *)(a2 + 12) = v5;
    v6 = *(_DWORD *)(a1[1028] + 52LL);
    if ( v6 >= 4 )
    {
      v7 = 0;
      v8 = a2 + 28;
      do
      {
        v9 = v8 + 4;
        gmu_core_regread(a1, v7 + 115712, v8);
        ++v7;
        v8 = v9;
        v6 = *(_DWORD *)(a1[1028] + 52LL);
      }
      while ( v7 < v6 >> 2 );
    }
    return v6 + 28LL;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&a6xx_gmu_snapshot_dtcm__rs, "a6xx_gmu_snapshot_dtcm") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "GMU DTCM Memory");
    return 0;
  }
}
