__int64 __fastcall wlan_hdd_validate_mon_params(
        __int64 a1,
        unsigned int *a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 *v14; // x27
  __int64 v15; // x20
  __int64 result; // x0
  __int64 v17; // x20
  const char *v18; // x2
  unsigned int v19; // w24
  unsigned int *v20; // x28
  bool is_sub_20_mhz_enabled; // w0
  unsigned int *v22; // x22
  unsigned int v23; // w23
  bool is_24ghz_ch_freq; // w8
  unsigned int v25; // w9
  unsigned int v26; // w10
  unsigned int v27; // w11
  unsigned int vht_ch_width; // w25
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x4
  bool v38; // w8
  char v39; // w8
  _DWORD *v40; // x10
  _DWORD *v41; // x9
  unsigned __int64 v42; // x12
  bool v43; // cf
  const char *v44; // x2
  __int64 v45; // x5
  unsigned int v46; // w0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w19
  unsigned int v56; // w1
  __int64 v57; // x0
  __int64 v58; // x22
  bool v59; // w0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned int v68; // w0
  unsigned int v69; // w1
  __int64 v70; // x0
  _QWORD v71[3]; // [xsp+8h] [xbp-18h] BYREF

  v71[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(__int64 **)(a1 + 24);
  v71[0] = 0;
  v71[1] = 0;
  if ( curr_con_mode != 4 && (policy_mgr_is_sta_mon_concurrency(*v14) & 1) == 0 )
  {
    v18 = "%s: Not supported, device is not in monitor mode";
LABEL_11:
    qdf_trace_msg(0x33u, 2u, v18, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_hdd_validate_mon_params");
LABEL_12:
    result = 4294967274LL;
    goto LABEL_13;
  }
  if ( *(_DWORD *)(a1 + 40) != 6 )
  {
    v17 = jiffies;
    if ( wlan_hdd_validate_mon_params___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Not supported, adapter is not in monitor mode",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_hdd_validate_mon_params");
      wlan_hdd_validate_mon_params___last_ticks = v17;
    }
    goto LABEL_12;
  }
  if ( *(_BYTE *)(a1 + 52194) == 1 )
  {
    v15 = jiffies;
    if ( wlan_hdd_validate_mon_params___last_ticks_185 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: monitor mode vdev up in progress",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_hdd_validate_mon_params");
      wlan_hdd_validate_mon_params___last_ticks_185 = v15;
    }
    result = 4294967280LL;
    goto LABEL_13;
  }
  if ( a3 < 2u )
  {
    if ( !a3 )
    {
LABEL_28:
      result = 4294967274LL;
LABEL_29:
      v22 = a2 + 4;
      if ( a2 != (unsigned int *)-16LL )
      {
        if ( *v22 )
        {
          v23 = result;
          is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*v22);
          result = v23;
          if ( is_24ghz_ch_freq
            || (v38 = wlan_reg_is_24ghz_ch_freq(*a2), result = v23, !v38)
            && (v39 = policy_mgr_mon_sbs_mac0_freq(**(_QWORD **)(a1 + 24), *v22), result = v23, (v39 & 1) != 0) )
          {
            v25 = a2[1];
            v26 = a2[4];
            v27 = a2[5];
            a2[4] = *a2;
            a2[5] = v25;
            *a2 = v26;
            a2[1] = v27;
          }
        }
      }
      if ( a1 )
      {
        if ( (*(_QWORD *)(a1 + 1640) & 1) != 0 )
        {
          v40 = (_DWORD *)(a1 + 52832);
          if ( a1 != -52832 )
          {
            if ( a3 )
            {
              v41 = a2 + 1;
              v42 = 1;
              do
              {
                v40[20] = *(v41 - 1);
                v40[21] = *v41;
                if ( (unsigned __int8)~(-910593773 * ((unsigned int)((_DWORD)v40 - *v40 - 52832) >> 4)) )
                  break;
                v40 = (_DWORD *)(((__int64)(*(_QWORD *)(a1 + 1640) << 63) >> 63) & (a1 + 52832));
                if ( !v40 )
                  break;
                v43 = v42++ >= a3;
                v41 += 4;
              }
              while ( !v43 );
            }
          }
        }
      }
      goto LABEL_13;
    }
  }
  else if ( a2 != (unsigned int *)-16LL && a2[4] )
  {
    if ( (ucfg_dp_ml_mon_supported() & 1) == 0 )
    {
      v18 = "%s: ML monitor mode not supported";
      goto LABEL_11;
    }
    if ( curr_con_mode != 4 )
    {
      v18 = "%s: Curret mode is not Global monitor mode";
      goto LABEL_11;
    }
    if ( a2[1] == 7 || a2[5] == 7 )
    {
      v18 = "%s: 320MHz not supported in ML monitor mode";
      goto LABEL_11;
    }
    if ( (policy_mgr_2_freq_always_on_same_mac(**(_QWORD **)(a1 + 24), *a2, a2[4]) & 1) != 0 )
    {
      v37 = *a2;
      v45 = a2[4];
      v44 = "%s: freq1 %d freq2 %d combo not allowed";
      goto LABEL_54;
    }
  }
  if ( !*a2 )
    goto LABEL_28;
  v20 = a2 + 1;
  v19 = a2[1];
  if ( v19 > 6
    || (is_sub_20_mhz_enabled = cds_is_sub_20_mhz_enabled(a4, a5, a6, a7, a8, a9, a10, a11), v19 >= 5)
    && !is_sub_20_mhz_enabled )
  {
LABEL_27:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: invalid BW received %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_hdd_validate_mon_params",
      v19);
    goto LABEL_12;
  }
  vht_ch_width = sme_get_vht_ch_width();
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: max fw BW %d ch width %d",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "wlan_hdd_validate_mon_params",
    vht_ch_width,
    v19);
  if ( v19 == 3 && vht_ch_width < 2 )
  {
LABEL_36:
    v37 = 3;
LABEL_53:
    v44 = "%s: FW does not support this BW %d max BW supported %d";
    v45 = vht_ch_width;
LABEL_54:
    qdf_trace_msg(0x33u, 2u, v44, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_hdd_validate_mon_params", v37, v45);
    goto LABEL_12;
  }
  if ( v19 == 4 && vht_ch_width < 3 )
  {
LABEL_52:
    v37 = 4;
    goto LABEL_53;
  }
  v46 = hdd_validate_channel_and_bandwidth(a1, *a2, 0, a2[1], a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !v46 )
  {
    v56 = *a2;
    v57 = v14[1];
    LODWORD(v71[0]) = a2[1];
    wlan_reg_set_channel_params_for_pwrmode(v57, v56, 0, (__int64)v71, 0, v47, v48, v49, v50, v51, v52, v53, v54);
    if ( LODWORD(v71[0]) == 8 )
    {
LABEL_61:
      v18 = "%s: Invalid capture channel or bandwidth for a country";
      goto LABEL_11;
    }
    if ( a3 != 1 )
    {
      v20 = a2 + 5;
      v58 = a3 - 1LL;
      while ( *(v20 - 1) )
      {
        v19 = *v20;
        if ( *v20 > 6 )
          goto LABEL_27;
        v59 = cds_is_sub_20_mhz_enabled(a4, a5, a6, a7, a8, a9, a10, a11);
        if ( v19 >= 5 && !v59 )
          goto LABEL_27;
        vht_ch_width = sme_get_vht_ch_width();
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: max fw BW %d ch width %d",
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          "wlan_hdd_validate_mon_params",
          vht_ch_width,
          v19);
        if ( v19 == 3 && vht_ch_width < 2 )
          goto LABEL_36;
        if ( v19 == 4 && vht_ch_width <= 2 )
          goto LABEL_52;
        v68 = hdd_validate_channel_and_bandwidth(a1, *(v20 - 1), 0, *v20, a4, a5, a6, a7, a8, a9, a10, a11);
        if ( v68 )
        {
          v55 = v68;
          a2 = v20 - 1;
          goto LABEL_57;
        }
        v69 = *(v20 - 1);
        v70 = v14[1];
        LODWORD(v71[0]) = *v20;
        wlan_reg_set_channel_params_for_pwrmode(v70, v69, 0, (__int64)v71, 0, v47, v48, v49, v50, v51, v52, v53, v54);
        if ( LODWORD(v71[0]) == 8 )
          goto LABEL_61;
        result = 0;
        --v58;
        v20 += 4;
        if ( !v58 )
          goto LABEL_29;
      }
    }
    result = 0;
    goto LABEL_29;
  }
  v55 = v46;
LABEL_57:
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Invalid CH %d and BW %d combo",
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    "wlan_hdd_validate_mon_params",
    *a2,
    *v20);
  result = v55;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
