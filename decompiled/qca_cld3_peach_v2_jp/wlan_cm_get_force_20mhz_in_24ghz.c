__int64 __fastcall wlan_cm_get_force_20mhz_in_24ghz(
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
  __int64 ext_hdl; // x0
  char v10; // w8

  if ( !a1 )
    return 1;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( ext_hdl )
    v10 = *(_BYTE *)(ext_hdl + 24268);
  else
    v10 = 1;
  return v10 & 1;
}
