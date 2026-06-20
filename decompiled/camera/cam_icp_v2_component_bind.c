__int64 __fastcall cam_icp_v2_component_bind(__int64 a1)
{
  __int64 matched; // x0
  __int64 v3; // x23
  __int64 v4; // x0
  unsigned int v5; // w23
  __int64 v6; // x19
  __int64 v7; // x0
  __int64 v8; // x21
  __int64 v9; // x0
  _QWORD *v10; // x22
  int v11; // w9
  _DWORD *v12; // x0
  __int64 v13; // x8
  unsigned int v14; // w0
  int v15; // w10
  unsigned int v16; // w0
  _QWORD *v17; // x20
  _QWORD *v18; // x0
  __int64 v19; // x0
  unsigned int v20; // w9
  unsigned int v21; // w9
  __int64 *v22; // x9
  unsigned int v23; // w9
  int v24; // w10
  int v25; // w9
  unsigned int v26; // w11
  unsigned int v27; // w9
  unsigned __int64 StatusReg; // x21
  __int64 v29; // x22
  _QWORD v31[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v32[3]; // [xsp+18h] [xbp-18h] BYREF

  v32[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32[0] = 0;
  v32[1] = 0;
  v31[0] = 0;
  v31[1] = 0;
  ktime_get_real_ts64(v32);
  matched = of_match_device(*(_QWORD *)(*(_QWORD *)(a1 + 136) + 40LL), a1);
  if ( !matched )
  {
    v5 = -22;
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_v2_component_bind",
        102,
        "No ICP v2 hardware info");
    goto LABEL_66;
  }
  v3 = matched;
  if ( mem_trace_en == 1 )
    v4 = cam_mem_trace_alloc(120, 0xCC0u, 0, "cam_icp_v2_component_bind", 0x6Au);
  else
    v4 = _kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
  v6 = v4;
  if ( !v4 )
  {
LABEL_53:
    v5 = -12;
    goto LABEL_66;
  }
  while ( 1 )
  {
    if ( mem_trace_en == 1 )
      v7 = cam_mem_trace_alloc(3688, 0xCC0u, 0, "cam_icp_v2_component_bind", 0x6Eu);
    else
      v7 = _kvmalloc_node_noprof(3688, 0, 3520, 0xFFFFFFFFLL);
    v8 = v7;
    if ( !v7 )
    {
      v5 = -12;
      goto LABEL_63;
    }
    if ( mem_trace_en == 1 )
      v9 = cam_mem_trace_alloc(112, 0xCC0u, 0, "cam_icp_v2_component_bind", 0x74u);
    else
      v9 = _kvmalloc_node_noprof(112, 0, 3520, 0xFFFFFFFFLL);
    v10 = (_QWORD *)v9;
    if ( !v9 )
    {
      v5 = -12;
      goto LABEL_60;
    }
    v11 = (unsigned __int8)mem_trace_en;
    *(_QWORD *)(v9 + 16) = *(_QWORD *)(v3 + 192);
    *(_QWORD *)(v8 + 3680) = v9;
    if ( v11 == 1 )
    {
      v12 = (_DWORD *)cam_mem_trace_alloc(88, 0xCC0u, 0, "cam_icp_v2_soc_info_init", 0x3Au);
      if ( !v12 )
        goto LABEL_56;
    }
    else
    {
      v12 = (_DWORD *)_kvmalloc_node_noprof(88, 0, 3520, 0xFFFFFFFFLL);
      if ( !v12 )
      {
LABEL_56:
        v5 = -12;
        goto LABEL_57;
      }
    }
    *(_QWORD *)(v8 + 96) = a1 - 16;
    *(_QWORD *)(v8 + 104) = a1;
    v13 = *(_QWORD *)(a1 - 16);
    *(_QWORD *)(v8 + 3392) = v12;
    *(_QWORD *)(v8 + 120) = v13;
    *v12 = 1;
    _mutex_init(v8, "&icp_v2_info->hw_mutex", &cam_icp_v2_component_bind___key);
    *(_DWORD *)(v8 + 48) = 0;
    *(_DWORD *)(v8 + 56) = 0;
    _init_swait_queue_head(v8 + 64, "&x->wait", &init_completion___key_12);
    v14 = cam_icp_soc_resources_init(v8 + 96, &cam_icp_v2_handle_irq, v8);
    if ( v14 )
    {
      v5 = v14;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_v2_component_bind",
        136,
        "soc resources init failed rc=%d",
        v14);
      goto LABEL_27;
    }
    v5 = cam_icp_v2_core_init(v8 + 96, v10);
    if ( v5 )
      goto LABEL_27;
    *(_QWORD *)(v6 + 112) = v8;
    *(_DWORD *)v6 = 1;
    v15 = *(_DWORD *)(v8 + 116);
    *(_QWORD *)(v6 + 16) = &cam_icp_v2_hw_init;
    *(_QWORD *)(v6 + 24) = cam_icp_v2_hw_deinit;
    *(_QWORD *)(v6 + 88) = &cam_icp_v2_process_cmd;
    *(_DWORD *)(v6 + 4) = v15;
    *(_QWORD *)(v6 + 104) = cam_icp_v2_test_irq_line;
    *(_DWORD *)(v8 + 3400) = *(_DWORD *)(v8 + 116) + 14080;
    v16 = cam_icp_v2_cpas_register(v6);
    if ( v16 )
    {
      v5 = v16;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_v2_component_bind",
        161,
        "cpas registration failed rc=%d",
        v16);
      goto LABEL_26;
    }
    if ( *(_DWORD *)(v6 + 4) > max_icp_v2_hw_idx )
      max_icp_v2_hw_idx = *(_DWORD *)(v6 + 4);
    v3 = *(_QWORD *)(v8 + 3392);
    v19 = mem_trace_en == 1
        ? cam_mem_trace_alloc(4LL * *(unsigned int *)(v3 + 72), 0xCC0u, 0, "cam_icp_v2_component_bind", 0xAAu)
        : _kvmalloc_node_noprof(4LL * *(unsigned int *)(v3 + 72), 0, 3520, 0xFFFFFFFFLL);
    v20 = *(_DWORD *)(v6 + 4);
    if ( v20 < 2 )
    {
      *((_QWORD *)&cam_icp_hw_list + 3 * v20 + 2) = v19;
      v21 = *(_DWORD *)(v6 + 4);
      if ( v21 <= 1 )
        break;
    }
LABEL_52:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v29 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_icp_v2_component_bind__alloc_tag;
    v6 = _kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v29;
    if ( !v6 )
      goto LABEL_53;
  }
  v22 = (__int64 *)((char *)&cam_icp_hw_list + 24 * v21);
  if ( v22[2] )
  {
    *v22 = v6;
    v23 = *(_DWORD *)(v6 + 4);
    if ( v23 <= 1 )
    {
      v24 = *(_DWORD *)(v3 + 72);
      *((_DWORD *)&cam_icp_hw_list + 6 * v23 + 2) = v24;
      if ( v24 )
      {
        v25 = 0;
        while ( 1 )
        {
          v26 = *(_DWORD *)(v6 + 4);
          if ( v26 > 1 )
            break;
          *(_DWORD *)(*((_QWORD *)&cam_icp_hw_list + 3 * v26 + 2) + 4LL * v25) = *(_DWORD *)(*(_QWORD *)(v3 + 80)
                                                                                           + 4LL * v25);
          if ( (unsigned int)++v25 >= *(_DWORD *)(v3 + 72) )
            goto LABEL_49;
        }
      }
      else
      {
LABEL_49:
        v27 = *(_DWORD *)(v6 + 4);
        if ( v27 <= 2 )
        {
          *(_QWORD *)(a1 + 152) = (char *)&cam_icp_hw_list + 24 * v27;
          ktime_get_real_ts64(v31);
          cam_record_bind_latency();
          v5 = 0;
          goto LABEL_66;
        }
      }
    }
    goto LABEL_52;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_v2_component_bind",
    172,
    "Failed at allocating memory for icp hw list");
  v5 = -12;
LABEL_26:
  cam_icp_soc_resources_deinit(v8 + 96);
LABEL_27:
  v17 = *(_QWORD **)(v8 + 3392);
  v18 = (_QWORD *)v17[10];
  if ( v18 )
  {
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v18, 0);
    else
      kvfree(v18);
    v17[10] = 0;
    v17 = *(_QWORD **)(v8 + 3392);
  }
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v17, 0);
  else
    kvfree(v17);
  *(_QWORD *)(v8 + 3392) = 0;
LABEL_57:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v10, 0);
  else
    kvfree(v10);
LABEL_60:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v8, 0);
  else
    kvfree(v8);
LABEL_63:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v6, 0);
  else
    kvfree(v6);
LABEL_66:
  _ReadStatusReg(SP_EL0);
  return v5;
}
