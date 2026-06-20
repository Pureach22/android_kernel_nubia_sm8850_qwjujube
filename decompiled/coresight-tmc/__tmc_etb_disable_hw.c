__int64 __fastcall _tmc_etb_disable_hw(__int64 a1)
{
  __int64 v2; // x8
  char v3; // w0
  __int64 v4; // x8
  _DWORD *v5; // x21
  char v6; // w20
  unsigned int *v7; // x0
  int v8; // w0
  _QWORD *v9; // x8
  __int64 v10; // x9

  writel_relaxed_0(3316436565LL, *(_QWORD *)(a1 + 8) + 4016LL);
  __dsb(0xFu);
  if ( (readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 8) + 32LL)) & 1) != 0 )
  {
    tmc_flush_and_stop(a1);
    tmc_disable_stop_on_flush(a1);
    if ( (unsigned int)*(_QWORD *)(*(_QWORD *)(a1 + 16) + 968LL) == 1 )
    {
      v3 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(a1 + 8) + 12LL));
      v4 = *(_QWORD *)(a1 + 8);
      v5 = *(_DWORD **)(a1 + 120);
      v6 = v3;
      *(_DWORD *)(a1 + 128) = 0;
      v7 = (unsigned int *)(v4 + 16);
      while ( 1 )
      {
        v8 = readl_relaxed_0(v7);
        if ( v8 == -1 )
          break;
        *v5++ = v8;
        v7 = (unsigned int *)(*(_QWORD *)(a1 + 8) + 16LL);
        *(_DWORD *)(a1 + 128) += 4;
      }
      if ( (v6 & 1) != 0 )
      {
        v9 = *(_QWORD **)(a1 + 120);
        if ( v9 )
        {
          v10 = coresight_barrier_pkt[1];
          *v9 = coresight_barrier_pkt[0];
          v9[1] = v10;
        }
      }
    }
    tmc_disable_hw(a1);
    v2 = *(_QWORD *)(a1 + 8);
    __dsb(0xFu);
  }
  else
  {
    v2 = *(_QWORD *)(a1 + 8);
    __dsb(0xFu);
  }
  return writel_relaxed_0(0, v2 + 4016);
}
