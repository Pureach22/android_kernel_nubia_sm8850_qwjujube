__int64 __fastcall gen7_gmu_snapshot_dtcm(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v5; // x20
  __int64 v6; // x8
  unsigned int v7; // w8
  unsigned int v8; // w8
  unsigned __int64 v9; // t2
  unsigned int v10; // w8
  __int64 v11; // x23
  unsigned int v12; // w21

  if ( (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 8224) + 52LL) + 28 <= a3 )
  {
    *(_QWORD *)(a2 + 4) = 0;
    v5 = a2 + 28;
    *(_DWORD *)a2 = 5;
    v6 = *(unsigned int *)(*(_QWORD *)(a1 + 8224) + 48LL);
    *(_QWORD *)(a2 + 20) = 0;
    *(_QWORD *)(a2 + 12) = v6;
    v7 = **(_DWORD **)(a1 + 14264);
    if ( v7 - 459264 < 2
      || v7 == 460288
      || v7 >> 1 == 230528
      || (HIDWORD(v9) = v7 - 461568, LODWORD(v9) = v7 - 461568, v8 = v9 >> 8, v8 <= 6) && ((1 << v8) & 0x59) != 0 )
    {
      kgsl_regmap_write(a1 + 13200, 2148532224LL);
      v10 = *(_DWORD *)(*(_QWORD *)(a1 + 8224) + 52LL);
      if ( v10 >= 4 )
      {
        v11 = 0;
        do
        {
          *(_DWORD *)(v5 + 4 * v11++) = kgsl_regmap_read(a1 + 13200);
          v10 = *(_DWORD *)(*(_QWORD *)(a1 + 8224) + 52LL);
        }
        while ( (unsigned int)v11 < v10 >> 2 );
      }
    }
    else
    {
      v10 = *(_DWORD *)(*(_QWORD *)(a1 + 8224) + 52LL);
      if ( v10 >= 4 )
      {
        v12 = 0;
        do
        {
          gmu_core_regread(a1, v12 + 115712, v5);
          ++v12;
          v5 += 4;
          v10 = *(_DWORD *)(*(_QWORD *)(a1 + 8224) + 52LL);
        }
        while ( v12 < v10 >> 2 );
      }
    }
    return v10 + 28LL;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen7_gmu_snapshot_dtcm__rs, "gen7_gmu_snapshot_dtcm") )
      dev_err(*(_QWORD *)a1, "snapshot: not enough snapshot memory for section %s\n", "GMU DTCM Memory");
    return 0;
  }
}
