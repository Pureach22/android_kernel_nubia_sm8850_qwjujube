__int64 __fastcall wlansap_extend_to_acs_range(
        __int64 a1,
        unsigned int *a2,
        unsigned int *a3,
        _DWORD *a4,
        _DWORD *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v14; // w24
  unsigned int v19; // w24
  unsigned int v20; // w8
  unsigned int v21; // w22
  unsigned int v22; // w0
  __int64 result; // x0
  unsigned int v24; // w22
  unsigned int v25; // w22
  unsigned int v26; // w22
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w25
  unsigned int v36; // w25
  unsigned int v37; // w8
  unsigned int v38; // w23
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int v47; // w0
  unsigned int v48; // w23
  unsigned int v49; // w23
  unsigned int v50; // w23
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int v59; // w0
  __int64 v60; // x4
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 v78; // x0

  if ( !a1 )
    return qdf_trace_msg(
             0x39u,
             2u,
             "%s: Invalid mac_ctx",
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             "wlansap_extend_to_acs_range");
  v14 = *a2;
  if ( v14 <= (unsigned int)wlan_reg_ch_to_freq(0xDu) )
  {
    *a4 = 0;
    v24 = *a2;
    if ( v24 > (unsigned int)wlan_reg_ch_to_freq(4u) )
    {
      v21 = *a2 - 20;
      goto LABEL_19;
    }
    v22 = 0;
    goto LABEL_16;
  }
  v19 = *a2;
  if ( v19 <= (unsigned int)wlan_reg_ch_to_freq(0x29u) )
  {
    *a4 = 14;
    v25 = *a2 - 60;
    if ( v25 > (unsigned int)wlan_reg_ch_to_freq(0xEu) )
    {
      v21 = *a2 - 60;
      goto LABEL_19;
    }
    v22 = 14;
    goto LABEL_16;
  }
  if ( wlan_reg_is_6ghz_chan_freq(*a2) )
  {
    v20 = *a2;
    *a4 = 42;
    v21 = v20 - 60;
    if ( v20 - 60 > (unsigned int)wlan_reg_ch_to_freq(0x2Au) )
      goto LABEL_19;
    v22 = 42;
LABEL_16:
    v21 = wlan_reg_ch_to_freq(v22);
    goto LABEL_19;
  }
  *a4 = 0;
  v26 = *a2;
  if ( v26 <= (unsigned int)wlan_reg_ch_to_freq(4u) )
    v21 = wlan_reg_ch_to_freq(0);
  else
    v21 = *a2 - 20;
  qdf_trace_msg(
    0x39u,
    2u,
    "%s: unexpected start freq %d",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "wlansap_extend_to_acs_range");
LABEL_19:
  v35 = *a3;
  if ( v35 <= (unsigned int)wlan_reg_ch_to_freq(0xDu) )
  {
    *a5 = 13;
    v48 = *a3 + 20;
    if ( v48 <= (unsigned int)wlan_reg_ch_to_freq(0xDu) )
    {
      v38 = *a3 + 20;
      goto LABEL_35;
    }
    v47 = 13;
    goto LABEL_28;
  }
  v36 = *a3;
  if ( v36 <= (unsigned int)wlan_reg_ch_to_freq(0x29u) )
  {
    *a5 = 41;
    v49 = *a3 + 60;
    if ( v49 <= (unsigned int)wlan_reg_ch_to_freq(0x29u) )
    {
      v38 = *a3 + 60;
      goto LABEL_35;
    }
    v47 = 41;
    goto LABEL_28;
  }
  if ( !wlan_reg_is_6ghz_chan_freq(*a3) )
  {
    *a5 = 41;
    v50 = *a3 + 60;
    if ( v50 <= (unsigned int)wlan_reg_ch_to_freq(0x29u) )
    {
      v60 = *a3;
      v38 = v60 + 60;
    }
    else
    {
      v59 = wlan_reg_ch_to_freq(0x29u);
      v60 = *a3;
      v38 = v59;
    }
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: unexpected end freq %d",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "wlansap_extend_to_acs_range",
      v60);
    goto LABEL_35;
  }
  v37 = *a3;
  *a5 = 101;
  v38 = v37 + 60;
  if ( v37 + 60 > (unsigned int)wlan_reg_ch_to_freq(0x65u) )
  {
    v47 = 101;
LABEL_28:
    v38 = wlan_reg_ch_to_freq(v47);
  }
LABEL_35:
  *a2 = v21;
  *a3 = v38;
  if ( (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21632), *a2, v39, v40, v41, v42, v43, v44, v45, v46) & 1) != 0 )
  {
    v69 = *(_QWORD *)(a1 + 21632);
    while ( (wlan_reg_is_dfs_for_freq(v69, v21, v61, v62, v63, v64, v65, v66, v67, v68) & 1) == 0 && v21 < *a2 )
    {
      v69 = *(_QWORD *)(a1 + 21632);
      v21 += 20;
    }
    *a2 = v21;
  }
  result = wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21632), *a3, v61, v62, v63, v64, v65, v66, v67, v68);
  if ( (result & 1) != 0 )
  {
    v78 = *(_QWORD *)(a1 + 21632);
    while ( 1 )
    {
      result = wlan_reg_is_dfs_for_freq(v78, v38, v70, v71, v72, v73, v74, v75, v76, v77);
      if ( (result & 1) != 0 || v38 <= *a3 )
        break;
      v78 = *(_QWORD *)(a1 + 21632);
      v38 -= 20;
    }
    *a3 = v38;
  }
  return result;
}
