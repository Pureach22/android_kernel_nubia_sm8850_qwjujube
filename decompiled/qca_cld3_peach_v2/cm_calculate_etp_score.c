__int64 __fastcall cm_calculate_etp_score(__int64 a1, __int64 a2, unsigned __int8 *a3, int a4, char a5)
{
  _BOOL4 v9; // w27
  __int16 v10; // w8
  unsigned int v11; // w22
  unsigned int v12; // w20
  unsigned int v13; // w23
  unsigned int v14; // w8
  unsigned int v15; // w28
  __int64 is_24ghz_ch_freq; // x0
  __int64 v17; // x1
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w9
  int v27; // w8
  _BOOL4 v28; // w10
  unsigned int v29; // w11
  int v30; // w11
  int v31; // w20
  int v32; // w9
  unsigned int v33; // w24
  __int64 v34; // x8
  int v35; // w9
  int v36; // w23
  unsigned int v37; // w22
  int v38; // w11
  unsigned int v39; // w9
  int v40; // w8
  int v41; // w9
  int v42; // w13
  __int64 v43; // x12
  unsigned int v44; // w10
  int v45; // w23
  __int64 v46; // x27
  int v47; // w8
  __int64 v48; // x0
  __int64 v49; // x22
  __int64 v50; // x24
  int v51; // w26
  int v52; // w20
  int v53; // w19
  __int64 v54; // x25
  int v55; // w8
  int v56; // w8
  unsigned int v57; // w8
  unsigned int v58; // w27
  unsigned int v59; // w9
  unsigned int v60; // w8
  unsigned int v61; // w23
  char v62; // w14
  const char *v63; // x3
  int v64; // w25
  unsigned int v65; // w28
  int v66; // w8
  int max_amsdu_num; // w0
  int v68; // w14
  unsigned int v69; // w8
  bool v70; // zf
  int v71; // w15
  unsigned int v72; // w12
  unsigned int v73; // w8
  unsigned int v74; // w9
  unsigned int v75; // w10
  unsigned int v76; // w9
  unsigned int v77; // w28
  unsigned int v78; // w8
  __int64 v79; // x14
  int v80; // w9
  unsigned int v81; // w25
  unsigned int v82; // w26
  unsigned int v83; // w8
  const char *v84; // x3
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  unsigned int v93; // w8
  unsigned int v94; // w9
  int v95; // w9
  bool v96; // zf
  int v97; // w8
  __int64 v99; // [xsp+0h] [xbp-90h]
  __int64 v100; // [xsp+8h] [xbp-88h]
  __int64 v101; // [xsp+10h] [xbp-80h]
  unsigned int v102; // [xsp+50h] [xbp-40h]
  unsigned int v103; // [xsp+54h] [xbp-3Ch]
  unsigned int v104; // [xsp+58h] [xbp-38h]
  unsigned int v105; // [xsp+58h] [xbp-38h]
  unsigned int v106; // [xsp+5Ch] [xbp-34h]
  unsigned int v107; // [xsp+5Ch] [xbp-34h]
  unsigned int v108; // [xsp+60h] [xbp-30h]
  int v109; // [xsp+64h] [xbp-2Ch]
  int v110; // [xsp+64h] [xbp-2Ch]
  _BOOL4 v111; // [xsp+68h] [xbp-28h]
  int v112; // [xsp+6Ch] [xbp-24h]
  unsigned int v113; // [xsp+6Ch] [xbp-24h]
  unsigned int v115; // [xsp+70h] [xbp-20h]
  _BOOL4 v116; // [xsp+74h] [xbp-1Ch]
  int v117; // [xsp+78h] [xbp-18h]
  char v118[4]; // [xsp+7Ch] [xbp-14h] BYREF
  unsigned int v119; // [xsp+80h] [xbp-10h]
  char v120[4]; // [xsp+84h] [xbp-Ch] BYREF
  __int64 v121; // [xsp+88h] [xbp-8h]

  v9 = 0;
  v121 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *((_WORD *)a3 + 1);
  v118[0] = 0;
  if ( (v10 & 4) != 0 )
    v9 = *(_QWORD *)(a2 + 1696) != 0;
  if ( (v10 & 0x12) == 0
    || !*(_QWORD *)(a2 + 1560) && (wlan_reg_is_6ghz_chan_freq(*(unsigned int *)(a2 + 1192)) & 1) == 0 )
  {
    v117 = 0;
    if ( (*((_WORD *)a3 + 1) & 1) == 0 )
      goto LABEL_7;
LABEL_9:
    v116 = *(_QWORD *)(a2 + 1456) != 0;
    goto LABEL_10;
  }
  v117 = 1;
  if ( (*((_WORD *)a3 + 1) & 1) != 0 )
    goto LABEL_9;
LABEL_7:
  v116 = 0;
LABEL_10:
  v11 = *(_DWORD *)(a2 + 1192);
  v12 = *a3;
  v13 = a3[1];
  if ( (policy_mgr_is_chnl_in_diff_band(a1, v11) & 1) != 0
    && (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0
    && (policy_mgr_is_hw_dbs_2x2_capable(a1) & 1) == 0 )
  {
    v14 = 1;
  }
  else if ( (wlan_reg_is_24ghz_ch_freq(v11) & 1) != 0 )
  {
    v14 = v12;
  }
  else
  {
    v14 = v13;
  }
  if ( v14 >= *(unsigned __int8 *)(a2 + 84) )
    v15 = *(unsigned __int8 *)(a2 + 84);
  else
    v15 = v14;
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(unsigned int *)(a2 + 1192));
  v26 = *((unsigned __int16 *)a3 + 1);
  if ( (is_24ghz_ch_freq & 1) != 0 )
  {
    v27 = (v26 >> 7) & 1;
    v28 = (v26 & 0x10) == 0;
  }
  else if ( (v26 & 2) != 0 )
  {
    v27 = (v26 >> 6) & 1;
    v28 = 0;
  }
  else
  {
    v27 = 0;
    v28 = 1;
  }
  v29 = *(_DWORD *)(a2 + 52) - 7;
  if ( v29 > 0x21 )
    v30 = 0;
  else
    v30 = dword_AD1EA4[v29];
  v31 = *(unsigned __int8 *)(a2 + 82);
  v32 = ((int)(v26 << 31) >> 31) & v30;
  if ( v28 )
    v32 = v32 != 0;
  if ( v27 )
    v33 = v32;
  else
    v33 = 0;
  if ( *(_BYTE *)(a2 + 82) )
  {
    v34 = *(_QWORD *)(a2 + 1736);
    if ( v34 )
    {
      v35 = (*(unsigned __int8 *)(v34 + 6) >> 5) - 1;
      if ( (unsigned int)v35 > 6 )
        v36 = 1;
      else
        v36 = dword_AD1F2C[v35];
      v112 = 50 * *(unsigned __int8 *)(v34 + 8);
      is_24ghz_ch_freq = qdf_trace_msg(
                           0x68u,
                           8u,
                           "%s: esp ba_window_size: %d, ppdu_duration: %d",
                           v18,
                           v19,
                           v20,
                           v21,
                           v22,
                           v23,
                           v24,
                           v25,
                           "cm_calculate_etp_score");
      if ( !*(_QWORD *)(a2 + 1824) )
        goto LABEL_41;
      goto LABEL_44;
    }
    goto LABEL_38;
  }
  if ( *(_BYTE *)(a2 + 83) )
  {
    is_24ghz_ch_freq = qdf_trace_msg(
                         0x68u,
                         8u,
                         "%s: qbss_chan_load: %d",
                         v18,
                         v19,
                         v20,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25,
                         "cm_calculate_etp_score");
    v31 = *(unsigned __int8 *)(a2 + 83) ^ 0xFF;
LABEL_38:
    v36 = 32;
    goto LABEL_43;
  }
  v36 = 32;
  v31 = 127;
LABEL_43:
  v112 = 5000;
  if ( !*(_QWORD *)(a2 + 1824) )
  {
LABEL_41:
    v37 = 1;
    goto LABEL_45;
  }
LABEL_44:
  v37 = 2 * *(unsigned __int8 *)(a2 + 1918) + 2;
LABEL_45:
  if ( v33 - 5 < 2 )
    goto LABEL_142;
  if ( v9 )
  {
    if ( v33 - 1 > 6 )
      v38 = 234;
    else
      v38 = dword_AD1F64[v33 - 1] * dword_AD1F48[v33 - 1];
  }
  else
  {
    if ( v117 )
    {
      v39 = v33 - 1;
      if ( v33 - 1 >= 4 )
      {
        v41 = 1;
        v40 = 52;
      }
      else
      {
        v40 = dword_B35918[v39];
        v41 = dword_B35938[v39];
      }
    }
    else if ( v116 )
    {
      if ( v33 == 1 )
        v40 = 108;
      else
        v40 = 52;
      v41 = 1;
    }
    else
    {
      v41 = 1;
      v40 = 48;
    }
    v38 = v41 * v40;
  }
  v108 = v36;
  if ( v117 )
  {
    v42 = 4 * v15 + 36;
  }
  else if ( v116 )
  {
    v42 = 4 * v15 + 32;
  }
  else
  {
    v42 = 20;
  }
  v43 = *(_QWORD *)(a2 + 1456);
  v44 = 5000;
  v45 = *(char *)(a2 + 60);
  v111 = v9;
  if ( (*((_WORD *)a3 + 1) & 2) == 0 )
    goto LABEL_71;
  v46 = *(_QWORD *)(a2 + 1560);
  if ( !v46 )
    goto LABEL_71;
  v104 = v33;
  v106 = v37;
  v47 = a4;
  v48 = a1;
  v49 = *(_QWORD *)(a2 + 1696);
  v50 = *(_QWORD *)(a2 + 1456);
  v51 = v31;
  v52 = v42;
  v53 = v38;
  v109 = v47;
  v54 = v48;
  v119 = 0;
  is_24ghz_ch_freq = wlan_mlme_cfg_get_vht_rx_mcs_map();
  if ( (_DWORD)is_24ghz_ch_freq )
  {
    v43 = v50;
    v44 = 5000;
    v33 = v104;
    v37 = v106;
    v38 = v53;
    a1 = v54;
    v42 = v52;
    v31 = v51;
    a4 = v109;
LABEL_71:
    if ( v45 < -96 )
      goto LABEL_142;
    goto LABEL_72;
  }
  LOBYTE(v78) = v119;
  v79 = v49;
  if ( v15 == 2 )
  {
    v43 = v50;
    v33 = v104;
    v78 = v119 >> 2;
    v38 = v53;
    a1 = v54;
    v80 = *(unsigned __int16 *)(v46 + 6) >> 2;
    v42 = v52;
    v31 = v51;
  }
  else
  {
    v38 = v53;
    v42 = v52;
    v43 = v50;
    if ( v15 == 3 )
    {
      v33 = v104;
      v78 = v119 >> 4;
      a1 = v54;
      v31 = v51;
      v80 = *(unsigned __int16 *)(v46 + 6) >> 4;
    }
    else
    {
      v33 = v104;
      a1 = v54;
      v31 = v51;
      if ( v15 == 4 )
      {
        v78 = v119 >> 6;
        v80 = *(unsigned __int16 *)(v46 + 6) >> 6;
      }
      else
      {
        LOWORD(v80) = *(_WORD *)(v46 + 6);
      }
    }
  }
  v93 = v78 & 3;
  v94 = v80 & 3;
  v37 = v106;
  if ( v93 >= v94 )
    v93 = v94;
  if ( v79 )
  {
    if ( v93 == 1 )
      v95 = 7500;
    else
      v95 = 5000;
    v96 = v93 == 2;
    v97 = 8333;
  }
  else
  {
    if ( v93 == 1 )
      v95 = 6000;
    else
      v95 = 5000;
    v96 = v93 == 2;
    v97 = 6667;
  }
  a4 = v109;
  if ( v96 )
    v44 = v97;
  else
    v44 = v95;
  if ( v45 < -96 )
    goto LABEL_142;
LABEL_72:
  if ( v33 >= 3 )
    v55 = 3;
  else
    v55 = v33;
  v56 = -3 * v55 + v45 + 80;
  if ( v56 > 9 )
  {
    v58 = 334 * v56;
  }
  else
  {
    if ( v56 <= -10 )
      v56 = -10;
    v57 = v56 + 10;
    if ( v57 > 0x13 )
    {
      __break(1u);
      return cm_get_ch_width(is_24ghz_ch_freq, v17);
    }
    v58 = SNR_DB_TO_BIT_PER_TONE_LUT[v57];
  }
  if ( v58 >= v44 )
    v59 = v44;
  else
    v59 = v58;
  v60 = v38 * v15 * v59;
  if ( v111 )
    v61 = v60 / 0xE;
  else
    v61 = v60 >> 2;
  v62 = a5;
  if ( v61 > 0x3E7 )
  {
    v110 = a4;
    v103 = v38;
    v107 = v44;
    if ( v116 )
    {
      v64 = v42;
      v65 = 100;
      v66 = ((*(unsigned __int8 *)(v43 + 2) >> 2) & 7) - 1;
      if ( (unsigned int)v66 <= 6 )
        v65 = dword_AD1F80[v66];
      v120[0] = 0;
      max_amsdu_num = wlan_mlme_get_max_amsdu_num(a1, v120);
      v42 = v64;
      v68 = v112 - v64;
      v69 = v65 + 100 * (v112 - v64);
      v70 = v120[0] == 1 && max_amsdu_num == 0;
      v113 = v65;
      if ( v70 )
        v71 = 7935;
      else
        v71 = 3839;
      v105 = v68;
      v72 = (v69 - 1) / v65;
      v73 = v61 / 0x3E8;
      v74 = 8 * v71 + 208;
      v75 = v74 + v61 / 0x3E8 * v68;
      v62 = a5;
      v76 = (v75 - 1) / v74;
      if ( v72 < v76 )
        v76 = v72;
      v102 = v76;
      if ( v76 <= 1 )
        v76 = 1;
      if ( v108 >= v76 )
        v77 = v76;
      else
        v77 = v108;
    }
    else
    {
      v113 = 0;
      v77 = 1;
      v105 = 0;
      v71 = 1500;
      v102 = 0;
      v73 = v61 / 0x3E8;
    }
    v81 = v71;
    v115 = v42;
    v82 = v42 + 4 * ((4 * v73 + v77 * (8 * v71 + 208) - 1) / (4 * v73));
    v83 = (v82 + v77 * 8 * v71 - 1) / v82 * v31 / 0xFF;
    if ( v83 <= v37 )
      v83 = v37;
    if ( v83 >= 0x4E20 )
      v37 = 20000;
    else
      v37 = v83;
    if ( (v62 & 2) != 0 )
      v84 = "Candidate";
    else
      v84 = "Partner";
    qdf_trace_msg(
      0x68u,
      8u,
      "%s(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d HT %d VHT %d HE %d ATF %d NSS %d ch_width %d data_rate %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v84,
      *(unsigned __int8 *)(a2 + 1),
      *(unsigned __int8 *)(a2 + 2),
      *(unsigned __int8 *)(a2 + 3),
      *(unsigned __int8 *)(a2 + 6),
      *(_DWORD *)(a2 + 1192),
      *(char *)(a2 + 60),
      v116,
      v117,
      v111,
      v31,
      *(unsigned __int8 *)(a2 + 84),
      v33,
      v61);
    if ( v116 )
    {
      LODWORD(v99) = v108;
      qdf_trace_msg(
        0x68u,
        8u,
        "min_mpdu_ss_us_100x %d max_amsdu %d ppdu_payload_dur_us %d mpdu_per_ampdu %d mpdu_per_ppdu %d ba_window %d",
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v113,
        v81,
        v105,
        v102,
        v77,
        v99);
    }
    LODWORD(v101) = v37;
    LODWORD(v100) = v82;
    LODWORD(v99) = v81;
    qdf_trace_msg(
      0x68u,
      8u,
      "ETP score: ntone %d phy_hdr_dur_us %d max_bits_per_sc_1000x %d snr_tone_1000x %d mpdu_p_ppdu %d max_amsdu %d ppdu_"
      "dur_us %d TOTAL %d",
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v103,
      v115,
      v107,
      v58,
      v77,
      v99,
      v100,
      v101);
    a4 = v110;
  }
  else
  {
    if ( (a5 & 2) != 0 )
      v63 = "Candidate";
    else
      v63 = "Partner";
    qdf_trace_msg(
      0x68u,
      8u,
      "%s(%02x:%02x:%02x:**:**:%02x freq %d): data_rate_kbps %d is less than 1Mbps, so return score %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v63,
      *(unsigned __int8 *)(a2 + 1),
      *(unsigned __int8 *)(a2 + 2),
      *(unsigned __int8 *)(a2 + 3),
      *(unsigned __int8 *)(a2 + 6),
      *(_DWORD *)(a2 + 1192),
      v61,
      v37);
  }
LABEL_142:
  if ( (a4 & 0xFFFFFFFB) != 0 )
  {
    wlan_mlme_get_mlo_prefer_percentage(a1, v118);
    if ( v118[0] )
      v37 += (int)(v37 * v118[0]) / 100;
  }
  _ReadStatusReg(SP_EL0);
  return v37;
}
