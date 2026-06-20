__int64 __fastcall wlan_mlme_check_chan_param_has_dfs(
        __int64 a1,
        unsigned int *a2,
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
  char is_dfs_for_freq; // w20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int channel_state_for_pwrmode; // w0

  if ( *a2 == 4 )
  {
    if ( (unsigned int)wlan_reg_get_channel_state_for_pwrmode(a1, a3, 0, a4, a5, a6, a7, a8, a9, a10, a11) == 2
      || (channel_state_for_pwrmode = wlan_reg_get_channel_state_for_pwrmode(
                                        a1,
                                        a2[3],
                                        0,
                                        v15,
                                        v16,
                                        v17,
                                        v18,
                                        v19,
                                        v20,
                                        v21,
                                        v22),
          is_dfs_for_freq = 0,
          channel_state_for_pwrmode == 2) )
    {
      is_dfs_for_freq = 1;
    }
  }
  else if ( *a2 == 3 )
  {
    is_dfs_for_freq = (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                      a1,
                                      a3,
                                      a2,
                                      0,
                                      a4,
                                      a5,
                                      a6,
                                      a7,
                                      a8,
                                      a9,
                                      a10,
                                      a11) == 2;
  }
  else
  {
    is_dfs_for_freq = wlan_reg_is_dfs_for_freq(a1, a3, a4, a5, a6, a7, a8, a9, a10, a11);
  }
  if ( wlan_reg_is_6ghz_chan_freq(a3) || wlan_reg_is_24ghz_ch_freq(a3) )
    is_dfs_for_freq = 0;
  return is_dfs_for_freq & 1;
}
