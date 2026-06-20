__int64 __fastcall policy_mgr_get_second_connection_pcl_table_index(__int64 a1)
{
  __int64 context; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w20
  bool v20; // w0
  bool v21; // zf
  int v22; // w8
  bool v23; // w0
  bool is_24ghz_ch_freq; // w0
  bool v25; // w0

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v10 = context;
    qdf_mutex_acquire(context + 56);
    v19 = 23;
    if ( (int)pm_conc_connection_list > 2 )
    {
      if ( (_DWORD)pm_conc_connection_list == 3 )
      {
        is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list));
        v21 = dword_81C450 == 0;
        if ( is_24ghz_ch_freq )
          v22 = 8;
        else
          v22 = 10;
      }
      else
      {
        if ( (_DWORD)pm_conc_connection_list != 5 )
        {
          if ( (_DWORD)pm_conc_connection_list == 6 )
            v19 = 22;
          goto LABEL_27;
        }
        v21 = dword_81C450 == 0;
        v22 = 16;
      }
      goto LABEL_24;
    }
    if ( (_DWORD)pm_conc_connection_list )
    {
      if ( (_DWORD)pm_conc_connection_list == 1 )
      {
        v25 = wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list));
        v21 = dword_81C450 == 0;
        if ( v25 )
          v22 = 12;
        else
          v22 = 14;
        goto LABEL_24;
      }
      if ( (_DWORD)pm_conc_connection_list == 2 )
      {
        v20 = wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list));
        v21 = dword_81C450 == 0;
        if ( v20 )
          v22 = 4;
        else
          v22 = 6;
        goto LABEL_24;
      }
    }
    else
    {
      v23 = wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list));
      v21 = dword_81C450 == 0;
      if ( !v23 )
      {
        v22 = 2;
LABEL_24:
        if ( v21 )
          v19 = v22;
        else
          v19 = v22 + 1;
        goto LABEL_27;
      }
      v19 = dword_81C450 != 0;
    }
LABEL_27:
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: mode:%d freq:%d chain:%d index:%d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "policy_mgr_get_second_connection_pcl_table_index",
      (unsigned int)pm_conc_connection_list,
      HIDWORD(pm_conc_connection_list),
      (unsigned int)dword_81C450,
      v19);
    qdf_mutex_release(v10 + 56);
    return v19;
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: Invalid Context",
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    "policy_mgr_get_second_connection_pcl_table_index");
  return 23;
}
