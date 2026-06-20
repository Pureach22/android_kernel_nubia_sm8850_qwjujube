__int64 __fastcall wlan_mlme_disable_fd_in_6ghz_band(
        __int64 a1,
        char a2,
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
  const char *v12; // x2

  if ( a1 )
  {
    result = wlan_objmgr_vdev_get_comp_private_obj(a1, 0);
    if ( result )
    {
      *(_BYTE *)(result + 233) = a2 & 1;
      return result;
    }
    v12 = "%s:  MLME component object is NULL";
  }
  else
  {
    v12 = "%s: vdev is NULL";
  }
  return qdf_trace_msg(0x68u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_mlme_get_cmpt_obj");
}
