__int64 __fastcall lim_send_delba_action_frame(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        __int16 a4,
        unsigned __int8 a5)
{
  unsigned __int8 v8; // w19
  __int64 session_by_vdev_id; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  int v23; // w8
  __int64 result; // x0
  unsigned int packed_delba_req_size; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v34; // w24
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  char *v43; // x23
  char *v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w9
  __int16 v54; // w9
  __int64 v55; // x5
  char *v56; // x23
  unsigned int v57; // w0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  char v66; // w21
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  _QWORD *context; // x0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  unsigned int v84; // w19
  int v85; // [xsp+8h] [xbp-68h]
  int v86; // [xsp+10h] [xbp-60h]
  char *v87; // [xsp+48h] [xbp-28h] BYREF
  __int64 v88; // [xsp+50h] [xbp-20h] BYREF
  __int64 v89; // [xsp+5Ch] [xbp-14h] BYREF
  __int16 v90; // [xsp+64h] [xbp-Ch]
  __int64 v91; // [xsp+68h] [xbp-8h]

  v8 = a2;
  v91 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v90 = 0;
  v89 = 0;
  v87 = nullptr;
  v88 = 0;
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, a2);
  if ( !session_by_vdev_id )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: delba invalid vdev id %d ",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "lim_send_delba_action_frame",
      v8);
    result = 4;
    goto LABEL_28;
  }
  v19 = session_by_vdev_id;
  if ( a3 )
  {
    v20 = *a3;
    v21 = a3[1];
    v22 = a3[2];
    v23 = a3[5];
  }
  else
  {
    v22 = 0;
    v20 = 0;
    v21 = 0;
    v23 = 0;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: send delba vdev %d %02x:%02x:%02x:**:**:%02x tid %d reason %d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "lim_send_delba_action_frame",
    v8,
    v20,
    v21,
    v22,
    v23,
    (unsigned __int8)a4,
    a5);
  qdf_mem_set((char *)&v89 + 4, 6u, 0);
  WORD2(v89) = 515;
  v90 = a5;
  HIWORD(v89) = HIWORD(v89) & 0x7FF | (a4 << 12);
  packed_delba_req_size = dot11f_get_packed_delba_req_size(a1, (char *)&v89 + 4, &v89);
  if ( (packed_delba_req_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a DELBA(0x%08x).",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "lim_send_delba_action_frame",
      packed_delba_req_size);
    LODWORD(v89) = 6;
  }
  else if ( packed_delba_req_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Warnings in calculating the packed size for a DELBA (0x%08x).",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "lim_send_delba_action_frame");
  }
  v34 = v89;
  if ( (unsigned int)cds_packet_alloc((unsigned __int16)v89 + 24, &v87, &v88) || !v88 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to allocate %d bytes for a DELBA",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "lim_send_delba_action_frame",
      (unsigned int)(v34 + 24));
LABEL_27:
    result = 16;
    goto LABEL_28;
  }
  qdf_mem_set(v87, (unsigned int)(v34 + 24), 0);
  v43 = v87;
  v44 = v87 + 4;
  *v87 = -48;
  qdf_mem_copy(v44, a3, 6u);
  v43[10] = *(_BYTE *)(v19 + 30);
  v43[11] = *(_BYTE *)(v19 + 31);
  v43[12] = *(_BYTE *)(v19 + 32);
  v43[13] = *(_BYTE *)(v19 + 33);
  v43[14] = *(_BYTE *)(v19 + 34);
  v43[15] = *(_BYTE *)(v19 + 35);
  qdf_mem_copy(v43 + 16, a3, 6u);
  v53 = *(unsigned __int16 *)(a1 + 21604);
  if ( v53 <= 0xFFE )
    v54 = v53 + 1;
  else
    v54 = 2048;
  *(_WORD *)(a1 + 21604) = v54;
  *((_WORD *)v43 + 11) = (16 * (v54 & 0xF)) | *((_WORD *)v43 + 11) & 0xFF0F;
  v55 = (unsigned __int8)(*(_WORD *)(a1 + 21604) >> 4);
  *((_WORD *)v43 + 11) = (16 * *(_WORD *)(a1 + 21604)) & 0xFF00 | (16 * (v54 & 0xF));
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    "lim_populate_mac_header",
    v54 & 0xF,
    v55,
    *(unsigned __int16 *)(a1 + 21604),
    0);
  v56 = v87;
  v87[16] = *(_BYTE *)(v19 + 24);
  v56[17] = *(_BYTE *)(v19 + 25);
  v56[18] = *(_BYTE *)(v19 + 26);
  v56[19] = *(_BYTE *)(v19 + 27);
  v56[20] = *(_BYTE *)(v19 + 28);
  v56[21] = *(_BYTE *)(v19 + 29);
  lim_set_protected_bit(a1, v19, a3, v56);
  v57 = dot11f_pack_delba_req(a1, (char *)&v89 + 4, v87 + 24, (unsigned int)v89, &v89);
  if ( (v57 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to pack a DELBA (0x%08x)",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      "lim_send_delba_action_frame",
      v57);
    if ( v88 )
      cds_packet_free(v88);
    goto LABEL_27;
  }
  if ( v57 )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while packing DELBA (0x%08x)",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      "lim_send_delba_action_frame");
  if ( wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(v19 + 284))
    || wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v19 + 284))
    || (*(_DWORD *)(v19 + 7036) & 0xFFFFFFFE) == 2 )
  {
    v66 = 64;
  }
  else
  {
    v66 = 0;
  }
  qdf_trace(53, 2u, *(_WORD *)(v19 + 8), (unsigned __int8)*(_WORD *)v56 >> 4);
  context = _cds_get_context(54, (__int64)"lim_send_delba_action_frame", v67, v68, v69, v70, v71, v72, v73, v74);
  LOBYTE(v86) = v8;
  LOBYTE(v85) = v66;
  result = wma_tx_packet(
             context,
             v88,
             (unsigned int)(v34 + 24),
             3,
             1,
             7,
             0,
             v87,
             lim_delba_tx_complete_cnf,
             v85,
             v86,
             0,
             0,
             12,
             0,
             0);
  if ( (_DWORD)result )
  {
    v84 = result;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: delba wma_tx_frame FAILED! Status [%d]",
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      "lim_send_delba_action_frame",
      (unsigned int)result);
    result = v84;
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
