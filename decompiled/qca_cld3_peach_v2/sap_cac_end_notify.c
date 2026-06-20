__int64 __fastcall sap_cac_end_notify(
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
  __int64 v12; // x19
  _DWORD *v13; // x25
  unsigned int v14; // w28
  const char *v15; // x2
  __int64 v16; // x0
  bool v17; // zf
  unsigned int *v18; // x24
  __int64 v19; // x0
  __int64 active_channel; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x4
  __int64 v39; // x5
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int v56; // w0
  _BYTE *v57; // x8
  char v58; // w1
  __int64 v59; // x4
  const char *v60; // x2

  v12 = 0;
  v13 = (_DWORD *)(a1 + 14888);
  v14 = 16;
  while ( 1 )
  {
    v16 = *(_QWORD *)v13;
    v17 = (v13[2] | 2) != 3 || v16 == 0;
    if ( v17
      || (*(_BYTE *)(v16 + 1561) & 1) != 0
      || ((unsigned __int8)sap_is_dfs_cac_wait_state(v16, a3, a4, a5, a6, a7, a8, a9, a10) & 1) == 0 )
    {
      goto LABEL_4;
    }
    v18 = *(unsigned int **)v13;
    v19 = *(_QWORD *)(*(_QWORD *)v13 + 16LL);
    if ( v19 )
      break;
    v15 = "%s: vdev invalid";
LABEL_3:
    qdf_trace_msg(0x39u, 8u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "sap_operating_on_dfs");
LABEL_4:
    ++v12;
    v13 += 4;
    if ( v12 == 6 )
      return v14;
  }
  active_channel = wlan_vdev_get_active_channel(v19);
  if ( !active_channel )
  {
    v15 = "%s: Couldn't get vdev active channel";
    goto LABEL_3;
  }
  if ( (*(_WORD *)(active_channel + 6) & 6) == 0 )
    goto LABEL_4;
  if ( (wlan_pre_cac_get_status(*(_QWORD *)(a1 + 21624)) & 1) != 0 )
  {
    v59 = *((unsigned __int8 *)v18 + 12);
    *((_BYTE *)v18 + 13) = 0;
    *((_BYTE *)v18 + 1561) = 1;
    v18[182] = 2;
    qdf_trace_msg(
      0x39u,
      3u,
      "%s: sap_fsm: vdev %d => SAP_STARTED, pre cac end notify on %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wlansap_pre_cac_end_notify",
      v59,
      (unsigned int)v12);
    wlan_pre_cac_handle_cac_end(*((_QWORD *)v18 + 2));
    return v14;
  }
  v29 = sap_signal_hdd_event((__int64)v18, 0, 0x10u, nullptr, v21, v22, v23, v24, v25, v26, v27, v28);
  if ( v29 )
  {
    v14 = v29;
    v60 = "%s: failed setting isCacEndNotified on interface[%d]";
    goto LABEL_25;
  }
  *((_BYTE *)v18 + 1561) = 1;
  *((_BYTE *)v18 + 13) = 0;
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: sapdfs: Start beacon request on sapctx[%pK]",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "sap_cac_end_notify",
    v18);
  wlansap_start_beacon_req(v18);
  v38 = *((unsigned __int8 *)v18 + 12);
  v39 = *v18;
  v18[182] = 2;
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: sap_fsm: vdev %d: SAP_STARTING => SAP_STARTED, freq %d",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "sap_cac_end_notify",
    v38,
    v39);
  v56 = sap_signal_hdd_event((__int64)v18, a2, 0, nullptr, v48, v49, v50, v51, v52, v53, v54, v55);
  if ( !v56 )
  {
    v57 = *((_BYTE **)v18 + 193);
    if ( v57 )
      v58 = *v57 != 0;
    else
      v58 = 0;
    policy_mgr_check_concurrent_intf_and_restart_sap(*(_QWORD *)(a1 + 21624), v58);
    v14 = 0;
    goto LABEL_4;
  }
  v14 = v56;
  v60 = "%s: Failed setting isCacEndNotified on interface[%d]";
LABEL_25:
  qdf_trace_msg(0x39u, 2u, v60, v30, v31, v32, v33, v34, v35, v36, v37, "sap_cac_end_notify", (unsigned int)v12);
  return v14;
}
