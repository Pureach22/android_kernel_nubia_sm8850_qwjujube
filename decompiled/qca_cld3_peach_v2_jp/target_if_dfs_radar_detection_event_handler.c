__int64 __fastcall target_if_dfs_radar_detection_event_handler(
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
  __int64 psoc_from_scn_hdl; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x22
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 result; // x0
  const char *v32; // x2
  __int64 v33; // x4
  __int64 pdev_by_id; // x19
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  _DWORD *v43; // x8
  unsigned int *v44; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w20
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  _QWORD v62[7]; // [xsp+8h] [xbp-38h] BYREF

  v62[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v62, 0, 48);
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: scn: %pK, data: %pK",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_dfs_radar_detection_event_handler",
      a1,
      a2);
LABEL_17:
    result = 4294967274LL;
    goto LABEL_18;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v32 = "%s: null psoc";
LABEL_14:
    qdf_trace_msg(0x49u, 2u, v32, v11, v12, v13, v14, v15, v16, v17, v18, "target_if_dfs_radar_detection_event_handler");
    goto LABEL_17;
  }
  v19 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
  if ( !v19 )
  {
    qdf_trace_msg(0x49u, 2u, "%s: rx_ops is NULL", v11, v12, v13, v14, v15, v16, v17, v18, "target_if_dfs_get_rx_ops");
    v33 = 0;
LABEL_16:
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Invalid dfs_rx_ops: %pK",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "target_if_dfs_radar_detection_event_handler",
      v33);
    goto LABEL_17;
  }
  if ( !*(_QWORD *)(v19 + 824) )
  {
    v33 = v19 + 680;
    goto LABEL_16;
  }
  v20 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v20 || (v21 = *(_QWORD *)(v20 + 16)) == 0 )
  {
    v32 = "%s: Invalid WMI handle";
    goto LABEL_14;
  }
  v22 = psoc_from_scn_hdl;
  if ( (unsigned int)wmi_extract_dfs_radar_detection_event(v21) )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: failed to extract cac complete event",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "target_if_dfs_radar_detection_event_handler");
    result = 4294967282LL;
    goto LABEL_18;
  }
  pdev_by_id = wlan_objmgr_get_pdev_by_id(v22, v62[0], 0xEu);
  if ( !pdev_by_id )
  {
    pdev_by_id = wlan_objmgr_get_pdev_by_id(v22, 0, 0xEu);
    if ( !pdev_by_id )
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: pdev id %d null pdev",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "target_if_dfs_get_pdev",
        0);
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: pdev id %d null pdev",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "target_if_dfs_radar_detection_event_handler",
        LODWORD(v62[0]));
      goto LABEL_17;
    }
  }
  v43 = *(_DWORD **)(v19 + 824);
  if ( *(v43 - 1) != 1732649785 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(__int64, _QWORD *))v43)(pdev_by_id, v62) )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: dfs_process_radar_ind failed pdev_id=%d",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "target_if_dfs_radar_detection_event_handler",
      LODWORD(v62[0]));
    v53 = -22;
  }
  else
  {
    v53 = 0;
  }
  wlan_objmgr_pdev_release_ref(pdev_by_id, 0xEu, v44, v45, v46, v47, v48, v49, v50, v51, v52);
  result = v53;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
