__int64 __fastcall enh_cfr_dbr_event_handler(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x26
  __int64 comp_private_obj; // x0
  unsigned int v14; // w21
  __int64 v15; // x19
  _DWORD *v16; // x24
  char v17; // w20
  char v18; // w9
  __int64 v19; // x27
  const char *v20; // x2
  __int64 result; // x0
  unsigned int v22; // w9
  int v23; // w9
  __int64 v24; // x10
  bool v25; // zf
  __int64 v26; // x9
  __int64 v27; // x8
  unsigned int v28; // w23
  int v29; // w28
  unsigned __int64 StatusReg; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 lut_entry; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int16 v48; // w9
  __int64 v49; // x22
  int v50; // w23
  __int64 v51; // x0
  unsigned int v52; // w9
  int v53; // w10
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w8
  char v63; // w10
  unsigned int v64; // w13
  const char *v65; // x2
  __int64 v66; // x8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  int v75; // w13
  unsigned __int64 v76; // x9
  unsigned int v77; // w16
  int v78; // w17
  unsigned __int64 v79; // x0
  int v80; // w1
  unsigned __int64 v81; // x2
  int v82; // w4
  unsigned __int64 v83; // x13
  unsigned __int64 v84; // x15
  const char *v85; // x3
  const char *v86; // x2
  unsigned __int64 v87; // x13
  unsigned __int64 v88; // x14
  __int64 v89; // x16
  int v90; // w5
  int v91; // w20
  unsigned __int64 v92; // x2
  int v93; // w4
  int v94; // w20
  __int64 v95; // x23
  unsigned __int64 v96; // x8
  int v97; // w20
  __int64 v98; // x23
  unsigned int v99; // w8
  int v100; // w0
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  double (__fastcall *v109)(__int64, __int64, __int64, __int64, __int64, void *, __int64); // x8
  __int64 v110; // x3
  __int64 v111; // x4
  unsigned int v112; // w20
  __int64 v113; // x8
  __int64 v114; // [xsp+0h] [xbp-D0h]
  __int64 v115; // [xsp+8h] [xbp-C8h]
  __int64 v116; // [xsp+10h] [xbp-C0h]
  __int64 v117; // [xsp+18h] [xbp-B8h]
  __int64 v118; // [xsp+20h] [xbp-B0h]
  __int64 v119; // [xsp+28h] [xbp-A8h]
  __int64 v120; // [xsp+30h] [xbp-A0h]
  __int64 v121; // [xsp+38h] [xbp-98h]
  __int64 v122; // [xsp+40h] [xbp-90h]
  int v123; // [xsp+48h] [xbp-88h]
  __int64 v124; // [xsp+48h] [xbp-88h]
  int v125; // [xsp+50h] [xbp-80h]
  __int64 v126; // [xsp+50h] [xbp-80h]
  int v127; // [xsp+58h] [xbp-78h]
  __int64 v128; // [xsp+58h] [xbp-78h]
  int v129; // [xsp+60h] [xbp-70h]
  __int64 v130; // [xsp+60h] [xbp-70h]
  __int64 v131; // [xsp+68h] [xbp-68h]
  int v132; // [xsp+70h] [xbp-60h]
  __int64 v133; // [xsp+70h] [xbp-60h]
  int v134; // [xsp+78h] [xbp-58h]
  __int64 v135; // [xsp+78h] [xbp-58h]
  int v136; // [xsp+80h] [xbp-50h]
  __int64 v137; // [xsp+80h] [xbp-50h]
  unsigned int v138; // [xsp+88h] [xbp-48h]
  __int64 v139; // [xsp+88h] [xbp-48h]
  int v140; // [xsp+90h] [xbp-40h]
  char v141; // [xsp+9Ch] [xbp-34h]
  _DWORD *v142; // [xsp+A0h] [xbp-30h]
  unsigned __int64 v144; // [xsp+B0h] [xbp-20h] BYREF
  __int64 v145; // [xsp+B8h] [xbp-18h]
  __int64 v146; // [xsp+C0h] [xbp-10h]

  v146 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v144 = 0;
  v145 = 0;
  if ( !a1 || !a2 )
  {
    v20 = "%s: pdev or payload is null";
LABEL_15:
    qdf_trace_msg(0x6Au, 2u, v20, a3, a4, a5, a6, a7, a8, a9, a10, "enh_cfr_dbr_event_handler");
    goto LABEL_16;
  }
  v10 = *(_QWORD *)(a1 + 80);
  if ( !v10 )
  {
    v20 = "%s: psoc is null";
    goto LABEL_15;
  }
  v11 = *(_QWORD *)(v10 + 2136);
  if ( !v11 )
  {
    v20 = "%s: rx_ops is NULL";
    goto LABEL_15;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
  if ( !comp_private_obj )
  {
    v20 = "%s: pdev object for CFR is null";
    goto LABEL_15;
  }
  v14 = *(_DWORD *)(a2 + 16);
  v15 = comp_private_obj;
  v16 = *(_DWORD **)(a2 + 8);
  qdf_trace_msg(
    0x6Au,
    8u,
    "%s: <DBRCOMP><%u>:bufferaddr: 0x%pK cookie: %u\n",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "enh_cfr_dbr_event_handler",
    v14,
    *(_QWORD *)(a2 + 24),
    v14);
  qdf_mem_copy(&v144, v16, 0x10u);
  if ( (v145 & 0x8000000) == 0 )
  {
    v142 = nullptr;
LABEL_8:
    v17 = 0;
    v18 = -1;
    goto LABEL_9;
  }
  v142 = v16 + 4;
  v22 = (v16[4] >> 1) & 7;
  if ( v22 > 2 )
  {
    switch ( v22 )
    {
      case 3u:
        v17 = 0;
        v18 = 6;
        break;
      case 4u:
        v17 = 0;
        v18 = 7;
        break;
      case 5u:
        v17 = 0;
        v18 = 8;
        break;
      default:
        goto LABEL_8;
    }
  }
  else if ( v22 )
  {
    if ( v22 != 1 )
    {
      if ( v22 == 2 )
      {
        v17 = 1;
        v141 = 5;
        if ( (v145 & 0x4000000) == 0 )
          goto LABEL_10;
LABEL_23:
        v23 = WORD1(v145) >> 12;
        v24 = 28;
        if ( v23 == 5 )
          v24 = 32;
        v25 = v23 == 3;
        v26 = 30;
        if ( !v25 )
          v26 = v24;
        if ( (v145 & 0x8000000) != 0 )
          v27 = v26;
        else
          v27 = 0;
        v19 = (__int64)v16 + v27 + 16;
        goto LABEL_31;
      }
      goto LABEL_8;
    }
    v17 = 0;
    v18 = 4;
  }
  else
  {
    v17 = 0;
    v18 = 3;
  }
LABEL_9:
  v141 = v18;
  if ( (v145 & 0x4000000) != 0 )
    goto LABEL_23;
LABEL_10:
  v19 = 0;
LABEL_31:
  v28 = v144;
  v29 = (unsigned __int16)v145;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v15 + 1704);
  }
  else
  {
    raw_spin_lock_bh(v15 + 1704);
    *(_QWORD *)(v15 + 1712) |= 1uLL;
  }
  lut_entry = get_lut_entry(v15, v14, v31, v32, v33, v34, v35, v36, v37, v38);
  if ( lut_entry )
  {
    v48 = HIWORD(v144);
    *(_QWORD *)(lut_entry + 8) = v16;
    v49 = lut_entry;
    *(_WORD *)(lut_entry + 20) = v48;
    v50 = ((v28 >> 6) & 0xFC) + v29;
    *(_DWORD *)(lut_entry + 16) = v50;
    *(_QWORD *)(lut_entry + 24) = *(_QWORD *)(a2 + 24);
    v51 = ktime_get(lut_entry);
    v52 = ((unsigned int)v144 >> 8) & 0x3F;
    v53 = (unsigned __int16)v145;
    *(_QWORD *)(v49 + 216) = v51 / 1000000;
    *(_DWORD *)(v49 + 224) = v52;
    *(_DWORD *)(v49 + 228) = v53;
    qdf_mem_copy((void *)(v49 + 200), &v144, 8u);
    v62 = v144;
    v63 = *(_BYTE *)(v15 + 10);
    v64 = *(_DWORD *)((char *)&v145 + 2);
    *(_DWORD *)(v49 + 86) = v50;
    *(_BYTE *)(v49 + 50) = v63;
    *(_BYTE *)(v49 + 66) = (v62 >> 28) & 7;
    *(_BYTE *)(v49 + 77) = (2 << ((v62 >> 25) & 7)) - 1;
    if ( (v17 & 1) == 0 )
    {
      *(_BYTE *)(v49 + 75) = v141;
      *(_BYTE *)(v49 + 76) = ((v62 >> 22) & 7) + 1;
      if ( (v64 & 0xC00) == 0x800 )
      {
        extract_peer_mac_from_freeze_tlv(v142, v49 + 92);
        v64 = *(_DWORD *)((char *)&v145 + 2);
      }
    }
    if ( (v64 & 0x800) != 0 )
    {
      if ( (v64 & 0xF) == 9 )
      {
        v136 = (unsigned __int16)v64 >> 12;
        v134 = HIBYTE(v64) & 0xF;
        v138 = v64 >> 28;
        v140 = HIWORD(v145);
        v132 = BYTE2(v64);
        v129 = (v64 >> 10) & 1;
        v127 = (v64 >> 8) & 1;
        v125 = (unsigned __int8)v64 >> 4;
        v65 = "%s: <DBRCOMP><%u>\n"
              "Tag: 0x%02x Length: %d udone: %d\n"
              "ctype: %d preamble: %d Nss: %d\n"
              "num_chains: %d bw: %d peervalid: %d\n"
              "peer_id: %d ppdu_id: 0x%04x\n"
              "total_bytes: %d header_version: %d\n"
              "target_id: %d cfr_fmt: %d\n"
              "mu_rx_data_incl: %d freeze_data_incl: %d\n"
              "mu_rx_num_users: %d decimation_factor: %d\n"
              "freeze_tlv_version: %d\n"
              "he_ltf_type: %u ext_preamble_type = %u\n";
        v123 = 9;
      }
      else
      {
        v125 = (unsigned __int8)v64 >> 4;
        v65 = "%s: <DBRCOMP><%u>\n"
              "Tag: 0x%02x Length: %d udone: %d\n"
              "ctype: %d preamble: %d Nss: %d\n"
              "num_chains: %d bw: %d peervalid: %d\n"
              "peer_id: %d ppdu_id: 0x%04x\n"
              "total_bytes: %d header_version: %d\n"
              "target_id: %d cfr_fmt: %d\n"
              "mu_rx_data_incl: %d freeze_data_incl: %d\n"
              "mu_rx_num_users: %d decimation_factor: %d\n"
              "freeze_tlv_version: %d\n";
        v136 = (unsigned __int16)v64 >> 12;
        v134 = HIBYTE(v64) & 0xF;
        v132 = BYTE2(v64);
        v129 = (v64 >> 10) & 1;
        v127 = (v64 >> 8) & 1;
        v123 = v64 & 0xF;
      }
      qdf_trace_msg(
        0x6Au,
        8u,
        v65,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "dump_enh_dma_hdr",
        v14,
        (unsigned __int8)v144,
        ((unsigned int)v144 >> 8) & 0x3F,
        WORD1(v144) & 1,
        ((unsigned int)v144 >> 17) & 7,
        ((unsigned int)v144 >> 20) & 3,
        ((unsigned int)v144 >> 22) & 7,
        ((unsigned int)v144 >> 25) & 7,
        ((unsigned int)v144 >> 28) & 7,
        (v144 >> 31) & 1,
        WORD2(v144),
        HIWORD(v144),
        (unsigned __int16)v145,
        v123,
        v125,
        v127,
        v129,
        1,
        v132,
        v134,
        v136,
        v138,
        v140);
      if ( (v145 & 0x8000000) != 0 )
      {
        v75 = WORD1(v145) >> 12;
        v76 = *(_QWORD *)v142;
        if ( v75 == 5 )
        {
          v87 = *((_QWORD *)v142 + 1);
          v88 = *((_QWORD *)v142 + 2);
          v89 = *((_QWORD *)v142 + 3);
          LODWORD(v118) = HIWORD(v76);
          LODWORD(v137) = WORD2(v89);
          LODWORD(v139) = HIWORD(v89) & 0x7FFF;
          LODWORD(v135) = ((unsigned int)v89 >> 22) & 1;
          LODWORD(v133) = WORD1(v89) & 0x3F;
          LODWORD(v131) = (unsigned __int16)v89;
          LODWORD(v130) = HIWORD(v88);
          LODWORD(v128) = WORD2(v88);
          v85 = "dump_freeze_tlv_v5";
          LODWORD(v126) = WORD1(v88);
          v86 = "%s: <DBRCOMP><FREEZE><%u>\n"
                "freeze: %d capture_reason: %d packet_type: 0x%x\n"
                "packet_subtype: 0x%x sw_peer_id_valid: %d sw_peer_id: %d\n"
                "phy_ppdu_id: 0x%04x packet_ta_lower_16: 0x%04x\n"
                "packet_ta_mid_16: 0x%04x packet_ta_upper_16: 0x%04x\n"
                "packet_ra_lower_16: 0x%04x packet_ra_mid_16: 0x%04x\n"
                "packet_ra_upper_16: 0x%04x\n"
                "tsf_timestamp_15_0: 0x%04x\n"
                "tsf_timestamp_31_16: 0x%04x\n"
                "tsf_timestamp_47_32: 0x%04x\n"
                "tsf_timestamp_63_48: 0x%04x\n"
                "user_index_or_user_mask_5_0: 0x%04x\n"
                "directed: %d\n"
                "user_mask_21_6: 0x%04x\n"
                "user_mask_36_22: 0x%04x\n";
          LODWORD(v124) = (unsigned __int16)v88;
          LODWORD(v122) = HIWORD(v87);
          LODWORD(v121) = WORD2(v87);
          LODWORD(v120) = WORD1(v87);
          LODWORD(v119) = (unsigned __int16)v87;
        }
        else
        {
          if ( v75 == 3 )
          {
            v83 = *((_QWORD *)v142 + 1);
            v84 = *((_QWORD *)v142 + 2);
            LODWORD(v137) = ((unsigned int)v76 >> 10) & 1;
            v77 = (unsigned __int16)v142[6];
            LODWORD(v120) = HIWORD(v76);
            v78 = WORD1(v83);
            v79 = HIWORD(v83);
            v80 = WORD2(v83);
            v81 = HIWORD(v84);
            v82 = WORD1(v84);
            LODWORD(v83) = (unsigned __int16)v83;
            LODWORD(v84) = (unsigned __int16)v84;
            LODWORD(v135) = *((unsigned __int16 *)v142 + 14);
            LODWORD(v133) = HIWORD(v142[6]);
            LODWORD(v131) = v82;
            LODWORD(v130) = WORD2(v84);
            v85 = "dump_freeze_tlv_v3";
            LODWORD(v128) = v81;
            v86 = "%s: <DBRCOMP><FREEZE><%u>\n"
                  "freeze: %d capture_reason: %d packet_type: 0x%x\n"
                  "packet_subtype: 0x%x sw_peer_id_valid: %d sw_peer_id: %d\n"
                  "phy_ppdu_id: 0x%04x packet_ta_upper_16: 0x%04x\n"
                  "packet_ta_mid_16: 0x%04x packet_ta_lower_16: 0x%04x\n"
                  "packet_ra_upper_16: 0x%04x packet_ra_mid_16: 0x%04x\n"
                  "packet_ra_lower_16: 0x%04x\n"
                  "tsf_63_48_or_user_mask_36_32: 0x%04x\n"
                  "tsf_timestamp_47_32: 0x%04x\n"
                  "tsf_timestamp_31_16: 0x%04x\n"
                  "tsf_timestamp_15_0: 0x%04x\n"
                  "user_index_or_user_mask_15_0: 0x%04x\n"
                  "user_mask_31_16: 0x%04x\n"
                  "directed: %d\n";
          }
          else
          {
            v83 = *((_QWORD *)v142 + 1);
            v84 = *((_QWORD *)v142 + 2);
            v77 = v142[6];
            LODWORD(v120) = HIWORD(v76);
            v90 = HIWORD(v77) & 0x3F;
            v91 = (v77 >> 22) & 1;
            v77 = (unsigned __int16)v77;
            v92 = HIWORD(v84);
            v78 = WORD1(v83);
            v79 = HIWORD(v83);
            v80 = WORD2(v83);
            v93 = WORD1(v84);
            LODWORD(v83) = (unsigned __int16)v83;
            LODWORD(v84) = (unsigned __int16)v84;
            LODWORD(v130) = WORD2(v84);
            LODWORD(v128) = v92;
            v86 = "%s: <DBRCOMP><FREEZE><%u>\n"
                  "freeze: %d capture_reason: %d packet_type: 0x%x\n"
                  "packet_subtype: 0x%x sw_peer_id_valid: %d sw_peer_id: %d\n"
                  "phy_ppdu_id: 0x%04x packet_ta_upper_16: 0x%04x\n"
                  "packet_ta_mid_16: 0x%04x packet_ta_lower_16: 0x%04x\n"
                  "packet_ra_upper_16: 0x%04x packet_ra_mid_16: 0x%04x\n"
                  "packet_ra_lower_16: 0x%04x tsf_timestamp_63_48: 0x%04x\n"
                  "tsf_timestamp_47_32: 0x%04x tsf_timestamp_31_16: 0x%04x\n"
                  "tsf_timestamp_15_0: 0x%04x user_index_or_user_mask_5_0: %d\n"
                  "directed: %d\n";
            v85 = "dump_freeze_tlv";
            LODWORD(v135) = v91;
            LODWORD(v133) = v90;
            LODWORD(v131) = v93;
          }
          LODWORD(v126) = v77;
          LODWORD(v124) = v80;
          LODWORD(v122) = v79;
          LODWORD(v121) = v84;
          LODWORD(v119) = v83;
          LODWORD(v118) = v78;
        }
        LODWORD(v117) = (unsigned __int16)WORD2(*(_QWORD *)v142);
        LODWORD(v116) = WORD1(*(_QWORD *)v142);
        LODWORD(v115) = ((unsigned int)*(_QWORD *)v142 >> 15) & 1;
        LODWORD(v114) = ((unsigned int)v76 >> 6) & 0xF;
        qdf_trace_msg(
          0x6Au,
          8u,
          v86,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          v85,
          v14,
          *(_QWORD *)v142 & 1LL,
          ((unsigned int)*(_QWORD *)v142 >> 1) & 7,
          ((unsigned int)*(_QWORD *)v142 >> 4) & 3,
          v114,
          v115,
          v116,
          v117,
          v118,
          v119,
          v120,
          v121,
          v122,
          v124,
          v126,
          v128,
          v130,
          v131,
          v133,
          v135,
          v137,
          v139);
      }
      if ( (WORD1(v145) & 0xF400) == 0x5400 )
      {
        if ( (*(_DWORD *)((_BYTE *)&v145 + 2) & 0xFF0000) != 0 )
        {
          v94 = BYTE4(v145);
          v95 = 0;
          do
          {
            v96 = *(_QWORD *)(v19 + 8 * v95);
            LODWORD(v130) = HIBYTE(v96) & 0x3F;
            LODWORD(v128) = HIWORD(v96) & 0x3F;
            LODWORD(v126) = (v96 >> 40) & 0x3F;
            LODWORD(v124) = BYTE4(v96) & 0x3F;
            LODWORD(v122) = (unsigned int)v96 >> 28;
            LODWORD(v121) = BYTE3(v96) & 0xF;
            LODWORD(v120) = ((unsigned int)v96 >> 20) & 0xF;
            LODWORD(v119) = WORD1(v96) & 0xF;
            LODWORD(v118) = ((unsigned int)v96 >> 15) & 1;
            LODWORD(v117) = ((unsigned int)v96 >> 14) & 1;
            LODWORD(v116) = ((unsigned int)v96 >> 11) & 7;
            LODWORD(v115) = ((unsigned int)v96 >> 8) & 7;
            LODWORD(v114) = (unsigned __int8)v96 >> 4;
            qdf_trace_msg(
              0x6Au,
              8u,
              "%s: <DBRCOMP><MU><%u>\n"
              "<user_id:%d>\n"
              "bw_info_valid = %d\n"
              "uplink_receive_type = %d\n"
              "uplink_11ax_mcs = %d\n"
              "nss = %d\n"
              "stream_offset = %d\n"
              "sta_dcm = %d\n"
              "sta_coding = %d\n"
              "ru_type_80_0 = %d\n"
              "ru_type_80_1 = %d\n"
              "ru_type_80_2 = %d\n"
              "ru_type_80_3 = %d\n"
              "ru_start_index_80_0 = %d\n"
              "ru_start_index_80_1 = %d\n"
              "ru_start_index_80_2 = %d\n"
              "ru_start_index_80_3 = %d\n",
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              "dump_mu_rx_info_v2",
              v14,
              (unsigned int)v95++,
              v96 & 1,
              ((unsigned int)v96 >> 1) & 3,
              v114,
              v115,
              v116,
              v117,
              v118,
              v119,
              v120,
              v121,
              v122,
              v124,
              v126,
              v128,
              v130);
          }
          while ( v94 != (_DWORD)v95 );
        }
      }
      else if ( (v145 & 0x4000000) != 0 && (*(_DWORD *)((_BYTE *)&v145 + 2) & 0xFF0000) != 0 )
      {
        v97 = BYTE4(v145);
        v98 = 0;
        do
        {
          v99 = *(_DWORD *)(v19 + 4 * v98);
          LODWORD(v118) = (v99 >> 22) & 1;
          LODWORD(v120) = HIBYTE(v99) & 0x7F;
          LODWORD(v119) = (v99 >> 23) & 1;
          LODWORD(v117) = (v99 >> 19) & 7;
          LODWORD(v116) = HIWORD(v99) & 7;
          LODWORD(v115) = (v99 >> 8) & 0x7F;
          LODWORD(v114) = (unsigned __int8)v99 >> 4;
          qdf_trace_msg(
            0x6Au,
            8u,
            "%s: <DBRCOMP><MU><%u>\n"
            "<user_id:%d>\n"
            "bw_info_valid = %d\n"
            "uplink_receive_type = %d\n"
            "uplink_11ax_mcs = %d\n"
            "ru_width = %d\n"
            "nss = %d\n"
            "stream_offset = %d\n"
            "sta_dcm = %d\n"
            "sta_coding = %d\n"
            "ru_start_index = %d\n",
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            "dump_mu_rx_info",
            v14,
            (unsigned int)v98++,
            v99 & 1,
            (v99 >> 1) & 3,
            v114,
            v115,
            v116,
            v117,
            v118,
            v119,
            v120);
        }
        while ( v97 != (_DWORD)v98 );
      }
    }
    v100 = correlate_and_relay_enh(a1, v14, (char *)v49, 0);
    if ( v100 == 1 )
    {
      v112 = 0;
      v113 = *(_QWORD *)(v15 + 1712);
      if ( (v113 & 1) == 0 )
      {
LABEL_78:
        raw_spin_unlock(v15 + 1704);
LABEL_79:
        result = v112;
        goto LABEL_17;
      }
    }
    else
    {
      if ( !v100 )
      {
        v109 = *(double (__fastcall **)(__int64, __int64, __int64, __int64, __int64, void *, __int64))(v11 + 224);
        if ( v109 )
        {
          v110 = *(_QWORD *)(v49 + 8);
          v111 = *(unsigned int *)(v49 + 16);
          if ( *((_DWORD *)v109 - 1) != 1435207299 )
            __break(0x8228u);
          v101 = v109(a1, v49 + 40, 160, v110, v111, &end_magic, 4);
        }
        dump_metadata((unsigned int *)(v49 + 40), v14, v101, v102, v103, v104, v105, v106, v107, v108);
        release_lut_entry(a1, v49);
      }
      v112 = 1;
      v113 = *(_QWORD *)(v15 + 1712);
      if ( (v113 & 1) == 0 )
        goto LABEL_78;
    }
    *(_QWORD *)(v15 + 1712) = v113 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v15 + 1704);
    goto LABEL_79;
  }
  qdf_trace_msg(0x6Au, 2u, "%s: lut is NULL", v40, v41, v42, v43, v44, v45, v46, v47, "enh_cfr_dbr_event_handler");
  v66 = *(_QWORD *)(v15 + 1712);
  if ( (v66 & 1) != 0 )
  {
    *(_QWORD *)(v15 + 1712) = v66 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v15 + 1704);
  }
  else
  {
    raw_spin_unlock(v15 + 1704);
  }
LABEL_16:
  result = 1;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
