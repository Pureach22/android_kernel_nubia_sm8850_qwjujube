__int64 __fastcall cam_icp_hw_mgr_init(const void *a1, __int64 *a2, _DWORD *a3, __int64 a4, unsigned int a5)
{
  _BYTE *v5; // x25
  _QWORD *v6; // x26
  __int64 v7; // x27
  __int64 result; // x0
  __int64 v12; // x0
  __int64 v13; // x19
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 i; // x25
  unsigned int inited; // w0
  unsigned int v20; // w21
  unsigned int handle; // w0
  unsigned int v22; // w0
  unsigned int wq; // w0
  unsigned int debugfs_entry; // w0
  unsigned int v25; // w0
  unsigned int svs_clk_info; // w0
  _QWORD *v27; // x0
  int v28; // w8
  int v29; // w9
  int v30; // w8
  unsigned __int64 StatusReg; // x23
  __int64 v32; // x24
  _QWORD *v33; // x0
  _DWORD *v34; // [xsp+8h] [xbp-8h]

  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_hw_mgr_init",
      10033,
      "Invalid args of_node %pK hw_mgr %pK",
      a1,
      a2);
    return 4294967274LL;
  }
  if ( a5 >= 2 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v32 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_icp_hw_mgr_init__alloc_tag;
    v13 = _kvmalloc_node_noprof(44264, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v32;
    if ( v13 )
      goto LABEL_12;
    return 4294967284LL;
  }
  v6 = g_icp_hw_mgr;
  if ( g_icp_hw_mgr[a5] )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_hw_mgr_init",
      10038,
      "HW mgr for device idx: %u already initialized",
      a5);
    return 0xFFFFFFFFLL;
  }
  a2[19] = 0;
  a2[20] = 0;
  v5 = &unk_2FD000;
  v7 = a4;
  a2[17] = 0;
  a2[18] = 0;
  a2[15] = 0;
  a2[16] = 0;
  a2[13] = 0;
  a2[14] = 0;
  a2[11] = 0;
  a2[12] = 0;
  a2[9] = 0;
  a2[10] = 0;
  a2[7] = 0;
  a2[8] = 0;
  a2[5] = 0;
  a2[6] = 0;
  a2[3] = 0;
  a2[4] = 0;
  a2[1] = 0;
  a2[2] = 0;
  *a2 = 0;
  v34 = a3;
  if ( mem_trace_en == 1 )
    v12 = cam_mem_trace_alloc(44264, 0xCC0u, 0, "cam_icp_hw_mgr_init", 0x273Cu);
  else
    v12 = _kvmalloc_node_noprof(44264, 0, 3520, 0xFFFFFFFFLL);
  v13 = v12;
  if ( !v12 )
    return 4294967284LL;
LABEL_12:
  if ( v5[2904] == 1 )
  {
    v14 = cam_mem_trace_alloc(432, 0xCC0u, 0, "cam_icp_hw_mgr_init", 0x2742u);
    *(_QWORD *)(v13 + 96) = v14;
    if ( !v14 )
      goto LABEL_65;
  }
  else
  {
    v15 = _kvmalloc_node_noprof(432, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(v13 + 96) = v15;
    if ( !v15 )
    {
LABEL_65:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_hw_mgr_init",
        10052,
        "Failed at allocating memory for context data");
      v20 = -12;
      goto LABEL_70;
    }
  }
  if ( v5[2904] == 1 )
  {
    v16 = cam_mem_trace_alloc(2592, 0xCC0u, 0, "cam_icp_hw_mgr_init", 0x274Bu);
    *(_QWORD *)(v13 + 88) = v16;
    if ( !v16 )
      goto LABEL_66;
  }
  else
  {
    v17 = _kvmalloc_node_noprof(2592, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(v13 + 88) = v17;
    if ( !v17 )
    {
LABEL_66:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_hw_mgr_init",
        10061,
        "Failed at allocating memory for mutex of each ctx");
      v20 = -12;
LABEL_67:
      v33 = *(_QWORD **)(v13 + 96);
      if ( v5[2904] == 1 )
        cam_mem_trace_free(v33, 0);
      else
        kvfree(v33);
LABEL_70:
      if ( v5[2904] == 1 )
        cam_mem_trace_free((_QWORD *)v13, 0);
      else
        kvfree(v13);
      return v20;
    }
  }
  for ( i = 0; i != 2592; i += 48 )
    _mutex_init(*(_QWORD *)(v13 + 88) + i, "&hw_mgr->ctx_mutex[i]", &cam_icp_hw_mgr_init___key);
  *(_DWORD *)(v13 + 144) = a5;
  if ( a5 )
    scnprintf(v13 + 112, 32, "icp%u", a5);
  else
    sized_strscpy(v13 + 112, "icp");
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_hw_mgr_init",
      10079,
      "Initailize hw mgr[%u] with name: %s",
      a5,
      (const char *)(v13 + 112));
  *a2 = v13;
  a2[1] = (__int64)cam_icp_mgr_get_hw_caps;
  a2[2] = (__int64)&cam_icp_mgr_get_hw_caps_v2;
  a2[3] = (__int64)cam_icp_mgr_acquire_hw;
  a2[4] = (__int64)cam_icp_mgr_release_hw;
  a2[7] = (__int64)cam_icp_mgr_prepare_hw_update;
  a2[8] = (__int64)cam_icp_mgr_config_stream_settings;
  a2[9] = (__int64)cam_icp_mgr_config_hw;
  a2[14] = (__int64)cam_icp_mgr_hw_close_u;
  a2[15] = (__int64)cam_icp_mgr_hw_flush;
  a2[12] = (__int64)&cam_icp_mgr_cmd;
  a2[13] = (__int64)cam_icp_mgr_hw_open_u;
  a2[17] = (__int64)&cam_icp_mgr_hw_dump;
  a2[19] = (__int64)cam_icp_mgr_inject_evt;
  *(_DWORD *)(v13 + 44112) = 0;
  *(_QWORD *)(v13 + 104) = v7;
  a2[20] = (__int64)cam_icp_mgr_service_synx_test_cmds;
  *(_BYTE *)(v13 + 44237) = 0;
  _mutex_init(v13, "&hw_mgr->hw_mgr_mutex", &cam_icp_hw_mgr_init___key_17);
  *(_DWORD *)(v13 + 48) = 0;
  *(_DWORD *)(v13 + 44168) = 0;
  *(_DWORD *)(v13 + 44172) = -1;
  inited = cam_icp_mgr_init_devs(a1, v13);
  if ( inited )
  {
    v20 = inited;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_hw_mgr_init",
      10123,
      "[%s] cam_icp_mgr_init_devs fail: rc: %d",
      v13 + 112);
    v5 = &unk_2FD000;
    goto LABEL_49;
  }
  handle = cam_smmu_get_handle((char *)(v13 + 112), (int *)(v13 + 148));
  if ( handle )
  {
    v20 = handle;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_hw_mgr_init",
      10130,
      "[%s] get mmu handle failed: %d",
      v13 + 112);
    v5 = &unk_2FD000;
LABEL_48:
    cam_icp_mgr_free_hw_devs(v13);
LABEL_49:
    v27 = *(_QWORD **)(v13 + 88);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v27, 0);
    else
      kvfree(v27);
    goto LABEL_67;
  }
  v22 = cam_smmu_get_handle("cam-secure", (int *)(v13 + 152));
  if ( v22 )
  {
    v20 = v22;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_hw_mgr_init",
      10137,
      "[%s] get secure mmu handle failed: %d",
      v13 + 112);
    v5 = &unk_2FD000;
LABEL_47:
    cam_smmu_destroy_handle(*(_DWORD *)(v13 + 148));
    *(_DWORD *)(v13 + 148) = -1;
    goto LABEL_48;
  }
  wq = cam_icp_mgr_create_wq(v13);
  if ( wq )
  {
    v20 = wq;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_hw_mgr_init",
      10144,
      "[%s] cam_icp_mgr_create_wq fail: rc=%d",
      v13 + 112);
LABEL_46:
    v5 = &unk_2FD000;
    cam_smmu_destroy_handle(*(_DWORD *)(v13 + 152));
    *(_DWORD *)(v13 + 152) = -1;
    goto LABEL_47;
  }
  debugfs_entry = cam_icp_hw_mgr_create_debugfs_entry(v13);
  if ( debugfs_entry )
  {
    v20 = debugfs_entry;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_hw_mgr_init",
      10151,
      "[%s] Fail to create debugfs entry",
      (const char *)(v13 + 112));
LABEL_45:
    cam_icp_mgr_destroy_wq((_QWORD *)v13);
    goto LABEL_46;
  }
  if ( v34 )
    *v34 = *(_DWORD *)(v13 + 148);
  v25 = cam_icp_mgr_register_hfi_client(v13);
  if ( v25 )
  {
    v20 = v25;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_hw_mgr_init",
      10161,
      "[%s] Fail to register hw mgr as hfi handle",
      (const char *)(v13 + 112));
LABEL_44:
    debugfs_remove(*(_QWORD *)(v13 + 44088));
    *(_QWORD *)(v13 + 44088) = 0;
    goto LABEL_45;
  }
  *(_DWORD *)(v13 + 44024) = 0;
  _init_swait_queue_head(v13 + 44032, "&x->wait", &init_completion___key_9);
  cam_common_register_mini_dump_cb((__int64)cam_icp_hw_mgr_mini_dump_cb, (const char *)(v13 + 112), v13 + 144);
  svs_clk_info = cam_icp_get_svs_clk_info(v13);
  if ( svs_clk_info )
  {
    v20 = svs_clk_info;
    ((void (__fastcall *)(__int64))cam_hfi_unregister)(v13 + 156);
    goto LABEL_44;
  }
  if ( *(_BYTE *)(v13 + 44235) == 1 )
  {
    v28 = *(_DWORD *)(v13 + 144);
    if ( v28 == 1 )
      v29 = 2;
    else
      v29 = 3;
    if ( v28 )
      v30 = v29;
    else
      v30 = 1;
    *(_DWORD *)(v13 + 160) = v30;
  }
  v6[a5] = v13;
  result = 0;
  *(_DWORD *)(v13 + 44176) = 0;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_hw_mgr_init",
      10192,
      "Done hw mgr[%u] init: icp name:%s",
      a5,
      (const char *)(v13 + 112));
    return 0;
  }
  return result;
}
