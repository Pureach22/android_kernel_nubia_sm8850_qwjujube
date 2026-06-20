__int64 __fastcall wlan_hdd_cfg80211_mgmt_tx_cancel_wait(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x0
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19
  unsigned __int8 sta_vdev_id; // w20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 sta_vdev_for_p2p_dev; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x7
  __int64 v44; // x21
  double v45; // d0
  unsigned int v46; // w0
  unsigned int v47; // w19
  unsigned int *v48; // x8
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  _QWORD v64[2]; // [xsp+0h] [xbp-10h] BYREF

  v64[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a2 + 32);
  v64[0] = 0;
  result = _osif_vdev_sync_op_start(v5, v64, "wlan_hdd_cfg80211_mgmt_tx_cancel_wait");
  if ( !(_DWORD)result )
  {
    v15 = *(_QWORD *)(a2 + 32);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "__wlan_hdd_cfg80211_mgmt_tx_cancel_wait");
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "__wlan_hdd_cfg80211_mgmt_tx_cancel_wait");
      v24 = -22;
LABEL_12:
      _osif_vdev_sync_op_stop(v64[0], "wlan_hdd_cfg80211_mgmt_tx_cancel_wait");
      result = v24;
      goto LABEL_13;
    }
    if ( *(_DWORD *)(v15 + 2728) == 7
      && (ucfg_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(**(_QWORD **)(v15 + 2712)) & 1) != 0 )
    {
      sta_vdev_id = ucfg_p2p_psoc_priv_get_sta_vdev_id(**(_QWORD **)(v15 + 2712));
      sta_vdev_for_p2p_dev = wlan_hdd_get_sta_vdev_for_p2p_dev(
                               **(_QWORD **)(v15 + 2712),
                               sta_vdev_id,
                               0x53u,
                               v26,
                               v27,
                               v28,
                               v29,
                               v30,
                               v31,
                               v32,
                               v33);
      v43 = 7;
      if ( !sta_vdev_for_p2p_dev )
      {
LABEL_7:
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: vdev %d is NULL",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "__wlan_hdd_cfg80211_mgmt_tx_cancel_wait",
          sta_vdev_id);
        v24 = -22;
        goto LABEL_12;
      }
    }
    else
    {
      sta_vdev_id = *(_BYTE *)(*(_QWORD *)(v15 + 55512) + 8LL);
      if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                           sta_vdev_id,
                           (__int64)"__wlan_hdd_cfg80211_mgmt_tx_cancel_wait",
                           v16,
                           v17,
                           v18,
                           v19,
                           v20,
                           v21,
                           v22,
                           v23) )
      {
        v24 = -22;
        goto LABEL_12;
      }
      sta_vdev_for_p2p_dev = _hdd_objmgr_get_vdev_by_user(
                               *(_QWORD *)(v15 + 55512),
                               0x53u,
                               (__int64)"__wlan_hdd_cfg80211_mgmt_tx_cancel_wait");
      v43 = 0;
      if ( !sta_vdev_for_p2p_dev )
        goto LABEL_7;
    }
    v44 = sta_vdev_for_p2p_dev;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: cancel mgmt tx, vdev:%d adapter_device_mode:%d vdev_device_mode:%d opmode:%d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "__wlan_hdd_cfg80211_mgmt_tx_cancel_wait",
      *(unsigned __int8 *)(sta_vdev_for_p2p_dev + 104),
      *(unsigned int *)(v15 + 2728),
      *(unsigned int *)(sta_vdev_for_p2p_dev + 16),
      v43);
    v45 = wlan_cfg80211_mgmt_tx_cancel(v44, a3, *(unsigned int *)(v15 + 2728));
    v47 = v46;
    _hdd_objmgr_put_vdev_by_user(
      v44,
      0x53u,
      (__int64)"__wlan_hdd_cfg80211_mgmt_tx_cancel_wait",
      v48,
      v45,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: cancel mgmt tx, status:%d",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      "__wlan_hdd_cfg80211_mgmt_tx_cancel_wait",
      v47);
    v24 = 0;
    goto LABEL_12;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
