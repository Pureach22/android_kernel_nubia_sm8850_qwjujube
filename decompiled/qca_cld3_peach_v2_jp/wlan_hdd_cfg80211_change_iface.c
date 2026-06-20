__int64 __fastcall wlan_hdd_cfg80211_change_iface(__int64 a1, __int64 a2, unsigned int a3)
{
  int v5; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 result; // x0
  int v15; // w24
  __int64 v16; // x22
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w0
  __int64 *v27; // x20
  unsigned int ap_random_bssid_enable; // w0
  const char *v29; // x23
  const char *v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w19
  unsigned int v49; // w0
  unsigned int v50; // w1
  int v51; // w0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  const char *v60; // x2
  int v61; // w21
  const char *v62; // x4
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  const char *v71; // x2
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  int *v88; // x8
  int v89; // w9
  int v90; // w10
  unsigned __int8 *v91; // x8
  __int64 v92; // x3
  __int64 v93; // x1
  __int64 v94; // x2
  __int64 v95; // [xsp+0h] [xbp-20h] BYREF
  _BYTE v96[4]; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v97; // [xsp+Ch] [xbp-14h] BYREF
  int v98; // [xsp+10h] [xbp-10h] BYREF
  __int16 v99; // [xsp+14h] [xbp-Ch]
  __int64 v100; // [xsp+18h] [xbp-8h]

  v100 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v95 = 0;
  v5 = _osif_vdev_sync_trans_start(a2, &v95, "_wlan_hdd_cfg80211_change_iface");
  if ( !v5 )
  {
    v15 = *(_DWORD *)(a2 + 176);
    v16 = *(_QWORD *)(a2 + 55512);
    v97 = 0;
    v98 = 0;
    v96[0] = 0;
    v99 = 0;
    v17 = qdf_trace_msg(0x33u, 8u, "%s: enter", v6, v7, v8, v9, v10, v11, v12, v13, "__wlan_hdd_cfg80211_change_iface");
    if ( (unsigned int)hdd_get_conparam(v17) == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "__wlan_hdd_cfg80211_change_iface");
      v26 = -22;
LABEL_18:
      v48 = v26;
      osif_vdev_sync_trans_stop(v95);
      result = v48;
      goto LABEL_19;
    }
    v27 = *(__int64 **)(a2 + 2712);
    v26 = _wlan_hdd_validate_context(v27, "__wlan_hdd_cfg80211_change_iface");
    if ( v26 )
      goto LABEL_18;
    wlan_hdd_lpc_handle_concurrency(v27, 0);
    if ( (policy_mgr_is_sta_mon_concurrency(*v27) & 1) != 0 && (hdd_lpc_is_work_scheduled(v27) & 1) == 0 )
    {
LABEL_17:
      v26 = -22;
      goto LABEL_18;
    }
    qdf_mtrace(51, 51, 0x29u, *(_BYTE *)(v16 + 8), a3);
    ap_random_bssid_enable = hdd_nl_to_qdf_iface_type(a3, &v97);
    if ( ap_random_bssid_enable )
    {
LABEL_11:
      v26 = qdf_status_to_os_return(ap_random_bssid_enable);
      goto LABEL_18;
    }
    if ( strnstr(a2 + 296, "p2p", 3) && !v97 )
      v97 = 7;
    v29 = qdf_opmode_str(*(_DWORD *)(a2 + 2728));
    v30 = qdf_opmode_str(v97);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Changing mode for '%s' from %s to %s",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "__wlan_hdd_cfg80211_change_iface",
      a2 + 296,
      v29,
      v30);
    v39 = hdd_trigger_psoc_idle_restart(v27);
    if ( v39 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to restart psoc; errno:%d",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "__wlan_hdd_cfg80211_change_iface",
        v39);
      goto LABEL_17;
    }
    ((void (__fastcall *)(__int64, _QWORD))policy_mgr_clear_concurrency_mode)(*v27, *(unsigned int *)(a2 + 2728));
    v49 = *(_DWORD *)(a2 + 2728);
    if ( v49 != 7 && v49 != 2 )
    {
      if ( v49 )
      {
        if ( ((v49 - 1) & 0xFFFFFFFD) != 0 )
        {
          v62 = qdf_opmode_str(v49);
          v71 = "%s: Changing from device mode '%s' is not supported";
LABEL_33:
          qdf_trace_msg(0x33u, 2u, v71, v63, v64, v65, v66, v67, v68, v69, v70, "__wlan_hdd_cfg80211_change_iface", v62);
          v61 = -95;
          goto LABEL_50;
        }
        v50 = v97;
        if ( v97 <= 7 && ((1 << v97) & 0x85) != 0 )
        {
          v51 = hdd_change_adapter_mode(a2 + 2688);
          if ( v51 )
          {
            v60 = "%s: change mode fail %d";
            goto LABEL_28;
          }
          goto LABEL_44;
        }
        if ( ((v97 - 1) & 0xFFFFFFFD) == 0 )
        {
          *(_DWORD *)(a2 + 2728) = v97;
          hdd_adapter_reset_ml_cap(v27, a2 + 2688);
          goto LABEL_49;
        }
LABEL_32:
        v62 = qdf_opmode_str(v50);
        v71 = "%s: Changing to device mode '%s' is not supported";
        goto LABEL_33;
      }
      hdd_cleanup_conn_info(v16);
    }
    v50 = v97;
    if ( v97 <= 7 && ((1 << v97) & 0x85) != 0 )
    {
      v51 = hdd_change_adapter_mode(a2 + 2688);
      if ( v51 )
      {
        v60 = "%s: change intf mode fail %d";
LABEL_28:
        v61 = v51;
        qdf_trace_msg(0x33u, 2u, v60, v52, v53, v54, v55, v56, v57, v58, v59, "__wlan_hdd_cfg80211_change_iface");
LABEL_50:
        ((void (__fastcall *)(__int64, _QWORD))policy_mgr_set_concurrency_mode)(*v27, *(unsigned int *)(a2 + 2728));
        qdf_trace_msg(0x33u, 8u, "%s: exit", v80, v81, v82, v83, v84, v85, v86, v87, "__wlan_hdd_cfg80211_change_iface");
        v26 = v61;
        goto LABEL_18;
      }
      goto LABEL_44;
    }
    if ( ((v97 - 1) & 0xFFFFFFFD) == 0 )
    {
      if ( v97 == 3 )
        wlan_hdd_cleanup_remain_on_channel_ctx(v16);
      hdd_stop_adapter(v27, a2 + 2688);
      hdd_deinit_adapter(v27, a2 + 2688, 1);
      memset((void *)(v16 + 80), 0, 0x8F8u);
      *(_DWORD *)(a2 + 2728) = v97;
      ap_random_bssid_enable = ucfg_mlme_get_ap_random_bssid_enable(*v27, v96);
      if ( ap_random_bssid_enable )
        goto LABEL_11;
      if ( *(_DWORD *)(a2 + 2728) == 1 && v96[0] == 1 )
      {
        v88 = *(int **)(a2 + 1008);
        v89 = *v88;
        v99 = *((_WORD *)v88 + 2);
        v98 = v89;
        get_random_bytes((char *)&v98 + 3, 3);
        LOWORD(v98) = 6658;
        BYTE2(v98) = 17;
        HIBYTE(v98) |= 0xF0u;
        v90 = v98;
        *(_WORD *)(a2 + 4309) = v99;
        *(_DWORD *)(a2 + 4305) = v90;
        dev_addr_mod(a2, 0, &v98, 6);
        v91 = *(unsigned __int8 **)(a2 + 1008);
        v92 = 0;
        v93 = 0;
        v94 = 0;
        if ( v91 )
        {
          v93 = *v91;
          v94 = v91[1];
          v92 = v91[2];
        }
        printk(&unk_97B0C2, v93, v94, v92);
      }
      hdd_set_ap_ops(*(_QWORD *)(a2 + 2720));
LABEL_44:
      hdd_adapter_reset_ml_cap(v27, a2 + 2688);
      if ( (v15 & 1) != 0 && (unsigned int)hdd_start_adapter(a2 + 2688, 1) )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to start adapter",
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          "__wlan_hdd_cfg80211_change_iface");
        v61 = -22;
        goto LABEL_50;
      }
LABEL_49:
      *(_DWORD *)(*(_QWORD *)(a2 + 992) + 8LL) = a3;
      hdd_lpass_notify_mode_change(v16);
      v61 = 0;
      goto LABEL_50;
    }
    goto LABEL_32;
  }
  if ( v5 == -11 )
    result = 4294967285LL;
  else
    result = 4294967280LL;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
