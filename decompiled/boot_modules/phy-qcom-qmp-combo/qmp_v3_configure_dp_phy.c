__int64 __fastcall qmp_v3_configure_dp_phy(__int64 a1)
{
  int v1; // w10
  __int64 v3; // x21
  _BOOL4 v4; // w9
  _BOOL4 v5; // w11
  unsigned int v6; // w20
  bool v7; // zf
  __int64 v8; // x11
  unsigned int v9; // w8
  __int64 v10; // x0
  int v11; // w9
  __int64 result; // x0
  __int64 v13; // x0
  __int64 v14; // x20
  __int64 v15; // x0
  __int64 v16; // x20
  __int64 v17; // x0
  __int64 v18; // x20
  __int64 v19; // x0
  __int64 v20; // x20
  __int64 v21; // x0
  __int64 v22; // x20
  __int64 v23; // x0
  __int64 v24; // x20
  __int64 v25; // x0
  __int64 v26; // x20

  v1 = *(_DWORD *)(a1 + 456);
  v3 = *(_QWORD *)(a1 + 8);
  v4 = *(_DWORD *)(a1 + 304) == 4;
  v5 = v1 == 2 || *(_DWORD *)(a1 + 304) == 4;
  if ( v1 == 2 )
  {
    v6 = 76;
  }
  else
  {
    v4 = 1;
    v6 = 92;
  }
  v7 = !v5;
  v8 = *(_QWORD *)(a1 + 120);
  if ( v7 )
    v9 = 117;
  else
    v9 = 125;
  if ( v4 )
    v10 = v9;
  else
    v10 = 109;
  writel(v10, v8 + 24);
  writel(v6, *(_QWORD *)(a1 + 120) + 28LL);
  writel(5, *(_QWORD *)(a1 + 120) + 108LL);
  writel(5, *(_QWORD *)(a1 + 120) + 136LL);
  v11 = *(_DWORD *)(a1 + 300);
  result = 4294967274LL;
  if ( v11 > 5399 )
  {
    if ( v11 == 5400 )
    {
      v13 = 2;
    }
    else
    {
      if ( v11 != 8100 )
        return result;
      v13 = 0;
    }
    goto LABEL_22;
  }
  if ( v11 != 1620 )
  {
    if ( v11 != 2700 )
      return result;
    v13 = 1;
LABEL_22:
    v14 = 1350000000;
    goto LABEL_23;
  }
  v13 = 1;
  v14 = 810000000;
LABEL_23:
  writel(v13, *(_QWORD *)(a1 + 120) + *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 280LL) + 48LL));
  clk_set_rate(*(_QWORD *)(a1 + 408), (unsigned int)(100000 * *(_DWORD *)(a1 + 300)));
  clk_set_rate(*(_QWORD *)(a1 + 432), v14);
  writel(4, *(_QWORD *)(a1 + 120) + 40LL);
  writel(1, *(_QWORD *)(a1 + 120) + 16LL);
  writel(5, *(_QWORD *)(a1 + 120) + 16LL);
  writel(1, *(_QWORD *)(a1 + 120) + 16LL);
  writel(9, *(_QWORD *)(a1 + 120) + 16LL);
  v15 = writel(32, *(_QWORD *)(a1 + 96) + *(unsigned int *)(*(_QWORD *)(v3 + 280) + 28LL));
  v16 = ktime_get(v15);
  v17 = readl(*(_QWORD *)(a1 + 96) + *(unsigned int *)(*(_QWORD *)(v3 + 280) + 32LL));
  if ( (v17 & 1) == 0 )
  {
    v18 = v16 + 10000000;
    while ( ktime_get(v17) <= v18 )
    {
      usleep_range_state(126, 500, 2);
      __yield();
      v17 = readl(*(_QWORD *)(a1 + 96) + *(unsigned int *)(*(_QWORD *)(v3 + 280) + 32LL));
      if ( (v17 & 1) != 0 )
        goto LABEL_29;
    }
    if ( (readl(*(_QWORD *)(a1 + 96) + *(unsigned int *)(*(_QWORD *)(v3 + 280) + 32LL)) & 1) == 0 )
      return 4294967186LL;
  }
LABEL_29:
  v19 = writel(25, *(_QWORD *)(a1 + 120) + 16LL);
  v20 = ktime_get(v19);
  v21 = readl(*(_QWORD *)(a1 + 120) + *(unsigned int *)(*(_QWORD *)(v3 + 280) + 44LL));
  if ( (v21 & 2) == 0 )
  {
    v22 = v20 + 10000000;
    while ( ktime_get(v21) <= v22 )
    {
      usleep_range_state(126, 500, 2);
      __yield();
      v21 = readl(*(_QWORD *)(a1 + 120) + *(unsigned int *)(*(_QWORD *)(v3 + 280) + 44LL));
      if ( (v21 & 2) != 0 )
        goto LABEL_36;
    }
    if ( (readl(*(_QWORD *)(a1 + 120) + *(unsigned int *)(*(_QWORD *)(v3 + 280) + 44LL)) & 2) == 0 )
      return 4294967186LL;
  }
LABEL_36:
  writel(24, *(_QWORD *)(a1 + 120) + 16LL);
  _const_udelay(8590000);
  v23 = writel(25, *(_QWORD *)(a1 + 120) + 16LL);
  v24 = ktime_get(v23);
  v25 = readl(*(_QWORD *)(a1 + 120) + *(unsigned int *)(*(_QWORD *)(v3 + 280) + 44LL));
  if ( (v25 & 2) != 0 )
    return 0;
  v26 = v24 + 10000000;
  while ( ktime_get(v25) <= v26 )
  {
    usleep_range_state(126, 500, 2);
    __yield();
    v25 = readl(*(_QWORD *)(a1 + 120) + *(unsigned int *)(*(_QWORD *)(v3 + 280) + 44LL));
    if ( (v25 & 2) != 0 )
      return 0;
  }
  if ( (readl(*(_QWORD *)(a1 + 120) + *(unsigned int *)(*(_QWORD *)(v3 + 280) + 44LL)) & 2) != 0 )
    return 0;
  else
    return 4294967186LL;
}
