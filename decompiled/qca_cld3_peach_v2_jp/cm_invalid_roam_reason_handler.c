__int64 __fastcall cm_invalid_roam_reason_handler(
        unsigned int a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD *v23; // x22
  __int64 v24; // x23
  _DWORD *v25; // x8
  __int64 v26; // x0

  result = (__int64)_cds_get_context(54, (__int64)"cm_invalid_roam_reason_handler", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( result )
  {
    v23 = (_QWORD *)result;
    if ( a2 == 1 )
    {
      result = _qdf_mem_malloc(0x9C8u, "wma_invalid_roam_reason_handler", 2698);
      if ( !result )
        return result;
      *(_BYTE *)(result + 13) = a1;
      v24 = result;
      cm_fw_roam_start_req(v23[3], a1);
    }
    else
    {
      if ( a2 != 2 )
      {
        result = qdf_trace_msg(
                   0x36u,
                   8u,
                   "%s: Invalid notif %d",
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   "wma_invalid_roam_reason_handler",
                   a2);
LABEL_12:
        if ( (a2 & 0xFFFFFFFB) == 8 )
          return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))cm_report_roam_rt_stats)(
                   v23[3],
                   a1,
                   0,
                   0,
                   a2,
                   0,
                   a3);
        return result;
      }
      lim_sae_auth_cleanup_retry(*(_QWORD *)(result + 16), a1);
      result = _qdf_mem_malloc(0x9C8u, "wma_invalid_roam_reason_handler", 2698);
      if ( !result )
        return result;
      *(_BYTE *)(result + 13) = a1;
      v24 = result;
      v25 = (_DWORD *)v23[388];
      v26 = v23[2];
      if ( *(v25 - 1) != -478742497 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64, _QWORD, __int64))v25)(v26, a1, v24, 0, 4);
      cm_fw_roam_abort_req(v23[3], a1);
    }
    result = _qdf_mem_free(v24);
    goto LABEL_12;
  }
  return result;
}
