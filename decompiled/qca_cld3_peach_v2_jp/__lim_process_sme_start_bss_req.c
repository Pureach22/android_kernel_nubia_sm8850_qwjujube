__int64 __fastcall _lim_process_sme_start_bss_req(__int64 a1, __int64 a2)
{
  const void *v3; // x20
  unsigned __int8 *v4; // x0
  unsigned __int8 *v5; // x21
  unsigned int v6; // w20
  int opmode_from_vdev_id; // w23
  unsigned int v8; // w22
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w24
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w24
  __int64 result; // x0
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x22
  _BYTE *v46; // x26
  double started; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  int v55; // w8
  __int64 v56; // x0
  __int64 cmpt_obj; // x0
  __int64 v58; // x24
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w28
  unsigned int v68; // w25
  int v69; // w28
  int v70; // w27
  int v71; // w9
  __int64 v72; // x8
  int v73; // w8
  unsigned int v74; // w0
  unsigned int v75; // w8
  unsigned int v76; // w25
  unsigned int v77; // w24
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  char v86; // w9
  unsigned __int8 v87; // w8
  unsigned int v88; // w1
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  int v97; // w9
  __int64 v98; // x8
  char v99; // w9
  int param; // w24
  char v101; // w25
  int v102; // w0
  int v103; // w9
  int v104; // w8
  char v105; // w10
  bool v106; // w12
  bool v107; // w10
  unsigned int v108; // w0
  bool is_24ghz_ch_freq; // w0
  __int64 v110; // x8
  _BYTE *v111; // x24
  char v112; // w8
  unsigned int v113; // w8
  int v114; // w0
  bool v115; // cf
  unsigned int v116; // w9
  unsigned int v117; // w8
  char v118; // w10
  int v119; // w8
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  __int64 v128; // x0
  __int64 v129; // x0
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
  char v138; // w8
  __int64 v139; // x23
  char v140; // w9
  int v141; // w8
  int v142; // w8
  _BYTE *v143; // x0
  int rf_band; // w0
  int v145; // w8
  int v146; // w8
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  double v155; // d0
  double v156; // d1
  double v157; // d2
  double v158; // d3
  double v159; // d4
  double v160; // d5
  double v161; // d6
  double v162; // d7
  _BYTE v163[4]; // [xsp+Ch] [xbp-14h] BYREF
  int v164; // [xsp+10h] [xbp-10h] BYREF
  __int16 v165; // [xsp+14h] [xbp-Ch]
  __int64 v166; // [xsp+18h] [xbp-8h]

  v166 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(const void **)(a2 + 8);
  v163[0] = 0;
  v165 = 0;
  v164 = 0;
  lim_diag_event_report(a1, 18, 0, 0);
  v4 = (unsigned __int8 *)_qdf_mem_malloc(0x2B0u, "__lim_handle_sme_start_bss_request", 902);
  if ( v4 )
  {
    v5 = v4;
    qdf_mem_copy(v4, v3, 0x2B0u);
    v6 = *v5;
    opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), *v5);
    if ( opmode_from_vdev_id == 11 )
      v8 = 4;
    else
      v8 = 1;
    wlan_mlme_get_mac_vdev_id(*(_QWORD *)(a1 + 21560), v6, &v164);
    if ( *(_DWORD *)(a1 + 4056) > 1u )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Received unexpected START_BSS_REQ, in state %X",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "__lim_handle_sme_start_bss_request");
      goto LABEL_11;
    }
    if ( (((__int64 (__fastcall *)(__int64, unsigned __int8 *, _QWORD))lim_is_sme_start_bss_req_valid)(a1, v5, v8) & 1) == 0 )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Received invalid eWNI_SME_START_BSS_REQ",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "__lim_handle_sme_start_bss_request");
      v34 = 500;
      goto LABEL_13;
    }
    v25 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21560), *((_DWORD *)v5 + 92), v17, v18, v19, v20, v21, v22, v23, v24);
    if ( pe_find_session_by_bssid(a1, &v164, v163) )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Session Already exists for given BSSID",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "__lim_handle_sme_start_bss_request");
LABEL_11:
      v34 = 504;
LABEL_13:
      _qdf_mem_free((__int64)v5);
      goto LABEL_14;
    }
    v36 = ((__int64 (__fastcall *)(__int64, int *, _BYTE *, _QWORD, _QWORD, _QWORD))pe_create_session)(
            a1,
            &v164,
            v163,
            *(unsigned __int8 *)(a1 + 12272),
            v8,
            *v5);
    if ( !v36 )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Session Can not be created",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "__lim_handle_sme_start_bss_request");
      v34 = 502;
      goto LABEL_13;
    }
    v45 = v36;
    v46 = (_BYTE *)(v36 + 7024);
    lim_set_bcn_probe_filter(a1, v36, v25);
    if ( opmode_from_vdev_id != 11 )
    {
      lim_start_bss_update_add_ie_buffer(v45 + 7296, v45 + 7288, *((_QWORD *)v5 + 41), *((unsigned __int16 *)v5 + 160));
      lim_start_bss_update_add_ie_buffer(v45 + 7328, v45 + 7320, *((_QWORD *)v5 + 45), *((unsigned __int16 *)v5 + 176));
      started = lim_start_bss_update_add_ie_buffer(
                  v45 + 7312,
                  v45 + 7304,
                  *((_QWORD *)v5 + 43),
                  *((unsigned __int16 *)v5 + 168));
    }
    v55 = *((_DWORD *)v5 + 92);
    v56 = *(_QWORD *)(v45 + 16);
    *(_QWORD *)(v45 + 104) = v5;
    *(_DWORD *)(v45 + 284) = v55;
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v56, started, v48, v49, v50, v51, v52, v53, v54);
    if ( cmpt_obj )
    {
      v58 = cmpt_obj;
      if ( (policy_mgr_is_dbs_enable(*(_QWORD *)(a1 + 21552)) & 1) != 0 )
      {
        v67 = *(_DWORD *)(v58 + 48);
      }
      else
      {
        v68 = *(_DWORD *)(v45 + 284);
        v69 = *(_DWORD *)(v58 + 48);
        v70 = *(_DWORD *)(v58 + 60);
        if ( (*(_WORD *)(*(_QWORD *)(a1 + 8) + 1268LL) & 1) != 0 && (wma_is_rx_ldpc_supported_for_channel(v68) & 1) != 0 )
        {
          v67 = v69 | 0x10;
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: LDPC enable for ch freq[%d]",
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            "lim_set_ldpc_exception",
            v68);
          v71 = v70 & 0xFFFE | 1;
        }
        else
        {
          v67 = v69 & 0xFFFFFFEF;
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: LDPC disable for ch freq[%d]",
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            "lim_set_ldpc_exception",
            v68);
          v71 = v70 & 0xFFFE;
        }
        *(_DWORD *)(v58 + 48) = v67;
        *(_DWORD *)(v58 + 60) = v71 | v70 & 0xFFFF0000;
      }
      v72 = *(_QWORD *)(a1 + 8);
      if ( *(_BYTE *)(v72 + 2623) == 1 )
        v73 = *(unsigned __int8 *)(v72 + 2675) << 12;
      else
        v73 = 0;
      v74 = *(_DWORD *)(v45 + 284);
      v75 = v67 & 0xFFEF0FFF | v73 | 0x6000;
      if ( *(unsigned __int8 *)(*(_QWORD *)(v45 + 104) + 372LL) >= 3u )
        v76 = v75;
      else
        v76 = v75 & 0xFFEF7FB3;
      *(_DWORD *)(v45 + 7268) = v76;
      v77 = *(_DWORD *)(v58 + 60);
      *(_WORD *)(v45 + 7266) = v77;
      if ( wlan_reg_is_24ghz_ch_freq(v74) )
        *(_DWORD *)(v45 + 7268) &= 0xFFFFFF9F;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: cur_op_freq %d HT capability 0x%x VHT capability 0x%x bw %d",
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        "lim_start_bss_update_ht_vht_caps",
        *(unsigned int *)(v45 + 284),
        v77,
        v76,
        *(unsigned __int8 *)(*(_QWORD *)(v45 + 104) + 372LL));
    }
    v86 = v164;
    *(_BYTE *)(v45 + 31) = BYTE1(v164);
    v87 = BYTE2(v164);
    *(_BYTE *)(v45 + 30) = v86;
    *(_WORD *)(v45 + 32) = __PAIR16__(HIBYTE(v164), v87);
    *(_WORD *)(v45 + 34) = v165;
    qdf_mem_copy((void *)(v45 + 36), v5 + 8, (unsigned int)v5[8] + 1);
    v88 = *(_DWORD *)(v45 + 284);
    *(_DWORD *)(v45 + 96) = *((_DWORD *)v5 + 95);
    *(_WORD *)(v45 + 7158) = *((_WORD *)v5 + 21);
    *(_DWORD *)(v45 + 7232) = *((_DWORD *)v5 + 95);
    v46[8] = wlan_reg_get_channel_reg_power_for_freq(
               *(_QWORD *)(a1 + 21560),
               v88,
               v89,
               v90,
               v91,
               v92,
               v93,
               v94,
               v95,
               v96);
    v97 = v5[377];
    *(_BYTE *)(v45 + 154) = v97;
    v98 = *(_QWORD *)(a1 + 8);
    if ( v97 == 3 )
      v99 = 0;
    else
      v99 = *(_BYTE *)(v98 + 1284);
    *(_BYTE *)(v98 + 5388) = v99;
    param = wlan_crypto_get_param(*(_QWORD *)(v45 + 16), 1u);
    v101 = wlan_crypto_get_param(*(_QWORD *)(v45 + 16), 0);
    v102 = wlan_crypto_get_param(*(_QWORD *)(v45 + 16), 7u);
    v103 = v5[49];
    v104 = param & 0x18001;
    *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5439LL) = 0;
    if ( (param & 0x18001) != 0 && (v101 & 0x10) != 0 )
    {
      v105 = 9;
    }
    else if ( (v101 & 4) != 0 )
    {
      v105 = 1;
    }
    else if ( (v102 & 0x18000C00) != 0 )
    {
      v105 = 3;
    }
    else
    {
      if ( (v102 & 0xC0000) == 0 || *(_DWORD *)(v45 + 7036) != 1 )
      {
LABEL_48:
        v106 = v104 == 0;
        if ( (param & 0x669E) == 0 )
          v106 = 0;
        *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5386LL) = v106;
        v107 = (param & 0x669E) != 0;
        if ( !v103 )
          v107 = 0;
        if ( v104 )
          v107 = 1;
        *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5436LL) = v107;
        *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5440LL) = 0;
        v108 = *(_DWORD *)(v45 + 284);
        v46[261] = *(_BYTE *)(a1 + 17157);
        is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v108);
        v110 = 21522;
        if ( is_24ghz_ch_freq )
          v110 = 21512;
        v111 = (_BYTE *)(a1 + v110);
        if ( opmode_from_vdev_id == 11 )
        {
          v112 = v111[9];
          *(_DWORD *)(v45 + 88) = 6;
        }
        else
        {
          lim_configure_ap_start_bss_session(a1, v45, v5);
          if ( *(_DWORD *)(v45 + 7036) == 1 )
            v112 = v111[1];
          else
            v112 = v111[2];
        }
        v46[1628] = v112;
        v46[1611] = v112;
        if ( !*(_BYTE *)(*(_QWORD *)(a1 + 8) + 2667LL) || policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(a1 + 21552), v6) )
          v46[1611] = 1;
        v113 = *(unsigned __int8 *)(v45 + 154);
        v114 = *(_DWORD *)(v45 + 284);
        v115 = v113 >= 0xE;
        v116 = 0x3FA1u >> v113;
        v117 = 0x3F01u >> v113;
        v118 = !v115;
        *(_BYTE *)(v45 + 155) = v118 & v116;
        v46[146] = v118 & v117;
        if ( wlan_reg_is_6ghz_chan_freq(v114) )
        {
          v119 = *(unsigned __int8 *)(v45 + 154);
          if ( (unsigned int)(v119 - 7) >= 7 && v119 != 5 && *(_BYTE *)(v45 + 154) )
          {
LABEL_72:
            if ( (unsigned int)(v119 - 10) >= 4 && v119 )
            {
              if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v45 + 284)) )
              {
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: Invalid oper_ch_freq %d for dot11mode %d",
                  v155,
                  v156,
                  v157,
                  v158,
                  v159,
                  v160,
                  v161,
                  v162,
                  "__lim_handle_sme_start_bss_request",
                  *(unsigned int *)(v45 + 284),
                  *(unsigned __int8 *)(v45 + 154));
                goto LABEL_109;
              }
              lim_strip_he_ies_from_add_ies(a1, v45);
            }
            else
            {
              lim_update_session_he_capable(a1, v45);
              lim_copy_bss_he_cap(v45);
            }
LABEL_75:
            v128 = *(_QWORD *)(v45 + 16);
            v46[212] = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1283LL);
            *v46 = ((unsigned int)wlan_crypto_get_param(v128, 5u) >> 3) & 0x10 | *v46 & 0xEF;
            qdf_mem_copy((void *)(v45 + 252), v5 + 384, 0xDu);
            qdf_mem_copy((void *)(v45 + 265), v5 + 397, 0xDu);
            if ( opmode_from_vdev_id == 11 )
              goto LABEL_79;
            v129 = _qdf_mem_malloc(8LL * *(unsigned __int16 *)(v45 + 376), "__lim_handle_sme_start_bss_request", 1122);
            *(_QWORD *)(v45 + 384) = v129;
            if ( !v129 )
            {
              v139 = 0;
LABEL_101:
              v34 = 502;
LABEL_110:
              if ( *(unsigned __int8 **)(v45 + 104) == v5 )
                *(_QWORD *)(v45 + 104) = 0;
              _qdf_mem_free((__int64)v5);
              if ( v139 )
                _qdf_mem_free(v139);
              pe_delete_session(a1);
              goto LABEL_14;
            }
            if ( *((_DWORD *)v5 + 92) )
            {
LABEL_79:
              if ( *(_BYTE *)(a1 + 17158) == 1 && !policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(a1 + 21552), v6) )
                v138 = *(_BYTE *)(v45 + 155);
              else
                v138 = v5[375] != 0;
              *(_BYTE *)(v45 + 160) = v138;
              v140 = v46[1652];
              v141 = v5[375];
              *(_DWORD *)(v45 + 164) = v141;
              *(_BYTE *)(v45 + 161) = v141 != 0;
              if ( (v140 & 1) != 0 || v46[146] || *(_BYTE *)(v45 + 155) )
              {
                *(_DWORD *)(v45 + 7176) = v5[372];
                v46[150] = v5[373];
                v46[160] = v5[374];
                lim_update_he_bw_cap_mcs(v45, 0);
              }
              lim_delete_pre_auth_list(a1);
              v142 = *(_DWORD *)(v45 + 88);
              if ( v142 == 6 || v142 == 1 )
                *(_QWORD *)(v45 + 1944) = 0;
              lim_set_rnr_ie_from_start_bss_req(a1, v5 + 420, v45);
              v143 = (_BYTE *)_qdf_mem_malloc(1u, "__lim_handle_sme_start_bss_request", 1175);
              v139 = (__int64)v143;
              if ( v143 )
              {
                *v143 = *(_BYTE *)(v45 + 8);
                if ( *(_DWORD *)(v45 + 88) == 1 )
                {
                  *(_DWORD *)(v45 + 10048) = *((_DWORD *)v5 + 103);
                  *(_DWORD *)(v45 + 10064) = *((_DWORD *)v5 + 104);
                }
                rf_band = lim_get_rf_band(*((_DWORD *)v5 + 92));
                *(_DWORD *)(v45 + 7028) = 0;
                *(_DWORD *)(v45 + 168) = rf_band;
                if ( !rf_band )
                  goto LABEL_98;
                v145 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 1061LL);
                *(_DWORD *)(v45 + 7028) = v145;
                if ( v145 == 1 && *(_DWORD *)(v45 + 92) == 1 )
                {
                  v145 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 3168LL);
                  *(_DWORD *)(v45 + 7028) = v145;
                }
                if ( !v145 )
LABEL_98:
                  *(_BYTE *)(*(_QWORD *)(a1 + 8) + 4411LL) = 0;
                v146 = *(_DWORD *)(v45 + 80);
                *(_DWORD *)(v45 + 80) = 14;
                *(_DWORD *)(v45 + 84) = v146;
                lim_dump_session_info(a1, v45);
                lim_dump_he_info(a1, v45);
                qdf_trace(53, 1u, *(_WORD *)(v45 + 8), *(_DWORD *)(v45 + 80));
                if ( !(unsigned int)wlan_vdev_mlme_sm_deliver_evt(
                                      *(_QWORD *)(v45 + 16),
                                      0,
                                      1u,
                                      v139,
                                      v147,
                                      v148,
                                      v149,
                                      v150,
                                      v151,
                                      v152,
                                      v153,
                                      v154) )
                {
                  _qdf_mem_free(v139);
                  result = lim_update_rrm_capability(a1);
                  goto LABEL_15;
                }
                v34 = 0;
                goto LABEL_110;
              }
              goto LABEL_101;
            }
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Received invalid eWNI_SME_START_BSS_REQ",
              v130,
              v131,
              v132,
              v133,
              v134,
              v135,
              v136,
              v137,
              "__lim_handle_sme_start_bss_request");
LABEL_109:
            v139 = 0;
            v34 = 500;
            goto LABEL_110;
          }
          if ( policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(v45 + 10)) )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: For LL LT vdev %d allow 6 Ghz freq %d for dot11mode %d",
              v120,
              v121,
              v122,
              v123,
              v124,
              v125,
              v126,
              v127,
              "__lim_handle_sme_start_bss_request",
              *(unsigned __int8 *)(v45 + 10),
              *(unsigned int *)(v45 + 284),
              *(unsigned __int8 *)(v45 + 154));
            goto LABEL_75;
          }
        }
        v119 = *(unsigned __int8 *)(v45 + 154);
        goto LABEL_72;
      }
      v105 = 4;
    }
    *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5439LL) = v105;
    goto LABEL_48;
  }
  v6 = 255;
  v34 = 502;
LABEL_14:
  result = lim_send_sme_start_bss_rsp(a1, v34, 0, v6);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
