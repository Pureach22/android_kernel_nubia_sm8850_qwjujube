__int64 __fastcall dp_vco_recalc_rate_4nm(_QWORD *a1)
{
  __int64 v2; // x20
  __int64 v3; // x25
  unsigned int v4; // w19
  int v5; // w26
  int v6; // w21
  __int64 v7; // x0
  unsigned __int64 StatusReg; // x21
  unsigned int v9; // w22
  int v10; // w23
  __int64 v11; // x0
  unsigned __int64 v12; // x25
  __int64 ipc_log_context; // x0
  __int64 v15; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input parameters\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_26189D, "dp_vco_recalc_rate_4nm");
    return -22;
  }
  if ( (readl_relaxed_2(*(_QWORD *)(a1[47] + 24LL)) & 0x80000000) == 0 )
    return 0;
  v2 = 8100000;
  v3 = 2700000;
  v4 = readl_relaxed_2(*(_QWORD *)(a1[44] + 24LL) + 60LL) & 0xF;
  if ( v4 > 2 )
  {
    if ( v4 == 5 )
    {
      v5 = 1;
      v6 = 5;
      goto LABEL_16;
    }
    if ( v4 == 3 )
    {
      v5 = 0;
      v6 = 3;
      v2 = 2700000;
      goto LABEL_16;
    }
  }
  else
  {
    if ( !v4 )
    {
      v5 = 0;
      v6 = 1;
      goto LABEL_16;
    }
    if ( v4 == 1 )
    {
      v5 = 0;
      v6 = 2;
      v2 = 5400000;
      goto LABEL_16;
    }
  }
  v7 = get_ipc_log_context();
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(v7, "[d][%-4d]unknown divider. forcing to default\n", *(_DWORD *)(StatusReg + 1800));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]unknown divider. forcing to default\n", *(_DWORD *)(StatusReg + 1800));
  v6 = 5;
  v5 = 1;
LABEL_16:
  v9 = ((unsigned int)readl_relaxed_2(*(_QWORD *)(a1[43] + 24LL) + 40LL) >> 2) & 3;
  switch ( v9 )
  {
    case 0u:
      v10 = 5;
      if ( !v5 )
        goto LABEL_25;
      goto LABEL_22;
    case 2u:
      v10 = 20;
      goto LABEL_24;
    case 1u:
      v10 = 10;
      if ( (v5 & 1) == 0 )
        goto LABEL_25;
      goto LABEL_22;
  }
  v15 = get_ipc_log_context();
  ipc_log_string(v15, "[e][%-4d]unsupported div. Phy_mode: %d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), 3);
  printk(&unk_21CA97, "dp_vco_recalc_rate_4nm");
  v10 = 0;
  if ( (v5 & 1) != 0 )
  {
LABEL_22:
    v3 = 1620000;
LABEL_24:
    v2 = v3;
  }
LABEL_25:
  v11 = get_ipc_log_context();
  v12 = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    v11,
    "[d][%-4d]hsclk: sel=0x%x, div=0x%x; lclk: sel=%u, div=%u, rate=%lu\n",
    *(_DWORD *)(v12 + 1800),
    v4,
    v6,
    v9,
    v10,
    v2);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]hsclk: sel=0x%x, div=0x%x; lclk: sel=%u, div=%u, rate=%lu\n",
      *(_DWORD *)(v12 + 1800),
      v4,
      v6,
      v9,
      v10,
      v2);
  return v2;
}
