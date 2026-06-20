__int64 __fastcall policy_mgr_get_third_connection_pcl_table_index(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w21
  unsigned int third_connection_pcl_table_index_sap_sap; // w0
  _BOOL4 v23; // w10
  bool v24; // zf
  _BOOL4 v26; // w10
  bool v27; // zf
  _BOOL4 v29; // w10
  bool v30; // zf
  _BOOL4 v33; // w10
  bool v34; // zf
  _BOOL4 v36; // w10
  bool v37; // zf
  _BOOL4 v39; // w10
  bool v40; // zf
  _BOOL4 v42; // w10
  bool v43; // zf
  _BOOL4 v45; // w10
  bool v46; // zf

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v11 = context;
    qdf_mutex_acquire(context + 56);
    if ( (_DWORD)pm_conc_connection_list == 2 && (_DWORD)qword_8D4F0C == 1
      || (_DWORD)pm_conc_connection_list == 1 && (_DWORD)qword_8D4F0C == 2 )
    {
      if ( HIDWORD(pm_conc_connection_list) == HIDWORD(qword_8D4F0C) )
      {
        if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list)) )
        {
          if ( dword_8D4EF8 )
            v20 = 79;
          else
            v20 = 78;
        }
        else if ( dword_8D4EF8 )
        {
          v20 = 83;
        }
        else
        {
          v20 = 82;
        }
        goto LABEL_112;
      }
      if ( (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_8D4F0C)) & 1) != 0 )
      {
        if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
          && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C)) )
        {
          if ( dword_8D4EF8 )
            v20 = 81;
          else
            v20 = 80;
        }
        else if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
               || wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C)) )
        {
          if ( dword_8D4EF8 )
            v20 = 87;
          else
            v20 = 86;
        }
        else if ( dword_8D4EF8 )
        {
          v20 = 85;
        }
        else
        {
          v20 = 84;
        }
        goto LABEL_112;
      }
      if ( (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_8D4F0C)) & 1) == 0 )
      {
        if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
          || wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C)) )
        {
          if ( dword_8D4EF8 )
            v20 = 89;
          else
            v20 = 88;
        }
        else
        {
          v20 = 90;
        }
        goto LABEL_112;
      }
    }
    else
    {
      if ( ((_DWORD)pm_conc_connection_list || (_DWORD)qword_8D4F0C != 1)
        && ((_DWORD)pm_conc_connection_list != 1 || (_DWORD)qword_8D4F0C) )
      {
        if ( (_DWORD)pm_conc_connection_list == 1 && (_DWORD)qword_8D4F0C == 1 )
        {
          third_connection_pcl_table_index_sap_sap = policy_mgr_get_third_connection_pcl_table_index_sap_sap(a1);
        }
        else if ( ((_DWORD)pm_conc_connection_list || (_DWORD)qword_8D4F0C != 3)
               && ((_DWORD)pm_conc_connection_list != 3 || (_DWORD)qword_8D4F0C) )
        {
          v23 = (_DWORD)pm_conc_connection_list == 2 && (_DWORD)qword_8D4F0C == 0;
          v24 = (_DWORD)qword_8D4F0C == 2 && (_DWORD)pm_conc_connection_list == 0;
          if ( v24 || v23 )
          {
            third_connection_pcl_table_index_sap_sap = policy_mgr_get_third_connection_pcl_table_index_sta_cli(a1);
          }
          else
          {
            v26 = (_DWORD)pm_conc_connection_list == 2 && (_DWORD)qword_8D4F0C == 3;
            v27 = (_DWORD)qword_8D4F0C == 2 && (_DWORD)pm_conc_connection_list == 3;
            if ( v27 || v26 )
            {
              third_connection_pcl_table_index_sap_sap = policy_mgr_get_third_connection_pcl_table_index_go_cli(a1);
            }
            else
            {
              v29 = (_DWORD)pm_conc_connection_list == 3 && (_DWORD)qword_8D4F0C == 1;
              v30 = (_DWORD)qword_8D4F0C == 3 && (_DWORD)pm_conc_connection_list == 1;
              if ( v30 || v29 )
              {
                third_connection_pcl_table_index_sap_sap = policy_mgr_get_third_connection_pcl_table_index_go_sap(a1);
              }
              else if ( (unsigned int)pm_conc_connection_list | (unsigned int)qword_8D4F0C )
              {
                if ( ((_DWORD)pm_conc_connection_list != 5 || (_DWORD)qword_8D4F0C)
                  && ((_DWORD)pm_conc_connection_list || (_DWORD)qword_8D4F0C != 5) )
                {
                  v33 = (_DWORD)pm_conc_connection_list == 4 && (_DWORD)qword_8D4F0C == 5;
                  v34 = (_DWORD)qword_8D4F0C == 4 && (_DWORD)pm_conc_connection_list == 5;
                  if ( v34 || v33 )
                  {
                    third_connection_pcl_table_index_sap_sap = policy_mgr_get_third_connection_pcl_table_index_nan_ndi(a1);
                  }
                  else
                  {
                    v36 = (_DWORD)pm_conc_connection_list == 5 && (_DWORD)qword_8D4F0C == 1;
                    v37 = (_DWORD)qword_8D4F0C == 5 && (_DWORD)pm_conc_connection_list == 1;
                    if ( v37 || v36 )
                    {
                      third_connection_pcl_table_index_sap_sap = policy_mgr_get_third_connection_pcl_table_index_sap_nan(a1);
                    }
                    else if ( (_DWORD)pm_conc_connection_list == 3 && (_DWORD)qword_8D4F0C == 3 )
                    {
                      third_connection_pcl_table_index_sap_sap = policy_mgr_get_third_connection_pcl_table_index_go_go(a1);
                    }
                    else if ( (_DWORD)pm_conc_connection_list == 2 && (_DWORD)qword_8D4F0C == 2 )
                    {
                      third_connection_pcl_table_index_sap_sap = policy_mgr_get_third_connection_pcl_table_index_cli_cli(a1);
                    }
                    else if ( ((_DWORD)pm_conc_connection_list || (_DWORD)qword_8D4F0C != 6)
                           && ((_DWORD)pm_conc_connection_list != 6 || (_DWORD)qword_8D4F0C) )
                    {
                      v39 = (_DWORD)pm_conc_connection_list == 6 && (_DWORD)qword_8D4F0C == 1;
                      v40 = (_DWORD)qword_8D4F0C == 6 && (_DWORD)pm_conc_connection_list == 1;
                      if ( v40 || v39 )
                      {
                        third_connection_pcl_table_index_sap_sap = policy_mgr_get_third_connection_pcl_table_index_sap_ll_lt_sap(a1);
                      }
                      else
                      {
                        v42 = (_DWORD)pm_conc_connection_list == 6 && (_DWORD)qword_8D4F0C == 3;
                        v43 = (_DWORD)qword_8D4F0C == 6 && (_DWORD)pm_conc_connection_list == 3;
                        if ( v43 || v42 )
                        {
                          third_connection_pcl_table_index_sap_sap = policy_mgr_get_third_connection_pcl_table_index_go_ll_lt_sap(a1);
                        }
                        else
                        {
                          v45 = (_DWORD)pm_conc_connection_list == 6 && (_DWORD)qword_8D4F0C == 2;
                          v46 = (_DWORD)qword_8D4F0C == 6 && (_DWORD)pm_conc_connection_list == 2;
                          if ( !v46 && !v45 )
                          {
                            if ( (_DWORD)pm_conc_connection_list == 5 && (qword_8D4F0C & 0xFFFFFFFE) == 2
                              || (v20 = 164, (_DWORD)qword_8D4F0C == 5) && (pm_conc_connection_list & 0xFFFFFFFE) == 2 )
                            {
                              if ( HIDWORD(pm_conc_connection_list) != HIDWORD(qword_8D4F0C) )
                                policy_mgr_are_2_freq_on_same_mac(
                                  a1,
                                  HIDWORD(pm_conc_connection_list),
                                  HIDWORD(qword_8D4F0C));
                              v20 = 148;
                            }
                            goto LABEL_112;
                          }
                          third_connection_pcl_table_index_sap_sap = policy_mgr_get_third_connection_pcl_table_index_cli_ll_lt_sap(a1);
                        }
                      }
                    }
                    else
                    {
                      third_connection_pcl_table_index_sap_sap = policy_mgr_get_third_connection_pcl_table_index_sta_ll_lt_sap(a1);
                    }
                  }
                }
                else
                {
                  third_connection_pcl_table_index_sap_sap = policy_mgr_get_third_connection_pcl_table_index_sta_nan(a1);
                }
              }
              else
              {
                third_connection_pcl_table_index_sap_sap = policy_mgr_get_third_connection_pcl_table_index_sta_sta(a1);
              }
            }
          }
        }
        else
        {
          third_connection_pcl_table_index_sap_sap = policy_mgr_get_third_connection_pcl_table_index_sta_go(a1);
        }
        v20 = third_connection_pcl_table_index_sap_sap;
LABEL_112:
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: mode0:%d mode1:%d freq0:%d freq1:%d chain:%d index:%d",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "policy_mgr_get_third_connection_pcl_table_index",
          (unsigned int)pm_conc_connection_list,
          (unsigned int)qword_8D4F0C,
          HIDWORD(pm_conc_connection_list),
          HIDWORD(qword_8D4F0C),
          dword_8D4EF8,
          v20);
        qdf_mutex_release(v11 + 56);
        return v20;
      }
      if ( HIDWORD(pm_conc_connection_list) == HIDWORD(qword_8D4F0C) )
      {
        if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list)) )
        {
          v20 = dword_8D4EF8 != 0;
        }
        else if ( dword_8D4EF8 )
        {
          v20 = 5;
        }
        else
        {
          v20 = 4;
        }
        goto LABEL_112;
      }
      if ( (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_8D4F0C)) & 1) != 0 )
      {
        if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
          && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C)) )
        {
          if ( dword_8D4EF8 )
            v20 = 3;
          else
            v20 = 2;
        }
        else if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
               || wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C)) )
        {
          if ( dword_8D4EF8 )
            v20 = 9;
          else
            v20 = 8;
        }
        else if ( dword_8D4EF8 )
        {
          v20 = 7;
        }
        else
        {
          v20 = 6;
        }
        goto LABEL_112;
      }
      if ( (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_8D4F0C)) & 1) == 0 )
      {
        if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
          || wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C)) )
        {
          if ( dword_8D4EF8 )
            v20 = 11;
          else
            v20 = 10;
        }
        else
        {
          v20 = 12;
        }
        goto LABEL_112;
      }
    }
    v20 = 164;
    goto LABEL_112;
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: Invalid Context",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "policy_mgr_get_third_connection_pcl_table_index");
  return 164;
}
