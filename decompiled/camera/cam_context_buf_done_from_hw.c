__int64 __fastcall cam_context_buf_done_from_hw(__int64 a1, __int64 a2, int a3)
{
  __int64 *v7; // x20
  __int64 **v8; // x8
  __int64 *v9; // x9
  __int64 v10; // x0
  int v11; // w8
  unsigned int v12; // w22
  unsigned int v13; // w27
  int buffers_from_packet; // w0
  __int64 v15; // x24
  __int64 v16; // x24
  __int64 v17; // x7
  const char *v18; // x5
  __int64 v19; // x4
  __int64 v20; // x0
  unsigned int v21; // w19
  __int64 v22; // x0
  __int64 v23; // [xsp+0h] [xbp-10h]
  __int64 v24; // [xsp+8h] [xbp-8h]

  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_buf_done_from_hw",
      179,
      "Invalid input params %pK %pK",
      (const void *)a1,
      (const void *)a2);
    return 4294967274LL;
  }
  if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFFFF00) != 0 )
  {
    _warn_printk("Invalid execution context\n");
    __break(0x800u);
    return 4294967274LL;
  }
  raw_spin_lock(a1 + 120);
  v7 = *(__int64 **)(a1 + 128);
  if ( v7 == (__int64 *)(a1 + 128) )
  {
    v17 = *(unsigned int *)(a1 + 32);
    v18 = "[%s][%d] no active request";
    v19 = 190;
LABEL_32:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, __int64, __int64))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_buf_done_from_hw",
      v19,
      v18,
      a1,
      v17,
      v23,
      v24);
LABEL_33:
    raw_spin_unlock(a1 + 120);
    return 4294967291LL;
  }
  if ( *(_QWORD *)(a2 + 168) != v7[3] )
  {
    v17 = *(unsigned int *)(a1 + 32);
    v18 = "[%s][%d] mismatch: done req[%lld], active req[%lld]";
    v23 = *(_QWORD *)(a2 + 168);
    v24 = v7[3];
    v19 = 203;
    goto LABEL_32;
  }
  if ( !*((_DWORD *)v7 + 20) )
  {
    if ( (debug_mdl & 0x80000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x80000,
        4,
        "cam_context_buf_done_from_hw",
        210,
        "[%s][%d] no output fence to signal",
        (const char *)a1,
        *(_DWORD *)(a1 + 32));
    list_del_init(v7);
    cam_smmu_buffer_tracker_putref(v7 + 14);
    v20 = v7[17];
    if ( v20 )
    {
      cam_common_mem_free(v20);
      v7[17] = 0;
    }
    v7[13] = 0;
    list_add_tail(v7, a1 + 176);
    goto LABEL_33;
  }
  v8 = (__int64 **)v7[1];
  if ( *v8 == v7 && (v9 = (__int64 *)*v7, *(__int64 **)(*v7 + 8) == v7) )
  {
    v9[1] = (__int64)v8;
    *v8 = v9;
  }
  else
  {
    _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 128));
  }
  *v7 = (__int64)v7;
  v7[1] = (__int64)v7;
  raw_spin_unlock(a1 + 120);
  v10 = cam_smmu_buffer_tracker_putref(v7 + 14);
  if ( a3 == 2 )
    v11 = 4;
  else
    v11 = 3;
  if ( a3 )
    v12 = v11;
  else
    v12 = 2;
  if ( (debug_mdl & 0x1080000) == 0 || debug_priority )
  {
    if ( *((_DWORD *)v7 + 20) )
      goto LABEL_21;
LABEL_43:
    if ( (*(_QWORD *)(a1 + 24) & (unsigned int)cam_debug_ctx_req_list) != 0 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x80000,
        3,
        "cam_context_buf_done_from_hw",
        264,
        "[%s][%d] : Moving req[%llu] from active_list to free_list",
        (const char *)a1,
        *(_DWORD *)(a1 + 32),
        v7[3]);
    cam_cpas_notify_event(a1 + 276, *((unsigned int *)v7 + 6));
    v22 = v7[17];
    if ( v22 )
    {
      cam_common_mem_free(v22);
      v7[17] = 0;
    }
    v7[13] = 0;
    raw_spin_lock(a1 + 120);
    list_add_tail(v7, a1 + 176);
    raw_spin_unlock(a1 + 120);
    return 0;
  }
  v10 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x1080000,
          4,
          "cam_context_buf_done_from_hw",
          241,
          "[%s][ctx_id %d] : req[%llu] : Signaling %d",
          (const char *)a1,
          *(_DWORD *)(a1 + 32),
          v7[3],
          v12);
  if ( !*((_DWORD *)v7 + 20) )
    goto LABEL_43;
LABEL_21:
  v13 = 0;
  while ( 1 )
  {
    if ( (cam_presil_mode_enabled(v10) & 1) != 0 )
    {
      buffers_from_packet = cam_presil_retrieve_buffers_from_packet(
                              (unsigned int *)v7[17],
                              *(_DWORD *)(a1 + 512),
                              *(_DWORD *)(v7[9] + ((__int64)(int)v13 << 6)));
      if ( buffers_from_packet )
        break;
    }
    if ( (debug_mdl & 0x1080000) != 0 && !debug_priority )
    {
      v15 = (int)v13;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1080000,
        4,
        "cam_context_buf_done_from_hw",
        255,
        "fence %d signal with %d",
        *(_DWORD *)(v7[9] + ((__int64)(int)v13 << 6) + 16),
        v12);
    }
    else
    {
      v15 = (int)v13;
    }
    v16 = v15 << 6;
    v10 = cam_sync_signal(*(unsigned int *)(v7[9] + v16 + 16), v12, *(unsigned int *)(a2 + 176));
    ++v13;
    *(_DWORD *)(v7[9] + v16 + 16) = -1;
    if ( v13 >= *((_DWORD *)v7 + 20) )
      goto LABEL_43;
  }
  v21 = buffers_from_packet;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x80000,
    1,
    "cam_context_buf_done_from_hw",
    249,
    "Failed to retrieve image buffers rc:%d",
    buffers_from_packet);
  return v21;
}
