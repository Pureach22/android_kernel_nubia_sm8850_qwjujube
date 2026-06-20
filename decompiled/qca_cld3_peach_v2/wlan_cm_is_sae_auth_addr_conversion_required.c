__int64 __fastcall wlan_cm_is_sae_auth_addr_conversion_required(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0

  if ( *(_BYTE *)(a1 + 94) != 1 )
    return 0;
  if ( wlan_cm_is_vdev_roaming(a1, a2, a3, a4, a5, a6, a7, a8, a9) )
  {
    if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 0 )
      return 0;
    result = cm_get_ext_hdl_fl(a1, (__int64)"wlan_cm_roam_is_mlo_ap", 0x183Bu, v10, v11, v12, v13, v14, v15, v16, v17);
    if ( !result )
      return result;
    if ( (*(_BYTE *)(result + 948) & 1) == 0 )
      return 0;
  }
  else if ( (wlan_vdev_mlme_is_mlo_vdev(a1, v10, v11, v12, v13, v14, v15, v16, v17) & 1) == 0 )
  {
    return 0;
  }
  return 1;
}
