__int64 __fastcall wlan_vdev_mlme_set_mlo_link_vdev(
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
  __int64 v9; // x20
  int v11; // w8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v21; // x2
  unsigned int v28; // w9

  if ( !a1 )
  {
    v21 = "%s: vdev is NULL";
    return qdf_trace_msg(0x57u, 2u, v21, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_vdev_mlme_set_mlo_link_vdev");
  }
  v9 = *(_QWORD *)(a1 + 216);
  if ( !v9 )
  {
    v21 = "%s: pdev is NULL";
    return qdf_trace_msg(0x57u, 2u, v21, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_vdev_mlme_set_mlo_link_vdev");
  }
  qdf_mutex_acquire(a1 + 96);
  v11 = *(_DWORD *)(a1 + 60);
  if ( (v11 & 2) != 0 )
    return qdf_mutex_release(a1 + 96);
  if ( (v11 & 1) == 0 )
  {
    _X8 = (unsigned int *)(v9 + 528);
    __asm { PRFM            #0x11, [X8] }
    do
      v28 = __ldxr(_X8);
    while ( __stxr(v28 + 1, _X8) );
  }
  *(_DWORD *)(a1 + 60) |= 3u;
  qdf_mutex_release(a1 + 96);
  return qdf_trace_msg(
           0x57u,
           8u,
           "%s: Set MLO link flag: vdev_id: %d",
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           "wlan_vdev_mlme_set_mlo_link_vdev",
           *(unsigned __int8 *)(a1 + 168));
}
