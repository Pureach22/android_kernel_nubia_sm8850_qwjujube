__int64 __fastcall cam_isp_blob_fcg_config_prepare(_DWORD *a1, _QWORD *a2, int a3)
{
  __int64 v3; // x20
  __int64 v5; // x21
  __int64 v6; // x7
  __int64 v7; // x8
  const char *v8; // x5
  __int64 v9; // x4
  _DWORD *v11; // x23

  v3 = a2[40];
  v5 = a2[2];
  v6 = *(_QWORD *)(*a2 + 8LL);
  if ( a3 == 2 )
  {
    if ( *(_BYTE *)(v3 + 4362) == 1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_blob_fcg_config_prepare",
        12632,
        "IFE/MC_TFE FCG config is sent more than once, ctx_id: %u, request_id: %llu",
        *(_DWORD *)(v5 + 56),
        v6);
      return 4294967274LL;
    }
LABEL_7:
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v11 = a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_isp_blob_fcg_config_prepare",
        12638,
        "Start storing FCG config in req_isp on ctx_idx: %u, hw_type: %d, request_id: %llu",
        *(_DWORD *)(v5 + 56),
        a3,
        v6);
      a1 = v11;
    }
    if ( (56 * a1[3] + 40) * a1[2] + 40 == a1[1] )
    {
      if ( a3 == 2 )
      {
        *(_BYTE *)(v3 + 4362) = 1;
        v7 = 4336;
        goto LABEL_16;
      }
      if ( a3 == 7 )
      {
        *(_BYTE *)(v3 + 4361) = 1;
        v7 = 4304;
LABEL_16:
        cam_isp_copy_fcg_config(v3 + v7, a1);
        return 0;
      }
      v8 = "Failed in parsing FCG configuration for hw_type: %u, ctx_idx: %u, request_id: %llu";
      v9 = 12669;
    }
    else
    {
      v8 = "Mismatched size between userspace provides and real comsumption %u - %u, ctx_idx: %u, request_id: %llu";
      v9 = 12651;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_blob_fcg_config_prepare",
      v9,
      v8);
    return 4294967274LL;
  }
  if ( a3 != 7 || *(_BYTE *)(v3 + 4361) != 1 )
    goto LABEL_7;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_isp_blob_fcg_config_prepare",
    12624,
    "SFE FCG config is sent more than once, ctx_id: %u, request_id: %llu",
    *(_DWORD *)(v5 + 56),
    v6);
  return 4294967274LL;
}
