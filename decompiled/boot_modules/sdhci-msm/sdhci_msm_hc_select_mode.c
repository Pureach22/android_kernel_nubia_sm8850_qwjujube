__int64 __fastcall sdhci_msm_hc_select_mode(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x20
  int v4; // w0
  int v5; // w0
  int v6; // w0
  __int64 result; // x0
  __int64 v8; // x21
  char v9; // w20
  int v10; // w0
  int v11; // w0
  __int64 v12; // x20
  __int16 v13; // w2
  __int64 v14; // x20
  __int64 v15; // x8
  __int64 v16; // x1

  v1 = *(_QWORD *)(a1 + 72);
  if ( *(_BYTE *)(v1 + 1056) == 10 || (*(_BYTE *)(a1 + 797) & 0x20) != 0 )
  {
    v8 = *(_QWORD *)(a1 + 1624);
    v9 = *(_BYTE *)(v1 + 1059);
    v10 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v8 + 68)));
    result = writel_relaxed(v10 | 0x300u, (unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v8 + 68)));
    if ( ((*(_BYTE *)(a1 + 1561) & 1) != 0 || (v9 & 1) != 0) && (*(_BYTE *)(a1 + 1562) & 1) == 0 )
    {
      v11 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v8 + 68)));
      result = writel_relaxed(v11 | 0x340000u, (unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v8 + 68)));
    }
    if ( !*(_QWORD *)(a1 + 1520) && (*(_BYTE *)(a1 + 1564) & 1) == 0 )
    {
      v12 = ktime_get(result);
      result = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v8 + 64)));
      v13 = result;
      if ( (result & 0x880) == 0 )
      {
        v14 = v12 + 1000000;
        while ( ktime_get(result) <= v14 )
        {
          usleep_range_state(3, 10, 2);
          __yield();
          result = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v8 + 64)));
          if ( (result & 0x880) != 0 )
            goto LABEL_18;
        }
        result = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v8 + 64)));
LABEL_18:
        v13 = result;
      }
      if ( (v13 & 0x880) == 0 )
      {
        v15 = *(_QWORD *)(a1 + 72);
        v16 = *(_QWORD *)(v15 + 120);
        if ( !v16 )
          v16 = *(_QWORD *)(v15 + 8);
        result = printk(&unk_FDF2, v16);
      }
    }
    __dsb(0xEu);
  }
  else
  {
    v3 = *(_QWORD *)(a1 + 1624);
    if ( (*(_BYTE *)(a1 + 1564) & 1) == 0 )
    {
      v4 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v3 + 96)));
      writel_relaxed(v4 & 0xFFFFFFF7, (unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v3 + 96)));
    }
    v5 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v3 + 68)));
    writel_relaxed(v5 & 0xFFFFFCFF | 0x200, (unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v3 + 68)));
    v6 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v3 + 68)));
    result = writel_relaxed(v6 & 0xFFC3FFFF, (unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v3 + 68)));
    __dsb(0xEu);
  }
  return result;
}
