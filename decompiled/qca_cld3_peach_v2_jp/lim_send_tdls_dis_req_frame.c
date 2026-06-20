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
  unsigned int packed_tdls_dis_req_size; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2
  __int64 result; // x0
  int v31; // w9
  unsigned int v32; // w28
  unsigned int v33; // w27
  unsigned int v34; // w8
  unsigned int v35; // w24
  unsigned int v36; // w10
  unsigned int v37; // w26
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x5
  __int64 v47; // x25
  unsigned int v48; // w0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  char *v65; // x8
  unsigned __int8 *v66; // x1
  unsigned __int8 v67; // w21
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  _QWORD *context; // x0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  _QWORD *v93; // [xsp+58h] [xbp-28h] BYREF
  char *v94; // [xsp+60h] [xbp-20h] BYREF
  unsigned int v95; // [xsp+6Ch] [xbp-14h] BYREF
  int v96; // [xsp+70h] [xbp-10h] BYREF
  __int16 v97; // [xsp+74h] [xbp-Ch]
  __int64 v98; // [xsp+78h] [xbp-8h]

  v98 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v95 = 0;
  v93 = nullptr;
  v94 = nullptr;
  v10 = _qdf_mem_malloc(0x16u, "lim_send_tdls_dis_req_frame", 676);
  if ( !v10 )
  {
    v29 = "%s: memory allocation failed for DisReq";
LABEL_6:
    result = qdf_trace_msg(0x35u, 2u, v29, v11, v12, v13, v14, v15, v16, v17, v18, "lim_send_tdls_dis_req_frame");
    goto LABEL_36;
  }
  v19 = (char *)v10;
  *(_BYTE *)(v10 + 2) = a3;
  *(_WORD *)v10 = 2572;
  v97 = WORD2(a2);
  v96 = a2;
  qdf_mem_copy((void *)(v10 + 4), (const void *)(a4 + 24), 6u);
  qdf_mem_copy(v19 + 10, (const void *)(a4 + 30), 6u);
  qdf_mem_copy(v19 + 16, &v96, 6u);
  v19[3] = 1;
  packed_tdls_dis_req_size = dot11f_get_packed_tdls_dis_req_size(a1, (__int64)v19, (int *)&v95);
  if ( (packed_tdls_dis_req_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a discovery Request (0x%08x)",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "lim_send_tdls_dis_req_frame",
      packed_tdls_dis_req_size);
    v95 = 22;
  }
  else if ( packed_tdls_dis_req_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating the packed size for a discovery Request (0x%08x)",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "lim_send_tdls_dis_req_frame");
  }
  if ( (*(_BYTE *)(a4 + 7024) & 1) != 0 && (*(_WORD *)(a4 + 176) & 0x200) != 0 )
  {
    v31 = 26;
  }
  else
  {
    v31 = 24;
    if ( (*(_BYTE *)(a4 + 7024) & 2) != 0 )
    {
      if ( (*(_BYTE *)(a4 + 178) & 2) != 0 )
        v31 = 26;
      else
        v31 = 24;
    }
  }
  v32 = v95 - 45;
  v33 = 45 - v95;
  v34 = v95 + v31;
  if ( 45 - v95 <= 5 )
    v35 = 5;
  else
    v35 = 45 - v95;
  if ( v32 >= 0xFFFFFFD2 )
    v36 = v35;
  else
    v36 = 0;
  v37 = v34 + v36;
  if ( (unsigned int)cds_packet_alloc((unsigned __int16)v34 + (unsigned __int16)v36 + 9, &v94, &v93) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to allocate: %d bytes for a TDLS Discovery Request",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "lim_send_tdls_dis_req_frame",
      v37 + 9);
LABEL_35:
    result = _qdf_mem_free((__int64)v19);
    goto LABEL_36;
  }
  qdf_mem_set(v94, v37 + 9, 0);
  if ( a5 == 1 )
    v46 = 4;
  else
    v46 = 1;
  v47 = (unsigned int)lim_prepare_tdls_frame_header(a1, v94, v19 + 3, 0, 0, v46, a4);
  v48 = dot11f_pack_tdls_dis_req(a1, (__int64)v19, &v94[v47], v95, &v95);
  if ( (v48 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to pack a TDLS discovery req (0x%08x)",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "lim_send_tdls_dis_req_frame",
      v48);
    cds_packet_free((__int64)v93);
    goto LABEL_35;
  }
  if ( v48 )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while packing TDLS Discovery Request (0x%08x)",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "lim_send_tdls_dis_req_frame");
  lim_cp_stats_cstats_log_disc_req_evt(v19, a4);
  _qdf_mem_free((__int64)v19);
  if ( v32 >= 0xFFFFFFD2 )
  {
    v65 = &v94[v95 + v47];
    *v65 = -35;
    v65[1] = v35 - 2;
    *((_WORD *)v65 + 1) = -24576;
    v65[4] = -58;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Padding Vendor Specific Ie Len: %d",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "lim_send_tdls_dis_req_frame",
      v35);
    if ( v33 >= 6 )
      qdf_mem_set(&v94[v95 + 5 + v47], v35 - 5, 0);
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: [TDLS] action: %d (%s) -AP-> OTA peer=%02x:%02x:%02x:**:**:%02x",
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    "lim_send_tdls_dis_req_frame",
    10,
    "TDLS_DISCOVERY_REQUEST",
    (unsigned __int8)a2,
    BYTE1(a2),
    BYTE2(a2),
    BYTE5(a2));
  v66 = (unsigned __int8 *)v94;
  *(_DWORD *)(a1 + 12368) = *(unsigned __int8 *)(a4 + 10);
  v67 = *(_BYTE *)(a4 + 10);
  lim_diag_mgmt_tx_event_report(a1, v66, a4, 0, 0, v68, v69, v70, v71, v72, v73, v74, v75);
  context = _cds_get_context(54, (__int64)"lim_send_tdls_dis_req_frame", v76, v77, v78, v79, v80, v81, v82, v83);
  result = wma_tx_packet(
             (__int64)context,
             v93,
             (unsigned __int16)v37 + 9,
             5u,
             v85,
             v86,
             v87,
             v88,
             v89,
             v90,
             v91,
             v92,
             1,
             4,
             lim_tx_complete,
             v94,
             (__int64)lim_mgmt_tdls_tx_complete,
             192,
             v67,
             0,
             0,
             0xCu,
             0);
  if ( (_DWORD)result )
  {
    v29 = "%s: could not send TDLS Discovery Request frame";
    *(_DWORD *)(a1 + 12368) = 255;
    goto LABEL_6;
  }
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
