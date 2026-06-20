bool __fastcall mlo_is_mld_connected(
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
  _QWORD *v9; // x19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x0
  __int64 v19; // x0
  _BOOL8 result; // x0

  v9 = *(_QWORD **)(a1 + 1360);
  result = true;
  if ( v9 && (wlan_vdev_mlme_is_mlo_vdev(a1, a2, a3, a4, a5, a6, a7, a8, a9) & 1) != 0 )
  {
    v18 = v9[3];
    if ( v18 )
    {
      if ( (*(_QWORD *)(v9[278] + 8LL) & 1) != 0
        && !wlan_cm_is_vdev_connected(v18, v10, v11, v12, v13, v14, v15, v16, v17) )
      {
        return false;
      }
    }
    v19 = v9[4];
    if ( v19 )
    {
      if ( (*(_QWORD *)(v9[278] + 8LL) & 2) != 0
        && !wlan_cm_is_vdev_connected(v19, v10, v11, v12, v13, v14, v15, v16, v17) )
      {
        return false;
      }
    }
  }
  return result;
}
