bool __fastcall mlo_is_mld_vdevs_active(
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
  __int64 v10; // x0
  __int64 v11; // x0
  _BOOL8 result; // x0

  v9 = *(_QWORD **)(a1 + 1360);
  result = true;
  if ( v9 && (wlan_vdev_mlme_is_mlo_vdev(a1, a2, a3, a4, a5, a6, a7, a8, a9) & 1) != 0 )
  {
    v10 = v9[3];
    if ( v10 )
    {
      if ( (*(_QWORD *)(v9[278] + 8LL) & 1) != 0 && (unsigned int)wlan_vdev_mlme_is_active(v10) )
        return false;
    }
    v11 = v9[4];
    if ( v11 )
    {
      if ( (*(_QWORD *)(v9[278] + 8LL) & 2) != 0 && (unsigned int)wlan_vdev_mlme_is_active(v11) )
        return false;
    }
  }
  return result;
}
