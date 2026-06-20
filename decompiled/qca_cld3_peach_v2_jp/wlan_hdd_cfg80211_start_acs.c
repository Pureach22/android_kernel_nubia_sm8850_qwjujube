__int64 __fastcall wlan_hdd_cfg80211_start_acs(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x22
  __int64 result; // x0
  __int64 v5; // x20
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 *conn_info; // x0
  int v23; // w1
  const void *v24; // x1
  int v25; // w8
  void *v26; // x0
  __int64 v27; // x23
  int v28; // w25
  __int64 v29; // x0
  __int64 v30; // x24
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  const char *v39; // x2
  const void *link_mac_addr; // x0
  int v41; // w0
  _BYTE v42[4]; // [xsp+8h] [xbp-38h] BYREF
  _BYTE v43[4]; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD v44[6]; // [xsp+10h] [xbp-30h] BYREF

  v44[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)a1;
  v42[0] = 0;
  v3 = *(_QWORD *)(v2 + 24);
  result = _wlan_hdd_validate_context(v3, "wlan_hdd_cfg80211_start_acs");
  if ( !(_DWORD)result )
  {
    v5 = *(_QWORD *)(a1 + 272);
    *(_DWORD *)(a1 + 720) = *(_DWORD *)(v3 + 1620);
    ucfg_policy_mgr_get_mcc_scc_switch(*(_QWORD *)v3, v42);
    if ( *(_DWORD *)(a1 + 2344) )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: ACS is already in progress vdev %d",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "wlan_hdd_cfg80211_start_acs",
        *(unsigned __int8 *)(*(_QWORD *)(v5 + 16) + 104LL));
      result = 0;
      goto LABEL_26;
    }
    if ( v42[0] != 5
      && ((policy_mgr_is_hw_dbs_capable(*(_QWORD *)v3) & 1) == 0 || !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a1 + 1428)))
      && (wlansap_dcs_is_wlan_interference_mitigation_enabled(v5) & 1) == 0 )
    {
      result = wlan_hdd_sap_cfg_dfs_override((__int64 *)a1, v14, v15, v16, v17, v18, v19, v20, v21);
      if ( (result & 0x80000000) != 0 )
        goto LABEL_26;
      if ( (_DWORD)result )
      {
        wlan_hdd_cfg80211_acs_ch_select_evt(a1, 1);
        ((void (__fastcall *)(__int64, __int64))wlansap_dcs_set_wlan_interference_mitigation_on_band)(v5, a1 + 280);
        result = 0;
        goto LABEL_26;
      }
    }
    if ( (unsigned int)policy_mgr_get_connection_count(*(_QWORD *)v3) == 2 && *(_DWORD *)(a1 + 1996) == 4 )
    {
      LODWORD(v44[0]) = 0;
      conn_info = policy_mgr_get_conn_info(v44);
      if ( (policy_mgr_are_2_freq_on_same_mac(*(_QWORD *)v3, *((_DWORD *)conn_info + 1), *((_DWORD *)conn_info + 10)) & 1) != 0 )
      {
        if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a1 + 1460)) )
          v23 = 1;
        else
          v23 = 2;
        *(_DWORD *)(a1 + 1996) = v23;
        hdd_update_acs_channel_list(a1 + 280);
      }
    }
    if ( *(_DWORD *)(v5 + 728) == 2
      && policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)v3, *(unsigned __int8 *)(*(_QWORD *)(v5 + 16) + 104LL)) )
    {
      v24 = *(const void **)(a1 + 1448);
      if ( v24 )
      {
        v25 = *(unsigned __int8 *)(a1 + 1456);
        v26 = *(void **)(a1 + 1432);
        v27 = *(_QWORD *)v3;
        v28 = *(unsigned __int8 *)(a1 + 1440);
        memset(v44, 0, 40);
        v43[0] = 0;
        qdf_mem_copy(v26, v24, (unsigned int)(4 * v25));
        *(_BYTE *)(a1 + 1440) = *(_BYTE *)(a1 + 1456);
        v29 = _qdf_mem_malloc(0x204u, "update_ll_lt_sap_channel_list", 2495);
        if ( v29 )
        {
          v30 = v29;
          if ( !(unsigned int)policy_mgr_get_pcl_ch_list_for_ll_sap(
                                v27,
                                v29,
                                *(unsigned __int8 *)(v5 + 12),
                                (__int64)v44,
                                v43) )
          {
            wlan_hdd_trim_acs_channel_list(v30, *(unsigned int *)(v30 + 512), *(_QWORD *)(a1 + 1432), a1 + 1440);
            if ( v28 != *(unsigned __int8 *)(a1 + 1440) )
              sap_dump_acs_channel(a1 + 1416);
          }
          _qdf_mem_free(v30);
        }
      }
    }
    if ( (unsigned int)wlan_hdd_config_acs(v3, v2) )
    {
      v39 = "%s: ACS config failed";
LABEL_25:
      qdf_trace_msg(0x33u, 2u, v39, v31, v32, v33, v34, v35, v36, v37, v38, "wlan_hdd_cfg80211_start_acs");
      result = 4294967274LL;
      goto LABEL_26;
    }
    link_mac_addr = (const void *)hdd_adapter_get_link_mac_addr(a1);
    if ( !link_mac_addr )
    {
      v39 = "%s: link_mac_addr is null";
      goto LABEL_25;
    }
    qdf_mem_copy((void *)(a1 + 712), link_mac_addr, 6u);
    *(_DWORD *)(a1 + 2344) = 1;
    v41 = wlansap_acs_chselect(v5, hdd_hostapd_sap_event_cb, a1 + 280);
    if ( (*(_BYTE *)(a1 + 2000) & 1) != 0 || v41 )
    {
      *(_DWORD *)(a1 + 2344) = 0;
      if ( v41 )
      {
        v39 = "%s: ACS channel select failed";
        goto LABEL_25;
      }
    }
    if ( (sap_is_auto_channel_select(v5) & 1) != 0 )
    {
      result = 0;
      *(_BYTE *)(a1 + 1416) = 1;
    }
    else
    {
      result = 0;
    }
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
