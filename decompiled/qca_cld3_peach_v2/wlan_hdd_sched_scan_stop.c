__int64 __fastcall wlan_hdd_sched_scan_stop(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  const char *v10; // x2
  unsigned int v11; // w1
  __int64 *v13; // x8
  __int64 vdev_by_user; // x0
  __int64 v15; // x19
  unsigned int v16; // w20
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  if ( (unsigned int)hdd_get_conparam() == 5 )
  {
    v10 = "%s: Command not allowed in FTM mode";
LABEL_3:
    v11 = 2;
LABEL_4:
    qdf_trace_msg(0x33u, v11, v10, v2, v3, v4, v5, v6, v7, v8, v9, "wlan_hdd_sched_scan_stop");
    return 4294967274LL;
  }
  if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                       *(_BYTE *)(*(_QWORD *)(a1 + 55520) + 8LL),
                       (__int64)"wlan_hdd_sched_scan_stop",
                       v2,
                       v3,
                       v4,
                       v5,
                       v6,
                       v7,
                       v8,
                       v9) )
    return 4294967274LL;
  v13 = *(__int64 **)(a1 + 2712);
  if ( !v13 )
  {
    v10 = "%s: HDD context is Null";
    goto LABEL_3;
  }
  if ( (ucfg_scan_is_pno_offload_enabled(*v13) & 1) == 0 )
  {
    v10 = "%s: PnoOffload is not enabled!!!";
    v11 = 8;
    goto LABEL_4;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 55520), 0x4Fu, (__int64)"wlan_hdd_sched_scan_stop");
  if ( vdev_by_user )
  {
    v15 = vdev_by_user;
    v16 = wlan_cfg80211_sched_scan_stop();
    _hdd_objmgr_put_vdev_by_user(
      v15,
      0x4Fu,
      (__int64)"wlan_hdd_sched_scan_stop",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25);
    return v16;
  }
  return 4294967274LL;
}
