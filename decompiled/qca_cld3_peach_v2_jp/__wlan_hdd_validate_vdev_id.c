__int64 __fastcall _wlan_hdd_validate_vdev_id(
        unsigned __int8 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20

  if ( a1 == 255 )
  {
    v10 = jiffies;
    if ( _wlan_hdd_validate_vdev_id___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: adapter is not up (via %s)",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "__wlan_hdd_validate_vdev_id",
        a2);
      _wlan_hdd_validate_vdev_id___last_ticks = v10;
    }
    return 4294967274LL;
  }
  if ( a1 >= 6u )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: bad vdev Id:%u (via %s)",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "__wlan_hdd_validate_vdev_id");
    return 4294967274LL;
  }
  return 0;
}
