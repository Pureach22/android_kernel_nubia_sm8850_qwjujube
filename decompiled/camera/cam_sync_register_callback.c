__int64 __fastcall cam_sync_register_callback(_DWORD *a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 v7; // x23
  __int64 v8; // x20
  __int64 v9; // x0
  unsigned int v10; // w19
  __int64 v11; // x2
  _QWORD *v12; // x8
  _QWORD *v13; // x1
  __int64 v14; // x26
  unsigned int v15; // w20
  __int64 v16; // x21
  __int64 v17; // x22
  char v18; // w8
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // [xsp+18h] [xbp+18h]

  result = 4294967274LL;
  if ( a1 && a3 - 1 <= 0x7FE )
  {
    v7 = a3;
    raw_spin_lock_bh(sync_dev + 4LL * a3 + 136);
    v8 = *(_QWORD *)(sync_dev + 128) + 216LL * a3;
    if ( !*(_DWORD *)(v8 + 104) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        128,
        1,
        "cam_sync_register_callback",
        160,
        "Error: accessing an uninitialized sync obj %s[%d]",
        (const char *)(*(_QWORD *)(sync_dev + 128) + 216LL * a3),
        a3);
      v10 = -22;
LABEL_37:
      cam_sync_dump_monitor_array(v8);
      raw_spin_unlock_bh(sync_dev + 4 * v7 + 136);
      return v10;
    }
    if ( mem_trace_en == 1 )
    {
      v9 = cam_mem_trace_alloc(80, 0x820u, 0, "cam_sync_register_callback", 0xA5u);
      if ( !v9 )
        goto LABEL_36;
    }
    else
    {
      v9 = _kvmalloc_node_noprof(80, 0, 2336, 0xFFFFFFFFLL);
      if ( !v9 )
      {
LABEL_36:
        v10 = -12;
        goto LABEL_37;
      }
    }
    if ( (unsigned int)(*(_DWORD *)(v8 + 104) - 2) > 2 || *(_DWORD *)(v8 + 108) )
    {
      *(_QWORD *)v9 = a1;
      *(_QWORD *)(v9 + 8) = a2;
      v11 = v8 + 144;
      *(_DWORD *)(v9 + 20) = a3;
      *(_QWORD *)(v9 + 32) = 0xFFFFFFFE00000LL;
      v12 = (_QWORD *)(v9 + 64);
      *(_QWORD *)(v9 + 40) = v9 + 40;
      *(_QWORD *)(v9 + 48) = v9 + 40;
      *(_QWORD *)(v9 + 56) = cam_sync_util_cb_dispatch;
      v13 = *(_QWORD **)(v8 + 152);
      if ( v9 + 64 == v8 + 144 || v13 == v12 || *v13 != v11 )
      {
        _list_add_valid_or_report(v9 + 64);
      }
      else
      {
        *(_QWORD *)(v8 + 152) = v12;
        *(_QWORD *)(v9 + 64) = v11;
        *(_QWORD *)(v9 + 72) = v13;
        *v13 = v12;
      }
      if ( (cam_sync_monitor_mask & 2) != 0 )
        cam_generic_fence_update_monitor_array(a3, sync_dev + 8328, *(_QWORD *)(sync_dev + 8672), 1);
    }
    else
    {
      if ( (cam_sync_monitor_mask & 2) != 0 )
      {
        v14 = v9;
        cam_generic_fence_update_monitor_array(a3, sync_dev + 8328, *(_QWORD *)(sync_dev + 8672), 2);
        v9 = v14;
      }
      if ( trigger_cb_without_switch == 1 )
      {
        if ( (debug_mdl & 0x80) != 0 && !debug_priority )
        {
          v21 = v9;
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            (unsigned __int8)debug_mdl & 0x80,
            4,
            "cam_sync_register_callback",
            184,
            "Invoke callback for sync object:%s[%d]",
            (const char *)v8,
            a3);
          v9 = v21;
        }
        v15 = *(_DWORD *)(v8 + 104);
        if ( mem_trace_en == 1 )
          cam_mem_trace_free((_QWORD *)v9, 0);
        else
          kvfree(v9);
        raw_spin_unlock_bh(sync_dev + 4LL * a3 + 136);
        if ( *(a1 - 1) != 1136383842 )
          __break(0x8236u);
        ((void (__fastcall *)(_QWORD, _QWORD, __int64))a1)(a3, v15, a2);
        return 0;
      }
      *(_QWORD *)v9 = a1;
      *(_QWORD *)(v9 + 8) = a2;
      *(_QWORD *)(v9 + 32) = 0xFFFFFFFE00000LL;
      v16 = v9 + 32;
      *(_DWORD *)(v9 + 20) = a3;
      *(_QWORD *)(v9 + 40) = v9 + 40;
      v17 = v9;
      *(_QWORD *)(v9 + 48) = v9 + 40;
      *(_QWORD *)(v9 + 56) = cam_sync_util_cb_dispatch;
      v18 = debug_mdl;
      *(_DWORD *)(v9 + 16) = *(_DWORD *)(v8 + 104);
      if ( v18 < 0 && !debug_priority )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v18 & 0x80,
          4,
          "cam_sync_register_callback",
          198,
          "Enqueue callback for sync object:%s[%d]",
          (const char *)v8,
          a3);
      v19 = ktime_get_with_offset(1);
      v20 = sync_dev;
      *(_QWORD *)(v17 + 24) = v19;
      queue_work_on(32, *(_QWORD *)(v20 + 8392), v16);
    }
    raw_spin_unlock_bh(sync_dev + 4LL * a3 + 136);
    return 0;
  }
  return result;
}
