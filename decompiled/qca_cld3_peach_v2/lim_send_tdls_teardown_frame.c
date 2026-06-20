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
  int *v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int *v25; // x25
  unsigned int packed_tdls_teardown_size; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v35; // x2
  __int64 result; // x0
  unsigned __int16 *v37; // x0
  int v38; // w10
  unsigned int v39; // w23
  _BOOL4 v40; // w26
  int v41; // w22
  int v42; // w10
  unsigned int v43; // w19
  unsigned int v44; // w28
  unsigned int v45; // w21
  unsigned int v46; // w24
  unsigned int v47; // w27
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x5
  __int64 v65; // x28
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
  bool v83; // cf
  unsigned __int8 *v84; // x19
  char *v85; // x8
  const char *v86; // x7
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  __int64 assoc_link_vdev; // x0
  unsigned __int8 v104; // w19
  _QWORD *v105; // x20
  char *v106; // x22
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  _QWORD *context; // x0
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  __int16 v124; // [xsp+40h] [xbp-60h]
  unsigned int v125; // [xsp+44h] [xbp-5Ch]
  const void *v126; // [xsp+48h] [xbp-58h]
  unsigned __int16 v127; // [xsp+54h] [xbp-4Ch]
  unsigned __int16 v128; // [xsp+58h] [xbp-48h]
  _BOOL4 v129; // [xsp+64h] [xbp-3Ch]
  __int64 v130; // [xsp+68h] [xbp-38h]
  __int64 v131; // [xsp+70h] [xbp-30h]
  __int16 v132; // [xsp+7Ch] [xbp-24h] BYREF
  _QWORD *v133; // [xsp+80h] [xbp-20h] BYREF
  char *v134; // [xsp+88h] [xbp-18h] BYREF
  unsigned int v135; // [xsp+94h] [xbp-Ch] BYREF
  __int64 v136; // [xsp+98h] [xbp-8h]

  v136 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v135 = 0;
  v133 = nullptr;
  v134 = nullptr;
  v132 = 0;
  v16 = (int *)_qdf_mem_malloc(0xF4u, "lim_send_tdls_teardown_frame", 2355);
  if ( !v16 )
  {
    v35 = "%s: memory allocation failed for teardown";
LABEL_6:
    result = qdf_trace_msg(0x35u, 2u, v35, v17, v18, v19, v20, v21, v22, v23, v24, "lim_send_tdls_teardown_frame");
    goto LABEL_54;
  }
  v25 = v16;
  *(_WORD *)v16 = 780;
  *((_WORD *)v16 + 1) = a3;
  v129 = a4 == 1;
  populate_dot11f_link_iden(a5, v16 + 56, a2 & 0xFFFFFFFFFFFFLL, a4 == 1);
  packed_tdls_teardown_size = dot11f_get_packed_tdls_teardown_size(a1, (__int64)v25, (int *)&v135);
  if ( (packed_tdls_teardown_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a discovery Request (0x%08x)",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "lim_send_tdls_teardown_frame",
      packed_tdls_teardown_size);
    v135 = 1160;
  }
  else if ( packed_tdls_teardown_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating the packed size for a discovery Request (0x%08x)",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "lim_send_tdls_teardown_frame");
  }
  v37 = (unsigned __int16 *)dph_lookup_hash_entry(
                              v27,
                              v28,
                              v29,
                              v30,
                              v31,
                              v32,
                              v33,
                              v34,
                              a1,
                              (unsigned __int8 *)(a5 + 24),
                              &v132,
                              a5 + 360);
  v126 = a6;
  if ( v37 )
    v38 = (*v37 >> 1) & 1;
  else
    LOBYTE(v38) = 0;
  v39 = a3;
  v40 = a3 != 25;
  v125 = a7;
  v130 = a2;
  v131 = a1;
  v128 = a7;
  v127 = a3;
  if ( (*(_BYTE *)(a5 + 7024) & 1) != 0 && (*(_WORD *)(a5 + 176) & 0x200) != 0 )
  {
    if ( a3 == 25 )
      LOBYTE(v38) = 1;
    if ( (v38 & 1) == 0 )
      goto LABEL_15;
  }
  else if ( (*(_BYTE *)(a5 + 7024) & 2) != 0 )
  {
    if ( a3 == 25 )
      LOBYTE(v38) = (*(_BYTE *)(a5 + 178) & 2) != 0;
    if ( (v38 & 1) == 0 )
      goto LABEL_15;
  }
  else if ( ((a3 != 25) & (unsigned __int8)v38) == 0 )
  {
LABEL_15:
    v41 = a8;
    v42 = 24;
    goto LABEL_20;
  }
  v41 = a8;
  v42 = 26;
LABEL_20:
  v43 = v135 - 45;
  v44 = a7 + v135 + 9 + v42;
  v45 = 45 - v135;
  if ( 45 - v135 <= 5 )
    v46 = 5;
  else
    v46 = 45 - v135;
  if ( v43 >= 0xFFFFFFD2 )
    v47 = v46;
  else
    v47 = 0;
  if ( (unsigned int)cds_packet_alloc((unsigned __int16)v44 + (unsigned __int16)v47, &v134, &v133) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to allocate %d bytes for a TDLS Teardown Frame.",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "lim_send_tdls_teardown_frame",
      v44 + v47);
LABEL_53:
    result = _qdf_mem_free((__int64)v25);
    goto LABEL_54;
  }
  v124 = v44;
  qdf_mem_set(v134, v44 + v47, 0);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Reason of TDLS Teardown: %d",
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    "lim_send_tdls_teardown_frame",
    v39);
  if ( v41 == 1 )
    v64 = 4;
  else
    v64 = 1;
  v65 = (unsigned int)lim_prepare_tdls_frame_header(v131, v134, v25 + 56, v40, v129, v64, a5);
  v66 = dot11f_pack_tdls_teardown(v131, (__int64)v25, &v134[v65], v135, &v135);
  if ( (v66 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to pack a TDLS Teardown frame (0x%08x)",
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      "lim_send_tdls_teardown_frame",
      v66);
    cds_packet_free((__int64)v133);
    goto LABEL_53;
  }
  if ( v66 )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while packing TDLS Teardown frame (0x%08x)",
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      "lim_send_tdls_teardown_frame");
  lim_cp_stats_cstats_log_tear_down_evt(v25, a5);
  _qdf_mem_free((__int64)v25);
  if ( v128 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Copy Additional Ie Len = %d",
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      "lim_send_tdls_teardown_frame",
      v125);
    qdf_mem_copy(&v134[v135 + v65], v126, v125);
  }
  v83 = __CFADD__(v43, 46);
  v84 = (unsigned __int8 *)(a5 + 10);
  if ( v83 )
  {
    v85 = &v134[v135 + v128 + v65];
    *v85 = -35;
    v85[1] = v46 - 2;
    *((_WORD *)v85 + 1) = -24576;
    v85[4] = -58;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Padding Vendor Specific Ie Len = %d",
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      "lim_send_tdls_teardown_frame",
      v46);
    if ( v45 >= 6 )
      qdf_mem_set(&v134[v135 + 5 + v128 + v65], v46 - 5, 0);
  }
  if ( v127 == 25 )
    v86 = "AP";
  else
    v86 = "DIRECT";
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: [TDLS] vdev:%d action: %d (%s) -%s-> OTA peer=%02x:%02x:%02x:**:**:%02x",
    v75,
    v76,
    v77,
    v78,
    v79,
    v80,
    v81,
    v82,
    "lim_send_tdls_teardown_frame",
    *(unsigned __int8 *)(a5 + 10),
    3,
    "TDLS_TEARDOWN",
    v86,
    (unsigned __int8)v130,
    BYTE1(v130),
    BYTE2(v130),
    BYTE5(v130));
  *(_DWORD *)(v131 + 12368) = *(unsigned __int8 *)(a5 + 10);
  if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a5 + 16), v87, v88, v89, v90, v91, v92, v93, v94) & 1) != 0 )
  {
    assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(*(_QWORD *)(a5 + 16));
    if ( assoc_link_vdev )
      v84 = (unsigned __int8 *)(assoc_link_vdev + 168);
  }
  v104 = *v84;
  lim_diag_mgmt_tx_event_report(v131, (unsigned __int8 *)v134, a5, 0, 0, v95, v96, v97, v98, v99, v100, v101, v102);
  v105 = v133;
  v106 = v134;
  context = _cds_get_context(
              54,
              (__int64)"wma_tx_frame_with_tx_complete_send",
              v107,
              v108,
              v109,
              v110,
              v111,
              v112,
              v113,
              v114);
  result = wma_tx_packet(
             (__int64)context,
             v105,
             v124 + (unsigned __int16)v47,
             5u,
             v116,
             v117,
             v118,
             v119,
             v120,
             v121,
             v122,
             v123,
             1,
             4,
             lim_tx_complete,
             v106,
             (__int64)lim_mgmt_tdls_tx_complete,
             192,
             v104,
             0,
             0,
             0xCu,
             0,
             0);
  if ( (_DWORD)result )
  {
    v35 = "%s: could not send TDLS Teardown frame";
    *(_DWORD *)(v131 + 12368) = 255;
    goto LABEL_6;
  }
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
