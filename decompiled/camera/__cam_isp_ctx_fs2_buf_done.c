__int64 __fastcall _cam_isp_ctx_fs2_buf_done(__int64 a1, __int64 a2)
{
  __int64 v2; // x22
  __int64 v3; // x21
  int v5; // w24
  __int64 v6; // x23
  __int64 v7; // x20
  __int64 result; // x0
  __int64 v9; // x8
  unsigned int v10; // w21
  int v11; // w6
  int v12; // w7
  unsigned int v13; // w22

  v2 = *(_QWORD *)a1;
  v3 = a1 + 36864;
  v5 = *(_DWORD *)(a1 + 37320);
  v6 = *(_QWORD *)a1 + 128LL;
  if ( *(_QWORD *)v6 )
    v7 = *(int *)(*(_QWORD *)v6 + 24LL);
  else
    v7 = 0;
  result = _cam_isp_ctx_handle_buf_done_in_activated_state((__int64 *)a1, a2, 0);
  if ( v5 == *(_DWORD *)(v3 + 456) + 1 && *(_QWORD *)(v2 + 160) == v2 + 160 && *(_QWORD *)v6 == v6 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v11 = *(_DWORD *)(v2 + 32);
      v12 = *(_DWORD *)(v2 + 64);
      v13 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_fs2_buf_done",
        5110,
        "No request, move to SOF, ctx_idx: %u, link: 0x%x",
        v11,
        v12);
      result = v13;
    }
    v9 = *(_QWORD *)(v3 + 464);
    *(_DWORD *)(a1 + 20) = 0;
    if ( v9 < v7 )
    {
      *(_QWORD *)(v3 + 464) = v7;
      v10 = result;
      _cam_isp_ctx_send_sof_timestamp(a1, v7, 0);
      return v10;
    }
  }
  return result;
}
