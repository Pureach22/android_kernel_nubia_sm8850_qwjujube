__int64 __fastcall sme_ps_uapsd_disable(
        _QWORD *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  if ( a2 > 5 )
    return 4;
  if ( (*(_BYTE *)(a1[1] + 5417LL) & 1) == 0 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: vdev:%d power save mode is disabled via ini",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sme_enable_sta_ps_check",
      a2,
      v10,
      v11);
    return 16;
  }
  mlme_get_user_ps(a1[2694], a2);
  if ( !cm_is_vdevid_active(a1[2695], a2) )
    return 16;
  result = sme_ps_process_command((__int64)a1, a2, 3u, v15, v16, v17, v18, v19, v20, v21, v22);
  if ( !(_DWORD)result )
  {
    ((void (__fastcall *)(_QWORD *, _QWORD))sme_offload_qos_process_out_of_uapsd_mode)(a1, a2);
    return 0;
  }
  return result;
}
