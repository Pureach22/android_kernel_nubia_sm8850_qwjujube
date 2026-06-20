__int64 __fastcall cam_sync_util_dispatch_signaled_cb(__int64 result, int a2)
{
  unsigned int v2; // w19
  __int64 v3; // x20
  _QWORD *v5; // x23
  _QWORD *v6; // x8
  _QWORD *v7; // x28
  __int64 v8; // x20
  _QWORD *v9; // x24
  _QWORD *v10; // t1
  _QWORD *v11; // x26
  __int64 v12; // x21
  _QWORD *v13; // x8
  _QWORD *v14; // x9
  _QWORD *v15; // x0
  __int64 v16; // [xsp+0h] [xbp-10h]

  v2 = result;
  v3 = *(_QWORD *)(sync_dev + 128) + 216LL * (int)result;
  if ( *(_DWORD *)(v3 + 104) )
  {
    v5 = *(_QWORD **)(v3 + 144);
    v16 = *(_QWORD *)(sync_dev + 128) + 216LL * (int)result;
    if ( v5 != (_QWORD *)(v3 + 144) )
    {
      do
      {
        v7 = (_QWORD *)*v5;
        v6 = (_QWORD *)v5[1];
        *((_DWORD *)v5 - 12) = a2;
        if ( (_QWORD *)*v6 == v5 && (_QWORD *)v7[1] == v5 )
        {
          v7[1] = v6;
          *v6 = v7;
        }
        else
        {
          _list_del_entry_valid_or_report(v5);
        }
        *v5 = v5;
        v5[1] = v5;
        if ( (cam_sync_monitor_mask & 2) != 0 )
          cam_generic_fence_update_monitor_array(v2, sync_dev + 8328, *(_QWORD *)(sync_dev + 8672), 5);
        queue_work_on(32, *(_QWORD *)(sync_dev + 8392), v5 - 4);
        v5 = v7;
      }
      while ( v7 != (_QWORD *)(v3 + 144) );
    }
    v10 = *(_QWORD **)(v3 + 160);
    v8 = v3 + 160;
    v9 = v10;
    if ( v10 != (_QWORD *)v8 )
    {
      do
      {
        v11 = (_QWORD *)*v9;
        raw_spin_lock_bh(sync_dev + 8408);
        v12 = *(_QWORD *)(sync_dev + 8400);
        raw_spin_unlock_bh(sync_dev + 8408);
        if ( !v12 )
          break;
        cam_sync_util_send_v4l2_event(0, v2, a2, v9 - 2);
        v13 = (_QWORD *)v9[1];
        if ( (_QWORD *)*v13 == v9 && (v14 = (_QWORD *)*v9, *(_QWORD **)(*v9 + 8LL) == v9) )
        {
          v14[1] = v13;
          *v13 = v14;
        }
        else
        {
          _list_del_entry_valid_or_report(v9);
        }
        *v9 = v9;
        v9[1] = v9;
        if ( (cam_sync_monitor_mask & 2) != 0 )
          cam_generic_fence_update_monitor_array(v2, sync_dev + 8328, *(_QWORD *)(sync_dev + 8672), 5);
        v15 = v9 - 2;
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v15, 0);
        else
          kvfree(v15);
        v9 = v11;
      }
      while ( v11 != (_QWORD *)v8 );
    }
    return complete_all(v16 + 112);
  }
  else if ( (debug_mdl & 0x80) != 0 && !debug_priority )
  {
    return ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             (unsigned __int8)debug_mdl & 0x80,
             4,
             "cam_sync_util_dispatch_signaled_cb",
             688,
             "Accessing invalid sync object:%s[%i]",
             (const char *)v3,
             result);
  }
  return result;
}
