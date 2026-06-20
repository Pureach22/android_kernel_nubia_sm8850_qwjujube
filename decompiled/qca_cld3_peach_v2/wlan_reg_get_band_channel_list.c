__int64 __fastcall wlan_reg_get_band_channel_list(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  if ( a1 )
    return reg_get_band_channel_list(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
  qdf_trace_msg(
    0x51u,
    2u,
    "%s: pdev object is NULL",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlan_reg_get_band_channel_list");
  return 0;
}
