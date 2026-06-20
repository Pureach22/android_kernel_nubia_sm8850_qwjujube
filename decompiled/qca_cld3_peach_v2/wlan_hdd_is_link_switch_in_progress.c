__int64 __fastcall wlan_hdd_is_link_switch_in_progress(
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  char is_mlo_vdev; // w21
  __int64 v21; // x0
  __int64 v22; // x20
  char is_link_switch_in_progress; // w19
  __int64 v24; // x21
  const char *v25; // x3

  if ( !a1 )
  {
    v24 = jiffies;
    if ( wlan_hdd_is_link_switch_in_progress___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid link info",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "wlan_hdd_is_link_switch_in_progress");
      is_link_switch_in_progress = 0;
      wlan_hdd_is_link_switch_in_progress___last_ticks = v24;
      return is_link_switch_in_progress & 1;
    }
    goto LABEL_11;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 81, "wlan_hdd_is_mlo_connection");
  if ( !vdev_by_user )
  {
    v25 = "wlan_hdd_is_mlo_connection";
LABEL_10:
    qdf_trace_msg(0x33u, 2u, "%s: invalid vdev", v11, v12, v13, v14, v15, v16, v17, v18, v25);
    goto LABEL_11;
  }
  v19 = vdev_by_user;
  is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(vdev_by_user, v11, v12, v13, v14, v15, v16, v17, v18);
  _hdd_objmgr_put_vdev_by_user(v19, 81, "wlan_hdd_is_mlo_connection");
  if ( (is_mlo_vdev & 1) == 0 )
  {
LABEL_11:
    is_link_switch_in_progress = 0;
    return is_link_switch_in_progress & 1;
  }
  v21 = _hdd_objmgr_get_vdev_by_user(a1, 81, "wlan_hdd_is_link_switch_in_progress");
  if ( !v21 )
  {
    v25 = "wlan_hdd_is_link_switch_in_progress";
    goto LABEL_10;
  }
  v22 = v21;
  is_link_switch_in_progress = mlo_mgr_is_link_switch_in_progress(v21);
  _hdd_objmgr_put_vdev_by_user(v22, 81, "wlan_hdd_is_link_switch_in_progress");
  return is_link_switch_in_progress & 1;
}
