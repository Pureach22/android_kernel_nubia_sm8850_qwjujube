__int64 __fastcall _cam_isp_ctx_handle_buf_done_in_activated_state(__int64 *a1, __int64 a2, unsigned int a3)
{
  __int64 v4; // x25
  __int64 v7; // x24
  __int64 v8; // x22
  __int64 result; // x0
  __int64 v10; // x21
  __int64 v11; // x6
  unsigned int v12; // w23
  unsigned int v13; // w8
  int v14; // w9
  __int64 v15; // x7
  __int64 v16; // x8
  __int64 v17; // x23
  __int64 v18; // x22
  __int64 v19; // x6
  _BOOL4 v20; // w8
  const char *v21; // x5
  __int64 v22; // x2
  __int64 v23; // x4
  char v24; // w24
  char v25; // w8
  __int64 v26; // x24
  unsigned int v27; // w26
  __int64 v28; // x8
  __int64 v29; // x27
  int v30; // w9
  __int64 v31; // x26
  _BOOL4 v32; // w24
  unsigned int v33; // w24
  int v34; // w0
  _BOOL4 v35; // w25
  const char *v36; // x0
  _QWORD v37[4]; // [xsp+18h] [xbp-48h] BYREF
  _QWORD v38[5]; // [xsp+38h] [xbp-28h] BYREF

  v4 = (__int64)a1 + 45580;
  v38[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*((_BYTE *)a1 + 45745) & 1) == 0 && *((_BYTE *)a1 + 45754) != 1 || (*(_BYTE *)(a2 + 24) & 1) != 0 )
  {
    v7 = *a1;
    memset(v38, 0, 32);
    v8 = *(_QWORD *)(v7 + 128);
    if ( v8 == v7 + 128 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "__cam_isp_ctx_handle_buf_done",
        3040,
        "Buf done with no active request, ctx_idx:%u link[0x%x]",
        *(_DWORD *)(v7 + 32),
        *(_DWORD *)(v7 + 64));
      result = 0;
    }
    else
    {
      result = _cam_isp_ctx_handle_buf_done_for_request(a1, *(_QWORD *)(v7 + 128), a2, a3, v38);
      if ( HIDWORD(v38[0]) )
      {
        v10 = *(_QWORD *)(v7 + 136);
        v11 = *(_QWORD *)(v8 + 24);
        v12 = result;
        v13 = *(_DWORD *)(v7 + 32);
        v14 = *(_DWORD *)(v7 + 64);
        v15 = *(_QWORD *)(v10 + 24);
        memset(v37, 0, sizeof(v37));
        if ( v15 == v11 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, int))cam_print_log)(
            3,
            8,
            2,
            "__cam_isp_ctx_handle_buf_done",
            3086,
            "Req %lld only active request, spurious buf_done rxd, ctx_idx:%u link[0x%x]",
            v15,
            v13,
            v14);
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            2,
            "__cam_isp_ctx_handle_buf_done",
            3069,
            "Unhandled bufdone resources for req %lld,trying next request %lld,ctx:%u link[0x%x]",
            v11,
            v15,
            v13,
            v14);
          _cam_isp_ctx_handle_buf_done_for_request(a1, v10, v38, a3, v37);
          if ( HIDWORD(v37[0]) )
          {
            v21 = "BUF Done not handled for next request %lld, ctx_idx:%u link[0x%x]";
            v22 = 1;
            v23 = 3082;
          }
          else
          {
            v21 = "BUF Done event handed for next request %lld, ctx_idx:%u link[0x%x]";
            v22 = 3;
            v23 = 3078;
          }
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD))cam_print_log)(
            3,
            8,
            v22,
            "__cam_isp_ctx_handle_buf_done",
            v23,
            v21,
            *(_QWORD *)(v10 + 24),
            *(unsigned int *)(v7 + 32),
            *(_DWORD *)(v7 + 64));
        }
        result = v12;
      }
    }
    goto LABEL_30;
  }
  v16 = *a1;
  v17 = *(_QWORD *)(*a1 + 128);
  if ( v17 == *a1 + 128 )
  {
    result = _cam_isp_ctx_check_deferred_buf_done(a1, a2, a3);
    goto LABEL_30;
  }
  if ( *((int *)a1 + 9330) < 2 )
  {
    v20 = 0;
    v18 = 0;
  }
  else
  {
    v18 = *(_QWORD *)(v16 + 136);
    v19 = *(_QWORD *)(v18 + 24);
    if ( v19 == *(_QWORD *)(v17 + 24) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "__cam_isp_ctx_handle_buf_done_verify_addr",
        3337,
        "Req %lld only active request, spurious buf_done rxd, ctx: %u link: 0x%x",
        v19,
        *(_DWORD *)(v16 + 32),
        *(_DWORD *)(v16 + 64));
      v20 = 0;
      goto LABEL_17;
    }
    v26 = *(_QWORD *)(v18 + 32);
    v27 = *(_DWORD *)(a2 + 8);
    v28 = 5709;
    if ( *(_DWORD *)a2 == 7 )
      v28 = 5710;
    v29 = a1[v28];
    v20 = (_cam_isp_ctx_check_buf_done_match_for_request(
             a1,
             *(_QWORD *)(v18 + 32),
             a2,
             *((unsigned __int8 *)a1 + 45754))
         & 1) != 0
       || (int)_cam_isp_context_try_match_buf_done_with_other_ports(
                 a1,
                 v29 + 292LL * v27,
                 a2,
                 v26,
                 *(unsigned __int8 *)(v4 + 174)) > 0;
    v30 = debug_priority;
    v31 = debug_mdl & 8;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v33 = *(_DWORD *)(a2 + 4);
      v34 = *(_DWORD *)v4;
      v35 = v20;
      v36 = _cam_isp_resource_handle_id_to_type(v34, v33);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v31,
        4,
        "__cam_isp_ctx_buf_done_match_req",
        3130,
        "buf done num handles %d [%s] match count %d for next req:%lld",
        v33,
        v36,
        v35,
        *(_QWORD *)(v18 + 24));
      v30 = debug_priority;
      v20 = v35;
      v31 = debug_mdl & 8;
      if ( (debug_mdl & 8) != 0 )
      {
LABEL_36:
        if ( !v30 )
        {
          v32 = v20;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v31,
            4,
            "__cam_isp_ctx_buf_done_match_req",
            3132,
            "irq_delay_detected %d",
            v20);
          v20 = v32;
        }
      }
    }
    else if ( (debug_mdl & 8) != 0 )
    {
      goto LABEL_36;
    }
  }
LABEL_17:
  v24 = !v20;
  result = _cam_isp_ctx_handle_buf_done_for_request_verify_addr(a1, v17, a2, a3, !v20, 0);
  if ( !(_DWORD)result )
  {
    if ( v18 )
      v25 = v24;
    else
      v25 = 1;
    if ( (v25 & 1) != 0 )
      result = 0;
    else
      result = _cam_isp_ctx_handle_buf_done_for_request_verify_addr(a1, v18, a2, a3, 1, 0);
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
