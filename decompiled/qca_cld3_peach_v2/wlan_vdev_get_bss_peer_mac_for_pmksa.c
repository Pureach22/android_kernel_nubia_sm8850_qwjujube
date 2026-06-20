__int64 __fastcall wlan_vdev_get_bss_peer_mac_for_pmksa(
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
  int v12; // w21

  if ( a1 )
  {
    qdf_mutex_acquire(a1 + 96);
    v12 = *(_DWORD *)(a1 + 60);
    qdf_mutex_release(a1 + 96);
    if ( (v12 & 1) != 0 )
      return wlan_vdev_get_bss_peer_mld_mac(a1, a2);
  }
  else
  {
    qdf_trace_msg(0x57u, 2u, "%s: vdev is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_mlme_is_mlo_vdev");
  }
  return wlan_vdev_get_bss_peer_mac(a1, a2);
}
