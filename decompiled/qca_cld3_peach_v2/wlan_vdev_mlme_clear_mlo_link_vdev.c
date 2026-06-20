__int64 __fastcall wlan_vdev_mlme_clear_mlo_link_vdev(
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
  int v10; // w8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( !a1 )
    return qdf_trace_msg(
             0x57u,
             2u,
             "%s: vdev is NULL",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "wlan_vdev_mlme_clear_mlo_link_vdev");
  qdf_mutex_acquire(a1 + 96);
  v10 = *(_DWORD *)(a1 + 60);
  if ( (v10 & 2) == 0 )
    return qdf_mutex_release(a1 + 96);
  *(_DWORD *)(a1 + 60) = v10 & 0xFFFFFFFD;
  qdf_mutex_release(a1 + 96);
  return qdf_trace_msg(
           0x57u,
           8u,
           "%s: Clear MLO link flag: vdev_id: %d",
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           "wlan_vdev_mlme_clear_mlo_link_vdev",
           *(unsigned __int8 *)(a1 + 168));
}
