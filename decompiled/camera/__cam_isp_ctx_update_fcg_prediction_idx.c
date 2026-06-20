__int64 __fastcall _cam_isp_ctx_update_fcg_prediction_idx(__int64 result, __int64 a2, _DWORD *a3, __int64 a4)
{
  unsigned int v4; // w9
  __int64 v5; // x8
  char v6; // w9

  v4 = a3[3];
  v5 = *(_QWORD *)(result + 256);
  if ( v4 && v4 <= *(_DWORD *)(*(_QWORD *)a3 + 8LL) )
  {
    *(_DWORD *)a4 = v4;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 8,
               4,
               "__cam_isp_ctx_update_fcg_prediction_idx",
               5762,
               "Apply req: %llu, FCG prediction: %u, frame_id: %llu, ctx_id: %u",
               a2,
               a3[3],
               *(_QWORD *)(v5 + 8),
               *(_DWORD *)(result + 32));
  }
  else
  {
    v6 = debug_mdl;
    *(_BYTE *)(a4 + 64) = 1;
    if ( (v6 & 8) != 0 && !debug_priority )
      return ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               v6 & 8,
               4,
               "__cam_isp_ctx_update_fcg_prediction_idx",
               5756,
               "Apply req: %llu, Use current FCG value, frame_id: %llu, ctx_id: %u",
               a2,
               *(_QWORD *)(v5 + 8),
               *(_DWORD *)(result + 32));
  }
  return result;
}
