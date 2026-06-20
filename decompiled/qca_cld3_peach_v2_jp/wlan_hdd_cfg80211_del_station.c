__int64 __fastcall wlan_hdd_cfg80211_del_station(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 v4; // x20
  int v5; // w21
  int v6; // w22
  __int64 result; // x0
  __int64 v8; // x0
  unsigned int v9; // w20
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  const char *v18; // x2
  unsigned int v19; // w19
  __int64 *v20; // x22
  __int64 sta_info_by_mac; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x5
  __int64 v32; // x6
  const char *v33; // x2
  __int64 vdev_by_user; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w20
  unsigned __int8 *v44; // x21
  __int64 v45; // x0
  __int64 v46; // x22
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // [xsp+8h] [xbp-28h] BYREF
  __int64 v56; // [xsp+10h] [xbp-20h] BYREF
  __int64 v57; // [xsp+18h] [xbp-18h] BYREF
  __int64 v58; // [xsp+20h] [xbp-10h]
  __int64 v59; // [xsp+28h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
  {
    v4 = *a3;
    v5 = *((unsigned __int16 *)a3 + 5);
    v6 = *((unsigned __int8 *)a3 + 8);
    v57 = 0;
    v58 = 0;
    v55 = 0;
    result = _osif_vdev_sync_op_start(a2, &v55, "_wlan_hdd_cfg80211_del_station");
    if ( !(_DWORD)result )
    {
      v8 = wlansap_populate_del_sta_params(v4, v5, v6, (int)&v57);
      v9 = *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL);
      if ( (unsigned int)hdd_get_conparam(v8) == 5 )
      {
        v18 = "%s: Command not allowed in FTM mode";
LABEL_5:
        qdf_trace_msg(0x33u, 2u, v18, v10, v11, v12, v13, v14, v15, v16, v17, "__wlan_hdd_cfg80211_del_station");
LABEL_8:
        v19 = -22;
LABEL_9:
        _osif_vdev_sync_op_stop(v55, "_wlan_hdd_cfg80211_del_station");
        result = v19;
        goto LABEL_10;
      }
      if ( (unsigned int)_wlan_hdd_validate_vdev_id(v9, "__wlan_hdd_cfg80211_del_station") )
        goto LABEL_8;
      qdf_mtrace(51, 51, 0x34u, v9, *(_DWORD *)(a2 + 2728));
      v20 = *(__int64 **)(a2 + 2712);
      if ( !v20 )
      {
        v18 = "%s: hdd_ctx is NULL";
        goto LABEL_5;
      }
      if ( (*(_DWORD *)(a2 + 2728) | 2) == 3 )
      {
        if ( (_DWORD)v57 == -1 && SWORD2(v57) == -1 )
        {
          vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a2 + 55512), 6, "__wlan_hdd_cfg80211_del_station");
          if ( vdev_by_user )
          {
            v43 = *(unsigned __int16 *)(vdev_by_user + 160);
            _hdd_objmgr_put_vdev_by_user(vdev_by_user, 6, "__wlan_hdd_cfg80211_del_station");
            if ( v43 >= 2 && policy_mgr_is_vdev_ll_lt_sap(*v20, *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL)) )
              v35 = wlan_ll_sap_switch_bearer_on_stop_ap(*v20, *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL));
          }
          hdd_softap_deauth_all_sta((_QWORD *)(a2 + 2688), &v57, v35, v36, v37, v38, v39, v40, v41, v42);
        }
        else
        {
          sta_info_by_mac = hdd_get_sta_info_by_mac(a2 + 41536, &v57, 14, 3);
          v56 = sta_info_by_mac;
          if ( !sta_info_by_mac )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Vdev %d Skip DEL STA as sta not found for %02x:%02x:%02x:**:**:%02x",
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              "__wlan_hdd_cfg80211_del_station",
              v9,
              (unsigned __int8)v57,
              BYTE1(v57),
              BYTE2(v57),
              BYTE5(v57));
            v19 = -2;
            goto LABEL_9;
          }
          if ( *(_BYTE *)(sta_info_by_mac + 49) == 1 )
          {
            v31 = (unsigned __int8)v57;
            v32 = BYTE1(v57);
            v33 = "%s: vdev %d Skip DEL STA as deauth is in progress for STA %02x:%02x:%02x:**:**:%02x";
LABEL_34:
            qdf_trace_msg(
              0x33u,
              8u,
              v33,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              "__wlan_hdd_cfg80211_del_station",
              v9,
              v31,
              v32,
              BYTE2(v57),
              BYTE5(v57));
            hdd_put_sta_info_ref(a2 + 41536, &v56, 1, 14);
            v19 = -2;
            goto LABEL_9;
          }
          v44 = *(unsigned __int8 **)(sta_info_by_mac + 16);
          if ( !v44 )
          {
            v31 = (unsigned __int8)v57;
            v32 = BYTE1(v57);
            v33 = "%s: Vdev %d invalid link info%02x:%02x:%02x:**:**:%02x";
            goto LABEL_34;
          }
          if ( WORD2(v58) == 23 )
          {
            v45 = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(sta_info_by_mac + 16), 97, "__wlan_hdd_cfg80211_del_station");
            if ( v45 )
            {
              v46 = v45;
              ucfg_dp_softap_check_wait_for_tx_eap_pkt(
                v45,
                (unsigned __int8 *)&v57,
                v23,
                v24,
                v25,
                v26,
                v27,
                v28,
                v29,
                v30);
              _hdd_objmgr_put_vdev_by_user(v46, 97, "__wlan_hdd_cfg80211_del_station");
            }
          }
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: vdev %d, Delete STA %02x:%02x:%02x:**:**:%02x",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "__wlan_hdd_cfg80211_del_station",
            v9,
            (unsigned __int8)v57,
            BYTE1(v57),
            BYTE2(v57),
            BYTE5(v57));
          hdd_softap_deauth_current_sta(v44, v56, (__int64)&v57, v47, v48, v49, v50, v51, v52, v53, v54);
          hdd_put_sta_info_ref(a2 + 41536, &v56, 1, 14);
        }
      }
      v19 = 0;
      goto LABEL_9;
    }
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
