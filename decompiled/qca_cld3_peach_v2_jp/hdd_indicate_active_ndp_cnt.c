double __fastcall hdd_indicate_active_ndp_cnt(
        __int64 a1,
        unsigned __int8 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  __int64 link_info_by_vdev; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  double result; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x5

  context = _cds_get_context(51, (__int64)"wlan_hdd_get_link_info_from_vdev", a4, a5, a6, a7, a8, a9, a10, a11);
  link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)context, a2);
  if ( link_info_by_vdev )
  {
    v24 = link_info_by_vdev;
    if ( (cfg_nan_is_roam_config_disabled(a1) & 1) != 0 )
    {
      if ( a3 )
        v33 = (const char *)&unk_8B9E43;
      else
        v33 = " no more";
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: vdev_id:%d%s active ndp sessions present",
        result,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "hdd_indicate_active_ndp_cnt",
        a2,
        v33);
      return wlan_hdd_set_roaming_state(v24, 16, a3 == 0);
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: vdev %d Get adapter by vdev id failed",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wlan_hdd_get_link_info_from_vdev",
      a2);
  }
  return result;
}
