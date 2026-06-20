__int64 __fastcall policy_mgr_allow_sap_go_concurrency(__int64 a1, int a2, unsigned int a3, int a4)
{
  __int64 v4; // x29
  __int64 v5; // x30
  char is_hw_dbs_capable; // w23
  __int64 v11; // x25
  int v12; // w24
  unsigned int v13; // w27
  char p2p_p2p_conc_support; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  __int64 v24; // x0
  char v25; // w28
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x2
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x8
  __int64 v44; // x0
  char v45; // w28
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  const char *v54; // x2
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  const char *v63; // x2
  __int64 v65; // [xsp+0h] [xbp-60h]
  __int64 v66; // [xsp+8h] [xbp-58h]

  if ( (a2 & 0xFFFFFFFD) != 1 )
    return 1;
  v65 = v4;
  v66 = v5;
  is_hw_dbs_capable = policy_mgr_is_hw_dbs_capable(a1);
  v11 = 0;
  while ( 1 )
  {
    if ( *((_BYTE *)&pm_conc_connection_list + v11 + 28) != 1 )
      goto LABEL_3;
    if ( *(_DWORD *)((char *)&pm_conc_connection_list + v11 + 24) == a4 )
      goto LABEL_3;
    v12 = *(_DWORD *)((char *)&pm_conc_connection_list + v11);
    if ( (v12 & 0xFFFFFFFD) != 1 )
      goto LABEL_3;
    v13 = *(_DWORD *)((char *)&pm_conc_connection_list + v11 + 4);
    p2p_p2p_conc_support = wlan_mlme_get_p2p_p2p_conc_support(a1);
    if ( v12 == 3 && a2 == 3 && (p2p_p2p_conc_support & 1) != 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: GO+GO scc is allowed freq = %d ",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "policy_mgr_allow_sap_go_concurrency",
        a3,
        v65,
        v66);
      return 1;
    }
    if ( !a1 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Invalid WMI handle",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "policy_mgr_dual_beacon_on_single_mac_mcc_capable",
        v65,
        v66);
LABEL_30:
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Invalid WMI handle",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "policy_mgr_dual_beacon_on_single_mac_scc_capable");
      goto LABEL_31;
    }
    v23 = *(_QWORD *)(a1 + 2800);
    if ( v23 && (v24 = *(_QWORD *)(v23 + 16)) != 0 )
    {
      v25 = wmi_service_enabled(v24, 0x99u, v15, v16, v17, v18, v19, v20, v21, v22);
      if ( (v25 & 1) != 0 )
        v34 = "%s: Dual beaconing on different channel on single MAC supported";
      else
        v34 = "%s: Dual beaconing on different channel on single MAC is not supported";
      qdf_trace_msg(
        0x4Fu,
        8u,
        v34,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "policy_mgr_dual_beacon_on_single_mac_mcc_capable",
        v65,
        v66);
      if ( (v25 & 1) != 0 && (a2 | 2) == 3 && (v12 | 2) == 3 )
        return 1;
      v43 = *(_QWORD *)(a1 + 2800);
      if ( !v43 )
        goto LABEL_30;
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Invalid WMI handle",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "policy_mgr_dual_beacon_on_single_mac_mcc_capable",
        v65,
        v66);
      v43 = *(_QWORD *)(a1 + 2800);
      if ( !v43 )
        goto LABEL_30;
    }
    v44 = *(_QWORD *)(v43 + 16);
    if ( !v44 )
      goto LABEL_30;
    v45 = wmi_service_enabled(v44, 0x98u, v35, v36, v37, v38, v39, v40, v41, v42);
    if ( (v45 & 1) != 0 )
      v54 = "%s: Dual beaconing on same channel on single MAC supported";
    else
      v54 = "%s: Dual beaconing on same channel on single MAC is not supported";
    qdf_trace_msg(
      0x4Fu,
      8u,
      v54,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "policy_mgr_dual_beacon_on_single_mac_scc_capable");
    if ( (v45 & 1) != 0 && v13 == a3 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: SCC enabled, 2 AP on same channel, allow 2nd AP",
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "policy_mgr_allow_sap_go_concurrency");
      return 1;
    }
LABEL_31:
    if ( (is_hw_dbs_capable & 1) == 0 )
      break;
    if ( (policy_mgr_are_2_freq_on_same_mac(a1, a3, v13) & 1) != 0 )
    {
      v63 = "%s: DBS supported, 2 SAP on same band, reject 2nd AP";
      goto LABEL_38;
    }
LABEL_3:
    v11 += 36;
    if ( v11 == 180 )
      return 1;
  }
  v63 = "%s: DBS unsupported, mcc and scc unsupported too, don't allow 2nd AP";
LABEL_38:
  qdf_trace_msg(0x4Fu, 8u, v63, v55, v56, v57, v58, v59, v60, v61, v62, "policy_mgr_allow_sap_go_concurrency");
  return 0;
}
