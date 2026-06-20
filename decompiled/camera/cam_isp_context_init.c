__int64 __fastcall cam_isp_context_init(__int64 *a1, __int64 a2, __int64 a3, __int64 a4, int a5, int a6, int a7)
{
  _QWORD *v10; // x26
  _QWORD *v11; // x27
  _QWORD *v12; // x28
  __int64 v17; // x1
  unsigned int v18; // w0
  int v19; // w6
  int v20; // w7
  unsigned int v21; // w19
  __int64 result; // x0
  _QWORD **v23; // x21
  __int64 v24; // x0
  _QWORD *v25; // x8
  _QWORD *v26; // x1
  __int64 v27; // x0
  _QWORD *v28; // x8
  _QWORD *v29; // x1
  __int64 v30; // x0
  _QWORD *v31; // x8
  _QWORD *v32; // x1
  _DWORD *v33; // x8
  __int64 v34; // x9
  _QWORD *v35; // x9
  _QWORD *v36; // x8
  _QWORD *v37; // x20
  _QWORD *v38; // x0
  unsigned __int64 v39[2]; // [xsp+10h] [xbp-10h] BYREF

  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_context_init",
      10808,
      "Invalid Context");
    result = 0xFFFFFFFFLL;
    goto LABEL_50;
  }
  v10 = a1 + 5264;
  v11 = a1 + 4662;
  v12 = a1 + 4098;
  memset(a1 + 2, 0, 0xB2B8u);
  *a1 = a2;
  a1[1] = 0;
  *((_BYTE *)v10 + 3632) = 0;
  *((_DWORD *)v11 + 6) = 0;
  *((_DWORD *)v11 + 20) = 0;
  v11[12] = 0;
  *v11 = 0;
  a1[4] = (__int64)&cam_isp_ctx_activated_state_machine;
  a1[5] = (__int64)cam_isp_ctx_activated_state_machine_irq;
  *((_DWORD *)v10 + 866) = jiffies_to_msecs(jiffies, v17);
  a1[10] = (__int64)(a1 + 150);
  a1[714] = (__int64)(a1 + 24);
  a1[28] = (__int64)(a1 + 714);
  a1[1278] = (__int64)(a1 + 42);
  a1[46] = (__int64)(a1 + 1278);
  a1[1842] = (__int64)(a1 + 60);
  a1[64] = (__int64)(a1 + 1842);
  a1[2406] = (__int64)(a1 + 78);
  a1[82] = (__int64)(a1 + 2406);
  a1[2970] = (__int64)(a1 + 96);
  a1[100] = (__int64)(a1 + 2970);
  a1[118] = (__int64)(a1 + 3534);
  *((_DWORD *)v10 + 867) = a6;
  a1[150] = (__int64)(a1 + 6);
  a1[3534] = (__int64)(a1 + 114);
  a1[136] = (__int64)v12;
  *v12 = a1 + 132;
  v18 = cam_context_init(a2, "cam-isp", 8, a5, a3, a4, (__int64)(a1 + 6), 8, a7);
  if ( v18 )
  {
    v19 = *(_DWORD *)(a2 + 32);
    v20 = *(_DWORD *)(a2 + 64);
    v21 = v18;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_context_init",
      10844,
      "Camera Context Base init failed, ctx_idx: %u, link: 0x%x",
      v19,
      v20);
    result = v21;
    goto LABEL_50;
  }
  v23 = (_QWORD **)(v10 + 451);
  v10[451] = v10 + 451;
  v10[452] = v10 + 451;
  if ( mem_trace_en == 1 )
  {
    v24 = cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_isp_context_init", 0x2A63u);
    if ( !v24 )
      goto LABEL_39;
  }
  else
  {
    v24 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
    if ( !v24 )
      goto LABEL_39;
  }
  v25 = (_QWORD *)(v24 + 8);
  v26 = (_QWORD *)v10[452];
  if ( (_QWORD **)(v24 + 8) != v23 && v25 != v26 && (_QWORD **)*v26 == v23 )
  {
    v10[452] = v25;
    *(_QWORD *)(v24 + 8) = v23;
    *(_QWORD *)(v24 + 16) = v26;
    *v26 = v25;
    if ( (mem_trace_en & 1) != 0 )
      goto LABEL_14;
LABEL_17:
    v27 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
    if ( !v27 )
      goto LABEL_39;
    goto LABEL_18;
  }
  _list_add_valid_or_report(v24 + 8);
  if ( (mem_trace_en & 1) == 0 )
    goto LABEL_17;
LABEL_14:
  v27 = cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_isp_context_init", 0x2A63u);
  if ( !v27 )
    goto LABEL_39;
LABEL_18:
  v28 = (_QWORD *)(v27 + 8);
  v29 = (_QWORD *)v10[452];
  if ( (_QWORD **)(v27 + 8) == v23 || v28 == v29 || (_QWORD **)*v29 != v23 )
  {
    _list_add_valid_or_report(v27 + 8);
    if ( (mem_trace_en & 1) != 0 )
    {
LABEL_22:
      v30 = cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_isp_context_init", 0x2A63u);
      if ( !v30 )
        goto LABEL_39;
LABEL_26:
      v31 = (_QWORD *)(v30 + 8);
      v32 = (_QWORD *)v10[452];
      if ( (_QWORD **)(v30 + 8) == v23 || v31 == v32 || (_QWORD **)*v32 != v23 )
      {
        _list_add_valid_or_report(v30 + 8);
      }
      else
      {
        v10[452] = v31;
        *(_QWORD *)(v30 + 8) = v23;
        *(_QWORD *)(v30 + 16) = v32;
        *v32 = v31;
      }
      v33 = v11 + 21;
      *(_QWORD *)(a2 + 248) = &cam_isp_ctx_top_state_machine;
      *(_QWORD *)(a2 + 256) = a1;
      v34 = 84;
      do
      {
        v34 -= 2;
        *(v33 - 14) = 7;
        *v33 = 7;
        v33 += 28;
      }
      while ( v34 );
      v11[13] = -1;
      *v10 = -1;
      v10[1] = -1;
      v10[2] = -1;
      v10[3] = -1;
      v10[4] = -1;
      v10[5] = -1;
      v10[390] = -1;
      if ( isp_ctx_debug )
      {
        result = 0;
      }
      else
      {
        v39[0] = 0;
        if ( (unsigned int)cam_debugfs_create_subdir("isp_ctx", v39) )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            8,
            1,
            "cam_isp_context_debug_register",
            10776,
            "DebugFS could not create directory!");
        }
        else
        {
          isp_ctx_debug = v39[0];
          debugfs_create_u32("enable_state_monitor_dump", 420, v39[0], &unk_3A8B88);
          debugfs_create_u8("enable_cdm_cmd_buffer_dump", 420, isp_ctx_debug, &byte_3A8B90);
          debugfs_create_u32("disable_internal_recovery_mask", 420, isp_ctx_debug, &byte_3A8B8C);
          debugfs_create_bool("wait_indefinitely_mup_sync", 420);
        }
        result = 0;
      }
      goto LABEL_50;
    }
  }
  else
  {
    v10[452] = v28;
    *(_QWORD *)(v27 + 8) = v23;
    *(_QWORD *)(v27 + 16) = v29;
    *v29 = v28;
    if ( (mem_trace_en & 1) != 0 )
      goto LABEL_22;
  }
  v30 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
  if ( v30 )
    goto LABEL_26;
LABEL_39:
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_isp_context_init",
    10855,
    "Failed to allocate memory for FCG struct, ctx_idx: %u, link: %x",
    *(_DWORD *)(a2 + 32),
    *(_DWORD *)(a2 + 64));
  v35 = *v23;
  if ( *v23 != v23 )
  {
    do
    {
      v37 = (_QWORD *)*v35;
      v36 = (_QWORD *)v35[1];
      if ( (_QWORD *)*v36 == v35 && (_QWORD *)v37[1] == v35 )
      {
        v37[1] = v36;
        *v36 = v37;
      }
      else
      {
        _list_del_entry_valid_or_report(v35);
      }
      v38 = v35 - 1;
      *v35 = 0xDEAD000000000100LL;
      v35[1] = 0xDEAD000000000122LL;
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v38, 0);
      else
        kvfree(v38);
      v35 = v37;
    }
    while ( v37 != v23 );
  }
  result = 4294967284LL;
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
