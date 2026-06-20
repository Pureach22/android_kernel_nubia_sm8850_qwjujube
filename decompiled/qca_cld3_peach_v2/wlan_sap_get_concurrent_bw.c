__int64 __fastcall wlan_sap_get_concurrent_bw(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  unsigned int v8; // w21
  char is_sta_present_on_freq; // w22
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int ch_width; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  char is_dfs_for_freq; // w0
  char is_freq_indoor; // w26
  char v37; // w27
  char is_hw_dbs_capable; // w0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  const char *v55; // x2
  const char *v57; // x2
  int v58; // w8
  const char *v59; // x2
  _BYTE v60[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v61[4]; // [xsp+10h] [xbp-10h] BYREF
  int v62; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v63; // [xsp+18h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v62 = 0;
  v61[0] = 0;
  v60[0] = 0;
  if ( wlan_reg_is_24ghz_ch_freq(a3) || wlan_reg_is_6ghz_chan_freq(a3) )
    goto LABEL_14;
  v8 = (unsigned __int8)policy_mgr_mode_specific_connection_count(a2, 0, nullptr);
  is_sta_present_on_freq = policy_mgr_is_sta_present_on_freq(a2, v61, a3, &v62);
  if ( (is_sta_present_on_freq & 1) == 0 )
  {
    ch_width = 0;
LABEL_9:
    v37 = 0;
    is_freq_indoor = 0;
    goto LABEL_10;
  }
  ch_width = policy_mgr_get_ch_width(v62, v10, v11, v12, v13, v14, v15, v16, v17);
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: sta_chan_width:%d, channel_width:%d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "wlan_sap_get_concurrent_bw",
    ch_width,
    a4);
  is_dfs_for_freq = wlan_reg_is_dfs_for_freq(a1, a3, v27, v28, v29, v30, v31, v32, v33, v34);
  is_freq_indoor = 0;
  v37 = 1;
  if ( ch_width != 3 && (is_dfs_for_freq & 1) == 0 )
  {
    if ( wlan_reg_is_5ghz_ch_freq(a3) )
    {
      is_freq_indoor = wlan_reg_is_freq_indoor();
      v37 = 0;
      goto LABEL_10;
    }
    goto LABEL_9;
  }
LABEL_10:
  policy_mgr_get_sta_sap_scc_on_dfs_chnl(a2, v60);
  is_hw_dbs_capable = policy_mgr_is_hw_dbs_capable(a2);
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: sta_sap_scc_on_dfs_chnl:%d, is_hw_dbs_capable:%d, sta_count:%d, scc_sta_present:%d",
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    "wlan_sap_get_concurrent_bw",
    v60[0],
    is_hw_dbs_capable & 1,
    v8,
    is_sta_present_on_freq & 1);
  if ( (is_freq_indoor & 1) != 0 )
  {
    v55 = "%s: STA + SAP on indoor channels";
    if ( ch_width < a4 )
      a4 = ch_width;
    goto LABEL_13;
  }
  if ( (v37 & 1) != 0 )
  {
    if ( v60[0] == 1 )
    {
      if ( (is_sta_present_on_freq & 1) != 0 )
      {
        v57 = "%s: STA present: Limit the SAP channel width";
LABEL_31:
        qdf_trace_msg(0x39u, 8u, v57, v47, v48, v49, v50, v51, v52, v53, v54, "wlan_sap_get_concurrent_bw");
        if ( ch_width < a4 )
          a4 = ch_width;
        goto LABEL_14;
      }
      v59 = "%s: Limit Standalone SAP/GO to 80Mhz";
    }
    else
    {
      if ( v60[0] == 2 )
      {
        if ( (is_sta_present_on_freq & 1) != 0 )
        {
          v57 = "%s: STA+SAP/GO: limit the SAP channel width";
          goto LABEL_31;
        }
        v55 = "%s: Standalone SAP/GO: set BW coming in start req";
LABEL_13:
        qdf_trace_msg(0x39u, 8u, v55, v47, v48, v49, v50, v51, v52, v53, v54, "wlan_sap_get_concurrent_bw");
        goto LABEL_14;
      }
      if ( !v8 )
      {
        v55 = "%s: Single SAP/GO: set BW coming in SAP/GO start req";
        goto LABEL_13;
      }
      v59 = "%s: STA present, Limit SAP/GO to 80Mhz";
    }
    qdf_trace_msg(0x39u, 8u, v59, v47, v48, v49, v50, v51, v52, v53, v54, "wlan_sap_get_concurrent_bw");
    if ( a4 >= 2 )
      a4 = 2;
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: STA + SAP/GO or standalone SAP on active channel",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "wlan_sap_get_concurrent_bw");
    if ( (is_sta_present_on_freq & 1) != 0 )
    {
      if ( ch_width <= 2 )
        a4 = 2;
      else
        a4 = ch_width;
    }
    else
    {
      if ( a4 >= 2 )
        v58 = 2;
      else
        v58 = a4;
      if ( v8 )
        a4 = v58;
    }
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return a4;
}
