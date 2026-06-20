__int64 __fastcall wlan_ipa_wdi_opt_dpath_flt_add_cb(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char v10; // w8
  int v12; // w2
  int v13; // w3
  int v14; // w4
  int v15; // w5
  int v16; // w6
  int v17; // w7
  const char *v18; // x1
  __int64 result; // x0
  __int64 v20; // x21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w3
  int v31; // w4
  int v32; // w5
  int v33; // w6
  int v34; // w7
  unsigned __int8 *v35; // x26
  __int64 v36; // x20
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  int v45; // w3
  int v46; // w4
  int v47; // w5
  int v48; // w6
  int v49; // w7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  int v58; // w3
  int v59; // w4
  int v60; // w5
  int v61; // w6
  int v62; // w7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  int v71; // w3
  int v72; // w4
  int v73; // w5
  int v74; // w6
  int v75; // w7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  int v84; // w3
  int v85; // w4
  int v86; // w5
  int v87; // w6
  int v88; // w7
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  int v97; // w3
  int v98; // w4
  int v99; // w5
  int v100; // w6
  int v101; // w7
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  int v110; // w3
  int v111; // w4
  int v112; // w5
  int v113; // w6
  int v114; // w7
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  int v123; // w3
  int v124; // w4
  int v125; // w5
  int v126; // w6
  int v127; // w7
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  int v136; // w3
  int v137; // w4
  int v138; // w5
  int v139; // w6
  int v140; // w7
  int v141; // w2
  const char *v142; // x1
  unsigned int v143; // w8
  __int64 v144; // x21
  int v145; // w8
  int v146; // w8
  __int64 v147; // x9
  int v148; // w9
  unsigned int v149; // w9
  double v150; // d0
  double v151; // d1
  double v152; // d2
  double v153; // d3
  double v154; // d4
  double v155; // d5
  double v156; // d6
  double v157; // d7
  double v158; // d0
  double v159; // d1
  double v160; // d2
  double v161; // d3
  double v162; // d4
  double v163; // d5
  double v164; // d6
  double v165; // d7
  int v166; // w5
  int v167; // w6
  int v168; // w7
  double v169; // d0
  double v170; // d1
  double v171; // d2
  double v172; // d3
  double v173; // d4
  double v174; // d5
  double v175; // d6
  double v176; // d7
  unsigned int v177; // w0
  double v178; // d0
  double v179; // d1
  double v180; // d2
  double v181; // d3
  double v182; // d4
  double v183; // d5
  double v184; // d6
  double v185; // d7
  unsigned int v186; // w20
  int v187; // w21
  int v188; // w4
  int v189; // w5
  int v190; // w6
  int v191; // w7
  char v192; // [xsp+0h] [xbp-20h]
  char v193; // [xsp+0h] [xbp-20h]
  char v194; // [xsp+0h] [xbp-20h]
  char v195; // [xsp+0h] [xbp-20h]
  char v196; // [xsp+0h] [xbp-20h]
  char v197; // [xsp+0h] [xbp-20h]
  char v198; // [xsp+0h] [xbp-20h]
  char v199; // [xsp+0h] [xbp-20h]
  __int64 v200; // [xsp+8h] [xbp-18h]
  unsigned int v201; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v202; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v203; // [xsp+18h] [xbp-8h]

  v203 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_BYTE *)(a1 + 3440);
  v202 = 0;
  v201 = 0;
  if ( (v10 & 1) != 0 || *(_BYTE *)(a1 + 3441) == 1 )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: Pipes are going down. Reject flt add request",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_ipa_wdi_opt_dpath_flt_add_cb");
    v18 = "Pipes are going down. Reject flt add request";
LABEL_4:
    wlan_ipa_log_message((int)"wlan_ipa_wdi_opt_dpath_flt_add_cb", (int)v18, v12, v13, v14, v15, v16, v17, v192);
    goto LABEL_5;
  }
  v20 = *a2;
  if ( !lmac_get_htc_hdl(*(_QWORD *)a1, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: HTC Handle is null",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wlan_ipa_wdi_opt_dpath_flt_add_cb");
    v18 = "HTC Handle is null";
    goto LABEL_4;
  }
  if ( (*(_BYTE *)(a1 + 7438) & 1) == 0 )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: IPA flt not reserved before adding",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wlan_ipa_wdi_opt_dpath_flt_add_cb");
    goto LABEL_5;
  }
  if ( (unsigned int)v20 > 2 )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: Wrong IPA flt count %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wlan_ipa_wdi_opt_dpath_flt_add_cb",
      (unsigned int)v20);
    wlan_ipa_log_message(
      (int)"wlan_ipa_wdi_opt_dpath_flt_add_cb",
      (int)"Wrong IPA flt count %d",
      v20,
      v30,
      v31,
      v32,
      v33,
      v34,
      v192);
    goto LABEL_5;
  }
  v200 = v20;
  if ( !(_DWORD)v20 )
  {
LABEL_31:
    *(_WORD *)(a1 + 7520) = 256;
    *(_BYTE *)(a1 + 7522) = v200;
    qdf_event_reset(a1 + 8072);
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: opt_dp: op %d, pdev_id %d. num_flts %d",
      v158,
      v159,
      v160,
      v161,
      v162,
      v163,
      v164,
      v165,
      "wlan_ipa_wdi_opt_dpath_flt_add_cb",
      *(unsigned __int8 *)(a1 + 7521),
      *(unsigned __int8 *)(a1 + 7520),
      (unsigned int)v200);
    wlan_ipa_log_message(
      (int)"wlan_ipa_wdi_opt_dpath_flt_add_cb",
      (int)"opt_dp: op %d, pdev_id %d. num_flts %d",
      *(unsigned __int8 *)(a1 + 7521),
      *(unsigned __int8 *)(a1 + 7520),
      v200,
      v166,
      v167,
      v168,
      v192);
    cdp_ipa_rx_cce_super_rule_setup(*(_QWORD *)(a1 + 1456), v169, v170, v171, v172, v173, v174, v175, v176);
    v177 = qdf_wait_single_event(a1 + 8072, 0x64u);
    v186 = *(_DWORD *)(a1 + 7524);
    if ( v177 | v186 )
    {
      v187 = v177;
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: opt_dp: error on filter add evt, status - %d, response - %d",
        v178,
        v179,
        v180,
        v181,
        v182,
        v183,
        v184,
        v185,
        "wlan_ipa_wdi_opt_dpath_flt_add_cb",
        v177,
        v186);
      wlan_ipa_log_message(
        (int)"wlan_ipa_wdi_opt_dpath_flt_add_cb",
        (int)"opt_dp: error on filter add evt, status - %d, response - %d",
        v187,
        v186,
        v188,
        v189,
        v190,
        v191,
        v199);
      if ( v187 )
        v186 = v187;
      wlan_ipa_wdi_opt_dpath_clean_db(a1);
      result = v186;
    }
    else
    {
      result = 0;
      *(_BYTE *)(a1 + 7580) = 0;
      *(_BYTE *)(a1 + 7684) = 0;
    }
    goto LABEL_6;
  }
  v35 = a2 + 40;
  v36 = v20;
  while ( *(_BYTE *)(a1 + 7581) != 1 )
  {
    v143 = 0;
LABEL_21:
    v144 = a1 + 7528 + 104LL * v143;
    *((_DWORD *)v35 + 2) = v143 | 0xC;
    *(_BYTE *)v144 = 1;
    v145 = *((_DWORD *)v35 + 2);
    *(_WORD *)(v144 + 52) = 257;
    *(_DWORD *)(v144 + 48) = v145;
    if ( *(v35 - 36) )
    {
      if ( *(v35 - 36) != 1 )
      {
        qdf_trace_msg(
          0x61u,
          2u,
          "%s: Wrong IPA version %d",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "wlan_ipa_wdi_opt_dpath_flt_add_cb");
        goto LABEL_5;
      }
      v146 = 56710;
    }
    else
    {
      v146 = 8;
    }
    v147 = *(_QWORD *)(a1 + 1464);
    *(_WORD *)(v144 + 42) = v146;
    if ( (*(_BYTE *)(v147 + 1) & 8) != 0 )
    {
      v148 = *v35;
      if ( v148 == 17 || v148 == 6 )
      {
        *(_BYTE *)(v144 + 41) = v148;
        *(_WORD *)(v144 + 44) = bswap32(*((unsigned __int16 *)v35 + 1)) >> 16;
        *(_WORD *)(v144 + 46) = bswap32(*((unsigned __int16 *)v35 + 2)) >> 16;
      }
    }
    if ( v146 == 56710 )
    {
      v202 = bswap32(*((_DWORD *)v35 - 8));
      qdf_mem_copy((void *)(v144 + 9), &v202, 4u);
      v202 = bswap32(*((_DWORD *)v35 - 7));
      qdf_mem_copy((void *)(v144 + 13), &v202, 4u);
      v202 = bswap32(*((_DWORD *)v35 - 6));
      qdf_mem_copy((void *)(v144 + 17), &v202, 4u);
      v202 = bswap32(*((_DWORD *)v35 - 5));
      qdf_mem_copy((void *)(v144 + 21), &v202, 4u);
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: ipv6 src addr rxed from ipa 0x%x",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "wlan_ipa_wdi_opt_dpath_flt_add_cb",
        *((unsigned int *)v35 - 8));
      wlan_ipa_log_message(
        (int)"wlan_ipa_wdi_opt_dpath_flt_add_cb",
        (int)"ipv6 src addr rxed from ipa 0x%x",
        *((_DWORD *)v35 - 8),
        v45,
        v46,
        v47,
        v48,
        v49,
        v192);
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: ipv6 src addr rxed from ipa 0x%x",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "wlan_ipa_wdi_opt_dpath_flt_add_cb",
        *((unsigned int *)v35 - 7));
      wlan_ipa_log_message(
        (int)"wlan_ipa_wdi_opt_dpath_flt_add_cb",
        (int)"ipv6 src addr rxed from ipa 0x%x",
        *((_DWORD *)v35 - 7),
        v58,
        v59,
        v60,
        v61,
        v62,
        v193);
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: ipv6 src addr rxed from ipa 0x%x",
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        "wlan_ipa_wdi_opt_dpath_flt_add_cb",
        *((unsigned int *)v35 - 6));
      wlan_ipa_log_message(
        (int)"wlan_ipa_wdi_opt_dpath_flt_add_cb",
        (int)"ipv6 src addr rxed from ipa 0x%x",
        *((_DWORD *)v35 - 6),
        v71,
        v72,
        v73,
        v74,
        v75,
        v194);
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: ipv6 src addr rxed from ipa 0x%x",
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        "wlan_ipa_wdi_opt_dpath_flt_add_cb",
        *((unsigned int *)v35 - 5));
      wlan_ipa_log_message(
        (int)"wlan_ipa_wdi_opt_dpath_flt_add_cb",
        (int)"ipv6 src addr rxed from ipa 0x%x",
        *((_DWORD *)v35 - 5),
        v84,
        v85,
        v86,
        v87,
        v88,
        v195);
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: ipv6 sent to FW 0x%x",
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        "wlan_ipa_wdi_opt_dpath_flt_add_cb",
        *(unsigned int *)(v144 + 9));
      wlan_ipa_log_message(
        (int)"wlan_ipa_wdi_opt_dpath_flt_add_cb",
        (int)"ipv6 sent to FW 0x%x",
        *(_DWORD *)(v144 + 9),
        v97,
        v98,
        v99,
        v100,
        v101,
        v196);
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: ipv6 sent to FW 0x%x",
        v102,
        v103,
        v104,
        v105,
        v106,
        v107,
        v108,
        v109,
        "wlan_ipa_wdi_opt_dpath_flt_add_cb",
        *(unsigned int *)(v144 + 13));
      wlan_ipa_log_message(
        (int)"wlan_ipa_wdi_opt_dpath_flt_add_cb",
        (int)"ipv6 sent to FW 0x%x",
        *(_DWORD *)(v144 + 13),
        v110,
        v111,
        v112,
        v113,
        v114,
        v197);
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: ipv6 sent to FW 0x%x",
        v115,
        v116,
        v117,
        v118,
        v119,
        v120,
        v121,
        v122,
        "wlan_ipa_wdi_opt_dpath_flt_add_cb",
        *(unsigned int *)(v144 + 17));
      wlan_ipa_log_message(
        (int)"wlan_ipa_wdi_opt_dpath_flt_add_cb",
        (int)"ipv6 sent to FW 0x%x",
        *(_DWORD *)(v144 + 17),
        v123,
        v124,
        v125,
        v126,
        v127,
        v198);
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: ipv6 sent to FW 0x%x",
        v128,
        v129,
        v130,
        v131,
        v132,
        v133,
        v134,
        v135,
        "wlan_ipa_wdi_opt_dpath_flt_add_cb",
        *(unsigned int *)(v144 + 21));
      v141 = *(_DWORD *)(v144 + 21);
      v142 = "ipv6 sent to FW 0x%x";
    }
    else
    {
      v149 = bswap32(*((_DWORD *)v35 - 7));
      v202 = bswap32(*((_DWORD *)v35 - 8));
      v201 = v149;
      qdf_mem_copy((void *)(v144 + 1), &v202, 4u);
      qdf_mem_copy((void *)(v144 + 5), &v201, 4u);
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: ipv4 sent to FW 0x%x",
        v150,
        v151,
        v152,
        v153,
        v154,
        v155,
        v156,
        v157,
        "wlan_ipa_wdi_opt_dpath_flt_add_cb",
        v202);
      v141 = v202;
      v142 = "ipv4 sent to FW 0x%x";
    }
    wlan_ipa_log_message((int)"wlan_ipa_wdi_opt_dpath_flt_add_cb", (int)v142, v141, v136, v137, v138, v139, v140, v192);
    --v36;
    v35 += 48;
    if ( !v36 )
      goto LABEL_31;
  }
  if ( *(_BYTE *)(a1 + 7685) != 1 )
  {
    v143 = 1;
    goto LABEL_21;
  }
  qdf_trace_msg(
    0x61u,
    2u,
    "%s: Wrong IPA flt count %d, i=%d",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "wlan_ipa_wdi_opt_dpath_flt_add_cb",
    v200,
    2);
LABEL_5:
  result = 49;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
