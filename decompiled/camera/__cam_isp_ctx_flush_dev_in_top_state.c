__int64 __fastcall _cam_isp_ctx_flush_dev_in_top_state(__int64 a1, __int64 a2)
{
  __int64 v2; // x6
  __int64 result; // x0
  __int64 v4; // [xsp+10h] [xbp-30h]

  _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 256) + 45737LL) & 1) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_flush_dev_in_top_state",
      7629,
      "flush dev only supported in offline context,ctx: %u, link:0x%x",
      *(unsigned int *)(a1 + 32),
      *(unsigned int *)(a1 + 64));
LABEL_10:
    result = 4294967274LL;
    goto LABEL_11;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v4 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_flush_dev_in_top_state",
      7638,
      "offline flush (type:%u, req:%lu), ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(a2 + 16) != 1,
      *(_QWORD *)(a2 + 24),
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    a1 = v4;
  }
  v2 = *(unsigned int *)(a1 + 240);
  if ( (_DWORD)v2 != 5 )
  {
    if ( (_DWORD)v2 == 3 )
    {
      result = _cam_isp_ctx_flush_req_in_ready();
      goto LABEL_11;
    }
    if ( (_DWORD)v2 != 2 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, _DWORD))cam_print_log)(
        3,
        8,
        1,
        "__cam_isp_ctx_flush_dev_in_top_state",
        7648,
        "flush dev in wrong state: %d, ctx_idx: %u, link: 0x%x",
        v2,
        *(unsigned int *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      goto LABEL_10;
    }
  }
  result = _cam_isp_ctx_flush_req_in_top_state();
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
