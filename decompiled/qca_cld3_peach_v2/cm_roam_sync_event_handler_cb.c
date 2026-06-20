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
  __int64 v11; // x21
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
  unsigned int started; // w0
  unsigned int v26; // w20
  __int64 result; // x0
  const char *v28; // x2
  __int64 v29; // x5
  const char *v30; // x2
  unsigned int v31; // w2
  unsigned int v32; // w0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w20
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  _BYTE v58[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v59; // [xsp+8h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58[0] = 0;
  if ( !a2 )
  {
    v28 = "%s: Roam Sync ind ptr is NULL";
LABEL_13:
    qdf_trace_msg(0x68u, 2u, v28, a3, a4, a5, a6, a7, a8, a9, a10, "cm_roam_sync_event_handler_cb");
    goto LABEL_14;
  }
  if ( !a1 )
  {
    v28 = "%s: Vdev is NULL";
    goto LABEL_13;
  }
  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v28 = "%s: Psoc is NULL";
    goto LABEL_13;
  }
  v13 = *(unsigned __int8 *)(a1 + 168);
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
LABEL_14:
    result = 29;
    goto LABEL_15;
  }
  v16 = rso_config_fl;
  wlan_roam_debug_log(*(unsigned __int8 *)(a2 + 13), 8u, 0xFFFFu, a2 + 14, 0, 0, 0);
  qdf_dp_trace_record_event(6, *(_BYTE *)(a2 + 13), 0xFFu, 6, 32);
  if ( (unsigned int)mlme_get_roam_state(v11, *(unsigned __int8 *)(a2 + 13)) == 5 && (is_multi_link_roam(a2) & 1) == 0 )
  {
    v29 = *(unsigned __int8 *)(a2 + 13);
    v30 = "%s: vdev:%d Ignoring RSI as its already in progress on roamed vdev:%d";
LABEL_25:
    qdf_trace_msg(0x68u, 2u, v30, v17, v18, v19, v20, v21, v22, v23, v24, "cm_roam_sync_event_handler_cb", v13, v29);
    result = 16;
    goto LABEL_15;
  }
  started = cm_fw_roam_sync_start_ind(a1, a2);
  if ( started )
  {
    v26 = started;
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
    result = v26;
    goto LABEL_15;
  }
  if ( (*(_BYTE *)(a1 + 60) & 2) != 0 && *(_WORD *)(a2 + 2494) )
  {
    if ( *(unsigned __int16 *)(a2 + 2494) <= 0x24u )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: LFR3: MLO: vdev:%d Invalid link Beacon Length",
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
      result = 16;
      goto LABEL_15;
    }
    goto LABEL_23;
  }
  v29 = *(unsigned __int16 *)(a2 + 2);
  if ( (unsigned int)v29 < 0x25 )
  {
    v30 = "%s: LFR3: vdev:%d Invalid Beacon Length:%d";
    goto LABEL_25;
  }
  if ( (is_multi_link_roam(a2) & 1) == 0 )
  {
    v31 = *(unsigned __int16 *)(a2 + 2) - 36;
    goto LABEL_27;
  }
LABEL_23:
  v31 = 2268;
LABEL_27:
  v32 = cm_roam_pe_sync_callback(a2, v13, v31, v58, v17, v18, v19, v20, v21, v22, v23, v24);
  if ( v32 )
  {
    v41 = v32;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: LFR3: vdev:%d PE roam synch cb failed",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "cm_roam_sync_event_handler_cb",
      v13);
    result = v41;
  }
  else
  {
    result = cm_roam_update_vdev(a1, a2, v33, v34, v35, v36, v37, v38, v39, v40);
    if ( !(_DWORD)result )
    {
      cm_update_phymode_on_roam(v13, a2, v42, v43, v44, v45, v46, v47, v48, v49);
      result = cm_fw_roam_sync_propagation(v11, v13, (unsigned __int16 *)a2, v50, v51, v52, v53, v54, v55, v56, v57);
    }
  }
  if ( v58[0] == 1 && (_DWORD)result )
    result = cm_roam_delete_session_for_sl_to_ml_failure(v13, v42, v43, v44, v45, v46, v47, v48, v49);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
