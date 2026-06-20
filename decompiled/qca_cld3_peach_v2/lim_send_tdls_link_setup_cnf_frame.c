__int64 __fastcall lim_send_tdls_link_setup_cnf_frame(
        __int64 a1,
        __int64 a2,
        char a3,
        char a4,
        __int64 a5,
        const void *a6,
        unsigned __int16 a7,
        int a8)
{
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x23
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  _BYTE *v34; // x21
  __int64 v35; // x10
  char v36; // w8
  __int16 v37; // w8
  unsigned int v38; // w26
  const char *v39; // x2
  __int64 result; // x0
  __int64 v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int packed_tdls_setup_cnf_size; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  int v59; // w9
  unsigned int v60; // w24
  unsigned int v61; // w22
  unsigned int v62; // w21
  unsigned int v63; // w28
  unsigned int v64; // w27
  unsigned int v65; // w8
  unsigned int v66; // w9
  unsigned __int16 v67; // w26
  unsigned int v68; // w25
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x5
  __int64 v78; // x28
  unsigned int v79; // w0
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  unsigned __int16 v96; // w26
  bool v97; // cf
  unsigned __int8 *v98; // x21
  char *v99; // x8
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  __int64 assoc_link_vdev; // x0
  unsigned __int8 v117; // w23
  _QWORD *v118; // x20
  char *v119; // x21
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  _QWORD *context; // x0
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  unsigned int v137; // [xsp+4Ch] [xbp-54h]
  unsigned __int16 v138; // [xsp+50h] [xbp-50h]
  const void *v139; // [xsp+58h] [xbp-48h]
  __int64 v140; // [xsp+60h] [xbp-40h]
  int v141; // [xsp+6Ch] [xbp-34h]
  const void *v142; // [xsp+70h] [xbp-30h]
  char v143[4]; // [xsp+7Ch] [xbp-24h] BYREF
  _QWORD *v144; // [xsp+80h] [xbp-20h] BYREF
  char *v145; // [xsp+88h] [xbp-18h] BYREF
  unsigned int v146; // [xsp+94h] [xbp-Ch] BYREF
  __int64 v147; // [xsp+98h] [xbp-8h]

  v147 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v146 = 0;
  v144 = nullptr;
  v145 = nullptr;
  v143[0] = 0;
  v16 = _qdf_mem_malloc(0x20Cu, "lim_send_tdls_link_setup_cnf_frame", 2882);
  if ( !v16 )
  {
    v39 = "%s: memory allocation failed for SetupCnf";
LABEL_17:
    result = qdf_trace_msg(0x35u, 2u, v39, v17, v18, v19, v20, v21, v22, v23, v24, "lim_send_tdls_link_setup_cnf_frame");
    goto LABEL_71;
  }
  v25 = v16;
  *(_WORD *)v16 = 524;
  *(_BYTE *)(v16 + 4) = a3;
  v26 = populate_dot11f_link_iden(a5, v16 + 458, a2 & 0xFFFFFFFFFFFFLL, 0);
  if ( (a4 & 4) != 0 && *(_BYTE *)(a1 + 11370) == 1 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: populate WMM praram in Setup Confirm",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "lim_send_tdls_link_setup_cnf_frame");
    populate_dot11f_wmm_params(a1, v25 + 478, a5);
  }
  v34 = (_BYTE *)(a5 + 7024);
  if ( (a4 & 2) != 0 )
  {
    populate_dot11f_vht_operation(a1, a5, v25 + 498);
LABEL_19:
    populate_dot11f_ht_info(a1, v25 + 400, a5, v26, v27, v28, v29, v30, v31, v32, v33);
    if ( (a4 & 8) == 0 )
      goto LABEL_14;
    goto LABEL_8;
  }
  if ( (a4 & 1) != 0 )
    goto LABEL_19;
  if ( (a4 & 8) == 0 )
    goto LABEL_14;
LABEL_8:
  v35 = *(_QWORD *)(a1 + 8);
  *(_DWORD *)(v25 + 507) &= ~0x80000u;
  v36 = *(_BYTE *)(v25 + 511) & 0xC0 | *(_BYTE *)(a5 + 8767) & 0x3F;
  if ( (*(_BYTE *)(a5 + 8767) & 0x3F) == 0 )
    v36 = *(_BYTE *)(v25 + 511) & 0x40 | 0x80;
  *(_BYTE *)(v25 + 511) = v36;
  if ( *(_BYTE *)(a5 + 8635) == 1 )
    v37 = -4;
  else
    v37 = -16;
  *(_WORD *)(v25 + 512) = v37 | *(_WORD *)(v35 + 1480);
  populate_dot11f_he_operation(a1, a5, (_BYTE *)(v25 + 506));
LABEL_14:
  if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a5 + 16), v26, v27, v28, v29, v30, v31, v32, v33) & 1) != 0 )
    v38 = lim_send_tdls_mgmt_frame_mlo(a1, a5);
  else
    v38 = 0;
  v141 = a8;
  v140 = a2;
  if ( *(_BYTE *)(a5 + 10071) == 1 )
  {
    v41 = lim_ieee80211_pack_ehtcap_tdls(a1, a5, v143);
    if ( !v41 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: malloc failed for eht_cap_ie",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "lim_send_tdls_link_setup_cnf_frame");
LABEL_70:
      result = _qdf_mem_free(v25);
      goto LABEL_71;
    }
  }
  else
  {
    v41 = 0;
  }
  v142 = (const void *)v41;
  packed_tdls_setup_cnf_size = dot11f_get_packed_tdls_setup_cnf_size(a1, v25, (int *)&v146);
  if ( (packed_tdls_setup_cnf_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a Setup Confirm (0x%08x)",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "lim_send_tdls_link_setup_cnf_frame",
      packed_tdls_setup_cnf_size);
    v146 = 1160;
  }
  else if ( packed_tdls_setup_cnf_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating the packed size for Setup Confirm (0x%08x)",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "lim_send_tdls_link_setup_cnf_frame");
  }
  v139 = a6;
  if ( (*v34 & 1) != 0 && (*(_WORD *)(a5 + 176) & 0x200) != 0 )
  {
    v59 = 26;
  }
  else
  {
    v59 = 24;
    if ( (*v34 & 2) != 0 )
    {
      if ( (*(_BYTE *)(a5 + 178) & 2) != 0 )
        v59 = 26;
      else
        v59 = 24;
    }
  }
  v60 = a7;
  v61 = 45 - v146;
  v62 = v146 - 45;
  v63 = v38;
  if ( 45 - v146 <= 5 )
    v64 = 5;
  else
    v64 = 45 - v146;
  v65 = a7 + (unsigned __int16)v38 + v146 + v59;
  if ( v62 >= 0xFFFFFFD2 )
    v66 = v64;
  else
    v66 = 0;
  v67 = a7;
  v68 = v65 + (unsigned __int8)v143[0] + v66;
  if ( (unsigned int)cds_packet_alloc(
                       (unsigned __int16)v65 + (unsigned __int8)v143[0] + (unsigned __int16)v66 + 9,
                       &v145,
                       &v144) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to allocate %d bytes for a TDLS Setup Confirm",
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      "lim_send_tdls_link_setup_cnf_frame",
      v68 + 9);
LABEL_69:
    _qdf_mem_free((__int64)v142);
    goto LABEL_70;
  }
  v137 = v63;
  v138 = v67;
  qdf_mem_set(v145, v68 + 9, 0);
  if ( v141 == 1 )
    v77 = 4;
  else
    v77 = 1;
  v78 = (unsigned int)lim_prepare_tdls_frame_header(a1, v145, v25 + 458, 0, 0, v77, a5);
  v79 = dot11f_pack_tdls_setup_cnf(a1, v25, &v145[v78], v146, &v146);
  if ( (v79 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to pack a TDLS discovery req (0x%08x)",
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      "lim_send_tdls_link_setup_cnf_frame",
      v79);
    cds_packet_free((__int64)v144);
    goto LABEL_69;
  }
  if ( v79 )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while packing TDLS Discovery Request (0x%08x)",
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      "lim_send_tdls_link_setup_cnf_frame");
  lim_cp_stats_cstats_log_setup_confirm_evt((__int16 *)v25, a5);
  _qdf_mem_free(v25);
  v96 = v137;
  if ( v138 )
  {
    qdf_mem_copy(&v145[v146 + v78], v139, v60);
    v146 += v60;
  }
  if ( v143[0] )
  {
    qdf_mem_copy(&v145[v146 + v78], v142, (unsigned __int8)v143[0]);
    _qdf_mem_free((__int64)v142);
    v146 += (unsigned __int8)v143[0];
  }
  if ( (_WORD)v137 )
  {
    if ( (unsigned int)lim_fill_complete_mlo_ie(a5, v137, &v145[v146 + v78]) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: assemble ml ie error",
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        "lim_send_tdls_link_setup_cnf_frame");
      v96 = 0;
    }
    v146 += v96;
  }
  v97 = __CFADD__(v62, 46);
  v98 = (unsigned __int8 *)(a5 + 10);
  if ( v97 )
  {
    v99 = &v145[v146 + v138 + v78];
    *v99 = -35;
    v99[1] = v64 - 2;
    *((_WORD *)v99 + 1) = -24576;
    v99[4] = -58;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Padding Vendor Specific Ie Len: %d",
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      "lim_send_tdls_link_setup_cnf_frame",
      v64);
    if ( v61 >= 6 )
      qdf_mem_set(&v145[v146 + 5 + v138 + v78], v64 - 5, 0);
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: [TDLS] action: %d (%s) -AP-> OTA peer=%02x:%02x:%02x:**:**:%02x",
    v88,
    v89,
    v90,
    v91,
    v92,
    v93,
    v94,
    v95,
    "lim_send_tdls_link_setup_cnf_frame",
    2,
    "TDLS_SETUP_CONFIRM",
    (unsigned __int8)v140,
    BYTE1(v140),
    BYTE2(v140),
    BYTE5(v140));
  *(_DWORD *)(a1 + 12368) = *(unsigned __int8 *)(a5 + 10);
  if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a5 + 16), v100, v101, v102, v103, v104, v105, v106, v107) & 1) != 0 )
  {
    assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(*(_QWORD *)(a5 + 16));
    if ( assoc_link_vdev )
      v98 = (unsigned __int8 *)(assoc_link_vdev + 168);
  }
  v117 = *v98;
  lim_diag_mgmt_tx_event_report(a1, (unsigned __int8 *)v145, a5, 0, 0, v108, v109, v110, v111, v112, v113, v114, v115);
  v118 = v144;
  v119 = v145;
  context = _cds_get_context(
              54,
              (__int64)"wma_tx_frame_with_tx_complete_send",
              v120,
              v121,
              v122,
              v123,
              v124,
              v125,
              v126,
              v127);
  result = wma_tx_packet(
             (__int64)context,
             v118,
             (unsigned __int16)v68 + 9,
             5u,
             v129,
             v130,
             v131,
             v132,
             v133,
             v134,
             v135,
             v136,
             1,
             4,
             lim_tx_complete,
             v119,
             (__int64)lim_mgmt_tdls_tx_complete,
             192,
             v117,
             0,
             0,
             0xCu,
             0,
             0);
  if ( (_DWORD)result )
  {
    v39 = "%s: could not send TDLS Setup Confirm frame";
    *(_DWORD *)(a1 + 12368) = 255;
    goto LABEL_17;
  }
LABEL_71:
  _ReadStatusReg(SP_EL0);
  return result;
}
