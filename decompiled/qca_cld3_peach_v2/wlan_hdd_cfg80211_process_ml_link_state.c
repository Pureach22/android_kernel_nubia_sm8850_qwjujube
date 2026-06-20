__int64 __fastcall wlan_hdd_cfg80211_process_ml_link_state(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x24
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w19
  __int64 v28; // x23
  __int64 vdev_by_user; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x22
  unsigned int *v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 *v48[2]; // [xsp+0h] [xbp-10h] BYREF

  v48[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v48[0] = nullptr;
  result = _osif_vdev_sync_op_start(v8, v48, (__int64)"wlan_hdd_cfg80211_process_ml_link_state");
  if ( !(_DWORD)result )
  {
    v18 = *(_QWORD *)(a2 + 32);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "__wlan_hdd_cfg80211_process_ml_link_state",
      v18 + 296);
    if ( (unsigned int)_hdd_validate_adapter(
                         v18 + 2688,
                         (__int64)"__wlan_hdd_cfg80211_process_ml_link_state",
                         v19,
                         v20,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25,
                         v26)
      || (v28 = *(_QWORD *)(v18 + 2712)) == 0
      || *(_DWORD *)(v18 + 2728)
      || (vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                           *(_QWORD *)(v18 + 55520),
                           6u,
                           (__int64)"__wlan_hdd_cfg80211_process_ml_link_state")) == 0 )
    {
      v27 = -22;
    }
    else
    {
      v38 = vdev_by_user;
      if ( (wlan_vdev_mlme_is_mlo_vdev(vdev_by_user, v30, v31, v32, v33, v34, v35, v36, v37) & 1) != 0 )
        v27 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64, _QWORD))wlan_handle_mlo_link_state_operation)(
                v18 + 2688,
                a1,
                v38,
                v28,
                a3,
                a4);
      else
        v27 = 0;
      _hdd_objmgr_put_vdev_by_user(
        v38,
        6u,
        (__int64)"__wlan_hdd_cfg80211_process_ml_link_state",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47);
    }
    _osif_vdev_sync_op_stop((__int64)v48[0], (__int64)"wlan_hdd_cfg80211_process_ml_link_state");
    result = v27;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
