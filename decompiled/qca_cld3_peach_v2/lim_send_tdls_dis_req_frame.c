__int64 __fastcall lim_send_tdls_dis_req_frame(__int64 a1, __int64 a2, char a3, __int64 a4, int a5)
{
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  char *v19; // x22
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w23
  unsigned int packed_tdls_dis_req_size; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  const char *v38; // x2
  __int64 result; // x0
  int v40; // w9
  unsigned int v41; // w28
  unsigned int v42; // w27
  unsigned int v43; // w24
  unsigned int v44; // w8
  unsigned int v45; // w10
  unsigned int v46; // w26
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x5
  __int64 v56; // x25
  unsigned int v57; // w0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned __int8 *v74; // x23
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  char *v83; // x8
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  __int64 assoc_link_vdev; // x0
  unsigned __int8 v101; // w21
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
  _QWORD *v119; // [xsp+50h] [xbp-20h] BYREF
  char *v120; // [xsp+58h] [xbp-18h] BYREF
  unsigned int v121; // [xsp+64h] [xbp-Ch] BYREF
  __int64 v122; // [xsp+68h] [xbp-8h]

  v122 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v121 = 0;
  v119 = nullptr;
  v120 = nullptr;
  v10 = _qdf_mem_malloc(0x16u, "lim_send_tdls_dis_req_frame", 676);
  if ( !v10 )
  {
    v38 = "%s: memory allocation failed for DisReq";
LABEL_8:
    result = qdf_trace_msg(0x35u, 2u, v38, v11, v12, v13, v14, v15, v16, v17, v18, "lim_send_tdls_dis_req_frame");
    goto LABEL_45;
  }
  v19 = (char *)v10;
  *(_BYTE *)(v10 + 2) = a3;
  *(_WORD *)v10 = 2572;
  v20 = populate_dot11f_link_iden(a4, v10 + 3, a2 & 0xFFFFFFFFFFFFLL, 0);
  v28 = 0;
  if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a4 + 16), v20, v21, v22, v23, v24, v25, v26, v27) & 1) != 0 )
    v28 = lim_send_tdls_mgmt_frame_mlo(a1, a4);
  packed_tdls_dis_req_size = dot11f_get_packed_tdls_dis_req_size(a1, (__int64)v19, (int *)&v121);
  if ( (packed_tdls_dis_req_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a discovery Request (0x%08x)",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "lim_send_tdls_dis_req_frame",
      packed_tdls_dis_req_size);
    v121 = 22;
  }
  else if ( packed_tdls_dis_req_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating the packed size for a discovery Request (0x%08x)",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "lim_send_tdls_dis_req_frame");
  }
  if ( (*(_BYTE *)(a4 + 7024) & 1) != 0 && (*(_WORD *)(a4 + 176) & 0x200) != 0 )
  {
    v40 = 26;
  }
  else
  {
    v40 = 24;
    if ( (*(_BYTE *)(a4 + 7024) & 2) != 0 )
    {
      if ( (*(_BYTE *)(a4 + 178) & 2) != 0 )
        v40 = 26;
      else
        v40 = 24;
    }
  }
  v41 = v121 - 45;
  v42 = 45 - v121;
  if ( 45 - v121 <= 5 )
    v43 = 5;
  else
    v43 = 45 - v121;
  v44 = v121 + (unsigned __int16)v28 + v40;
  if ( v41 >= 0xFFFFFFD2 )
    v45 = v43;
  else
    v45 = 0;
  v46 = v44 + v45;
  if ( (unsigned int)cds_packet_alloc((unsigned __int16)v44 + (unsigned __int16)v45 + 9, &v120, &v119) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to allocate: %d bytes for a TDLS Discovery Request",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "lim_send_tdls_dis_req_frame",
      v46 + 9);
LABEL_44:
    result = _qdf_mem_free((__int64)v19);
    goto LABEL_45;
  }
  qdf_mem_set(v120, v46 + 9, 0);
  if ( a5 == 1 )
    v55 = 4;
  else
    v55 = 1;
  v56 = (unsigned int)lim_prepare_tdls_frame_header(a1, v120, v19 + 3, 0, 0, v55, a4);
  v57 = dot11f_pack_tdls_dis_req(a1, (__int64)v19, &v120[v56], v121, &v121);
  if ( (v57 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to pack a TDLS discovery req (0x%08x)",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      "lim_send_tdls_dis_req_frame",
      v57);
    cds_packet_free((__int64)v119);
    goto LABEL_44;
  }
  if ( v57 )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while packing TDLS Discovery Request (0x%08x)",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      "lim_send_tdls_dis_req_frame");
  if ( (_WORD)v28 )
  {
    if ( (unsigned int)lim_fill_complete_mlo_ie(a4, v28, &v120[v121 + v56]) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: assemble ml ie error",
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        "lim_send_tdls_dis_req_frame");
      LOWORD(v28) = 0;
    }
    v121 += (unsigned __int16)v28;
  }
  v74 = (unsigned __int8 *)(a4 + 10);
  lim_cp_stats_cstats_log_disc_req_evt(v19, a4);
  _qdf_mem_free((__int64)v19);
  if ( v41 >= 0xFFFFFFD2 )
  {
    v83 = &v120[v121 + v56];
    *v83 = -35;
    v83[1] = v43 - 2;
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
      "lim_send_tdls_dis_req_frame",
      v43);
    if ( v42 >= 6 )
      qdf_mem_set(&v120[v121 + 5 + v56], v43 - 5, 0);
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
    "lim_send_tdls_dis_req_frame",
    10,
    "TDLS_DISCOVERY_REQUEST",
    (unsigned __int8)a2,
    BYTE1(a2),
    BYTE2(a2),
    BYTE5(a2));
  *(_DWORD *)(a1 + 12368) = *(unsigned __int8 *)(a4 + 10);
  if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a4 + 16), v84, v85, v86, v87, v88, v89, v90, v91) & 1) != 0 )
  {
    assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(*(_QWORD *)(a4 + 16));
    if ( assoc_link_vdev )
      v74 = (unsigned __int8 *)(assoc_link_vdev + 168);
  }
  v101 = *v74;
  lim_diag_mgmt_tx_event_report(a1, (unsigned __int8 *)v120, a4, 0, 0, v92, v93, v94, v95, v96, v97, v98, v99);
  context = _cds_get_context(54, (__int64)"lim_send_tdls_dis_req_frame", v102, v103, v104, v105, v106, v107, v108, v109);
  result = wma_tx_packet(
             (__int64)context,
             v119,
             (unsigned __int16)v46 + 9,
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
             v120,
             (__int64)lim_mgmt_tdls_tx_complete,
             192,
             v101,
             0,
             0,
             0xCu,
             0,
             0);
  if ( (_DWORD)result )
  {
    v38 = "%s: could not send TDLS Discovery Request frame";
    *(_DWORD *)(a1 + 12368) = 255;
    goto LABEL_8;
  }
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
