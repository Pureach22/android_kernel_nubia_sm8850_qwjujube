__int64 __fastcall wlan_mgmt_txrx_mgmt_frame_tx(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        __int64 a14,
        __int64 a15)
{
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x5
  __int64 v30; // x22
  __int64 v31; // x23
  const char *v32; // x2
  __int64 v33; // x4
  __int64 result; // x0
  __int64 v35; // x26
  _QWORD *comp_private_obj; // x0
  _QWORD *v37; // x0
  _QWORD *v38; // x21
  char v39; // w8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 (__fastcall **v48)(__int64, __int64, __int64, __int64); // x8
  __int64 (__fastcall *v49)(__int64, __int64, __int64, __int64); // x8
  __int64 v50; // x2
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int v59; // w1
  __int64 v60; // [xsp+8h] [xbp-8h]

  if ( !a1 )
  {
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: peer passed is NULL",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "wlan_mgmt_txrx_mgmt_frame_tx");
    return 29;
  }
  if ( (unsigned int)wlan_objmgr_peer_try_get_ref(a1, 4) )
  {
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: failed to get ref count for peer %pK",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wlan_mgmt_txrx_mgmt_frame_tx",
      a1);
    return 29;
  }
  v29 = *(_QWORD *)(a1 + 96);
  if ( !v29 )
  {
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: vdev unavailable for peer %pK",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wlan_mgmt_txrx_mgmt_frame_tx",
      a1);
    goto LABEL_13;
  }
  v30 = *(_QWORD *)(v29 + 216);
  if ( !v30 || (v31 = *(_QWORD *)(v30 + 80)) == 0 )
  {
    v32 = "%s: psoc unavailable for peer %pK vdev %pK";
    v33 = a1;
LABEL_11:
    qdf_trace_msg(0x4Bu, 2u, v32, v21, v22, v23, v24, v25, v26, v27, v28, "wlan_mgmt_txrx_mgmt_frame_tx", v33);
    goto LABEL_13;
  }
  if ( (**(_BYTE **)(a3 + 224) & 3) != 0 )
  {
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: Incorrect frame control version",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wlan_mgmt_txrx_mgmt_frame_tx");
LABEL_13:
    wlan_objmgr_peer_release_ref(a1, 4);
    return 29;
  }
  v35 = *(_QWORD *)(a1 + 96);
  comp_private_obj = (_QWORD *)wlan_objmgr_pdev_get_comp_private_obj(*(_QWORD *)(v29 + 216), 1);
  if ( !comp_private_obj )
  {
    v32 = "%s: No txrx context for peer %pK pdev %pK";
    v33 = a1;
    goto LABEL_11;
  }
  v60 = (__int64)comp_private_obj;
  v37 = wlan_mgmt_txrx_desc_get(comp_private_obj);
  if ( !v37 )
  {
    wlan_objmgr_peer_release_ref(a1, 4);
    return 1;
  }
  v37[3] = a5;
  v37[4] = a3;
  v38 = v37;
  v37[2] = a4;
  v37[6] = a1;
  v39 = *(_BYTE *)(v35 + 168);
  v37[7] = a2;
  *((_BYTE *)v37 + 64) = v39;
  if ( (unsigned int)iot_sim_mgmt_tx_update() == 29 )
    goto LABEL_28;
  v48 = *(__int64 (__fastcall ***)(__int64, __int64, __int64, __int64))(v31 + 2128);
  if ( !v48 )
  {
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: tx_ops is NULL",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "wlan_mgmt_txrx_mgmt_frame_tx");
LABEL_28:
    wlan_objmgr_peer_release_ref(a1, 4);
    wlan_mgmt_txrx_desc_put(v60, *((_DWORD *)v38 + 10));
    return 29;
  }
  v49 = *v48;
  if ( !v49 )
  {
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: mgmt txrx txop to send mgmt frame is NULL for psoc: %pK",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "wlan_mgmt_txrx_mgmt_frame_tx",
      v31);
    goto LABEL_30;
  }
  v50 = *((unsigned int *)v38 + 10);
  if ( *((_DWORD *)v49 - 1) != 199632710 )
    __break(0x8228u);
  result = v49(v35, a3, v50, a15);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: Mgmt send fail for peer %pK psoc %pK pdev: %pK",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "wlan_mgmt_txrx_mgmt_frame_tx",
      a1,
      v31,
      v30);
LABEL_30:
    wlan_objmgr_peer_release_ref(a1, 4);
    v59 = *((_DWORD *)v38 + 10);
    v38[4] = 0;
    wlan_mgmt_txrx_desc_put(v60, v59);
    return 16;
  }
  return result;
}
