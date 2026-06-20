__int64 __fastcall target_if_wifi_pos_pasn_peer_create_ev_handler(__int64 a1)
{
  __int64 v2; // x0
  unsigned __int8 *v3; // x19
  __int64 psoc_from_scn_hdl; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v31; // x8
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
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
  __int64 v57; // x8
  double (__fastcall *v58)(__int64, unsigned __int8 *, __int64, __int64); // x8
  __int64 v59; // x3
  __int64 v60; // x2
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  const char *v69; // x4

  v2 = _qdf_mem_malloc(0x17C4u, "target_if_wifi_pos_pasn_peer_create_ev_handler", 181);
  if ( !v2 )
    return 4294967284LL;
  v3 = (unsigned __int8 *)v2;
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: psoc is null",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "target_if_wifi_pos_pasn_peer_create_ev_handler");
LABEL_21:
    _qdf_mem_free((__int64)v3);
    return 4294967274LL;
  }
  v13 = psoc_from_scn_hdl;
  wlan_objmgr_psoc_get_ref(psoc_from_scn_hdl, 0x29u, v5, v6, v7, v8, v9, v10, v11, v12);
  if ( (*(_BYTE *)(v13 + 24) & 0x40) == 0 )
  {
    wlan_objmgr_psoc_release_ref(v13, 0x29u, v14, v15, v16, v17, v18, v19, v20, v21);
    _qdf_mem_free((__int64)v3);
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: Firmware doesn't support Peer delete all",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "target_if_wifi_pos_pasn_peer_create_ev_handler");
    return 0xFFFFFFFFLL;
  }
  v31 = *(_QWORD *)(v13 + 2800);
  if ( !v31 || (v32 = *(_QWORD *)(v31 + 16)) == 0 )
  {
    wlan_objmgr_psoc_release_ref(v13, 0x29u, v14, v15, v16, v17, v18, v19, v20, v21);
    _qdf_mem_free((__int64)v3);
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: wmi_handle is null",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "target_if_wifi_pos_pasn_peer_create_ev_handler");
    return 4294967274LL;
  }
  if ( (unsigned int)wmi_extract_pasn_peer_create_req(v32) )
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: Extract PASN peer create failed",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "target_if_wifi_pos_pasn_peer_create_ev_handler");
LABEL_20:
    wlan_objmgr_psoc_release_ref(v13, 0x29u, v41, v42, v43, v44, v45, v46, v47, v48);
    goto LABEL_21;
  }
  v57 = *(_QWORD *)(v13 + 2136);
  if ( !v57 )
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: rx_ops is NULL",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "target_if_wifi_pos_get_rx_ops");
    v69 = "rx_ops";
LABEL_19:
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: %s is null",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "target_if_wifi_pos_pasn_peer_create_ev_handler",
      v69);
    goto LABEL_20;
  }
  v58 = *(double (__fastcall **)(__int64, unsigned __int8 *, __int64, __int64))(v57 + 384);
  if ( !v58 )
  {
    v69 = "rx_ops_cb";
    goto LABEL_19;
  }
  v59 = v3[1];
  v60 = *v3;
  if ( *((_DWORD *)v58 - 1) != 20355383 )
    __break(0x8228u);
  v61 = v58(v13, v3 + 4, v60, v59);
  wlan_objmgr_psoc_release_ref(v13, 0x29u, v61, v62, v63, v64, v65, v66, v67, v68);
  _qdf_mem_free((__int64)v3);
  return 0;
}
