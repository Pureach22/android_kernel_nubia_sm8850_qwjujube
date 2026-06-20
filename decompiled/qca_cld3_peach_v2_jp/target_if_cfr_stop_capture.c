__int64 __fastcall target_if_cfr_stop_capture(__int64 a1, __int64 a2)
{
  __int64 comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  __int64 pdev_wmi_handle; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x22
  __int64 v24; // x23
  int v25; // w9
  int v26; // w8
  unsigned int v27; // w19
  __int64 v28; // x0
  _QWORD *v29; // x20
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 result; // x0
  const char *v63; // x2
  __int64 v64; // [xsp+8h] [xbp-28h] BYREF
  __int64 v65; // [xsp+10h] [xbp-20h]
  __int64 v66; // [xsp+18h] [xbp-18h]
  __int64 v67; // [xsp+20h] [xbp-10h]
  __int64 v68; // [xsp+28h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(a2, 0x1Eu);
  if ( !comp_private_obj )
    goto LABEL_8;
  v13 = comp_private_obj;
  pdev_wmi_handle = lmac_get_pdev_wmi_handle(a1, v5, v6, v7, v8, v9, v10, v11, v12);
  if ( !pdev_wmi_handle )
  {
    v63 = "%s: pdev wmi handle NULL";
LABEL_7:
    qdf_trace_msg(0x6Au, 2u, v63, v15, v16, v17, v18, v19, v20, v21, v22, "target_if_cfr_stop_capture");
LABEL_8:
    result = 4294967274LL;
    goto LABEL_9;
  }
  v23 = pdev_wmi_handle;
  v24 = *(_QWORD *)(a2 + 88);
  qdf_mem_set(&v64, 0x20u, 0);
  v25 = *(unsigned __int8 *)(v24 + 104);
  v65 = a2 + 48;
  LODWORD(v66) = v25;
  v26 = *(_DWORD *)(v13 + 12);
  LODWORD(v64) = 0;
  HIDWORD(v66) = v26;
  LODWORD(v67) = *(unsigned __int8 *)(v13 + 9);
  HIDWORD(v67) = *(unsigned __int8 *)(v13 + 16);
  v27 = wmi_unified_send_peer_cfr_capture_cmd(v23, &v64);
  v28 = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
  if ( !v28 )
  {
    v63 = "%s: pdev object for CFR is null";
    goto LABEL_7;
  }
  v29 = (_QWORD *)v28;
  qdf_trace_msg(
    0x6Au,
    2u,
    "%s: CFR capture stats for this capture:",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "target_if_cfr_stop_capture");
  qdf_trace_msg(
    0x6Au,
    2u,
    "%s: DBR event count = %llu, Tx event count = %llu Release count = %llu",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "target_if_cfr_stop_capture",
    v29[14],
    v29[12],
    v29[15]);
  qdf_trace_msg(
    0x6Au,
    2u,
    "%s: tx_peer_status_cfr_fail = %llu",
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    "target_if_cfr_stop_capture",
    v29[16]);
  qdf_trace_msg(
    0x6Au,
    2u,
    "%s: tx_evt_status_cfr_fail = %llu",
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    "target_if_cfr_stop_capture",
    v29[17]);
  qdf_trace_msg(
    0x6Au,
    2u,
    "%s: tx_dbr_cookie_lookup_fail = %llu",
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    "target_if_cfr_stop_capture",
    v29[18]);
  result = v27;
  v29[12] = 0;
  v29[14] = 0;
  v29[15] = 0;
  v29[16] = 0;
  v29[17] = 0;
  v29[18] = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
