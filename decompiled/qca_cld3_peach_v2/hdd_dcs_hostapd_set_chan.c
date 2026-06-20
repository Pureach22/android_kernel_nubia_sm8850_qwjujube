__int64 __fastcall hdd_dcs_hostapd_set_chan(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  const char *v15; // x2
  __int64 v16; // x4
  int v17; // w22
  bool is_vdev_ll_lt_sap; // w8
  __int64 v19; // x0
  int v20; // w21
  __int64 result; // x0
  __int64 link_info_by_vdev; // x0
  int *v23; // x24
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x1
  __int64 v30; // x0
  unsigned int cu_for_freq; // w21
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int trnsprt_switch_rjt_th_cu; // w0
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
  unsigned int v57; // w21
  __int64 v58; // x22
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned __int8 v67[4]; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v68; // [xsp+10h] [xbp-20h] BYREF
  __int64 v69; // [xsp+18h] [xbp-18h] BYREF
  int v70; // [xsp+20h] [xbp-10h] BYREF
  __int64 v71; // [xsp+28h] [xbp-8h]

  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)a1;
  v67[0] = 0;
  v70 = 0;
  v68 = 0;
  v69 = 0;
  if ( (unsigned int)policy_mgr_get_mac_id_by_session_id(v6, a2, v67) )
  {
    v15 = "%s: vdev %d get mac id failed";
    v16 = (unsigned __int8)a2;
LABEL_23:
    qdf_trace_msg(0x33u, 2u, v15, v7, v8, v9, v10, v11, v12, v13, v14, "hdd_dcs_hostapd_set_chan", v16);
LABEL_24:
    result = 4;
    goto LABEL_25;
  }
  v17 = (unsigned __int8)a2;
  is_vdev_ll_lt_sap = policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)a1, (unsigned __int8)a2);
  v19 = *(_QWORD *)a1;
  if ( is_vdev_ll_lt_sap )
  {
    hdd_switch_bearer_to_wlan_on_ll_lt_sap_acs_complete(v19, a2);
    if ( (policy_mgr_is_scc_with_this_vdev_id(*(_QWORD *)a1, a2) & 1) == 0 )
    {
      cu_for_freq = wlan_ll_sap_get_cu_for_freq(*(_QWORD *)(a1 + 8), a3);
      trnsprt_switch_rjt_th_cu = wlan_dcs_get_trnsprt_switch_rjt_th_cu(
                                   *(_QWORD *)a1,
                                   v67[0],
                                   v32,
                                   v33,
                                   v34,
                                   v35,
                                   v36,
                                   v37,
                                   v38,
                                   v39);
      if ( cu_for_freq )
      {
        if ( cu_for_freq > trnsprt_switch_rjt_th_cu )
        {
          qdf_trace_msg(
            0x33u,
            4u,
            "%s: Congested channel cu %d > coch_intfr_threshold %d, no need to do CSA",
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            "hdd_dcs_hostapd_set_chan",
            cu_for_freq,
            trnsprt_switch_rjt_th_cu);
          ucfg_config_dcs_event_data(*(_QWORD *)a1, v67[0], 1, v49, v50, v51, v52, v53, v54, v55, v56);
          goto LABEL_24;
        }
      }
    }
    v20 = 1;
    LODWORD(v68) = v17;
  }
  else
  {
    result = policy_mgr_get_sap_go_count_on_mac(v19, &v68, v67[0]);
    v20 = result;
    if ( !(_DWORD)result )
    {
LABEL_25:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  link_info_by_vdev = hdd_get_link_info_by_vdev(a1, v68);
  if ( !link_info_by_vdev )
    goto LABEL_21;
  v23 = (int *)&v68 + 1;
  wlansap_dcs_set_vdev_starting(
    *(_QWORD *)(link_info_by_vdev + 272),
    *(_DWORD *)(link_info_by_vdev + 2424) != a3,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14);
  if ( v20 == 1 )
    goto LABEL_17;
  v24 = hdd_get_link_info_by_vdev(a1, SHIDWORD(v68));
  if ( !v24 )
    goto LABEL_22;
  wlansap_dcs_set_vdev_starting(
    *(_QWORD *)(v24 + 272),
    *(_DWORD *)(v24 + 2424) != a3,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14);
  if ( v20 == 2 )
    goto LABEL_17;
  v25 = hdd_get_link_info_by_vdev(a1, v69);
  if ( !v25 )
  {
    v23 = (int *)&v69;
    goto LABEL_22;
  }
  wlansap_dcs_set_vdev_starting(
    *(_QWORD *)(v25 + 272),
    *(_DWORD *)(v25 + 2424) != a3,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14);
  if ( v20 == 3 )
    goto LABEL_17;
  v26 = hdd_get_link_info_by_vdev(a1, SHIDWORD(v69));
  if ( !v26 )
  {
    v23 = (int *)&v69 + 1;
    goto LABEL_22;
  }
  wlansap_dcs_set_vdev_starting(
    *(_QWORD *)(v26 + 272),
    *(_DWORD *)(v26 + 2424) != a3,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14);
  if ( v20 == 4 )
    goto LABEL_17;
  v27 = hdd_get_link_info_by_vdev(a1, v70);
  if ( !v27 )
  {
    v23 = &v70;
    goto LABEL_22;
  }
  v28 = wlansap_dcs_set_vdev_starting(
          *(_QWORD *)(v27 + 272),
          *(_DWORD *)(v27 + 2424) != a3,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14);
  if ( v20 == 5 )
  {
LABEL_17:
    v30 = hdd_get_link_info_by_vdev(a1, v68);
    if ( v30 )
    {
      if ( *(_DWORD *)(v30 + 2424) != a3 )
        goto LABEL_40;
      if ( v20 == 1 )
      {
LABEL_20:
        result = 0;
        goto LABEL_25;
      }
      v30 = hdd_get_link_info_by_vdev(a1, SHIDWORD(v68));
      if ( v30 )
      {
        if ( *(_DWORD *)(v30 + 2424) != a3 )
          goto LABEL_40;
        if ( v20 == 2 )
          goto LABEL_20;
        v30 = hdd_get_link_info_by_vdev(a1, v69);
        v23 = (int *)&v69;
        if ( v30 )
        {
          if ( *(_DWORD *)(v30 + 2424) != a3 )
            goto LABEL_40;
          if ( v20 == 3 )
            goto LABEL_20;
          v30 = hdd_get_link_info_by_vdev(a1, SHIDWORD(v69));
          v23 = (int *)&v69 + 1;
          if ( v30 )
          {
            if ( *(_DWORD *)(v30 + 2424) != a3 )
              goto LABEL_40;
            if ( v20 == 4 )
              goto LABEL_20;
            v30 = hdd_get_link_info_by_vdev(a1, v70);
            v23 = &v70;
            if ( v30 )
            {
              if ( *(_DWORD *)(v30 + 2424) == a3 )
                goto LABEL_20;
LABEL_40:
              *(_DWORD *)(a1 + 1620) = 0;
              v57 = *(unsigned __int16 *)(v30 + 1466);
              v58 = v30;
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: dcs triggers old ch:%d new ch:%d new BW:%d",
                v7,
                v8,
                v9,
                v10,
                v11,
                v12,
                v13,
                v14,
                "hdd_dcs_hostapd_set_chan",
                *(unsigned int *)(v30 + 2424),
                a3,
                *(unsigned __int16 *)(v30 + 1466));
              wlan_hdd_set_sap_csa_reason(*(_QWORD *)a1, *(_BYTE *)(v58 + 8), 0xAu);
              LODWORD(result) = hdd_switch_sap_chan_freq(v58, a3, v57, 1, v59, v60, v61, v62, v63, v64, v65, v66);
              if ( (_DWORD)result )
                result = (unsigned int)result;
              else
                result = 24;
              goto LABEL_25;
            }
          }
        }
      }
LABEL_22:
      v16 = (unsigned int)*v23;
      v15 = "%s: vdev_id %u does not exist with host";
      goto LABEL_23;
    }
LABEL_21:
    v23 = (int *)&v68;
    goto LABEL_22;
  }
  __break(0x5512u);
  return hdd_switch_bearer_to_wlan_on_ll_lt_sap_acs_complete(v28, v29);
}
