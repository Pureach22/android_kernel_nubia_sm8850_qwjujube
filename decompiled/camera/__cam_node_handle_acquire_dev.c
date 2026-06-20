__int64 __fastcall _cam_node_handle_acquire_dev(__int64 a1, __int64 a2)
{
  __int64 *v4; // x21
  __int64 **v5; // x8
  __int64 v6; // x20
  __int64 *v7; // x9
  unsigned int v8; // w0
  unsigned int v9; // w21
  __int64 result; // x0
  unsigned int v11; // w20
  __int64 v12; // x23

  if ( !a2 )
    return 4294967274LL;
  mutex_lock(a1 + 32);
  v4 = *(__int64 **)(a1 + 80);
  if ( v4 == (__int64 *)(a1 + 80) )
  {
    mutex_unlock(a1 + 32);
    goto LABEL_11;
  }
  v5 = (__int64 **)v4[1];
  v6 = (__int64)(v4 - 5);
  if ( *v5 == v4 && (v7 = (__int64 *)*v4, *(__int64 **)(*v4 + 8) == v4) )
  {
    v7[1] = (__int64)v5;
    *v5 = v7;
  }
  else
  {
    _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 80));
  }
  *v4 = (__int64)v4;
  v4[1] = (__int64)v4;
  mutex_unlock(a1 + 32);
  if ( v4 == &qword_28 )
  {
LABEL_11:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      2,
      1,
      "__cam_node_handle_acquire_dev",
      121,
      "No free ctx in free list node %s with size:%d",
      (const char *)a1,
      *(_DWORD *)(a1 + 104));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      2,
      3,
      "cam_node_print_ctx_state",
      23,
      "[%s] state=%d, ctx_size %d",
      (const char *)a1,
      *(_DWORD *)(a1 + 20),
      *(_DWORD *)(a1 + 104));
    mutex_lock(a1 + 32);
    if ( *(_DWORD *)(a1 + 104) )
    {
      v11 = 0;
      do
      {
        v12 = *(_QWORD *)(a1 + 96) + 552LL * (int)v11;
        raw_spin_lock_bh(v12 + 120);
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          2,
          3,
          "cam_node_print_ctx_state",
          38,
          "[%s][%d] : state=%d, refcount=%d, active_req_list=%d, pending_req_list=%d, wait_req_list=%d, free_req_list=%d",
          (const char *)v12,
          v11,
          *(_DWORD *)(v12 + 240),
          *(_DWORD *)(v12 + 404),
          *(_QWORD *)(v12 + 128) == v12 + 128,
          *(_QWORD *)(v12 + 144) == v12 + 144,
          *(_QWORD *)(v12 + 160) == v12 + 160,
          *(_QWORD *)(v12 + 176) == v12 + 176);
        raw_spin_unlock_bh(v12 + 120);
        ++v11;
      }
      while ( v11 < *(_DWORD *)(a1 + 104) );
    }
    mutex_unlock(a1 + 32);
    return 4294967284LL;
  }
  *((_DWORD *)v4 + 91) = 1;
  *((_DWORD *)v4 + 106) = 0;
  v8 = cam_handle_validate(*(_DWORD *)(a2 + 4), *(_DWORD *)(a2 + 4));
  if ( v8 )
  {
    v9 = v8;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "__cam_node_handle_acquire_dev",
      132,
      "Invalid session handle for acquire dev");
LABEL_17:
    cam_context_putref(v6);
    return v9;
  }
  result = cam_context_handle_acquire_dev((__int64)(v4 - 5), a2);
  if ( (_DWORD)result )
  {
    v9 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      2,
      1,
      "__cam_node_handle_acquire_dev",
      139,
      "Acquire device failed for node %s",
      (const char *)a1);
    goto LABEL_17;
  }
  if ( (debug_mdl & 2) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 2,
      4,
      "__cam_node_handle_acquire_dev",
      144,
      "[%s] Acquire ctx_id %d",
      (const char *)a1,
      *((_DWORD *)v4 - 2));
    return 0;
  }
  return result;
}
