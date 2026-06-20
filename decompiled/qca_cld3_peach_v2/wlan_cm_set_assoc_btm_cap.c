__int64 __fastcall wlan_cm_set_assoc_btm_cap(
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
  if ( result )
  {
    result = wlan_vdev_mlme_get_ext_hdl(result, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( result )
      *(_BYTE *)(result + 24244) = a2 & 1;
  }
  return result;
}
