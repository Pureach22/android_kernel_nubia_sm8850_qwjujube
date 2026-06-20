__int64 __fastcall wlan_hdd_get_mib_stats(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 vdev_by_user; // x0
  __int64 v11; // x21
  __int64 mib_stats; // x20
  unsigned int *v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  unsigned int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: Invalid context, adapter", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_get_mib_stats");
    goto LABEL_8;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52832), 0x51u, (__int64)"wlan_hdd_get_mib_stats");
  if ( !vdev_by_user )
  {
LABEL_8:
    result = 5;
    goto LABEL_9;
  }
  v11 = vdev_by_user;
  mib_stats = wlan_cfg80211_mc_cp_stats_get_mib_stats(vdev_by_user, &v23);
  _hdd_objmgr_put_vdev_by_user(
    v11,
    0x51u,
    (__int64)"wlan_hdd_get_mib_stats",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21);
  if ( !v23 && mib_stats )
    hdd_debugfs_process_mib_stats(a1, mib_stats);
  wlan_cfg80211_mc_cp_stats_free_stats_event(mib_stats);
  result = v23;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
