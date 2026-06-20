__int64 __fastcall hdd_dcs_clear(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v9; // x8
  __int64 v10; // x19
  const char *v12; // x2
  __int64 result; // x0
  __int64 v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  unsigned int v24; // w21
  unsigned int v25; // w22
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
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
  unsigned __int8 v58[4]; // [xsp+Ch] [xbp-24h] BYREF
  _QWORD v59[2]; // [xsp+10h] [xbp-20h] BYREF
  int v60; // [xsp+20h] [xbp-10h]
  __int64 v61; // [xsp+28h] [xbp-8h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(__int64 **)(a1 + 24);
  v58[0] = 0;
  v60 = 0;
  v59[0] = 0;
  v59[1] = 0;
  if ( !v9 )
  {
    v12 = "%s: Invalid HDD context pointer";
    goto LABEL_5;
  }
  v10 = *v9;
  if ( (unsigned int)policy_mgr_get_mac_id_by_session_id(*v9, *(_BYTE *)(*(_QWORD *)(a1 + 52824) + 8LL), v58) )
  {
    v12 = "%s: get mac id failed";
LABEL_5:
    result = qdf_trace_msg(0x33u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_dcs_clear");
    goto LABEL_13;
  }
  v14 = *(_QWORD *)(*(_QWORD *)(a1 + 52824) + 272LL);
  if ( (unsigned int)policy_mgr_get_sap_go_count_on_mac(v10, v59, v58[0]) <= 1 )
  {
    ucfg_config_dcs_disable(v10, v58[0], 2, v15, v16, v17, v18, v19, v20, v21, v22);
    v23 = *(_QWORD *)(a1 + 52824);
    v24 = v58[0];
    v25 = *(unsigned __int8 *)(v23 + 8);
    if ( (ucfg_is_vdev_level_dcs_supported(v10, v26, v27, v28, v29, v30, v31, v32, v33) & 1) != 0 )
      ucfg_wlan_dcs_cmd_for_vdev(v10, v24, v25, v34, v35, v36, v37, v38, v39, v40, v41);
    else
      ucfg_wlan_dcs_cmd(v10, v24, 1, v34, v35, v36, v37, v38, v39, v40, v41);
    if ( (wlansap_dcs_is_wlan_interference_mitigation_enabled(v14, v42, v43, v44, v45, v46, v47, v48, v49) & 1) != 0 )
      ucfg_dcs_clear(v10, v58[0], v15, v16, v17, v18, v19, v20, v21, v22);
  }
  wlansap_dcs_set_vdev_wlan_interference_mitigation(v14, 0, v15, v16, v17, v18, v19, v20, v21, v22);
  result = wlansap_dcs_set_vdev_starting(v14, 0, v50, v51, v52, v53, v54, v55, v56, v57);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
