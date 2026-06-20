__int64 __fastcall _lim_process_sme_session_update(
        __int64 a1,
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
  __int64 session_by_vdev_id; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  const char *v21; // x2
  const char *v22; // x3
  unsigned int v23; // w1
  __int64 result; // x0
  unsigned int v25; // w20
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7

  if ( !a2 )
  {
    v21 = "%s: Buffer is Pointing to NULL";
    goto LABEL_6;
  }
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)(a2 + 4));
  if ( !session_by_vdev_id )
    return qdf_trace_msg(
             0x35u,
             3u,
             "%s: Session does not exist for given vdev_id %d",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "__lim_process_sme_session_update",
             *(unsigned __int8 *)(a2 + 4));
  v20 = session_by_vdev_id;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: received SME Session update for %d val %d",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "__lim_process_sme_session_update",
    *(unsigned int *)(a2 + 8),
    *(unsigned int *)(a2 + 12));
  if ( *(_DWORD *)(a2 + 8) )
  {
    v21 = "%s: Unknown session param";
LABEL_6:
    v22 = "__lim_process_sme_session_update";
    v23 = 2;
    return qdf_trace_msg(0x35u, v23, v21, a3, a4, a5, a6, a7, a8, a9, a10, v22);
  }
  v25 = *(unsigned __int8 *)(a2 + 12);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: rcvd HIDE_SSID message old HIDE_SSID: %d new HIDE_SSID: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_handle_update_ssid_hidden",
    *(unsigned __int8 *)(v20 + 7020),
    v25);
  if ( *(unsigned __int8 *)(v20 + 7020) == v25 )
  {
    v21 = "%s: Dont process HIDE_SSID msg with existing setting";
    v22 = "lim_handle_update_ssid_hidden";
    v23 = 8;
    return qdf_trace_msg(0x35u, v23, v21, a3, a4, a5, a6, a7, a8, a9, a10, v22);
  }
  v26 = *(_QWORD *)(v20 + 16);
  *(_BYTE *)(v20 + 7020) = v25;
  ap_mlme_set_hidden_ssid_restart_in_progress(v26, 1, a3, a4, a5, a6, a7, a8, a9, a10);
  result = wlan_vdev_mlme_sm_deliver_evt(
             *(_QWORD *)(v20 + 16),
             0x15u,
             0x36B0u,
             v20,
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33,
             v34);
  if ( (_DWORD)result )
    return ap_mlme_set_hidden_ssid_restart_in_progress(*(_QWORD *)(v20 + 16), 0, v35, v36, v37, v38, v39, v40, v41, v42);
  return result;
}
