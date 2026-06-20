__int64 __fastcall _cam_isp_ctx_rdi_only_apply_req_top_state(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  char v4; // w23
  unsigned int v5; // w0
  char v6; // w23
  unsigned int v7; // w20
  int v8; // w0
  __int64 v9; // x8
  __int64 v10; // x0
  const char *v11; // x8
  __int64 v13; // x24
  const char *v14; // x0
  const char *v15; // x0

  v2 = *(_QWORD *)(a1 + 256);
  v4 = debug_mdl;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v13 = a2;
    v14 = _cam_isp_ctx_substate_val_to_type(*(_DWORD *)(v2 + 20));
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v4 & 8,
      4,
      "__cam_isp_ctx_rdi_only_apply_req_top_state",
      7553,
      "current Substate[%s], ctx_idx: %u, link: 0x%x",
      v14,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    a2 = v13;
  }
  v5 = _cam_isp_ctx_apply_req_in_activated_state(a1, a2, 1u);
  v6 = debug_mdl;
  v7 = v5;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v15 = _cam_isp_ctx_substate_val_to_type(*(_DWORD *)(v2 + 20));
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v6 & 8,
      4,
      "__cam_isp_ctx_rdi_only_apply_req_top_state",
      7558,
      "new Substate[%s], ctx_idx: %u, link: 0x%x",
      v15,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    if ( !v7 )
      return v7;
  }
  else if ( !v5 )
  {
    return v7;
  }
  v8 = __ratelimit(&_cam_isp_ctx_rdi_only_apply_req_top_state__rs, "__cam_isp_ctx_rdi_only_apply_req_top_state");
  v9 = *(unsigned int *)(v2 + 20);
  if ( v8 )
    v10 = 3;
  else
    v10 = 2;
  if ( (unsigned int)v9 > 6 )
    v11 = "INVALID";
  else
    v11 = off_451850[v9];
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    v10,
    8,
    1,
    "__cam_isp_ctx_rdi_only_apply_req_top_state",
    7565,
    "ctx_id:%u link: 0x%x Apply failed in Substate[%s], rc %d",
    *(_DWORD *)(a1 + 32),
    *(_DWORD *)(a1 + 64),
    v11,
    v7);
  return v7;
}
