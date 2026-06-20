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
  __int64 *v14; // x26
  __int64 v15; // x20
  __int64 result; // x0
  __int64 v17; // x20
  const char *v18; // x2
  unsigned int v19; // w22
  unsigned int *v20; // x27
  _BOOL8 is_sub_20_mhz_enabled; // x0
  __int64 v22; // x1
  __int64 v23; // x2
  __int64 v24; // x3
  unsigned int *v25; // x22
  unsigned int v26; // w23
  bool is_24ghz_ch_freq; // w8
  unsigned int v28; // w9
  unsigned int v29; // w10
  unsigned int v30; // w11
  unsigned int vht_ch_width; // w25
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x0
  __int64 v41; // x4
  bool v42; // w8
  char v43; // w8
  _DWORD *v44; // x14
  unsigned __int64 v45; // x8
  unsigned int *v46; // x16
  unsigned int v47; // w14
  __int64 v48; // x16
  __int64 v49; // x17
  __int64 v50; // x14
  const char *v51; // x2
  const char *v52; // x3
  __int64 v53; // x5
  int eht_ch_width; // w0
  unsigned int v55; // w8
  unsigned int v56; // w0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int v65; // w20
  unsigned int v66; // w1
  __int64 v67; // x0
  __int64 v68; // x28
  unsigned int v69; // w25
  _BOOL8 v70; // x0
  __int64 v71; // x1
  __int64 v72; // x2
  __int64 v73; // x3
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x0
  int v83; // w0
  unsigned int v84; // w8
  unsigned int v85; // w0
  unsigned int v86; // w1
  __int64 v87; // x0
  __int64 v88; // [xsp+0h] [xbp-20h] BYREF
  __int64 v89; // [xsp+8h] [xbp-18h]
  __int64 v90; // [xsp+10h] [xbp-10h]
  __int64 v91; // [xsp+18h] [xbp-8h]

  v91 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(__int64 **)(a1 + 24);
  v89 = 0;
  v90 = 0;
  v88 = 0;
  if ( curr_con_mode != 4 && (policy_mgr_is_sta_mon_concurrency(*v14) & 1) == 0 )
  {
    v18 = "%s: Not supported, device is not in monitor mode";
LABEL_11:
    qdf_trace_msg(0x33u, 2u, v18, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_hdd_validate_mon_params", v88);
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
        "wlan_hdd_validate_mon_params",
        v88,
        v89,
        v90,
        v91);
      wlan_hdd_validate_mon_params___last_ticks = v17;
    }
    goto LABEL_12;
  }
  if ( *(_BYTE *)(a1 + 52194) == 1 )
  {
    v15 = jiffies;
    if ( wlan_hdd_validate_mon_params___last_ticks_198 - jiffies + 125 < 0 )
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
        "wlan_hdd_validate_mon_params",
        v88,
        v89,
        v90,
        v91);
      wlan_hdd_validate_mon_params___last_ticks_198 = v15;
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
      v25 = a2 + 4;
      if ( a2 != (unsigned int *)-16LL )
      {
        if ( *v25 )
        {
          v26 = result;
          is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*v25);
          result = v26;
          if ( is_24ghz_ch_freq
            || (v42 = wlan_reg_is_24ghz_ch_freq(*a2), result = v26, !v42)
            && (v43 = policy_mgr_mon_sbs_mac0_freq(**(_QWORD **)(a1 + 24), *v25), result = v26, (v43 & 1) != 0) )
          {
            v28 = a2[1];
            v29 = a2[4];
            v30 = a2[5];
            a2[4] = *a2;
            a2[5] = v28;
            *a2 = v29;
            a2[1] = v30;
          }
        }
      }
      if ( a1 )
      {
        if ( (*(_QWORD *)(a1 + 1640) & 1) == 0 || (v44 = (_DWORD *)(a1 + 52840), a1 == -52840) )
        {
          if ( (*(_QWORD *)(a1 + 1640) & 2) == 0 || (v44 = (_DWORD *)(a1 + 58928), a1 == -58928) )
            v44 = (_DWORD *)((a1 + 65016) & ((__int64)(*(_QWORD *)(a1 + 1640) << 61) >> 63));
        }
        if ( v44 && a3 )
        {
          v45 = 0;
          do
          {
            v46 = &a2[4 * v45];
            v44[20] = *v46;
            v44[21] = v46[1];
            v47 = 73 * ((unsigned int)((_DWORD)v44 - *v44 - 52840) >> 3) + 1;
            if ( (unsigned __int8)v47 > 2u )
              break;
            v48 = (unsigned __int8)v47;
            v44 = nullptr;
            v49 = a1 + 52840 + 6088LL * (unsigned int)v48;
            do
            {
              if ( v44 )
                break;
              v50 = *(_QWORD *)(a1 + 1640) >> v48++;
              v44 = (_DWORD *)((v50 << 63 >> 63) & v49);
              v49 += 6088;
            }
            while ( v48 != 3 );
            if ( !v44 )
              break;
            ++v45;
          }
          while ( v45 < a3 );
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
      v41 = *a2;
      v53 = a2[4];
      v51 = "%s: freq1 %d freq2 %d combo not allowed";
      v52 = "wlan_hdd_validate_mon_params";
      goto LABEL_60;
    }
  }
  if ( !*a2 )
    goto LABEL_28;
  v20 = a2 + 1;
  v19 = a2[1];
  if ( v19 > 7
    || !(is_sub_20_mhz_enabled = cds_is_sub_20_mhz_enabled(a4, a5, a6, a7, a8, a9, a10, a11)) && v19 - 7 > 0xFFFFFFFD )
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
      v19,
      v88);
    goto LABEL_12;
  }
  vht_ch_width = sme_get_vht_ch_width(is_sub_20_mhz_enabled, v22, v23, v24);
  v40 = qdf_trace_msg(
          0x33u,
          8u,
          "%s: max fw BW %d ch width %d",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "wlan_hdd_validate_mon_params",
          vht_ch_width,
          v19,
          v88,
          v89,
          v90,
          v91);
  if ( v19 == 3 && vht_ch_width < 2 )
  {
LABEL_36:
    v41 = 3;
LABEL_59:
    v51 = "%s: FW does not support this BW %d max BW supported %d";
    v52 = "wlan_hdd_validate_mon_params";
    v53 = vht_ch_width;
LABEL_60:
    qdf_trace_msg(0x33u, 2u, v51, a4, a5, a6, a7, a8, a9, a10, a11, v52, v41, v53, v88);
    goto LABEL_12;
  }
  if ( v19 == 4 && vht_ch_width < 3 )
  {
LABEL_58:
    v41 = 4;
    goto LABEL_59;
  }
  eht_ch_width = sme_get_eht_ch_width(v40);
  if ( eht_ch_width == 2 )
    v53 = 3;
  else
    v53 = 2;
  if ( eht_ch_width == 4 )
    v55 = 7;
  else
    v55 = v53;
  if ( v55 < v19 )
  {
LABEL_68:
    v51 = "%s: FW does not support this BW %d max BW supported %d";
    v52 = "hdd_is_target_eht_phy_ch_width_supported";
    v41 = v19;
    goto LABEL_60;
  }
  v56 = hdd_validate_channel_and_bandwidth(a1, *a2, 0, a2[1], a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !v56 )
  {
    v66 = *a2;
    v67 = v14[1];
    LODWORD(v88) = a2[1];
    wlan_reg_set_channel_params_for_pwrmode(v67, v66, 0, (__int64)&v88, 0, v57, v58, v59, v60, v61, v62, v63, v64);
    if ( (_DWORD)v88 == 8 )
    {
LABEL_75:
      v18 = "%s: Invalid capture channel or bandwidth for a country";
      goto LABEL_11;
    }
    if ( a3 != 1 )
    {
      v20 = a2 + 5;
      v68 = a3 - 1LL;
      while ( *(v20 - 1) )
      {
        v19 = *v20;
        v69 = *v20 - 7;
        if ( *v20 > 7 )
          goto LABEL_27;
        v70 = cds_is_sub_20_mhz_enabled(a4, a5, a6, a7, a8, a9, a10, a11);
        if ( !v70 && v69 >= 0xFFFFFFFE )
          goto LABEL_27;
        vht_ch_width = sme_get_vht_ch_width(v70, v71, v72, v73);
        v82 = qdf_trace_msg(
                0x33u,
                8u,
                "%s: max fw BW %d ch width %d",
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                v80,
                v81,
                "wlan_hdd_validate_mon_params",
                vht_ch_width,
                v19);
        if ( v19 == 3 && vht_ch_width < 2 )
          goto LABEL_36;
        if ( v19 == 4 && vht_ch_width <= 2 )
          goto LABEL_58;
        v83 = sme_get_eht_ch_width(v82);
        if ( v83 == 2 )
          v53 = 3;
        else
          v53 = 2;
        if ( v83 == 4 )
          v84 = 7;
        else
          v84 = v53;
        if ( v84 < v19 )
          goto LABEL_68;
        v85 = hdd_validate_channel_and_bandwidth(a1, *(v20 - 1), 0, *v20, a4, a5, a6, a7, a8, a9, a10, a11);
        if ( v85 )
        {
          v65 = v85;
          a2 = v20 - 1;
          goto LABEL_73;
        }
        v86 = *(v20 - 1);
        v87 = v14[1];
        LODWORD(v88) = *v20;
        wlan_reg_set_channel_params_for_pwrmode(v87, v86, 0, (__int64)&v88, 0, v57, v58, v59, v60, v61, v62, v63, v64);
        if ( (_DWORD)v88 == 8 )
          goto LABEL_75;
        result = 0;
        --v68;
        v20 += 4;
        if ( !v68 )
          goto LABEL_29;
      }
    }
    result = 0;
    goto LABEL_29;
  }
  v65 = v56;
LABEL_73:
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Invalid CH %d and BW %d combo",
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    "wlan_hdd_validate_mon_params",
    *a2,
    *v20);
  result = v65;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
