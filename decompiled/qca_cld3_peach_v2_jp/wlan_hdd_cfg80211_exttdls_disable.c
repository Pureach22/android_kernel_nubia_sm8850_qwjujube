__int64 __fastcall wlan_hdd_cfg80211_exttdls_disable(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w19
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 vdev_by_user; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x19
  char tdls_chan_switch_prohibited; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int *v59; // x8
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 *v68[2]; // [xsp+0h] [xbp-10h] BYREF

  v68[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 32);
  v68[0] = nullptr;
  result = _osif_vdev_sync_op_start(v4, v68, (__int64)"wlan_hdd_cfg80211_exttdls_disable");
  if ( !(_DWORD)result )
  {
    if ( !a1 )
    {
      __break(0x800u);
      JUMPOUT(0x5C9960);
    }
    v14 = *(_QWORD *)(a2 + 32);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "__wlan_hdd_cfg80211_exttdls_disable",
      v14 + 296);
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "__wlan_hdd_cfg80211_exttdls_disable");
      v23 = -1;
LABEL_14:
      _osif_vdev_sync_op_stop((__int64)v68[0], (__int64)"wlan_hdd_cfg80211_exttdls_disable");
      result = v23;
      goto LABEL_15;
    }
    if ( (unsigned int)_wlan_hdd_validate_context(
                         a1 + 1536,
                         (__int64)"__wlan_hdd_cfg80211_exttdls_disable",
                         v15,
                         v16,
                         v17,
                         v18,
                         v19,
                         v20,
                         v21,
                         v22) )
    {
LABEL_6:
      v23 = -22;
      goto LABEL_14;
    }
    if ( (*(_DWORD *)(v14 + 2728) | 2) != 2 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Failed to get TDLS info due to opmode:%d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "__wlan_hdd_cfg80211_exttdls_disable");
      v23 = -95;
      goto LABEL_14;
    }
    if ( v14 != -2688 && (*(_QWORD *)(v14 + 4328) & 1) != 0 )
    {
      vdev_by_user = _hdd_objmgr_get_vdev_by_user(v14 + 55520, 0x11u, (__int64)"wlan_hdd_tdls_disable");
      if ( !vdev_by_user )
        goto LABEL_6;
      v41 = vdev_by_user;
      tdls_chan_switch_prohibited = mlme_get_tdls_chan_switch_prohibited(
                                      vdev_by_user,
                                      v33,
                                      v34,
                                      v35,
                                      v36,
                                      v37,
                                      v38,
                                      v39,
                                      v40);
      wlan_tdls_notify_sta_disconnect(
        *(_BYTE *)(v41 + 104),
        tdls_chan_switch_prohibited & 1,
        1,
        v41,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50);
      ucfg_tdls_set_user_tdls_enable(v41, 0, v51, v52, v53, v54, v55, v56, v57, v58);
      _hdd_objmgr_put_vdev_by_user(
        v41,
        0x11u,
        (__int64)"wlan_hdd_tdls_disable",
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67);
    }
    v23 = 0;
    goto LABEL_14;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
