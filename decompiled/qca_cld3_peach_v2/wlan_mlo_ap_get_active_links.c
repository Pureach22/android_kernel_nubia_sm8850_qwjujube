__int64 __fastcall wlan_mlo_ap_get_active_links(
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
  __int64 *v9; // x20
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x19
  unsigned int v19; // w21
  __int64 v20; // x19

  if ( !a1 || (v9 = *(__int64 **)(a1 + 1360)) == nullptr || !v9[279] )
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: Invalid input", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_mlo_ap_get_active_links");
    return 0;
  }
  qdf_mutex_acquire((__int64)(v9 + 207));
  v18 = v9[3];
  if ( v18
    && *(_DWORD *)(v18 + 16) == 1
    && (wlan_vdev_mlme_is_mlo_vdev(v9[3], v10, v11, v12, v13, v14, v15, v16, v17) & 1) != 0 )
  {
    v19 = (unsigned int)(*(_DWORD *)(v18 + 20) - 2) < 3;
    v20 = v9[4];
    if ( !v20 )
      goto LABEL_15;
LABEL_11:
    if ( *(_DWORD *)(v20 + 16) == 1
      && (wlan_vdev_mlme_is_mlo_vdev(v20, v10, v11, v12, v13, v14, v15, v16, v17) & 1) != 0
      && (unsigned int)(*(_DWORD *)(v20 + 20) - 2) < 3 )
    {
      ++v19;
    }
    goto LABEL_15;
  }
  v19 = 0;
  v20 = v9[4];
  if ( v20 )
    goto LABEL_11;
LABEL_15:
  qdf_mutex_release((__int64)(v9 + 207));
  return v19;
}
