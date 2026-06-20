__int64 __fastcall dp_pll_driver_probe(__int64 a1)
{
  __int64 matched; // x0
  unsigned int *v3; // x21
  __int64 v4; // x0
  unsigned int *v5; // x20
  __int64 v6; // x0
  __int64 property; // x0
  const char *v8; // x8
  __int64 v9; // x0
  bool v10; // w9
  __int64 v11; // x0
  __int64 v12; // x0
  int v13; // w8
  bool v14; // zf
  int v15; // w0
  char v16; // w9
  __int64 ipc_log_context; // x0
  unsigned int v19; // w19
  __int64 v20; // x0
  __int64 v21; // x8
  unsigned __int64 StatusReg; // x21
  const char *v23; // x3
  unsigned int v24; // w21
  char v25; // w22

  if ( !a1 || !*(_QWORD *)(a1 + 760) )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]pdev not found\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_26F5D2, "dp_pll_driver_probe");
    return 4294967277LL;
  }
  matched = of_match_node(&dp_pll_of_match);
  if ( !matched )
    return 4294967277LL;
  v3 = *(unsigned int **)(matched + 192);
  v4 = _kmalloc_cache_noprof(msleep, 3520, 424);
  v5 = (unsigned int *)v4;
  if ( !v4 )
    return 4294967284LL;
  *(_QWORD *)(v4 + 312) = a1;
  v6 = *(_QWORD *)(a1 + 760);
  *v5 = *v3;
  property = of_get_property(v6, "label", 0);
  v8 = "dp0";
  if ( property )
    v8 = (const char *)property;
  v9 = *(_QWORD *)(a1 + 760);
  *((_QWORD *)v5 + 3) = v8;
  v10 = of_find_property(v9, "qcom,ssc-feature-enable", 0) != 0;
  v11 = *(_QWORD *)(a1 + 760);
  *((_BYTE *)v5 + 32) = v10;
  v12 = of_find_property(v11, "qcom,bonding-feature-enable", 0);
  v13 = *v5;
  v14 = v12 == 0;
  v15 = -524;
  v16 = !v14;
  *((_BYTE *)v5 + 33) = v16;
  if ( v13 > 4 )
  {
    switch ( v13 )
    {
      case 5:
        v15 = edp_pll_clock_register_4nm(v5);
        goto LABEL_23;
      case 6:
        v15 = edp_pll_clock_register_5nm(v5);
        goto LABEL_23;
      case 7:
        v15 = dp_pll_clock_register_3nm(v5);
        goto LABEL_23;
    }
LABEL_24:
    v19 = v15;
    kfree(v5);
    return v19;
  }
  if ( (unsigned int)(v13 - 1) < 2 )
  {
    v15 = dp_pll_clock_register_5nm(v5);
    goto LABEL_23;
  }
  if ( (unsigned int)(v13 - 3) >= 2 )
    goto LABEL_24;
  v15 = dp_pll_clock_register_4nm(v5);
LABEL_23:
  if ( v15 )
    goto LABEL_24;
  v20 = get_ipc_log_context();
  v21 = *v5;
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (unsigned int)v21 > 7 )
    v23 = "???";
  else
    v23 = off_2841F0[v21];
  ipc_log_string(
    v20,
    "[i][%-4d]revision=%s, ssc_en=%d, bonding_en=%d\n",
    *(_DWORD *)(StatusReg + 1800),
    v23,
    *((unsigned __int8 *)v5 + 32),
    *((unsigned __int8 *)v5 + 33));
  v24 = *(_DWORD *)(StatusReg + 1800);
  v25 = _drm_debug;
  dp_pll_get_revision(*v5);
  if ( (v25 & 4) != 0 )
    printk(&unk_264EC8, v24);
  else
    printk(&unk_2153A4, "dp_pll_driver_probe");
  *(_QWORD *)(a1 + 168) = v5;
  return 0;
}
