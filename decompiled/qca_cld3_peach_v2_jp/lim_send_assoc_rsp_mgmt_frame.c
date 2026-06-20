__int64 __fastcall lim_send_assoc_rsp_mgmt_frame(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned __int8 *a4,
        unsigned __int8 a5,
        __int64 a6,
        __int64 a7,
        char a8)
{
  __int64 v15; // x1
  __int64 session_by_vdev_id; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  char *v26; // x26
  char v27; // w25
  __int64 v28; // x28
  _DWORD *v29; // x27
  char v30; // w8
  bool v31; // w25
  const char *v32; // x2
  unsigned int v33; // w8
  __int16 v34; // w8
  __int64 v35; // x1
  char v36; // w9
  int v37; // w9
  void *v38; // x0
  const void *v39; // x27
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  int v48; // w22
  __int64 result; // x0
  _QWORD *v50; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  _BYTE *v59; // x8
  int v60; // w25
  unsigned int packed_assoc_response_size; // w0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  unsigned int v70; // w22
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  char *v79; // x25
  char *v80; // x0
  char v81; // w8
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  unsigned int v90; // w8
  __int16 v91; // w8
  __int64 v92; // x5
  char *v93; // x26
  char *v94; // x9
  unsigned int v95; // w0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  int v104; // w15
  int v105; // w16
  size_t v106; // x2
  size_t v107; // x2
  int v108; // w25
  int v109; // w8
  __int64 v110; // x5
  __int64 v111; // x6
  __int64 v112; // x7
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  char v121; // w25
  __int64 v122; // x0
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  _QWORD *context; // x0
  int v132; // w0
  unsigned int v133; // w22
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  int v142; // [xsp+0h] [xbp-F0h]
  int v143; // [xsp+8h] [xbp-E8h]
  int v144; // [xsp+8h] [xbp-E8h]
  int v145; // [xsp+10h] [xbp-E0h]
  int v146; // [xsp+10h] [xbp-E0h]
  int v147; // [xsp+18h] [xbp-D8h]
  int v148; // [xsp+20h] [xbp-D0h]
  int v149; // [xsp+30h] [xbp-C0h]
  int v150; // [xsp+38h] [xbp-B8h]
  char *v151; // [xsp+60h] [xbp-90h]
  char v152; // [xsp+68h] [xbp-88h]
  char v153; // [xsp+6Ch] [xbp-84h]
  unsigned __int8 v154; // [xsp+70h] [xbp-80h]
  unsigned int v155; // [xsp+74h] [xbp-7Ch]
  __int64 v156; // [xsp+78h] [xbp-78h] BYREF
  char *v157; // [xsp+80h] [xbp-70h]
  unsigned __int16 v158; // [xsp+8Ch] [xbp-64h] BYREF
  __int64 v159; // [xsp+90h] [xbp-60h] BYREF
  __int64 v160; // [xsp+98h] [xbp-58h]
  __int64 v161; // [xsp+A0h] [xbp-50h]
  int v162; // [xsp+A8h] [xbp-48h]
  __int64 v163; // [xsp+B0h] [xbp-40h] BYREF
  unsigned int v164; // [xsp+BCh] [xbp-34h] BYREF
  char *v165; // [xsp+C0h] [xbp-30h] BYREF
  _QWORD v166[2]; // [xsp+C8h] [xbp-28h] BYREF
  char v167; // [xsp+D8h] [xbp-18h]
  __int64 v168; // [xsp+E0h] [xbp-10h]

  v168 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = *(unsigned __int8 *)(a7 + 10);
  v165 = nullptr;
  v166[0] = 0;
  v164 = 0;
  v163 = 0;
  v162 = 0;
  v160 = 0;
  v161 = 0;
  v159 = 0;
  v158 = 0;
  v167 = 0;
  v166[1] = 0;
  v156 = 0;
  v157 = nullptr;
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, v15);
  if ( !session_by_vdev_id )
  {
    v32 = "%s: pe_session is NULL";
LABEL_58:
    result = qdf_trace_msg(0x35u, 2u, v32, v17, v18, v19, v20, v21, v22, v23, v24, "lim_send_assoc_rsp_mgmt_frame");
    goto LABEL_81;
  }
  v153 = a8;
  v154 = a5;
  v25 = session_by_vdev_id;
  v26 = (char *)(session_by_vdev_id + 7024);
  v152 = *(_BYTE *)(session_by_vdev_id + 10);
  qdf_mem_set(&lim_send_assoc_rsp_mgmt_frame_frm, 0x1310u, 0);
  v27 = *v26;
  word_81FBDA = a2;
  word_81FBDC = a3 | 0xC000;
  v155 = a3;
  if ( !a6 )
  {
    populate_dot11f_supp_rates(a1, 255, &unk_81FBDE, v25);
    populate_dot11f_ext_supp_rates(a1, 255, &unk_81FBEC, v25);
    v28 = 0;
    v29 = (_DWORD *)(v25 + 88);
    v31 = (unsigned __int16)a2 == 0;
    goto LABEL_45;
  }
  populate_dot11f_assoc_rsp_rates(a1, &unk_81FBDE, &unk_81FBEC, a6 + 264, a6 + 272);
  v28 = 0;
  v29 = (_DWORD *)(v25 + 88);
  if ( !(_WORD)a2 && *(_DWORD *)(v25 + 88) == 1 )
  {
    v28 = *(_QWORD *)(*(_QWORD *)(v25 + 384) + 8LL * *(unsigned __int16 *)(a6 + 336));
    if ( v28 )
    {
      if ( *(_BYTE *)(v28 + 3268) )
        populate_dot11_assoc_res_p2p_ie(a1, &unk_820D5C, v28);
    }
  }
  if ( (v27 & 1) == 0 || (*(_WORD *)a6 & 0x80) == 0 )
  {
    if ( (v27 & 2) != 0 && (*(_WORD *)a6 & 0x40) != 0 )
    {
      populate_dot11f_wmm_params(a1, &unk_820C36, v25);
      if ( (*(_WORD *)a6 & 0x100) != 0 )
        populate_dot11f_wmm_caps(&unk_820C4A);
    }
    v30 = *(_BYTE *)(a6 + 32);
    if ( (v30 & 8) == 0 )
      goto LABEL_15;
LABEL_19:
    v31 = (unsigned __int16)a2 == 0;
    if ( *(_BYTE *)(v25 + 155) )
    {
      populate_dot11f_ht_caps(a1, v25, &byte_81FD04);
      v33 = (*(unsigned __int8 *)(a6 + 334) >> 3) & 1;
      if ( v33 >= *(unsigned __int8 *)(v25 + 160) )
        v33 = *(unsigned __int8 *)(v25 + 160);
      if ( v33 )
        v34 = word_81FD05 & 0xFFFD | (2 * v33);
      else
        v34 = word_81FD05 & 0xFFBD;
      word_81FD05 = v34;
      populate_dot11f_ht_info(a1, &unk_81FD40, v25);
      v30 = *(_BYTE *)(a6 + 32);
    }
    goto LABEL_26;
  }
  populate_dot11f_edca_param_set(a1, &unk_81FBFA, v25);
  v30 = *(_BYTE *)(a6 + 32);
  if ( (v30 & 8) != 0 )
    goto LABEL_19;
LABEL_15:
  v31 = (unsigned __int16)a2 == 0;
LABEL_26:
  if ( (v30 & 0x10) != 0 && v26[146] )
  {
    populate_dot11f_vht_caps(a1, v25, &byte_81FDE0);
    populate_dot11f_vht_operation(a1, v25, &unk_81FDF0);
    v35 = 1;
  }
  else
  {
    v35 = 0;
    if ( *(_BYTE *)(a6 + 39) == 1 && byte_81FD04 )
    {
      v35 = 0;
      byte_81FD49 = 0;
      byte_81FD09 = 0;
    }
  }
  if ( v26[146] && v28 && (v26[1604] & 1) != 0 && *(_BYTE *)(v28 + 3344) )
  {
    byte_820D68 = 1;
    v36 = v26[1603];
    byte_820D6C = 1;
    byte_820D69 = v36;
    populate_dot11f_vht_caps(a1, v25, &byte_820D6C);
    populate_dot11f_vht_operation(a1, v25, &unk_820D7C);
    v35 = 1;
  }
  populate_dot11f_ext_cap(a1, v35, &unk_81FD8A, v25);
  populate_dot11f_qcn_ie(a1, v25, &unk_820D84, 255);
  if ( *(_BYTE *)(a6 + 38) == 1 && v26[1652] == 1 )
  {
    populate_dot11f_he_caps(
      a1,
      v25,
      *(_DWORD *)(v25 + 7036),
      *(_DWORD *)(v25 + 284),
      *(_DWORD *)(v25 + 7176),
      (int)&byte_820114);
    populate_dot11f_sr_info(a1, v25, &unk_820162);
    populate_dot11f_he_operation(a1, v25, (int)&unk_820150);
    populate_dot11f_he_6ghz_cap(a1, v25, &unk_820188);
  }
  if ( (unsigned __int16)a2 == 30 )
    populate_dot11f_timeout_interval(
      a1,
      &unk_81FCFC,
      3,
      (*(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 1043LL) - *(unsigned __int8 *)(a6 + 629))
    * (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 1044LL));
  if ( *v29 == 1 && *(_BYTE *)(a6 + 646) )
    ++v26[1651];
LABEL_45:
  qdf_mem_set(&v159, 0x1Cu, 0);
  if ( *v29 == 1 && *(_BYTE *)(v25 + 428) )
    lim_decide_ap_protection(a1, a4, &v159, v25);
  lim_update_short_preamble(a1, a4, &v159, v25);
  lim_update_short_slot_time(a1, a4, &v159, v25);
  populate_dot11f_capabilities(a1, &lim_send_assoc_rsp_mgmt_frame_frm, v25, 0);
  v37 = *(unsigned __int8 *)(a1 + 14809);
  LOBYTE(v159) = *(_BYTE *)(v25 + 10);
  if ( !v37 && HIWORD(v160) )
  {
    ((void (__fastcall *)(__int64, __int64))sch_set_fixed_beacon_fields)(a1, v25);
    lim_send_beacon_params(a1, &v159, v25);
  }
  lim_obss_send_detection_cfg(a1, v25, 0);
  v38 = (void *)_qdf_mem_malloc(0xFFu, "lim_send_assoc_rsp_mgmt_frame", 2441);
  if ( !v38 )
  {
    v32 = "%s: memory alloc failed for add_ie";
    goto LABEL_58;
  }
  v39 = v38;
  if ( v28 && (LODWORD(v28) = *(unsigned __int16 *)(v25 + 7304), (unsigned int)(v28 - 1) <= 0xFE) )
  {
    qdf_mem_copy(v38, *(const void **)(v25 + 7312), *(unsigned __int16 *)(v25 + 7304));
    qdf_mem_set(v166, 0x11u, 0);
    v158 = v28;
    if ( (unsigned int)lim_strip_extcap_update_struct(a1, v39, &v158, v166) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: strip off extcap IE failed",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "lim_send_assoc_rsp_mgmt_frame");
    }
    else
    {
      LODWORD(v28) = v158;
      lim_merge_extcap_struct(&unk_81FD8A, v166, 1);
      populate_dot11f_twt_extended_caps(a1, v25, &unk_81FD8A);
    }
    v48 = v28;
  }
  else
  {
    v48 = 0;
  }
  populate_dot11f_bcn_prot_extcaps(a1, v25, &unk_81FD8A);
  if ( a4 && *(_DWORD *)(v25 + 88) == 1 )
  {
    v50 = lim_search_pre_auth_list(*(_QWORD *)(v25 + 8608), a4);
    if ( v50 )
    {
      v59 = (_BYTE *)v50[76];
      if ( !v59 )
        goto LABEL_71;
LABEL_67:
      if ( (v31 & *v59) != 0 )
        v60 = 16;
      else
        v60 = 0;
      goto LABEL_72;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: No preauth node created for %02x:%02x:%02x:**:**:%02x",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "lim_get_fils_info",
      *a4,
      a4[1],
      a4[2],
      a4[5]);
  }
  else
  {
    v59 = *(_BYTE **)(v25 + 9976);
    if ( v59 )
      goto LABEL_67;
  }
LABEL_71:
  v60 = 0;
LABEL_72:
  packed_assoc_response_size = dot11f_get_packed_assoc_response_size(a1, &lim_send_assoc_rsp_mgmt_frame_frm, &v164);
  if ( (packed_assoc_response_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: get Association Response size failure (0x%08x)",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "lim_send_assoc_rsp_mgmt_frame",
      packed_assoc_response_size);
  }
  else
  {
    if ( packed_assoc_response_size )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: get Association Response size warning (0x%08x)",
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        "lim_send_assoc_rsp_mgmt_frame");
    v70 = v48 + v60 + v164 + 24;
    if ( a6 )
      v70 += *(_DWORD *)(a6 + 48) + *(_DWORD *)(a6 + 64);
    if ( (unsigned int)cds_packet_alloc(v70, &v165, &v163) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: cds_packet_alloc failed",
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        "lim_send_assoc_rsp_mgmt_frame");
    }
    else
    {
      qdf_mem_set(v165, v70, 0);
      v79 = v165;
      v80 = v165 + 4;
      if ( v154 )
        v81 = 48;
      else
        v81 = 16;
      *v165 = v81;
      qdf_mem_copy(v80, a4, 6u);
      v79[10] = *(_BYTE *)(v25 + 30);
      v79[11] = *(_BYTE *)(v25 + 31);
      v79[12] = *(_BYTE *)(v25 + 32);
      v79[13] = *(_BYTE *)(v25 + 33);
      v79[14] = *(_BYTE *)(v25 + 34);
      v79[15] = *(_BYTE *)(v25 + 35);
      qdf_mem_copy(v79 + 16, a4, 6u);
      v90 = *(unsigned __int16 *)(a1 + 21532);
      if ( v90 <= 0xFFE )
        v91 = v90 + 1;
      else
        v91 = 2048;
      *(_WORD *)(a1 + 21532) = v91;
      *((_WORD *)v79 + 11) = (16 * (v91 & 0xF)) | *((_WORD *)v79 + 11) & 0xFF0F;
      v92 = (unsigned __int8)(*(_WORD *)(a1 + 21532) >> 4);
      *((_WORD *)v79 + 11) = (16 * *(_WORD *)(a1 + 21532)) & 0xFF00 | (16 * (v91 & 0xF));
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        "lim_populate_mac_header",
        v91 & 0xF,
        v92,
        *(unsigned __int16 *)(a1 + 21532),
        0);
      v93 = v165;
      v94 = v165;
      v165[16] = *(_BYTE *)(v25 + 24);
      v151 = v94 + 16;
      v93[17] = *(_BYTE *)(v25 + 25);
      v93[18] = *(_BYTE *)(v25 + 26);
      v93[19] = *(_BYTE *)(v25 + 27);
      v93[20] = *(_BYTE *)(v25 + 28);
      v93[21] = *(_BYTE *)(v25 + 29);
      v95 = dot11f_pack_assoc_response(a1, &lim_send_assoc_rsp_mgmt_frame_frm, v165 + 24, v164, &v164);
      if ( (v95 & 0x10000000) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Association Response pack failure(0x%08x)",
          v96,
          v97,
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          "lim_send_assoc_rsp_mgmt_frame",
          v95);
        cds_packet_free(v163);
      }
      else
      {
        if ( v95 )
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: Association Response pack warning (0x%08x)",
            v96,
            v97,
            v98,
            v99,
            v100,
            v101,
            v102,
            v103,
            "lim_send_assoc_rsp_mgmt_frame");
        if ( (unsigned int)(v28 - 1) <= 0xFE )
        {
          qdf_mem_copy(&v165[v164 + 24], v39, (unsigned int)v28);
          v164 += v28;
        }
        v104 = (unsigned __int16)a2;
        v105 = (unsigned __int16)v155;
        if ( a6 )
        {
          v106 = *(unsigned int *)(a6 + 48);
          if ( (_DWORD)v106 )
          {
            qdf_mem_copy(&v165[v164 + 24], *(const void **)(a6 + 40), v106);
            v105 = (unsigned __int16)v155;
            v104 = (unsigned __int16)a2;
            v164 += *(_DWORD *)(a6 + 48);
          }
          v107 = *(unsigned int *)(a6 + 64);
          if ( (_DWORD)v107 )
          {
            v108 = v105;
            qdf_mem_copy(&v165[v164 + 24], *(const void **)(a6 + 56), v107);
            v105 = v108;
            v104 = (unsigned __int16)a2;
            v164 += *(_DWORD *)(a6 + 64);
          }
        }
        v109 = (_DWORD)v93 + 4;
        if ( v93 == (char *)-4LL )
        {
          v112 = 0;
          v110 = 0;
          v111 = 0;
        }
        else
        {
          v110 = (unsigned __int8)v93[4];
          v111 = (unsigned __int8)v93[5];
          v112 = (unsigned __int8)v93[6];
          v109 = (unsigned __int8)v93[9];
        }
        qdf_trace_msg(
          0x35u,
          8u,
          "Assoc rsp TX: vdev %d subtype %d to %02x:%02x:%02x:**:**:%02x seq num %d status %d aid %d addn_ie_len %d ht %d"
          " vht %d vendor vht %d he %d eht %d",
          v96,
          v97,
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          *(unsigned __int8 *)(v25 + 10),
          v154,
          v110,
          v111,
          v112,
          v109,
          *(unsigned __int16 *)(a1 + 21532),
          v104,
          v105,
          v28,
          (unsigned __int8)byte_81FD04,
          (unsigned __int8)byte_81FDE0,
          (unsigned __int8)byte_820D68,
          (unsigned __int8)byte_820114,
          (unsigned __int8)byte_820898);
        LOBYTE(v145) = 0;
        LOBYTE(v142) = byte_820114 != 0;
        LOBYTE(v143) = byte_820898 != 0;
        lim_cp_stats_cstats_log_assoc_resp_evt(
          v25,
          0,
          a2,
          v155,
          v151,
          v93 + 4,
          byte_81FD04 != 0,
          byte_81FDE0 != 0,
          v142,
          v143,
          v145);
        if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v25 + 284)) && (*(_DWORD *)(v25 + 7036) & 0xFFFFFFFE) != 2 )
          v121 = 0;
        else
          v121 = 64;
        v122 = *(_QWORD *)(a1 + 21552);
        v157 = v165 + 30;
        LODWORD(v156) = v164 - 6;
        mlme_set_peer_assoc_rsp_ie(v122, a4, (unsigned int *)&v156, v113, v114, v115, v116, v117, v118, v119, v120);
        qdf_trace(53, 2u, *(_WORD *)(v25 + 8), (unsigned __int8)*(_WORD *)v93 >> 4);
        v123 = lim_diag_mgmt_tx_event_report(a1, v93, v25, 0, a2);
        context = _cds_get_context(
                    54,
                    (__int64)"lim_send_assoc_rsp_mgmt_frame",
                    v123,
                    v124,
                    v125,
                    v126,
                    v127,
                    v128,
                    v129,
                    v130);
        LOWORD(v150) = 0;
        LOBYTE(v149) = 0;
        LOWORD(v148) = 0;
        if ( (v153 & 1) != 0 )
        {
          LOBYTE(v146) = v152;
          LOBYTE(v144) = v121;
          LOBYTE(v147) = 0;
          v132 = wma_tx_packet(
                   context,
                   v163,
                   v70,
                   3,
                   1,
                   7,
                   lim_tx_complete,
                   v165,
                   lim_assoc_rsp_tx_complete,
                   v144,
                   v146,
                   v147,
                   v148,
                   12,
                   v149,
                   v150);
        }
        else
        {
          LOBYTE(v147) = 0;
          LOBYTE(v146) = v152;
          LOBYTE(v144) = v121;
          v132 = wma_tx_packet(
                   context,
                   v163,
                   v70,
                   3,
                   1,
                   7,
                   lim_tx_complete,
                   v165,
                   0,
                   v144,
                   v146,
                   v147,
                   v148,
                   12,
                   v149,
                   v150);
        }
        v133 = v132;
        qdf_trace(53, 5u, *(_WORD *)(v25 + 8), v132);
        if ( v133 )
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Could not Send Re/AssocRsp, retCode=%X",
            v134,
            v135,
            v136,
            v137,
            v138,
            v139,
            v140,
            v141,
            "lim_send_assoc_rsp_mgmt_frame",
            v133);
        lim_util_count_sta_add(a1, a6, v25);
      }
    }
  }
  _qdf_mem_free(0);
  _qdf_mem_free(0);
  result = _qdf_mem_free((__int64)v39);
LABEL_81:
  _ReadStatusReg(SP_EL0);
  return result;
}
