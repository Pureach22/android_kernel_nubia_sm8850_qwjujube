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
  int v41; // w8
  int v42; // w9
  int v43; // w10
  int v44; // w11
  int v45; // w12
  int v46; // w13
  int v47; // w14
  int v48; // w15
  int v49; // w16
  int v50; // w17
  int v51; // w0
  int v52; // w1
  int v53; // w2
  int v54; // w3
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  int v87; // w8
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  int v96; // w8
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  _DWORD *v129; // x23
  int *v130; // x22
  __int64 result; // x0
  __int64 v132; // x11
  _DWORD *v133; // x8
  int v134; // w13
  unsigned __int8 *v135; // x12
  unsigned int v136; // w13
  unsigned int v137; // w11
  int v138; // w11
  unsigned int v139; // w11
  int v140; // w11
  unsigned int v141; // w10
  int v142; // w9
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  int *v151; // x8
  int v152; // w9
  __int64 v153; // x4
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7
  unsigned int v162; // w19
  __int64 v163; // [xsp+0h] [xbp-80h]
  __int64 v164; // [xsp+0h] [xbp-80h]
  __int64 v165; // [xsp+0h] [xbp-80h]
  __int64 v166; // [xsp+8h] [xbp-78h]
  __int64 v167; // [xsp+10h] [xbp-70h]
  __int64 v168; // [xsp+18h] [xbp-68h]
  __int64 v169; // [xsp+20h] [xbp-60h]
  __int64 v170; // [xsp+28h] [xbp-58h]
  __int64 v171; // [xsp+30h] [xbp-50h]

  if ( (wmi_service_enabled(a1, 0xD3u, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
  {
    v12 = 0;
    v13 = 296;
  }
  else
  {
    v14 = *((_DWORD *)a2 + 79) != -1;
    if ( *((_DWORD *)a2 + 77) != -1 )
      ++v14;
    if ( *((_DWORD *)a2 + 81) != -1 )
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
    if ( *((_DWORD *)a2 + 113) == -1 )
      v15 = v14;
    else
      v15 = v14 + 1;
    if ( *((_DWORD *)a2 + 115) == -1 )
      v12 = v15;
    else
      v12 = v15 + 1;
    v13 = 12 * v12 + 332;
  }
  if ( *((_DWORD *)a2 + 50) )
    v13 += 76;
  if ( a2[468] )
    v16 = 44;
  else
    v16 = 4;
  v17 = v13 + v16 + 4 * *((_DWORD *)a2 + 18);
  v18 = wmi_buf_alloc_fl(a1, v17 + 4, "send_roam_scan_offload_ap_profile_cmd_tlv", 0x1548u);
  if ( !v18 )
    return 2;
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
  v41 = *((_DWORD *)a2 + 34);
  v19[26] = v41;
  v42 = *((_DWORD *)a2 + 35);
  v19[27] = v42;
  v43 = *((_DWORD *)a2 + 36);
  v19[28] = v43;
  v44 = *((_DWORD *)a2 + 37);
  v19[29] = v44;
  v45 = *((_DWORD *)a2 + 65);
  v19[67] = v45;
  v46 = *((_DWORD *)a2 + 38);
  v19[30] = v46;
  v47 = *((_DWORD *)a2 + 39);
  v19[31] = v47;
  v48 = *((_DWORD *)a2 + 40);
  v19[32] = v48;
  v49 = *((_DWORD *)a2 + 41);
  v19[33] = v49;
  v50 = *((_DWORD *)a2 + 42);
  v19[59] = v50;
  v51 = *((_DWORD *)a2 + 43);
  v19[60] = v51;
  v52 = *((_DWORD *)a2 + 50);
  v19[57] = v52;
  v53 = *((_DWORD *)a2 + 44);
  v19[69] = 0;
  v19[61] = v53;
  v54 = *((_DWORD *)a2 + 67);
  v19[70] = v54;
  LODWORD(v171) = v48;
  LODWORD(v170) = v47;
  LODWORD(v169) = v46;
  LODWORD(v168) = v44;
  LODWORD(v167) = v43;
  LODWORD(v166) = v42;
  LODWORD(v163) = v41;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Score params weightage: disable_bitmap %x rssi %d ht %d vht %d he %d BW %d band %d NSS %d ESP %d BF %d PCL %d OC"
    "E WAN %d APTX %d roam score algo %d subnet id %d sae-pk %d security %d mlo_etp_weight_pct %d sta_sap_mcc_pcnt %d",
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    "send_roam_scan_offload_ap_profile_cmd_tlv",
    v163,
    v166,
    v167,
    v168,
    v169,
    v170,
    v171,
    v49,
    v50,
    v52,
    v51,
    v53,
    v45,
    0,
    v54);
  v19[42] = *((_DWORD *)a2 + 45);
  v19[43] = *((_DWORD *)a2 + 46);
  v19[44] = *((_DWORD *)a2 + 47);
  v19[68] = *((_DWORD *)a2 + 66);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: bw_index_score %x band_index_score %x nss_index_score %x security_index_score %x",
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
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
    v71,
    v72,
    v73,
    v74,
    v75,
    v76,
    v77,
    v78,
    "send_roam_scan_offload_ap_profile_cmd_tlv");
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Good RSSI score for each slot %d bad RSSI score for each slot %d good bucket %d bad bucket %d",
    v79,
    v80,
    v81,
    v82,
    v83,
    v84,
    v85,
    v86,
    "send_roam_scan_offload_ap_profile_cmd_tlv",
    (unsigned int)v19[37],
    (unsigned int)v19[38],
    (unsigned int)v19[39],
    (unsigned int)v19[40]);
  v19[45] = a2[220];
  v19[46] = *((_DWORD *)a2 + 56);
  v19[47] = *((_DWORD *)a2 + 57);
  v19[48] = *((_DWORD *)a2 + 58);
  v87 = *((_DWORD *)a2 + 59);
  v19[49] = v87;
  LODWORD(v164) = v87;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: ESP QBSS index weight: slots %d weight 0to3 %x weight 4to7 %x weight 8to11 %x weight 12to15 %x",
    v88,
    v89,
    v90,
    v91,
    v92,
    v93,
    v94,
    v95,
    "send_roam_scan_offload_ap_profile_cmd_tlv",
    v164);
  v19[50] = a2[240];
  v19[51] = *((_DWORD *)a2 + 61);
  v19[52] = *((_DWORD *)a2 + 62);
  v19[53] = *((_DWORD *)a2 + 63);
  v96 = *((_DWORD *)a2 + 64);
  v19[54] = v96;
  LODWORD(v165) = v96;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: OCE WAN index weight: slots %d weight 0to3 %x weight 4to7 %x weight 8to11 %x weight 12to15 %x",
    v97,
    v98,
    v99,
    v100,
    v101,
    v102,
    v103,
    v104,
    "send_roam_scan_offload_ap_profile_cmd_tlv",
    v165);
  v19[55] = *((_DWORD *)a2 + 48);
  v19[56] = *((_DWORD *)a2 + 49);
  v19[58] = *((_DWORD *)a2 + 51);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Roam score delta:%d Roam_trigger_bitmap:%x cand min score delta = %d",
    v105,
    v106,
    v107,
    v108,
    v109,
    v110,
    v111,
    v112,
    "send_roam_scan_offload_ap_profile_cmd_tlv");
  if ( (wmi_service_enabled(a1, 0xD3u, v113, v114, v115, v116, v117, v118, v119, v120) & 1) == 0 )
  {
    v132 = 0;
    v19[71] = (12 * v12) | 0x120000;
    v133 = v19 + 72;
    do
    {
      v135 = &a2[v132];
      if ( *(_DWORD *)&a2[v132 + 308] != -1 )
      {
        *v133 = 52494344;
        v136 = *((_DWORD *)v135 + 78) - 1;
        if ( v136 <= 0x13 )
          v134 = dword_A2E9E8[v136];
        else
          v134 = 0;
        v133[1] = v134;
        v133[2] = *((_DWORD *)v135 + 77);
        v133 += 3;
      }
      v132 += 8;
    }
    while ( v132 != 160 );
    *v133 = 1179684;
    v133[1] = 52559880;
    v137 = *((_DWORD *)a2 + 72) - 1;
    if ( v137 > 0x13 )
      v138 = 0;
    else
      v138 = dword_A2E9E8[v137];
    v133[2] = v138;
    v133[3] = *((_DWORD *)a2 + 71);
    v133[4] = 52559880;
    v139 = *((_DWORD *)a2 + 74) - 1;
    if ( v139 > 0x13 )
      v140 = 0;
    else
      v140 = dword_A2E9E8[v139];
    v133[5] = v140;
    v133[6] = *((_DWORD *)a2 + 73);
    v133[7] = 52559880;
    v141 = *((_DWORD *)a2 + 76) - 1;
    if ( v141 > 0x13 )
      v142 = 0;
    else
      v142 = dword_A2E9E8[v141];
    v133[8] = v142;
    v129 = v133 + 10;
    v133[9] = *((_DWORD *)a2 + 75);
    if ( *((_DWORD *)a2 + 50) )
      goto LABEL_52;
LABEL_71:
    v130 = v129 + 1;
    *v129 = 1179648;
    goto LABEL_72;
  }
  v129 = v19 + 73;
  *(_QWORD *)(v19 + 71) = 0x12000000120000LL;
  if ( !*((_DWORD *)a2 + 50) )
    goto LABEL_71;
LABEL_52:
  *v129 = 1179724;
  *(_QWORD *)(v129 + 1) = -4228644792LL;
  v129[17] = *((_DWORD *)a2 + 68);
  v129[18] = *((_DWORD *)a2 + 69);
  v129[19] = *((_DWORD *)a2 + 70);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Band weight 2 GHz:%d Band weight 5 GHz:%d, Band weight 6 GHz:%d",
    v121,
    v122,
    v123,
    v124,
    v125,
    v126,
    v127,
    v128,
    "send_roam_scan_offload_ap_profile_cmd_tlv");
  v130 = v129 + 20;
LABEL_72:
  if ( a2[468] != 1 )
    goto LABEL_87;
  *v130 = 1179688;
  v130[1] = 66388004;
  v130[2] = a2[469];
  qdf_mem_copy(v130 + 3, a2 + 470, a2[469]);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: [OWE_TRANSITION]: open ssid:%.*s",
    v143,
    v144,
    v145,
    v146,
    v147,
    v148,
    v149,
    v150,
    "send_roam_scan_offload_ap_profile_cmd_tlv",
    (unsigned int)v130[2],
    v130 + 3);
  v151 = v130 + 11;
  v152 = *((_DWORD *)a2 + 18);
  if ( v152 )
  {
    while ( 1 )
    {
      *v151 = (4 * (v152 & 0x3FFF)) | 0x100000;
      v130 = v151 + 1;
      if ( !*((_DWORD *)a2 + 18) )
        break;
      *v130 = *((_DWORD *)a2 + 19);
      v153 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v153 < 2 )
        goto LABEL_90;
      v151[2] = *((_DWORD *)a2 + 20);
      v153 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v153 < 3 )
        goto LABEL_90;
      v151[3] = *((_DWORD *)a2 + 21);
      v153 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v153 < 4 )
        goto LABEL_90;
      v151[4] = *((_DWORD *)a2 + 22);
      v153 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v153 < 5 )
        goto LABEL_90;
      v151[5] = *((_DWORD *)a2 + 23);
      v153 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v153 < 6 )
        goto LABEL_90;
      v151[6] = *((_DWORD *)a2 + 24);
      v153 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v153 < 7 )
        goto LABEL_90;
      v151[7] = *((_DWORD *)a2 + 25);
      v153 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v153 < 8 )
        goto LABEL_90;
      v151[8] = *((_DWORD *)a2 + 26);
      v153 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v153 < 9 )
        goto LABEL_90;
      v151[9] = *((_DWORD *)a2 + 27);
      v153 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v153 < 0xA )
        goto LABEL_90;
      v151[10] = *((_DWORD *)a2 + 28);
      v153 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v153 < 0xB )
        goto LABEL_90;
      v151[11] = *((_DWORD *)a2 + 29);
      v153 = *((unsigned int *)a2 + 18);
      if ( (unsigned int)v153 <= 0xB )
        goto LABEL_90;
      __break(0x5512u);
LABEL_87:
      v151 = v130 + 1;
      *v130 = 1179648;
      v152 = *((_DWORD *)a2 + 18);
      if ( !v152 )
        goto LABEL_88;
    }
    v153 = 0;
LABEL_90:
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: [Allowed Authmode]: num_allowed_authmode: %d",
      v121,
      v122,
      v123,
      v124,
      v125,
      v126,
      v127,
      v128,
      "send_roam_scan_offload_ap_profile_cmd_tlv",
      v153);
    ((void (__fastcall *)(__int64, __int64, int *, _QWORD))qdf_trace_hex_dump)(
      49,
      8,
      v130,
      (unsigned int)(4 * *((_DWORD *)a2 + 18)));
  }
  else
  {
LABEL_88:
    *v151 = 1179648;
  }
  wmi_mtrace(0xB005u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v20,
             v17 + 4,
             0xB005u,
             "send_roam_scan_offload_ap_profile_cmd_tlv",
             0x16A4u,
             v154,
             v155,
             v156,
             v157,
             v158,
             v159,
             v160,
             v161);
  if ( (_DWORD)result )
  {
    v162 = result;
    wmi_buf_free();
    return v162;
  }
  return result;
}
