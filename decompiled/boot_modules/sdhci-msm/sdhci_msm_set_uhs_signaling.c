__int64 __fastcall sdhci_msm_set_uhs_signaling(__int64 a1, unsigned int a2)
{
  __int64 v2; // x22
  __int64 v4; // x23
  __int64 (*v6)(void); // x8
  int v7; // w0
  unsigned int v8; // w8
  unsigned int v9; // w20
  int v10; // w0
  int v11; // w0
  _DWORD *v12; // x8
  __int64 result; // x0
  __int64 v14; // x21
  __int64 v15; // x20
  int v16; // w0
  __int64 v17; // x21
  int v18; // w0
  int v19; // w0
  int v20; // w0
  int v21; // w0
  int v22; // w0
  int v23; // w0
  int v24; // w0
  int v25; // w0
  int v26; // w0
  __int64 v27; // x0
  __int64 v28; // x20
  __int64 v29; // x0
  __int64 v30; // x20
  unsigned int *v31; // x21
  __int64 v32; // x20
  __int64 v33; // x8
  __int64 v34; // x9
  __int64 v35; // x8
  unsigned int v36; // w0
  int v37; // w0
  int v38; // w0
  __int64 v39; // x0
  __int64 v40; // x20
  __int64 v41; // x20
  int v42; // w0
  int v43; // w0
  __int64 v44; // x8
  __int64 v45; // x1
  void *v46; // x0
  __int64 v47; // x8
  __int64 v48; // x8
  __int64 v49; // x1
  __int64 v50; // x8
  __int64 v51; // x1

  v2 = *(_QWORD *)(a1 + 72);
  v4 = *(_QWORD *)(a1 + 1624);
  v6 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 64) + 8LL);
  if ( v6 )
  {
    if ( *((_DWORD *)v6 - 1) != -1608852288 )
      __break(0x8228u);
    v7 = v6();
  }
  else
  {
    v7 = readw(*(_QWORD *)(a1 + 24) + 62LL);
  }
  v8 = v7 & 0xFFFFFFF8;
  if ( a2 > 0xA )
    goto LABEL_10;
  if ( ((1 << a2) & 0x640) != 0 )
  {
    v9 = v8 | 3;
    goto LABEL_12;
  }
  if ( ((1 << a2) & 0x180) != 0 )
  {
    v9 = v8 | 4;
    goto LABEL_12;
  }
  if ( a2 == 5 )
  {
    v9 = v8 | 2;
  }
  else
  {
LABEL_10:
    v9 = v7 & 0xFFFFFFF8;
    if ( a2 == 4 )
      v9 = v8 | 1;
  }
LABEL_12:
  if ( *(_DWORD *)(a1 + 820) < 0x5F5E101u )
  {
    if ( a2 <= 0xA && ((1 << a2) & 0x640) != 0 )
      v9 = v7 & 0xFFFFFFF8;
    v10 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v4 + 60)));
    writel_relaxed(v10 | 0x40000000, (unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v4 + 60)));
    v11 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v4 + 60)));
    writel_relaxed(v11 | 0x20000000, (unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v4 + 60)));
    *(_BYTE *)(a1 + 1562) = 0;
  }
  v12 = *(_DWORD **)(*(_QWORD *)(a1 + 64) + 32LL);
  if ( v12 )
  {
    if ( *(v12 - 1) != -139597297 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v12)(a1, v9, 62);
  }
  else
  {
    result = writew(v9, *(_QWORD *)(a1 + 24) + 62LL);
  }
  if ( *(_BYTE *)(v2 + 1056) == 10
    && *(_DWORD *)(a1 + 820) > 0x5F5E100u
    && ((*(_BYTE *)(a1 + 1561) & 1) != 0 || *(_BYTE *)(v2 + 1059) == 1)
    && (*(_BYTE *)(a1 + 1562) & 1) == 0 )
  {
    v14 = *(_QWORD *)(a1 + 72);
    v15 = *(_QWORD *)(a1 + 1624);
    if ( (unsigned int)msm_init_cm_dll(a1, 0) )
      goto LABEL_69;
    if ( (*(_BYTE *)(v14 + 1059) & 1) == 0 )
    {
      if ( (unsigned int)msm_config_cm_dll_phase(a1, *(unsigned __int8 *)(a1 + 1563)) )
        goto LABEL_69;
      v16 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v15 + 60)));
      writel_relaxed(v16 | 1, (unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v15 + 60)));
    }
    if ( *(_BYTE *)(a1 + 1564) == 1 )
    {
      v17 = *(_QWORD *)(a1 + 1624);
      if ( (unsigned int)msm_init_cm_dll(a1, 0)
        || (unsigned int)msm_config_cm_dll_phase(a1, *(unsigned __int8 *)(a1 + 1563)) )
      {
LABEL_69:
        v50 = *(_QWORD *)(a1 + 72);
        v51 = *(_QWORD *)(v50 + 120);
        if ( !v51 )
          v51 = *(_QWORD *)(v50 + 8);
        return printk(&unk_10B12, v51);
      }
      v18 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v17 + 60)));
      writel_relaxed(v18 | 1, (unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v17 + 60)));
      v19 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v17 + 92)));
      writel_relaxed(v19 & 0xFFFFFFFE, (unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v17 + 92)));
      v20 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + 376LL));
      writel_relaxed(v20 & 0xFFFFFFFE, (unsigned int *)(*(_QWORD *)(a1 + 24) + 376LL));
      v21 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + 376LL));
      writel_relaxed(v21 | 2, (unsigned int *)(*(_QWORD *)(a1 + 24) + 376LL));
      v22 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v17 + 92)));
      writel_relaxed(v22 & 0xFFFFFFBF, (unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v17 + 92)));
      writel_relaxed(0x11800ECu, (unsigned int *)(*(_QWORD *)(a1 + 24) + 304LL));
      writel_relaxed(0x3011111u, (unsigned int *)(*(_QWORD *)(a1 + 24) + 308LL));
      writel_relaxed(0x1201000u, (unsigned int *)(*(_QWORD *)(a1 + 24) + 312LL));
      writel_relaxed(4u, (unsigned int *)(*(_QWORD *)(a1 + 24) + 316LL));
      writel_relaxed(0xCB732020, (unsigned int *)(*(_QWORD *)(a1 + 24) + 320LL));
      writel_relaxed(0xB19u, (unsigned int *)(*(_QWORD *)(a1 + 24) + 324LL));
      writel_relaxed(0x4E2u, (unsigned int *)(*(_QWORD *)(a1 + 24) + 336LL));
      writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a1 + 24) + 332LL));
      writel_relaxed(0x16334u, (unsigned int *)(*(_QWORD *)(a1 + 24) + 352LL));
      v23 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + 304LL));
      writel_relaxed(v23 | 0x10000, (unsigned int *)(*(_QWORD *)(a1 + 24) + 304LL));
      v24 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + 304LL));
      writel_relaxed(v24 & 0xFFFEFFFF, (unsigned int *)(*(_QWORD *)(a1 + 24) + 304LL));
      v25 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + 304LL));
      writel_relaxed(v25 | 0x20000, (unsigned int *)(*(_QWORD *)(a1 + 24) + 304LL));
      v26 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + 312LL));
      v27 = writel_relaxed(v26 | 0x10000u, (unsigned int *)(*(_QWORD *)(a1 + 24) + 312LL));
      v28 = ktime_get(v27);
      v29 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + 356LL));
      if ( (v29 & 1) == 0 )
      {
        v30 = v28 + 50000;
        while ( ktime_get(v29) <= v30 )
        {
          usleep_range_state(1, 1, 2);
          __yield();
          v29 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + 356LL));
          if ( (v29 & 1) != 0 )
            goto LABEL_55;
        }
        LOBYTE(v29) = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + 356LL));
      }
LABEL_55:
      if ( (v29 & 1) != 0 )
      {
        if ( (readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + 356LL)) & 0x7000000) == 0 )
        {
          v43 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v17 + 92)));
          result = writel_relaxed(v43 | 0x40u, (unsigned int *)(*(_QWORD *)(a1 + 24) + *(unsigned int *)(v17 + 92)));
LABEL_58:
          *(_BYTE *)(a1 + 1562) = 1;
          return result;
        }
        v48 = *(_QWORD *)(a1 + 72);
        v49 = *(_QWORD *)(v48 + 120);
        if ( !v49 )
          v49 = *(_QWORD *)(v48 + 8);
        printk(&unk_1043C, v49);
        goto LABEL_69;
      }
      v47 = *(_QWORD *)(a1 + 72);
      v45 = *(_QWORD *)(v47 + 120);
      if ( !v45 )
        v45 = *(_QWORD *)(v47 + 8);
      v46 = &unk_10BA6;
    }
    else
    {
      v31 = *(unsigned int **)(a1 + 1624);
      v32 = *(_QWORD *)(a1 + 72);
      v33 = 27;
      if ( *(_BYTE *)(a1 + 1640) )
        v33 = 28;
      v34 = *(_QWORD *)(a1 + 2032);
      v35 = v31[v33];
      if ( !v34 || (v36 = *(_DWORD *)(v34 + 16)) == 0 )
        v36 = -2147219341;
      writel_relaxed(v36, (unsigned int *)(*(_QWORD *)(a1 + 24) + v35));
      if ( *(_BYTE *)(v32 + 1059) == 1 )
      {
        v37 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v31[23]));
        writel_relaxed(v37 | 2, (unsigned int *)(*(_QWORD *)(a1 + 24) + v31[23]));
      }
      v38 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v31[25]));
      v39 = writel_relaxed(v38 | 1u, (unsigned int *)(*(_QWORD *)(a1 + 24) + v31[25]));
      v40 = ktime_get(v39);
      result = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v31[16]));
      if ( (result & 0x800) == 0 )
      {
        v41 = v40 + 1000000;
        while ( ktime_get(result) <= v41 )
        {
          usleep_range_state(3, 10, 2);
          __yield();
          result = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v31[16]));
          if ( (result & 0x800) != 0 )
            goto LABEL_50;
        }
        result = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v31[16]));
      }
LABEL_50:
      if ( (result & 0x800) != 0 )
      {
        if ( (*(_BYTE *)(a1 + 1560) & 1) == 0 )
        {
          v42 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v31[24]));
          result = writel_relaxed(v42 | 8u, (unsigned int *)(*(_QWORD *)(a1 + 24) + v31[24]));
        }
        __dsb(0xEu);
        goto LABEL_58;
      }
      v44 = *(_QWORD *)(a1 + 72);
      v45 = *(_QWORD *)(v44 + 120);
      if ( !v45 )
        v45 = *(_QWORD *)(v44 + 8);
      v46 = &unk_10C41;
    }
    printk(v46, v45);
    goto LABEL_69;
  }
  return result;
}
