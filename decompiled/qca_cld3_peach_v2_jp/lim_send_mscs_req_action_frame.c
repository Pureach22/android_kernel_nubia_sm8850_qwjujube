__int64 __fastcall lim_send_mscs_req_action_frame(__int64 a1, __int64 a2, unsigned __int8 *a3, __int64 a4)
{
  unsigned __int8 v7; // w8
  unsigned int packed_mscs_request_action_frameSize; // w0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2
  __int64 v27; // x4
  __int64 result; // x0
  char *v29; // x22
  char *v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w8
  __int16 v40; // w8
  __int64 v41; // x5
  char *v42; // x22
  unsigned int v43; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  _QWORD *context; // x0
  unsigned int v61; // w0
  int v62; // [xsp+8h] [xbp-88h]
  int v63; // [xsp+10h] [xbp-80h]
  __int64 v64; // [xsp+40h] [xbp-50h] BYREF
  unsigned int v65; // [xsp+4Ch] [xbp-44h] BYREF
  char *v66; // [xsp+50h] [xbp-40h] BYREF
  int v67; // [xsp+58h] [xbp-38h] BYREF
  __int16 v68; // [xsp+5Ch] [xbp-34h]
  _QWORD v69[4]; // [xsp+60h] [xbp-30h] BYREF
  int v70; // [xsp+80h] [xbp-10h]
  __int64 v71; // [xsp+88h] [xbp-8h]

  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v67 = a2;
  v68 = WORD2(a2);
  v66 = nullptr;
  v70 = 0;
  memset(v69, 0, sizeof(v69));
  v65 = 0;
  v64 = 0;
  qdf_mem_set(v69, 0x24u, 0);
  v7 = a3[7];
  LOWORD(v69[0]) = 1043;
  BYTE2(v69[0]) = v7;
  populate_dot11f_mscs_dec_element(a3, v69);
  packed_mscs_request_action_frameSize = dot11f_get_packed_mscs_request_action_frameSize(a1, v69, &v65);
  if ( (packed_mscs_request_action_frameSize & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for an MSCS Request (0x%08x)",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "lim_send_mscs_req_action_frame",
      packed_mscs_request_action_frameSize);
    v65 = 36;
  }
  else if ( packed_mscs_request_action_frameSize )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating the packed size for MSCS Request (0x%08x)",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "lim_send_mscs_req_action_frame");
  }
  v17 = v65;
  if ( (unsigned int)cds_packet_alloc((unsigned __int16)v65 + 6, &v66, &v64) )
  {
    v26 = "%s: Failed to allocate %d bytes for an mscs request";
    v27 = v17 + 6;
  }
  else
  {
    qdf_mem_set(v66, v17 + 6, 0);
    v29 = v66;
    v30 = v66 + 4;
    *v66 = -48;
    qdf_mem_copy(v30, &v67, 6u);
    v29[10] = *(_BYTE *)(a4 + 30);
    v29[11] = *(_BYTE *)(a4 + 31);
    v29[12] = *(_BYTE *)(a4 + 32);
    v29[13] = *(_BYTE *)(a4 + 33);
    v29[14] = *(_BYTE *)(a4 + 34);
    v29[15] = *(_BYTE *)(a4 + 35);
    qdf_mem_copy(v29 + 16, &v67, 6u);
    v39 = *(unsigned __int16 *)(a1 + 21532);
    if ( v39 <= 0xFFE )
      v40 = v39 + 1;
    else
      v40 = 2048;
    *(_WORD *)(a1 + 21532) = v40;
    *((_WORD *)v29 + 11) = (16 * (v40 & 0xF)) | *((_WORD *)v29 + 11) & 0xFF0F;
    v41 = (unsigned __int8)(*(_WORD *)(a1 + 21532) >> 4);
    *((_WORD *)v29 + 11) = (16 * *(_WORD *)(a1 + 21532)) & 0xFF00 | (16 * (v40 & 0xF));
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "lim_populate_mac_header",
      v40 & 0xF,
      v41,
      *(unsigned __int16 *)(a1 + 21532),
      0);
    v42 = v66;
    qdf_mem_copy(&v67, (const void *)(a4 + 24), 6u);
    lim_set_protected_bit(a1, a4, &v67, v42);
    v43 = dot11f_pack_mscs_request_action_frame(a1, v69, v66 + 24, v65, &v65);
    if ( (v43 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to pack an mscs Request (0x%08x)",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "lim_send_mscs_req_action_frame",
        v43);
      result = cds_packet_free(v64);
      goto LABEL_18;
    }
    if ( v43 )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: There were warnings while packing an mscs Request (0x%08x)",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "lim_send_mscs_req_action_frame");
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: mscs req TX: vdev id: %d to %02x:%02x:%02x:**:**:%02x seq num[%d], frame subtype:%d ",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "lim_send_mscs_req_action_frame",
      *a3,
      (unsigned __int8)v67,
      BYTE1(v67),
      BYTE2(v67),
      HIBYTE(v68),
      *(unsigned __int16 *)(a1 + 21532),
      (unsigned __int8)*(_WORD *)v66 >> 4);
    v52 = ((double (__fastcall *)(__int64, __int64, char *, _QWORD))qdf_trace_hex_dump)(
            53,
            8,
            v66,
            (unsigned __int16)(v65 + 24));
    context = _cds_get_context(54, (__int64)"lim_send_mscs_req_action_frame", v52, v53, v54, v55, v56, v57, v58, v59);
    LOBYTE(v63) = *(_BYTE *)(a4 + 10);
    LOBYTE(v62) = 0x80;
    v61 = wma_tx_packet(
            context,
            v64,
            (unsigned int)(unsigned __int16)v65 + 24,
            3,
            1,
            7,
            lim_tx_complete,
            v66,
            lim_mscs_req_tx_complete_cnf,
            v62,
            v63,
            0,
            0,
            12,
            0,
            0);
    if ( !v61 )
    {
      result = mlme_set_is_mscs_req_sent(*(_QWORD *)(a4 + 16), 1, v18, v19, v20, v21, v22, v23, v24, v25);
      goto LABEL_18;
    }
    v27 = v61;
    v26 = "%s: Could not send an mscs Request (%X)";
  }
  result = qdf_trace_msg(0x35u, 2u, v26, v18, v19, v20, v21, v22, v23, v24, v25, "lim_send_mscs_req_action_frame", v27);
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
