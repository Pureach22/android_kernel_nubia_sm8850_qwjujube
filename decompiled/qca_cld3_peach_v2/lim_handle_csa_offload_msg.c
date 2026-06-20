__int64 __fastcall lim_handle_csa_offload_msg(
        _QWORD *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int8 *v10; // x19
  __int64 session_by_bssid; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 result; // x0
  _BYTE v39[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v40; // [xsp+8h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned __int8 **)(a2 + 8);
  v39[0] = 0;
  if ( v10 )
  {
    session_by_bssid = pe_find_session_by_bssid(a1, v10 + 28, v39);
    if ( session_by_bssid )
    {
      v21 = session_by_bssid;
      if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(session_by_bssid + 16), v13, v14, v15, v16, v17, v18, v19, v20) & 1) != 0
        && (mlo_is_sta_csa_param_handled(*(_QWORD *)(v21 + 16), v10) & 1) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: vdev_id: %d, csa param is already handled. return",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "lim_handle_csa_offload_msg",
          v39[0]);
        _qdf_mem_free((__int64)v10);
        result = wlan_mlme_send_csa_event_status_ind(*(_QWORD *)(v21 + 16), 0, v30, v31, v32, v33, v34, v35, v36, v37);
      }
      else
      {
        result = lim_handle_sta_csa_param(a1, v10, 1, v22, v23, v24, v25, v26, v27, v28, v29);
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Session does not exists for %02x:%02x:%02x:**:**:%02x",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "lim_handle_csa_offload_msg",
        v10[28],
        v10[29],
        v10[30],
        v10[33]);
      result = _qdf_mem_free((__int64)v10);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: limMsgQ body ptr is NULL",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "lim_handle_csa_offload_msg");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
