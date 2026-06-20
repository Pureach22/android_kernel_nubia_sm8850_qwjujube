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
        __int16 a21,
        unsigned int a22,
        unsigned __int8 a23)
{
  _QWORD *v23; // x27
  _QWORD *v27; // x19
  __int16 *v28; // x24
  _QWORD *context; // x22
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 result; // x0
  __int64 v41; // x23
  __int64 v42; // x8
  _DWORD *v43; // x8
  const char *v44; // x2
  _QWORD *v45; // x0
  __int64 v46; // x11
  __int64 v47; // x23
  unsigned int v48; // w9
  const void *v49; // x28
  unsigned __int8 *v50; // x2
  __int16 v51; // w8
  __int16 v52; // w9
  _BYTE *v53; // x24
  unsigned __int64 system_ticks; // x0
  unsigned __int64 v55; // x25
  __int64 *v56; // x24
  int param; // w0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned __int8 mmie_size; // w0
  unsigned __int16 v67; // w19
  unsigned int v68; // w0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 v93; // x0
  unsigned int v94; // w8
  size_t v95; // x2
  __int64 v96; // x1
  __int64 v97; // x8
  __int64 v98; // x24
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  __int64 v107; // x0
  __int64 v108; // x0
  __int64 ctrl_pdev_from_vdev; // x0
  double v110; // d0
  int v111; // w0
  int v112; // w28
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  char v120; // w0
  __int64 v121; // x3
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  __int16 v130; // w9
  int v131; // w23
  _BOOL4 v132; // w10
  _QWORD *v133; // x8
  __int64 v134; // x1
  char v136; // w11
  char v137; // w10
  int v138; // w9
  int v139; // w28
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  char is_vdev_in_ap_mode; // w0
  __int16 v149; // w9
  __int16 v150; // w23
  char v151; // w8
  unsigned int v152; // w10
  bool is_5ghz_ch_freq; // w28
  __int64 v154; // x19
  double v155; // d0
  double v156; // d1
  double v157; // d2
  double v158; // d3
  double v159; // d4
  double v160; // d5
  double v161; // d6
  double v162; // d7
  double v163; // d0
  double v164; // d1
  double v165; // d2
  double v166; // d3
  double v167; // d4
  double v168; // d5
  double v169; // d6
  double v170; // d7
  __int64 v171; // x25
  __int64 v172; // x8
  char v173; // w24
  __int64 peer; // x0
  __int64 v175; // x23
  int v176; // w24
  double v177; // d0
  double v178; // d1
  double v179; // d2
  double v180; // d3
  double v181; // d4
  double v182; // d5
  double v183; // d6
  double v184; // d7
  double v185; // d0
  double v186; // d1
  double v187; // d2
  double v188; // d3
  double v189; // d4
  double v190; // d5
  double v191; // d6
  double v192; // d7
  __int64 v193; // x21
  const char *v194; // x2
  unsigned int v195; // w0
  char v196; // w8
  double v197; // d0
  double v198; // d1
  double v199; // d2
  double v200; // d3
  double v201; // d4
  double v202; // d5
  double v203; // d6
  double v204; // d7
  bool v205; // w8
  __int64 v206; // x0
  unsigned int *v207; // x8
  _BYTE *v208; // x23
  unsigned int v209; // t1
  double v210; // d0
  double v211; // d1
  double v212; // d2
  double v213; // d3
  double v214; // d4
  double v215; // d5
  double v216; // d6
  double v217; // d7
  char v218; // [xsp+Ch] [xbp-C4h]
  __int64 v219; // [xsp+10h] [xbp-C0h]
  char v220; // [xsp+1Ch] [xbp-B4h]
  _QWORD *v221; // [xsp+20h] [xbp-B0h]
  unsigned __int8 v222[4]; // [xsp+44h] [xbp-8Ch] BYREF
  _QWORD *v223; // [xsp+48h] [xbp-88h] BYREF
  __int64 v224; // [xsp+50h] [xbp-80h]
  char *v225; // [xsp+58h] [xbp-78h]
  __int64 v226; // [xsp+60h] [xbp-70h]
  _QWORD *v227; // [xsp+68h] [xbp-68h]
  __int64 v228; // [xsp+70h] [xbp-60h] BYREF
  __int64 v229; // [xsp+78h] [xbp-58h]
  __int64 v230; // [xsp+80h] [xbp-50h]
  _QWORD *v231; // [xsp+88h] [xbp-48h] BYREF
  char *v232; // [xsp+90h] [xbp-40h] BYREF
  _QWORD v233[4]; // [xsp+98h] [xbp-38h] BYREF
  int v234; // [xsp+B8h] [xbp-18h]
  __int64 v235; // [xsp+C0h] [xbp-10h]

  v23 = a2;
  v235 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = a2 + 28;
  v28 = (__int16 *)a2[28];
  v231 = nullptr;
  v232 = nullptr;
  v229 = 0;
  v230 = 0;
  v227 = nullptr;
  v228 = 0;
  v225 = nullptr;
  v226 = 0;
  v223 = nullptr;
  v224 = 0;
  context = _cds_get_context(71, (__int64)"wma_tx_packet", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( (unsigned int)_wma_validate_handle(a1, "wma_tx_packet") )
    goto LABEL_2;
  if ( *(unsigned __int16 *)(a1 + 162) <= (unsigned int)a19 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: tx packet with invalid vdev_id :%d",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "wma_tx_packet");
    goto LABEL_3;
  }
  if ( !context )
  {
LABEL_2:
    cds_packet_free((__int64)v23);
LABEL_3:
    result = 16;
    goto LABEL_4;
  }
  v41 = *(_QWORD *)(a1 + 520);
  if ( *context && (v42 = *(_QWORD *)(*context + 64LL)) != 0 )
  {
    v43 = *(_DWORD **)(v42 + 32);
    if ( v43 )
    {
      if ( *(v43 - 1) != 1944199495 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD *, _QWORD, _QWORD))v43)(context, a19, 0);
    }
    if ( a4 >= 7 )
      goto LABEL_14;
  }
  else
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v32, v33, v34, v35, v36, v37, v38, v39, "cdp_hl_tdls_flag_reset");
    if ( a4 >= 7 )
    {
LABEL_14:
      v44 = "%s: Invalid Frame Type Fail to send Frame";
LABEL_15:
      qdf_trace_msg(0x36u, 2u, v44, v32, v33, v34, v35, v36, v37, v38, v39, "wma_tx_packet");
      goto LABEL_2;
    }
  }
  v45 = _cds_get_context(53, (__int64)"wma_tx_packet", v32, v33, v34, v35, v36, v37, v38, v39);
  if ( !v45 )
    goto LABEL_2;
  if ( a4 != 3 && a4 != 5 )
  {
    v44 = "%s: No Support to send other frames except 802.11 Mgmt/Data";
    goto LABEL_15;
  }
  v221 = v45;
  v46 = v41 + 488LL * a19;
  v47 = a17;
  if ( *(_BYTE *)(v46 + 210) )
  {
    if ( a4 != 3 )
      goto LABEL_35;
LABEL_27:
    v48 = (unsigned __int8)*v28 >> 4;
    if ( v48 > 0xD || ((1 << v48) & 0x3400) == 0 )
      goto LABEL_74;
    v49 = (const void *)*v27;
    v50 = (unsigned __int8 *)(*v27 + 4LL);
    if ( (*v50 & 1) != 0 )
    {
      v56 = (__int64 *)v46;
      param = wlan_crypto_get_param(*(_QWORD *)v46, 3u);
      if ( param < 1 )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Invalid key cipher %d",
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          "wma_tx_packet",
          (unsigned int)param);
        cds_packet_free((__int64)v23);
        result = 4294967274LL;
        goto LABEL_4;
      }
      if ( (param & 0x40) != 0 )
        mmie_size = cds_get_mmie_size();
      else
        mmie_size = cds_get_gmac_mmie_size();
      v67 = a3 + mmie_size;
      v68 = cds_packet_alloc(v67, &v232, &v231);
      if ( v68 )
        goto LABEL_51;
      qdf_mem_set(v232, v67, 0);
      qdf_mem_copy(v232, v49, 0x18u);
      qdf_mem_copy(v232 + 24, a16 + 24, (unsigned int)a3 - 24);
      if ( !wlan_crypto_add_mmie(v77, v78, v79, v80, v81, v82, v83, v84, *v56, v232, a3) )
      {
        qdf_trace_msg(0x36u, 1u, "%s: Failed to attach MMIE", v85, v86, v87, v88, v89, v90, v91, v92, "wma_tx_packet");
        cds_packet_free((__int64)v23);
        v93 = (__int64)v231;
LABEL_132:
        cds_packet_free(v93);
LABEL_133:
        *(_QWORD *)(a1 + 336) = 0;
        result = 16;
        *(_QWORD *)(a1 + 424) = 0;
        goto LABEL_4;
      }
    }
    else
    {
      if ( (*v28 & 0x4000) == 0 )
      {
LABEL_73:
        *((_BYTE *)v23 + 60) |= 1u;
LABEL_74:
        v27 = v23 + 28;
        goto LABEL_75;
      }
      LOBYTE(v233[0]) = 0;
      v222[0] = 0;
      if ( (a18 & 0x20) != 0 && *(_DWORD *)(v46 + 164) == 7 )
      {
        v51 = 8;
        v52 = 8;
        v222[0] = 8;
        LOBYTE(v233[0]) = 8;
      }
      else
      {
        if ( (unsigned int)mlme_get_peer_mic_len(
                             *(_QWORD *)(a1 + 24),
                             *(_BYTE *)(*(_QWORD *)(a1 + 32) + 40LL),
                             v50,
                             v233,
                             v222,
                             v32,
                             v33,
                             v34,
                             v35,
                             v36,
                             v37,
                             v38,
                             v39) )
        {
LABEL_131:
          v93 = (__int64)v23;
          goto LABEL_132;
        }
        v52 = v222[0];
        v51 = LOBYTE(v233[0]);
      }
      v67 = v52 + a3 + v51;
      v68 = cds_packet_alloc(v67, &v232, &v231);
      if ( v68 )
      {
LABEL_51:
        qdf_trace_msg(
          0x36u,
          1u,
          "%s: Failed to allocate %d bytes for RMF status code (%x)",
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          "wma_tx_packet",
          v67,
          v68);
        goto LABEL_131;
      }
      qdf_mem_set(v232, v67, 0);
      qdf_mem_copy(v232, v49, 0x18u);
      qdf_mem_copy(&v232[v222[0] + 24], a16 + 24, (unsigned int)a3 - 24);
    }
    cds_packet_free((__int64)v23);
    v23 = v231;
    a16 = v232;
    a3 = v67;
    v28 = (__int16 *)v231[28];
    goto LABEL_73;
  }
  if ( a4 == 3 && (a18 & 0x20) != 0 )
    goto LABEL_27;
  if ( a4 != 3 )
  {
LABEL_35:
    v53 = (_BYTE *)*v27;
    memset(v233, 0, sizeof(v233));
    system_ticks = qdf_mc_timer_get_system_ticks();
    if ( !a17 )
    {
      v44 = "%s: No Ack Complete Cb. Don't Allow";
      goto LABEL_15;
    }
    v55 = system_ticks;
    if ( *(_QWORD *)(a1 + 424) )
    {
      if ( system_ticks < *(_QWORD *)(a1 + 432) + 200LL )
      {
        v44 = "%s: Already one Data pending for Ack, reject Tx of data frame";
        goto LABEL_15;
      }
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: No Tx Ack for last data frame for more than 2 secs, allow Tx of current data frame",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "wma_tx_packet");
    }
    if ( (~(unsigned __int8)v53[1] & 3) != 0 )
      v94 = 24;
    else
      v94 = 30;
    if ( (*v53 & 0x8C) == 0x88 )
      v95 = v94 + 2;
    else
      v95 = v94;
    v234 = v95;
    qdf_mem_copy(v233, v53, v95);
    v96 = v234;
    v97 = v23[5];
    if ( v97 )
      v23[5] = v97 + v234;
    skb_pull(v23, v96);
    wma_decap_to_8023(v23, v233);
    qdf_mem_set(v23 + 5, 0x30u, 0);
    *v23 = 0;
    *(_QWORD *)(a1 + 424) = a17;
    *(_QWORD *)(a1 + 432) = v55;
    *(_QWORD *)(a1 + 440) = v23;
    cdp_hl_tdls_flag_reset(context, a19, a20 & 1);
    v98 = cdp_tx_non_std(context, a19, v23);
    cdp_hl_tdls_flag_reset(context, a19, 0);
    if ( v98 )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: TxRx Rejected. Fail to do Tx",
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
        "wma_tx_packet");
      if ( a15 )
      {
        v107 = *(_QWORD *)(a1 + 16);
        if ( *(a15 - 1) != 1402114878 )
          __break(0x8235u);
        ((void (__fastcall *)(__int64, _QWORD *, __int64))a15)(v107, v23, 1);
      }
      *(_QWORD *)(a1 + 424) = 0;
      result = 16;
      *(_QWORD *)(a1 + 440) = 0;
      goto LABEL_4;
    }
    if ( a15 )
    {
      v108 = *(_QWORD *)(a1 + 16);
      if ( *(a15 - 1) != 1402114878 )
        __break(0x8235u);
      ((void (__fastcall *)(__int64, _QWORD *, _QWORD))a15)(v108, v23, 0);
    }
LABEL_139:
    result = 0;
    goto LABEL_4;
  }
LABEL_75:
  if ( (*v28 & 0xF0) == 0x50 )
    *(_QWORD *)(*v27 + 24LL) = -*(_QWORD *)(*(_QWORD *)(a1 + 520) + 488LL * a19 + 192);
  ctrl_pdev_from_vdev = cdp_get_ctrl_pdev_from_vdev(context);
  if ( !ctrl_pdev_from_vdev )
  {
    v44 = "%s: ol_pdev_handle is NULL";
    goto LABEL_15;
  }
  v110 = cdp_cfg_is_high_latency(context, ctrl_pdev_from_vdev);
  v112 = v111;
  v120 = wmi_service_enabled(*(_QWORD *)a1, 0x5Bu, v110, v113, v114, v115, v116, v117, v118, v119);
  if ( !a15 || !v112 )
  {
    v130 = *v28;
    v133 = v221;
    v134 = a19;
    v132 = (*v28 & 0xC) != 0 || a17 == 0;
    goto LABEL_92;
  }
  v130 = *v28;
  v131 = *v28 & 0xC;
  if ( v131 )
    v132 = 1;
  else
    v132 = a17 == 0;
  if ( (a17 == 0) | v120 & 1 )
  {
    v133 = v221;
    v134 = a19;
    v47 = a17;
LABEL_92:
    v136 = 0;
    if ( v132 )
      v137 = 0;
    else
      v137 = 3;
    goto LABEL_95;
  }
  *(_QWORD *)(a1 + 336) = a15;
  v195 = qdf_event_reset(a1 + 344);
  if ( v195 )
  {
    qdf_trace_msg(
      0x36u,
      1u,
      "%s: Event Reset failed tx comp event %x",
      v122,
      v123,
      v124,
      v125,
      v126,
      v127,
      v128,
      v129,
      "wma_tx_packet",
      v195);
    goto LABEL_131;
  }
  v130 = *v28;
  v134 = a19;
  v205 = v131 == 0;
  v136 = 1;
  v47 = a17;
  v137 = 2 * v205;
  v133 = v221;
LABEL_95:
  v138 = (unsigned __int8)v130 >> 4;
  LOWORD(v139) = a21;
  v219 = v47;
  v218 = v136;
  v220 = v137;
  if ( v138 == 13 || v138 == 11 )
    goto LABEL_105;
  if ( v138 != 5 )
    goto LABEL_104;
  if ( (wma_is_vdev_in_ap_mode(a1, v134) & 1) != 0 && *(_DWORD *)(*(_QWORD *)(a1 + 520) + 488LL * a19 + 436) )
    v139 = *(_DWORD *)(*(_QWORD *)(a1 + 520) + 488LL * a19 + 436);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Probe response frame on channel %d vdev:%d",
    v140,
    v141,
    v142,
    v143,
    v144,
    v145,
    v146,
    v147,
    "wma_tx_packet",
    (unsigned __int16)v139,
    a19);
  is_vdev_in_ap_mode = wma_is_vdev_in_ap_mode(a1, a19);
  if ( (_WORD)v139 )
  {
    v133 = v221;
    goto LABEL_105;
  }
  v133 = v221;
  if ( (is_vdev_in_ap_mode & 1) != 0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: AP oper chan is zero",
      v122,
      v123,
      v124,
      v125,
      v126,
      v127,
      v128,
      v129,
      "wma_tx_packet");
    v133 = v221;
LABEL_104:
    LOWORD(v139) = 0;
  }
LABEL_105:
  v149 = *v28;
  v150 = v139;
  if ( (*v28 & 0xC) == 0 )
  {
    if ( (v151 = *(_BYTE *)(v133[1] + 1060LL), (v151 & 1) != 0)
      && ((v152 = (unsigned __int8)v149 >> 4, v152 > 0xD) || ((1 << v152) & 0x2030) == 0)
      || (v149 & 0xF0) == 0xD0 && (v151 & 8) != 0 )
    {
      mgmt_txrx_frame_hex_dump((__int64)a16, a3, 1, v121, v122, v123, v124, v125, v126, v127, v128, v129);
    }
  }
  is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(*(_QWORD *)(a1 + 520) + 488LL * a19 + 436));
  v154 = *v27;
  v223 = v23;
  LOWORD(v224) = a3;
  BYTE2(v224) = a19;
  v225 = a16;
  WORD2(v224) = v150;
  v227 = _cds_get_context(64, (__int64)"wma_tx_packet", v155, v156, v157, v158, v159, v160, v161, v162);
  BYTE1(v229) = (a18 & 0x40) != 0;
  BYTE3(v224) = v220;
  LOWORD(v230) = a23;
  if ( (a18 & 0x10) != 0 )
    HIDWORD(v229) |= 1u;
  if ( a22 - 12 >= 0xFFFFFFF5 && (a22 != 4 || !is_5ghz_ch_freq) )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: using rate id: %d for Tx",
      v163,
      v164,
      v165,
      v166,
      v167,
      v168,
      v169,
      v170,
      "wma_tx_packet",
      a22);
    LOBYTE(v229) = 1;
    wma_update_tx_send_params(&v228, a22);
  }
  v171 = *(_QWORD *)(a1 + 24);
  if ( !v171 )
  {
    v194 = "%s: psoc ctx is NULL";
    goto LABEL_130;
  }
  v172 = *(_QWORD *)(a1 + 32);
  if ( !v172 )
  {
    v194 = "%s: pdev ctx is NULL";
    goto LABEL_130;
  }
  v173 = *(_BYTE *)(v172 + 40);
  peer = wlan_objmgr_get_peer(*(_QWORD *)(a1 + 24), v173, (_BYTE *)(v154 + 4), 4u);
  if ( !peer )
  {
    peer = wlan_objmgr_get_peer(v171, v173, (_BYTE *)(v154 + 10), 4u);
    if ( !peer )
    {
      v206 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v171, a19, 4);
      if ( v206 )
      {
        v208 = (_BYTE *)v206;
        wlan_objmgr_vdev_release_ref(v206, 4u, v207, v163, v164, v165, v166, v167, v168, v169, v170);
        v209 = (unsigned __int8)v208[80];
        v208 += 80;
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: mld mac addr %02x:%02x:%02x:**:**:%02x",
          v210,
          v211,
          v212,
          v213,
          v214,
          v215,
          v216,
          v217,
          "wma_tx_packet",
          v209,
          (unsigned __int8)v208[1],
          (unsigned __int8)v208[2],
          (unsigned __int8)v208[5]);
        peer = wlan_objmgr_get_peer(v171, v173, v208, 4u);
        if ( peer )
          goto LABEL_121;
        v194 = "%s: peer is null";
      }
      else
      {
        v194 = "%s: vdev is null";
      }
LABEL_130:
      qdf_trace_msg(0x36u, 2u, v194, v163, v164, v165, v166, v167, v168, v169, v170, "wma_tx_packet");
      goto LABEL_131;
    }
  }
LABEL_121:
  v175 = peer;
  v176 = wlan_mgmt_txrx_mgmt_frame_tx(
           peer,
           *(_QWORD *)(a1 + 16),
           (__int64)v23,
           0,
           v219,
           v163,
           v164,
           v165,
           v166,
           v167,
           v168,
           v169,
           v170,
           0,
           (__int64)&v223);
  wlan_objmgr_peer_release_ref(v175, 4u, v177, v178, v179, v180, v181, v182, v183, v184);
  if ( v176 )
  {
    v193 = jiffies;
    if ( wma_tx_packet___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x36u, 2u, "%s: mgmt tx failed", v185, v186, v187, v188, v189, v190, v191, v192, "wma_tx_packet");
      wma_tx_packet___last_ticks = v193;
    }
    if ( v23 )
      _qdf_nbuf_free((__int64)v23);
    goto LABEL_133;
  }
  v196 = v218 ^ 1;
  if ( !a15 )
    v196 = 1;
  if ( (v196 & 1) != 0 )
    goto LABEL_139;
  result = qdf_wait_for_event_completion(a1 + 344, 0x3E8u);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(0x36u, 1u, "Wait Event failed txfrm_comp_event", v197, v198, v199, v200, v201, v202, v203, v204);
    result = cdp_display_stats(context);
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
