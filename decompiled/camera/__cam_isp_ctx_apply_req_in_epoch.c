__int64 __fastcall _cam_isp_ctx_apply_req_in_epoch(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  char v4; // w23
  __int64 result; // x0
  char v6; // w23
  char v7; // w22
  __int64 v8; // x24
  const char *v9; // x0
  unsigned int v10; // w24
  const char *v11; // x0
  unsigned int v12; // w8
  unsigned int v13; // w20
  const char *v14; // x0

  v2 = *(_QWORD *)(a1 + 256);
  v4 = debug_mdl;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v8 = a2;
    v9 = _cam_isp_ctx_substate_val_to_type(*(_DWORD *)(v2 + 20));
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v4 & 8,
      4,
      "__cam_isp_ctx_apply_req_in_epoch",
      6052,
      "current Substate[%s], ctx %u, link: 0x%x",
      v9,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    a2 = v8;
  }
  result = _cam_isp_ctx_apply_req_in_activated_state(a1, a2, 1);
  v6 = debug_mdl;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v10 = result;
    v11 = _cam_isp_ctx_substate_val_to_type(*(_DWORD *)(v2 + 20));
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v6 & 8,
      4,
      "__cam_isp_ctx_apply_req_in_epoch",
      6057,
      "new Substate[%s], ctx %u, link: 0x%x",
      v11,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    result = v10;
    if ( !v10 )
      return result;
  }
  else if ( !(_DWORD)result )
  {
    return result;
  }
  v7 = debug_mdl;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v12 = *(_DWORD *)(v2 + 20);
    v13 = result;
    v14 = _cam_isp_ctx_substate_val_to_type(v12);
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v7 & 8,
      4,
      "__cam_isp_ctx_apply_req_in_epoch",
      6062,
      "Apply failed in Substate[%s], rc %d, ctx %u, link: 0x%x",
      v14,
      v13,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    return v13;
  }
  return result;
}
