__int64 __fastcall hdd_lost_link_info_cb(
        __int64 a1,
        int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 link_info_by_vdev; // x0
  __int64 v22; // x20
  const char *v23; // x2
  __int64 v24; // x20

  result = _wlan_hdd_validate_context(a1, (__int64)"hdd_lost_link_info_cb", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !(_DWORD)result )
  {
    if ( !a2 )
    {
      v23 = "%s: lost_link_info is NULL";
      return qdf_trace_msg(0x33u, 2u, v23, v13, v14, v15, v16, v17, v18, v19, v20, "hdd_lost_link_info_cb");
    }
    if ( a2[1] )
    {
      link_info_by_vdev = hdd_get_link_info_by_vdev(a1, *a2);
      if ( link_info_by_vdev )
      {
        v22 = link_info_by_vdev;
        *(_DWORD *)(link_info_by_vdev + 2420) = a2[1];
        result = qdf_trace_msg(
                   0x33u,
                   8u,
                   "%s: rssi on disconnect %d",
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   "hdd_lost_link_info_cb");
        *(_BYTE *)(v22 + 1512) = a2[1];
        return result;
      }
      v23 = "%s: invalid vdev";
      return qdf_trace_msg(0x33u, 2u, v23, v13, v14, v15, v16, v17, v18, v19, v20, "hdd_lost_link_info_cb");
    }
    v24 = jiffies;
    if ( hdd_lost_link_info_cb___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: Invalid rssi on disconnect sent by FW",
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 "hdd_lost_link_info_cb");
      hdd_lost_link_info_cb___last_ticks = v24;
    }
  }
  return result;
}
