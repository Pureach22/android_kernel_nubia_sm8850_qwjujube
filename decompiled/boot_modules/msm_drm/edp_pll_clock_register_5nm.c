__int64 __fastcall edp_pll_clock_register_5nm(__int64 a1)
{
  __int64 v1; // x22
  __int64 v3; // x0
  __int64 v4; // x0
  const char *v5; // x3
  const char *v6; // x3
  unsigned int v7; // w0
  unsigned int v8; // w20
  __int64 v9; // x0
  unsigned __int64 StatusReg; // x21
  int v11; // w2
  __int64 ipc_log_context; // x0
  __int64 v14; // x0
  void *v15; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]pll data not initialized\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_22D972, "edp_pll_clock_register_5nm");
    return 4294967274LL;
  }
  v1 = *(_QWORD *)(a1 + 312);
  v3 = _kmalloc_cache_noprof(kthread_create_on_node, 3520, 16);
  *(_QWORD *)(a1 + 384) = v3;
  if ( !v3 )
    return 4294967284LL;
  **(_QWORD **)(a1 + 384) = _kmalloc_cache_noprof(kthread_create_on_node, 3520, 16);
  v4 = *(_QWORD *)(a1 + 384);
  if ( !*(_QWORD *)v4 )
  {
    kfree(v4);
    return 4294967284LL;
  }
  *(_DWORD *)(v4 + 8) = 2;
  *(_QWORD *)(a1 + 64) = &pll_params_0;
  v5 = *(const char **)(a1 + 24);
  *(_QWORD *)(a1 + 400) = edp_pll_configure;
  *(_QWORD *)(a1 + 408) = edp_pll_prepare;
  *(_QWORD *)(a1 + 48) = a1;
  *(_QWORD *)(a1 + 416) = edp_pll_unprepare;
  snprintf((char *)(a1 + 160), 0x20u, "%s%s", v5, "_phy_pll_link_clk");
  v6 = *(const char **)(a1 + 24);
  *(_QWORD *)(a1 + 104) = a1 + 160;
  *(_QWORD *)(a1 + 112) = &edp_pll_link_clk_ops;
  *(_QWORD *)(a1 + 88) = a1 + 104;
  snprintf((char *)(a1 + 280), 0x20u, "%s%s", v6, "_phy_pll_vco_div_clk");
  *(_QWORD *)(a1 + 232) = &edp_pll_vco_div_clk_ops;
  *(_QWORD *)(a1 + 224) = a1 + 280;
  *(_QWORD *)(a1 + 208) = a1 + 224;
  v7 = dp_pll_clock_register_helper(a1, a1 + 72, 2);
  if ( v7 )
  {
    v8 = v7;
    v14 = get_ipc_log_context();
    ipc_log_string(v14, "[e][%-4d]Clock register failed rc=%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v8);
    v15 = &unk_24F36D;
LABEL_15:
    printk(v15, "edp_pll_clock_register_5nm");
    dp_pll_clock_unregister_5nm(a1);
    return v8;
  }
  v8 = of_clk_add_provider(*(_QWORD *)(v1 + 760), &of_clk_src_onecell_get, *(_QWORD *)(a1 + 384));
  v9 = get_ipc_log_context();
  StatusReg = _ReadStatusReg(SP_EL0);
  v11 = *(_DWORD *)(StatusReg + 1800);
  if ( v8 )
  {
    ipc_log_string(v9, "[e][%-4d]Clock add provider failed rc=%d\n", v11, v8);
    v15 = &unk_23107D;
    goto LABEL_15;
  }
  ipc_log_string(v9, "[d][%-4d]success\n", v11);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]success\n", *(_DWORD *)(StatusReg + 1800));
  return 0;
}
