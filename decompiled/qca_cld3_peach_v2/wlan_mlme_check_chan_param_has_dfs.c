__int64 __fastcall wlan_mlme_check_chan_param_has_dfs(
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
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  char is_dfs_for_freq; // w20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int channel_state_for_pwrmode; // w0

  if ( *(_DWORD *)a2 == 4 )
  {
    if ( (unsigned int)wlan_reg_get_channel_state_for_pwrmode(a1, a3, 0, a4, a5, a6, a7, a8, a9, a10, a11) == 2
      || (channel_state_for_pwrmode = wlan_reg_get_channel_state_for_pwrmode(
                                        a1,
                                        *(_DWORD *)(a2 + 12),
                                        0,
                                        v24,
                                        v25,
                                        v26,
                                        v27,
                                        v28,
                                        v29,
                                        v30,
                                        v31),
          is_dfs_for_freq = 0,
          channel_state_for_pwrmode == 2) )
    {
      is_dfs_for_freq = 1;
    }
  }
  else if ( *(_DWORD *)a2 == 3 )
  {
    wlan_reg_set_create_punc_bitmap(a2, 1);
    is_dfs_for_freq = (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                      a1,
                                      a3,
                                      (int *)a2,
                                      0,
                                      v14,
                                      v15,
                                      v16,
                                      v17,
                                      v18,
                                      v19,
                                      v20,
                                      v21) == 2;
  }
  else
  {
    is_dfs_for_freq = wlan_reg_is_dfs_for_freq(a1, a3, a4, a5, a6, a7, a8, a9, a10, a11);
  }
  if ( wlan_reg_is_6ghz_chan_freq(a3) || wlan_reg_is_24ghz_ch_freq(a3) )
    is_dfs_for_freq = 0;
  return is_dfs_for_freq & 1;
}
