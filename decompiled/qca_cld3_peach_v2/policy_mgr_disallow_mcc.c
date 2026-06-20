__int64 __fastcall policy_mgr_disallow_mcc(__int64 a1, unsigned int a2)
{
  __int64 comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  unsigned int v14; // w20

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( comp_private_obj )
  {
    v13 = comp_private_obj;
    qdf_mutex_acquire(comp_private_obj + 56);
    if ( BYTE4(qword_8D4F00) != 1 )
      goto LABEL_38;
    if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
    {
      if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list))
        && HIDWORD(pm_conc_connection_list) != a2
        && (policy_mgr_are_sbs_chan(a1, a2, HIDWORD(pm_conc_connection_list)) & 1) == 0 )
      {
        goto LABEL_36;
      }
    }
    else if ( HIDWORD(pm_conc_connection_list) != a2 )
    {
      goto LABEL_36;
    }
    if ( BYTE4(qword_8D4F24) != 1 )
      goto LABEL_38;
    if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
    {
      if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C))
        && HIDWORD(qword_8D4F0C) != a2
        && (policy_mgr_are_sbs_chan(a1, a2, HIDWORD(qword_8D4F0C)) & 1) == 0 )
      {
        goto LABEL_36;
      }
    }
    else if ( HIDWORD(qword_8D4F0C) != a2 )
    {
      goto LABEL_36;
    }
    if ( BYTE4(qword_8D4F48) != 1 )
      goto LABEL_38;
    if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
    {
      if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F30))
        && HIDWORD(qword_8D4F30) != a2
        && (policy_mgr_are_sbs_chan(a1, a2, HIDWORD(qword_8D4F30)) & 1) == 0 )
      {
        goto LABEL_36;
      }
    }
    else if ( HIDWORD(qword_8D4F30) != a2 )
    {
      goto LABEL_36;
    }
    if ( BYTE4(qword_8D4F6C) != 1 )
      goto LABEL_38;
    if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
    {
      if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F54))
        && HIDWORD(qword_8D4F54) != a2
        && (policy_mgr_are_sbs_chan(a1, a2, HIDWORD(qword_8D4F54)) & 1) == 0 )
      {
        goto LABEL_36;
      }
    }
    else if ( HIDWORD(qword_8D4F54) != a2 )
    {
      goto LABEL_36;
    }
    if ( BYTE4(qword_8D4F90) != 1 )
      goto LABEL_38;
    if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
    {
      if ( !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F78))
        && HIDWORD(qword_8D4F78) != a2
        && (policy_mgr_are_sbs_chan(a1, a2, HIDWORD(qword_8D4F78)) & 1) == 0 )
      {
        goto LABEL_36;
      }
LABEL_38:
      v14 = 0;
      goto LABEL_39;
    }
    if ( HIDWORD(qword_8D4F78) == a2 )
      goto LABEL_38;
LABEL_36:
    v14 = 1;
LABEL_39:
    qdf_mutex_release(v13 + 56);
    return v14;
  }
  qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v5, v6, v7, v8, v9, v10, v11, v12, "policy_mgr_disallow_mcc");
  return 0;
}
