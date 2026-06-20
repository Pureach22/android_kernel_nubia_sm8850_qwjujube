__int64 __fastcall wma_get_vdev_bssid(
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
  __int64 cmpt_obj; // x0
  const char *v11; // x2

  if ( a1 )
  {
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
    if ( cmpt_obj )
      return cmpt_obj + 168;
    v11 = "%s: Failed to get mlme_obj";
  }
  else
  {
    v11 = "%s: vdev is NULL";
  }
  qdf_trace_msg(0x36u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "wma_get_vdev_bssid");
  return 0;
}
