__int64 __fastcall msm_ssphy_qmp_set_suspend(_QWORD *a1, int a2)
{
  __int64 v4; // x20
  unsigned int v5; // w9
  int v6; // w8
  unsigned int v7; // w8
  char v8; // w8
  __int64 v9; // x0
  unsigned int v10; // w0
  int v11; // w0
  unsigned int v12; // w9
  char v13; // w8
  int v14; // w0
  __int64 v15; // x0
  __int64 v16; // x8
  const char *v17; // x1
  unsigned int v18; // w19

  if ( *((unsigned __int8 *)a1 + 547) == a2 )
    return 0;
  if ( a2 )
  {
    if ( *((_BYTE *)a1 + 546) == 1 )
    {
      v4 = *(unsigned int *)(a1[69] + 4LL);
      writel_relaxed(1);
      __dsb(0xEu);
      writel_relaxed(0);
      v5 = readl_relaxed(a1[46] + v4) & 0xFFFFFFEC;
      if ( (a1[2] & 2) != 0 )
        v6 = 3;
      else
        v6 = 17;
      writel_relaxed(v6 | v5);
      v7 = *((_DWORD *)a1 + 145);
      if ( v7 >= 2 )
      {
        if ( v7 != 2 )
        {
LABEL_29:
          __dsb(0xEu);
          msm_ssphy_qmp_enable_clks(a1, 0);
          v13 = *((_BYTE *)a1 + 16);
          *((_BYTE *)a1 + 547) = 1;
          if ( (v13 & 1) == 0 && (*((_BYTE *)a1 + 546) & 1) == 0 )
          {
            v14 = msm_ssusb_qmp_ldo_enable(a1, 0);
            if ( v14 )
              dev_err(*a1, "msm_ssusb_qmp_ldo_enable(0) failed, ret=%d\n", v14);
          }
          v10 = _pm_runtime_idle(*a1, 4);
          if ( (v10 & 0x80000000) == 0 )
            return 0;
          v16 = *a1;
          v17 = "pm_runtime_put_sync failed with %d\n";
          goto LABEL_45;
        }
      }
      else
      {
        if ( a1[47] )
          writel_relaxed(1);
        if ( !a1[48] )
          goto LABEL_29;
      }
    }
    else if ( *((_DWORD *)a1 + 145) == 2 && (*((_BYTE *)a1 + 17) & 6) == 0 )
    {
      writel_relaxed(1);
      readl_relaxed(a1[46] + *(unsigned int *)(a1[69] + 40LL));
    }
    writel_relaxed(0);
    goto LABEL_29;
  }
  v8 = *((_BYTE *)a1 + 17);
  v9 = *a1;
  if ( (v8 & 2) != 0 )
  {
    dev_info(v9, "QMP PHY currently in DP mode\n");
    return 4294967280LL;
  }
  v10 = _pm_runtime_resume(v9, 4);
  if ( (v10 & 0x80000000) == 0 )
  {
    if ( (a1[2] & 1) == 0 && (*((_BYTE *)a1 + 546) & 1) == 0 )
    {
      v11 = msm_ssusb_qmp_ldo_enable(a1, 1);
      if ( v11 )
        dev_err(*a1, "msm_ssusb_qmp_ldo_enable(1) failed, ret=%d\n", v11);
    }
    msm_ssphy_qmp_enable_clks(a1, 1);
    if ( (*((_BYTE *)a1 + 546) & 1) == 0 )
    {
      v15 = 1;
LABEL_41:
      writel_relaxed(v15);
      __dsb(0xEu);
      *((_BYTE *)a1 + 547) = 0;
      return 0;
    }
    v12 = *((_DWORD *)a1 + 145);
    if ( v12 >= 2 )
    {
      if ( v12 != 2 )
      {
LABEL_40:
        writel_relaxed(0);
        writel_relaxed(1);
        __dsb(0xEu);
        v15 = 0;
        goto LABEL_41;
      }
    }
    else
    {
      if ( a1[47] )
        writel_relaxed(0);
      if ( !a1[48] )
        goto LABEL_40;
    }
    writel_relaxed(1);
    goto LABEL_40;
  }
  v16 = *a1;
  v17 = "pm_runtime_get_sync failed with %d\n";
LABEL_45:
  v18 = v10;
  dev_err(v16, v17, v10);
  return v18;
}
