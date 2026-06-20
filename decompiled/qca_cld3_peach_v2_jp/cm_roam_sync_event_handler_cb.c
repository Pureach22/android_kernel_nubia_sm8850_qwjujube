__int64 __fastcall cm_roam_sync_event_handler_cb(
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
  __int64 v10; // x8
  __int64 v11; // x20
  unsigned int v13; // w19
  __int64 rso_config_fl; // x0
  __int64 v16; // x23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x5
  const char *v26; // x2
  __int64 result; // x0
  const char *v28; // x2
  unsigned int started; // w0
  unsigned int v30; // w20
  unsigned int v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w20
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7

  _ReadStatusReg(SP_EL0);
  if ( !a2 )
  {
    v28 = "%s: Roam Sync ind ptr is NULL";
LABEL_12:
    qdf_trace_msg(0x68u, 2u, v28, a3, a4, a5, a6, a7, a8, a9, a10, "cm_roam_sync_event_handler_cb");
    goto LABEL_13;
  }
  if ( !a1 )
  {
    v28 = "%s: Vdev is NULL";
    goto LABEL_12;
  }
  v10 = *(_QWORD *)(a1 + 152);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v28 = "%s: Psoc is NULL";
    goto LABEL_12;
  }
  v13 = *(unsigned __int8 *)(a1 + 104);
  rso_config_fl = wlan_cm_get_rso_config_fl(
                    a1,
                    (__int64)"cm_roam_sync_event_handler_cb",
                    0x216u,
                    a3,
                    a4,
                    a5,
                    a6,
                    a7,
                    a8,
                    a9,
                    a10);
  if ( !rso_config_fl )
  {
LABEL_13:
    result = 29;
    goto LABEL_14;
  }
  v16 = rso_config_fl;
  wlan_roam_debug_log(*(unsigned __int8 *)(a2 + 13), 8u, 0xFFFFu, a2 + 14, 0, 0, 0);
  qdf_dp_trace_record_event(6, *(_BYTE *)(a2 + 13), 0xFFu, 6, 32);
  if ( (unsigned int)mlme_get_roam_state(v11, *(unsigned __int8 *)(a2 + 13)) == 5 )
  {
    v25 = *(unsigned __int8 *)(a2 + 13);
    v26 = "%s: vdev:%d Ignoring RSI as its already in progress on roamed vdev:%d";
LABEL_8:
    qdf_trace_msg(0x68u, 2u, v26, v17, v18, v19, v20, v21, v22, v23, v24, "cm_roam_sync_event_handler_cb", v13, v25);
    result = 16;
    goto LABEL_14;
  }
  started = cm_fw_roam_sync_start_ind(a1, a2);
  if ( started )
  {
    v30 = started;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: LFR3: vdev:%d CSR Roam synch cb failed",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "cm_roam_sync_event_handler_cb",
      v13);
    wlan_cm_free_roam_synch_frame_ind(v16);
    result = v30;
    goto LABEL_14;
  }
  v25 = *(unsigned __int16 *)(a2 + 2);
  if ( (unsigned int)v25 < 0x25 )
  {
    v26 = "%s: LFR3: vdev:%d Invalid Beacon Length:%d";
    goto LABEL_8;
  }
  v31 = cm_roam_pe_sync_callback(a2, v13, (int)v25 - 36, v17, v18, v19, v20, v21, v22, v23, v24);
  if ( v31 )
  {
    v40 = v31;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: LFR3: vdev:%d PE roam synch cb failed",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "cm_roam_sync_event_handler_cb",
      v13);
    result = v40;
  }
  else
  {
    result = cm_roam_update_vdev(a1, a2, v32, v33, v34, v35, v36, v37, v38, v39);
    if ( !(_DWORD)result )
    {
      cm_update_phymode_on_roam(v13, a2, v41, v42, v43, v44, v45, v46, v47, v48);
      result = cm_fw_roam_sync_propagation(v11, v13, (unsigned __int16 *)a2, v49, v50, v51, v52, v53, v54, v55, v56);
    }
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
