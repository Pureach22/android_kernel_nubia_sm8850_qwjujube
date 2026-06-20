__int64 __fastcall send_roam_scan_offload_ap_profile_cmd_tlv(
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
  unsigned __int8 v12; // w26
  int v13; // w8
  unsigned __int8 v14; // w10
  unsigned __int8 v15; // w8
  int v16; // w9
  int v17; // w24
  __int64 v18; // x0
  _DWORD *v19; // x27
  __int64 v20; // x21
  int v21; // w8
  size_t v22; // x2
  int v23; // w8
  __int64 v24; // x4
  __int64 v25; // x7
  int v26; // w13
  int v27; // w9
  __int64 v28; // x5
  __int64 v29; // x6
  int v30; // w10
  int v31; // w11
  int v32; // w12
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  int v81; // w8
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  int v90; // w8
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  _DWORD *v123; // x23
  int *v124; // x22
  __int64 result; // x0
  __int64 v126; // x11
  _DWORD *v127; // x8
  int v128; // w13
  unsigned __int8 *v129; // x12
  unsigned int v130; // w13
  unsigned int v131; // w11
  int v132; // w11
  unsigned int v133; // w11
  int v134; // w11
  unsigned int v135; // w10
  int v136; // w9
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  int *v145; // x8
  int v146; // w9
  __int64 v147; // x4
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  unsigned int v156; // w19
  __int64 v157; // [xsp+0h] [xbp-90h]
  __int64 v158; // [xsp+0h] [xbp-90h]
  __int64 v159; // [xsp+0h] [xbp-90h]
  __int64 v160; // [xsp+8h] [xbp-88h]
  __int64 v161; // [xsp+10h] [xbp-80h]
  __int64 v162; // [xsp+18h] [xbp-78h]
  __int64 v163; // [xsp+20h] [xbp-70h]
  __int64 v164; // [xsp+28h] [xbp-68h]
  __int64 v165; // [xsp+30h] [xbp-60h]
  char v166[4]; // [xsp+84h] [xbp-Ch] BYREF
  __int64 v167; // [xsp+88h] [xbp-8h]

  v167 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v166[0] = 0;
  if ( (wmi_service_enabled(a1, 0xD3u, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
  {
    v12 = 0;
    v13 = 296;
  }
  else
  {
    v14 = *((_DWORD *)a2 + 81) != -1;
    if ( *((_DWORD *)a2 + 79) != -1 )
      ++v14;
    if ( *((_DWORD *)a2 + 83) != -1 )
      ++v14;
    if ( *((_DWORD *)a2 + 85) != -1 )
      ++v14;
    if ( *((_DWORD *)a2 + 87) != -1 )
      ++v14;
    if ( *((_DWORD *)a2 + 89) != -1 )
      ++v14;
    if ( *((_DWORD *)a2 + 91) != -1 )
      ++v14;
    if ( *((_DWORD *)a2 + 93) != -1 )
      ++v14;
    if ( *((_DWORD *)a2 + 95) != -1 )
      ++v14;
    if ( *((_DWORD *)a2 + 97) != -1 )
      ++v14;
    if ( *((_DWORD *)a2 + 99) != -1 )
      ++v14;
    if ( *((_DWORD *)a2 + 101) != -1 )
      ++v14;
    if ( *((_DWORD *)a2 + 103) != -1 )
      ++v14;
    if ( *((_DWORD *)a2 + 105) != -1 )
      ++v14;
    if ( *((_DWORD *)a2 + 107) != -1 )
      ++v14;
    if ( *((_DWORD *)a2 + 109) != -1 )
      ++v14;
    if ( *((_DWORD *)a2 + 111) != -1 )
      ++v14;
    if ( *((_DWORD *)a2 + 113) != -1 )
      ++v14;
    if ( *((_DWORD *)a2 + 115) == -1 )
      v15 = v14;
    else
      v15 = v14 + 1;
    if ( *((_DWORD *)a2 + 117) == -1 )
      v12 = v15;
    else
      v12 = v15 + 1;
    v13 = 12 * v12 + 332;
  }
  if ( *((_DWORD *)a2 + 50) )
    v13 += 76;
  if ( a2[476] )
    v16 = 44;
  else
    v16 = 4;
  v17 = v13 + v16 + 4 * *((_DWORD *)a2 + 18);
  v18 = wmi_buf_alloc_fl(a1, v17 + 4, "send_roam_scan_offload_ap_profile_cmd_tlv", 0x1548u);
  if ( !v18 )
  {
    result = 2;
    goto LABEL_93;
  }
  v19 = *(_DWORD **)(v18 + 224);
  v20 = v18;
  *v19 = 11403272;
  v21 = *a2;
  v19[1] = 0;
  v19[2] = v21;
  v19[3] = 11468868;
  v19[4] = *((_DWORD *)a2 + 1);
  v19[5] = *((_DWORD *)a2 + 2);
  v19[20] = a2[68];
  v22 = a2[12];
  v19[6] = v22;
  qdf_mem_copy(v19 + 7, a2 + 13, v22);
  v23 = *((_DWORD *)a2 + 12);
  v24 = (unsigned int)v19[2];
  v25 = (unsigned int)v19[20];
  v26 = v19[6];
  v19[15] = v23;
  v27 = *((_DWORD *)a2 + 13);
  v28 = (unsigned int)v19[4];
  v29 = (unsigned int)v19[5];
  v19[16] = v27;
  v30 = *((_DWORD *)a2 + 14);
  v19[17] = v30;
  v31 = *((_DWORD *)a2 + 15);
  v19[18] = v31;
  v32 = *((_DWORD *)a2 + 16);
  v19[19] = v32;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev %d AP PROFILE: flags:%x rssi_thres:%d bg_rssi_thres:%d ssid:%.*s authmode:%d uc cipher:%d mc cipher:%d mc m"
    "gmt cipher:%d rssi abs thresh:%d",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "send_roam_scan_offload_ap_profile_cmd_tlv",
    v24,
    v28,
    v29,
    v25,
    v26,
    a2 + 13,
    v23,
    v27,
    v30,
    v31,
    v32);
  v19[21] = 44892356;
  v19[22] = *((_DWORD *)a2 + 30);
  v19[23] = *((_DWORD *)a2 + 31);
  v19[24] = *((_DWORD *)a2 + 32);
  v19[25] = *((_DWORD *)a2 + 33);
  v19[26] = *((_DWORD *)a2 + 34);
  v19[27] = *((_DWORD *)a2 + 35);
  v19[28] = *((_DWORD *)a2 + 36);
  v19[29] = *((_DWORD *)a2 + 37);
  v19[67] = *((_DWORD *)a2 + 67);
  v19[30] = *((_DWORD *)a2 + 38);
  v19[31] = *((_DWORD *)a2 + 39);
  v19[32] = *((_DWORD *)a2 + 40);
  v19[33] = *((_DWORD *)a2 + 41);
  v19[59] = *((_DWORD *)a2 + 42);
  v19[60] = *((_DWORD *)a2 + 43);
  v19[57] = *((_DWORD *)a2 + 50);
  v19[61] = *((_DWORD *)a2 + 44);
  wlan_mlme_get_mlo_prefer_percentage(**(_QWORD **)(a1 + 760), v166);
  v166[0] += 100;
  v19[69] = v166[0];
  v19[70] = *((_DWORD *)a2 + 69);
  v19[63] = a2[260];
  v19[64] = *((_DWORD *)a2 + 66);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: 11be score params weightage: EHT %d MLO 0x%x",
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    "send_update_mlo_roam_params");
  LODWORD(v165) = v19[32];
  LODWORD(v164) = v19[31];
  LODWORD(v163) = v19[30];
  LODWORD(v162) = v19[29];
  LODWORD(v161) = v19[28];
  LODWORD(v160) = v19[27];
  LODWORD(v157) = v19[26];
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Score params weightage: disable_bitmap %x rssi %d ht %d vht %d he %d BW %d band %d NSS %d ESP %d BF %d PCL %d OC"
    "E WAN %d APTX %d roam score algo %d subnet id %d sae-pk %d security %d mlo_etp_weight_pct %d sta_sap_mcc_pcnt %d",
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    "send_roam_scan_offload_ap_profile_cmd_tlv",
    (unsigned int)v19[22],
    (unsigned int)v19[23],
    (unsigned int)v19[24],
    (unsigned int)v19[25],
    v157,
    v160,
    v161,
    v162,
    v163,
    v164,
    v165,
    v19[33],
    v19[59],
    v19[57],
    v19[60],
    v19[61],
    v19[67],
    v19[69],
    v19[70]);
  v19[42] = *((_DWORD *)a2 + 45);
  v19[43] = *((_DWORD *)a2 + 46);
  v19[44] = *((_DWORD *)a2 + 47);
  v19[68] = *((_DWORD *)a2 + 68);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: bw_index_score %x band_index_score %x nss_index_score %x security_index_score %x",
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    "send_roam_scan_offload_ap_profile_cmd_tlv");
  v19[34] = -a2[208];
  v19[35] = -a2[209];
  v19[36] = -a2[210];
  v19[37] = a2[211];
  v19[38] = a2[212];
  v19[39] = a2[213];
  v19[40] = a2[214];
  v19[41] = -a2[215];
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Rssi scoring threshold: best RSSI %d good RSSI %d bad RSSI %d prefer 5g threshold %d",
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    "send_roam_scan_offload_ap_profile_cmd_tlv");
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Good RSSI score for each slot %d bad RSSI score for each slot %d good bucket %d bad bucket %d",
    v73,
    v74,
    v75,
    v76,
    v77,
    v78,
    v79,
    v80,
    "send_roam_scan_offload_ap_profile_cmd_tlv",
    (unsigned int)v19[37],
    (unsigned int)v19[38],
    (unsigned int)v19[39],
    (unsigned int)v19[40]);
  v19[45] = a2[220];
  v19[46] = *((_DWORD *)a2 + 56);
  v19[47] = *((_DWORD *)a2 + 57);
  v19[48] = *((_DWORD *)a2 + 58);
  v81 = *((_DWORD *)a2 + 59);
  v19[49] = v81;
  LODWORD(v158) = v81;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: ESP QBSS index weight: slots %d weight 0to3 %x weight 4to7 %x weight 8to11 %x weight 12to15 %x",
    v82,
    v83,
    v84,
    v85,
    v86,
    v87,
    v88,
    v89,
    "send_roam_scan_offload_ap_profile_cmd_tlv",
    v158);
  v19[50] = a2[240];
  v19[51] = *((_DWORD *)a2 + 61);
  v19[52] = *((_DWORD *)a2 + 62);
  v19[53] = *((_DWORD *)a2 + 63);
  v90 = *((_DWORD *)a2 + 64);
  v19[54] = v90;
  LODWORD(v159) = v90;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: OCE WAN index weight: slots %d weight 0to3 %x weight 4to7 %x weight 8to11 %x weight 12to15 %x",
    v91,
    v92,
    v93,
    v94,
    v95,
    v96,
    v97,
    v98,
    "send_roam_scan_offload_ap_profile_cmd_tlv",
    v159);
  v19[55] = *((_DWORD *)a2 + 48);
  v19[56] = *((_DWORD *)a2 + 49);
  v19[58] = *((_DWORD *)a2 + 51);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Roam score delta:%d Roam_trigger_bitmap:%x cand min score delta = %d",
    v99,
    v100,
    v101,
    v102,
    v103,
    v104,
    v105,
    v106,
    "send_roam_scan_offload_ap_profile_cmd_tlv");
  if ( (wmi_service_enabled(a1, 0xD3u, v107, v108, v109, v110, v111, v112, v113, v114) & 1) == 0 )
  {
    v126 = 0;
    v19[71] = (12 * v12) | 0x120000;
    v127 = v19 + 72;
    do
    {
      v129 = &a2[v126];
      if ( *(_DWORD *)&a2[v126 + 316] != -1 )
      {
        *v127 = 52494344;
        v130 = *((_DWORD *)v129 + 80) - 1;
        if ( v130 <= 0x13 )
          v128 = dword_B342D0[v130];
        else
          v128 = 0;
        v127[1] = v128;
        v127[2] = *((_DWORD *)v129 + 79);
        v127 += 3;
      }
      v126 += 8;
    }
    while ( v126 != 160 );
    *v127 = 1179684;
    v127[1] = 52559880;
    v131 = *((_DWORD *)a2 + 74) - 1;
    if ( v131 > 0x13 )
      v132 = 0;
    else
      v132 = dword_B342D0[v131];
    v127[2] = v132;
    v127[3] = *((_DWORD *)a2 + 73);
    v127[4] = 52559880;
    v133 = *((_DWORD *)a2 + 76) - 1;
    if ( v133 > 0x13 )
      v134 = 0;
    else
      v134 = dword_B342D0[v133];
    v127[5] = v134;
    v127[6] = *((_DWORD *)a2 + 75);
    v127[7] = 52559880;
    v135 = *((_DWORD *)a2 + 78) - 1;
    if ( v135 > 0x13 )
      v136 = 0;
    else
      v136 = dword_B342D0[v135];
    v127[8] = v136;
    v123 = v127 + 10;
    v127[9] = *((_DWORD *)a2 + 77);
    if ( *((_DWORD *)a2 + 50) )
      goto LABEL_52;
LABEL_71:
    v124 = v123 + 1;
    *v123 = 1179648;
    goto LABEL_72;
  }
  v123 = v19 + 73;
  *(_QWORD *)(v19 + 71) = 0x12000000120000LL;
  if ( !*((_DWORD *)a2 + 50) )
    goto LABEL_71;
LABEL_52:
  *v123 = 1179724;
  *(_QWORD *)(v123 + 1) = -4228644792LL;
  v123[17] = *((_DWORD *)a2 + 70);
  v123[18] = *((_DWORD *)a2 + 71);
  v123[19] = *((_DWORD *)a2 + 72);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Band weight 2 GHz:%d Band weight 5 GHz:%d, Band weight 6 GHz:%d",
    v115,
    v116,
    v117,
    v118,
    v119,
    v120,
    v121,
    v122,
    "send_roam_scan_offload_ap_profile_cmd_tlv");
  v124 = v123 + 20;
LABEL_72:
  if ( a2[476] != 1 )
    goto LABEL_87;
  *v124 = 1179688;
  v124[1] = 66388004;
  v124[2] = a2[477];
  qdf_mem_copy(v124 + 3, a2 + 478, a2[477]);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: [OWE_TRANSITION]: open ssid:%.*s",
    v137,
    v138,
    v139,
    v140,
    v141,
    v142,
    v143,
    v144,
    "send_roam_scan_offload_ap_profile_cmd_tlv",
    (unsigned int)v124[2],
    v124 + 3);
  v145 = v124 + 11;
  v146 = *((_DWORD *)a2 + 18);
  if ( v146 )
  {
    while ( 1 )
    {
      *v145 = (4 * (v146 & 0x3FFF)) | 0x100000;
      v124 = v145 + 1;
      if ( !*((_DWORD *)a2 + 18) )
        break;
      *v124 = *((_DWORD *)a2 + 19);
      v147 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v147 < 2 )
        goto LABEL_90;
      v145[2] = *((_DWORD *)a2 + 20);
      v147 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v147 < 3 )
        goto LABEL_90;
      v145[3] = *((_DWORD *)a2 + 21);
      v147 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v147 < 4 )
        goto LABEL_90;
      v145[4] = *((_DWORD *)a2 + 22);
      v147 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v147 < 5 )
        goto LABEL_90;
      v145[5] = *((_DWORD *)a2 + 23);
      v147 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v147 < 6 )
        goto LABEL_90;
      v145[6] = *((_DWORD *)a2 + 24);
      v147 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v147 < 7 )
        goto LABEL_90;
      v145[7] = *((_DWORD *)a2 + 25);
      v147 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v147 < 8 )
        goto LABEL_90;
      v145[8] = *((_DWORD *)a2 + 26);
      v147 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v147 < 9 )
        goto LABEL_90;
      v145[9] = *((_DWORD *)a2 + 27);
      v147 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v147 < 0xA )
        goto LABEL_90;
      v145[10] = *((_DWORD *)a2 + 28);
      v147 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v147 < 0xB )
        goto LABEL_90;
      v145[11] = *((_DWORD *)a2 + 29);
      v147 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v147 <= 0xB )
        goto LABEL_90;
      __break(0x5512u);
LABEL_87:
      v145 = v124 + 1;
      *v124 = 1179648;
      v146 = *((_DWORD *)a2 + 18);
      if ( !v146 )
        goto LABEL_88;
    }
    v147 = 0;
LABEL_90:
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: [Allowed Authmode]: num_allowed_authmode: %d",
      v115,
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      "send_roam_scan_offload_ap_profile_cmd_tlv",
      v147);
    ((void (__fastcall *)(__int64, __int64, int *, _QWORD))qdf_trace_hex_dump)(
      49,
      8,
      v124,
      (unsigned int)(4 * *((_DWORD *)a2 + 18)));
  }
  else
  {
LABEL_88:
    *v145 = 1179648;
  }
  wmi_mtrace(0xB005u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v20,
             v17 + 4,
             0xB005u,
             "send_roam_scan_offload_ap_profile_cmd_tlv",
             0x16A4u,
             v148,
             v149,
             v150,
             v151,
             v152,
             v153,
             v154,
             v155);
  if ( (_DWORD)result )
  {
    v156 = result;
    wmi_buf_free();
    result = v156;
  }
LABEL_93:
  _ReadStatusReg(SP_EL0);
  return result;
}
