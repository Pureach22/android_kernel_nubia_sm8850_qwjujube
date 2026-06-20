__int64 __fastcall cam_sync_deregister_callback(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v7; // x24
  __int64 v8; // x20
  _QWORD *v9; // x27
  char v10; // w25
  _QWORD *v11; // x0
  _QWORD *v12; // x9
  _QWORD *v13; // x0
  __int64 v14; // t1
  _QWORD *v15; // x8
  _QWORD *v16; // x10

  if ( a3 - 2048 < 0xFFFFF801 )
    return 4294967274LL;
  v7 = a3;
  raw_spin_lock_bh(sync_dev + 4LL * a3 + 136);
  v8 = *(_QWORD *)(sync_dev + 128) + 216LL * a3;
  if ( *(_DWORD *)(v8 + 104) )
  {
    if ( (debug_mdl & 0x80) != 0 && !debug_priority )
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        (unsigned __int8)debug_mdl & 0x80,
        4,
        "cam_sync_deregister_callback",
        252,
        "deregistered callback for sync object:%s[%d]",
        (const char *)v8,
        a3);
    v9 = *(_QWORD **)(v8 + 144);
    if ( v9 == (_QWORD *)(v8 + 144) )
    {
      v10 = 0;
    }
    else
    {
      v10 = 0;
      do
      {
        v11 = v9;
        v12 = v9;
        v9 = (_QWORD *)*v9;
        v14 = *(v11 - 8);
        v13 = v11 - 8;
        if ( v14 == a1 && *(v12 - 7) == a2 )
        {
          v15 = (_QWORD *)v12[1];
          if ( (_QWORD *)*v15 == v12 && (_QWORD *)v9[1] == v12 )
          {
            v9[1] = v15;
            *v15 = v9;
          }
          else
          {
            _list_del_entry_valid_or_report(v12);
            v13 = v16;
          }
          *v12 = v12;
          v12[1] = v12;
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v13, 0);
          else
            kvfree(v13);
          v10 = 1;
        }
      }
      while ( v9 != (_QWORD *)(v8 + 144) );
    }
    if ( (cam_sync_monitor_mask & 2) != 0 )
    {
      if ( (v10 & 1) != 0 )
      {
        cam_generic_fence_update_monitor_array(a3, sync_dev + 8328, *(_QWORD *)(sync_dev + 8672), 6);
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          128,
          1,
          "cam_sync_deregister_callback",
          270,
          "Error: Callback not found sync obj = %s[%d] : sync_id %d, state %d",
          (const char *)v8,
          a3,
          *(_DWORD *)(v8 + 68),
          *(_DWORD *)(v8 + 104));
        cam_sync_dump_monitor_array(v8);
      }
    }
    raw_spin_unlock_bh(sync_dev + 4 * v7 + 136);
    if ( (v10 & 1) != 0 )
      return 0;
    else
      return 4294967294LL;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_deregister_callback",
      246,
      "Error: accessing an uninitialized sync obj = %s[%d]",
      (const char *)(*(_QWORD *)(sync_dev + 128) + 216LL * a3),
      a3);
    cam_sync_dump_monitor_array(v8);
    raw_spin_unlock_bh(sync_dev + 4 * v7 + 136);
    return 4294967274LL;
  }
}
