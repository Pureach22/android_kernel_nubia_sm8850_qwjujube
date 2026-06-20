__int64 __fastcall lim_send_delts_req_action_frame(
        __int64 result,
        const void *a2,
        unsigned __int8 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  char v6; // w24
  __int64 v10; // x20
  unsigned int packed_wmm_del_ts_size; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v21; // x2
  unsigned int packed_del_ts_size; // w0
  unsigned int v24; // w23
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x2
  __int64 v34; // x4
  int v35; // w25
  char *v36; // x22
  char *v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w9
  __int16 v47; // w9
  __int64 v48; // x5
  char *v49; // x22
  unsigned int v50; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x4
  const char *v60; // x2
  unsigned int v61; // w0
  __int64 v62; // x5
  __int64 v63; // x6
  __int64 v64; // x7
  int v65; // w8
  const char *v66; // x2
  char v67; // w21
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  _QWORD *context; // x0
  int v77; // w0
  __int16 v78; // w2
  unsigned int v79; // w19
  __int64 v80; // [xsp+40h] [xbp-70h] BYREF
  unsigned int v81; // [xsp+4Ch] [xbp-64h] BYREF
  __int64 v82; // [xsp+50h] [xbp-60h] BYREF
  int v83; // [xsp+58h] [xbp-58h]
  char *v84; // [xsp+60h] [xbp-50h] BYREF
  _QWORD v85[9]; // [xsp+68h] [xbp-48h] BYREF

  v85[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a6 )
    goto LABEL_38;
  v6 = *(_BYTE *)(a6 + 10);
  v10 = result;
  v84 = nullptr;
  memset(v85, 0, 64);
  v82 = 0;
  v83 = 0;
  v81 = 0;
  v80 = 0;
  if ( a3 )
  {
    qdf_mem_set(v85, 0x40u, 0);
    LODWORD(v85[0]) = 529;
    populate_dot11f_wmmtspec(a5, (char *)v85 + 4);
    packed_wmm_del_ts_size = dot11f_get_packed_wmm_del_ts_size(v10, v85, &v81);
    if ( (packed_wmm_del_ts_size & 0x10000000) == 0 )
    {
      if ( !packed_wmm_del_ts_size )
        goto LABEL_12;
      v21 = "%s: There were warnings while calculating the packed size for a WMM Del TS (0x%08x)";
LABEL_9:
      qdf_trace_msg(0x35u, 3u, v21, v13, v14, v15, v16, v17, v18, v19, v20, "lim_send_delts_req_action_frame");
      goto LABEL_12;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a WMM Del TS (0x%08x)",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "lim_send_delts_req_action_frame",
      packed_wmm_del_ts_size);
    v81 = 12;
  }
  else
  {
    qdf_mem_set(&v82, 0xCu, 0);
    LOWORD(v82) = 513;
    populate_dot11f_ts_info(a4, (char *)&v82 + 4);
    packed_del_ts_size = dot11f_get_packed_del_ts_size(v10, &v82, &v81);
    if ( (packed_del_ts_size & 0x10000000) == 0 )
    {
      if ( !packed_del_ts_size )
        goto LABEL_12;
      v21 = "%s: There were warnings while calculating the packed size for a Del TS (0x%08x)";
      goto LABEL_9;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a Del TS (0x%08x)",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "lim_send_delts_req_action_frame",
      packed_del_ts_size);
    v81 = 12;
  }
LABEL_12:
  v24 = v81;
  if ( (unsigned int)cds_packet_alloc((unsigned __int16)v81 + 24, &v84, &v80) )
  {
    v33 = "%s: Failed to allocate %d bytes for an Add TS Response";
    v34 = v24 + 24;
LABEL_14:
    result = qdf_trace_msg(
               0x35u,
               2u,
               v33,
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               "lim_send_delts_req_action_frame",
               v34);
    goto LABEL_38;
  }
  v35 = a3;
  qdf_mem_set(v84, v24 + 24, 0);
  v36 = v84;
  v37 = v84 + 4;
  *v84 = -48;
  qdf_mem_copy(v37, a2, 6u);
  v36[10] = *(_BYTE *)(a6 + 30);
  v36[11] = *(_BYTE *)(a6 + 31);
  v36[12] = *(_BYTE *)(a6 + 32);
  v36[13] = *(_BYTE *)(a6 + 33);
  v36[14] = *(_BYTE *)(a6 + 34);
  v36[15] = *(_BYTE *)(a6 + 35);
  qdf_mem_copy(v36 + 16, a2, 6u);
  v46 = *(unsigned __int16 *)(v10 + 21604);
  if ( v46 <= 0xFFE )
    v47 = v46 + 1;
  else
    v47 = 2048;
  *(_WORD *)(v10 + 21604) = v47;
  *((_WORD *)v36 + 11) = (16 * (v47 & 0xF)) | *((_WORD *)v36 + 11) & 0xFF0F;
  v48 = (unsigned __int8)(*(_WORD *)(v10 + 21604) >> 4);
  *((_WORD *)v36 + 11) = (16 * *(_WORD *)(v10 + 21604)) & 0xFF00 | (16 * (v47 & 0xF));
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    "lim_populate_mac_header",
    v47 & 0xF,
    v48,
    *(unsigned __int16 *)(v10 + 21604),
    0);
  v49 = v84;
  v84[16] = *(_BYTE *)(a6 + 24);
  v49[17] = *(_BYTE *)(a6 + 25);
  v49[18] = *(_BYTE *)(a6 + 26);
  v49[19] = *(_BYTE *)(a6 + 27);
  v49[20] = *(_BYTE *)(a6 + 28);
  v49[21] = *(_BYTE *)(a6 + 29);
  lim_set_protected_bit(v10, a6, a2, v49);
  if ( v35 )
  {
    v50 = dot11f_pack_wmm_del_ts(v10, v85, v84 + 24, v81, &v81);
    v59 = v50;
    if ( (v50 & 0x10000000) == 0 )
    {
      if ( !v50 )
        goto LABEL_26;
      v60 = "%s: There were warnings while packing a WMM Del TS frame (0x%08x)";
      goto LABEL_25;
    }
    v66 = "%s: Failed to pack a WMM Del TS frame (0x%08x)";
LABEL_30:
    qdf_trace_msg(0x35u, 2u, v66, v51, v52, v53, v54, v55, v56, v57, v58, "lim_send_delts_req_action_frame", v59);
    result = cds_packet_free(v80);
    goto LABEL_38;
  }
  v61 = dot11f_pack_del_ts(v10, &v82, v84 + 24, v81, &v81);
  v59 = v61;
  if ( (v61 & 0x10000000) != 0 )
  {
    v66 = "%s: Failed to pack a Del TS frame (0x%08x)";
    goto LABEL_30;
  }
  if ( !v61 )
    goto LABEL_26;
  v60 = "%s: There were warnings while packing a Del TS frame (0x%08x)";
LABEL_25:
  qdf_trace_msg(0x35u, 3u, v60, v51, v52, v53, v54, v55, v56, v57, v58, "lim_send_delts_req_action_frame");
LABEL_26:
  if ( v49 == (char *)-4LL )
  {
    v64 = 0;
    v62 = 0;
    v63 = 0;
    v65 = 0;
  }
  else
  {
    v62 = (unsigned __int8)v49[4];
    v63 = (unsigned __int8)v49[5];
    v64 = (unsigned __int8)v49[6];
    v65 = (unsigned __int8)v49[9];
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Sending DELTS REQ (size %d) to %02x:%02x:%02x:**:**:%02x",
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    "lim_send_delts_req_action_frame",
    v24 + 24,
    v62,
    v63,
    v64,
    v65);
  if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a6 + 284)) && (*(_DWORD *)(a6 + 7036) & 0xFFFFFFFE) != 2 )
    v67 = 0;
  else
    v67 = 64;
  qdf_trace(53, 2u, *(_WORD *)(a6 + 8), (unsigned __int8)*(_WORD *)v49 >> 4);
  v68 = lim_diag_mgmt_tx_event_report(v10, v49, a6, 0, 0);
  context = _cds_get_context(54, (__int64)"lim_send_delts_req_action_frame", v68, v69, v70, v71, v72, v73, v74, v75);
  v77 = wma_tx_packet(context, v80, v24 + 24, 3, 1, 7, lim_tx_complete, v84, 0, v67, v6, 0, 0, 12, 0, 0);
  v78 = *(_WORD *)(a6 + 8);
  v79 = v77;
  result = qdf_trace(53, 5u, v78, v77);
  if ( v79 )
  {
    v33 = "%s: Failed to send Del TS (%X)!";
    v34 = v79;
    goto LABEL_14;
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
