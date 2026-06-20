__int64 __fastcall gen8_gmu_snapshot_itcm(__int64 a1, __int64 a2, unsigned __int64 a3, __int64 a4)
{
  __int64 v6; // x8

  if ( *(_QWORD *)(a4 + 1032) )
  {
    if ( (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 8224) + 4LL) + 28 <= a3 )
    {
      *(_QWORD *)(a2 + 4) = 0;
      *(_DWORD *)a2 = 5;
      v6 = **(unsigned int **)(a1 + 8224);
      *(_QWORD *)(a2 + 20) = 0;
      *(_QWORD *)(a2 + 12) = v6;
      memcpy((void *)(a2 + 28), *(const void **)(a4 + 1032), *(unsigned int *)(*(_QWORD *)(a1 + 8224) + 4LL));
      return *(unsigned int *)(*(_QWORD *)(a1 + 8224) + 4LL) + 28LL;
    }
    else
    {
      if ( (unsigned int)__ratelimit(&gen8_gmu_snapshot_itcm__rs, "gen8_gmu_snapshot_itcm") )
        dev_err(*(_QWORD *)a1, "snapshot: not enough snapshot memory for section %s\n", "GMU ITCM Memory");
      return 0;
    }
  }
  else
  {
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "No memory allocated for ITCM shadow capture\n");
    return 0;
  }
}
