__int64 __fastcall send_roam_scan_offload_mode_cmd_tlv(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v12; // w8
  unsigned int v13; // w21
  int v14; // w8
  int v15; // w10
  unsigned int v16; // w8
  unsigned int v17; // w22
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x25
  __int64 v28; // x21
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 result; // x0
  unsigned int v38; // w8
  unsigned int v39; // w8
  unsigned int v40; // w9
  unsigned int v41; // w10
  unsigned int v42; // w12
  unsigned int v43; // w13
  int v44; // w13
  unsigned int v45; // w11
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w23
  unsigned int v55; // w8
  unsigned int v56; // w9
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
  _DWORD *v81; // x27
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  unsigned int v90; // w19
  size_t v91; // x2
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  unsigned __int8 *v100; // x27
  char *v101; // x24
  unsigned int v102; // w27
  size_t v103; // x2
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  __int64 v112; // x8
  size_t v113; // x2
  int v114; // w8
  __int64 v115; // x5
  __int64 v116; // x6
  __int64 v117; // x2
  unsigned int v118; // w5
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  size_t v127; // x2
  __int64 v128; // x8
  _DWORD *v129; // x23
  size_t v130; // x2
  size_t v131; // x2
  size_t v132; // x2
  size_t v133; // x2
  _DWORD *v134; // x24
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  unsigned int v143; // w8
  unsigned int v144; // w8
  size_t v145; // x2
  size_t v146; // x2
  unsigned int v147; // w8
  __int64 v148; // x5
  double v149; // d0
  double v150; // d1
  double v151; // d2
  double v152; // d3
  double v153; // d4
  double v154; // d5
  double v155; // d6
  double v156; // d7
  __int64 v157; // [xsp+0h] [xbp-30h]
  __int64 v158; // [xsp+0h] [xbp-30h]
  __int64 v159; // [xsp+0h] [xbp-30h]
  __int64 v160; // [xsp+0h] [xbp-30h]
  __int64 v161; // [xsp+8h] [xbp-28h]
  __int64 v162; // [xsp+8h] [xbp-28h]
  __int64 v163; // [xsp+8h] [xbp-28h]
  __int64 v164; // [xsp+10h] [xbp-20h]
  __int64 v165; // [xsp+18h] [xbp-18h]
  __int64 v166; // [xsp+20h] [xbp-10h]

  v12 = 24;
  if ( *((_BYTE *)a2 + 4) )
    goto LABEL_23;
  if ( (a2[285] & 1) == 0 )
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: vdev[%d]: %s roam offload: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wmi_get_rso_buf_len",
      *a2,
      &unk_8B9E43);
    v12 = 24;
    goto LABEL_23;
  }
  v13 = a2[286];
  qdf_trace_msg(0x31u, 8u, "%s: wmi akm = %d", a3, a4, a5, a6, a7, a8, a9, a10, "wmi_get_rso_buf_len", v13);
  if ( v13 )
  {
    if ( v13 == 1 )
    {
      if ( (a2[357] & 1) == 0 )
      {
        v14 = 128;
        if ( *((_BYTE *)a2 + 1420) )
        {
          if ( *((_BYTE *)a2 + 1300) )
            v14 = 276;
          else
            v14 = 128;
        }
        goto LABEL_17;
      }
    }
    else if ( (a2[357] & 1) == 0 )
    {
      if ( v13 <= 0x20 && ((1LL << v13) & 0x107806000LL) != 0 )
        v14 = 276;
      else
        v14 = 208;
      goto LABEL_17;
    }
    v14 = 180;
  }
  else
  {
    v14 = 128;
  }
LABEL_17:
  if ( *((_BYTE *)a2 + 1141) )
    v15 = 432;
  else
    v15 = 4;
  v12 = ((a2[28] + 3) & 0xFFFFFFFC) + v14 + v15;
  if ( *((_BYTE *)a2 + 1231) )
    v12 += 12;
  a2[2] |= 4u;
LABEL_23:
  v16 = v12 + 196;
  if ( a2[2] == 4 )
    v17 = 24;
  else
    v17 = v16;
  v18 = wmi_buf_alloc_fl(a1, v17, "send_roam_scan_offload_mode_cmd_tlv", 0x1417u);
  if ( !v18 )
    return 2;
  v27 = *(_QWORD *)(v18 + 224);
  v28 = v18;
  *(_DWORD *)v27 = 7274516;
  *(_DWORD *)(v27 + 20) = a2[4];
  *(_DWORD *)(v27 + 16) = 1000 * a2[3];
  *(_DWORD *)(v27 + 4) = a2[2];
  *(_DWORD *)(v27 + 8) = *a2;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: RSO_CFG: vdev_id:%d roam scan mode:0x%x min_delay_bitmap:0x%x min_delay_btw_scans:%d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "send_roam_scan_offload_mode_cmd_tlv");
  if ( a2[2] == 4 )
  {
    *(_DWORD *)(v27 + 12) |= 1u;
    goto LABEL_44;
  }
  *(_DWORD *)(v27 + 84) = 2092;
  *(_DWORD *)(v27 + 24) = 5046440;
  if ( *((_BYTE *)a2 + 4) )
  {
    *(_QWORD *)(v27 + 64) = 0;
    *(_QWORD *)(v27 + 48) = 0x6E00000064LL;
    *(_QWORD *)(v27 + 56) = 0x1F400000032LL;
    *(_QWORD *)(v27 + 76) = 30000;
    v38 = a2[10];
    *(_DWORD *)(v27 + 88) = 0;
    *(_DWORD *)(v27 + 72) = v38;
  }
  else
  {
    *(_DWORD *)(v27 + 48) = a2[7];
    *(_DWORD *)(v27 + 52) = a2[6];
    *(_DWORD *)(v27 + 184) = a2[8];
    *(_DWORD *)(v27 + 88) = a2[9];
    v39 = a2[10];
    *(_DWORD *)(v27 + 56) = v39;
    v40 = a2[11];
    *(_DWORD *)(v27 + 60) = v40;
    v41 = a2[14];
    *(_DWORD *)(v27 + 64) = v41;
    v42 = a2[12];
    *(_DWORD *)(v27 + 68) = v42;
    v43 = a2[13];
    *(_DWORD *)(v27 + 76) = 30000;
    *(_DWORD *)(v27 + 80) = v43;
    *(_DWORD *)(v27 + 72) = a2[16];
    *(_DWORD *)(v27 + 108) = a2[17];
    v44 = a2[18] | 0x82C;
    *(_DWORD *)(v27 + 84) = v44;
    *(_DWORD *)(v27 + 172) = a2[25];
    v45 = a2[26];
    *(_DWORD *)(v27 + 176) = v45;
    *(_DWORD *)(v27 + 84) = ((a2[20] & 7) << 21) | v44;
    if ( *((_BYTE *)a2 + 5) == 1 )
      *(_DWORD *)(v27 + 164) |= 1u;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: RSO_CFG: dwell time: active %d passive %d, burst_duration:%d, active 6g %d passive 6g %d, min_rest_time %d max"
      " rest %d repeat probe time %d probe_spacing:%d",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "wmi_fill_rso_start_scan_tlv",
      v45,
      v39,
      v40,
      v41,
      v42);
    LODWORD(v158) = *(_DWORD *)(v27 + 108);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: RSO_CFG: ctrl_flags:0x%x probe_delay:%d max_scan_time:%d idle_time:%d n_probes:%d",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "wmi_fill_rso_start_scan_tlv",
      *(unsigned int *)(v27 + 164),
      *(unsigned int *)(v27 + 80),
      *(unsigned int *)(v27 + 76),
      *(unsigned int *)(v27 + 72),
      v158);
  }
  *(_DWORD *)(v27 + 104) = 0;
  if ( !*((_BYTE *)a2 + 4) && (a2[285] & 1) != 0 )
  {
    v54 = a2[286];
    *(_DWORD *)(v27 + 196) = 1179744;
    *(_DWORD *)(v27 + 200) = 21495900;
    *(_DWORD *)(v27 + 208) = *((unsigned __int8 *)a2 + 1149);
    *(_DWORD *)(v27 + 204) = *((unsigned __int8 *)a2 + 1148);
    *(_DWORD *)(v27 + 212) = *((unsigned __int8 *)a2 + 1150);
    *(_DWORD *)(v27 + 272) = a2[289];
    v55 = a2[290];
    *(_DWORD *)(v27 + 276) = v55;
    v56 = a2[291];
    *(_DWORD *)(v27 + 280) = v56;
    *(_DWORD *)(v27 + 216) = a2[288];
    *(_DWORD *)(v27 + 284) = a2[293];
    *(_DWORD *)(v27 + 288) = *((unsigned __int8 *)a2 + 1168);
    LODWORD(v161) = v56;
    LODWORD(v157) = v55;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: RSO_CFG: prefer_5g:%d rssi_cat_gap:%d select_5g_margin:%d ho_delay:%d max_sw_retry:%d no_ack_timeout:%d",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "wmi_fill_rso_tlvs",
      v157,
      v161);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: RSO_CFG: reassoc_fail_timeout:%d rct_validity_time:%d disable_self_roam:%d",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "wmi_fill_rso_tlvs",
      *(unsigned int *)(v27 + 216),
      *(unsigned int *)(v27 + 284),
      *(unsigned int *)(v27 + 288));
    *(_DWORD *)(v27 + 220) = a2[294];
    *(_DWORD *)(v27 + 224) = a2[295];
    *(_DWORD *)(v27 + 228) = a2[296];
    *(_DWORD *)(v27 + 232) = a2[297];
    *(_DWORD *)(v27 + 236) = a2[298];
    *(_DWORD *)(v27 + 240) = a2[299];
    *(_DWORD *)(v27 + 248) = a2[301];
    *(_DWORD *)(v27 + 244) = a2[300];
    *(_DWORD *)(v27 + 252) = a2[302];
    qdf_mem_copy((void *)(v27 + 256), a2 + 303, 0x10u);
    LODWORD(v166) = *(_DWORD *)(v27 + 252);
    LODWORD(v165) = *(_DWORD *)(v27 + 244);
    LODWORD(v164) = *(_DWORD *)(v27 + 248);
    LODWORD(v162) = *(_DWORD *)(v27 + 240);
    LODWORD(v159) = *(_DWORD *)(v27 + 236);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: RSO_CFG: capability:0x%x ht_caps:0x%x ampdu_param:0%x ht_ext_cap:0x%x ht_txbf:0x%x asel_cap:0x%x qos_caps:0x%x"
      " qos_en:%d wmm_caps:0x%x",
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      "wmi_fill_rso_tlvs",
      *(unsigned int *)(v27 + 220),
      *(unsigned int *)(v27 + 224),
      *(unsigned int *)(v27 + 228),
      *(unsigned int *)(v27 + 232),
      v159,
      v162,
      v164,
      v165,
      v166);
    if ( !v54 )
    {
LABEL_42:
      v81 = (_DWORD *)(v27 + 308);
      *(_DWORD *)(v27 + 304) = 1179648;
      *(_QWORD *)(v27 + 296) = 0x12000000120000LL;
LABEL_66:
      *v81 = 1179656;
      v81[1] = 36569092;
      v118 = a2[28];
      v81[2] = v118;
      v81[3] = ((_WORD)v118 + 3) & 0xFFFC | 0x110000;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: RSO_CFG: akm:%d assoc_ies len:%d",
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        "wmi_fill_rso_tlvs",
        v54);
      v127 = (unsigned int)v81[2];
      if ( (_DWORD)v127 )
      {
        qdf_mem_copy(v81 + 4, a2 + 29, v127);
        v128 = ((unsigned int)v81[2] + 3LL) & 0x1FFFFFFFCLL;
      }
      else
      {
        v128 = 0;
      }
      v129 = (_DWORD *)((char *)v81 + v128 + 16);
      if ( (*((_BYTE *)a2 + 1141) & 1) != 0 )
      {
        *v129 = 1180076;
        v129[1] = 43778472;
        v130 = a2[375];
        v129[7] = v130;
        qdf_mem_copy(v129 + 3, a2 + 371, v130);
        v129[8] = a2[370];
        v131 = a2[392];
        v129[25] = v131;
        qdf_mem_copy(v129 + 9, a2 + 376, v131);
        v132 = a2[409];
        v129[42] = v132;
        qdf_mem_copy(v129 + 26, a2 + 393, v132);
        v133 = a2[474];
        v129[107] = v133;
        qdf_mem_copy(v129 + 43, a2 + 410, v133);
        v134 = v129 + 108;
        LODWORD(v160) = v129[107];
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: RSO_CFG: ERP: usrname_len:%d next_erp_seq_num:%d rRk_len:%d rIk_len:%d realm_len:%d",
          v135,
          v136,
          v137,
          v138,
          v139,
          v140,
          v141,
          v142,
          "wmi_add_fils_tlv",
          (unsigned int)v129[7],
          (unsigned int)v129[8],
          (unsigned int)v129[25],
          (unsigned int)v129[42],
          v160);
      }
      else
      {
        v134 = v129 + 1;
        *v129 = 1179648;
      }
      if ( *((_BYTE *)a2 + 1231) == 1 )
      {
        *v134 = 1179656;
        v134[1] = 62914564;
        v134[2] = a2[488];
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: spmk_timeout:%d seconds",
          v119,
          v120,
          v121,
          v122,
          v123,
          v124,
          v125,
          v126,
          "wmi_fill_sae_single_pmk_tlv");
      }
      goto LABEL_44;
    }
    if ( v54 == 1 )
    {
      if ( (a2[357] & 1) == 0 )
      {
        if ( !*((_BYTE *)a2 + 1420) || (a2[325] & 1) == 0 )
          goto LABEL_42;
        goto LABEL_51;
      }
    }
    else if ( (a2[357] & 1) == 0 )
    {
      if ( v54 > 0x20 || ((1LL << v54) & 0x107806000LL) == 0 )
      {
        *(_DWORD *)(v27 + 296) = 1179728;
        if ( *((_BYTE *)a2 + 1228) == 1 && *((_BYTE *)a2 + 1229) == 1 )
          v143 = *(_DWORD *)(v27 + 304) | 1;
        else
          v143 = *(_DWORD *)(v27 + 304) & 0xFFFFFFFE;
        *(_DWORD *)(v27 + 304) = v143;
        if ( *((_BYTE *)a2 + 1228) == 1 && *((_BYTE *)a2 + 1230) == 1 )
          v144 = v143 & 0xFFFFFFFD;
        else
          v144 = v143 | 2;
        *(_DWORD *)(v27 + 304) = v144;
        if ( *((_BYTE *)a2 + 1231) == 1 )
          *(_DWORD *)(v27 + 304) = v144 | 4;
        if ( *((unsigned __int8 *)a2 + 1296) >= 0x20u )
          v145 = 32;
        else
          v145 = *((unsigned __int8 *)a2 + 1296);
        *(_DWORD *)(v27 + 340) = v145;
        qdf_mem_copy((void *)(v27 + 308), a2 + 308, v145);
        *(_DWORD *)(v27 + 344) = 0;
        v146 = 0;
        v147 = *((unsigned __int8 *)a2 + 1296);
        if ( v147 >= 0x21 )
        {
          if ( v147 >= 0x40 )
            v146 = 32;
          else
            v146 = v147 - 32;
          *(_DWORD *)(v27 + 344) = v146;
        }
        qdf_mem_copy((void *)(v27 + 348), a2 + 316, v146);
        v148 = *(unsigned int *)(v27 + 340);
        *(_DWORD *)(v27 + 300) = 21561420;
        *(_QWORD *)(v27 + 380) = 0x12000000120000LL;
        v81 = (_DWORD *)(v27 + 388);
        LODWORD(v163) = *((unsigned __int8 *)a2 + 1228);
        LODWORD(v160) = *((unsigned __int8 *)a2 + 1231);
        qdf_trace_msg(
          0x31u,
          4u,
          "%s: RSO_CFG: vdev:%d pmk_len = %d pmksa caching:%d OKC:%d sae_same_pmk:%d key_mgmt_offload:%d",
          v149,
          v150,
          v151,
          v152,
          v153,
          v154,
          v155,
          v156,
          "wmi_fill_rso_tlvs",
          *a2,
          v148,
          *((unsigned __int8 *)a2 + 1230),
          *((unsigned __int8 *)a2 + 1229),
          v160,
          v163);
        if ( *(_DWORD *)(v27 + 340) )
          ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(49, 8, v27 + 308, 2);
        if ( !*(_DWORD *)(v27 + 344) )
          goto LABEL_66;
        v117 = v27 + 348;
LABEL_65:
        ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(49, 8, v117, 2);
        goto LABEL_66;
      }
LABEL_51:
      *(_DWORD *)(v27 + 296) = 1179648;
      *(_DWORD *)(v27 + 300) = 1179796;
      v91 = a2[342];
      *(_DWORD *)(v27 + 364) = v91;
      qdf_mem_copy((void *)(v27 + 316), a2 + 343, v91);
      if ( v54 - 25 <= 1 && *((_BYTE *)a2 + 1948) )
      {
        v100 = (unsigned __int8 *)(a2 + 487);
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: Update the FILS FT key to Firmware",
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          v98,
          v99,
          "wmi_fill_roam_offload_11r_params");
        v101 = (char *)(a2 + 475);
      }
      else
      {
        v101 = (char *)a2 + 1303;
        v100 = (unsigned __int8 *)a2 + 1367;
      }
      v102 = *v100;
      if ( v102 >= 0x20 )
        v103 = 32;
      else
        v103 = v102;
      *(_DWORD *)(v27 + 400) = v103;
      qdf_mem_copy((void *)(v27 + 368), v101, v103);
      *(_DWORD *)(v27 + 404) = 0;
      if ( v102 >= 0x21 )
      {
        v112 = *(unsigned int *)(v27 + 400);
        v113 = v102 - (unsigned int)v112;
        *(_DWORD *)(v27 + 404) = v113;
        qdf_mem_copy((void *)(v27 + 408), &v101[v112], v113);
      }
      *(_DWORD *)(v27 + 308) = *((unsigned __int8 *)a2 + 1420);
      *(_DWORD *)(v27 + 312) = *((unsigned __int16 *)a2 + 711);
      *(_DWORD *)(v27 + 440) = *((unsigned __int8 *)a2 + 1301);
      *(_DWORD *)(v27 + 444) = *((unsigned __int8 *)a2 + 1302);
      v114 = *((unsigned __int8 *)a2 + 1424);
      *(_DWORD *)(v27 + 448) = v114;
      if ( v54 == 1 )
      {
        v115 = 0;
        *(_DWORD *)(v27 + 364) = 0;
        *(_DWORD *)(v27 + 400) = 0;
      }
      else
      {
        v115 = *(unsigned int *)(v27 + 400);
      }
      v116 = *(unsigned int *)(v27 + 404);
      *(_DWORD *)(v27 + 452) = 1179648;
      *(_DWORD *)(v27 + 304) = 21627024;
      v81 = (_DWORD *)(v27 + 456);
      LODWORD(v160) = v114;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: RSO_CFG: vdev[%d] 11r TLV psk_msk_len = %d psk_msk_ext:%d md:0x%x ft_over_ds_enable:%d",
        v104,
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        "wmi_fill_rso_tlvs",
        *a2,
        v115,
        v116,
        v160);
      if ( !*(_DWORD *)(v27 + 400) )
        goto LABEL_66;
      v117 = v27 + 368;
      goto LABEL_65;
    }
    *(_QWORD *)(v27 + 296) = 0x12000000120000LL;
    *(_DWORD *)(v27 + 304) = 1179700;
    qdf_mem_copy((void *)(v27 + 312), (char *)a2 + 1429, 0x10u);
    qdf_mem_copy((void *)(v27 + 328), (char *)a2 + 1445, 0x20u);
    v81 = (_DWORD *)(v27 + 360);
    *(_DWORD *)(v27 + 308) = 21692464;
    goto LABEL_66;
  }
  *(_QWORD *)(v27 + 196) = 0x12000000120000LL;
  *(_QWORD *)(v27 + 204) = 0x12000000120000LL;
  *(_QWORD *)(v27 + 212) = 0x11000000120000LL;
LABEL_44:
  wmi_mtrace(0xB001u, *a2, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v28,
             v17,
             0xB001u,
             "send_roam_scan_offload_mode_cmd_tlv",
             0x1452u,
             v82,
             v83,
             v84,
             v85,
             v86,
             v87,
             v88,
             v89);
  if ( (_DWORD)result )
  {
    v90 = result;
    wmi_buf_free();
    return v90;
  }
  return result;
}
