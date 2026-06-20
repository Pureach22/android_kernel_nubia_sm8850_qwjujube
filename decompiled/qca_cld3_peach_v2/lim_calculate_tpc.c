__int64 __fastcall lim_calculate_tpc(
        __int64 a1,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x28
  __int64 v13; // x0
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int8 *v23; // x22
  __int64 v24; // x20
  __int64 v25; // x20
  unsigned int v26; // w23
  unsigned __int16 bw_value; // w21
  unsigned __int8 v28; // w0
  int v29; // w0
  __int64 v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  int v39; // w19
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  int v48; // w8
  unsigned int v49; // w4
  char v50; // w25
  unsigned __int8 channel_reg_power_for_freq; // w0
  __int64 v52; // x8
  char v53; // w8
  char is_6g_psd_power; // w0
  unsigned int num_pwr_levels; // w0
  __int64 v56; // x23
  unsigned __int64 v57; // x26
  int v58; // w25
  char v59; // w3
  unsigned __int64 v60; // x21
  int v61; // w8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  unsigned __int8 v70; // w8
  bool v71; // cc
  unsigned int v72; // w19
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  unsigned __int8 v81; // w22
  __int16 v82; // w8
  int v83; // w24
  __int64 v84; // x19
  __int64 cmpt_obj; // x0
  unsigned __int64 v86; // x8
  __int64 v87; // x28
  int v88; // w10
  __int64 v89; // x0
  int v90; // w8
  __int16 v91; // w6
  __int64 v92; // x5
  unsigned __int8 *v93; // [xsp+8h] [xbp-98h]
  unsigned int v94; // [xsp+14h] [xbp-8Ch]
  __int64 v95; // [xsp+18h] [xbp-88h]
  __int64 v97; // [xsp+28h] [xbp-78h]
  bool is_6ghz_chan_freq; // [xsp+34h] [xbp-6Ch]
  _DWORD *v99; // [xsp+38h] [xbp-68h]
  unsigned int v100; // [xsp+44h] [xbp-5Ch]
  char v101; // [xsp+48h] [xbp-58h]
  char v102; // [xsp+4Ch] [xbp-54h]
  __int64 v103; // [xsp+50h] [xbp-50h]
  char v104[4]; // [xsp+5Ch] [xbp-44h] BYREF
  int v105; // [xsp+60h] [xbp-40h] BYREF
  __int64 v106; // [xsp+64h] [xbp-3Ch]
  __int64 v107; // [xsp+6Ch] [xbp-34h]
  __int64 v108; // [xsp+74h] [xbp-2Ch] BYREF
  __int16 v109; // [xsp+7Ch] [xbp-24h] BYREF
  __int16 v110[2]; // [xsp+80h] [xbp-20h] BYREF
  char v111[4]; // [xsp+84h] [xbp-1Ch] BYREF
  _WORD v112[2]; // [xsp+88h] [xbp-18h] BYREF
  _BYTE v113[4]; // [xsp+8Ch] [xbp-14h] BYREF
  __int16 v114[2]; // [xsp+90h] [xbp-10h] BYREF
  unsigned __int16 v115; // [xsp+94h] [xbp-Ch] BYREF
  __int64 v116; // [xsp+98h] [xbp-8h]

  v12 = a2;
  v116 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a2 + 16);
  v113[0] = 0;
  v112[0] = 0;
  *(_WORD *)v111 = 0;
  v110[0] = 0;
  v109 = 0;
  v108 = 0;
  v107 = 0;
  v106 = 0;
  v104[0] = 0;
  result = wlan_vdev_mlme_get_cmpt_obj(v13, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !result )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: vdev component object is NULL",
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               "lim_calculate_tpc");
    goto LABEL_97;
  }
  v23 = (unsigned __int8 *)(v12 + 7186);
  if ( *(_BYTE *)(v12 + 10070) == 1 )
  {
    v24 = jiffies;
    if ( lim_calculate_tpc___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: STA operates in 6 GHz power of SAP, do not update STA power",
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 "lim_calculate_tpc");
      lim_calculate_tpc___last_ticks = v24;
    }
    goto LABEL_97;
  }
  v25 = result;
  v26 = *(_DWORD *)(v12 + 284);
  bw_value = wlan_reg_get_bw_value(*(_DWORD *)(v12 + 7176));
  v28 = *v23;
  v105 = *(_DWORD *)(v12 + 7176);
  v29 = wlan_reg_compute_6g_center_freq_from_cfi(v28);
  v30 = *(_QWORD *)(a1 + 21632);
  LODWORD(v107) = v29;
  wlan_reg_set_channel_params_for_pwrmode(v30, v26, 0, (__int64)&v105, 0, v31, v32, v33, v34, v35, v36, v37, v38);
  if ( (_DWORD)v107 )
    v39 = v107;
  else
    v39 = HIDWORD(v106);
  is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(v26);
  if ( is_6ghz_chan_freq )
  {
    if ( *(_DWORD *)(v12 + 88) != 2 )
    {
      v50 = 0;
      v99 = (_DWORD *)(v12 + 88);
LABEL_21:
      is_6g_psd_power = wlan_reg_is_6g_psd_power(*(_QWORD *)(a1 + 21632), v40, v41, v42, v43, v44, v45, v46, v47);
      v113[0] = is_6g_psd_power & 1;
      goto LABEL_22;
    }
    v48 = *(unsigned __int8 *)(v12 + 10069);
    v49 = *(unsigned __int8 *)(v25 + 549);
    v50 = v48 == 3;
    if ( (a3 & 1) != 0 )
      v48 = 2;
    HIDWORD(v108) = v48;
    v99 = (_DWORD *)(v12 + 88);
    if ( !v49 )
      goto LABEL_21;
  }
  else
  {
    channel_reg_power_for_freq = wlan_reg_get_channel_reg_power_for_freq(
                                   *(_QWORD *)(a1 + 21632),
                                   v26,
                                   v40,
                                   v41,
                                   v42,
                                   v43,
                                   v44,
                                   v45,
                                   v46,
                                   v47);
    v52 = *(_QWORD *)(a1 + 21624);
    v112[0] = channel_reg_power_for_freq;
    v50 = wlan_mlme_skip_tpe(v52);
    v99 = (_DWORD *)(v12 + 88);
    if ( *(_DWORD *)(v12 + 88) != 2 || (v49 = *(unsigned __int8 *)(v25 + 549), !*(_BYTE *)(v25 + 549)) )
    {
      is_6g_psd_power = v113[0];
LABEL_22:
      num_pwr_levels = lim_get_num_pwr_levels(
                         is_6g_psd_power & 1,
                         *(_DWORD *)(v12 + 7176),
                         v40,
                         v41,
                         v42,
                         v43,
                         v44,
                         v45,
                         v46,
                         v47);
      if ( !num_pwr_levels )
      {
        v103 = 0;
        goto LABEL_91;
      }
      v49 = num_pwr_levels;
      v100 = v26;
      v53 = 1;
      v93 = (unsigned __int8 *)(v12 + 7186);
      goto LABEL_26;
    }
  }
  v93 = (unsigned __int8 *)(v12 + 7186);
  v100 = v26;
  v113[0] = *(_BYTE *)(v25 + 544);
  if ( v49 < 0x11 )
  {
    v53 = 0;
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: reset num_pwr_levels %d to MAX_NUM_PWR_LEVELS %d",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "lim_calculate_tpc");
    v53 = 0;
    v49 = 16;
  }
LABEL_26:
  v56 = 0;
  v103 = v49;
  v57 = 0;
  v97 = a1;
  v95 = v12;
  v101 = v53 | v50;
  v102 = v53 | !is_6ghz_chan_freq;
  v58 = v39 - (bw_value >> 1) + 10;
  do
  {
    v59 = v113[0];
    v60 = v25 + 4 * v57;
    if ( (v102 & 1) == 0 )
    {
      if ( v113[0] )
      {
        if ( v57 >= 0x10 )
          goto LABEL_98;
        wlan_reg_get_client_power_for_connecting_ap(
          *(_QWORD *)(a1 + 21632),
          HIDWORD(v108),
          *(_DWORD *)(v60 + 572),
          1,
          v112,
          v111,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47);
      }
      else
      {
        wlan_reg_get_client_power_for_connecting_ap(
          *(_QWORD *)(a1 + 21632),
          HIDWORD(v108),
          v100,
          0,
          v112,
          v111,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47);
      }
      goto LABEL_46;
    }
    if ( v113[0] )
    {
      v61 = v58;
      if ( v57 >= 0x10 )
        goto LABEL_98;
    }
    else
    {
      v61 = v100;
      if ( v57 > 0xF )
        goto LABEL_98;
    }
    *(_DWORD *)(v60 + 572) = v61;
    if ( !is_6ghz_chan_freq )
      goto LABEL_46;
    if ( *v99 == 2 )
    {
      wlan_reg_get_client_power_for_connecting_ap(
        *(_QWORD *)(a1 + 21632),
        HIDWORD(v108),
        v61,
        v59,
        v112,
        v111,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47);
      goto LABEL_46;
    }
    if ( (a3 & 1) != 0 )
    {
      HIDWORD(v108) = 2;
      goto LABEL_45;
    }
    if ( (unsigned int)wlan_reg_decide_6ghz_power_within_bw_for_freq(
                         *(_QWORD *)(a1 + 21632),
                         v100,
                         *(unsigned int *)(v12 + 7176),
                         (__int64)v113,
                         v110,
                         &v109,
                         (_DWORD *)&v108 + 1,
                         0xFFFFFFFF,
                         v40,
                         v41,
                         v42,
                         v43,
                         v44,
                         v45,
                         v46,
                         v47,
                         0) )
    {
      wlan_reg_get_cur_6g_ap_pwr_type(
        *(_QWORD *)(a1 + 21632),
        (unsigned int *)&v108 + 1,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69);
      v61 = *(_DWORD *)(v60 + 572);
LABEL_45:
      wlan_reg_get_6g_chan_ap_power(
        *(_QWORD *)(a1 + 21632),
        v61,
        v113,
        v112,
        v111,
        a3 & 1,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47);
LABEL_46:
      v70 = v112[0];
      v71 = v57 > 0xF;
      if ( v112[0] )
        goto LABEL_47;
      goto LABEL_50;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: get pwr attr from secondary list",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "lim_calculate_tpc");
    v70 = v110[0];
    v112[0] = v110[0];
    *(_WORD *)v111 = v109;
    v71 = v57 > 0xF;
    if ( v110[0] )
    {
LABEL_47:
      if ( v71 )
        goto LABEL_98;
      goto LABEL_52;
    }
LABEL_50:
    if ( v71 )
      goto LABEL_98;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Reg power due to invalid freq: %d",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "lim_calculate_tpc",
      *(unsigned int *)(v60 + 572));
    v70 = *(_BYTE *)(v25 + 552);
    v112[0] = v70;
LABEL_52:
    *(_BYTE *)(v25 + v57 + 552) = v70;
    *(_DWORD *)(v25 + v56 + 652) = *(_DWORD *)(v60 + 572);
    v72 = *(unsigned __int8 *)(v25 + 568);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: local constraint: %d power constraint absolute %d",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "lim_calculate_tpc",
      *(unsigned __int8 *)(v25 + 568),
      *(unsigned __int8 *)(v25 + 948));
    if ( v113[0] == 1 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Reg psd power: %d",
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        "lim_calculate_tpc",
        *(unsigned __int16 *)v111);
      v81 = v111[0];
      goto LABEL_61;
    }
    if ( *(_BYTE *)(v25 + 948) != 1 )
      goto LABEL_60;
    if ( !v72 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Ignore zero abs ap constraint power",
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        "lim_calculate_tpc");
LABEL_60:
      v81 = v112[0];
      goto LABEL_61;
    }
    if ( v112[0] >= v72 )
      v81 = v72;
    else
      v81 = v112[0];
LABEL_61:
    *(_BYTE *)(v25 + 548) = BYTE4(v108);
    if ( (v101 & 1) != 0 )
      goto LABEL_28;
    if ( (v113[0] & 1) != 0 || (v82 = *(_WORD *)(v25 + 546)) == 0 )
      LOBYTE(v82) = *(_BYTE *)(v25 + v57 + 636);
    v83 = (char)v81;
    if ( (char)v81 >= (char)(v82 + ((unsigned __int8)(v82 & 0x80) >> 7)) >> 1 )
      v81 = (char)(v82 + ((unsigned __int8)(v82 & 0x80) >> 7)) >> 1;
    qdf_trace_msg(0x35u, 8u, "%s: TPE: %d", v73, v74, v75, v76, v77, v78, v79, v80, "lim_calculate_tpc");
    wma_is_both_psd_eirp_support_present_for_sp(v25 + 544, v104);
    if ( v104[0] != 1 || *v99 != 2 )
    {
      a1 = v97;
      goto LABEL_28;
    }
    v84 = *(_QWORD *)(v12 + 16);
    v115 = 0;
    v114[0] = 0;
    v94 = HIDWORD(v108);
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v84, v73, v74, v75, v76, v77, v78, v79, v80);
    if ( cmpt_obj )
    {
      v86 = *(unsigned __int8 *)(cmpt_obj + 551);
      v87 = cmpt_obj;
      if ( v57 < *(unsigned __int8 *)(cmpt_obj + 550) )
      {
        v88 = (*(unsigned __int8 *)(cmpt_obj + v56 + 784) + (*(unsigned __int8 *)(cmpt_obj + v56 + 784) >> 7)) << 24 >> 25;
        if ( v88 >= v83 )
          LOBYTE(v88) = v83;
        *(_WORD *)(cmpt_obj + v56 + 784) = (unsigned __int8)v88;
      }
      a1 = v97;
      if ( v57 < v86 )
      {
        v89 = *(_QWORD *)(v84 + 216);
        if ( v89 )
        {
          wlan_reg_get_client_power_for_connecting_ap(
            v89,
            v94,
            v100,
            0,
            &v115,
            v114,
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            v80);
          if ( *(_BYTE *)(v87 + 948) == 1 )
          {
            v90 = *(unsigned __int8 *)(v87 + 568);
            if ( *(_BYTE *)(v87 + 568) )
            {
              if ( v115 < (unsigned int)v90 )
                v90 = v115;
              goto LABEL_85;
            }
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: ignore zero ap constraint power",
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              "lim_update_both_eirp_psd");
          }
          v90 = v115;
LABEL_85:
          if ( v57 > 4 )
LABEL_98:
            __break(0x5512u);
          if ( (*(unsigned __int8 *)(v87 + v56 + 912) + (*(unsigned __int8 *)(v87 + v56 + 912) >> 7)) << 24 >> 25 < v90 )
            LOBYTE(v90) = (*(unsigned __int8 *)(v87 + v56 + 912) + (*(unsigned __int8 *)(v87 + v56 + 912) >> 7)) << 24 >> 25;
          *(_WORD *)(v87 + v56 + 912) = (unsigned __int8)v90;
          goto LABEL_89;
        }
        qdf_trace_msg(0x35u, 2u, "%s: pdev is NULL", v73, v74, v75, v76, v77, v78, v79, v80, "lim_update_both_eirp_psd");
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: vdev component object is NULL",
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        "lim_update_both_eirp_psd");
      a1 = v97;
    }
LABEL_89:
    v12 = v95;
LABEL_28:
    *(_WORD *)(v25 + v56 + 656) = v81;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: freq: %d reg power: %d, max_tx_power(eirp/psd): %d",
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      "lim_calculate_tpc",
      *(unsigned int *)(v60 + 572),
      v112[0]);
    ++v57;
    v56 += 8;
    v58 += 20;
  }
  while ( v103 != v57 );
  v23 = v93;
LABEL_91:
  v91 = v112[0];
  v92 = v113[0];
  *(_BYTE *)(v25 + 549) = v103;
  *(_WORD *)(v25 + 546) = v91;
  *(_BYTE *)(v25 + 544) = v92;
  if ( v23[2883] == 8 )
    *(_BYTE *)(v25 + 949) = 1;
  if ( *v99 == 1 && (_DWORD)v92 )
  {
    wlan_mlme_set_sap_psd_for_20mhz(*(_QWORD *)(v12 + 16), v111[0], v40, v41, v42, v43, v44, v45, v46, v47);
    v92 = v113[0];
  }
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: num_pwr_levels: %d, is_psd_power: %d, total eirp_power: %d, ap_pwr_type: %d",
             v40,
             v41,
             v42,
             v43,
             v44,
             v45,
             v46,
             v47,
             "lim_calculate_tpc",
             v103,
             v92);
LABEL_97:
  _ReadStatusReg(SP_EL0);
  return result;
}
