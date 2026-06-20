__int64 __fastcall _cam_isp_ctx_apply_req(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x21
  __int64 v3; // x2
  __int64 v5; // x3
  __int64 v6; // x4
  char v8; // w22
  __int64 (__fastcall *v9)(__int64, unsigned int *, __int64, __int64, __int64); // x8
  unsigned int v10; // w20
  int v11; // w0
  __int64 v12; // x8
  __int64 v13; // x0
  const char *v14; // x6
  int v15; // w0
  __int64 v16; // x8
  __int64 v17; // x0
  const char *v18; // x6
  const char *v20; // x0

  v2 = *(_QWORD *)(a1 + 256);
  v3 = *(unsigned int *)(a1 + 32);
  v5 = *((_QWORD *)a2 + 1);
  v6 = *a2;
  v8 = debug_mdl;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v20 = _cam_isp_ctx_substate_val_to_type(*(_DWORD *)(v2 + 20));
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v8 & 8,
      4,
      "__cam_isp_ctx_apply_req",
      10192,
      "Enter: apply req in Substate[%s] request_id:%lld, ctx: %u link: 0x%x",
      v20,
      *((_QWORD *)a2 + 1),
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
  }
  v9 = *(__int64 (__fastcall **)(__int64, unsigned int *, __int64, __int64, __int64))(*(_QWORD *)(v2 + 32)
                                                                                    + 192LL * *(unsigned int *)(v2 + 20)
                                                                                    + 96);
  if ( !v9 )
  {
    v11 = __ratelimit(&_cam_isp_ctx_apply_req__rs, "__cam_isp_ctx_apply_req");
    v12 = *(unsigned int *)(v2 + 20);
    if ( v11 )
      v13 = 3;
    else
      v13 = 2;
    if ( (unsigned int)v12 > 6 )
      v14 = "INVALID";
    else
      v14 = off_451850[v12];
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v13,
      8,
      2,
      "__cam_isp_ctx_apply_req",
      10200,
      "No handle function in activated Substate[%s], ctx: %u link: 0x%x",
      v14,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    v10 = -14;
LABEL_16:
    v15 = __ratelimit(&_cam_isp_ctx_apply_req__rs_697, "__cam_isp_ctx_apply_req");
    v16 = *(unsigned int *)(v2 + 20);
    if ( v15 )
      v17 = 3;
    else
      v17 = 2;
    if ( (unsigned int)v16 > 6 )
      v18 = "INVALID";
    else
      v18 = off_451850[v16];
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      v17,
      8,
      2,
      "__cam_isp_ctx_apply_req",
      10208,
      "Apply failed in active Substate[%s] rc %d, ctx: %u link: 0x%x",
      v18,
      v10,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 64));
    return v10;
  }
  if ( *((_DWORD *)v9 - 1) != -289573293 )
    __break(0x8228u);
  v10 = v9(a1, a2, v3, v5, v6);
  if ( v10 )
    goto LABEL_16;
  return v10;
}
