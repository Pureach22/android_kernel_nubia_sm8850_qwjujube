__int64 __fastcall lim_send_tdls_teardown_frame(
        __int64 a1,
        __int64 a2,
        unsigned __int16 a3,
        char a4,
        __int64 a5,
        const void *a6,
        unsigned __int16 a7,
        int a8)
{
  char *v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  bool v25; // zf
  __int64 v26; // x25
  char *v27; // x8
  char *v28; // x9
  void *v29; // x0
  void *v30; // x23
  void *v31; // x24
  unsigned int packed_tdls_teardown_size; // w0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  const char *v41; // x2
  __int64 result; // x0
  unsigned __int16 *v43; // x0
  int v44; // w10
  unsigned int v45; // w23
  int v46; // w9
  int v47; // w10
  unsigned int v48; // w26
  int v49; // w21
  unsigned int v50; // w22
  unsigned int v51; // w28
  unsigned int v52; // w19
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x5
  __int64 v70; // x24
  unsigned int v71; // w0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  char *v88; // x8
  const char *v89; // x7
  unsigned __int8 *v90; // x1
  unsigned __int8 v91; // w23
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  _QWORD *v100; // x20
  char *v101; // x22
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  _QWORD *context; // x0
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  unsigned int v119; // [xsp+54h] [xbp-6Ch]
  const void *v120; // [xsp+58h] [xbp-68h]
  unsigned __int16 v121; // [xsp+64h] [xbp-5Ch]
  unsigned __int16 v122; // [xsp+68h] [xbp-58h]
  _BOOL4 v123; // [xsp+70h] [xbp-50h]
  _BOOL4 v124; // [xsp+74h] [xbp-4Ch]
  __int64 v125; // [xsp+78h] [xbp-48h]
  __int64 v126; // [xsp+80h] [xbp-40h]
  __int16 v127; // [xsp+8Ch] [xbp-34h] BYREF
  _QWORD *v128; // [xsp+90h] [xbp-30h] BYREF
  char *v129; // [xsp+98h] [xbp-28h] BYREF
  unsigned int v130; // [xsp+A4h] [xbp-1Ch] BYREF
  int v131; // [xsp+A8h] [xbp-18h] BYREF
  __int16 v132; // [xsp+ACh] [xbp-14h]
  __int64 v133; // [xsp+B0h] [xbp-10h]

  v133 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v130 = 0;
  v128 = nullptr;
  v129 = nullptr;
  v127 = 0;
  v16 = (char *)_qdf_mem_malloc(0xF4u, "lim_send_tdls_teardown_frame", 2355);
  if ( !v16 )
  {
    v41 = "%s: memory allocation failed for teardown";
LABEL_12:
    result = qdf_trace_msg(0x35u, 2u, v41, v17, v18, v19, v20, v21, v22, v23, v24, "lim_send_tdls_teardown_frame");
    goto LABEL_56;
  }
  v25 = a4 == 1;
  v26 = (__int64)v16;
  *((_WORD *)v16 + 1) = a3;
  *(_WORD *)v16 = 780;
  v27 = v16 + 231;
  v124 = v25;
  v28 = v16 + 237;
  v29 = v16 + 225;
  v120 = a6;
  v132 = WORD2(a2);
  if ( a4 == 1 )
    v30 = v28;
  else
    v30 = v27;
  if ( v25 )
    v31 = v27;
  else
    v31 = v28;
  v131 = a2;
  qdf_mem_copy(v29, (const void *)(a5 + 24), 6u);
  qdf_mem_copy(v30, (const void *)(a5 + 30), 6u);
  qdf_mem_copy(v31, &v131, 6u);
  *(_BYTE *)(v26 + 224) = 1;
  packed_tdls_teardown_size = dot11f_get_packed_tdls_teardown_size(a1, v26, (int *)&v130);
  if ( (packed_tdls_teardown_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a discovery Request (0x%08x)",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "lim_send_tdls_teardown_frame",
      packed_tdls_teardown_size);
    v130 = 1160;
  }
  else if ( packed_tdls_teardown_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating the packed size for a discovery Request (0x%08x)",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "lim_send_tdls_teardown_frame");
  }
  v43 = (unsigned __int16 *)dph_lookup_hash_entry(
                              v33,
                              v34,
                              v35,
                              v36,
                              v37,
                              v38,
                              v39,
                              v40,
                              a1,
                              (unsigned __int8 *)(a5 + 24),
                              &v127,
                              a5 + 360);
  if ( v43 )
    v44 = (*v43 >> 1) & 1;
  else
    LOBYTE(v44) = 0;
  v45 = a3;
  v122 = a7;
  v46 = a7 + v130 + 9;
  v119 = a7;
  v125 = a2;
  v126 = a1;
  v121 = a3;
  v123 = a3 != 25;
  if ( (*(_BYTE *)(a5 + 7024) & 1) != 0 && (*(_WORD *)(a5 + 176) & 0x200) != 0 )
  {
    if ( a3 == 25 )
      LOBYTE(v44) = 1;
    if ( (v44 & 1) == 0 )
      goto LABEL_21;
  }
  else if ( (*(_BYTE *)(a5 + 7024) & 2) != 0 )
  {
    if ( a3 == 25 )
      LOBYTE(v44) = (*(_BYTE *)(a5 + 178) & 2) != 0;
    if ( (v44 & 1) == 0 )
      goto LABEL_21;
  }
  else if ( ((a3 != 25) & (unsigned __int8)v44) == 0 )
  {
LABEL_21:
    v47 = 24;
    goto LABEL_26;
  }
  v47 = 26;
LABEL_26:
  v48 = v130 - 45;
  v49 = v46 + v47;
  v50 = 45 - v130;
  if ( 45 - v130 <= 5 )
    v51 = 5;
  else
    v51 = 45 - v130;
  if ( v48 >= 0xFFFFFFD2 )
    v52 = v51;
  else
    v52 = 0;
  if ( (unsigned int)cds_packet_alloc((unsigned __int16)v49 + (unsigned __int16)v52, &v129, &v128) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to allocate %d bytes for a TDLS Teardown Frame.",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "lim_send_tdls_teardown_frame",
      v49 + v52);
LABEL_55:
    result = _qdf_mem_free(v26);
    goto LABEL_56;
  }
  qdf_mem_set(v129, v49 + v52, 0);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Reason of TDLS Teardown: %d",
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    "lim_send_tdls_teardown_frame",
    v45);
  if ( a8 == 1 )
    v69 = 4;
  else
    v69 = 1;
  v70 = (unsigned int)lim_prepare_tdls_frame_header(v126, v129, v26 + 224, v123, v124, v69, a5);
  v71 = dot11f_pack_tdls_teardown(v126, v26, &v129[v70], v130, &v130);
  if ( (v71 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to pack a TDLS Teardown frame (0x%08x)",
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      "lim_send_tdls_teardown_frame",
      v71);
    cds_packet_free((__int64)v128);
    goto LABEL_55;
  }
  if ( v71 )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while packing TDLS Teardown frame (0x%08x)",
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      "lim_send_tdls_teardown_frame");
  lim_cp_stats_cstats_log_tear_down_evt((int *)v26, a5);
  _qdf_mem_free(v26);
  if ( v122 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Copy Additional Ie Len = %d",
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      "lim_send_tdls_teardown_frame",
      v119);
    qdf_mem_copy(&v129[v130 + v70], v120, v119);
  }
  if ( v48 >= 0xFFFFFFD2 )
  {
    v88 = &v129[v130 + v122 + v70];
    *v88 = -35;
    v88[1] = v51 - 2;
    *((_WORD *)v88 + 1) = -24576;
    v88[4] = -58;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Padding Vendor Specific Ie Len = %d",
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      "lim_send_tdls_teardown_frame",
      v51);
    if ( v50 >= 6 )
      qdf_mem_set(&v129[v130 + 5 + v122 + v70], v51 - 5, 0);
  }
  if ( v121 == 25 )
    v89 = "AP";
  else
    v89 = "DIRECT";
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: [TDLS] vdev:%d action: %d (%s) -%s-> OTA peer=%02x:%02x:%02x:**:**:%02x",
    v80,
    v81,
    v82,
    v83,
    v84,
    v85,
    v86,
    v87,
    "lim_send_tdls_teardown_frame",
    *(unsigned __int8 *)(a5 + 10),
    3,
    "TDLS_TEARDOWN",
    v89,
    (unsigned __int8)v125,
    BYTE1(v125),
    BYTE2(v125),
    BYTE5(v125));
  v90 = (unsigned __int8 *)v129;
  *(_DWORD *)(v126 + 12368) = *(unsigned __int8 *)(a5 + 10);
  v91 = *(_BYTE *)(a5 + 10);
  lim_diag_mgmt_tx_event_report(v126, v90, a5, 0, 0, v92, v93, v94, v95, v96, v97, v98, v99);
  v100 = v128;
  v101 = v129;
  context = _cds_get_context(
              54,
              (__int64)"wma_tx_frame_with_tx_complete_send",
              v102,
              v103,
              v104,
              v105,
              v106,
              v107,
              v108,
              v109);
  result = wma_tx_packet(
             (__int64)context,
             v100,
             (unsigned __int16)v49 + (unsigned __int16)v52,
             5u,
             v111,
             v112,
             v113,
             v114,
             v115,
             v116,
             v117,
             v118,
             1,
             4,
             lim_tx_complete,
             v101,
             (__int64)lim_mgmt_tdls_tx_complete,
             192,
             v91,
             0,
             0,
             0xCu,
             0);
  if ( (_DWORD)result )
  {
    v41 = "%s: could not send TDLS Teardown frame";
    *(_DWORD *)(v126 + 12368) = 255;
    goto LABEL_12;
  }
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return result;
}
