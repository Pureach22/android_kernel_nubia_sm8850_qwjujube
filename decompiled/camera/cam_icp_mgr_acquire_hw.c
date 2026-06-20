__int64 __fastcall cam_icp_mgr_acquire_hw(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x20
  __int64 v7; // x8
  __int64 v8; // x24
  __int64 v9; // x26
  __int64 v10; // x0
  __int64 v11; // x20
  _QWORD **v12; // x21
  unsigned int unique_tbl; // w27
  _DWORD *v14; // x27
  unsigned int v15; // w6
  __int64 v16; // x11
  const char *v17; // x0
  unsigned int v18; // w0
  const char *v19; // x0
  _QWORD *v20; // x0
  __int64 v21; // x0
  _QWORD *v22; // x0
  _QWORD *v23; // x0
  unsigned int v24; // w0
  unsigned int v25; // w0
  int v26; // w0
  int v27; // w27
  int handle; // w0
  int inited; // w0
  int v30; // w8
  __int64 v31; // x8
  int v32; // w10
  int v33; // w8
  __int64 v34; // x0
  int v35; // w9
  int v36; // w0
  _QWORD *v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int16 v40; // w8
  _DWORD *v41; // x21
  _DWORD *v42; // [xsp+28h] [xbp-28h]
  _DWORD *v43; // [xsp+28h] [xbp-28h]
  __int64 v44; // [xsp+30h] [xbp-20h]
  int v45; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v46; // [xsp+48h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_acquire_hw",
      8884,
      "Invalid params: %pK %pK",
      (const void *)a1,
      a2);
    result = 4294967274LL;
    goto LABEL_36;
  }
  if ( *((_DWORD *)a2 + 8) >= 2u )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_acquire_hw",
      8890,
      "[%s] number of resources are wrong: %u",
      a1 + 112);
    result = 4294967274LL;
    goto LABEL_36;
  }
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_acquire_hw",
      8894,
      "[%s] ENTER Api = %d",
      (const char *)(a1 + 112),
      *((_DWORD *)a2 + 48));
  *(_WORD *)((char *)&v45 + 1) = 1;
  mutex_lock(a1);
  if ( mem_trace_en != 1 )
  {
    v5 = _kvmalloc_node_noprof(30192, 0, 3520, 0xFFFFFFFFLL);
    v6 = v5;
    if ( v5 )
      goto LABEL_11;
LABEL_17:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_allocate_ctx",
      4343,
      "Failed to allocate ctx data in the queue");
LABEL_34:
    unique_tbl = 0;
LABEL_35:
    mutex_unlock(a1);
    result = unique_tbl;
    goto LABEL_36;
  }
  v5 = cam_mem_trace_alloc(30192, 0xCC0u, 0, "cam_icp_mgr_allocate_ctx", 0x10F5u);
  v6 = v5;
  if ( !v5 )
    goto LABEL_17;
LABEL_11:
  v7 = *(_QWORD *)(a1 + 96);
  v8 = 0;
  v9 = 0;
  while ( *(_QWORD *)(v7 + 8 * v9) )
  {
    ++v9;
    v8 -= 48;
    if ( v9 == 54 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_allocate_ctx",
        4357,
        "No enough slots for ctx data");
      if ( mem_trace_en == 1 )
        cam_mem_trace_free((_QWORD *)v6, 0);
      else
        kvfree(v6);
      goto LABEL_34;
    }
  }
  *(_QWORD *)(v7 + 8 * v9) = v6;
  *(_DWORD *)(v6 + 29224) = v9;
  *(_DWORD *)(v6 + 104) = 1;
  if ( (cam_presil_mode_enabled(v5) & 1) != 0 )
  {
    if ( mem_trace_en == 1 )
      v10 = cam_mem_trace_alloc(6560, 0xCC0u, 0, "cam_icp_mgr_allocate_ctx", 0x110Du);
    else
      v10 = _kvmalloc_node_noprof(6560, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(v6 + 29184) = v10;
  }
  if ( (v9 & 0x80000000) != 0 )
    goto LABEL_34;
  mutex_lock(*(_QWORD *)(a1 + 88) - v8);
  v11 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 8 * v9);
  *(_QWORD *)(v11 + 8) = a1;
  v12 = (_QWORD **)(v11 + 30176);
  *(_DWORD *)(v11 + 88) = *((_DWORD *)a2 + 48);
  unique_tbl = cam_packet_util_get_unique_tbl((_QWORD *)(v11 + 30176), (__int64 *)(v11 + 30184));
  if ( unique_tbl )
  {
LABEL_45:
    v21 = cam_icp_mgr_process_dbg_buf(a1);
    if ( (cam_presil_mode_enabled(v21) & 1) != 0 )
    {
      v22 = *(_QWORD **)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 8 * v9) + 29184LL);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v22, 0);
      else
        kvfree(v22);
      *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 8 * v9) + 29184LL) = 0;
    }
    v23 = *(_QWORD **)(*(_QWORD *)(a1 + 96) + 8 * v9);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v23, 0);
    else
      kvfree(v23);
    *(_QWORD *)(*(_QWORD *)(a1 + 96) + 8 * v9) = 0;
    mutex_unlock(*(_QWORD *)(a1 + 88) - v8);
    goto LABEL_35;
  }
  unique_tbl = cam_icp_mgr_handle_acquire_info(a2, v11, 1);
  if ( unique_tbl )
  {
LABEL_44:
    cam_packet_util_put_unique_tbl(*v12, *(_QWORD **)(v11 + 30184));
    *v12 = nullptr;
    *(_QWORD *)(v11 + 30184) = 0;
    goto LABEL_45;
  }
  v14 = *(_DWORD **)(v11 + 80);
  v15 = v14[1];
  if ( v15 - 1 >= 9 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_get_hw_dev_type",
      8706,
      "Invalid resource type: %u",
      v15);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_acquire_hw",
      8921,
      "[%s] Wrong hw device type in acquire: %u",
      (const char *)(a1 + 112),
      v14[1]);
LABEL_39:
    unique_tbl = -22;
LABEL_40:
    v20 = *(_QWORD **)(v11 + 80);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v20, 0);
    else
      kvfree(v20);
    *(_QWORD *)(v11 + 80) = 0;
    *(_QWORD *)(v11 + 16) = 0;
    goto LABEL_44;
  }
  v16 = qword_451F90[v15 - 1];
  if ( (((unsigned __int64)*(unsigned int *)(a1 + 44180) >> v16) & 1) == 0 )
  {
    v19 = (const char *)cam_icp_dev_type_to_name(v15);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_acquire_hw",
      8929,
      "Attempt to acquire device %s not supported by [%s]",
      v19,
      (const char *)(a1 + 112));
    goto LABEL_39;
  }
  v44 = qword_451F90[v15 - 1];
  *(_QWORD *)(v11 + 16) = *(_QWORD *)(a1 + 56) + 584LL * *(char *)(a1 + v16 + 68);
  v17 = (const char *)cam_icp_dev_type_to_name((unsigned int)v14[1]);
  scnprintf(
    v11 + 29824,
    128,
    "[%s]_%s_ctx[%d]_hwmgr_ctx[%d]",
    (const char *)(a1 + 112),
    v17,
    *((_DWORD *)a2 + 2),
    *(_DWORD *)(v11 + 29224));
  v18 = cam_icp_mgr_try_icp_resume(a1, &v45);
  if ( v18 )
  {
    unique_tbl = v18;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_acquire_hw",
      8944,
      "Trigger resume failed, rc: %d",
      v18);
LABEL_31:
    if ( !*(_DWORD *)(a1 + 44080) && *(_BYTE *)(a1 + 44229) == 1 )
      cam_icp_mgr_icp_power_collapse(a1, &v45);
    goto LABEL_40;
  }
  if ( v14[4] == 1 )
  {
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_mgr_acquire_hw",
        8955,
        "%s: number of existing secure contexts = %d",
        *(unsigned int *)(a1 + 4 * v44 + 44240));
    v42 = v14;
    if ( *(_DWORD *)(a1 + 44240 + 4 * v44) )
      v24 = cam_icp_validate_secure_port_config(a1, v11);
    else
      v24 = cam_icp_handle_secure_port_config(v11, 0);
    unique_tbl = v24;
    if ( v24 )
      goto LABEL_31;
    v14 = v42;
    ++*(_DWORD *)(a1 + 44240 + 4 * v44);
  }
  v25 = cam_icp_mgr_device_resume(a1, v11);
  if ( v25 )
  {
LABEL_72:
    v30 = v14[4];
    unique_tbl = v25;
    if ( v30 == 1 )
    {
      v31 = a1 + 4 * v44;
      v32 = *(_DWORD *)(v31 + 44240) - 1;
      *(_DWORD *)(v31 + 44240) = v32;
      if ( !v32 )
        cam_icp_handle_secure_port_config(v11, 1);
    }
    goto LABEL_31;
  }
  v43 = v14;
  v26 = cam_icp_mgr_send_ping(a1, v11);
  if ( v26 )
  {
    v27 = v26;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_acquire_hw",
      8980,
      "%s: ping ack not received",
      (const char *)(v11 + 29824));
LABEL_71:
    cam_icp_mgr_dev_power_collapse(a1, v11);
    v25 = v27;
    v14 = v43;
    goto LABEL_72;
  }
  handle = cam_icp_mgr_create_handle(a1, (unsigned int)v14[1], v11);
  if ( handle )
  {
    v27 = handle;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_acquire_hw",
      8986,
      "%s: create handle failed",
      (const char *)(v11 + 29824));
    goto LABEL_71;
  }
  inited = cam_icp_mgr_send_init_config_io(a1, v11, v14);
  if ( inited )
  {
    v27 = inited;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_acquire_hw",
      8992,
      "%s: Init config io failed",
      (const char *)(v11 + 29824));
LABEL_70:
    cam_icp_mgr_destroy_handle(v11);
    goto LABEL_71;
  }
  *(_QWORD *)v11 = *a2;
  a2[6] = v11;
  v33 = (unsigned __int8)mem_trace_en;
  *((_DWORD *)a2 + 14) = *(_DWORD *)(v11 + 29224);
  if ( v33 == 1 )
  {
    v34 = cam_mem_trace_alloc(8, 0xCC0u, 0, "cam_icp_mgr_acquire_hw", 0x2328u);
    *(_QWORD *)(v11 + 1720) = v34;
    if ( v34 )
      goto LABEL_77;
LABEL_81:
    if ( (unsigned int)__ratelimit(&cam_icp_mgr_acquire_hw__rs, "cam_icp_mgr_acquire_hw") )
      v39 = 3;
    else
      v39 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      v39,
      256,
      1,
      "cam_icp_mgr_acquire_hw",
      9003,
      "%s: failed to allocate hfi frame bitmap",
      v11 + 29824);
    v27 = -12;
    goto LABEL_70;
  }
  v38 = _kvmalloc_node_noprof(8, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(v11 + 1720) = v38;
  if ( !v38 )
    goto LABEL_81;
LABEL_77:
  *(_QWORD *)(v11 + 29960) = 0;
  v35 = *(_DWORD *)(v11 + 76);
  *(_QWORD *)(v11 + 29952) = 0;
  *(_QWORD *)(v11 + 1728) = 64;
  *(_QWORD *)(v11 + 96) = a2[2];
  *v14 = v35;
  v36 = cam_icp_mgr_handle_acquire_info(a2, v11, 0);
  if ( v36 )
  {
    v27 = v36;
    v37 = *(_QWORD **)(v11 + 1720);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v37, 0);
    else
      kvfree(v37);
    *(_QWORD *)(v11 + 1720) = 0;
    goto LABEL_70;
  }
  cam_icp_ctx_clk_info_init(v11);
  v40 = debug_mdl;
  *(_DWORD *)(v11 + 104) = 2;
  if ( (v40 & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v40 & 0x100,
      4,
      "cam_icp_mgr_acquire_hw",
      9023,
      "%s: scratch size = %x fw_handle = %x",
      (const char *)(v11 + 29824),
      *v14,
      *(_DWORD *)(v11 + 72));
  cam_icp_device_timer_start(a1);
  cam_icp_ctx_timer_start(v11);
  ++*(_DWORD *)(a1 + 44080);
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_acquire_hw",
      9032,
      "%s: Acquire Done",
      (const char *)(v11 + 29824));
  ((void (*)(__int64, __int64, _QWORD, const char *, __int64, const char *, ...))cam_print_log)(
    2,
    256,
    0,
    "cam_icp_mgr_acquire_hw",
    9039,
    "%s: Acquired, in_res : format=%d, widht=%d, height=%d, fps=%d",
    (const char *)(v11 + 29824),
    *(_DWORD *)(*(_QWORD *)(v11 + 80) + 24LL),
    *(_DWORD *)(*(_QWORD *)(v11 + 80) + 28LL),
    *(_DWORD *)(*(_QWORD *)(v11 + 80) + 32LL),
    *(_DWORD *)(*(_QWORD *)(v11 + 80) + 36LL));
  v41 = *(_DWORD **)(v11 + 80);
  if ( v41[12] )
  {
    ((void (*)(__int64, __int64, _QWORD, const char *, __int64, const char *, ...))cam_print_log)(
      2,
      256,
      0,
      "cam_icp_mgr_acquire_hw",
      9047,
      "%s: Acquired, out_res[0] : format=%d, widht=%d, height=%d, fps=%d",
      (const char *)(v11 + 29824),
      v41[13],
      v41[14],
      v41[15],
      v41[16]);
    if ( *(_DWORD *)(*(_QWORD *)(v11 + 80) + 48LL) >= 2u )
      ((void (*)(__int64, __int64, _QWORD, const char *, __int64, const char *, ...))cam_print_log)(
        2,
        256,
        0,
        "cam_icp_mgr_acquire_hw",
        9054,
        "%s: Acquired, out_res[1] : format=%d, widht=%d, height=%d, fps=%d",
        (const char *)(v11 + 29824),
        v41[19],
        v41[20],
        v41[21],
        v41[22]);
  }
  mutex_unlock(*(_QWORD *)(a1 + 88) - v8);
  mutex_unlock(a1);
  result = 0;
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
