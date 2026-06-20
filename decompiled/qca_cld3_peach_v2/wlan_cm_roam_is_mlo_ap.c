__int64 __fastcall wlan_cm_roam_is_mlo_ap(
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
  __int64 ext_hdl_fl; // x0
  char v11; // w8

  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 0 )
    return 0;
  ext_hdl_fl = cm_get_ext_hdl_fl(a1, (__int64)"wlan_cm_roam_is_mlo_ap", 0x183Bu, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( ext_hdl_fl )
    v11 = *(_BYTE *)(ext_hdl_fl + 948);
  else
    v11 = 0;
  return v11 & 1;
}
