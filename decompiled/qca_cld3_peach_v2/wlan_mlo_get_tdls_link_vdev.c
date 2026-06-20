__int64 __fastcall wlan_mlo_get_tdls_link_vdev(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x0
  __int64 result; // x0

  v9 = *(_QWORD *)(a1 + 1360);
  if ( !v9 || (wlan_vdev_mlme_is_mlo_vdev(a1, a2, a3, a4, a5, a6, a7, a8, a9) & 1) == 0 )
    return 0;
  v18 = *(_QWORD *)(v9 + 24);
  if ( v18 && (wlan_vdev_mlme_is_tdls_vdev(v18, v10, v11, v12, v13, v14, v15, v16, v17) & 1) != 0 )
    return *(_QWORD *)(v9 + 24);
  result = *(_QWORD *)(v9 + 32);
  if ( result )
  {
    if ( (wlan_vdev_mlme_is_tdls_vdev(result, v10, v11, v12, v13, v14, v15, v16, v17) & 1) != 0 )
      return *(_QWORD *)(v9 + 32);
    return 0;
  }
  return result;
}
