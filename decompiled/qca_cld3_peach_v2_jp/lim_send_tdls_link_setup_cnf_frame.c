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
  _BYTE *v34; // x24
  __int64 v35; // x10
  char v36; // w8
  __int16 v37; // w8
  unsigned int packed_tdls_setup_cnf_size; // w0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  const char *v47; // x2
  __int64 result; // x0
  int v49; // w9
  unsigned int v50; // w27
  unsigned int v51; // w25
  unsigned int v52; // w24
  unsigned int v53; // w26
  unsigned int v54; // w10
  unsigned int v55; // w21
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x5
  __int64 v65; // x22
  unsigned int v66; // w0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  char *v83; // x8
  unsigned __int8 *v84; // x1
  unsigned __int8 v85; // w23
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  _QWORD *v94; // x20
  char *v95; // x22
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  _QWORD *context; // x0
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  unsigned __int16 v113; // [xsp+50h] [xbp-40h]
  const void *v114; // [xsp+58h] [xbp-38h]
  __int64 v115; // [xsp+60h] [xbp-30h]
  _QWORD *v116; // [xsp+68h] [xbp-28h] BYREF
  char *v117; // [xsp+70h] [xbp-20h] BYREF
  unsigned int v118; // [xsp+7Ch] [xbp-14h] BYREF
  int v119; // [xsp+80h] [xbp-10h] BYREF
  __int16 v120; // [xsp+84h] [xbp-Ch]
  __int64 v121; // [xsp+88h] [xbp-8h]

  v121 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v118 = 0;
  v116 = nullptr;
  v117 = nullptr;
  v16 = _qdf_mem_malloc(0x20Cu, "lim_send_tdls_link_setup_cnf_frame", 2882);
  if ( !v16 )
  {
    v47 = "%s: memory allocation failed for SetupCnf";
LABEL_18:
    result = qdf_trace_msg(0x35u, 2u, v47, v17, v18, v19, v20, v21, v22, v23, v24, "lim_send_tdls_link_setup_cnf_frame");
    goto LABEL_53;
  }
  v25 = v16;
  *(_WORD *)v16 = 524;
  *(_BYTE *)(v16 + 4) = a3;
  v120 = WORD2(a2);
  v119 = a2;
  qdf_mem_copy((void *)(v16 + 459), (const void *)(a5 + 24), 6u);
  qdf_mem_copy((void *)(v25 + 465), (const void *)(a5 + 30), 6u);
  qdf_mem_copy((void *)(v25 + 471), &v119, 6u);
  *(_BYTE *)(v25 + 458) = 1;
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
LABEL_20:
    populate_dot11f_ht_info(a1, v25 + 400, a5, v26, v27, v28, v29, v30, v31, v32, v33);
    if ( (a4 & 8) == 0 )
      goto LABEL_14;
    goto LABEL_8;
  }
  if ( (a4 & 1) != 0 )
    goto LABEL_20;
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
  *(_WORD *)(v25 + 512) = v37 | *(_WORD *)(v35 + 1460);
  populate_dot11f_he_operation(a1, a5, (_BYTE *)(v25 + 506));
LABEL_14:
  packed_tdls_setup_cnf_size = dot11f_get_packed_tdls_setup_cnf_size(a1, v25, (int *)&v118);
  if ( (packed_tdls_setup_cnf_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a Setup Confirm (0x%08x)",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "lim_send_tdls_link_setup_cnf_frame",
      packed_tdls_setup_cnf_size);
    v118 = 1160;
  }
  else if ( packed_tdls_setup_cnf_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating the packed size for Setup Confirm (0x%08x)",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "lim_send_tdls_link_setup_cnf_frame");
  }
  v114 = a6;
  v115 = a2;
  if ( (*v34 & 1) != 0 && (*(_WORD *)(a5 + 176) & 0x200) != 0 )
  {
    v49 = 26;
  }
  else
  {
    v49 = 24;
    if ( (*v34 & 2) != 0 )
    {
      if ( (*(_BYTE *)(a5 + 178) & 2) != 0 )
        v49 = 26;
      else
        v49 = 24;
    }
  }
  v50 = a7;
  v51 = v118 - 45;
  v52 = 45 - v118;
  if ( 45 - v118 <= 5 )
    v53 = 5;
  else
    v53 = 45 - v118;
  if ( v51 >= 0xFFFFFFD2 )
    v54 = v53;
  else
    v54 = 0;
  v55 = a7 + v118 + v49 + v54;
  if ( (unsigned int)cds_packet_alloc(a7 + (unsigned __int16)v118 + v49 + (unsigned __int16)v54 + 9, &v117, &v116) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to allocate %d bytes for a TDLS Setup Confirm",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      "lim_send_tdls_link_setup_cnf_frame",
      v55 + 9);
LABEL_52:
    _qdf_mem_free(0);
    result = _qdf_mem_free(v25);
    goto LABEL_53;
  }
  v113 = a7;
  qdf_mem_set(v117, v55 + 9, 0);
  if ( a8 == 1 )
    v64 = 4;
  else
    v64 = 1;
  v65 = (unsigned int)lim_prepare_tdls_frame_header(a1, v117, v25 + 458, 0, 0, v64, a5);
  v66 = dot11f_pack_tdls_setup_cnf(a1, v25, &v117[v65], v118, &v118);
  if ( (v66 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to pack a TDLS discovery req (0x%08x)",
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      "lim_send_tdls_link_setup_cnf_frame",
      v66);
    cds_packet_free((__int64)v116);
    goto LABEL_52;
  }
  if ( v66 )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while packing TDLS Discovery Request (0x%08x)",
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      "lim_send_tdls_link_setup_cnf_frame");
  lim_cp_stats_cstats_log_setup_confirm_evt((__int16 *)v25, a5);
  _qdf_mem_free(v25);
  if ( v113 )
  {
    qdf_mem_copy(&v117[v118 + v65], v114, v50);
    v118 += v50;
  }
  if ( v51 >= 0xFFFFFFD2 )
  {
    v83 = &v117[v118 + v113 + v65];
    *v83 = -35;
    v83[1] = v53 - 2;
    *((_WORD *)v83 + 1) = -24576;
    v83[4] = -58;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Padding Vendor Specific Ie Len: %d",
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      "lim_send_tdls_link_setup_cnf_frame",
      v53);
    if ( v52 >= 6 )
      qdf_mem_set(&v117[v118 + 5 + v113 + v65], v53 - 5, 0);
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: [TDLS] action: %d (%s) -AP-> OTA peer=%02x:%02x:%02x:**:**:%02x",
    v75,
    v76,
    v77,
    v78,
    v79,
    v80,
    v81,
    v82,
    "lim_send_tdls_link_setup_cnf_frame",
    2,
    "TDLS_SETUP_CONFIRM",
    (unsigned __int8)v115,
    BYTE1(v115),
    BYTE2(v115),
    BYTE5(v115));
  v84 = (unsigned __int8 *)v117;
  *(_DWORD *)(a1 + 12368) = *(unsigned __int8 *)(a5 + 10);
  v85 = *(_BYTE *)(a5 + 10);
  lim_diag_mgmt_tx_event_report(a1, v84, a5, 0, 0, v86, v87, v88, v89, v90, v91, v92, v93);
  v94 = v116;
  v95 = v117;
  context = _cds_get_context(
              54,
              (__int64)"wma_tx_frame_with_tx_complete_send",
              v96,
              v97,
              v98,
              v99,
              v100,
              v101,
              v102,
              v103);
  result = wma_tx_packet(
             (__int64)context,
             v94,
             (unsigned __int16)v55 + 9,
             5u,
             v105,
             v106,
             v107,
             v108,
             v109,
             v110,
             v111,
             v112,
             1,
             4,
             lim_tx_complete,
             v95,
             (__int64)lim_mgmt_tdls_tx_complete,
             192,
             v85,
             0,
             0,
             0xCu,
             0);
  if ( (_DWORD)result )
  {
    v47 = "%s: could not send TDLS Setup Confirm frame";
    *(_DWORD *)(a1 + 12368) = 255;
    goto LABEL_18;
  }
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return result;
}
