__int64 __fastcall target_if_peer_capture_event(
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
  __int64 v11; // x24
  __int64 v12; // x19
  const char *v13; // x2
  __int64 result; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  const char *v17; // x2
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x0
  __int64 v27; // x21
  __int64 v28; // x20
  const char *v29; // x2
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 comp_private_obj; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x22
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x4
  __int64 v66; // x5
  __int64 v67; // x6
  __int64 v68; // x7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned int *v77; // x8
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  unsigned int *v86; // x8
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  _DWORD v95[6]; // [xsp+0h] [xbp-150h] BYREF
  __int64 v96; // [xsp+18h] [xbp-138h]
  _QWORD v97[38]; // [xsp+20h] [xbp-130h] BYREF

  v97[37] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v95[5] = 0;
  v96 = 0;
  memset(v97, 0, 296);
  if ( !a1 || !a2 )
  {
    v13 = "%s: sc or data is null";
    goto LABEL_10;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v13 = "%s: psoc is null";
    goto LABEL_10;
  }
  v11 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
  v12 = psoc_from_scn_hdl;
  if ( !v11 )
  {
    v13 = "%s: rx_ops is NULL";
    goto LABEL_10;
  }
  if ( (unsigned int)wlan_objmgr_psoc_try_get_ref(psoc_from_scn_hdl, 0x30u, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    v13 = "%s: unable to get psoc reference";
LABEL_10:
    qdf_trace_msg(0x6Au, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_peer_capture_event");
LABEL_11:
    result = 4294967274LL;
    goto LABEL_12;
  }
  v15 = *(_QWORD *)(v12 + 2800);
  if ( !v15 || (v16 = *(_QWORD *)(v15 + 16)) == 0 )
  {
    v17 = "%s: wmi_handle is null";
    goto LABEL_18;
  }
  if ( (unsigned int)wmi_extract_cfr_peer_tx_event_param(v16) )
  {
    v17 = "%s: Failed to extract cfr tx event param";
LABEL_18:
    qdf_trace_msg(0x6Au, 2u, v17, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_peer_capture_event");
    wlan_objmgr_psoc_release_ref(v12, 0x30u, v18, v19, v20, v21, v22, v23, v24, v25);
    goto LABEL_11;
  }
  v26 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v12, HIDWORD(v96), 48);
  if ( !v26 )
  {
    v17 = "%s: vdev is null";
    goto LABEL_18;
  }
  v27 = *(_QWORD *)(v26 + 152);
  v28 = v26;
  if ( !v27 )
  {
    v29 = "%s: pdev is null";
    goto LABEL_25;
  }
  if ( (unsigned int)wlan_objmgr_pdev_try_get_ref(*(_QWORD *)(v26 + 152), 0x30u, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    v29 = "%s: failed to get pdev reference";
LABEL_25:
    qdf_trace_msg(0x6Au, 2u, v29, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_peer_capture_event");
    wlan_objmgr_psoc_release_ref(v12, 0x30u, v30, v31, v32, v33, v34, v35, v36, v37);
    wlan_objmgr_vdev_release_ref(v28, 0x30u, v38, v39, v40, v41, v42, v43, v44, v45, v46);
    goto LABEL_11;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(v27, 0x1Eu);
  if ( comp_private_obj )
  {
    v56 = comp_private_obj;
    target_if_cfr_get_target_type(v12, v48, v49, v50, v51, v52, v53, v54, v55);
    if ( v95 == (_DWORD *)-32LL )
      v65 = 0;
    else
      v65 = LOBYTE(v97[0]);
    if ( v97 )
      v66 = BYTE1(v97[0]);
    else
      v66 = 0;
    if ( v97 )
      v67 = BYTE2(v97[0]);
    else
      v67 = 0;
    if ( v97 )
      v68 = BYTE5(v97[0]);
    else
      v68 = 0;
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: CFR capture failed for peer: %02x:%02x:%02x:**:**:%02x",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "target_if_peer_capture_event",
      v65,
      v66,
      v67,
      v68);
    ++*(_QWORD *)(v56 + 128);
  }
  else
  {
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: pdev object for CFR is NULL",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "target_if_peer_capture_event");
  }
  wlan_objmgr_psoc_release_ref(v12, 0x30u, v69, v70, v71, v72, v73, v74, v75, v76);
  wlan_objmgr_vdev_release_ref(v28, 0x30u, v77, v78, v79, v80, v81, v82, v83, v84, v85);
  wlan_objmgr_pdev_release_ref(v27, 0x30u, v86, v87, v88, v89, v90, v91, v92, v93, v94);
  result = 4294967274LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
