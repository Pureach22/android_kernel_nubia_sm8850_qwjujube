__int64 __fastcall wlan_cm_get_rso_user_config_fl(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 ext_hdl_fl; // x0

  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 0 )
    return 0;
  ext_hdl_fl = cm_get_ext_hdl_fl(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( ext_hdl_fl )
    return ext_hdl_fl + 1376;
  else
    return 0;
}
