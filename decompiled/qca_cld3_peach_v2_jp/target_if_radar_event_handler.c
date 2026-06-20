__int64 __fastcall target_if_radar_event_handler(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 psoc_from_scn_hdl; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x22
  __int64 v23; // x8
  __int64 v24; // x8
  __int64 v25; // x21
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  const char *v35; // x2
  __int64 v36; // x4
  __int64 pdev_by_id; // x0
  __int64 v38; // x2
  __int64 v39; // x3
  double (__fastcall *v40)(__int64, __int64 *, __int64, __int64); // x8
  __int64 v41; // x19
  double v42; // d0
  unsigned int *v43; // x8
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // [xsp+0h] [xbp-30h] BYREF
  __int64 v52; // [xsp+8h] [xbp-28h]
  __int64 v53; // [xsp+10h] [xbp-20h]
  __int64 v54; // [xsp+18h] [xbp-18h]
  __int64 v55; // [xsp+20h] [xbp-10h]
  __int64 v56; // [xsp+28h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v51 = 0;
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: scn: %pK, data: %pK",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "target_if_radar_event_handler",
      a1,
      a2,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56);
LABEL_17:
    result = 4294967274LL;
    goto LABEL_18;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v35 = "%s: null psoc";
LABEL_14:
    qdf_trace_msg(
      0x49u,
      2u,
      v35,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_radar_event_handler",
      v51,
      v52,
      v53,
      v54);
    goto LABEL_17;
  }
  v22 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
  if ( !v22 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: rx_ops is NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_dfs_get_rx_ops",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56);
    v36 = 0;
LABEL_16:
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Invalid dfs_rx_ops: %pK",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_radar_event_handler",
      v36,
      v51,
      v52,
      v53,
      v54);
    goto LABEL_17;
  }
  if ( !*(_QWORD *)(v22 + 872) )
  {
    v36 = v22 + 680;
    goto LABEL_16;
  }
  v23 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v23 || (v24 = *(_QWORD *)(v23 + 16)) == 0 )
  {
    v35 = "%s: Invalid WMI context";
    goto LABEL_14;
  }
  v25 = psoc_from_scn_hdl;
  if ( (unsigned int)wmi_extract_wlan_radar_event_info(v24, a2, &v51, a3) )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: failed to extract wlan radar event",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "target_if_radar_event_handler",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56);
    result = 4294967282LL;
    goto LABEL_18;
  }
  pdev_by_id = wlan_objmgr_get_pdev_by_id(v25, v55, 0xEu);
  if ( !pdev_by_id )
  {
    v35 = "%s: null pdev";
    goto LABEL_14;
  }
  v40 = *(double (__fastcall **)(__int64, __int64 *, __int64, __int64))(v22 + 872);
  v41 = pdev_by_id;
  if ( *((_DWORD *)v40 - 1) != 506957694 )
    __break(0x8228u);
  v42 = v40(pdev_by_id, &v51, v38, v39);
  wlan_objmgr_pdev_release_ref(v41, 0xEu, v43, v42, v44, v45, v46, v47, v48, v49, v50);
  result = 0;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
