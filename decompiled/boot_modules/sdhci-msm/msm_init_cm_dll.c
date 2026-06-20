__int64 __fastcall msm_init_cm_dll(__int64 a1, int a2)
{
  __int64 v2; // x25
  unsigned int *v4; // x24
  int v6; // w26
  unsigned int v7; // w27
  __int64 v8; // x20
  __int64 rate; // x0
  __int64 v10; // x21
  int v11; // w0
  char v12; // w20
  int v13; // w0
  int v14; // w0
  int v15; // w0
  int v16; // w0
  __int64 v17; // x8
  unsigned int v18; // w23
  __int64 v19; // x8
  __int64 v20; // x9
  __int64 v21; // x8
  unsigned int v22; // w0
  __int64 v23; // x0
  char v24; // w8
  unsigned __int64 v25; // x8
  int v26; // w23
  int v27; // w0
  int v28; // w0
  int v29; // w0
  int v30; // w12
  int v31; // w8
  __int64 v32; // x21
  int v33; // w0
  int v34; // w0
  int v35; // w0
  int v36; // w0
  int v37; // w0
  int v38; // w0
  __int64 v39; // x21
  int v40; // w0
  int v41; // w22
  unsigned int v43; // w22
  int v44; // w0
  const char *v46; // x2
  __int64 v47; // x1

  v2 = *(_QWORD *)(a1 + 72);
  v4 = *(unsigned int **)(a1 + 1624);
  v6 = *(unsigned __int8 *)(v2 + 1056);
  if ( *(_DWORD *)(a1 + 820) >> 7 >= 0xC35u )
  {
    v8 = *(_QWORD *)(a1 + 1456);
    rate = clk_get_rate(v8);
    v7 = (unsigned int)clk_round_rate(v8, rate) >> (*(_QWORD *)(a1 + 1520) != *(unsigned int *)(a1 + 820));
  }
  else
  {
    v7 = 400000;
  }
  v10 = raw_spin_lock_irqsave(a1 + 792);
  v11 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[17]));
  v12 = v11;
  writel_relaxed(v11 & 0xFFFFFFFD, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[17]));
  if ( *(_BYTE *)(a1 + 1560) == 1 )
  {
    v13 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
    writel_relaxed(v13 & 0xFFFBFFFF, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
    v14 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[25]));
    writel_relaxed(v14 | 0x200000, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[25]));
  }
  v15 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
  writel_relaxed(v15 | 0x40000000, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
  v16 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
  writel_relaxed(v16 | 0x20000000, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
  if ( *(_BYTE *)(a1 + 2026) == 1 )
  {
    v17 = *(_QWORD *)(a1 + 2032);
    if ( v17 )
    {
      writel_relaxed(*(_DWORD *)(v17 + 8), (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[26]));
      v18 = *(_DWORD *)(*(_QWORD *)(a1 + 2032) + 12LL);
    }
    else
    {
      v18 = 738265088;
      writel_relaxed(0x10u, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[26]));
    }
    writel_relaxed(v18, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[29]));
  }
  v19 = 27;
  if ( *(_BYTE *)(a1 + 1640) )
    v19 = 28;
  v20 = *(_QWORD *)(a1 + 2032);
  v21 = v4[v19];
  if ( !v20 || (v22 = *(_DWORD *)(v20 + 16)) == 0 )
    v22 = -2147219341;
  writel_relaxed(v22, (unsigned int *)(*(_QWORD *)(a1 + 24) + v21));
  if ( *(_BYTE *)(a1 + 1560) == 1 )
  {
    if ( !a2 )
    {
      v23 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[25]));
      v24 = 2;
      if ( (v23 & 0x40000) != 0 )
        v24 = 3;
      v25 = (unsigned __int64)v7 << v24;
      if ( v25 % 0x124F800 <= 0x927BFF )
        v26 = v25 / 0x124F800;
      else
        v26 = v25 / 0x124F800 + 1;
      if ( v7 <= 0x5F5E0FF )
      {
        v47 = *(_QWORD *)(v2 + 120);
        if ( !v47 )
          v47 = *(_QWORD *)(v2 + 8);
        printk(&unk_109DD, v47);
      }
      v27 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[25]));
      writel_relaxed(v27 & 0xFFFC03FF | (v26 << 10), (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[25]));
    }
    if ( *(_BYTE *)(a1 + 2146) == 1 && (v6 == 6 || (*(_BYTE *)(v2 + 997) & 1) != 0) )
    {
      v28 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[25]));
      writel_relaxed(v28 | 0x80000, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[25]));
    }
    _const_udelay(21475);
  }
  if ( *(_QWORD *)(a1 + 2032) )
  {
    v29 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
    writel_relaxed(**(unsigned __int16 **)(a1 + 2032) | v29, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
  }
  if ( *(_BYTE *)(a1 + 2144) == 1 )
  {
    writel_relaxed(0x2C010800u, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[29]));
    v30 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[26])) & 0xFFFFFF00;
    if ( *(_QWORD *)(a1 + 1520) >= 0x8F0D180u )
      v31 = 16;
    else
      v31 = 8;
    writel_relaxed(v31 | v30, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[26]));
  }
  raw_spin_unlock_irqrestore(a1 + 792, v10);
  usleep_range_state(55, 60, 2);
  v32 = raw_spin_lock_irqsave(a1 + 792);
  v33 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
  writel_relaxed(v33 & 0xBFFFFFFF, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
  v34 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
  writel_relaxed(v34 & 0xDFFFFFFF, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
  v35 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
  writel_relaxed(v35 | 0x40000000, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
  v36 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
  writel_relaxed(v36 & 0xBFFFFFFF, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
  if ( *(_BYTE *)(a1 + 1560) == 1 )
  {
    v37 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[25]));
    writel_relaxed(v37 & 0xFFDFFFFF, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[25]));
  }
  v38 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
  writel_relaxed(v38 | 0x10000, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
  raw_spin_unlock_irqrestore(a1 + 792, v32);
  usleep_range_state(45, 50, 2);
  v39 = raw_spin_lock_irqsave(a1 + 792);
  v40 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
  writel_relaxed(v40 | 0x40000, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[15]));
  if ( (readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[16])) & 0x80) != 0 )
  {
LABEL_43:
    v43 = 0;
    if ( (v12 & 2) == 0 )
      goto LABEL_45;
LABEL_44:
    v44 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[17]));
    writel_relaxed(v44 | 2, (unsigned int *)(*(_QWORD *)(a1 + 24) + v4[17]));
    goto LABEL_45;
  }
  v41 = -50;
  while ( !__CFADD__(v41++, 1) )
  {
    _const_udelay(4295);
    if ( (readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v4[16])) & 0x80) != 0 )
      goto LABEL_43;
  }
  v46 = *(const char **)(v2 + 120);
  if ( !v46 )
    v46 = *(const char **)(v2 + 8);
  dev_err(*(_QWORD *)v2, "%s: DLL failed to LOCK\n", v46);
  v43 = -110;
  if ( (v12 & 2) != 0 )
    goto LABEL_44;
LABEL_45:
  raw_spin_unlock_irqrestore(a1 + 792, v39);
  return v43;
}
