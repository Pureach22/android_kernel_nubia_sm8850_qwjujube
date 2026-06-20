__int64 __fastcall policy_mgr_get_connected_vdev_band_mask(
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
  unsigned __int16 *active_channel; // x0
  const char *v11; // x2

  if ( a1 )
  {
    active_channel = (unsigned __int16 *)wlan_vdev_get_active_channel(a1);
    if ( active_channel )
      return 1LL << wlan_reg_freq_to_band(*active_channel);
    v11 = "%s: no active channel";
  }
  else
  {
    v11 = "%s: vdev is NULL";
  }
  qdf_trace_msg(0x4Fu, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "policy_mgr_get_connected_vdev_band_mask");
  return 0;
}
