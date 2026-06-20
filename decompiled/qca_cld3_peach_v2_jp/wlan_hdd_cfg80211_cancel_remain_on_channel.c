__int64 __fastcall wlan_hdd_cfg80211_cancel_remain_on_channel(__int64 a1, __int64 a2, __int64 a3)
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
  const char *v24; // x2
  unsigned int v25; // w19
  unsigned __int8 sta_vdev_id; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 sta_vdev_for_p2p_dev; // x0
  __int64 v36; // x21
  double v37; // d0
  unsigned int v38; // w0
  unsigned int v39; // w19
  unsigned int *v40; // x8
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  _QWORD v56[2]; // [xsp+0h] [xbp-10h] BYREF

  v56[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a2 + 32);
  v56[0] = 0;
  result = _osif_vdev_sync_op_start(v5, v56, "wlan_hdd_cfg80211_cancel_remain_on_channel");
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
      "__wlan_hdd_cfg80211_cancel_remain_on_channel");
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      v24 = "%s: Command not allowed in FTM mode";
LABEL_4:
      qdf_trace_msg(
        0x33u,
        2u,
        v24,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "__wlan_hdd_cfg80211_cancel_remain_on_channel");
      v25 = -22;
LABEL_13:
      _osif_vdev_sync_op_stop(v56[0], "wlan_hdd_cfg80211_cancel_remain_on_channel");
      result = v25;
      goto LABEL_14;
    }
    if ( *(_DWORD *)(v15 + 2728) == 7
      && (ucfg_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(**(_QWORD **)(v15 + 2712)) & 1) != 0 )
    {
      sta_vdev_id = ucfg_p2p_psoc_priv_get_sta_vdev_id(**(_QWORD **)(v15 + 2712));
      sta_vdev_for_p2p_dev = wlan_hdd_get_sta_vdev_for_p2p_dev(
                               **(_QWORD **)(v15 + 2712),
                               sta_vdev_id,
                               0x53u,
                               v27,
                               v28,
                               v29,
                               v30,
                               v31,
                               v32,
                               v33,
                               v34);
      if ( !sta_vdev_for_p2p_dev )
      {
LABEL_8:
        v24 = "%s: vdev is NULL";
        goto LABEL_4;
      }
    }
    else
    {
      if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                           *(_BYTE *)(*(_QWORD *)(v15 + 55512) + 8LL),
                           (__int64)"__wlan_hdd_cfg80211_cancel_remain_on_channel",
                           v16,
                           v17,
                           v18,
                           v19,
                           v20,
                           v21,
                           v22,
                           v23) )
      {
        v25 = -22;
        goto LABEL_13;
      }
      sta_vdev_for_p2p_dev = _hdd_objmgr_get_vdev_by_user(
                               *(_QWORD *)(v15 + 55512),
                               0x53u,
                               (__int64)"__wlan_hdd_cfg80211_cancel_remain_on_channel");
      if ( !sta_vdev_for_p2p_dev )
        goto LABEL_8;
    }
    v36 = sta_vdev_for_p2p_dev;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Cancel RoC req: vdev:%d adapter_device_mode:%d vdev_device_mode:%d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "__wlan_hdd_cfg80211_cancel_remain_on_channel",
      *(unsigned __int8 *)(sta_vdev_for_p2p_dev + 104),
      *(unsigned int *)(v15 + 2728),
      *(unsigned int *)(sta_vdev_for_p2p_dev + 16));
    v37 = wlan_cfg80211_cancel_roc(v36, a3, *(unsigned int *)(v15 + 2728));
    v39 = v38;
    _hdd_objmgr_put_vdev_by_user(
      v36,
      0x53u,
      (__int64)"__wlan_hdd_cfg80211_cancel_remain_on_channel",
      v40,
      v37,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: cancel remain on channel, status:%d",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "__wlan_hdd_cfg80211_cancel_remain_on_channel",
      v39);
    v25 = 0;
    goto LABEL_13;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
