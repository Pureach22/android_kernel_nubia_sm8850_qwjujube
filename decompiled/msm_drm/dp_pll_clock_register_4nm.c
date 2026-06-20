__int64 __fastcall dp_pll_clock_register_4nm(__int64 a1)
{
  __int64 v1; // x22
  __int64 v3; // x0
  __int64 v4; // x0
  int v5; // w11
  void *v6; // x8
  const char *v7; // x3
  const char *v8; // x3
  unsigned int v9; // w0
  unsigned int v10; // w20
  __int64 v11; // x0
  unsigned __int64 StatusReg; // x21
  int v13; // w2
  __int64 ipc_log_context; // x0
  __int64 v16; // x0
  void *v17; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]pll data not initialized\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_22D972, "dp_pll_clock_register_4nm");
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
  v5 = *(_DWORD *)a1;
  v6 = &pll_params_v1;
  *(_QWORD *)(a1 + 400) = dp_pll_configure_0;
  *(_QWORD *)(a1 + 408) = dp_pll_prepare_0;
  v7 = *(const char **)(a1 + 24);
  if ( v5 == 4 )
    v6 = &pll_params_v1_1;
  *(_QWORD *)(a1 + 48) = a1;
  *(_QWORD *)(a1 + 64) = v6;
  *(_QWORD *)(a1 + 416) = dp_pll_unprepare_0;
  snprintf((char *)(a1 + 160), 0x20u, "%s%s", v7, "_phy_pll_link_clk");
  v8 = *(const char **)(a1 + 24);
  *(_QWORD *)(a1 + 104) = a1 + 160;
  *(_QWORD *)(a1 + 112) = &pll_link_clk_ops_0;
  *(_QWORD *)(a1 + 88) = a1 + 104;
  snprintf((char *)(a1 + 280), 0x20u, "%s%s", v8, "_phy_pll_vco_div_clk");
  *(_QWORD *)(a1 + 232) = &pll_vco_div_clk_ops_0;
  *(_QWORD *)(a1 + 224) = a1 + 280;
  *(_QWORD *)(a1 + 208) = a1 + 224;
  v9 = dp_pll_clock_register_helper(a1, a1 + 72, 2);
  if ( v9 )
  {
    v10 = v9;
    v16 = get_ipc_log_context();
    ipc_log_string(v16, "[e][%-4d]Clock register failed rc=%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v10);
    v17 = &unk_24F36D;
LABEL_17:
    printk(v17, "dp_pll_clock_register_4nm");
    kfree(**(_QWORD **)(a1 + 384));
    kfree(*(_QWORD *)(a1 + 384));
    return v10;
  }
  v10 = of_clk_add_provider(*(_QWORD *)(v1 + 760), &of_clk_src_onecell_get, *(_QWORD *)(a1 + 384));
  v11 = get_ipc_log_context();
  StatusReg = _ReadStatusReg(SP_EL0);
  v13 = *(_DWORD *)(StatusReg + 1800);
  if ( v10 )
  {
    ipc_log_string(v11, "[e][%-4d]Clock add provider failed rc=%d\n", v13, v10);
    v17 = &unk_23107D;
    goto LABEL_17;
  }
  ipc_log_string(v11, "[d][%-4d]success\n", v13);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]success\n", *(_DWORD *)(StatusReg + 1800));
  return 0;
}
