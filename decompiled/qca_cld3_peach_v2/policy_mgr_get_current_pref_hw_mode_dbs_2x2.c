__int64 __fastcall policy_mgr_get_current_pref_hw_mode_dbs_2x2(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 result; // x0
  unsigned int connection_count; // w20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  char v28; // w20
  unsigned __int8 v29; // w0
  int v30; // w9
  char v31; // w0
  int v32; // w8
  char v33; // w21
  char v34; // w20
  unsigned __int8 v35; // w0
  int v36; // w10
  __int64 v37; // [xsp+8h] [xbp-18h] BYREF
  __int64 v38; // [xsp+10h] [xbp-10h]
  __int64 v39; // [xsp+18h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0;
  v38 = 0;
  if ( (unsigned int)policy_mgr_get_current_hw_mode(a1, &v37) )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: policy_mgr_get_current_hw_mode failed",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "policy_mgr_get_current_pref_hw_mode_dbs_2x2");
LABEL_3:
    result = 0;
    goto LABEL_4;
  }
  connection_count = policy_mgr_get_connection_count(a1);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: chan[0]:%d chan[1]:%d chan[2]:%d num_connections:%d dbs:%d",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "policy_mgr_get_current_pref_hw_mode_dbs_2x2",
    HIDWORD(pm_conc_connection_list),
    HIDWORD(qword_8D4F0C),
    HIDWORD(qword_8D4F30),
    connection_count,
    HIBYTE(v37));
  if ( connection_count != 3 )
  {
    if ( connection_count != 2 )
    {
      if ( connection_count == 1 )
      {
        result = (unsigned __int8)wlan_reg_freq_to_band(HIDWORD(pm_conc_connection_list)) == 0;
        goto LABEL_4;
      }
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: unexpected num_connections value %d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "policy_mgr_get_current_pref_hw_mode_dbs_2x2",
        connection_count);
      goto LABEL_3;
    }
    v28 = wlan_reg_freq_to_band(HIDWORD(pm_conc_connection_list));
    v29 = wlan_reg_freq_to_band(HIDWORD(qword_8D4F0C));
    if ( v28 )
    {
      v30 = v29;
      if ( v29 )
      {
        result = 0;
        if ( v28 == 1 && v30 == 1 )
        {
          v31 = policy_mgr_are_sbs_chan(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_8D4F0C));
          v32 = BYTE1(v38);
          if ( (v31 & 1) != 0 )
            goto LABEL_14;
          goto LABEL_30;
        }
        goto LABEL_4;
      }
    }
LABEL_27:
    result = HIBYTE(v37) == 0;
    goto LABEL_4;
  }
  v33 = wlan_reg_freq_to_band(HIDWORD(pm_conc_connection_list));
  v34 = wlan_reg_freq_to_band(HIDWORD(qword_8D4F0C));
  v35 = wlan_reg_freq_to_band(HIDWORD(qword_8D4F30));
  if ( !v33 )
    goto LABEL_27;
  if ( !v34 )
    goto LABEL_27;
  v36 = v35;
  if ( !v35 )
    goto LABEL_27;
  result = 0;
  if ( v33 == 1 && v34 == 1 && v36 == 1 )
  {
    if ( (policy_mgr_are_sbs_chan(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_8D4F30)) & 1) != 0
      && (policy_mgr_are_sbs_chan(a1, HIDWORD(qword_8D4F0C), HIDWORD(qword_8D4F30)) & 1) != 0
      && (policy_mgr_are_sbs_chan(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_8D4F0C)) & 1) != 0 )
    {
      v32 = BYTE1(v38);
LABEL_14:
      if ( v32 )
        result = 0;
      else
        result = 6;
      goto LABEL_4;
    }
    v32 = BYTE1(v38);
LABEL_30:
    result = 4 * (unsigned int)((v32 | HIBYTE(v37)) != 0);
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
