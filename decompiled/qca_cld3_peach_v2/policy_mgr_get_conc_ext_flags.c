__int64 __fastcall policy_mgr_get_conc_ext_flags(
        __int64 result,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  char is_mlo_vdev; // w8
  __int64 assoc_link_vdev; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( result )
  {
    if ( *(_DWORD *)(result + 16) )
    {
      return 0;
    }
    else if ( (a2 & 1) != 0
           || (v10 = result,
               is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(result, a3, a4, a5, a6, a7, a8, a9, a10),
               result = v10,
               (is_mlo_vdev & 1) != 0) )
    {
      if ( (*(_BYTE *)(result + 60) & 2) != 0 && (assoc_link_vdev = ucfg_mlo_get_assoc_link_vdev(result)) != 0 )
      {
        if ( ucfg_cm_is_vdev_active(assoc_link_vdev, v13, v14, v15, v16, v17, v18, v19, v20) )
          return 3;
        else
          return 1;
      }
      else
      {
        return 1;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
