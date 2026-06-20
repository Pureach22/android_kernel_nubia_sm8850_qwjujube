__int64 __fastcall _cam_isp_ctx_rdi_only_sof_in_top_state(__int64 a1, __int64 *a2)
{
  __int64 v2; // x21
  __int64 v3; // x20
  __int64 v5; // x7
  __int64 v6; // x8
  unsigned __int64 v7; // x1
  __int64 result; // x0
  __int64 v9; // x0
  char v10; // w20
  const char *v11; // x0

  v2 = *(_QWORD *)a1;
  if ( a2 )
  {
    v3 = a1 + 36864;
    v5 = *(_QWORD *)(a1 + 37304);
    if ( v5 != *a2 )
    {
      ++*(_QWORD *)(a1 + 8);
      v5 = *a2;
      *(_QWORD *)(a1 + 37304) = *a2;
      *(_QWORD *)(a1 + 37312) = a2[1];
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_rdi_only_sof_in_top_state",
        7057,
        "frame id: %lld time stamp:0x%llx, ctx_idx: %u, link: 0x%x",
        *(_QWORD *)(a1 + 8),
        v5,
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
    if ( *(int *)(v3 + 456) > 2 )
    {
      if ( (unsigned int)__ratelimit(
                           &_cam_isp_ctx_rdi_only_sof_in_top_state__rs,
                           "__cam_isp_ctx_rdi_only_sof_in_top_state") )
        v9 = 3;
      else
        v9 = 2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        v9,
        8,
        1,
        "__cam_isp_ctx_rdi_only_sof_in_top_state",
        7087,
        "Can not notify SOF to CRM, ctx_idx: %u, link: 0x%x",
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
    }
    else
    {
      _cam_isp_ctx_notify_trigger_util(1, (__int64 *)a1);
      v6 = *(_QWORD *)(v2 + 128);
      if ( v6 == v2 + 128 || (v7 = *(_QWORD *)(v6 + 24), v7 <= *(_QWORD *)(v3 + 464)) )
        v7 = 0;
      else
        *(_QWORD *)(v3 + 464) = v7;
      _cam_isp_ctx_send_sof_timestamp(a1, v7, 0);
    }
    if ( *(_QWORD *)(v2 + 128) == v2 + 128 )
    {
      *(_DWORD *)(a1 + 20) = 0;
    }
    else if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_rdi_only_sof_in_top_state",
        7094,
        "Still need to wait for the buf done, ctx_idx: %u, link: 0x%x",
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
    }
    v10 = debug_mdl;
    result = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v11 = _cam_isp_ctx_substate_val_to_type(*(_DWORD *)(a1 + 20));
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v10 & 8,
        4,
        "__cam_isp_ctx_rdi_only_sof_in_top_state",
        7098,
        "next Substate[%s], ctx_idx: %u, link: 0x%x",
        v11,
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
      return 0;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_rdi_only_sof_in_top_state",
      7050,
      "in valid sof event data, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(v2 + 32),
      *(_DWORD *)(v2 + 64));
    return 4294967274LL;
  }
  return result;
}
