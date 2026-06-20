__int64 __fastcall cam_icp_ctx_timer(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x22
  __int64 v4; // x21
  unsigned int v6; // w23
  const char *v7; // x5
  __int64 v8; // x4
  __int64 v10; // x8
  int v11; // w11
  unsigned int *v12; // x0

  v2 = *(_QWORD *)(a2 + 8);
  if ( !v2 )
  {
    v7 = "Null ICP ctx info";
    v8 = 790;
LABEL_10:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_ctx_timer",
      v8,
      v7);
    return (unsigned int)-22;
  }
  v3 = *(_QWORD *)(v2 + 16);
  if ( !v3 )
  {
    v7 = "ctx_data is NULL, failed to update clk";
    v8 = 797;
    goto LABEL_10;
  }
  v4 = *(int *)(v2 + 4);
  mutex_lock(*(_QWORD *)(a1 + 88) + 48LL * (int)v4);
  if ( v3 == *(_QWORD *)(*(_QWORD *)(a1 + 96) + 8 * v4) )
  {
    v10 = v3 + 28672;
    if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000100,
        4,
        "cam_icp_ctx_timer",
        814,
        "%s: ubw = %lld cbw = %lld curr_fc = %u bc = %u",
        (const char *)(v3 + 29824),
        *(_QWORD *)(v3 + 29248),
        *(_QWORD *)(v3 + 29256),
        *(_DWORD *)(v3 + 29232),
        *(_DWORD *)(v3 + 29240));
      v10 = v3 + 28672;
    }
    if ( *(_DWORD *)(v3 + 104) == 2 && (v11 = *(_DWORD *)(v10 + 1136)) != 0 )
    {
      if ( (**(_QWORD **)(v3 + 1720) & 0xFFFFFFFFFFLL) != 0 )
      {
        v12 = *(unsigned int **)(v3 + 29800);
        if ( v12 )
        {
          *(_DWORD *)(v10 + 1136) = v11 + 1;
          if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
              3,
              debug_mdl & 0x2000100,
              4,
              "cam_icp_ctx_timer_reset",
              427,
              "%s: reset timer : counter=%d",
              v3 + 29824);
            v12 = *(unsigned int **)(v3 + 29800);
          }
          crm_timer_reset(v12);
          v6 = -16;
        }
        else
        {
          v6 = -16;
        }
        goto LABEL_6;
      }
      cam_icp_remove_ctx_bw(a1, v3);
    }
    else
    {
      v6 = 0;
      if ( (debug_mdl & 0x2000100) == 0 || debug_priority )
        goto LABEL_6;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        debug_mdl & 0x2000100,
        4,
        "cam_icp_ctx_timer",
        820,
        "%s: state %d, counter=%d",
        v3 + 29824);
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      2,
      "cam_icp_ctx_timer",
      804,
      "ctx data is released before accessing it, ctx_id: %u",
      v4);
  }
  v6 = 0;
LABEL_6:
  mutex_unlock(*(_QWORD *)(a1 + 88) + 48LL * (int)v4);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v2, 0);
  else
    kvfree(v2);
  return v6;
}
