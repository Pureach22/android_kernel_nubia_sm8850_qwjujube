__int64 __fastcall wlan_hdd_get_sta_vdev_for_p2p_dev(
        __int64 a1,
        unsigned __int8 a2,
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
  const char *v22; // x2
  __int64 v23; // x4
  __int64 result; // x0
  __int64 link_info_from_vdev; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int *v34; // x8

  if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                       a2,
                       (__int64)"wlan_hdd_get_sta_vdev_for_p2p_dev",
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       a11) )
  {
    v22 = "%s: Invalid vdev %d";
LABEL_3:
    v23 = a2;
LABEL_4:
    qdf_trace_msg(0x33u, 2u, v22, v14, v15, v16, v17, v18, v19, v20, v21, "wlan_hdd_get_sta_vdev_for_p2p_dev", v23);
    return 0;
  }
  link_info_from_vdev = wlan_hdd_get_link_info_from_vdev(v14, v15, v16, v17, v18, v19, v20, v21, a1, a2);
  if ( !link_info_from_vdev )
  {
    v22 = "%s: vdev %d invalid link info";
    goto LABEL_3;
  }
  result = _hdd_objmgr_get_vdev_by_user(link_info_from_vdev, a3, (__int64)"wlan_hdd_get_sta_vdev_for_p2p_dev");
  if ( !result )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: vdev is NULL",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wlan_hdd_get_sta_vdev_for_p2p_dev");
    return 0;
  }
  v34 = (unsigned int *)*(unsigned int *)(result + 16);
  if ( (_DWORD)v34 )
  {
    _hdd_objmgr_put_vdev_by_user(
      result,
      a3,
      (__int64)"wlan_hdd_get_sta_vdev_for_p2p_dev",
      v34,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33);
    v22 = "%s: vdev %d not a sta vdev";
    v23 = a2;
    goto LABEL_4;
  }
  return result;
}
