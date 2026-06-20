__int64 __fastcall _cam_isp_handle_deferred_buf_done(
        __int64 *a1,
        __int64 a2,
        char a3,
        unsigned int a4,
        unsigned int a5)
{
  __int64 v5; // x28
  __int64 v6; // x25
  unsigned int v11; // w8
  unsigned int v12; // w23
  unsigned int i; // w26
  __int64 v14; // x27
  __int64 v15; // x9
  _DWORD *v16; // x8
  __int64 v17; // x9
  signed int v18; // w0

  v5 = *(_QWORD *)(a2 + 32);
  v6 = *a1;
  if ( (debug_mdl & 8) == 0 || debug_priority )
  {
    v11 = *(_DWORD *)(v5 + 56);
    if ( v11 )
      goto LABEL_4;
LABEL_21:
    v12 = 0;
    goto LABEL_22;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "__cam_isp_handle_deferred_buf_done",
    2397,
    "ctx[%u] link[0x%x] : Req %llu : Handling %d deferred buf_dones num_acked=%d, bubble_handling=%d",
    *(_DWORD *)(v6 + 32),
    *(_DWORD *)(v6 + 64),
    *(_QWORD *)(a2 + 24),
    *(_DWORD *)(v5 + 56),
    *(_DWORD *)(v5 + 52),
    a3 & 1);
  v11 = *(_DWORD *)(v5 + 56);
  if ( !v11 )
    goto LABEL_21;
LABEL_4:
  v12 = 0;
  for ( i = 0; i < v11; ++i )
  {
    v14 = *(int *)(*(_QWORD *)(v5 + 64) + 4LL * (int)i);
    v15 = *(_QWORD *)(v5 + 24);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_handle_deferred_buf_done",
        2407,
        "ctx[%u] link[0x%x] : Sync with status=%d, event_cause=%d: req %lld res 0x%x sync_id 0x%x",
        *(_DWORD *)(v6 + 32),
        *(_DWORD *)(v6 + 64),
        a4,
        a5,
        *(_QWORD *)(a2 + 24),
        *(_DWORD *)(v15 + (v14 << 6)),
        *(_DWORD *)(v15 + (v14 << 6) + 16));
      v15 = *(_QWORD *)(v5 + 24);
    }
    v16 = (_DWORD *)(v15 + (v14 << 6));
    if ( v16[4] == -1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "__cam_isp_handle_deferred_buf_done",
        2413,
        "ctx[%u] link[0x%x] :  Deferred buf_done already signalled, req_id=%llu, j=%d, res=0x%x",
        *(_DWORD *)(v6 + 32),
        *(_DWORD *)(v6 + 64),
        *(_QWORD *)(a2 + 24),
        v14,
        *v16);
    }
    else if ( (a3 & 1) != 0 )
    {
      ++*(_DWORD *)(v5 + 52);
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "__cam_isp_handle_deferred_buf_done",
        2421,
        "Unexpected Buf done for res=0x%x on ctx[%u] link[0x%x] for Req %llu, status=%d, possible bh delays",
        *v16,
        *(_DWORD *)(v6 + 32),
        *(_DWORD *)(v6 + 64),
        *(_QWORD *)(a2 + 24),
        a4);
      v12 = cam_sync_signal(*(_DWORD *)(*(_QWORD *)(v5 + 24) + (v14 << 6) + 16), a4, a5);
      if ( v12 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "__cam_isp_handle_deferred_buf_done",
          2430,
          "ctx[%u] link[0x%x] : Sync signal for Req %llu, sync_id %d status=%d failed with rc = %d",
          *(_DWORD *)(v6 + 32),
          *(_DWORD *)(v6 + 64),
          *(_QWORD *)(a2 + 24),
          *(_DWORD *)(*(_QWORD *)(v5 + 24) + (v14 << 6) + 16),
          a4,
          v12);
      }
      else
      {
        v17 = *(_QWORD *)(v5 + 24) + (v14 << 6);
        ++*(_DWORD *)(v5 + 52);
        *(_DWORD *)(v17 + 16) = -1;
      }
      v18 = *(_DWORD *)(*(_QWORD *)(v5 + 24) + (v14 << 6) + 20);
      if ( v18 >= 1 )
      {
        v12 = cam_sync_signal(v18, a4, a5);
        if ( v12 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "__cam_isp_handle_deferred_buf_done",
            2446,
            "Early sync=%d for req=%llu failed with rc=%d ctx:%u link[0x%x]",
            *(_DWORD *)(*(_QWORD *)(v5 + 24) + (v14 << 6) + 20),
            *(_QWORD *)(a2 + 24),
            v12,
            *(_DWORD *)(v6 + 32),
            *(_DWORD *)(v6 + 64));
        *(_DWORD *)(*(_QWORD *)(v5 + 24) + (v14 << 6) + 20) = -1;
      }
    }
    v11 = *(_DWORD *)(v5 + 56);
  }
LABEL_22:
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_handle_deferred_buf_done",
      2459,
      "ctx[%u] link[0x%x] : Req %llu : Handled %d deferred buf_dones num_acked=%d, num_fence_map_out=%d",
      *(_DWORD *)(v6 + 32),
      *(_DWORD *)(v6 + 64),
      *(_QWORD *)(a2 + 24),
      v11,
      *(_DWORD *)(v5 + 52),
      *(_DWORD *)(v5 + 32));
  *(_DWORD *)(v5 + 56) = 0;
  return v12;
}
