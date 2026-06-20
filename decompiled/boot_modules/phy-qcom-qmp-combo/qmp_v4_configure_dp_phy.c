__int64 __fastcall qmp_v4_configure_dp_phy(__int64 a1)
{
  __int64 v2; // x23
  int v3; // w21
  int v4; // w9
  _BOOL4 v5; // w8
  _BOOL4 v6; // w11
  unsigned int v7; // w20
  int v8; // w9
  unsigned int v9; // w0
  int v10; // w9
  __int64 result; // x0
  unsigned int v12; // w0
  __int64 v13; // x20
  __int64 v14; // x0
  __int64 v15; // x20
  __int64 v16; // x0
  __int64 v17; // x20
  __int64 v18; // x20
  __int64 v19; // x0
  __int64 v20; // x20
  __int64 v21; // x20
  __int64 v22; // x0
  __int64 v23; // x20
  __int64 v24; // x0
  __int64 v25; // x20
  __int64 v26; // x0
  __int64 v27; // x20
  __int64 v28; // x20
  __int64 v29; // x0
  __int64 v30; // x20
  int v31; // w9
  int v32; // w13
  int v33; // w11
  int v34; // w14
  int v35; // w12
  unsigned int v36; // w21
  unsigned int v37; // w0
  unsigned int v38; // w20
  unsigned int v39; // w22
  bool v40; // zf
  __int64 v41; // x0
  __int64 v42; // x20
  __int64 v43; // x0
  __int64 v44; // x20

  v2 = *(_QWORD *)(a1 + 8);
  v3 = *(_DWORD *)(a1 + 456);
  writel(0xFu, (unsigned int *)(*(_QWORD *)(a1 + 120) + 20LL));
  v4 = *(_DWORD *)(a1 + 456);
  v5 = *(_DWORD *)(a1 + 304) == 4;
  v6 = v4 == 2 || *(_DWORD *)(a1 + 304) == 4;
  if ( v4 == 2 )
  {
    v7 = 76;
  }
  else
  {
    v5 = 1;
    v7 = 92;
  }
  if ( v6 )
    v8 = 125;
  else
    v8 = 117;
  if ( v5 )
    v9 = v8;
  else
    v9 = 109;
  writel(v9, (unsigned int *)(*(_QWORD *)(a1 + 120) + 24LL));
  writel(v7, (unsigned int *)(*(_QWORD *)(a1 + 120) + 28LL));
  writel(0x13u, (unsigned int *)(*(_QWORD *)(a1 + 120) + 36LL));
  writel(0xA4u, (unsigned int *)(*(_QWORD *)(a1 + 120) + 40LL));
  writel(5u, (unsigned int *)(*(_QWORD *)(a1 + 120) + 120LL));
  writel(5u, (unsigned int *)(*(_QWORD *)(a1 + 120) + 156LL));
  v10 = *(_DWORD *)(a1 + 300);
  result = 4294967274LL;
  if ( v10 > 5399 )
  {
    if ( v10 == 5400 )
    {
      v12 = 2;
    }
    else
    {
      if ( v10 != 8100 )
        return result;
      v12 = 0;
    }
    goto LABEL_22;
  }
  if ( v10 != 1620 )
  {
    if ( v10 != 2700 )
      return result;
    v12 = 1;
LABEL_22:
    v13 = 1350000000;
    goto LABEL_23;
  }
  v12 = 1;
  v13 = 810000000;
LABEL_23:
  writel(
    v12,
    (unsigned int *)(*(_QWORD *)(a1 + 120) + *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 280LL) + 48LL)));
  clk_set_rate(*(_QWORD *)(a1 + 408), (unsigned int)(100000 * *(_DWORD *)(a1 + 300)));
  clk_set_rate(*(_QWORD *)(a1 + 432), v13);
  writel(1u, (unsigned int *)(*(_QWORD *)(a1 + 120) + 16LL));
  writel(5u, (unsigned int *)(*(_QWORD *)(a1 + 120) + 16LL));
  writel(1u, (unsigned int *)(*(_QWORD *)(a1 + 120) + 16LL));
  writel(9u, (unsigned int *)(*(_QWORD *)(a1 + 120) + 16LL));
  v14 = writel(0x20u, (unsigned int *)(*(_QWORD *)(a1 + 96) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 28LL)));
  v15 = ktime_get(v14);
  v16 = readl((unsigned int *)(*(_QWORD *)(a1 + 96) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 32LL)));
  if ( (v16 & 1) == 0 )
  {
    v17 = v15 + 10000000;
    while ( ktime_get(v16) <= v17 )
    {
      usleep_range_state(126, 500, 2);
      __yield();
      v16 = readl((unsigned int *)(*(_QWORD *)(a1 + 96) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 32LL)));
      if ( (v16 & 1) != 0 )
        goto LABEL_29;
    }
    v16 = readl((unsigned int *)(*(_QWORD *)(a1 + 96) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 32LL)));
    if ( (v16 & 1) == 0 )
      return 4294967186LL;
  }
LABEL_29:
  v18 = ktime_get(v16);
  v19 = readl((unsigned int *)(*(_QWORD *)(a1 + 96) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 36LL)));
  if ( (v19 & 1) == 0 )
  {
    v20 = v18 + 10000000;
    while ( ktime_get(v19) <= v20 )
    {
      usleep_range_state(126, 500, 2);
      __yield();
      v19 = readl((unsigned int *)(*(_QWORD *)(a1 + 96) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 36LL)));
      if ( (v19 & 1) != 0 )
        goto LABEL_35;
    }
    v19 = readl((unsigned int *)(*(_QWORD *)(a1 + 96) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 36LL)));
    if ( (v19 & 1) == 0 )
      return 4294967186LL;
  }
LABEL_35:
  v21 = ktime_get(v19);
  v22 = readl((unsigned int *)(*(_QWORD *)(a1 + 96) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 36LL)));
  if ( (v22 & 2) == 0 )
  {
    v23 = v21 + 10000000;
    while ( ktime_get(v22) <= v23 )
    {
      usleep_range_state(126, 500, 2);
      __yield();
      v22 = readl((unsigned int *)(*(_QWORD *)(a1 + 96) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 36LL)));
      if ( (v22 & 2) != 0 )
        goto LABEL_41;
    }
    if ( (readl((unsigned int *)(*(_QWORD *)(a1 + 96) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 36LL))) & 2) == 0 )
      return 4294967186LL;
  }
LABEL_41:
  v24 = writel(0x19u, (unsigned int *)(*(_QWORD *)(a1 + 120) + 16LL));
  v25 = ktime_get(v24);
  v26 = readl((unsigned int *)(*(_QWORD *)(a1 + 120) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 44LL)));
  if ( (v26 & 1) == 0 )
  {
    v27 = v25 + 10000000;
    while ( ktime_get(v26) <= v27 )
    {
      usleep_range_state(126, 500, 2);
      __yield();
      v26 = readl((unsigned int *)(*(_QWORD *)(a1 + 120) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 44LL)));
      if ( (v26 & 1) != 0 )
        goto LABEL_47;
    }
    v26 = readl((unsigned int *)(*(_QWORD *)(a1 + 120) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 44LL)));
    if ( (v26 & 1) == 0 )
      return 4294967186LL;
  }
LABEL_47:
  v28 = ktime_get(v26);
  v29 = readl((unsigned int *)(*(_QWORD *)(a1 + 120) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 44LL)));
  if ( (v29 & 2) == 0 )
  {
    v30 = v28 + 10000000;
    while ( ktime_get(v29) <= v30 )
    {
      usleep_range_state(126, 500, 2);
      __yield();
      v29 = readl((unsigned int *)(*(_QWORD *)(a1 + 120) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 44LL)));
      if ( (v29 & 2) != 0 )
        goto LABEL_53;
    }
    if ( (readl((unsigned int *)(*(_QWORD *)(a1 + 120) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 44LL))) & 2) == 0 )
      return 4294967186LL;
  }
LABEL_53:
  v31 = *(_DWORD *)(a1 + 304);
  if ( v31 == 2 )
  {
    v40 = v3 == 2;
    v37 = 16;
    if ( v3 == 2 )
      v36 = 63;
    else
      v36 = 21;
    if ( v40 )
      v38 = 21;
    else
      v38 = 63;
    v39 = 16;
  }
  else
  {
    if ( v3 == 2 )
      v32 = 62;
    else
      v32 = 21;
    if ( v3 == 2 )
      v33 = 21;
    else
      v33 = 62;
    if ( v3 == 2 )
      v34 = 19;
    else
      v34 = 16;
    if ( v3 == 2 )
      v35 = 16;
    else
      v35 = 19;
    if ( v31 == 1 )
      v36 = v32;
    else
      v36 = 63;
    if ( v31 == 1 )
      v37 = v34;
    else
      v37 = 16;
    if ( v31 == 1 )
      v38 = v33;
    else
      v38 = 63;
    if ( v31 == 1 )
      v39 = v35;
    else
      v39 = 16;
  }
  writel(v37, (unsigned int *)(*(_QWORD *)(a1 + 104) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 64LL)));
  writel(v36, (unsigned int *)(*(_QWORD *)(a1 + 104) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 68LL)));
  writel(v39, (unsigned int *)(*(_QWORD *)(a1 + 112) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 64LL)));
  writel(v38, (unsigned int *)(*(_QWORD *)(a1 + 112) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 68LL)));
  writel(0x18u, (unsigned int *)(*(_QWORD *)(a1 + 120) + 16LL));
  _const_udelay(8590000);
  v41 = writel(0x19u, (unsigned int *)(*(_QWORD *)(a1 + 120) + 16LL));
  v42 = ktime_get(v41);
  v43 = readl((unsigned int *)(*(_QWORD *)(a1 + 120) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 44LL)));
  if ( (v43 & 2) == 0 )
  {
    v44 = v42 + 10000000;
    while ( ktime_get(v43) <= v44 )
    {
      usleep_range_state(126, 500, 2);
      __yield();
      v43 = readl((unsigned int *)(*(_QWORD *)(a1 + 120) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 44LL)));
      if ( (v43 & 2) != 0 )
        goto LABEL_92;
    }
    if ( (readl((unsigned int *)(*(_QWORD *)(a1 + 120) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 44LL))) & 2) == 0 )
      return 4294967186LL;
  }
LABEL_92:
  writel(0xAu, (unsigned int *)(*(_QWORD *)(a1 + 104) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 52LL)));
  writel(0xAu, (unsigned int *)(*(_QWORD *)(a1 + 112) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 52LL)));
  writel(0x27u, (unsigned int *)(*(_QWORD *)(a1 + 104) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 56LL)));
  writel(0x27u, (unsigned int *)(*(_QWORD *)(a1 + 112) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 56LL)));
  writel(0x20u, (unsigned int *)(*(_QWORD *)(a1 + 104) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 60LL)));
  writel(0x20u, (unsigned int *)(*(_QWORD *)(a1 + 112) + *(unsigned int *)(*(_QWORD *)(v2 + 280) + 60LL)));
  return 0;
}
