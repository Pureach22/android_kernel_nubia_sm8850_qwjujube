__int64 __fastcall target_if_wifi_pos_pasn_peer_delete_ev_handler(__int64 a1)
{
  __int64 psoc_from_scn_hdl; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v20; // x22
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned __int8 *v30; // x20
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  const char *v47; // x2
  __int64 v49; // x8
  double (__fastcall *v50)(__int64, unsigned __int8 *, __int64, __int64); // x8
  __int64 v51; // x3
  __int64 v52; // x2
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  const char *v61; // x4

  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v47 = "%s: psoc is null";
    goto LABEL_9;
  }
  v10 = psoc_from_scn_hdl;
  wlan_objmgr_psoc_get_ref(psoc_from_scn_hdl, 0x29u, v2, v3, v4, v5, v6, v7, v8, v9);
  v19 = *(_QWORD *)(v10 + 2800);
  if ( !v19 || (v20 = *(_QWORD *)(v19 + 16)) == 0 )
  {
    wlan_objmgr_psoc_release_ref(v10, 0x29u, v11, v12, v13, v14, v15, v16, v17, v18);
    v47 = "%s: wmi_handle is null";
LABEL_9:
    qdf_trace_msg(0x49u, 2u, v47, v2, v3, v4, v5, v6, v7, v8, v9, "target_if_wifi_pos_pasn_peer_delete_ev_handler");
    return 28;
  }
  v21 = _qdf_mem_malloc(0x17C4u, "target_if_wifi_pos_pasn_peer_delete_ev_handler", 262);
  if ( !v21 )
  {
    wlan_objmgr_psoc_release_ref(v10, 0x29u, v22, v23, v24, v25, v26, v27, v28, v29);
    return 2;
  }
  v30 = (unsigned __int8 *)v21;
  if ( (unsigned int)wmi_extract_pasn_peer_delete_req(v20) )
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Extract PASN peer delete failed",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "target_if_wifi_pos_pasn_peer_delete_ev_handler");
LABEL_20:
    wlan_objmgr_psoc_release_ref(v10, 0x29u, v39, v40, v41, v42, v43, v44, v45, v46);
    _qdf_mem_free((__int64)v30);
    return 29;
  }
  v49 = *(_QWORD *)(v10 + 2136);
  if ( !v49 )
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: rx_ops is NULL",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "target_if_wifi_pos_get_rx_ops");
    v61 = "rx_ops";
LABEL_19:
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: %s is null",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "target_if_wifi_pos_pasn_peer_delete_ev_handler",
      v61);
    goto LABEL_20;
  }
  v50 = *(double (__fastcall **)(__int64, unsigned __int8 *, __int64, __int64))(v49 + 400);
  if ( !v50 )
  {
    v61 = "rx_ops_cb";
    goto LABEL_19;
  }
  v51 = v30[1];
  v52 = *v30;
  if ( *((_DWORD *)v50 - 1) != 20355383 )
    __break(0x8228u);
  v53 = v50(v10, v30 + 4, v52, v51);
  wlan_objmgr_psoc_release_ref(v10, 0x29u, v53, v54, v55, v56, v57, v58, v59, v60);
  _qdf_mem_free((__int64)v30);
  return 0;
}
