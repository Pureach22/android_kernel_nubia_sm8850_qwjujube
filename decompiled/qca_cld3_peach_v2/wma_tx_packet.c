__int64 __fastcall wma_tx_packet(
        __int64 a1,
        _QWORD *a2,
        unsigned __int16 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        __int64 a13,
        __int64 a14,
        _DWORD *a15,
        char *a16,
        __int64 a17,
        char a18,
        unsigned __int8 a19,
        char a20,
        unsigned __int16 a21,
        unsigned int a22,
        char a23,
        unsigned __int16 a24)
{
  _QWORD *v24; // x25
  unsigned __int8 **v28; // x19
  __int16 *v29; // x28
  _QWORD *context; // x22
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 result; // x0
  __int64 v42; // x23
  __int64 v43; // x8
  _DWORD *v44; // x8
  const char *v45; // x2
  _QWORD *v46; // x0
  __int64 *v47; // x11
  unsigned int v48; // w9
  unsigned __int8 *v49; // x19
  __int16 v50; // w8
  __int16 v51; // w9
  unsigned __int8 *v52; // x19
  unsigned __int64 system_ticks; // x0
  unsigned __int64 v54; // x24
  int param; // w0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned __int8 mmie_size; // w0
  unsigned __int16 v65; // w28
  unsigned int v66; // w0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  __int64 v91; // x0
  unsigned int v92; // w8
  size_t v93; // x2
  __int64 v94; // x1
  __int64 v95; // x8
  __int64 v96; // x24
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  __int64 v105; // x0
  __int64 v106; // x0
  __int64 ctrl_pdev_from_vdev; // x0
  double v108; // d0
  int v109; // w0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  char v117; // w0
  __int64 v118; // x3
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  __int16 v127; // w9
  int v128; // w23
  _BOOL4 v129; // w10
  unsigned int v130; // w0
  _QWORD *v132; // x8
  __int64 v133; // x1
  char v134; // w11
  char v135; // w10
  int v136; // w9
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  int v145; // w9
  char is_vdev_in_ap_mode; // w0
  __int16 v147; // w9
  char v148; // w8
  unsigned int v149; // w10
  bool is_5ghz_ch_freq; // w0
  unsigned __int8 *v151; // x19
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  __int64 v168; // x24
  __int64 v169; // x8
  unsigned __int8 v170; // w26
  _QWORD *peer; // x0
  __int64 v172; // x23
  int v173; // w24
  double v174; // d0
  double v175; // d1
  double v176; // d2
  double v177; // d3
  double v178; // d4
  double v179; // d5
  double v180; // d6
  double v181; // d7
  double v182; // d0
  double v183; // d1
  double v184; // d2
  double v185; // d3
  double v186; // d4
  double v187; // d5
  double v188; // d6
  double v189; // d7
  __int64 v190; // x21
  const char *v191; // x2
  char v192; // w8
  double v193; // d0
  double v194; // d1
  double v195; // d2
  double v196; // d3
  double v197; // d4
  double v198; // d5
  double v199; // d6
  double v200; // d7
  __int64 v201; // x0
  unsigned int *v202; // x8
  _BYTE *v203; // x23
  unsigned int v204; // t1
  double v205; // d0
  double v206; // d1
  double v207; // d2
  double v208; // d3
  double v209; // d4
  double v210; // d5
  double v211; // d6
  double v212; // d7
  char v213; // [xsp+Ch] [xbp-D4h]
  char v214; // [xsp+20h] [xbp-C0h]
  int v215; // [xsp+24h] [xbp-BCh]
  unsigned __int16 v216; // [xsp+24h] [xbp-BCh]
  __int64 *v217; // [xsp+28h] [xbp-B8h]
  __int64 *v218; // [xsp+28h] [xbp-B8h]
  _QWORD *v219; // [xsp+30h] [xbp-B0h]
  bool v220; // [xsp+38h] [xbp-A8h]
  unsigned __int8 v221[4]; // [xsp+54h] [xbp-8Ch] BYREF
  _QWORD *v222; // [xsp+58h] [xbp-88h] BYREF
  __int64 v223; // [xsp+60h] [xbp-80h]
  char *v224; // [xsp+68h] [xbp-78h]
  __int64 v225; // [xsp+70h] [xbp-70h]
  _QWORD *v226; // [xsp+78h] [xbp-68h]
  __int64 v227; // [xsp+80h] [xbp-60h] BYREF
  __int64 v228; // [xsp+88h] [xbp-58h]
  __int64 v229; // [xsp+90h] [xbp-50h]
  _QWORD *v230; // [xsp+98h] [xbp-48h] BYREF
  char *v231; // [xsp+A0h] [xbp-40h] BYREF
  _QWORD v232[4]; // [xsp+A8h] [xbp-38h] BYREF
  int v233; // [xsp+C8h] [xbp-18h]
  __int64 v234; // [xsp+D0h] [xbp-10h]

  v24 = a2;
  v234 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = (unsigned __int8 **)(a2 + 28);
  v29 = (__int16 *)a2[28];
  v230 = nullptr;
  v231 = nullptr;
  v228 = 0;
  v229 = 0;
  v226 = nullptr;
  v227 = 0;
  v224 = nullptr;
  v225 = 0;
  v222 = nullptr;
  v223 = 0;
  context = _cds_get_context(71, (__int64)"wma_tx_packet", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( (unsigned int)_wma_validate_handle(a1, "wma_tx_packet") )
    goto LABEL_2;
  if ( *(unsigned __int16 *)(a1 + 162) <= (unsigned int)a19 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: tx packet with invalid vdev_id :%d",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "wma_tx_packet");
    goto LABEL_3;
  }
  if ( !context )
  {
LABEL_2:
    cds_packet_free((__int64)v24);
LABEL_3:
    result = 16;
    goto LABEL_4;
  }
  v42 = *(_QWORD *)(a1 + 520);
  if ( *context && (v43 = *(_QWORD *)(*context + 64LL)) != 0 )
  {
    v44 = *(_DWORD **)(v43 + 32);
    if ( v44 )
    {
      if ( *(v44 - 1) != 1944199495 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD *, _QWORD, _QWORD))v44)(context, a19, 0);
    }
    if ( a4 >= 7 )
      goto LABEL_14;
  }
  else
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v33, v34, v35, v36, v37, v38, v39, v40, "cdp_hl_tdls_flag_reset");
    if ( a4 >= 7 )
    {
LABEL_14:
      v45 = "%s: Invalid Frame Type Fail to send Frame";
LABEL_15:
      qdf_trace_msg(0x36u, 2u, v45, v33, v34, v35, v36, v37, v38, v39, v40, "wma_tx_packet");
      goto LABEL_2;
    }
  }
  v46 = _cds_get_context(53, (__int64)"wma_tx_packet", v33, v34, v35, v36, v37, v38, v39, v40);
  if ( !v46 )
    goto LABEL_2;
  if ( a4 != 3 && a4 != 5 )
  {
    v45 = "%s: No Support to send other frames except 802.11 Mgmt/Data";
    goto LABEL_15;
  }
  v219 = v46;
  v47 = (__int64 *)(v42 + 488LL * a19);
  if ( *((_BYTE *)v47 + 210) )
  {
    if ( a4 != 3 )
      goto LABEL_35;
LABEL_27:
    v48 = (unsigned __int8)*v29 >> 4;
    if ( v48 > 0xD || ((1 << v48) & 0x3400) == 0 )
      goto LABEL_74;
    v49 = *v28;
    if ( (v49[4] & 1) != 0 )
    {
      v217 = (__int64 *)(v42 + 488LL * a19);
      param = wlan_crypto_get_param(*v47, 3u);
      if ( param < 1 )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Invalid key cipher %d",
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          "wma_tx_packet",
          (unsigned int)param);
        cds_packet_free((__int64)v24);
        result = 4294967274LL;
        goto LABEL_4;
      }
      if ( (param & 0x40) != 0 )
        mmie_size = cds_get_mmie_size();
      else
        mmie_size = cds_get_gmac_mmie_size();
      v65 = a3 + mmie_size;
      v66 = cds_packet_alloc(v65, &v231, &v230);
      if ( v66 )
        goto LABEL_51;
      qdf_mem_set(v231, v65, 0);
      qdf_mem_copy(v231, v49, 0x18u);
      qdf_mem_copy(v231 + 24, a16 + 24, (unsigned int)a3 - 24);
      if ( !wlan_crypto_add_mmie(v75, v76, v77, v78, v79, v80, v81, v82, *v217, v231, a3) )
      {
        qdf_trace_msg(0x36u, 1u, "%s: Failed to attach MMIE", v83, v84, v85, v86, v87, v88, v89, v90, "wma_tx_packet");
        cds_packet_free((__int64)v24);
        v91 = (__int64)v230;
LABEL_133:
        cds_packet_free(v91);
LABEL_134:
        *(_QWORD *)(a1 + 336) = 0;
        result = 16;
        *(_QWORD *)(a1 + 424) = 0;
        goto LABEL_4;
      }
    }
    else
    {
      if ( (*v29 & 0x4000) == 0 )
      {
LABEL_73:
        *((_BYTE *)v24 + 60) |= 1u;
LABEL_74:
        v28 = (unsigned __int8 **)(v24 + 28);
        goto LABEL_75;
      }
      LOBYTE(v232[0]) = 0;
      v221[0] = 0;
      v217 = (__int64 *)(v42 + 488LL * a19);
      if ( (a18 & 0x20) != 0 && *((_DWORD *)v47 + 41) == 7 )
      {
        v50 = 8;
        v51 = 8;
        v221[0] = 8;
        LOBYTE(v232[0]) = 8;
      }
      else
      {
        if ( (unsigned int)mlme_get_peer_mic_len(
                             *(_QWORD *)(a1 + 24),
                             *(_BYTE *)(*(_QWORD *)(a1 + 32) + 40LL),
                             v49 + 4,
                             v232,
                             v221,
                             v33,
                             v34,
                             v35,
                             v36,
                             v37,
                             v38,
                             v39,
                             v40) )
        {
LABEL_132:
          v91 = (__int64)v24;
          goto LABEL_133;
        }
        v51 = v221[0];
        v50 = LOBYTE(v232[0]);
      }
      v65 = v51 + a3 + v50;
      v66 = cds_packet_alloc(v65, &v231, &v230);
      if ( v66 )
      {
LABEL_51:
        qdf_trace_msg(
          0x36u,
          1u,
          "%s: Failed to allocate %d bytes for RMF status code (%x)",
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          "wma_tx_packet",
          v65,
          v66);
        goto LABEL_132;
      }
      qdf_mem_set(v231, v65, 0);
      qdf_mem_copy(v231, v49, 0x18u);
      qdf_mem_copy(&v231[v221[0] + 24], a16 + 24, (unsigned int)a3 - 24);
    }
    cds_packet_free((__int64)v24);
    v24 = v230;
    a16 = v231;
    a3 = v65;
    v47 = v217;
    v29 = (__int16 *)v230[28];
    goto LABEL_73;
  }
  if ( a4 == 3 && (a18 & 0x20) != 0 )
    goto LABEL_27;
  if ( a4 != 3 )
  {
LABEL_35:
    v52 = *v28;
    memset(v232, 0, sizeof(v232));
    system_ticks = qdf_mc_timer_get_system_ticks();
    if ( !a17 )
    {
      v45 = "%s: No Ack Complete Cb. Don't Allow";
      goto LABEL_15;
    }
    v54 = system_ticks;
    if ( *(_QWORD *)(a1 + 424) )
    {
      if ( system_ticks < *(_QWORD *)(a1 + 432) + 200LL )
      {
        v45 = "%s: Already one Data pending for Ack, reject Tx of data frame";
        goto LABEL_15;
      }
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: No Tx Ack for last data frame for more than 2 secs, allow Tx of current data frame",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "wma_tx_packet");
    }
    if ( (~v52[1] & 3) != 0 )
      v92 = 24;
    else
      v92 = 30;
    if ( (*v52 & 0x8C) == 0x88 )
      v93 = v92 + 2;
    else
      v93 = v92;
    v233 = v93;
    qdf_mem_copy(v232, v52, v93);
    v94 = v233;
    v95 = v24[5];
    if ( v95 )
      v24[5] = v95 + v233;
    skb_pull(v24, v94);
    wma_decap_to_8023(v24, v232);
    qdf_mem_set(v24 + 5, 0x30u, 0);
    *v24 = 0;
    *(_QWORD *)(a1 + 424) = a17;
    *(_QWORD *)(a1 + 432) = v54;
    *(_QWORD *)(a1 + 440) = v24;
    cdp_hl_tdls_flag_reset(context, a19, a20 & 1);
    v96 = cdp_tx_non_std(context, a19, v24);
    cdp_hl_tdls_flag_reset(context, a19, 0);
    if ( v96 )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: TxRx Rejected. Fail to do Tx",
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        "wma_tx_packet");
      if ( a15 )
      {
        v105 = *(_QWORD *)(a1 + 16);
        if ( *(a15 - 1) != 1402114878 )
          __break(0x8235u);
        ((void (__fastcall *)(__int64, _QWORD *, __int64))a15)(v105, v24, 1);
      }
      *(_QWORD *)(a1 + 424) = 0;
      result = 16;
      *(_QWORD *)(a1 + 440) = 0;
      goto LABEL_4;
    }
    if ( a15 )
    {
      v106 = *(_QWORD *)(a1 + 16);
      if ( *(a15 - 1) != 1402114878 )
        __break(0x8235u);
      ((void (__fastcall *)(__int64, _QWORD *, _QWORD))a15)(v106, v24, 0);
    }
LABEL_140:
    result = 0;
    goto LABEL_4;
  }
LABEL_75:
  v218 = v47;
  if ( (*v29 & 0xF0) == 0x50 )
    *((_QWORD *)*v28 + 3) = -*(_QWORD *)(*(_QWORD *)(a1 + 520) + 488LL * a19 + 192);
  ctrl_pdev_from_vdev = cdp_get_ctrl_pdev_from_vdev(context);
  if ( !ctrl_pdev_from_vdev )
  {
    v45 = "%s: ol_pdev_handle is NULL";
    goto LABEL_15;
  }
  v108 = cdp_cfg_is_high_latency(context, ctrl_pdev_from_vdev);
  v215 = v109;
  v117 = wmi_service_enabled(*(_QWORD *)a1, 0x5Bu, v108, v110, v111, v112, v113, v114, v115, v116);
  if ( !a15 || !v215 )
  {
    v127 = *v29;
    v129 = (*v29 & 0xC) != 0 || a17 == 0;
    goto LABEL_93;
  }
  v127 = *v29;
  v128 = *v29 & 0xC;
  if ( v128 )
    v129 = 1;
  else
    v129 = a17 == 0;
  if ( (a17 == 0) | v117 & 1 )
  {
LABEL_93:
    v132 = v219;
    v133 = a19;
    v134 = 0;
    if ( v129 )
      v135 = 0;
    else
      v135 = 3;
    goto LABEL_96;
  }
  *(_QWORD *)(a1 + 336) = a15;
  v130 = qdf_event_reset(a1 + 344);
  if ( v130 )
  {
    qdf_trace_msg(
      0x36u,
      1u,
      "%s: Event Reset failed tx comp event %x",
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      v125,
      v126,
      "wma_tx_packet",
      v130);
    goto LABEL_132;
  }
  v127 = *v29;
  v133 = a19;
  v134 = 1;
  v135 = 2 * (v128 == 0);
  v132 = v219;
LABEL_96:
  v136 = (unsigned __int8)v127 >> 4;
  v213 = v134;
  v214 = v135;
  if ( v136 == 13 || v136 == 11 )
  {
    v216 = a21;
    goto LABEL_108;
  }
  if ( v136 != 5 )
    goto LABEL_106;
  v216 = a21;
  if ( (wma_is_vdev_in_ap_mode(a1, v133) & 1) != 0 )
  {
    LOWORD(v145) = a21;
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 520) + 488LL * a19 + 436) )
      v145 = *(_DWORD *)(*(_QWORD *)(a1 + 520) + 488LL * a19 + 436);
    v216 = v145;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Probe response frame on channel %d vdev:%d",
    v137,
    v138,
    v139,
    v140,
    v141,
    v142,
    v143,
    v144,
    "wma_tx_packet",
    v216,
    a19);
  is_vdev_in_ap_mode = wma_is_vdev_in_ap_mode(a1, a19);
  if ( v216 )
  {
    v132 = v219;
    goto LABEL_108;
  }
  v132 = v219;
  if ( (is_vdev_in_ap_mode & 1) != 0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: AP oper chan is zero",
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      v125,
      v126,
      "wma_tx_packet");
    v132 = v219;
LABEL_106:
    v216 = 0;
  }
LABEL_108:
  v147 = *v29;
  if ( (*v29 & 0xC) == 0 )
  {
    if ( (v148 = *(_BYTE *)(v132[1] + 1060LL), (v148 & 1) != 0)
      && ((v149 = (unsigned __int8)v147 >> 4, v149 > 0xD) || ((1 << v149) & 0x2030) == 0)
      || (v147 & 0xF0) == 0xD0 && (v148 & 8) != 0 )
    {
      mgmt_txrx_frame_hex_dump((__int64)a16, a3, 1, v118, v119, v120, v121, v122, v123, v124, v125, v126);
    }
  }
  is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(*(_QWORD *)(a1 + 520) + 488LL * a19 + 436));
  v151 = *v28;
  v220 = is_5ghz_ch_freq;
  BYTE2(v223) = a19;
  v222 = v24;
  LOWORD(v223) = a3;
  v224 = a16;
  WORD2(v223) = v216;
  v226 = _cds_get_context(64, (__int64)"wma_tx_packet", v152, v153, v154, v155, v156, v157, v158, v159);
  BYTE1(v228) = (a18 & 0x40) != 0;
  BYTE3(v223) = v214;
  LOBYTE(v229) = a23;
  BYTE1(v229) = wma_is_mlo_link_agnostic(*v218, v151 + 4, a4, *(unsigned __int8 *)v29 >> 4, a24) & 1;
  if ( (a18 & 0x10) != 0 )
    HIDWORD(v228) |= 1u;
  if ( a22 - 12 >= 0xFFFFFFF5 && (a22 != 4 || !v220) )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: using rate id: %d for Tx",
      v160,
      v161,
      v162,
      v163,
      v164,
      v165,
      v166,
      v167,
      "wma_tx_packet",
      a22);
    LOBYTE(v228) = 1;
    wma_update_tx_send_params(&v227, a22);
  }
  v168 = *(_QWORD *)(a1 + 24);
  if ( !v168 )
  {
    v191 = "%s: psoc ctx is NULL";
    goto LABEL_131;
  }
  v169 = *(_QWORD *)(a1 + 32);
  if ( !v169 )
  {
    v191 = "%s: pdev ctx is NULL";
    goto LABEL_131;
  }
  v170 = *(_BYTE *)(v169 + 40);
  peer = wlan_objmgr_get_peer(*(_QWORD *)(a1 + 24), v170, v151 + 4, 4u);
  if ( !peer )
  {
    peer = wlan_objmgr_get_peer(v168, v170, v151 + 10, 4u);
    if ( !peer )
    {
      v201 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v168, a19, 4);
      if ( v201 )
      {
        v203 = (_BYTE *)v201;
        wlan_objmgr_vdev_release_ref(v201, 4u, v202, v160, v161, v162, v163, v164, v165, v166, v167);
        v204 = (unsigned __int8)v203[80];
        v203 += 80;
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: mld mac addr %02x:%02x:%02x:**:**:%02x",
          v205,
          v206,
          v207,
          v208,
          v209,
          v210,
          v211,
          v212,
          "wma_tx_packet",
          v204,
          (unsigned __int8)v203[1],
          (unsigned __int8)v203[2],
          (unsigned __int8)v203[5]);
        peer = wlan_objmgr_get_peer(v168, v170, v203, 4u);
        if ( peer )
          goto LABEL_124;
        v191 = "%s: peer is null";
      }
      else
      {
        v191 = "%s: vdev is null";
      }
LABEL_131:
      qdf_trace_msg(0x36u, 2u, v191, v160, v161, v162, v163, v164, v165, v166, v167, "wma_tx_packet");
      goto LABEL_132;
    }
  }
LABEL_124:
  v172 = (__int64)peer;
  v173 = wlan_mgmt_txrx_mgmt_frame_tx(
           (__int64)peer,
           *(_QWORD *)(a1 + 16),
           (__int64)v24,
           0,
           a17,
           v160,
           v161,
           v162,
           v163,
           v164,
           v165,
           v166,
           v167,
           0,
           (__int64)&v222);
  wlan_objmgr_peer_release_ref(v172, 4u, v174, v175, v176, v177, v178, v179, v180, v181);
  if ( v173 )
  {
    v190 = jiffies;
    if ( wma_tx_packet___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x36u, 2u, "%s: mgmt tx failed", v182, v183, v184, v185, v186, v187, v188, v189, "wma_tx_packet");
      wma_tx_packet___last_ticks = v190;
    }
    if ( v24 )
      _qdf_nbuf_free((__int64)v24);
    goto LABEL_134;
  }
  v192 = v213 ^ 1;
  if ( !a15 )
    v192 = 1;
  if ( (v192 & 1) != 0 )
    goto LABEL_140;
  result = qdf_wait_for_event_completion(a1 + 344, 0x3E8u);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(0x36u, 1u, "Wait Event failed txfrm_comp_event", v193, v194, v195, v196, v197, v198, v199, v200);
    result = cdp_display_stats(context);
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
