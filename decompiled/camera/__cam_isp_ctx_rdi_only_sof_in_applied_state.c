__int64 __fastcall _cam_isp_ctx_rdi_only_sof_in_applied_state(__int64 a1, _QWORD *a2)
{
  int v2; // w9
  __int64 v3; // x1
  unsigned int v4; // w8
  __int64 v6; // x21

  if ( a2 )
  {
    if ( *(_QWORD *)(a1 + 37304) != *a2 )
    {
      ++*(_QWORD *)(a1 + 8);
      *(_QWORD *)(a1 + 37304) = *a2;
      *(_QWORD *)(a1 + 37312) = a2[1];
    }
    v2 = debug_priority;
    v3 = debug_mdl & 8;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v6 = a1;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        v3,
        4,
        "__cam_isp_ctx_rdi_only_sof_in_applied_state",
        7115,
        "frame id: %lld time stamp:0x%llx",
        *(_QWORD *)(a1 + 8));
      v2 = debug_priority;
      a1 = v6;
      v3 = debug_mdl & 8;
    }
    v4 = 0;
    *(_DWORD *)(a1 + 20) = 4;
    if ( v3 && !v2 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v3,
        4,
        "__cam_isp_ctx_rdi_only_sof_in_applied_state",
        7120,
        "next Substate[%s]",
        "BUBBLE_APPLIED");
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_rdi_only_sof_in_applied_state",
      7108,
      "in valid sof event data");
    return (unsigned int)-22;
  }
  return v4;
}
