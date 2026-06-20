__int64 __fastcall wlansap_get_safe_channel(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x19
  unsigned int v22; // w22
  const char *v23; // x2
  __int64 result; // x0
  unsigned int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int valid_chans_from_range; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 is_5ghz_ch_freq; // x0
  __int64 v44; // x1
  __int64 v45; // x2
  __int64 v46; // x3
  __int64 v47; // x4
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned __int64 v56; // x23
  unsigned __int64 v57; // x24
  unsigned int v58; // w20
  unsigned int v59; // w22
  unsigned int v60; // w26
  unsigned int v61; // w21
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // [xsp+8h] [xbp-1A8h] BYREF
  _DWORD s[102]; // [xsp+10h] [xbp-1A0h] BYREF
  __int64 v72; // [xsp+1A8h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v70 = 0;
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", v4, v5, v6, v7, v8, v9, v10, v11);
  if ( !context )
  {
    v23 = "%s: Invalid MAC context";
    goto LABEL_5;
  }
  v21 = context;
  v22 = policy_mgr_qdf_opmode_to_pm_con_mode(
          context[2703],
          1,
          *(_BYTE *)(a1 + 12),
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20);
  if ( (unsigned int)policy_mgr_get_valid_chans(v21[2703], s, (unsigned int *)&v70 + 1) )
  {
    v23 = "%s: Error in getting valid channels";
LABEL_5:
    qdf_trace_msg(0x39u, 2u, v23, v13, v14, v15, v16, v17, v18, v19, v20, "wlansap_get_safe_channel");
LABEL_6:
    result = 0;
    goto LABEL_7;
  }
  v25 = wlansap_filter_ch_based_acs(a1, (__int64)s, (_DWORD *)&v70 + 1, v13, v14, v15, v16, v17, v18, v19, v20);
  if ( v25 )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: failed to filter ch from acs %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wlansap_get_safe_channel",
      v25);
    goto LABEL_6;
  }
  if ( !HIDWORD(v70) )
    goto LABEL_6;
  valid_chans_from_range = policy_mgr_get_valid_chans_from_range(
                             v21[2703],
                             s,
                             (unsigned int *)&v70 + 1,
                             v22,
                             *(unsigned __int8 *)(a1 + 12),
                             v26,
                             v27,
                             v28,
                             v29,
                             v30,
                             v31,
                             v32,
                             v33);
  if ( valid_chans_from_range || !HIDWORD(v70) )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: failed to get valid channel: %d len %d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "wlansap_get_safe_channel",
      valid_chans_from_range,
      HIDWORD(v70));
    goto LABEL_6;
  }
  hdd_remove_vlp_depriority_channels(
    v21[2704],
    (__int64)s,
    (unsigned int *)&v70 + 1,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42);
  is_5ghz_ch_freq = wlansap_select_chan_with_best_bandwidth(a1, s, HIDWORD(v70), &v70, a2);
  if ( !(_DWORD)is_5ghz_ch_freq )
    goto LABEL_47;
  if ( !HIDWORD(v70) )
  {
    v58 = s[0];
    LODWORD(v70) = s[0];
    goto LABEL_46;
  }
  v56 = 0;
  v57 = 0;
  v58 = 0;
  v59 = 0;
  v60 = 0;
  v61 = 0;
  do
  {
    if ( v60 )
    {
      if ( v57 > 0x65 )
        goto LABEL_49;
      if ( v56 > 0x197 )
      {
LABEL_48:
        __break(1u);
LABEL_49:
        __break(0x5512u);
        return wlansap_select_chan_with_best_bandwidth(is_5ghz_ch_freq, v44, v45, v46, v47);
      }
    }
    else
    {
      if ( v57 >= 0x66 )
        goto LABEL_49;
      is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(s[v56 / 4]);
      if ( (is_5ghz_ch_freq & 1) == 0 )
        goto LABEL_26;
      is_5ghz_ch_freq = wlan_reg_is_dfs_in_secondary_list_for_freq(
                          v21[2704],
                          s[v56 / 4],
                          v62,
                          v63,
                          v64,
                          v65,
                          v66,
                          v67,
                          v68,
                          v69);
      if ( (is_5ghz_ch_freq & 1) != 0 )
      {
        if ( !v61 )
          v61 = s[v56 / 4];
LABEL_26:
        v60 = 0;
        if ( v56 > 0x197 )
          goto LABEL_48;
        goto LABEL_29;
      }
      v60 = s[v56 / 4];
      if ( v56 > 0x197 )
        goto LABEL_48;
    }
LABEL_29:
    is_5ghz_ch_freq = wlan_reg_is_6ghz_chan_freq(s[v56 / 4]);
    if ( (is_5ghz_ch_freq & 1) != 0 )
    {
      if ( !v59 )
        v59 = s[v56 / 4];
      is_5ghz_ch_freq = wlan_reg_is_6ghz_psc_chan_freq(s[v56 / 4], v48, v49, v50, v51, v52, v53, v54, v55);
      if ( (is_5ghz_ch_freq & 1) != 0 && !v58 )
        v58 = s[v56 / 4];
    }
    ++v57;
    v56 += 4LL;
  }
  while ( v57 < HIDWORD(v70) );
  LODWORD(v70) = s[0];
  if ( v58 )
  {
    LODWORD(v70) = v58;
  }
  else if ( v59 )
  {
    LODWORD(v70) = v59;
    v58 = v59;
  }
  else if ( v60 )
  {
    LODWORD(v70) = v60;
    v58 = v60;
  }
  else if ( v61 )
  {
    v58 = v61;
    LODWORD(v70) = v61;
  }
  else
  {
    v58 = s[0];
  }
LABEL_46:
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: select %d from valid channel list, pref band = %d",
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    "wlansap_get_safe_channel",
    v58,
    2);
LABEL_47:
  result = (unsigned int)v70;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
