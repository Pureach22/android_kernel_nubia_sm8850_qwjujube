__int64 __fastcall _cam_isp_ctx_check_deferred_buf_done(_QWORD *a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x8
  __int64 v7; // x22
  __int64 v8; // x26
  __int64 v9; // x7
  __int64 v10; // x9
  unsigned int v11; // w23
  __int64 v12; // x9
  __int64 result; // x0
  unsigned int v14; // w20
  __int64 v15; // x7

  v3 = *a1;
  v7 = *(_QWORD *)(*a1 + 160LL);
  if ( v7 != *a1 + 160LL )
  {
    v8 = *(_QWORD *)(v7 + 32);
    v9 = a1[4669];
    v10 = a1[5701];
    v11 = *(_DWORD *)(v8 + 56);
    if ( v9 == v10 )
      goto LABEL_11;
    if ( (debug_mdl & 8) == 0 || debug_priority )
      goto LABEL_10;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, __int64, unsigned int, _DWORD, _DWORD))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_check_deferred_buf_done",
      3240,
      "Trying to find buf done with req in wait list, req %llu last apply id:%lld last err id:%lld curr_num_deferred: %u,"
      " ctx: %u link: 0x%x",
      *(_QWORD *)(v7 + 24),
      v9,
      v10,
      v11,
      *(_DWORD *)(v3 + 32),
      *(_DWORD *)(v3 + 64));
    goto LABEL_21;
  }
  v7 = *(_QWORD *)(v3 + 144);
  if ( v7 != v3 + 144 )
  {
    v8 = *(_QWORD *)(v7 + 32);
    v9 = a1[4669];
    v12 = a1[5701];
    v11 = *(_DWORD *)(v8 + 56);
    if ( v9 == v12 )
      goto LABEL_11;
    if ( (debug_mdl & 8) == 0 || debug_priority )
    {
LABEL_10:
      a1[5701] = v9;
LABEL_11:
      result = _cam_isp_ctx_handle_buf_done_for_request_verify_addr(a1, v7, a2, a3, 1, 1);
      if ( *(_DWORD *)(v8 + 56) > v11 )
      {
        v14 = result;
        _cam_isp_ctx_try_buf_done_process_for_active_request(v11, a1, v7);
        return v14;
      }
      return result;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, __int64, unsigned int, _DWORD, _DWORD))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_check_deferred_buf_done",
      3277,
      "Trying to find buf done with req in pending list, req %llu last apply id:%lld last err id:%lld curr_num_deferred: "
      "%u, ctx: %u link: 0x%x",
      *(_QWORD *)(v7 + 24),
      v9,
      v12,
      v11,
      *(_DWORD *)(v3 + 32),
      *(_DWORD *)(v3 + 64));
LABEL_21:
    v9 = a1[4669];
    goto LABEL_10;
  }
  v15 = a1[4669];
  if ( v15 == a1[5701] )
    return 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_check_deferred_buf_done",
      3302,
      "Bufdone without active request bubble_state=%d last_applied_req_id:%lld,ctx:%u link:0x%x",
      a3,
      v15,
      *(_DWORD *)(v3 + 32),
      *(_DWORD *)(v3 + 64));
    v15 = a1[4669];
  }
  a1[5701] = v15;
  return 0;
}
