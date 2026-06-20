__int64 __fastcall wlan_hdd_get_tx_power(__int64 a1, unsigned int *a2)
{
  __int64 vdev_by_user; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x21
  double tx_power; // d0
  unsigned int v14; // w0
  unsigned int v15; // w20
  unsigned int *v16; // x8
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52832), 0x56u, (__int64)"wlan_hdd_get_tx_power");
  if ( vdev_by_user )
  {
    v12 = vdev_by_user;
    tx_power = wlan_cfg80211_mc_cp_stats_get_tx_power(vdev_by_user, a2);
    v15 = v14;
    _hdd_objmgr_put_vdev_by_user(
      v12,
      0x56u,
      (__int64)"wlan_hdd_get_tx_power",
      v16,
      tx_power,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23);
    qdf_trace_msg(0x33u, 8u, "%s: power: %d", v24, v25, v26, v27, v28, v29, v30, v31, "wlan_hdd_get_tx_power", *a2);
  }
  else
  {
    qdf_trace_msg(0x33u, 4u, "%s: vdev is NULL", v4, v5, v6, v7, v8, v9, v10, v11, "wlan_hdd_get_tx_power");
    return (unsigned int)-22;
  }
  return v15;
}
