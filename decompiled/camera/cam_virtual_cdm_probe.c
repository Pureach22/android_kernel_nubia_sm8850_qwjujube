__int64 __fastcall cam_virtual_cdm_probe(__int64 a1)
{
  __int64 v2; // x0
  _DWORD *v3; // x19
  __int64 v4; // x0
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int v9; // w0
  unsigned int v10; // w21
  _QWORD *v11; // x0
  unsigned __int8 *v12; // x23
  __int64 v13; // x22
  int v14; // w8
  char v15; // w8
  __int64 v16; // x3
  __int64 v17; // x0
  int v18; // w8
  unsigned int v19; // w0
  int v20; // w8
  __int64 v21; // x9
  unsigned int v22; // w0
  _QWORD *v23; // x0
  _QWORD *v24; // x0
  __int64 result; // x0
  _QWORD *v26; // x0
  _QWORD v27[16]; // [xsp+0h] [xbp-B0h] BYREF
  __int64 v28; // [xsp+80h] [xbp-30h]
  __int64 v29; // [xsp+88h] [xbp-28h]
  _DWORD *v30; // [xsp+90h] [xbp-20h]
  __int64 (__fastcall *v31)(__int64, __int64, _DWORD *); // [xsp+98h] [xbp-18h]
  __int64 v32; // [xsp+A0h] [xbp-10h]
  __int64 v33; // [xsp+A8h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = nullptr;
  v32 = 0;
  v29 = 0;
  v30 = nullptr;
  v28 = 0;
  memset(v27, 0, sizeof(v27));
  if ( mem_trace_en == 1 )
    v2 = cam_mem_trace_alloc(120, 0xCC0u, 0, "cam_virtual_cdm_probe", 0xEEu);
  else
    v2 = _kvmalloc_node_noprof(120, 0, 3520, 0xFFFFFFFFLL);
  v3 = (_DWORD *)v2;
  if ( !v2 )
  {
    result = 4294967284LL;
    goto LABEL_68;
  }
  if ( mem_trace_en == 1 )
    v4 = cam_mem_trace_alloc(3688, 0xCC0u, 0, "cam_virtual_cdm_probe", 0xF2u);
  else
    v4 = _kvmalloc_node_noprof(3688, 0, 3520, 0xFFFFFFFFLL);
  v5 = v4;
  if ( !v4 )
  {
    if ( !mem_trace_en )
    {
LABEL_56:
      kvfree(v3);
      result = 4294967284LL;
      goto LABEL_68;
    }
    goto LABEL_51;
  }
  if ( mem_trace_en )
  {
    v6 = cam_mem_trace_alloc(4880, 0xCC0u, 0, "cam_virtual_cdm_probe", 0xF8u);
    *(_QWORD *)(v5 + 3680) = v6;
    if ( !v6 )
    {
LABEL_52:
      if ( mem_trace_en == 1 )
        cam_mem_trace_free((_QWORD *)v5, 0);
      else
        kvfree(v5);
      if ( mem_trace_en != 1 )
        goto LABEL_56;
LABEL_51:
      cam_mem_trace_free(v3, 0);
      result = 4294967284LL;
      goto LABEL_68;
    }
  }
  else
  {
    v7 = _kvmalloc_node_noprof(4880, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(v5 + 3680) = v7;
    if ( !v7 )
      goto LABEL_52;
  }
  *(_DWORD *)(v5 + 92) = 0;
  *(_QWORD *)(v5 + 96) = a1;
  *v3 = 0;
  if ( mem_trace_en == 1 )
    v8 = cam_mem_trace_alloc(2080, 0xCC0u, 0, "cam_virtual_cdm_probe", 0x102u);
  else
    v8 = _kvmalloc_node_noprof(2080, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(v5 + 3392) = v8;
  if ( !v8 )
  {
    v10 = -12;
LABEL_58:
    v26 = *(_QWORD **)(v5 + 3680);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v26, 0);
    else
      kvfree(v26);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v5, 0);
    else
      kvfree(v5);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v3, 0);
    else
      kvfree(v3);
    result = v10;
    goto LABEL_68;
  }
  v9 = ((__int64 (__fastcall *)(__int64))cam_cdm_soc_load_dt_private)(a1);
  if ( v9 )
  {
    v10 = v9;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_virtual_cdm_probe",
      266,
      "Failed to load CDM dt private data");
    v11 = *(_QWORD **)(v5 + 3392);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v11, 0);
    else
      kvfree(v11);
    *(_QWORD *)(v5 + 3392) = 0;
    goto LABEL_58;
  }
  v12 = *(unsigned __int8 **)(v5 + 3392);
  v13 = *(_QWORD *)(v5 + 3680);
  v14 = *v12;
  *(_BYTE *)(v13 + 4864) = 0;
  *(_DWORD *)(v13 + 136) = v14 ^ 1;
  *(_QWORD *)(v13 + 184) = v13 + 184;
  *(_QWORD *)(v13 + 192) = v13 + 184;
  *(_DWORD *)(v13 + 144) = 0;
  _init_swait_queue_head(v13 + 152, "&x->wait", &init_completion___key_2);
  *((_QWORD *)v3 + 1) = cam_cdm_get_caps;
  *((_QWORD *)v3 + 2) = 0;
  *((_QWORD *)v3 + 7) = cam_cdm_stream_start;
  *((_QWORD *)v3 + 8) = cam_cdm_stream_stop;
  *((_QWORD *)v3 + 10) = 0;
  *((_QWORD *)v3 + 11) = cam_cdm_process_cmd;
  v15 = debug_mdl;
  *((_QWORD *)v3 + 14) = v5;
  *((_QWORD *)v3 + 3) = 0;
  *((_QWORD *)v3 + 9) = 0;
  if ( (v15 & 1) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_virtual_cdm_probe",
      294,
      "type %d index %d",
      *v3,
      v3[1]);
  *(_QWORD *)(a1 + 168) = v3;
  *(_DWORD *)(v5 + 88) = 0;
  *(_QWORD *)(v13 + 224) = -1;
  _mutex_init(v5, "&cdm_hw->hw_mutex", &cam_virtual_cdm_probe___key);
  *(_DWORD *)(v5 + 48) = 0;
  *(_DWORD *)(v5 + 56) = 0;
  _init_swait_queue_head(v5 + 64, "&x->wait", &init_completion___key_2);
  mutex_lock(v5);
  strcpy((char *)(v13 + 4), "qcom,cam_virtual_cdm");
  *(_DWORD *)(v13 + 132) = 0;
  v17 = alloc_workqueue(v13 + 4, 74, 5, v16);
  *(_QWORD *)(v13 + 176) = v17;
  if ( !v17 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_virtual_cdm_probe",
      313,
      "Workqueue allocation failed for cdm %s",
      (const char *)(v13 + 4));
    v10 = 0;
LABEL_41:
    v24 = *(_QWORD **)(v5 + 3392);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v24, 0);
    else
      kvfree(v24);
    mutex_unlock(v5);
    goto LABEL_58;
  }
  *(_QWORD *)(v13 + 240) = 0;
  v31 = cam_cdm_cpas_cb;
  v18 = *(_DWORD *)(v5 + 116);
  v29 = a1 + 16;
  v30 = v3;
  LODWORD(v28) = v18;
  strcpy((char *)v27, "cam-cdm-intf");
  v19 = cam_cpas_register_client((__int64)v27);
  if ( v19 )
  {
    v10 = v19;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_virtual_cdm_probe",
      326,
      "Virtual CDM CPAS registration failed");
LABEL_37:
    v23 = *(_QWORD **)(v5 + 3392);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v23, 0);
    else
      kvfree(v23);
    _flush_workqueue(*(_QWORD *)(v13 + 176));
    destroy_workqueue(*(_QWORD *)(v13 + 176));
    mutex_unlock(v5);
    goto LABEL_41;
  }
  v20 = debug_priority;
  v21 = debug_mdl & 1;
  if ( (debug_mdl & 1) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_virtual_cdm_probe",
      330,
      "CPAS registration successful handle=%d",
      v32);
    v20 = debug_priority;
    v21 = debug_mdl & 1;
  }
  *(_DWORD *)(v13 + 4868) = v32;
  if ( v21 && !v20 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_virtual_cdm_probe",
      333,
      "CDM%d probe successful",
      v3[1]);
  v22 = cam_cdm_intf_register_hw_cdm((__int64)v3, (__int64)v12, 0, (int *)v13);
  if ( v22 )
  {
    v10 = v22;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_virtual_cdm_probe",
      338,
      "Virtual CDM Interface registration failed");
    cam_cpas_unregister_client(*(_DWORD *)(v13 + 4868));
    goto LABEL_37;
  }
  if ( (debug_mdl & 1) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_virtual_cdm_probe",
      342,
      "CDM%d registered to intf successful",
      v3[1]);
  mutex_unlock(v5);
  result = 0;
LABEL_68:
  _ReadStatusReg(SP_EL0);
  return result;
}
