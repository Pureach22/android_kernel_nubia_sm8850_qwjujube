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
  __int64 v13; // x24
  __int64 v14; // x0
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int8 *v24; // x25
  __int64 v25; // x20
  __int64 v26; // x20
  unsigned int v27; // w26
  unsigned __int16 bw_value; // w21
  unsigned __int8 v29; // w0
  int v30; // w0
  __int64 v31; // x8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  int v40; // w23
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // w8
  __int64 v50; // x4
  char v51; // w27
  unsigned __int8 channel_reg_power_for_freq; // w0
  __int64 v53; // x8
  char v54; // w22
  char is_6g_psd_power; // w0
  unsigned int num_pwr_levels; // w0
  __int64 v57; // x19
  unsigned __int64 v58; // x26
  char v59; // w9
  __int64 v60; // x22
  int v61; // w25
  char v62; // w3
  unsigned __int64 v63; // x23
  int v64; // w8
  unsigned __int8 v65; // w8
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned int v74; // w21
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int16 v83; // w8
  int v84; // w22
  __int64 v85; // x24
  __int64 cmpt_obj; // x0
  unsigned __int64 v87; // x8
  __int64 v88; // x28
  int v89; // w10
  __int64 v90; // x0
  int v91; // w8
  __int16 v92; // w6
  __int64 v93; // x5
  unsigned int v94; // w19
  __int64 v95; // [xsp+0h] [xbp-A0h]
  unsigned int v96; // [xsp+14h] [xbp-8Ch]
  unsigned __int8 *v97; // [xsp+18h] [xbp-88h]
  unsigned int v98; // [xsp+20h] [xbp-80h]
  char v99; // [xsp+24h] [xbp-7Ch]
  __int64 v100; // [xsp+28h] [xbp-78h]
  bool is_6ghz_chan_freq; // [xsp+34h] [xbp-6Ch]
  __int64 v102; // [xsp+38h] [xbp-68h]
  _DWORD *v103; // [xsp+40h] [xbp-60h]
  unsigned int v104; // [xsp+4Ch] [xbp-54h]
  __int64 v105; // [xsp+50h] [xbp-50h]
  char v106; // [xsp+5Ch] [xbp-44h]
  char v107; // [xsp+60h] [xbp-40h]
  char v108[4]; // [xsp+64h] [xbp-3Ch] BYREF
  int v109; // [xsp+68h] [xbp-38h] BYREF
  __int64 v110; // [xsp+6Ch] [xbp-34h]
  int v111; // [xsp+74h] [xbp-2Ch]
  unsigned int v112; // [xsp+78h] [xbp-28h] BYREF
  __int16 v113; // [xsp+7Ch] [xbp-24h] BYREF
  __int16 v114[2]; // [xsp+80h] [xbp-20h] BYREF
  char v115[4]; // [xsp+84h] [xbp-1Ch] BYREF
  _WORD v116[2]; // [xsp+88h] [xbp-18h] BYREF
  _BYTE v117[4]; // [xsp+8Ch] [xbp-14h] BYREF
  __int16 v118[2]; // [xsp+90h] [xbp-10h] BYREF
  unsigned __int16 v119; // [xsp+94h] [xbp-Ch] BYREF
  __int64 v120; // [xsp+98h] [xbp-8h]

  v13 = a2;
  v120 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a2 + 16);
  v117[0] = 0;
  v116[0] = 0;
  *(_WORD *)v115 = 0;
  v114[0] = 0;
  v113 = 0;
  v112 = 0;
  v110 = 0;
  v108[0] = 0;
  result = wlan_vdev_mlme_get_cmpt_obj(v14, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !result )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: vdev component object is NULL",
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               "lim_calculate_tpc");
    goto LABEL_94;
  }
  v24 = (unsigned __int8 *)(v13 + 7184);
  if ( *(_BYTE *)(v13 + 10070) == 1 )
  {
    v25 = jiffies;
    if ( lim_calculate_tpc___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: STA operates in 6 GHz power of SAP, do not update STA power",
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 "lim_calculate_tpc");
      lim_calculate_tpc___last_ticks = v25;
    }
    goto LABEL_94;
  }
  v26 = result;
  v27 = *(_DWORD *)(v13 + 284);
  bw_value = wlan_reg_get_bw_value(*(_DWORD *)(v13 + 7176));
  v29 = *v24;
  v109 = *(_DWORD *)(v13 + 7176);
  v30 = wlan_reg_compute_6g_center_freq_from_cfi(v29);
  v31 = *(_QWORD *)(a1 + 21560);
  v111 = v30;
  wlan_reg_set_channel_params_for_pwrmode(v31, v27, 0, (__int64)&v109, 0, v32, v33, v34, v35, v36, v37, v38, v39);
  if ( v111 )
    v40 = v111;
  else
    v40 = HIDWORD(v110);
  v102 = a1;
  is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(v27);
  if ( is_6ghz_chan_freq )
  {
    if ( *(_DWORD *)(v13 + 88) != 2 )
    {
      v51 = 0;
      v103 = (_DWORD *)(v13 + 88);
LABEL_22:
      is_6g_psd_power = wlan_reg_is_6g_psd_power(*(_QWORD *)(a1 + 21560), v41, v42, v43, v44, v45, v46, v47, v48);
      v117[0] = is_6g_psd_power & 1;
LABEL_23:
      num_pwr_levels = lim_get_num_pwr_levels(
                         is_6g_psd_power & 1,
                         *(_DWORD *)(v13 + 7176),
                         v41,
                         v42,
                         v43,
                         v44,
                         v45,
                         v46,
                         v47,
                         v48);
      v50 = num_pwr_levels;
      v54 = 1;
      if ( num_pwr_levels >= 9 )
        goto LABEL_24;
      goto LABEL_18;
    }
    v49 = *(unsigned __int8 *)(v13 + 10069);
    v50 = *(unsigned __int8 *)(v26 + 533);
    v51 = v49 == 3;
    if ( (a3 & 1) != 0 )
      v49 = 2;
    v112 = v49;
    v103 = (_DWORD *)(v13 + 88);
    if ( !(_DWORD)v50 )
      goto LABEL_22;
  }
  else
  {
    channel_reg_power_for_freq = wlan_reg_get_channel_reg_power_for_freq(
                                   *(_QWORD *)(a1 + 21560),
                                   v27,
                                   v41,
                                   v42,
                                   v43,
                                   v44,
                                   v45,
                                   v46,
                                   v47,
                                   v48);
    v53 = *(_QWORD *)(a1 + 21552);
    v116[0] = channel_reg_power_for_freq;
    v51 = wlan_mlme_skip_tpe(v53);
    v103 = (_DWORD *)(v13 + 88);
    if ( *(_DWORD *)(v13 + 88) != 2 || (v50 = *(unsigned __int8 *)(v26 + 533), !*(_BYTE *)(v26 + 533)) )
    {
      is_6g_psd_power = v117[0];
      goto LABEL_23;
    }
  }
  v54 = 0;
  v117[0] = *(_BYTE *)(v26 + 528);
  if ( (unsigned int)v50 >= 9 )
  {
LABEL_24:
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: reset num_pwr_levels %d to MAX_NUM_PWR_LEVELS %d",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "lim_calculate_tpc");
    LODWORD(v50) = 8;
    goto LABEL_25;
  }
LABEL_18:
  if ( (_DWORD)v50 )
  {
LABEL_25:
    v104 = v27;
    v57 = 0;
    v58 = 0;
    v97 = (unsigned __int8 *)(v13 + 7184);
    v107 = v54 | !is_6ghz_chan_freq;
    v59 = v54 | v51;
    v60 = v102;
    v106 = v59;
    v61 = v40 - (bw_value >> 1) + 10;
    v96 = v50;
    v105 = (unsigned int)v50;
    v100 = v13;
    v99 = a3;
    while ( 1 )
    {
      v62 = v117[0];
      v63 = v26 + 4 * v58;
      if ( (v107 & 1) == 0 )
      {
        if ( v117[0] )
        {
          wlan_reg_get_client_power_for_connecting_ap(
            *(_QWORD *)(v60 + 21560),
            v112,
            *(_DWORD *)(v63 + 556),
            1,
            v116,
            v115,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48);
          v65 = v116[0];
          if ( !v116[0] )
            goto LABEL_46;
          goto LABEL_47;
        }
        wlan_reg_get_client_power_for_connecting_ap(
          *(_QWORD *)(v60 + 21560),
          v112,
          v104,
          0,
          v116,
          v115,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48);
LABEL_39:
        v65 = v116[0];
        if ( !v116[0] )
          goto LABEL_46;
        goto LABEL_47;
      }
      v64 = v104;
      if ( v117[0] )
        v64 = v61;
      *(_DWORD *)(v63 + 556) = v64;
      if ( !is_6ghz_chan_freq )
        goto LABEL_39;
      if ( *v103 == 2 )
      {
        wlan_reg_get_client_power_for_connecting_ap(
          *(_QWORD *)(v60 + 21560),
          v112,
          v64,
          v62,
          v116,
          v115,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48);
        v65 = v116[0];
        if ( !v116[0] )
          goto LABEL_46;
        goto LABEL_47;
      }
      if ( (a3 & 1) != 0 )
        break;
      LOWORD(v95) = 0;
      if ( (unsigned int)wlan_reg_decide_6ghz_power_within_bw_for_freq(
                           *(_QWORD *)(v60 + 21560),
                           v104,
                           *(unsigned int *)(v13 + 7176),
                           (__int64)v117,
                           v114,
                           &v113,
                           &v112,
                           0xFFFFFFFF,
                           v41,
                           v42,
                           v43,
                           v44,
                           v45,
                           v46,
                           v47,
                           v48) )
      {
        wlan_reg_get_cur_6g_ap_pwr_type(*(_QWORD *)(v60 + 21560), &v112, v66, v67, v68, v69, v70, v71, v72, v73);
        v64 = *(_DWORD *)(v63 + 556);
LABEL_45:
        wlan_reg_get_6g_chan_ap_power(
          *(_QWORD *)(v60 + 21560),
          v64,
          v117,
          v116,
          v115,
          a3 & 1,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48);
        v65 = v116[0];
        if ( !v116[0] )
          goto LABEL_46;
        goto LABEL_47;
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: get pwr attr from secondary list",
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        "lim_calculate_tpc",
        v95);
      v65 = v114[0];
      v116[0] = v114[0];
      *(_WORD *)v115 = v113;
      if ( !v114[0] )
      {
LABEL_46:
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Reg power due to invalid freq: %d",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "lim_calculate_tpc",
          *(unsigned int *)(v63 + 556),
          v95);
        v65 = *(_BYTE *)(v26 + 536);
        v116[0] = v65;
      }
LABEL_47:
      *(_BYTE *)(v26 + v58 + 536) = v65;
      *(_DWORD *)(v26 + v57 + 636) = *(_DWORD *)(v63 + 556);
      v74 = *(unsigned __int8 *)(v26 + 552);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: local constraint: %d power constraint absolute %d",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "lim_calculate_tpc",
        *(unsigned __int8 *)(v26 + 552),
        *(unsigned __int8 *)(v26 + 932),
        v95);
      if ( v117[0] == 1 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Reg psd power: %d",
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          "lim_calculate_tpc",
          *(unsigned __int16 *)v115);
        LOBYTE(v74) = v115[0];
        goto LABEL_56;
      }
      if ( *(_BYTE *)(v26 + 932) != 1 )
        goto LABEL_55;
      if ( !v74 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Ignore zero abs ap constraint power",
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          "lim_calculate_tpc");
LABEL_55:
        LOBYTE(v74) = v116[0];
        goto LABEL_56;
      }
      if ( v116[0] < v74 )
        LOBYTE(v74) = v116[0];
LABEL_56:
      *(_BYTE *)(v26 + 532) = v112;
      if ( (v106 & 1) == 0 )
      {
        if ( (v117[0] & 1) != 0 || (v83 = *(_WORD *)(v26 + 530)) == 0 )
          LOBYTE(v83) = *(_BYTE *)(v26 + v58 + 620);
        v84 = (char)v74;
        if ( (char)v74 >= (char)(v83 + ((unsigned __int8)(v83 & 0x80) >> 7)) >> 1 )
          LOBYTE(v74) = (char)(v83 + ((unsigned __int8)(v83 & 0x80) >> 7)) >> 1;
        qdf_trace_msg(0x35u, 8u, "%s: TPE: %d", v75, v76, v77, v78, v79, v80, v81, v82, "lim_calculate_tpc");
        wma_is_both_psd_eirp_support_present_for_sp(v26 + 528, v108);
        if ( v108[0] == 1 && *v103 == 2 )
        {
          v85 = *(_QWORD *)(v13 + 16);
          v119 = 0;
          v118[0] = 0;
          v98 = v112;
          cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v85, v75, v76, v77, v78, v79, v80, v81, v82);
          if ( cmpt_obj )
          {
            v87 = *(unsigned __int8 *)(cmpt_obj + 535);
            v88 = cmpt_obj;
            if ( v58 < *(unsigned __int8 *)(cmpt_obj + 534) )
            {
              v89 = (*(unsigned __int8 *)(cmpt_obj + v57 + 768) + (*(unsigned __int8 *)(cmpt_obj + v57 + 768) >> 7)) << 24 >> 25;
              if ( v89 >= v84 )
                LOBYTE(v89) = v84;
              *(_WORD *)(cmpt_obj + v57 + 768) = (unsigned __int8)v89;
            }
            v60 = v102;
            if ( v58 >= v87 )
              goto LABEL_86;
            v90 = *(_QWORD *)(v85 + 152);
            if ( !v90 )
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: pdev is NULL",
                v75,
                v76,
                v77,
                v78,
                v79,
                v80,
                v81,
                v82,
                "lim_update_both_eirp_psd");
              goto LABEL_86;
            }
            wlan_reg_get_client_power_for_connecting_ap(
              v90,
              v98,
              v104,
              0,
              &v119,
              v118,
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              v81,
              v82);
            if ( *(_BYTE *)(v88 + 932) == 1 )
            {
              v91 = *(unsigned __int8 *)(v88 + 552);
              if ( *(_BYTE *)(v88 + 552) )
              {
                if ( v119 < (unsigned int)v91 )
                  v91 = v119;
LABEL_82:
                if ( v58 > 4 )
                {
                  __break(0x5512u);
                  JUMPOUT(0x16581F8);
                }
                if ( (*(unsigned __int8 *)(v88 + v57 + 896) + (*(unsigned __int8 *)(v88 + v57 + 896) >> 7)) << 24 >> 25 < v91 )
                  LOBYTE(v91) = (*(unsigned __int8 *)(v88 + v57 + 896) + (*(unsigned __int8 *)(v88 + v57 + 896) >> 7)) << 24 >> 25;
                *(_WORD *)(v88 + v57 + 896) = (unsigned __int8)v91;
LABEL_86:
                v13 = v100;
                a3 = v99;
                goto LABEL_27;
              }
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: ignore zero ap constraint power",
                v75,
                v76,
                v77,
                v78,
                v79,
                v80,
                v81,
                v82,
                "lim_update_both_eirp_psd");
            }
            v91 = v119;
            goto LABEL_82;
          }
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: vdev component object is NULL",
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            "lim_update_both_eirp_psd");
          v60 = v102;
          goto LABEL_86;
        }
        v60 = v102;
      }
LABEL_27:
      *(_WORD *)(v26 + v57 + 640) = (unsigned __int8)v74;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: freq: %d reg power: %d, max_tx_power(eirp/psd): %d",
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        "lim_calculate_tpc",
        *(unsigned int *)(v63 + 556),
        v116[0]);
      ++v58;
      v61 += 20;
      v57 += 8;
      if ( v105 == v58 )
      {
        v24 = v97;
        v50 = v96;
        goto LABEL_88;
      }
    }
    v112 = 2;
    goto LABEL_45;
  }
LABEL_88:
  v92 = v116[0];
  v93 = v117[0];
  *(_BYTE *)(v26 + 533) = v50;
  *(_WORD *)(v26 + 530) = v92;
  *(_BYTE *)(v26 + 528) = v93;
  if ( v24[2885] == 8 )
    *(_BYTE *)(v26 + 933) = 1;
  if ( *v103 == 1 && (_DWORD)v93 )
  {
    v94 = v50;
    wlan_mlme_set_sap_psd_for_20mhz(*(_QWORD *)(v13 + 16), v115[0], v41, v42, v43, v44, v45, v46, v47, v48);
    v93 = v117[0];
    v50 = v94;
  }
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: num_pwr_levels: %d, is_psd_power: %d, total eirp_power: %d, ap_pwr_type: %d",
             v41,
             v42,
             v43,
             v44,
             v45,
             v46,
             v47,
             v48,
             "lim_calculate_tpc",
             v50,
             v93);
LABEL_94:
  _ReadStatusReg(SP_EL0);
  return result;
}
