__int64 __fastcall wlan_vdev_mlme_is_mlo_vdev(
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
  unsigned int v10; // w19

  if ( a1 )
  {
    qdf_mutex_acquire(a1 + 96);
    v10 = *(_DWORD *)(a1 + 60) & 1;
    qdf_mutex_release(a1 + 96);
  }
  else
  {
    qdf_trace_msg(0x57u, 2u, "%s: vdev is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_vdev_mlme_is_mlo_vdev");
    return 0;
  }
  return v10;
}
