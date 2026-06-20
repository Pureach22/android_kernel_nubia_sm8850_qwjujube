__int64 __fastcall policy_mgr_get_index_for_3_given_freq_dbs(
        int *a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4)
{
  _BOOL4 is_24ghz_ch_freq; // w23
  _BOOL4 v9; // w23
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  bool v18; // w22
  char v19; // w21
  __int64 result; // x0
  int v21; // w8

  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(a2);
  if ( ((is_24ghz_ch_freq ^ wlan_reg_is_24ghz_ch_freq(a3)) & 1) != 0
    || (v9 = wlan_reg_is_24ghz_ch_freq(a3), ((v9 ^ wlan_reg_is_24ghz_ch_freq(a4)) & 1) != 0) )
  {
    v18 = wlan_reg_is_24ghz_ch_freq(a2);
    v19 = v18 ^ wlan_reg_is_24ghz_ch_freq(a3);
    result = wlan_reg_is_24ghz_ch_freq(a4);
    if ( (v19 & 1) != 0 )
    {
      if ( (result & 1) == 0 )
      {
LABEL_5:
        v21 = 3;
LABEL_8:
        *a1 = v21;
        return result;
      }
    }
    else if ( (result & 1) != 0 )
    {
      goto LABEL_5;
    }
    v21 = 2;
    goto LABEL_8;
  }
  return qdf_trace_msg(
           0x4Fu,
           2u,
           "%s: Invalid mode for all freq %d, %d and %d on same band",
           v10,
           v11,
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           "policy_mgr_get_index_for_3_given_freq_dbs",
           a2,
           a3,
           a4);
}
