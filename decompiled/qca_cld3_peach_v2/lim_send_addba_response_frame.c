__int64 __fastcall lim_send_addba_response_frame(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned int a3,
        __int64 a4,
        unsigned __int8 a5,
        char a6,
        char a7,
        __int16 a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        char *a17)
{
  unsigned int v19; // w20
  __int64 **context; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w26
  __int64 **v32; // x28
  __int64 v33; // x8
  void (*v34)(void); // x8
  __int64 v35; // x21
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  _BYTE *v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  char v53; // w8
  char v54; // w22
  unsigned int v55; // w4
  __int16 v56; // w8
  unsigned __int16 v57; // w8
  unsigned int v58; // w11
  unsigned int v59; // w8
  __int64 v60; // x8
  _DWORD *v61; // x8
  int v62; // w9
  __int16 v63; // w8
  int v64; // w10
  int v65; // w8
  int v66; // w9
  unsigned __int8 *v67; // x13
  unsigned __int8 *v68; // x10
  unsigned __int8 *v69; // x11
  unsigned __int8 *v70; // x12
  char *v71; // x8
  char *v72; // x9
  unsigned __int8 *v73; // x13
  __int64 v74; // x0
  unsigned int v75; // w20
  unsigned int v76; // w28
  unsigned int v77; // w22
  unsigned int v78; // w27
  int v79; // w10
  int v80; // w11
  int v81; // w12
  int v82; // w13
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  unsigned int packed_addba_rsp_size; // w0
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  unsigned int v108; // w24
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  char *v117; // x26
  char *v118; // x0
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  unsigned int v127; // w8
  __int16 v128; // w8
  __int64 v129; // x5
  char *v130; // x20
  char v131; // w21
  char v132; // w22
  const char *v133; // x2
  __int64 v134; // x4
  unsigned int v135; // w0
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  _QWORD *v152; // x0
  int v153; // w0
  __int16 v154; // w2
  unsigned int v155; // w19
  __int64 result; // x0
  __int64 v157; // [xsp+0h] [xbp-C0h]
  __int64 v158; // [xsp+0h] [xbp-C0h]
  int v159; // [xsp+8h] [xbp-B8h]
  int v160; // [xsp+10h] [xbp-B0h]
  int v161; // [xsp+18h] [xbp-A8h]
  __int16 v162; // [xsp+48h] [xbp-78h]
  char v163; // [xsp+4Ch] [xbp-74h]
  char v164; // [xsp+50h] [xbp-70h]
  _BYTE *v166; // [xsp+58h] [xbp-68h]
  char v169; // [xsp+70h] [xbp-50h]
  __int16 v170; // [xsp+74h] [xbp-4Ch] BYREF
  char v171; // [xsp+78h] [xbp-48h]
  __int16 v172; // [xsp+7Ch] [xbp-44h]
  __int16 v173; // [xsp+80h] [xbp-40h]
  unsigned __int16 v174; // [xsp+84h] [xbp-3Ch]
  __int64 v175; // [xsp+88h] [xbp-38h] BYREF
  unsigned int v176; // [xsp+94h] [xbp-2Ch] BYREF
  char *v177; // [xsp+98h] [xbp-28h] BYREF
  __int64 v178; // [xsp+A0h] [xbp-20h] BYREF
  int v179; // [xsp+A8h] [xbp-18h]
  __int64 v180; // [xsp+B0h] [xbp-10h]

  LOWORD(v19) = a8;
  v180 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v179 = 0;
  v177 = nullptr;
  v178 = 0;
  v176 = 0;
  v175 = 0;
  v174 = 0;
  v173 = 0;
  v172 = 0;
  v171 = 0;
  context = (__int64 **)_cds_get_context(
                          71,
                          (__int64)"lim_send_addba_response_frame",
                          a9,
                          a10,
                          a11,
                          a12,
                          a13,
                          a14,
                          a15,
                          a16);
  v31 = *(unsigned __int8 *)(a4 + 10);
  v32 = context;
  v170 = 0;
  if ( context && *context )
  {
    v33 = **context;
    if ( v33 )
    {
      v34 = *(void (**)(void))(v33 + 448);
      if ( v34 )
      {
        if ( *((_DWORD *)v34 - 1) != -456530754 )
          __break(0x8228u);
        v34();
      }
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v23, v24, v25, v26, v27, v28, v29, v30, "cdp_addba_responsesetup");
  }
  v35 = *(_QWORD *)(a1 + 8);
  qdf_mem_set(&v178, 0xCu, 0);
  LOWORD(v178) = 259;
  BYTE2(v178) = v171;
  WORD2(v178) = v173;
  v44 = (_BYTE *)dph_lookup_hash_entry(v36, v37, v38, v39, v40, v41, v42, v43, a1, a2, &v170, a4 + 360);
  if ( v44 )
  {
    if ( *(_BYTE *)(a4 + 8676) == 1 )
    {
      v53 = v44[38];
      if ( !a4 )
        goto LABEL_17;
    }
    else
    {
      v53 = 0;
      if ( !a4 )
        goto LABEL_17;
    }
    if ( *(_BYTE *)(a4 + 10071) == 1 )
    {
      v54 = v44[68];
      goto LABEL_18;
    }
  }
  else
  {
    v53 = 0;
  }
LABEL_17:
  v54 = 0;
LABEL_18:
  v166 = v44;
  if ( (unsigned int)(*(_DWORD *)(a4 + 88) - 1) > 1 )
  {
    if ( !*(_BYTE *)(a1 + 21693) )
      goto LABEL_32;
LABEL_58:
    WORD2(v178) = 37;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: refused addba req for rx_aggregation_size: %d mac_ctx->reject_addba_req: %d",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "lim_send_addba_response_frame");
    v19 = 0;
    goto LABEL_59;
  }
  v55 = *(_DWORD *)(v35 + 2912);
  if ( v55 == 1 && !*(_WORD *)(a1 + 21694) || *(_BYTE *)(a1 + 21693) )
    goto LABEL_58;
  if ( !*(_WORD *)(a1 + 21694) )
  {
    if ( v55 >= (unsigned __int16)v19 )
      v19 = (unsigned __int16)v19;
    else
      v19 = *(_DWORD *)(v35 + 2912);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: rx_aggregation_size %d, calc_buff_size %d",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "lim_send_addba_response_frame");
    if ( (v54 & 1) != 0 )
    {
      if ( v19 >= 0x400 )
        v19 = 1024;
      if ( !v32 )
        goto LABEL_69;
    }
    else
    {
      if ( v19 >= 0x100 )
        v19 = 256;
      if ( !v32 )
        goto LABEL_69;
    }
    goto LABEL_60;
  }
LABEL_32:
  if ( !v44 || v44[356] != 5 )
  {
    if ( (v53 & 1) != 0 )
      v56 = 256;
    else
      v56 = 64;
    if ( (v54 & 1) != 0 )
      LOWORD(v19) = 1024;
    else
      LOWORD(v19) = v56;
  }
  v57 = *(_WORD *)(a1 + 21694);
  if ( !v57 )
    v57 = v19;
  v58 = v57;
  if ( (v54 & 1) != 0 )
    v59 = 1024;
  else
    v59 = 256;
  if ( v59 >= v58 )
    v19 = v58;
  else
    v19 = v59;
  if ( v58 < 0x41 )
  {
    if ( (*(_BYTE *)(a4 + 10043) & 1) == 0 )
      *(_BYTE *)(a4 + 10043) = 1;
  }
  else if ( *(_BYTE *)(a4 + 10043) )
  {
    v19 = 64;
  }
  if ( v174 && v19 > v174 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: buff size: %d larger than peer's capability: %d",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "lim_send_addba_response_frame",
      v19);
    v19 = v174;
    if ( !v32 )
      goto LABEL_69;
    goto LABEL_60;
  }
LABEL_59:
  if ( !v32 )
  {
LABEL_69:
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance:",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "cdp_tid_update_ba_win_size");
    goto LABEL_70;
  }
LABEL_60:
  if ( !*v32 )
    goto LABEL_69;
  v60 = **v32;
  if ( v60 )
  {
    v61 = *(_DWORD **)(v60 + 464);
    if ( v61 )
    {
      if ( *(v61 - 1) != -1786116689 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64 **, unsigned __int8 *, _QWORD, _QWORD, _QWORD))v61)(v32, a2, v31, a3, v19);
    }
  }
LABEL_70:
  v62 = *(unsigned __int8 *)(a1 + 21696);
  HIWORD(v178) = BYTE6(v178) & 3 | (4 * (a3 & 0xF)) | ((_WORD)v19 << 6);
  if ( v62 == 1
    && (*(_BYTE *)(a4 + 8676) == 1 && wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284))
     || !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284))
     || v166 && v166[356] == 4 && (v166[38] & 1) != 0) )
  {
    v63 = HIWORD(v178) & 0xFFFE | a6 & 1;
  }
  else
  {
    v63 = HIWORD(v178) & 0xFFFE;
  }
  HIWORD(v178) = v63 | 2;
  LOWORD(v179) = v172;
  if ( a5 )
  {
    v64 = *(unsigned __int8 *)(a4 + 8676);
    v65 = HIBYTE(v179) & 0x1E | (v19 >> 5) & 0xE0;
    BYTE2(v179) = 1;
    HIBYTE(v179) = HIBYTE(v179) & 0x1E | (v19 >> 5) & 0xE0 | 1;
    if ( v64 == 1 )
    {
      v66 = (*(unsigned __int8 *)(a4 + 8681) >> 3) & 3;
      if ( v66 )
        HIBYTE(v179) = v65 & 0xF8 | (2 * v66);
    }
  }
  if ( (*(unsigned __int8 *)(a4 + 24) != *a2
     || *(unsigned __int8 *)(a4 + 25) != a2[1]
     || *(unsigned __int8 *)(a4 + 26) != a2[2]
     || *(unsigned __int8 *)(a4 + 27) != a2[3]
     || *(unsigned __int8 *)(a4 + 28) != a2[4]
     || *(unsigned __int8 *)(a4 + 29) != a2[5])
    && wlan_mlo_get_tdls_link_vdev(*(_QWORD *)(a4 + 16)) )
  {
    v67 = *(unsigned __int8 **)(a4 + 16);
    v68 = v67 + 80;
    v69 = v67 + 81;
    v70 = v67 + 82;
    v71 = (char *)(v67 + 83);
    v72 = (char *)(v67 + 84);
    v73 = v67 + 85;
LABEL_91:
    v162 = 769;
    goto LABEL_96;
  }
  v74 = *(_QWORD *)(a4 + 16);
  if ( *(_DWORD *)(v74 + 16) == 1 && (wlan_vdev_mlme_is_mlo_vdev(v74, v45, v46, v47, v48, v49, v50, v51, v52) & 1) != 0 )
  {
    v68 = (unsigned __int8 *)(a4 + 30);
    v69 = (unsigned __int8 *)(a4 + 31);
    v70 = (unsigned __int8 *)(a4 + 32);
    v71 = (char *)(a4 + 33);
    v72 = (char *)(a4 + 34);
    v73 = (unsigned __int8 *)(a4 + 35);
    goto LABEL_91;
  }
  v68 = (unsigned __int8 *)(a4 + 30);
  v69 = (unsigned __int8 *)(a4 + 31);
  v70 = (unsigned __int8 *)(a4 + 32);
  v71 = (char *)(a4 + 33);
  v72 = (char *)(a4 + 34);
  v73 = (unsigned __int8 *)(a4 + 35);
  v162 = 0;
LABEL_96:
  v75 = *v70;
  v76 = *v69;
  v77 = *v68;
  v78 = *v73;
  if ( a2 )
  {
    v79 = *a2;
    v80 = a2[1];
    v81 = a2[2];
    v82 = a2[5];
  }
  else
  {
    v81 = 0;
    v79 = 0;
    v80 = 0;
    v82 = 0;
  }
  v163 = *v71;
  v164 = *v72;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Sending a ADDBA Response from %02x:%02x:%02x:**:**:%02x to %02x:%02x:%02x:**:**:%02x",
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    "lim_send_addba_response_frame",
    v77,
    v76,
    v75,
    v78,
    v79,
    v80,
    v81,
    v82);
  LODWORD(v157) = BYTE6(v178) & 1;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: tid %d dialog_token %d status %d buff_size %d amsdu_supp %d",
    v83,
    v84,
    v85,
    v86,
    v87,
    v88,
    v89,
    v90,
    "lim_send_addba_response_frame",
    (unsigned __int16)a3,
    BYTE2(v178),
    WORD2(v178),
    HIWORD(v178) >> 6,
    v157);
  LODWORD(v158) = HIBYTE(v179) >> 5;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: addba_extn %d he_capable %d no_frag %d he_frag %d, exted buff size %d",
    v91,
    v92,
    v93,
    v94,
    v95,
    v96,
    v97,
    v98,
    "lim_send_addba_response_frame",
    a5,
    *(unsigned __int8 *)(a4 + 8676),
    HIBYTE(v179) & 1,
    (HIBYTE(v179) >> 1) & 3,
    v158);
  packed_addba_rsp_size = dot11f_get_packed_addba_rsp_size(a1, &v178, &v176);
  if ( (packed_addba_rsp_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a ADDBA Response (0x%08x).",
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      "lim_send_addba_response_frame",
      packed_addba_rsp_size);
    v176 = 12;
  }
  else if ( packed_addba_rsp_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating the packed size for a ADDBA Response (0x%08x).",
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      "lim_send_addba_response_frame");
  }
  v108 = v176;
  if ( (unsigned int)cds_packet_alloc((unsigned __int16)v176 + 24, &v177, &v175) || !v175 )
  {
    v133 = "%s: Failed to allocate %d bytes for a ADDBA response action frame";
    v134 = v108 + 24;
  }
  else
  {
    v169 = v31;
    qdf_mem_set(v177, v108 + 24, 0);
    v117 = v177;
    v118 = v177 + 4;
    *v177 = -48;
    qdf_mem_copy(v118, a2, 6u);
    v117[10] = v77;
    v117[11] = v76;
    v117[12] = v75;
    v117[13] = v163;
    v117[14] = v164;
    v117[15] = v78;
    qdf_mem_copy(v117 + 16, a2, 6u);
    v127 = *(unsigned __int16 *)(a1 + 21604);
    if ( v127 <= 0xFFE )
      v128 = v127 + 1;
    else
      v128 = 2048;
    *(_WORD *)(a1 + 21604) = v128;
    *((_WORD *)v117 + 11) = (16 * (v128 & 0xF)) | *((_WORD *)v117 + 11) & 0xFF0F;
    v129 = (unsigned __int8)(*(_WORD *)(a1 + 21604) >> 4);
    *((_WORD *)v117 + 11) = (16 * *(_WORD *)(a1 + 21604)) & 0xFF00 | (16 * (v128 & 0xF));
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      v125,
      v126,
      "lim_populate_mac_header",
      v128 & 0xF,
      v129,
      *(unsigned __int16 *)(a1 + 21604),
      0);
    v130 = v177;
    v177[16] = *a17;
    v130[17] = a17[1];
    v130[18] = a17[2];
    v130[19] = a17[3];
    v130[20] = a17[4];
    v130[21] = a17[5];
    lim_set_protected_bit(a1, a4, a2, v130);
    v131 = 0;
    if ( a7 )
    {
      v132 = v169;
      if ( v166 )
      {
        if ( v166[356] == 5 )
        {
          v131 = 32;
          *(_WORD *)v130 |= 0x4000u;
        }
        else
        {
          v131 = 0;
        }
      }
    }
    else
    {
      v132 = v169;
    }
    v135 = dot11f_pack_addba_rsp(a1, &v178, v177 + 24, v176, &v176);
    if ( (v135 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to pack a ADDBA Response (0x%08x)",
        v136,
        v137,
        v138,
        v139,
        v140,
        v141,
        v142,
        v143,
        "lim_send_addba_response_frame",
        v135);
      cds_packet_free(v175);
      goto LABEL_125;
    }
    if ( v135 )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: There were warnings while packing ADDBA Response (0x%08x)",
        v136,
        v137,
        v138,
        v139,
        v140,
        v141,
        v142,
        v143,
        "lim_send_addba_response_frame");
    if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284)) || (*(_DWORD *)(a4 + 7036) & 0xFFFFFFFE) == 2 )
      v131 |= 0x40u;
    qdf_trace(53, 2u, *(_WORD *)(a4 + 8), (unsigned __int8)*(_WORD *)v130 >> 4);
    v152 = _cds_get_context(
             54,
             (__int64)"lim_send_addba_response_frame",
             v144,
             v145,
             v146,
             v147,
             v148,
             v149,
             v150,
             v151);
    LOBYTE(v160) = v132;
    LOBYTE(v159) = v131;
    LOBYTE(v161) = 0;
    v153 = wma_tx_packet(
             v152,
             v175,
             v108 + 24,
             3,
             1,
             7,
             0,
             v177,
             lim_addba_rsp_tx_complete_cnf,
             v159,
             v160,
             v161,
             0,
             12,
             0,
             v162);
    v154 = *(_WORD *)(a4 + 8);
    v155 = v153;
    qdf_trace(53, 5u, v154, v153);
    if ( !v155 )
    {
      result = 0;
      goto LABEL_126;
    }
    v133 = "%s: wma_tx_frame FAILED! Status [%d]";
    v134 = v155;
  }
  qdf_trace_msg(0x35u, 2u, v133, v109, v110, v111, v112, v113, v114, v115, v116, "lim_send_addba_response_frame", v134);
LABEL_125:
  result = 16;
LABEL_126:
  _ReadStatusReg(SP_EL0);
  return result;
}
