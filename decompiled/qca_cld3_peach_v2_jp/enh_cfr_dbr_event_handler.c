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
  __int64 v40; // x1
  __int64 v41; // x2
  __int64 v42; // x3
  __int64 v43; // x4
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int16 v52; // w9
  __int64 v53; // x22
  int v54; // w23
  __int64 v55; // x0
  unsigned int v56; // w9
  int v57; // w10
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned int v66; // w8
  char v67; // w10
  unsigned int v68; // w13
  const char *v69; // x2
  __int64 v70; // x8
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  int v79; // w13
  unsigned __int64 v80; // x9
  unsigned int v81; // w16
  int v82; // w17
  unsigned __int64 v83; // x0
  int v84; // w1
  unsigned __int64 v85; // x2
  int v86; // w4
  unsigned __int64 v87; // x13
  unsigned __int64 v88; // x15
  const char *v89; // x3
  const char *v90; // x2
  unsigned __int64 v91; // x13
  unsigned __int64 v92; // x14
  __int64 v93; // x16
  int v94; // w5
  int v95; // w20
  unsigned __int64 v96; // x2
  int v97; // w4
  int v98; // w20
  __int64 v99; // x23
  unsigned __int64 v100; // x8
  int v101; // w20
  __int64 v102; // x23
  unsigned int v103; // w8
  int v104; // w0
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  double (__fastcall *v113)(__int64, __int64, __int64, __int64, __int64, void *, __int64); // x8
  __int64 v114; // x3
  __int64 v115; // x4
  unsigned int v116; // w20
  __int64 v117; // x8
  __int64 v118; // [xsp+0h] [xbp-D0h]
  __int64 v119; // [xsp+8h] [xbp-C8h]
  __int64 v120; // [xsp+10h] [xbp-C0h]
  __int64 v121; // [xsp+18h] [xbp-B8h]
  __int64 v122; // [xsp+20h] [xbp-B0h]
  __int64 v123; // [xsp+28h] [xbp-A8h]
  __int64 v124; // [xsp+30h] [xbp-A0h]
  __int64 v125; // [xsp+38h] [xbp-98h]
  __int64 v126; // [xsp+40h] [xbp-90h]
  int v127; // [xsp+48h] [xbp-88h]
  __int64 v128; // [xsp+48h] [xbp-88h]
  int v129; // [xsp+50h] [xbp-80h]
  __int64 v130; // [xsp+50h] [xbp-80h]
  int v131; // [xsp+58h] [xbp-78h]
  __int64 v132; // [xsp+58h] [xbp-78h]
  int v133; // [xsp+60h] [xbp-70h]
  __int64 v134; // [xsp+60h] [xbp-70h]
  __int64 v135; // [xsp+68h] [xbp-68h]
  int v136; // [xsp+70h] [xbp-60h]
  __int64 v137; // [xsp+70h] [xbp-60h]
  int v138; // [xsp+78h] [xbp-58h]
  __int64 v139; // [xsp+78h] [xbp-58h]
  int v140; // [xsp+80h] [xbp-50h]
  __int64 v141; // [xsp+80h] [xbp-50h]
  unsigned int v142; // [xsp+88h] [xbp-48h]
  __int64 v143; // [xsp+88h] [xbp-48h]
  int v144; // [xsp+90h] [xbp-40h]
  char v145; // [xsp+9Ch] [xbp-34h]
  _DWORD *v146; // [xsp+A0h] [xbp-30h]
  unsigned __int64 v148; // [xsp+B0h] [xbp-20h] BYREF
  __int64 v149; // [xsp+B8h] [xbp-18h]
  __int64 v150; // [xsp+C0h] [xbp-10h]

  v150 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v148 = 0;
  v149 = 0;
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
  qdf_mem_copy(&v148, v16, 0x10u);
  if ( (v149 & 0x8000000) == 0 )
  {
    v146 = nullptr;
LABEL_8:
    v17 = 0;
    v18 = -1;
    goto LABEL_9;
  }
  v146 = v16 + 4;
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
        v145 = 5;
        if ( (v149 & 0x4000000) == 0 )
          goto LABEL_10;
LABEL_23:
        v23 = WORD1(v149) >> 12;
        v24 = 28;
        if ( v23 == 5 )
          v24 = 32;
        v25 = v23 == 3;
        v26 = 30;
        if ( !v25 )
          v26 = v24;
        if ( (v149 & 0x8000000) != 0 )
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
  v145 = v18;
  if ( (v149 & 0x4000000) != 0 )
    goto LABEL_23;
LABEL_10:
  v19 = 0;
LABEL_31:
  v28 = v148;
  v29 = (unsigned __int16)v149;
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
    v52 = HIWORD(v148);
    *(_QWORD *)(lut_entry + 8) = v16;
    v53 = lut_entry;
    *(_WORD *)(lut_entry + 20) = v52;
    v54 = ((v28 >> 6) & 0xFC) + v29;
    *(_DWORD *)(lut_entry + 16) = v54;
    *(_QWORD *)(lut_entry + 24) = *(_QWORD *)(a2 + 24);
    v55 = ktime_get(lut_entry, v40, v41, v42, v43);
    v56 = ((unsigned int)v148 >> 8) & 0x3F;
    v57 = (unsigned __int16)v149;
    *(_QWORD *)(v53 + 216) = v55 / 1000000;
    *(_DWORD *)(v53 + 224) = v56;
    *(_DWORD *)(v53 + 228) = v57;
    qdf_mem_copy((void *)(v53 + 200), &v148, 8u);
    v66 = v148;
    v67 = *(_BYTE *)(v15 + 10);
    v68 = *(_DWORD *)((char *)&v149 + 2);
    *(_DWORD *)(v53 + 86) = v54;
    *(_BYTE *)(v53 + 50) = v67;
    *(_BYTE *)(v53 + 66) = (v66 >> 28) & 7;
    *(_BYTE *)(v53 + 77) = (2 << ((v66 >> 25) & 7)) - 1;
    if ( (v17 & 1) == 0 )
    {
      *(_BYTE *)(v53 + 75) = v145;
      *(_BYTE *)(v53 + 76) = ((v66 >> 22) & 7) + 1;
      if ( (v68 & 0xC00) == 0x800 )
      {
        extract_peer_mac_from_freeze_tlv(v146, v53 + 92);
        v68 = *(_DWORD *)((char *)&v149 + 2);
      }
    }
    if ( (v68 & 0x800) != 0 )
    {
      if ( (v68 & 0xF) == 9 )
      {
        v140 = (unsigned __int16)v68 >> 12;
        v138 = HIBYTE(v68) & 0xF;
        v142 = v68 >> 28;
        v144 = HIWORD(v149);
        v136 = BYTE2(v68);
        v133 = (v68 >> 10) & 1;
        v131 = (v68 >> 8) & 1;
        v129 = (unsigned __int8)v68 >> 4;
        v69 = "%s: <DBRCOMP><%u>\n"
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
        v127 = 9;
      }
      else
      {
        v129 = (unsigned __int8)v68 >> 4;
        v69 = "%s: <DBRCOMP><%u>\n"
              "Tag: 0x%02x Length: %d udone: %d\n"
              "ctype: %d preamble: %d Nss: %d\n"
              "num_chains: %d bw: %d peervalid: %d\n"
              "peer_id: %d ppdu_id: 0x%04x\n"
              "total_bytes: %d header_version: %d\n"
              "target_id: %d cfr_fmt: %d\n"
              "mu_rx_data_incl: %d freeze_data_incl: %d\n"
              "mu_rx_num_users: %d decimation_factor: %d\n"
              "freeze_tlv_version: %d\n";
        v140 = (unsigned __int16)v68 >> 12;
        v138 = HIBYTE(v68) & 0xF;
        v136 = BYTE2(v68);
        v133 = (v68 >> 10) & 1;
        v131 = (v68 >> 8) & 1;
        v127 = v68 & 0xF;
      }
      qdf_trace_msg(
        0x6Au,
        8u,
        v69,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        "dump_enh_dma_hdr",
        v14,
        (unsigned __int8)v148,
        ((unsigned int)v148 >> 8) & 0x3F,
        WORD1(v148) & 1,
        ((unsigned int)v148 >> 17) & 7,
        ((unsigned int)v148 >> 20) & 3,
        ((unsigned int)v148 >> 22) & 7,
        ((unsigned int)v148 >> 25) & 7,
        ((unsigned int)v148 >> 28) & 7,
        (v148 >> 31) & 1,
        WORD2(v148),
        HIWORD(v148),
        (unsigned __int16)v149,
        v127,
        v129,
        v131,
        v133,
        1,
        v136,
        v138,
        v140,
        v142,
        v144);
      if ( (v149 & 0x8000000) != 0 )
      {
        v79 = WORD1(v149) >> 12;
        v80 = *(_QWORD *)v146;
        if ( v79 == 5 )
        {
          v91 = *((_QWORD *)v146 + 1);
          v92 = *((_QWORD *)v146 + 2);
          v93 = *((_QWORD *)v146 + 3);
          LODWORD(v122) = HIWORD(v80);
          LODWORD(v141) = WORD2(v93);
          LODWORD(v143) = HIWORD(v93) & 0x7FFF;
          LODWORD(v139) = ((unsigned int)v93 >> 22) & 1;
          LODWORD(v137) = WORD1(v93) & 0x3F;
          LODWORD(v135) = (unsigned __int16)v93;
          LODWORD(v134) = HIWORD(v92);
          LODWORD(v132) = WORD2(v92);
          v89 = "dump_freeze_tlv_v5";
          LODWORD(v130) = WORD1(v92);
          v90 = "%s: <DBRCOMP><FREEZE><%u>\n"
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
          LODWORD(v128) = (unsigned __int16)v92;
          LODWORD(v126) = HIWORD(v91);
          LODWORD(v125) = WORD2(v91);
          LODWORD(v124) = WORD1(v91);
          LODWORD(v123) = (unsigned __int16)v91;
        }
        else
        {
          if ( v79 == 3 )
          {
            v87 = *((_QWORD *)v146 + 1);
            v88 = *((_QWORD *)v146 + 2);
            LODWORD(v141) = ((unsigned int)v80 >> 10) & 1;
            v81 = (unsigned __int16)v146[6];
            LODWORD(v124) = HIWORD(v80);
            v82 = WORD1(v87);
            v83 = HIWORD(v87);
            v84 = WORD2(v87);
            v85 = HIWORD(v88);
            v86 = WORD1(v88);
            LODWORD(v87) = (unsigned __int16)v87;
            LODWORD(v88) = (unsigned __int16)v88;
            LODWORD(v139) = *((unsigned __int16 *)v146 + 14);
            LODWORD(v137) = HIWORD(v146[6]);
            LODWORD(v135) = v86;
            LODWORD(v134) = WORD2(v88);
            v89 = "dump_freeze_tlv_v3";
            LODWORD(v132) = v85;
            v90 = "%s: <DBRCOMP><FREEZE><%u>\n"
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
            v87 = *((_QWORD *)v146 + 1);
            v88 = *((_QWORD *)v146 + 2);
            v81 = v146[6];
            LODWORD(v124) = HIWORD(v80);
            v94 = HIWORD(v81) & 0x3F;
            v95 = (v81 >> 22) & 1;
            v81 = (unsigned __int16)v81;
            v96 = HIWORD(v88);
            v82 = WORD1(v87);
            v83 = HIWORD(v87);
            v84 = WORD2(v87);
            v97 = WORD1(v88);
            LODWORD(v87) = (unsigned __int16)v87;
            LODWORD(v88) = (unsigned __int16)v88;
            LODWORD(v134) = WORD2(v88);
            LODWORD(v132) = v96;
            v90 = "%s: <DBRCOMP><FREEZE><%u>\n"
                  "freeze: %d capture_reason: %d packet_type: 0x%x\n"
                  "packet_subtype: 0x%x sw_peer_id_valid: %d sw_peer_id: %d\n"
                  "phy_ppdu_id: 0x%04x packet_ta_upper_16: 0x%04x\n"
                  "packet_ta_mid_16: 0x%04x packet_ta_lower_16: 0x%04x\n"
                  "packet_ra_upper_16: 0x%04x packet_ra_mid_16: 0x%04x\n"
                  "packet_ra_lower_16: 0x%04x tsf_timestamp_63_48: 0x%04x\n"
                  "tsf_timestamp_47_32: 0x%04x tsf_timestamp_31_16: 0x%04x\n"
                  "tsf_timestamp_15_0: 0x%04x user_index_or_user_mask_5_0: %d\n"
                  "directed: %d\n";
            v89 = "dump_freeze_tlv";
            LODWORD(v139) = v95;
            LODWORD(v137) = v94;
            LODWORD(v135) = v97;
          }
          LODWORD(v130) = v81;
          LODWORD(v128) = v84;
          LODWORD(v126) = v83;
          LODWORD(v125) = v88;
          LODWORD(v123) = v87;
          LODWORD(v122) = v82;
        }
        LODWORD(v121) = (unsigned __int16)WORD2(*(_QWORD *)v146);
        LODWORD(v120) = WORD1(*(_QWORD *)v146);
        LODWORD(v119) = ((unsigned int)*(_QWORD *)v146 >> 15) & 1;
        LODWORD(v118) = ((unsigned int)v80 >> 6) & 0xF;
        qdf_trace_msg(
          0x6Au,
          8u,
          v90,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v89,
          v14,
          *(_QWORD *)v146 & 1LL,
          ((unsigned int)*(_QWORD *)v146 >> 1) & 7,
          ((unsigned int)*(_QWORD *)v146 >> 4) & 3,
          v118,
          v119,
          v120,
          v121,
          v122,
          v123,
          v124,
          v125,
          v126,
          v128,
          v130,
          v132,
          v134,
          v135,
          v137,
          v139,
          v141,
          v143);
      }
      if ( (WORD1(v149) & 0xF400) == 0x5400 )
      {
        if ( (*(_DWORD *)((_BYTE *)&v149 + 2) & 0xFF0000) != 0 )
        {
          v98 = BYTE4(v149);
          v99 = 0;
          do
          {
            v100 = *(_QWORD *)(v19 + 8 * v99);
            LODWORD(v134) = HIBYTE(v100) & 0x3F;
            LODWORD(v132) = HIWORD(v100) & 0x3F;
            LODWORD(v130) = (v100 >> 40) & 0x3F;
            LODWORD(v128) = BYTE4(v100) & 0x3F;
            LODWORD(v126) = (unsigned int)v100 >> 28;
            LODWORD(v125) = BYTE3(v100) & 0xF;
            LODWORD(v124) = ((unsigned int)v100 >> 20) & 0xF;
            LODWORD(v123) = WORD1(v100) & 0xF;
            LODWORD(v122) = ((unsigned int)v100 >> 15) & 1;
            LODWORD(v121) = ((unsigned int)v100 >> 14) & 1;
            LODWORD(v120) = ((unsigned int)v100 >> 11) & 7;
            LODWORD(v119) = ((unsigned int)v100 >> 8) & 7;
            LODWORD(v118) = (unsigned __int8)v100 >> 4;
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
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              "dump_mu_rx_info_v2",
              v14,
              (unsigned int)v99++,
              v100 & 1,
              ((unsigned int)v100 >> 1) & 3,
              v118,
              v119,
              v120,
              v121,
              v122,
              v123,
              v124,
              v125,
              v126,
              v128,
              v130,
              v132,
              v134);
          }
          while ( v98 != (_DWORD)v99 );
        }
      }
      else if ( (v149 & 0x4000000) != 0 && (*(_DWORD *)((_BYTE *)&v149 + 2) & 0xFF0000) != 0 )
      {
        v101 = BYTE4(v149);
        v102 = 0;
        do
        {
          v103 = *(_DWORD *)(v19 + 4 * v102);
          LODWORD(v122) = (v103 >> 22) & 1;
          LODWORD(v124) = HIBYTE(v103) & 0x7F;
          LODWORD(v123) = (v103 >> 23) & 1;
          LODWORD(v121) = (v103 >> 19) & 7;
          LODWORD(v120) = HIWORD(v103) & 7;
          LODWORD(v119) = (v103 >> 8) & 0x7F;
          LODWORD(v118) = (unsigned __int8)v103 >> 4;
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
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            "dump_mu_rx_info",
            v14,
            (unsigned int)v102++,
            v103 & 1,
            (v103 >> 1) & 3,
            v118,
            v119,
            v120,
            v121,
            v122,
            v123,
            v124);
        }
        while ( v101 != (_DWORD)v102 );
      }
    }
    v104 = correlate_and_relay_enh(a1, v14, (char *)v53, 0);
    if ( v104 == 1 )
    {
      v116 = 0;
      v117 = *(_QWORD *)(v15 + 1712);
      if ( (v117 & 1) == 0 )
      {
LABEL_78:
        raw_spin_unlock(v15 + 1704);
LABEL_79:
        result = v116;
        goto LABEL_17;
      }
    }
    else
    {
      if ( !v104 )
      {
        v113 = *(double (__fastcall **)(__int64, __int64, __int64, __int64, __int64, void *, __int64))(v11 + 224);
        if ( v113 )
        {
          v114 = *(_QWORD *)(v53 + 8);
          v115 = *(unsigned int *)(v53 + 16);
          if ( *((_DWORD *)v113 - 1) != 1435207299 )
            __break(0x8228u);
          v105 = v113(a1, v53 + 40, 160, v114, v115, &end_magic, 4);
        }
        dump_metadata((unsigned int *)(v53 + 40), v14, v105, v106, v107, v108, v109, v110, v111, v112);
        release_lut_entry(a1, v53);
      }
      v116 = 1;
      v117 = *(_QWORD *)(v15 + 1712);
      if ( (v117 & 1) == 0 )
        goto LABEL_78;
    }
    *(_QWORD *)(v15 + 1712) = v117 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v15 + 1704);
    goto LABEL_79;
  }
  qdf_trace_msg(0x6Au, 2u, "%s: lut is NULL", v44, v45, v46, v47, v48, v49, v50, v51, "enh_cfr_dbr_event_handler");
  v70 = *(_QWORD *)(v15 + 1712);
  if ( (v70 & 1) != 0 )
  {
    *(_QWORD *)(v15 + 1712) = v70 & 0xFFFFFFFFFFFFFFFELL;
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
