__int64 __fastcall lim_send_stop_bss_response(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 session_by_vdev_id; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x22
  __int64 concurrent_session; // x0
  __int64 result; // x0
  __int64 v27; // [xsp+8h] [xbp-38h] BYREF
  __int64 v28; // [xsp+10h] [xbp-30h]
  __int64 v29; // [xsp+18h] [xbp-28h]
  __int64 v30; // [xsp+20h] [xbp-20h]
  __int64 v31; // [xsp+28h] [xbp-18h]
  __int64 v32; // [xsp+30h] [xbp-10h]
  __int64 v33; // [xsp+38h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v6 = lim_result_code_str(a3);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Sending stop bss response with reasonCode: %s",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "lim_send_stop_bss_response",
    v6);
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, a2);
  if ( session_by_vdev_id )
  {
    v24 = session_by_vdev_id;
    if ( (wlan_get_tpc_update_required_for_sta(
            *(_QWORD *)(session_by_vdev_id + 16),
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23)
        & 1) != 0 )
    {
      concurrent_session = lim_get_concurrent_session(a1, a2, *(unsigned int *)(v24 + 7036));
      if ( concurrent_session )
      {
        if ( *(_DWORD *)(concurrent_session + 284) == *(_DWORD *)(v24 + 284) )
          lim_update_tx_power(a1, v24, concurrent_session, 1);
      }
    }
    result = _qdf_mem_malloc(8u, "lim_send_stop_bss_response", 127);
    if ( result )
    {
      *(_DWORD *)(result + 4) = a3;
      *(_BYTE *)result = a2;
      v28 = result;
      LOWORD(v27) = 5145;
      HIDWORD(v27) = 0;
      lim_diag_event_report(a1, 27, 0, a3);
      result = sys_process_mmh_msg(a1, &v27);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Unable to find session for stop bss response",
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               "lim_send_stop_bss_response");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
