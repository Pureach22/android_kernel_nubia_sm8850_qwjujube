__int64 __fastcall reg_get_ch_state_based_on_nol_flag(
        __int64 a1,
        unsigned int a2,
        int *a3,
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
  if ( (a5 & 1) != 0 )
    return wlan_reg_get_5g_bonded_channel_state_for_pwrmode();
  else
    return reg_get_5g_chan_state(a1, a2, *a3, a4, a6, a7, a8, a9, a10, a11, a12, a13);
}
