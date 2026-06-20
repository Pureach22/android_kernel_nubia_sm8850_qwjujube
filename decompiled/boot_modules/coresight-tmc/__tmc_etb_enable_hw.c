__int64 __fastcall _tmc_etb_enable_hw(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v3; // w19
  __int64 v4; // x0
  __int64 v5; // x8

  writel_relaxed_0(3316436565LL, *(_QWORD *)(a1 + 8) + 4016LL);
  __dsb(0xFu);
  v2 = tmc_wait_for_tmcready(a1);
  v3 = v2;
  if ( (_DWORD)v2 )
  {
    dev_err(*(_QWORD *)(a1 + 16) + 56LL, "Failed to enable: TMC not ready\n");
    v5 = *(_QWORD *)(a1 + 8);
    __dsb(0xFu);
  }
  else
  {
    writel_relaxed_0(v2, *(_QWORD *)(a1 + 8) + 40LL);
    if ( *(_BYTE *)(a1 + 344) )
      v4 = 4403;
    else
      v4 = 307;
    writel_relaxed_0(v4, *(_QWORD *)(a1 + 8) + 772LL);
    writel_relaxed_0(*(unsigned int *)(a1 + 200), *(_QWORD *)(a1 + 8) + 28LL);
    tmc_enable_hw(a1);
    v5 = *(_QWORD *)(a1 + 8);
    __dsb(0xFu);
  }
  writel_relaxed_0(0, v5 + 4016);
  return v3;
}
