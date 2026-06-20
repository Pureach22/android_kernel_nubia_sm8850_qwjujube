__int64 __fastcall wlan_hdd_cfg80211_remain_on_channel(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, _QWORD *a5)
{
  __int64 v9; // x0
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x25
  __int64 *v20; // x22
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  const char *v38; // x2
  __int64 v39; // x23
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned __int8 sta_vdev_id; // w0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 sta_vdev_for_p2p_dev; // x23
  unsigned int v58; // w24
  unsigned int v59; // w19
  unsigned int *v60; // x8
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  unsigned int v78; // w0
  unsigned int v79; // w20
  unsigned int *v80; // x8
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  _QWORD v96[2]; // [xsp+0h] [xbp-10h] BYREF

  v96[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a2 + 32);
  v96[0] = 0;
  result = _osif_vdev_sync_op_start(v9, v96, "wlan_hdd_cfg80211_remain_on_channel");
  if ( !(_DWORD)result )
  {
    v19 = *(_QWORD *)(a2 + 32);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "__wlan_hdd_cfg80211_remain_on_channel");
    v20 = *(__int64 **)(v19 + 2712);
    v29 = _wlan_hdd_validate_context(
            (__int64)v20,
            (__int64)"__wlan_hdd_cfg80211_remain_on_channel",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28);
    if ( v29 )
    {
LABEL_13:
      v59 = v29;
      _osif_vdev_sync_op_stop(v96[0], "wlan_hdd_cfg80211_remain_on_channel");
      result = v59;
      goto LABEL_14;
    }
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      v38 = "%s: Command not allowed in FTM mode";
LABEL_5:
      qdf_trace_msg(0x33u, 2u, v38, v30, v31, v32, v33, v34, v35, v36, v37, "__wlan_hdd_cfg80211_remain_on_channel");
      v29 = -22;
      goto LABEL_13;
    }
    v39 = *v20;
    wlan_hdd_lpc_handle_concurrency();
    if ( (policy_mgr_is_sta_mon_concurrency(v39) & 1) == 0 || (hdd_lpc_is_work_scheduled((__int64)v20) & 1) != 0 )
    {
      if ( *(_DWORD *)(v19 + 2728) == 7 && (ucfg_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(v39) & 1) != 0 )
      {
        sta_vdev_id = ucfg_p2p_psoc_priv_get_sta_vdev_id(v39);
        sta_vdev_for_p2p_dev = wlan_hdd_get_sta_vdev_for_p2p_dev(
                                 v39,
                                 sta_vdev_id,
                                 0x53u,
                                 v49,
                                 v50,
                                 v51,
                                 v52,
                                 v53,
                                 v54,
                                 v55,
                                 v56);
        v58 = 7;
LABEL_16:
        if ( sta_vdev_for_p2p_dev )
        {
          if ( (wlan_is_scan_allowed(sta_vdev_for_p2p_dev) & 1) != 0 )
          {
            if ( (ucfg_nan_is_sta_p2p_ndp_supported(*v20) & 1) == 0 )
              ucfg_nan_disable_concurrency(*v20);
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: ROC req: vdev %d adapter device mode %d vdev device mode %d opmode %d",
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              "__wlan_hdd_cfg80211_remain_on_channel",
              *(unsigned __int8 *)(sta_vdev_for_p2p_dev + 168),
              *(unsigned int *)(v19 + 2728),
              *(unsigned int *)(sta_vdev_for_p2p_dev + 16),
              v58);
            v77 = wlan_cfg80211_roc(sta_vdev_for_p2p_dev, a3, a4, a5, v58);
            v79 = v78;
            _hdd_objmgr_put_vdev_by_user(
              sta_vdev_for_p2p_dev,
              0x53u,
              (__int64)"__wlan_hdd_cfg80211_remain_on_channel",
              v80,
              v77,
              v81,
              v82,
              v83,
              v84,
              v85,
              v86,
              v87);
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: remain on channel request, status:%d, cookie:0x%llx",
              v88,
              v89,
              v90,
              v91,
              v92,
              v93,
              v94,
              v95,
              "__wlan_hdd_cfg80211_remain_on_channel",
              v79,
              *a5);
            v29 = qdf_status_to_os_return(v79);
          }
          else
          {
            wlan_objmgr_vdev_release_ref(sta_vdev_for_p2p_dev, 0x53u, v60, v61, v62, v63, v64, v65, v66, v67, v68);
            v29 = -16;
          }
          goto LABEL_13;
        }
        v38 = "%s: vdev is NULL";
        goto LABEL_5;
      }
      if ( !(unsigned int)_wlan_hdd_validate_vdev_id(
                            *(_BYTE *)(*(_QWORD *)(v19 + 55520) + 8LL),
                            (__int64)"__wlan_hdd_cfg80211_remain_on_channel",
                            v40,
                            v41,
                            v42,
                            v43,
                            v44,
                            v45,
                            v46,
                            v47) )
      {
        sta_vdev_for_p2p_dev = _hdd_objmgr_get_vdev_by_user(
                                 *(_QWORD *)(v19 + 55520),
                                 0x53u,
                                 (__int64)"__wlan_hdd_cfg80211_remain_on_channel");
        v58 = 0;
        goto LABEL_16;
      }
    }
    v29 = -22;
    goto LABEL_13;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
