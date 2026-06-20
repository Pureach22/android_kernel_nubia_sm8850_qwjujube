void __fastcall wlan_hdd_tdls_get_all_peers(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 vdev_by_user; // x0
  __int64 v23; // x21
  __int64 tdls_link_vdev; // x0
  __int64 v25; // x22
  double all_peers; // d0
  unsigned int *v27; // x8
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int *v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7

  qdf_trace_msg(0x33u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "wlan_hdd_tdls_get_all_peers");
  if ( (unsigned int)_wlan_hdd_validate_context(
                       *(_QWORD *)(a1 + 24),
                       (__int64)"wlan_hdd_tdls_get_all_peers",
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       v19,
                       v20,
                       v21) )
  {
    scnprintf(a2, (int)a3, "\nHDD context is not valid\n");
  }
  else if ( (*(_DWORD *)(a1 + 40) | 2) == 2 )
  {
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52832), 0x57u, (__int64)"wlan_hdd_tdls_get_all_peers");
    if ( vdev_by_user )
    {
      v23 = vdev_by_user;
      tdls_link_vdev = ucfg_tdls_get_tdls_link_vdev(vdev_by_user, 0x57u);
      if ( tdls_link_vdev )
      {
        v25 = tdls_link_vdev;
        all_peers = wlan_cfg80211_tdls_get_all_peers(tdls_link_vdev, a2, a3);
        ucfg_tdls_put_tdls_link_vdev(v25, 0x57u, v27, all_peers, v28, v29, v30, v31, v32, v33, v34);
      }
      else
      {
        wlan_cfg80211_tdls_get_all_peers(v23, a2, a3);
      }
      _hdd_objmgr_put_vdev_by_user(
        v23,
        0x57u,
        (__int64)"wlan_hdd_tdls_get_all_peers",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43);
    }
    else
    {
      scnprintf(a2, (int)a3, "\nVDEV is NULL\n");
    }
  }
  else
  {
    scnprintf(a2, (int)a3, "\nNo TDLS support for this adapter\n");
  }
}
