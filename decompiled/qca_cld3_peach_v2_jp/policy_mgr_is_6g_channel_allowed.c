__int64 __fastcall policy_mgr_is_6g_channel_allowed(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x23
  bool is_5ghz_ch_freq; // w0
  int v26; // w8
  unsigned int v28; // w22
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x21
  __int64 v39; // x20

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v15 = context;
    if ( wlan_reg_is_6ghz_chan_freq(a3) )
    {
      if ( (a2 & 0xFFFFFFFD) != 0 && (a2 > 6 || ((1 << a2) & 0x4A) == 0) )
      {
        v39 = jiffies;
        if ( policy_mgr_is_6g_channel_allowed___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: mode %d for 6ghz not supported",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "policy_mgr_is_6g_channel_allowed",
            a2);
          policy_mgr_is_6g_channel_allowed___last_ticks = v39;
        }
        return 0;
      }
      else
      {
        qdf_mutex_acquire(v15 + 56);
        v24 = 0;
        while ( 1 )
        {
          if ( *((_BYTE *)&pm_conc_connection_list + v24 + 28) == 1
            && (*(_WORD *)((_BYTE *)&pm_conc_connection_list + v24 + 30) & 6) != 0 )
          {
            is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(*(_DWORD *)((char *)&pm_conc_connection_list + v24 + 4));
            v26 = *(_DWORD *)((char *)&pm_conc_connection_list + v24);
            if ( ((v26 & 0xFFFFFFFD) == 1 || v26 == 6) && is_5ghz_ch_freq )
            {
              v28 = *(_DWORD *)((char *)&pm_conc_connection_list + v24 + 4);
              if ( v28 != a3
                && ((policy_mgr_is_hw_sbs_capable(a1) & 1) == 0
                 || wlan_reg_is_24ghz_ch_freq(a3)
                 || wlan_reg_is_24ghz_ch_freq(v28)
                 || (policy_mgr_2_freq_same_mac_in_sbs(a1, a3, v28) & 1) != 0) )
              {
                break;
              }
            }
          }
          v24 += 36;
          if ( v24 == 180 )
          {
            qdf_mutex_release(v15 + 56);
            return 1;
          }
        }
        v37 = jiffies;
        if ( policy_mgr_is_6g_channel_allowed___last_ticks_243 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: don't allow MCC if SAP/GO on DFS channel",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "policy_mgr_is_6g_channel_allowed");
          policy_mgr_is_6g_channel_allowed___last_ticks_243 = v37;
        }
        qdf_mutex_release(v15 + 56);
        return 0;
      }
    }
    else
    {
      return 1;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "policy_mgr_is_6g_channel_allowed");
    return 0;
  }
}
