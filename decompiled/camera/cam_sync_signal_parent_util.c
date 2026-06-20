_QWORD *__fastcall cam_sync_signal_parent_util(_QWORD *result, unsigned int a2, _QWORD **a3)
{
  _QWORD *v3; // x25
  unsigned int v5; // w21
  __int64 v6; // x8
  unsigned int *v7; // x24
  _QWORD *v8; // x22
  __int64 v9; // x26
  __int64 v10; // x8
  __int64 v11; // x8
  _QWORD *v12; // x8
  _QWORD *v13; // x9
  _QWORD *v14; // x0

  v3 = *a3;
  if ( *a3 != a3 )
  {
    v5 = (unsigned int)result;
    while ( 1 )
    {
      v7 = (unsigned int *)(v3 - 1);
      v6 = *((int *)v3 - 2);
      if ( (unsigned int)v6 >= 0x801 )
        break;
      v8 = (_QWORD *)*v3;
      v9 = *(_QWORD *)(sync_dev + 128) + 216LL * (int)v6;
      raw_spin_lock_bh(sync_dev + 4 * v6 + 136);
      --*(_DWORD *)(v9 + 108);
      if ( (unsigned int)cam_sync_util_update_parent_state(v9, v5) )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          128,
          1,
          "cam_sync_signal_parent_util",
          336,
          "Invalid parent state %d",
          *(_DWORD *)(v9 + 104));
        v10 = *v7;
        if ( (unsigned int)v10 > 0x800 )
          break;
        raw_spin_unlock_bh(sync_dev + 4 * v10 + 136);
      }
      else
      {
        if ( !*(_DWORD *)(v9 + 108) )
          cam_sync_util_dispatch_signaled_cb(*v7, *(unsigned int *)(v9 + 104), a2);
        if ( (cam_sync_monitor_mask & 2) != 0 )
          cam_generic_fence_update_monitor_array(*v7, sync_dev + 8328, *(_QWORD *)(sync_dev + 8672), 4);
        v11 = *v7;
        if ( (unsigned int)v11 > 0x800 )
          break;
        raw_spin_unlock_bh(sync_dev + 4 * v11 + 136);
        v12 = (_QWORD *)v3[1];
        if ( (_QWORD *)*v12 == v3 && (v13 = (_QWORD *)*v3, *(_QWORD **)(*v3 + 8LL) == v3) )
        {
          v13[1] = v12;
          *v12 = v13;
        }
        else
        {
          _list_del_entry_valid_or_report(v3);
        }
        *v3 = v3;
        v3[1] = v3;
      }
      v14 = v3 - 1;
      if ( mem_trace_en == 1 )
        result = cam_mem_trace_free(v14, 0);
      else
        result = (_QWORD *)kvfree(v14);
      v3 = v8;
      if ( v8 == a3 )
        return result;
    }
    __break(0x5512u);
    return (_QWORD *)cam_sync_merge();
  }
  return result;
}
