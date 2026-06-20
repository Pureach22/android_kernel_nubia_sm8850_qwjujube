__int64 __fastcall wlan_hdd_mlo_reset(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  char is_mlo_vdev; // w8

  result = _hdd_objmgr_get_vdev_by_user(a1, 6, "wlan_hdd_mlo_reset");
  if ( result )
  {
    if ( *(_DWORD *)(result + 16) == 1 )
    {
      v11 = result;
      is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(result, v3, v4, v5, v6, v7, v8, v9, v10);
      result = v11;
      if ( (is_mlo_vdev & 1) != 0 )
      {
        *(_BYTE *)(a1 + 2151) = 0;
        *(_WORD *)(a1 + 2149) = 0;
        mlo_ap_vdev_detach(v11);
        result = v11;
      }
    }
    return _hdd_objmgr_put_vdev_by_user(result, 6, "wlan_hdd_mlo_reset");
  }
  return result;
}
