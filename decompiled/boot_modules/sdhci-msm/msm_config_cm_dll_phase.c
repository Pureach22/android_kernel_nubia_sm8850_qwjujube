__int64 __fastcall msm_config_cm_dll_phase(_QWORD *a1, unsigned __int8 a2)
{
  int v2; // w21
  unsigned int v3; // w21
  _QWORD *v5; // x23
  __int64 v6; // x24
  __int64 v8; // x20
  int v9; // w0
  __int64 v10; // x26
  _QWORD *v11; // x25
  int v12; // w27
  bool v13; // cf
  int v14; // w0
  int v15; // w0
  __int64 v16; // x25
  _QWORD *v17; // x22
  int v18; // w26
  int v19; // w0
  __int64 v21; // x2
  __int64 v22; // x2
  const char *v23; // x2

  v2 = a2;
  if ( a2 <= 0xFu )
  {
    v5 = (_QWORD *)a1[9];
    v6 = a1[203];
    v8 = raw_spin_lock_irqsave(a1 + 99);
    v9 = readl_relaxed((unsigned int *)(a1[3] + *(unsigned int *)(v6 + 60)));
    writel_relaxed(v9 & 0xFFF0FFFF | 0x90000, (unsigned int *)(a1[3] + *(unsigned int *)(v6 + 60)));
    v10 = a1[203];
    v11 = (_QWORD *)a1[9];
    if ( (readl_relaxed((unsigned int *)(a1[3] + *(unsigned int *)(v10 + 60))) & 0x40000) != 0 )
    {
      v12 = -50;
      while ( 1 )
      {
        v13 = __CFADD__(v12++, 1);
        if ( v13 )
          break;
        _const_udelay(4295);
        if ( (readl_relaxed((unsigned int *)(a1[3] + *(unsigned int *)(v10 + 60))) & 0x40000) == 0 )
          goto LABEL_7;
      }
      v21 = v11[15];
      if ( !v21 )
        v21 = v11[1];
      dev_err(*v11, "%s: CK_OUT_EN bit is not %d\n", v21, 0);
    }
    else
    {
LABEL_7:
      v14 = readl_relaxed((unsigned int *)(a1[3] + *(unsigned int *)(v6 + 60)));
      writel_relaxed(
        v14 & 0xFF0FFFFF | (msm_config_cm_dll_phase_grey_coded_phase_table[a2] << 20),
        (unsigned int *)(a1[3] + *(unsigned int *)(v6 + 60)));
      v15 = readl_relaxed((unsigned int *)(a1[3] + *(unsigned int *)(v6 + 60)));
      writel_relaxed(v15 | 0x40000, (unsigned int *)(a1[3] + *(unsigned int *)(v6 + 60)));
      v16 = a1[203];
      v17 = (_QWORD *)a1[9];
      if ( (readl_relaxed((unsigned int *)(a1[3] + *(unsigned int *)(v16 + 60))) & 0x40000) != 0 )
      {
LABEL_11:
        v19 = readl_relaxed((unsigned int *)(a1[3] + *(unsigned int *)(v6 + 60)));
        writel_relaxed(v19 & 0xFFF5FFFF | 0x20000, (unsigned int *)(a1[3] + *(unsigned int *)(v6 + 60)));
        v3 = 0;
LABEL_12:
        raw_spin_unlock_irqrestore(a1 + 99, v8);
        return v3;
      }
      v18 = -50;
      while ( 1 )
      {
        v13 = __CFADD__(v18++, 1);
        if ( v13 )
          break;
        _const_udelay(4295);
        if ( (readl_relaxed((unsigned int *)(a1[3] + *(unsigned int *)(v16 + 60))) & 0x40000) != 0 )
          goto LABEL_11;
      }
      v22 = v17[15];
      if ( !v22 )
        v22 = v17[1];
      dev_err(*v17, "%s: CK_OUT_EN bit is not %d\n", v22, 1);
    }
    v23 = (const char *)v5[15];
    if ( !v23 )
      v23 = (const char *)v5[1];
    dev_err(*v5, "%s: Failed to set DLL phase: %d\n", v23, v2);
    v3 = -110;
    goto LABEL_12;
  }
  return (unsigned int)-22;
}
