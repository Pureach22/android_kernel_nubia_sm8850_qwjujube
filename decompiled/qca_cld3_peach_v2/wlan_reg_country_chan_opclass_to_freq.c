__int64 __fastcall wlan_reg_country_chan_opclass_to_freq(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
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
  return reg_country_chan_opclass_to_freq(a6, a7, a8, a9, a10, a11, a12, a13, a1, a2, a3, a4, a5);
}
