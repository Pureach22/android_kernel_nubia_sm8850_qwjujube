__int64 __fastcall wlan_vdev_mlme_set_ext_hdl(
        __int64 a1,
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
  __int64 result; // x0
  const char *v12; // x2
  const char *v13; // x3

  if ( a2 )
  {
    if ( a1 )
    {
      result = wlan_objmgr_vdev_get_comp_private_obj(a1, 0);
      if ( result )
      {
        *(_QWORD *)(result + 520) = a2;
        return result;
      }
      v12 = "%s:  MLME component object is NULL";
    }
    else
    {
      v12 = "%s: vdev is NULL";
    }
    v13 = "wlan_vdev_mlme_get_cmpt_obj";
  }
  else
  {
    v12 = "%s: Invalid input";
    v13 = "wlan_vdev_mlme_set_ext_hdl";
  }
  return qdf_trace_msg(0x68u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, v13);
}
