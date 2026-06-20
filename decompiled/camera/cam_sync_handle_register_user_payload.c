__int64 __fastcall cam_sync_handle_register_user_payload(__int64 a1)
{
  __int64 v1; // x1
  __int64 result; // x0
  __int64 v3; // x19
  _QWORD *v4; // x20
  __int64 v5; // x9
  __int64 v6; // x8
  __int64 v7; // x21
  int v8; // w2
  _QWORD *v9; // x10
  _QWORD *v10; // x21
  _QWORD *v11; // t1
  _QWORD *v12; // x11
  __int64 v13; // [xsp+0h] [xbp-20h] BYREF
  __int64 v14; // [xsp+8h] [xbp-18h]
  __int64 v15; // [xsp+10h] [xbp-10h]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 4) != 24 )
    goto LABEL_6;
  v1 = *(_QWORD *)(a1 + 16);
  if ( !v1 )
    goto LABEL_6;
  v14 = 0;
  v15 = 0;
  v13 = 0;
  if ( inline_copy_from_user_2((int)&v13, v1, 0x18u) )
  {
    result = 4294967282LL;
    goto LABEL_7;
  }
  v3 = (unsigned int)v13;
  if ( (unsigned int)(v13 - 2048) < 0xFFFFF801 )
  {
LABEL_6:
    result = 4294967274LL;
    goto LABEL_7;
  }
  if ( mem_trace_en == 1 )
  {
    v4 = (_QWORD *)cam_mem_trace_alloc(32, 0xCC0u, 0, "cam_sync_handle_register_user_payload", 0x356u);
    if ( v4 )
      goto LABEL_10;
LABEL_16:
    result = 4294967284LL;
    goto LABEL_7;
  }
  v4 = (_QWORD *)_kvmalloc_node_noprof(32, 0, 3520, 0xFFFFFFFFLL);
  if ( !v4 )
    goto LABEL_16;
LABEL_10:
  v5 = v15;
  *v4 = v14;
  v4[1] = v5;
  raw_spin_lock_bh(sync_dev + 4 * v3 + 136);
  v6 = sync_dev;
  v7 = *(_QWORD *)(sync_dev + 128) + 216LL * (unsigned int)v3;
  v8 = *(_DWORD *)(v7 + 104);
  if ( (unsigned int)(v8 - 2) < 3 )
  {
    if ( (cam_sync_monitor_mask & 2) != 0 )
    {
      cam_generic_fence_update_monitor_array((unsigned int)v3, sync_dev + 8328, *(_QWORD *)(sync_dev + 8672), 2);
      v8 = *(_DWORD *)(v7 + 104);
    }
    cam_sync_util_send_v4l2_event(0, v3, v8, v4);
    raw_spin_unlock_bh(sync_dev + 4 * v3 + 136);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v4, 0);
    else
      kvfree(v4);
LABEL_35:
    result = 0;
    goto LABEL_7;
  }
  if ( v8 )
  {
    v11 = *(_QWORD **)(v7 + 160);
    v10 = (_QWORD *)(v7 + 160);
    v9 = v11;
    if ( v11 == v10 )
    {
LABEL_32:
      list_add_tail_0(v4 + 2, v10);
      if ( (cam_sync_monitor_mask & 2) != 0 )
        cam_generic_fence_update_monitor_array((unsigned int)v3, sync_dev + 8328, *(_QWORD *)(sync_dev + 8672), 1);
      raw_spin_unlock_bh(sync_dev + 4 * v3 + 136);
      goto LABEL_35;
    }
    while ( 1 )
    {
      v12 = (_QWORD *)*v9;
      if ( *(v9 - 2) == *v4 && *(v9 - 1) == v4[1] )
        break;
      v9 = (_QWORD *)*v9;
      if ( v12 == v10 )
        goto LABEL_32;
    }
    if ( (cam_sync_monitor_mask & 2) != 0 )
    {
      cam_generic_fence_update_monitor_array((unsigned int)v3, sync_dev + 8328, *(_QWORD *)(sync_dev + 8672), 3);
      v6 = sync_dev;
    }
    raw_spin_unlock_bh(v6 + 4 * v3 + 136);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v4, 0);
    else
      kvfree(v4);
    result = 4294967182LL;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_handle_register_user_payload",
      868,
      "Error: accessing an uninitialized sync obj = %s[%d]",
      (const char *)(*(_QWORD *)(sync_dev + 128) + 216LL * (unsigned int)v3),
      v3);
    raw_spin_unlock_bh(sync_dev + 4 * v3 + 136);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v4, 0);
    else
      kvfree(v4);
    result = 4294967274LL;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
