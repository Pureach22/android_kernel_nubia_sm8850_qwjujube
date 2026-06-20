__int64 __fastcall wlan_reg_get_band_channel_list_for_pwrmode(
        __int64 a1,
        char a2,
        __int64 a3,
        unsigned int a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  if ( a1 )
    return reg_get_band_channel_list_for_pwrmode(a1, a2, a3, a4, a5 & 1);
  qdf_trace_msg(
    0x51u,
    2u,
    "%s: pdev object is NULL",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "wlan_reg_get_band_channel_list_for_pwrmode");
  return 0;
}
