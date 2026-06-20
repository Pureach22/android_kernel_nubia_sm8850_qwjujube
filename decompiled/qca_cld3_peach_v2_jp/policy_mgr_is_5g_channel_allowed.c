__int64 __fastcall policy_mgr_is_5g_channel_allowed(__int64 a1, unsigned int a2, _DWORD *a3, unsigned int a4)
{
  __int64 comp_private_obj; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x22
  __int64 v18; // x23
  __int64 is_5ghz_ch_freq; // x0
  __int64 v20; // x2
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x20

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( comp_private_obj )
  {
    v17 = comp_private_obj;
    LODWORD(v18) = policy_mgr_mode_specific_connection_count(a1, a4, a3);
    is_5ghz_ch_freq = qdf_mutex_acquire(v17 + 56);
    if ( (_DWORD)v18 )
    {
      v18 = (unsigned int)v18;
      while ( 1 )
      {
        if ( *a3 >= 5u )
        {
LABEL_17:
          __break(0x5512u);
          return policy_mgr_get_conc_ml_sap_link_freq(is_5ghz_ch_freq);
        }
        if ( (*((_WORD *)&pm_conc_connection_list + 18 * (unsigned int)*a3 + 15) & 6) != 0 )
        {
          is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(a2);
          if ( (is_5ghz_ch_freq & 1) != 0 )
          {
            if ( *a3 > 4u )
              goto LABEL_17;
            v20 = *((unsigned int *)&pm_conc_connection_list + 9 * (unsigned int)*a3 + 1);
            if ( (_DWORD)v20 != a2 )
            {
              is_5ghz_ch_freq = policy_mgr_are_sbs_chan(a1, a2, v20);
              if ( (is_5ghz_ch_freq & 1) == 0 )
                break;
            }
          }
        }
        --v18;
        ++a3;
        if ( !v18 )
          goto LABEL_13;
      }
      qdf_mutex_release(v17 + 56);
      v29 = jiffies;
      if ( policy_mgr_is_5g_channel_allowed___last_ticks - jiffies + 125 >= 0 )
        return 0;
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: don't allow MCC if SAP/GO on DFS channel",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "policy_mgr_is_5g_channel_allowed");
      policy_mgr_is_5g_channel_allowed___last_ticks = v29;
      return 0;
    }
    else
    {
LABEL_13:
      qdf_mutex_release(v17 + 56);
      return 1;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "policy_mgr_is_5g_channel_allowed");
    return 0;
  }
}
