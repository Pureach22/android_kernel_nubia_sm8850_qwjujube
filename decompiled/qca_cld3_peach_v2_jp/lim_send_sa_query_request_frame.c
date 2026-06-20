__int64 __fastcall lim_send_sa_query_request_frame(__int64 a1, const void *a2, unsigned __int8 *a3, __int64 a4)
{
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  _WORD *v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  char v26; // w0
  __int64 v27; // x2
  char v28; // w22
  __int64 v29; // x3
  int v30; // w8
  int v31; // w8
  char v32; // w0
  char v33; // w8
  unsigned int packed_sa_query_req_size; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w22
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  const char *v52; // x2
  __int64 v53; // x4
  char *v54; // x23
  char *v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int v64; // w9
  __int16 v65; // w9
  __int64 v66; // x5
  char *v67; // x3
  unsigned int v68; // w0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  int v77; // w8
  int v78; // w9
  int v79; // w10
  int v80; // w11
  __int64 result; // x0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  char v90; // w20
  char v91; // w19
  _QWORD *context; // x0
  int v93; // [xsp+8h] [xbp-68h]
  int v94; // [xsp+10h] [xbp-60h]
  int v95; // [xsp+18h] [xbp-58h]
  __int64 v96; // [xsp+40h] [xbp-30h] BYREF
  unsigned int v97; // [xsp+4Ch] [xbp-24h] BYREF
  char *v98; // [xsp+50h] [xbp-20h] BYREF
  __int16 v99; // [xsp+5Ch] [xbp-14h] BYREF
  _QWORD v100[2]; // [xsp+60h] [xbp-10h] BYREF

  v100[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v100[0] = 0;
  v98 = nullptr;
  v97 = 0;
  v96 = 0;
  qdf_mem_set(v100, 8u, 0);
  LOWORD(v100[0]) = 8;
  qdf_mem_copy((char *)v100 + 2, a2, 2u);
  v8 = *(_QWORD *)(a4 + 16);
  v99 = 0;
  if ( (wlan_crypto_get_param(v8, 5u) & 0x4000) != 0 )
  {
    v17 = (_WORD *)dph_lookup_hash_entry(v9, v10, v11, v12, v13, v14, v15, v16, a1, a3, &v99, a4 + 360);
    if ( v17 )
    {
      if ( (*v17 & 0x800) != 0 )
      {
        v26 = wlan_reg_freq_to_chan(
                *(_QWORD *)(a1 + 21560),
                *(_DWORD *)(a4 + 284),
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                v25);
        v27 = *(unsigned int *)(a4 + 7176);
        v28 = v26;
        if ( (_DWORD)v27 == 2 )
        {
          v29 = 4;
        }
        else
        {
          v30 = *(_DWORD *)(a4 + 164);
          if ( v30 == 3 )
            v29 = 3;
          else
            v29 = v30 == 1;
        }
        lim_op_class_from_bandwidth(a1, *(unsigned int *)(a4 + 284), v27, v29);
        v31 = *(_DWORD *)(a4 + 7176);
        BYTE5(v100[0]) = v32;
        BYTE6(v100[0]) = v28;
        if ( v31 == 4 )
          v33 = *(_BYTE *)(a4 + 7184);
        else
          v33 = 0;
        HIBYTE(v100[0]) = v33;
        BYTE4(v100[0]) = 1;
      }
    }
  }
  packed_sa_query_req_size = dot11f_get_packed_sa_query_req_size(a1, v100, &v97);
  if ( (packed_sa_query_req_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for an SA Query Request (0x%08x)",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "lim_send_sa_query_request_frame",
      packed_sa_query_req_size);
    v97 = 8;
  }
  else if ( packed_sa_query_req_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating the packed size for an SA Query Request (0x%08x)",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "lim_send_sa_query_request_frame");
  }
  v43 = v97;
  if ( (unsigned int)cds_packet_alloc((unsigned __int16)v97 + 24, &v98, &v96) )
  {
    v52 = "%s: Failed to allocate %d bytes for a SA Query Request action frame";
    v53 = v43 + 24;
LABEL_19:
    qdf_trace_msg(0x35u, 2u, v52, v44, v45, v46, v47, v48, v49, v50, v51, "lim_send_sa_query_request_frame", v53);
LABEL_29:
    result = 16;
    goto LABEL_30;
  }
  qdf_mem_set(v98, v43 + 24, 0);
  v54 = v98;
  v55 = v98 + 4;
  *v98 = -48;
  qdf_mem_copy(v55, a3, 6u);
  v54[10] = *(_BYTE *)(a4 + 30);
  v54[11] = *(_BYTE *)(a4 + 31);
  v54[12] = *(_BYTE *)(a4 + 32);
  v54[13] = *(_BYTE *)(a4 + 33);
  v54[14] = *(_BYTE *)(a4 + 34);
  v54[15] = *(_BYTE *)(a4 + 35);
  qdf_mem_copy(v54 + 16, a3, 6u);
  v64 = *(unsigned __int16 *)(a1 + 21532);
  if ( v64 <= 0xFFE )
    v65 = v64 + 1;
  else
    v65 = 2048;
  *(_WORD *)(a1 + 21532) = v65;
  *((_WORD *)v54 + 11) = (16 * (v65 & 0xF)) | *((_WORD *)v54 + 11) & 0xFF0F;
  v66 = (unsigned __int8)(*(_WORD *)(a1 + 21532) >> 4);
  *((_WORD *)v54 + 11) = (16 * *(_WORD *)(a1 + 21532)) & 0xFF00 | (16 * (v65 & 0xF));
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    "lim_populate_mac_header",
    v65 & 0xF,
    v66,
    *(unsigned __int16 *)(a1 + 21532),
    0);
  v67 = v98;
  v98[16] = *(_BYTE *)(a4 + 24);
  v67[17] = *(_BYTE *)(a4 + 25);
  v67[18] = *(_BYTE *)(a4 + 26);
  v67[19] = *(_BYTE *)(a4 + 27);
  v67[20] = *(_BYTE *)(a4 + 28);
  v67[21] = *(_BYTE *)(a4 + 29);
  lim_set_protected_bit(a1, a4, a3, v67);
  v68 = dot11f_pack_sa_query_req(a1, v100, v98 + 24, v97, &v97);
  if ( (v68 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to pack an SA Query Request (0x%08x)",
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      "lim_send_sa_query_request_frame",
      v68);
    cds_packet_free(v96);
    goto LABEL_29;
  }
  if ( v68 )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while packing SA Query Request (0x%08x)",
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      "lim_send_sa_query_request_frame");
  if ( a3 )
  {
    v77 = *a3;
    v78 = a3[1];
    v79 = a3[2];
    v80 = a3[5];
  }
  else
  {
    v79 = 0;
    v77 = 0;
    v78 = 0;
    v80 = 0;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Sending an SA Query Request from %02x:%02x:%02x:**:**:%02x to %02x:%02x:%02x:**:**:%02x",
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    v76,
    "lim_send_sa_query_request_frame",
    *(unsigned __int8 *)(a4 + 30),
    *(unsigned __int8 *)(a4 + 31),
    *(unsigned __int8 *)(a4 + 32),
    *(unsigned __int8 *)(a4 + 35),
    v77,
    v78,
    v79,
    v80);
  if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284)) && (*(_DWORD *)(a4 + 7036) & 0xFFFFFFFE) != 2 )
    v90 = 0;
  else
    v90 = 64;
  v91 = *(_BYTE *)(a4 + 10);
  context = _cds_get_context(54, (__int64)"lim_send_sa_query_request_frame", v82, v83, v84, v85, v86, v87, v88, v89);
  LOBYTE(v95) = 0;
  LOBYTE(v94) = v91;
  LOBYTE(v93) = v90;
  result = wma_tx_packet(context, v96, v43 + 24, 3, 1, 7, lim_tx_complete, v98, 0, v93, v94, v95, 0, 12, 0, 0);
  if ( (_DWORD)result )
  {
    v53 = (unsigned int)result;
    v52 = "%s: wma_tx_frame FAILED! Status [%d]";
    goto LABEL_19;
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
