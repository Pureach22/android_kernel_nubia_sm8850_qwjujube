__int64 __fastcall cam_icp_v1_component_bind(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x20
  __int16 v6; // w8
  __int64 v7; // x0
  __int64 v8; // x22
  _DWORD *v9; // x0
  unsigned int v10; // w21
  __int64 v11; // x8
  unsigned int v12; // w0
  int v13; // w8
  __int64 v14; // x9
  unsigned int v15; // w0
  int v16; // w6
  _QWORD *v17; // x0
  _QWORD v19[2]; // [xsp+0h] [xbp-D0h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-C0h] BYREF
  _QWORD v21[16]; // [xsp+20h] [xbp-B0h] BYREF
  __int64 v22; // [xsp+A0h] [xbp-30h]
  __int64 v23; // [xsp+A8h] [xbp-28h]
  __int64 v24; // [xsp+B0h] [xbp-20h]
  __int64 (__fastcall *v25)(__int64, __int64, unsigned int *); // [xsp+B8h] [xbp-18h]
  __int64 v26; // [xsp+C0h] [xbp-10h]
  __int64 v27; // [xsp+C8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  v20[1] = 0;
  v19[0] = 0;
  v19[1] = 0;
  ktime_get_real_ts64(v20);
  if ( mem_trace_en == 1 )
    v2 = cam_mem_trace_alloc(120, 0xCC0u, 0, "cam_icp_v1_component_bind", 0x7Du);
  else
    v2 = _kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
  v3 = v2;
  if ( !v2 )
  {
    v10 = -12;
    goto LABEL_48;
  }
  of_property_read_variable_u32_array(a1[93], "cell-index", v2 + 4, 1, 0);
  if ( mem_trace_en == 1 )
    v4 = cam_mem_trace_alloc(3688, 0xCC0u, 0, "cam_icp_v1_component_bind", 0x84u);
  else
    v4 = _kvmalloc_node_noprof(3688, 0, 3520, 0xFFFFFFFFLL);
  v5 = v4;
  if ( !v4 )
  {
    v10 = -12;
LABEL_45:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v3, 0);
    else
      kvfree(v3);
    goto LABEL_48;
  }
  *(_DWORD *)v3 = 0;
  v6 = debug_mdl;
  *(_QWORD *)(v3 + 16) = &cam_icp_v1_init_hw;
  *(_QWORD *)(v3 + 24) = cam_icp_v1_deinit_hw;
  *(_QWORD *)(v3 + 112) = v4;
  *(_QWORD *)(v3 + 88) = cam_icp_v1_process_cmd;
  if ( (v6 & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v6 & 0x100,
      4,
      "cam_icp_v1_component_bind",
      146,
      "type %d index %d",
      0,
      *(_DWORD *)(v3 + 4));
  a1[19] = v3;
  if ( mem_trace_en == 1 )
    v7 = cam_mem_trace_alloc(72, 0xCC0u, 0, "cam_icp_v1_component_bind", 0x97u);
  else
    v7 = _kvmalloc_node_noprof(72, 0, 3520, 0xFFFFFFFFLL);
  v8 = v7;
  if ( !v7 )
  {
    v10 = -12;
LABEL_42:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v5, 0);
    else
      kvfree(v5);
    goto LABEL_45;
  }
  *(_QWORD *)(v5 + 3680) = v7;
  if ( !of_match_device(*(_QWORD *)(a1[17] + 40LL), a1) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_v1_component_bind",
      161,
      "No icp_v1 hardware info");
    v10 = -22;
LABEL_39:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v8, 0);
    else
      kvfree(v8);
    goto LABEL_42;
  }
  if ( mem_trace_en == 1 )
  {
    v9 = (_DWORD *)cam_mem_trace_alloc(88, 0xCC0u, 0, "cam_icp_v1_soc_info_init", 0x62u);
    if ( !v9 )
      goto LABEL_35;
  }
  else
  {
    v9 = (_DWORD *)_kvmalloc_node_noprof(88, 0, 3520, 0xFFFFFFFFLL);
    if ( !v9 )
    {
LABEL_35:
      v10 = -12;
LABEL_36:
      v17 = *(_QWORD **)(v5 + 3392);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v17, 0);
      else
        kvfree(v17);
      goto LABEL_39;
    }
  }
  *(_QWORD *)(v5 + 96) = a1 - 2;
  *(_QWORD *)(v5 + 104) = a1;
  v11 = *(a1 - 2);
  *(_QWORD *)(v5 + 3392) = v9;
  *(_QWORD *)(v5 + 120) = v11;
  *v9 = 0;
  v12 = cam_icp_soc_resources_init(v5 + 96, cam_icp_v1_irq, v5);
  if ( (v12 & 0x80000000) != 0 )
  {
    v10 = v12;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_v1_component_bind",
      173,
      "failed to init_soc");
    goto LABEL_36;
  }
  v13 = *(_DWORD *)(v3 + 4);
  v25 = nullptr;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v22 = 0;
  v14 = *(_QWORD *)(v5 + 96);
  v21[0] = 7365481;
  memset(&v21[1], 0, 120);
  v23 = v14 + 16;
  v25 = cam_icp_v1_cpas_cb;
  LODWORD(v22) = v13;
  v15 = cam_cpas_register_client((__int64)v21);
  if ( (v15 & 0x80000000) != 0 )
  {
    v10 = v15;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_v1_register_cpas",
      80,
      "failed: %d",
      v15);
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_v1_component_bind",
      180,
      "icp_v1 cpas registration failed");
    cam_icp_soc_resources_deinit(v5 + 96);
    goto LABEL_36;
  }
  *(_DWORD *)(v8 + 56) = v26;
  *(_DWORD *)(v8 + 60) = 2;
  *(_DWORD *)(v5 + 92) = 0;
  _mutex_init(v5, "&icp_v1_dev->hw_mutex", &cam_icp_v1_component_bind___key);
  *(_DWORD *)(v5 + 48) = 0;
  *(_DWORD *)(v5 + 56) = 0;
  _init_swait_queue_head(v5 + 64, "&x->wait", &init_completion___key_11);
  v16 = *(_DWORD *)(v3 + 4);
  if ( v16 > max_icp_v1_hw_idx )
    max_icp_v1_hw_idx = *(_DWORD *)(v3 + 4);
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_v1_component_bind",
      193,
      "ICP_V1:%u component bound successfully",
      v16);
  ktime_get_real_ts64(v19);
  cam_record_bind_latency();
  v10 = 0;
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return v10;
}
