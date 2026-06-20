__int64 __fastcall wlan_mlme_is_fd_disabled_in_6ghz_band(
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
  __int64 comp_private_obj; // x0
  char v10; // w8
  const char *v11; // x2

  if ( !a1 )
  {
    v11 = "%s: vdev is NULL";
LABEL_6:
    qdf_trace_msg(0x68u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_vdev_mlme_get_cmpt_obj");
    v10 = 0;
    return v10 & 1;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0);
  if ( !comp_private_obj )
  {
    v11 = "%s:  MLME component object is NULL";
    goto LABEL_6;
  }
  v10 = *(_BYTE *)(comp_private_obj + 217);
  return v10 & 1;
}
