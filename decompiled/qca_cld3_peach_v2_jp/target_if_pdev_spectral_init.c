__int64 __fastcall target_if_pdev_spectral_init(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  void *v10; // x0
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x21
  __int64 v21; // x20
  __int64 (__fastcall *v22)(_QWORD); // x8
  unsigned int v23; // w0
  __int64 (__fastcall *v24)(_QWORD); // x8
  unsigned int v25; // w20
  int v26; // w0
  int v27; // w21
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int (__fastcall *v44)(__int64, __int64); // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int (__fastcall *v53)(__int64, __int64); // x8
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 (__fastcall *v62)(_QWORD); // x8
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  unsigned int v71; // w8
  char v72; // w11
  __int16 v73; // w12
  int v74; // w9
  char v75; // w10
  char v76; // w13
  int v78; // w9
  int v79; // w10
  unsigned int v80; // w8
  int v81; // w9
  char v82; // w10
  char v83; // w8
  char v84; // w10
  int v85; // w12
  char v86; // w11
  int v87; // w9
  char v88; // w13
  __int64 v89; // x0
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  unsigned int v98; // w23
  _BOOL4 v99; // w8
  __int64 v100; // x0
  __int16 v101; // w8
  __int64 v102; // x0
  __int16 v103; // w8
  __int64 v104; // x0
  __int16 v105; // w8
  __int64 v106; // x0
  __int16 v107; // w8
  __int64 v108; // x0
  __int16 v109; // w8
  __int64 v110; // x0
  __int16 v111; // w8
  __int64 v112; // x0
  __int16 v113; // w8
  __int64 v114; // x0
  __int16 v115; // w8
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  __int64 v132; // x8
  int v133; // w8
  __int16 v134; // w8
  bool v135[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v136; // [xsp+8h] [xbp-8h]

  v136 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: SPECTRAL: pdev is NULL!",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_pdev_spectral_init");
LABEL_30:
    v11 = 0;
    goto LABEL_31;
  }
  v10 = (void *)_qdf_mem_malloc(0x8E8u, "target_if_pdev_spectral_init", 3951);
  v11 = (__int64)v10;
  if ( v10 )
  {
    qdf_mem_set(v10, 0x8E8u, 0);
    *(_QWORD *)v11 = a1;
    *(_WORD *)(v11 + 360) = -1;
    v20 = *(_QWORD *)(a1 + 80);
    if ( !v20 || (v21 = *(_QWORD *)(v20 + 2128)) == 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: tx_ops is NULL",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "target_if_pdev_spectral_init");
LABEL_29:
      _qdf_mem_free(v11);
      goto LABEL_30;
    }
    v22 = *(__int64 (__fastcall **)(_QWORD))(v21 + 1736);
    if ( !v22 )
      goto LABEL_29;
    if ( *((_DWORD *)v22 - 1) != 1468042957 )
      __break(0x8228u);
    v23 = v22(v20);
    v24 = *(__int64 (__fastcall **)(_QWORD))(v21 + 1752);
    if ( !v24 )
      goto LABEL_29;
    v25 = v23;
    if ( *((_DWORD *)v24 - 1) != 1468042957 )
      __break(0x8228u);
    v26 = v24(v20);
    *(_QWORD *)(v11 + 8) = null_get_tsf64;
    *(_QWORD *)(v11 + 16) = null_get_capability;
    *(_QWORD *)(v11 + 24) = null_set_rxfilter;
    v27 = v26;
    *(_QWORD *)(v11 + 32) = null_get_rxfilter;
    *(_QWORD *)(v11 + 40) = null_is_spectral_active;
    *(_QWORD *)(v11 + 48) = null_is_spectral_enabled;
    *(_QWORD *)(v11 + 56) = null_start_spectral_scan;
    *(_QWORD *)(v11 + 64) = null_stop_spectral_scan;
    *(_QWORD *)(v11 + 72) = null_get_extension_channel;
    *(_QWORD *)(v11 + 80) = null_get_ctl_noisefloor;
    *(_QWORD *)(v11 + 88) = null_get_ext_noisefloor;
    *(_QWORD *)(v11 + 96) = null_configure_spectral;
    *(_QWORD *)(v11 + 104) = null_get_spectral_config;
    *(_QWORD *)(v11 + 112) = null_get_ent_spectral_mask;
    *(_QWORD *)(v11 + 120) = null_get_mac_address;
    *(_QWORD *)(v11 + 128) = null_get_current_channel;
    *(_QWORD *)(v11 + 136) = null_reset_hw;
    *(_QWORD *)(v11 + 144) = null_get_chain_noise_floor;
    *(_QWORD *)(v11 + 152) = null_spectral_process_phyerr;
    *(_QWORD *)(v11 + 160) = null_process_spectral_report;
    qdf_trace_msg(
      0x56u,
      4u,
      "%s: SPECTRAL : %s not registered\n",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "null_get_capability",
      "get_capability");
    qdf_trace_msg(
      0x56u,
      4u,
      "%s: HAL_CAP_PHYDIAG : Capable",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "target_if_pdev_spectral_init");
    v44 = *(unsigned int (__fastcall **)(__int64, __int64))(v11 + 16);
    if ( *((_DWORD *)v44 - 1) != 182839231 )
      __break(0x8228u);
    if ( v44(v11, 1) )
      qdf_trace_msg(
        0x56u,
        4u,
        "%s: HAL_CAP_RADAR   : Capable",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "target_if_pdev_spectral_init");
    v53 = *(unsigned int (__fastcall **)(__int64, __int64))(v11 + 16);
    if ( *((_DWORD *)v53 - 1) != 182839231 )
      __break(0x8228u);
    if ( v53(v11, 2) )
      qdf_trace_msg(
        0x56u,
        4u,
        "%s: HAL_CAP_SPECTRAL_SCAN : Capable",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "target_if_pdev_spectral_init");
    *(_DWORD *)(v11 + 344) = 0;
    *(_QWORD *)(v11 + 352) = 0;
    *(_DWORD *)(v11 + 904) = 0;
    *(_QWORD *)(v11 + 912) = 0;
    qdf_mem_set((void *)(v11 + 456), 0x30u, 0);
    v62 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
    if ( *((_DWORD *)v62 - 1) != 1102547714 )
      __break(0x8228u);
    *(_QWORD *)(v11 + 496) = v62(v11);
    if ( v25 - 23 < 0xF || v25 <= 0x2B && ((1LL << v25) & 0xF8000100000LL) != 0 )
      *(_BYTE *)(v11 + 1386) = 1;
    v71 = v25 - 26;
    if ( v25 - 26 > 0x11 )
    {
      v74 = 0;
      v75 = 0;
      v76 = 16;
      v73 = 257;
      v72 = 3;
    }
    else
    {
      v72 = byte_A2CB18[v71];
      v73 = word_A2CB2C[v71];
      v74 = dword_A2CAD0[v71];
      v75 = byte_A2CB50[v71];
      v76 = byte_A2CB64[v71];
    }
    *(_DWORD *)(v11 + 1392) = v74;
    *(_BYTE *)(v11 + 1412) = v72;
    *(_WORD *)(v11 + 1398) = v73;
    *(_BYTE *)(v11 + 1396) = v75;
    *(_BYTE *)(v11 + 1397) = v76;
    *(_DWORD *)(v11 + 1400) = 0;
    if ( v71 > 0x11 )
    {
      v78 = 0;
      v79 = 1;
    }
    else
    {
      v78 = dword_A2CB78[v71];
      v79 = dword_A2CBC0[v71];
    }
    v80 = v25 - 20;
    *(_DWORD *)(v11 + 1404) = v78;
    *(_DWORD *)(v11 + 1408) = v79;
    if ( v25 - 20 > 0x17 )
    {
      v81 = 0;
      v82 = 1;
    }
    else
    {
      v81 = dword_A2CC08[v80];
      v82 = byte_A2CC68[v80];
    }
    *(_DWORD *)(v11 + 1348) = v81;
    *(_BYTE *)(v11 + 1442) = v82;
    if ( v80 > 0x17 )
      v83 = 0;
    else
      v83 = byte_A2CC80[v80];
    *(_BYTE *)(v11 + 1344) = v83;
    *(_BYTE *)(v11 + 1345) = v83;
    *(_BYTE *)(v11 + 1346) = v25 == 24;
    if ( v25 <= 0x2B && ((1LL << v25) & 0xFBFFFB00000LL) != 0 )
    {
      v84 = 3;
      v85 = 2;
      v86 = -6;
      v87 = 1;
      v88 = 2;
    }
    else
    {
      v87 = 0;
      v84 = -5;
      v88 = -7;
      v86 = -69;
      v85 = 1;
    }
    *(_BYTE *)(v11 + 1258) = v84;
    *(_DWORD *)(v11 + 1252) = v85;
    *(_BYTE *)(v11 + 1256) = v86;
    *(_BYTE *)(v11 + 1257) = v88;
    *(_BYTE *)(v11 + 1259) = 4;
    if ( v25 <= 0x29 && ((1LL << v25) & 0x28900000000LL) != 0 )
    {
      v89 = *(_QWORD *)v11;
      *(_WORD *)(v11 + 1444) = 5;
      *(_WORD *)(v11 + 1464) = 4095;
      v135[0] = 0;
      v98 = 0;
      if ( (unsigned int)wlan_reg_is_chwidth_supported(v89, 0, v135, v63, v64, v65, v66, v67, v68, v69, v70) )
        goto LABEL_80;
      v99 = v135[0];
      v100 = *(_QWORD *)v11;
      v135[0] = 0;
      v98 = 1;
      v101 = v99 ? 9 : -1;
      *(_WORD *)(v11 + 1446) = v101;
      if ( (unsigned int)wlan_reg_is_chwidth_supported(v100, 1u, v135, v90, v91, v92, v93, v94, v95, v96, v97) )
        goto LABEL_80;
      v102 = *(_QWORD *)v11;
      v98 = 2;
      v103 = v135[0] ? 10 : -1;
      *(_WORD *)(v11 + 1448) = v103;
      v135[0] = 0;
      if ( (unsigned int)wlan_reg_is_chwidth_supported(v102, 2u, v135, v90, v91, v92, v93, v94, v95, v96, v97) )
        goto LABEL_80;
      v104 = *(_QWORD *)v11;
      v98 = 3;
      v105 = v135[0] ? 11 : -1;
      *(_WORD *)(v11 + 1450) = v105;
      v135[0] = 0;
      if ( (unsigned int)wlan_reg_is_chwidth_supported(v104, 3u, v135, v90, v91, v92, v93, v94, v95, v96, v97) )
        goto LABEL_80;
      v106 = *(_QWORD *)v11;
      v98 = 4;
      v107 = v135[0] ? 11 : -1;
      *(_WORD *)(v11 + 1452) = v107;
      v135[0] = 0;
      if ( (unsigned int)wlan_reg_is_chwidth_supported(v106, 4u, v135, v90, v91, v92, v93, v94, v95, v96, v97) )
        goto LABEL_80;
      v108 = *(_QWORD *)v11;
      v98 = 5;
      v109 = v135[0] ? 11 : -1;
      *(_WORD *)(v11 + 1454) = v109;
      v135[0] = 0;
      if ( (unsigned int)wlan_reg_is_chwidth_supported(v108, 5u, v135, v90, v91, v92, v93, v94, v95, v96, v97) )
        goto LABEL_80;
      v110 = *(_QWORD *)v11;
      v98 = 6;
      v111 = v135[0] ? 11 : -1;
      *(_WORD *)(v11 + 1456) = v111;
      v135[0] = 0;
      if ( (unsigned int)wlan_reg_is_chwidth_supported(v110, 6u, v135, v90, v91, v92, v93, v94, v95, v96, v97) )
        goto LABEL_80;
      v112 = *(_QWORD *)v11;
      v98 = 7;
      v113 = v135[0] ? 11 : -1;
      *(_WORD *)(v11 + 1458) = v113;
      v135[0] = 0;
      if ( (unsigned int)wlan_reg_is_chwidth_supported(v112, 7u, v135, v90, v91, v92, v93, v94, v95, v96, v97)
        || ((v114 = *(_QWORD *)v11, v98 = 8, !v135[0]) ? (v115 = -1) : (v115 = 11),
            *(_WORD *)(v11 + 1460) = v115,
            v135[0] = 0,
            (unsigned int)wlan_reg_is_chwidth_supported(v114, 8u, v135, v90, v91, v92, v93, v94, v95, v96, v97)) )
      {
LABEL_80:
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: Unable to check if ch_width(%d) is supported",
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          "target_if_init_spectral_param_min_max_be",
          v98);
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: Failed to initialize parameter min max values",
          v116,
          v117,
          v118,
          v119,
          v120,
          v121,
          v122,
          v123,
          "target_if_pdev_spectral_init");
LABEL_81:
        qdf_trace_msg(
          0x56u,
          4u,
          "%s: spectral detach",
          v124,
          v125,
          v126,
          v127,
          v128,
          v129,
          v130,
          v131,
          "target_if_spectral_detach");
        hrtimer_cancel(v11 + 2096);
        hrtimer_cancel(v11 + 2192);
        goto LABEL_29;
      }
      if ( v135[0] )
        v134 = 11;
      else
        v134 = -1;
      *(_WORD *)(v11 + 1462) = v134;
    }
    else if ( v87 )
    {
      *(_WORD *)(v11 + 1464) = 4095;
      *(_DWORD *)(v11 + 1444) = 589829;
      if ( v25 <= 0x2B && ((1LL << v25) & 0x834EC000000LL) != 0 )
        v132 = 0xA000A000A000ALL;
      else
        v132 = 0x9000900090009LL;
      *(_QWORD *)(v11 + 1448) = v132;
    }
    else
    {
      *(_DWORD *)(v11 + 1452) = 589833;
      *(_QWORD *)(v11 + 1444) = 0x9000900090001LL;
    }
    *(_QWORD *)(v11 + 281) = 0x100010001000100LL;
    *(_WORD *)(v11 + 289) = 256;
    *(_QWORD *)(v11 + 300) = 0x1000100010001LL;
    *(_QWORD *)(v11 + 310) = 0x1000100010001LL;
    *(_QWORD *)(v11 + 318) = 0x1000100010001LL;
    *(_DWORD *)(v11 + 292) = 65537;
    *(_QWORD *)(v11 + 326) = 0x1000100010001LL;
    *(_QWORD *)(v11 + 232) = 0x1000100010001LL;
    *(_QWORD *)(v11 + 240) = 0x1000100010001LL;
    *(_QWORD *)(v11 + 248) = 0x1000100010001LL;
    *(_QWORD *)(v11 + 256) = 0x1000100010001LL;
    *(_QWORD *)(v11 + 264) = 0x1000100010001LL;
    *(_QWORD *)(v11 + 272) = 0x1000100010001LL;
    *(_WORD *)(v11 + 296) = 1;
    *(_BYTE *)(v11 + 298) = 1;
    *(_BYTE *)(v11 + 308) = 1;
    *(_QWORD *)(v11 + 334) = 0x1000100010001LL;
    *(_WORD *)(v11 + 342) = 1;
    *(_BYTE *)(v11 + 280) = 0;
    *(_BYTE *)(v11 + 243) = 1;
    *(_BYTE *)(v11 + 235) = 1;
    *(_BYTE *)(v11 + 253) = 1;
    *(_BYTE *)(v11 + 299) = 1;
    *(_BYTE *)(v11 + 291) = 1;
    *(_BYTE *)(v11 + 309) = 1;
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD))target_if_init_spectral_capability)(v11, v25) )
      goto LABEL_29;
    target_if_init_spectral_ops(v11);
    *(_QWORD *)(v11 + 1368) = 0;
    *(_QWORD *)(v11 + 1360) = 0;
    *(_QWORD *)(v11 + 1352) = 0;
    *(_WORD *)(v11 + 800) = 0;
    *(_DWORD *)(v11 + 976) = 0;
    *(_QWORD *)(v11 + 984) = 0;
    *(_BYTE *)(v11 + 1076) = 0;
    *(_DWORD *)(v11 + 1080) = 0;
    *(_QWORD *)(v11 + 1088) = 0;
    *(_BYTE *)(v11 + 1180) = 0;
    memcpy((void *)(v11 + 8), &spectral_ops, 0xB0u);
    if ( !(unsigned int)target_if_spectral_check_hw_capability(v11) )
      goto LABEL_81;
    *(_WORD *)(v11 + 1248) = 0;
    *(_BYTE *)(v11 + 1250) = 0;
    if ( v25 == 17 || v25 == 15 )
    {
      *(_WORD *)(v11 + 1248) = 257;
      *(_BYTE *)(v11 + 1250) = 1;
    }
    else if ( v25 == 9 && v27 == 1 )
    {
      *(_BYTE *)(v11 + 1250) = 1;
LABEL_100:
      v133 = *(_DWORD *)(v11 + 1252);
      *(_BYTE *)(v11 + 1328) = 0;
      if ( v133 == 2 )
        *(_QWORD *)(v11 + 1376) = 0;
      *(_DWORD *)(v11 + 2088) = 0;
      *(_DWORD *)(v11 + 2160) = 1;
      *(_QWORD *)(v11 + 2176) = target_if_spectral_scan_timeout_handler;
      *(_QWORD *)(v11 + 2168) = v11 + 2096;
      hrtimer_init();
      *(_QWORD *)(v11 + 2136) = _qdf_hrtimer_cb;
      *(_DWORD *)(v11 + 2184) = 1;
      *(_DWORD *)(v11 + 2256) = 1;
      *(_QWORD *)(v11 + 2272) = target_if_spectral_scan_timeout_handler;
      *(_QWORD *)(v11 + 2264) = v11 + 2192;
      hrtimer_init();
      *(_QWORD *)(v11 + 2232) = _qdf_hrtimer_cb;
      *(_DWORD *)(v11 + 1576) = 0;
      *(_QWORD *)(v11 + 1584) = 0;
      *(_DWORD *)(v11 + 1960) = 0;
      *(_QWORD *)(v11 + 1968) = 0;
      *(_DWORD *)(v11 + 1880) = 0;
      *(_QWORD *)(v11 + 1888) = 0;
      goto LABEL_31;
    }
    if ( v25 == 17 || v25 == 15 )
      *(_BYTE *)(v11 + 1251) = 1;
    goto LABEL_100;
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return v11;
}
