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
  unsigned int v31; // w25
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
  __int64 v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  char v53; // w8
  __int64 v54; // x24
  unsigned int v55; // w4
  unsigned __int8 v56; // w21
  unsigned __int16 v57; // w8
  __int64 v58; // x8
  _DWORD *v59; // x8
  int v60; // w9
  __int16 v61; // w8
  int v62; // w10
  int v63; // w8
  int v64; // w9
  char v65; // w28
  char v66; // w20
  char v67; // w22
  char v68; // w27
  int v69; // w8
  int v70; // w9
  int v71; // w10
  int v72; // w11
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  unsigned int packed_addba_rsp_size; // w0
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  unsigned int v98; // w25
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  char *v107; // x21
  char *v108; // x0
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  unsigned int v117; // w8
  __int16 v118; // w8
  __int64 v119; // x5
  char *v120; // x20
  char v121; // w21
  const char *v122; // x2
  __int64 v123; // x4
  unsigned int v124; // w0
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  _QWORD *v141; // x0
  int v142; // w0
  __int16 v143; // w2
  unsigned int v144; // w19
  __int64 result; // x0
  __int64 v146; // [xsp+0h] [xbp-B0h]
  __int64 v147; // [xsp+0h] [xbp-B0h]
  int v148; // [xsp+8h] [xbp-A8h]
  int v149; // [xsp+10h] [xbp-A0h]
  int v150; // [xsp+18h] [xbp-98h]
  char v151; // [xsp+40h] [xbp-70h]
  char v152; // [xsp+44h] [xbp-6Ch]
  char v153; // [xsp+48h] [xbp-68h]
  __int64 v155; // [xsp+50h] [xbp-60h]
  __int64 v157; // [xsp+58h] [xbp-58h]
  __int16 v159; // [xsp+64h] [xbp-4Ch] BYREF
  char v160; // [xsp+68h] [xbp-48h]
  __int16 v161; // [xsp+6Ch] [xbp-44h]
  __int16 v162; // [xsp+70h] [xbp-40h]
  unsigned __int16 v163; // [xsp+74h] [xbp-3Ch]
  __int64 v164; // [xsp+78h] [xbp-38h] BYREF
  unsigned int v165; // [xsp+84h] [xbp-2Ch] BYREF
  char *v166; // [xsp+88h] [xbp-28h] BYREF
  __int64 v167; // [xsp+90h] [xbp-20h] BYREF
  int v168; // [xsp+98h] [xbp-18h]
  __int64 v169; // [xsp+A0h] [xbp-10h]

  LOWORD(v19) = a8;
  v169 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v168 = 0;
  v166 = nullptr;
  v167 = 0;
  v165 = 0;
  v164 = 0;
  v163 = 0;
  v162 = 0;
  v161 = 0;
  v160 = 0;
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
  v159 = 0;
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
  qdf_mem_set(&v167, 0xCu, 0);
  LOWORD(v167) = 259;
  BYTE2(v167) = v160;
  WORD2(v167) = v162;
  v44 = dph_lookup_hash_entry(v36, v37, v38, v39, v40, v41, v42, v43, a1, a2, &v159, a4 + 360);
  if ( v44 && *(_BYTE *)(a4 + 8676) == 1 )
    v53 = *(_BYTE *)(v44 + 38);
  else
    v53 = 0;
  v54 = a1 + 20480;
  v155 = v44;
  if ( (unsigned int)(*(_DWORD *)(a4 + 88) - 1) > 1 )
  {
    if ( !*(_BYTE *)(a1 + 21621) )
      goto LABEL_26;
    goto LABEL_47;
  }
  v55 = *(_DWORD *)(v35 + 2708);
  if ( v55 == 1 && !*(_WORD *)(a1 + 21622) )
  {
LABEL_47:
    v56 = a5;
    goto LABEL_48;
  }
  v56 = a5;
  if ( !*(_BYTE *)(a1 + 21621) )
  {
    if ( !*(_WORD *)(a1 + 21622) )
    {
      if ( v55 >= (unsigned __int16)v19 )
        v19 = (unsigned __int16)v19;
      else
        v19 = v55;
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
      if ( v19 >= 0x100 )
        v19 = 256;
      if ( !v32 )
        goto LABEL_55;
      goto LABEL_49;
    }
LABEL_26:
    if ( !v44 || *(_BYTE *)(v44 + 344) != 5 )
    {
      if ( (v53 & 1) != 0 )
        LOWORD(v19) = 256;
      else
        LOWORD(v19) = 64;
    }
    v57 = *(_WORD *)(a1 + 21622);
    if ( !v57 )
      v57 = v19;
    if ( (v57 & 0xFF00) != 0 )
      v19 = 256;
    else
      v19 = v57;
    if ( v57 < 0x41u )
    {
      if ( (*(_BYTE *)(a4 + 10043) & 1) == 0 )
        *(_BYTE *)(a4 + 10043) = 1;
    }
    else if ( *(_BYTE *)(a4 + 10043) )
    {
      v19 = 64;
    }
    v56 = a5;
    if ( v163 && v19 > v163 )
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
      v19 = v163;
    }
    if ( !v32 )
      goto LABEL_55;
    goto LABEL_49;
  }
LABEL_48:
  WORD2(v167) = 37;
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
  if ( !v32 )
  {
LABEL_55:
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
    goto LABEL_56;
  }
LABEL_49:
  if ( !*v32 )
    goto LABEL_55;
  v58 = **v32;
  if ( v58 )
  {
    v59 = *(_DWORD **)(v58 + 464);
    if ( v59 )
    {
      if ( *(v59 - 1) != -1786116689 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64 **, unsigned __int8 *, _QWORD, _QWORD, _QWORD))v59)(v32, a2, v31, a3, v19);
    }
  }
LABEL_56:
  v60 = *(unsigned __int8 *)(a1 + 21624);
  HIWORD(v167) = BYTE6(v167) & 3 | (4 * (a3 & 0xF)) | ((_WORD)v19 << 6);
  if ( v60 == 1
    && (*(_BYTE *)(a4 + 8676) == 1 && wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284))
     || !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284))
     || v155 && *(_BYTE *)(v155 + 344) == 4 && (*(_BYTE *)(v155 + 38) & 1) != 0) )
  {
    v61 = HIWORD(v167) & 0xFFFE | a6 & 1;
  }
  else
  {
    v61 = HIWORD(v167) & 0xFFFE;
  }
  v157 = a1;
  HIWORD(v167) = v61 | 2;
  LOWORD(v168) = v161;
  if ( v56 )
  {
    v62 = *(unsigned __int8 *)(a4 + 8676);
    v63 = HIBYTE(v168) & 0x1E | (v19 >> 5) & 0xE0;
    BYTE2(v168) = 1;
    HIBYTE(v168) = HIBYTE(v168) & 0x1E | (v19 >> 5) & 0xE0 | 1;
    if ( v62 == 1 )
    {
      v64 = (*(unsigned __int8 *)(a4 + 8681) >> 3) & 3;
      if ( v64 )
        HIBYTE(v168) = v63 & 0xF8 | (2 * v64);
    }
  }
  v65 = *(_BYTE *)(a4 + 30);
  v66 = *(_BYTE *)(a4 + 31);
  v67 = *(_BYTE *)(a4 + 32);
  v68 = *(_BYTE *)(a4 + 35);
  v151 = v31;
  if ( a2 )
  {
    v69 = *a2;
    v70 = a2[1];
    v71 = a2[2];
    v72 = a2[5];
  }
  else
  {
    v71 = 0;
    v69 = 0;
    v70 = 0;
    v72 = 0;
  }
  v152 = *(_BYTE *)(a4 + 34);
  v153 = *(_BYTE *)(a4 + 33);
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
    *(unsigned __int8 *)(a4 + 30),
    *(unsigned __int8 *)(a4 + 31),
    *(unsigned __int8 *)(a4 + 32),
    *(unsigned __int8 *)(a4 + 35),
    v69,
    v70,
    v71,
    v72);
  LODWORD(v146) = BYTE6(v167) & 1;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: tid %d dialog_token %d status %d buff_size %d amsdu_supp %d",
    v73,
    v74,
    v75,
    v76,
    v77,
    v78,
    v79,
    v80,
    "lim_send_addba_response_frame",
    (unsigned __int16)a3,
    BYTE2(v167),
    WORD2(v167),
    HIWORD(v167) >> 6,
    v146);
  LODWORD(v147) = HIBYTE(v168) >> 5;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: addba_extn %d he_capable %d no_frag %d he_frag %d, exted buff size %d",
    v81,
    v82,
    v83,
    v84,
    v85,
    v86,
    v87,
    v88,
    "lim_send_addba_response_frame",
    v56,
    *(unsigned __int8 *)(a4 + 8676),
    HIBYTE(v168) & 1,
    (HIBYTE(v168) >> 1) & 3,
    v147);
  packed_addba_rsp_size = dot11f_get_packed_addba_rsp_size(v157, &v167, &v165);
  if ( (packed_addba_rsp_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a ADDBA Response (0x%08x).",
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      "lim_send_addba_response_frame",
      packed_addba_rsp_size);
    v165 = 12;
  }
  else if ( packed_addba_rsp_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating the packed size for a ADDBA Response (0x%08x).",
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      "lim_send_addba_response_frame");
  }
  v98 = v165;
  if ( (unsigned int)cds_packet_alloc((unsigned __int16)v165 + 24, &v166, &v164) || !v164 )
  {
    v122 = "%s: Failed to allocate %d bytes for a ADDBA response action frame";
    v123 = v98 + 24;
  }
  else
  {
    qdf_mem_set(v166, v98 + 24, 0);
    v107 = v166;
    v108 = v166 + 4;
    *v166 = -48;
    qdf_mem_copy(v108, a2, 6u);
    v107[10] = v65;
    v107[11] = v66;
    v107[12] = v67;
    v107[13] = v153;
    v107[14] = v152;
    v107[15] = v68;
    qdf_mem_copy(v107 + 16, a2, 6u);
    v117 = *(unsigned __int16 *)(v54 + 1052);
    if ( v117 <= 0xFFE )
      v118 = v117 + 1;
    else
      v118 = 2048;
    *(_WORD *)(v54 + 1052) = v118;
    *((_WORD *)v107 + 11) = (16 * (v118 & 0xF)) | *((_WORD *)v107 + 11) & 0xFF0F;
    v119 = (unsigned __int8)(*(_WORD *)(v54 + 1052) >> 4);
    *((_WORD *)v107 + 11) = (16 * *(_WORD *)(v54 + 1052)) & 0xFF00 | (16 * (v118 & 0xF));
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      v115,
      v116,
      "lim_populate_mac_header",
      v118 & 0xF,
      v119,
      *(unsigned __int16 *)(v54 + 1052),
      0);
    v120 = v166;
    v166[16] = *a17;
    v120[17] = a17[1];
    v120[18] = a17[2];
    v120[19] = a17[3];
    v120[20] = a17[4];
    v120[21] = a17[5];
    lim_set_protected_bit(v157, a4, a2, v120);
    v121 = 0;
    if ( a7 && v155 )
    {
      if ( *(_BYTE *)(v155 + 344) == 5 )
      {
        v121 = 32;
        *(_WORD *)v120 |= 0x4000u;
      }
      else
      {
        v121 = 0;
      }
    }
    v124 = dot11f_pack_addba_rsp(v157, &v167, v166 + 24, v165, &v165);
    if ( (v124 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to pack a ADDBA Response (0x%08x)",
        v125,
        v126,
        v127,
        v128,
        v129,
        v130,
        v131,
        v132,
        "lim_send_addba_response_frame",
        v124);
      cds_packet_free(v164);
      goto LABEL_97;
    }
    if ( v124 )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: There were warnings while packing ADDBA Response (0x%08x)",
        v125,
        v126,
        v127,
        v128,
        v129,
        v130,
        v131,
        v132,
        "lim_send_addba_response_frame");
    if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284)) || (*(_DWORD *)(a4 + 7036) & 0xFFFFFFFE) == 2 )
      v121 |= 0x40u;
    qdf_trace(53, 2u, *(_WORD *)(a4 + 8), (unsigned __int8)*(_WORD *)v120 >> 4);
    v141 = _cds_get_context(
             54,
             (__int64)"lim_send_addba_response_frame",
             v133,
             v134,
             v135,
             v136,
             v137,
             v138,
             v139,
             v140);
    LOBYTE(v149) = v151;
    LOBYTE(v148) = v121;
    LOBYTE(v150) = 0;
    v142 = wma_tx_packet(
             v141,
             v164,
             v98 + 24,
             3,
             1,
             7,
             0,
             v166,
             lim_addba_rsp_tx_complete_cnf,
             v148,
             v149,
             v150,
             0,
             12,
             0,
             0);
    v143 = *(_WORD *)(a4 + 8);
    v144 = v142;
    qdf_trace(53, 5u, v143, v142);
    if ( !v144 )
    {
      result = 0;
      goto LABEL_98;
    }
    v122 = "%s: wma_tx_frame FAILED! Status [%d]";
    v123 = v144;
  }
  qdf_trace_msg(0x35u, 2u, v122, v99, v100, v101, v102, v103, v104, v105, v106, "lim_send_addba_response_frame", v123);
LABEL_97:
  result = 16;
LABEL_98:
  _ReadStatusReg(SP_EL0);
  return result;
}
