__int64 __fastcall sde_kms_postinit(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 v3; // x21
  __int64 v4; // x0
  __int64 log_mask_ptr; // x0
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x22
  unsigned int v9; // w0
  unsigned int v10; // w21
  _QWORD *i; // x20
  __int64 v12; // x0
  __int64 v13; // x1
  _QWORD v15[3]; // [xsp+8h] [xbp-18h] BYREF

  v15[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = 0;
  v15[1] = 0;
  if ( !a1 || (v1 = *(_QWORD **)(a1 + 136)) == nullptr || !v1[1] || (v3 = v1[7]) == 0 )
  {
    printk(&unk_25E374, "sde_kms_postinit");
    v10 = -22;
    goto LABEL_28;
  }
  v4 = sde_kms_handle_power_event(8);
  if ( *(_DWORD *)(v3 + 5912) )
  {
    if ( *(_DWORD *)(a1 + 2544) )
      goto LABEL_7;
LABEL_10:
    sde_power_data_bus_set_quota(v3 + 16, 0, 0, 400000000);
    sde_power_data_bus_set_quota(v3 + 16, 1, 0, 400000000);
    sde_power_data_bus_set_quota(v3 + 16, 2, 0, 400000000);
    sde_power_data_bus_set_quota(v3 + 16, 3, 0, 400000000);
    sde_cesta_splash_release(**(unsigned int **)(*(_QWORD *)(a1 + 136) + 64LL));
    v4 = _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(a1 + 136) + 8LL), 4);
    goto LABEL_11;
  }
  v4 = sde_power_handle_register_event(v3 + 16, 9, sde_kms_handle_power_event, a1, &unk_2430CC);
  *(_QWORD *)(a1 + 1736) = v4;
  if ( !*(_DWORD *)(a1 + 2544) )
    goto LABEL_10;
LABEL_7:
  if ( (_drm_debug & 4) != 0 )
    v4 = _drm_dev_dbg(0, 0, 0, "Skipping MDP Resources disable\n");
LABEL_11:
  log_mask_ptr = sde_hw_util_get_log_mask_ptr(v4);
  if ( log_mask_ptr
    && (v6 = *(_QWORD *)(a1 + 136)) != 0
    && (v7 = *(_QWORD *)(v6 + 56)) != 0
    && (v8 = *(_QWORD *)(v7 + 5688)) != 0 )
  {
    debugfs_create_x32("hw_log_mask", 384, *(_QWORD *)(v7 + 5688), log_mask_ptr);
    sde_debugfs_vbif_init(a1, v8);
    sde_debugfs_core_irq_init(a1, v8);
    v9 = sde_core_perf_debugfs_init((char *)(a1 + 1960), v8);
    if ( !v9 )
    {
      sde_rm_debugfs_init(a1 + 2144, v8);
      if ( *(_DWORD *)(*(_QWORD *)(a1 + 152) + 19288LL) )
        debugfs_create_u32("qdss", 384, v8, a1 + 3745);
      debugfs_create_u32("pm_suspend_clk_dump", 384, v8, a1 + 3746);
      debugfs_create_u32("hw_fence_status", 384, v8, a1 + 6400);
      debugfs_create_u32("disable_early_EPT_handling", 384, v8, a1 + 6404);
      debugfs_create_u32("display_ctl", 384, v8, a1 + 6932);
      v10 = 0;
      goto LABEL_22;
    }
    v10 = v9;
    printk(&unk_212847, "_sde_debugfs_init");
  }
  else
  {
    v10 = -22;
  }
  printk(&unk_277335, "sde_kms_postinit");
LABEL_22:
  for ( i = (_QWORD *)v1[108]; i != v1 + 108; i = (_QWORD *)*i )
    sde_crtc_post_init((__int64)v1, (__int64)(i - 2));
  drm_connector_list_iter_begin(v1, v15);
  v12 = drm_connector_list_iter_next(v15);
  if ( v12 )
  {
    v13 = v12;
    do
    {
      sde_connector_post_init(v1, v13);
      v13 = drm_connector_list_iter_next(v15);
    }
    while ( v13 );
  }
  drm_connector_list_iter_end(v15);
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return v10;
}
