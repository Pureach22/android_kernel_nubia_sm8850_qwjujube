__int64 __fastcall cam_icp_mgr_delete_sync(_QWORD *a1, _QWORD *a2)
{
  __int64 v4; // x8
  __int64 v5; // x22
  __int64 v6; // x21
  _QWORD *v7; // x0
  const char *v9; // x5
  __int64 v10; // x4
  _QWORD *v11; // x0
  __int64 v12; // x8

  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_delete_sync",
      7507,
      "Invalid params%pK %pK",
      a2,
      a1);
    return 4294967274LL;
  }
  v4 = a2[1];
  if ( !v4 )
  {
    v9 = "Null ICP ctx info";
    v10 = 7514;
LABEL_14:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_delete_sync",
      v10,
      v9);
    v11 = (_QWORD *)a2[1];
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v11, 0);
    else
      kvfree(v11);
    a2[1] = 0;
    return 4294967274LL;
  }
  v5 = *(_QWORD *)(v4 + 16);
  if ( !v5 )
  {
    v9 = "Null Context";
    v10 = 7523;
    goto LABEL_14;
  }
  v6 = *(int *)(v4 + 4);
  mutex_lock(a1[11] + 48LL * (int)v6);
  if ( v5 == *(_QWORD *)(a1[12] + 8 * v6) )
  {
    v12 = -160;
    do
    {
      if ( *(_DWORD *)(v5 + v12 + 4824) )
        *(_DWORD *)(v5 + v12 + 4664) = 0;
      v12 += 4;
    }
    while ( v12 );
  }
  else if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_delete_sync",
      7532,
      "ctx data is already released before accessing, ctx_id: %u",
      v6);
  }
  mutex_unlock(a1[11] + 48LL * (int)v6);
  v7 = (_QWORD *)a2[1];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v7, 0);
  else
    kvfree(v7);
  a2[1] = 0;
  return 0;
}
