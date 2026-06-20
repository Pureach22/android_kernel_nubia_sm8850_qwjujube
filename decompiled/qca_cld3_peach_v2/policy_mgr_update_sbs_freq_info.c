_DWORD *__fastcall policy_mgr_update_sbs_freq_info(
        _DWORD *result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w21
  _DWORD *v10; // x20
  void *v11; // x19
  int v12; // w8
  int v13; // w9
  unsigned int v14; // w22
  unsigned int v15; // w0
  unsigned int v16; // w8
  unsigned int *v17; // x21
  unsigned int v18; // w8
  _DWORD *v19; // x22
  unsigned int v20; // w0
  unsigned int v21; // w8
  unsigned int v22; // w8
  int v23; // w9
  int v24; // w8
  unsigned int v25; // w0
  unsigned int v26; // w0
  unsigned int v27; // w8
  unsigned int v28; // w8
  int v29; // w9
  int v30; // w8
  unsigned int v31; // w0
  unsigned int v32; // w8
  unsigned int v33; // w8
  unsigned int v34; // w0
  unsigned int v35; // w8
  unsigned int v36; // w8
  unsigned int v37; // w8
  unsigned int v38; // w8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  int v47; // w9
  int v48; // w8
  unsigned int v49; // w0
  unsigned int v50; // w8
  unsigned int v51; // w0
  unsigned int v52; // w8
  unsigned int v53; // w21
  unsigned int v54; // w8
  unsigned int v55; // w8
  unsigned int v56; // w8
  unsigned int v57; // w8
  __int64 v58; // [xsp+0h] [xbp-10h]
  __int64 v59; // [xsp+8h] [xbp-8h]

  v9 = *((unsigned __int16 *)result + 600);
  v10 = result;
  v11 = result + 317;
  if ( *((_WORD *)result + 600) )
  {
    v12 = result[317];
    v13 = result[318];
    v14 = v9 + 10;
    result[325] = v12;
    result[326] = v13;
    if ( v12 )
    {
      result[327] = v14;
      if ( (unsigned __int16)wlan_reg_max_6ghz_chan_freq() )
        v15 = (unsigned __int16)wlan_reg_max_6ghz_chan_freq();
      else
        v15 = wlan_reg_max_5ghz_chan_freq();
      v22 = v10[320];
      if ( v10[324] > v22 )
        v22 = v10[324];
      if ( !v22 )
        v22 = v15;
    }
    else
    {
      v20 = result[319];
      v21 = v10[323];
      if ( !v20 || v21 < v20 )
      {
        v20 = v10[323];
        if ( !v21 )
          v20 = wlan_reg_min_5ghz_chan_freq();
      }
      v22 = v9;
      v10[327] = v20;
    }
    v23 = v10[321];
    v10[328] = v22;
    v24 = v10[322];
    v10[329] = v23;
    v10[330] = v24;
    if ( v23 )
    {
      v10[331] = v14;
      if ( (unsigned __int16)wlan_reg_max_6ghz_chan_freq() )
        v25 = (unsigned __int16)wlan_reg_max_6ghz_chan_freq();
      else
        v25 = wlan_reg_max_5ghz_chan_freq();
      v28 = v10[320];
      if ( v10[324] > v28 )
        v28 = v10[324];
      if ( !v28 )
        v28 = v25;
    }
    else
    {
      v26 = v10[319];
      v27 = v10[323];
      if ( !v26 || v27 < v26 )
      {
        v26 = v10[323];
        if ( !v27 )
          v26 = wlan_reg_min_5ghz_chan_freq();
      }
      v28 = v9;
      v10[331] = v26;
    }
    v29 = v10[317];
    v10[332] = v28;
    v30 = v10[318];
    v10[333] = v29;
    v10[334] = v30;
    if ( v29 )
    {
      v31 = v10[319];
      v32 = v10[323];
      if ( !v31 || v32 < v31 )
      {
        v31 = v10[323];
        if ( !v32 )
          v31 = wlan_reg_min_5ghz_chan_freq();
      }
      v10[335] = v31;
      v33 = v9;
    }
    else
    {
      v10[335] = v14;
      if ( (unsigned __int16)wlan_reg_max_6ghz_chan_freq() )
        v34 = (unsigned __int16)wlan_reg_max_6ghz_chan_freq();
      else
        v34 = wlan_reg_max_5ghz_chan_freq();
      v33 = v10[320];
      if ( v10[324] > v33 )
        v33 = v10[324];
      if ( !v33 )
        v33 = v34;
    }
    v47 = v10[321];
    v10[336] = v33;
    v48 = v10[322];
    v10[337] = v47;
    v10[338] = v48;
    if ( v47 )
    {
      v49 = v10[319];
      v50 = v10[323];
      if ( !v49 || v50 < v49 )
      {
        v49 = v10[323];
        if ( !v50 )
          v49 = wlan_reg_min_5ghz_chan_freq();
      }
      v10[339] = v49;
      v10[340] = v9;
    }
    else
    {
      v10[339] = v14;
      if ( (unsigned __int16)wlan_reg_max_6ghz_chan_freq() )
        v51 = (unsigned __int16)wlan_reg_max_6ghz_chan_freq();
      else
        v51 = wlan_reg_max_5ghz_chan_freq();
      v52 = v10[320];
      if ( v10[324] > v52 )
        v52 = v10[324];
      if ( v52 )
        v53 = v52;
      else
        v53 = v51;
      v10[340] = v53;
    }
    return qdf_mem_set(v11, 0x20u, 0);
  }
  v16 = result[319];
  v17 = result + 319;
  if ( result[317] )
  {
    if ( !v16 )
    {
      v19 = result + 317;
LABEL_52:
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid DBS/SBS mode with only 2.4Ghz",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "policy_mgr_modify_sbs_freq");
      if ( *v19 | *v17 )
        qdf_trace_msg(
          0x4Fu,
          8u,
          "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "MODE_SBS",
          2,
          0,
          *v17,
          v19[3]);
      if ( v19[4] | v19[6] )
      {
        LODWORD(v59) = v19[7];
        LODWORD(v58) = v19[6];
        qdf_trace_msg(
          0x4Fu,
          8u,
          "PLCY_MGR_FREQ_RANGE: %s(%d): mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "MODE_SBS",
          2,
          1,
          v58,
          v59);
      }
      return qdf_mem_set(v11, 0x20u, 0);
    }
  }
  else if ( result[323] <= v16 )
  {
    if ( result[324] >= result[320] )
      goto LABEL_86;
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "%s: LOW 5Ghz shared",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "policy_mgr_modify_sbs_freq");
    v54 = v10[324];
    if ( v54 >= v10[319] )
    {
      v55 = v54 + 10;
      if ( v55 >= v10[320] )
        v55 = v10[320];
      v10[319] = v55;
    }
  }
  else
  {
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "%s: High 5Ghz shared",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "policy_mgr_modify_sbs_freq");
    v35 = v10[323];
    if ( v10[320] >= v35 )
    {
      v36 = v35 - 10;
      if ( v36 <= v10[319] )
        v36 = v10[319];
      v10[320] = v36;
    }
  }
  v18 = v10[323];
  if ( v10[321] )
  {
    if ( v18 )
      return result;
    v19 = v10 + 321;
    v17 = v10 + 323;
    goto LABEL_52;
  }
  if ( *v17 > v18 )
  {
    result = (_DWORD *)qdf_trace_msg(
                         0x4Fu,
                         8u,
                         "%s: High 5Ghz shared",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         "policy_mgr_modify_sbs_freq");
    v37 = v10[319];
    if ( v10[324] >= v37 )
    {
      v38 = v37 - 10;
      if ( v38 <= v10[323] )
        v38 = v10[323];
      v10[324] = v38;
    }
    return result;
  }
  if ( v10[320] >= v10[324] )
  {
LABEL_86:
    qdf_trace_msg(
      0x4Fu,
      4u,
      "%s: Invalid SBS range with all 5Ghz shared",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "policy_mgr_modify_sbs_freq");
    return qdf_mem_set(v11, 0x20u, 0);
  }
  result = (_DWORD *)qdf_trace_msg(
                       0x4Fu,
                       8u,
                       "%s: LOW 5Ghz shared",
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       "policy_mgr_modify_sbs_freq");
  v56 = v10[320];
  if ( v56 >= v10[323] )
  {
    v57 = v56 + 10;
    if ( v57 >= v10[324] )
      v57 = v10[324];
    v10[323] = v57;
  }
  return result;
}
