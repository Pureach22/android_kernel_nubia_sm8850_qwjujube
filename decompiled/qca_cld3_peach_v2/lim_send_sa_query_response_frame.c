__int64 __fastcall lim_send_sa_query_response_frame(__int64 a1, const void *a2, unsigned __int8 *a3, __int64 a4)
{
  char v8; // w23
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _WORD *v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  char v27; // w0
  __int64 v28; // x2
  char v29; // w22
  __int64 v30; // x3
  int v31; // w8
  int v32; // w8
  char v33; // w0
  char v34; // w8
  unsigned int packed_sa_query_rsp_size; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w24
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  const char *v53; // x2
  __int64 v54; // x4
  char *v55; // x22
  char *v56; // x0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int v65; // w9
  __int16 v66; // w9
  __int64 v67; // x5
  char *v68; // x22
  unsigned int v69; // w0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 v78; // x4
  __int64 v79; // x5
  __int64 v80; // x6
  __int64 v81; // x7
  __int64 result; // x0
  char v83; // w20
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  _QWORD *context; // x0
  int v93; // w0
  __int16 v94; // w2
  unsigned int v95; // w19
  int v96; // [xsp+8h] [xbp-68h]
  int v97; // [xsp+10h] [xbp-60h]
  int v98; // [xsp+18h] [xbp-58h]
  __int64 v99; // [xsp+40h] [xbp-30h] BYREF
  unsigned int v100; // [xsp+4Ch] [xbp-24h] BYREF
  char *v101; // [xsp+50h] [xbp-20h] BYREF
  __int16 v102; // [xsp+5Ch] [xbp-14h] BYREF
  _QWORD v103[2]; // [xsp+60h] [xbp-10h] BYREF

  v103[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_BYTE *)(a4 + 10);
  v103[0] = 0;
  v101 = nullptr;
  v100 = 0;
  v99 = 0;
  qdf_mem_set(v103, 8u, 0);
  LOWORD(v103[0]) = 264;
  qdf_mem_copy((char *)v103 + 2, a2, 2u);
  v9 = *(_QWORD *)(a4 + 16);
  v102 = 0;
  if ( (wlan_crypto_get_param(v9, 5u) & 0x4000) != 0 )
  {
    v18 = (_WORD *)dph_lookup_hash_entry(v10, v11, v12, v13, v14, v15, v16, v17, a1, a3, &v102, a4 + 360);
    if ( v18 )
    {
      if ( (*v18 & 0x800) != 0 )
      {
        v27 = wlan_reg_freq_to_chan(
                *(_QWORD *)(a1 + 21632),
                *(_DWORD *)(a4 + 284),
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                v26);
        v28 = *(unsigned int *)(a4 + 7176);
        v29 = v27;
        if ( (_DWORD)v28 == 2 )
        {
          v30 = 4;
        }
        else
        {
          v31 = *(_DWORD *)(a4 + 164);
          if ( v31 == 3 )
            v30 = 3;
          else
            v30 = v31 == 1;
        }
        lim_op_class_from_bandwidth(a1, *(unsigned int *)(a4 + 284), v28, v30);
        v32 = *(_DWORD *)(a4 + 7176);
        BYTE5(v103[0]) = v33;
        BYTE6(v103[0]) = v29;
        if ( v32 == 4 )
          v34 = *(_BYTE *)(a4 + 7186);
        else
          v34 = 0;
        HIBYTE(v103[0]) = v34;
        BYTE4(v103[0]) = 1;
      }
    }
  }
  packed_sa_query_rsp_size = dot11f_get_packed_sa_query_rsp_size(a1, v103, &v100);
  if ( (packed_sa_query_rsp_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a SA Query Response (0x%08x)",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "lim_send_sa_query_response_frame",
      packed_sa_query_rsp_size);
    v100 = 8;
  }
  else if ( packed_sa_query_rsp_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating the packed size for an SA Query Response (0x%08x)",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "lim_send_sa_query_response_frame");
  }
  v44 = v100;
  if ( (unsigned int)cds_packet_alloc((unsigned __int16)v100 + 24, &v101, &v99) )
  {
    v53 = "%s: Failed to allocate %d bytes for a SA query response action frame";
    v54 = v44 + 24;
  }
  else
  {
    qdf_mem_set(v101, v44 + 24, 0);
    v55 = v101;
    v56 = v101 + 4;
    *v101 = -48;
    qdf_mem_copy(v56, a3, 6u);
    v55[10] = *(_BYTE *)(a4 + 30);
    v55[11] = *(_BYTE *)(a4 + 31);
    v55[12] = *(_BYTE *)(a4 + 32);
    v55[13] = *(_BYTE *)(a4 + 33);
    v55[14] = *(_BYTE *)(a4 + 34);
    v55[15] = *(_BYTE *)(a4 + 35);
    qdf_mem_copy(v55 + 16, a3, 6u);
    v65 = *(unsigned __int16 *)(a1 + 21604);
    if ( v65 <= 0xFFE )
      v66 = v65 + 1;
    else
      v66 = 2048;
    *(_WORD *)(a1 + 21604) = v66;
    *((_WORD *)v55 + 11) = (16 * (v66 & 0xF)) | *((_WORD *)v55 + 11) & 0xFF0F;
    v67 = (unsigned __int8)(*(_WORD *)(a1 + 21604) >> 4);
    *((_WORD *)v55 + 11) = (16 * *(_WORD *)(a1 + 21604)) & 0xFF00 | (16 * (v66 & 0xF));
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "lim_populate_mac_header",
      v66 & 0xF,
      v67,
      *(unsigned __int16 *)(a1 + 21604),
      0);
    v68 = v101;
    v101[16] = *(_BYTE *)(a4 + 24);
    v68[17] = *(_BYTE *)(a4 + 25);
    v68[18] = *(_BYTE *)(a4 + 26);
    v68[19] = *(_BYTE *)(a4 + 27);
    v68[20] = *(_BYTE *)(a4 + 28);
    v68[21] = *(_BYTE *)(a4 + 29);
    lim_set_protected_bit(a1, a4, a3, v68);
    v69 = dot11f_pack_sa_query_rsp(a1, v103, v101 + 24, v100, &v100);
    if ( (v69 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to pack an SA Query Response (0x%08x)",
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        "lim_send_sa_query_response_frame",
        v69);
      cds_packet_free(v99);
      goto LABEL_29;
    }
    if ( v69 )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: There were warnings while packing SA Query Response (0x%08x)",
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        "lim_send_sa_query_response_frame");
    if ( a3 )
    {
      v78 = *a3;
      v79 = a3[1];
      v80 = a3[2];
      v81 = a3[5];
    }
    else
    {
      v80 = 0;
      v78 = 0;
      v79 = 0;
      v81 = 0;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Sending SA Query Response to %02x:%02x:%02x:**:**:%02x op_class %d prim_ch_num %d freq_seg_1_ch_num %d oci_present %d",
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      "lim_send_sa_query_response_frame",
      v78,
      v79,
      v80,
      v81,
      BYTE5(v103[0]),
      BYTE6(v103[0]),
      HIBYTE(v103[0]),
      BYTE4(v103[0]));
    if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284)) && (*(_DWORD *)(a4 + 7036) & 0xFFFFFFFE) != 2 )
      v83 = 0;
    else
      v83 = 64;
    qdf_trace(53, 2u, *(_WORD *)(a4 + 8), (unsigned __int8)*(_WORD *)v68 >> 4);
    context = _cds_get_context(54, (__int64)"lim_send_sa_query_response_frame", v84, v85, v86, v87, v88, v89, v90, v91);
    LOBYTE(v98) = 0;
    LOBYTE(v97) = v8;
    LOBYTE(v96) = v83;
    v93 = wma_tx_packet(context, v99, v44 + 24, 3, 1, 7, lim_tx_complete, v101, 0, v96, v97, v98, 0, 12, 0, 0);
    v94 = *(_WORD *)(a4 + 8);
    v95 = v93;
    qdf_trace(53, 5u, v94, v93);
    if ( !v95 )
    {
      result = 0;
      goto LABEL_30;
    }
    v53 = "%s: wma_tx_frame FAILED! Status [%d]";
    v54 = v95;
  }
  qdf_trace_msg(0x35u, 2u, v53, v45, v46, v47, v48, v49, v50, v51, v52, "lim_send_sa_query_response_frame", v54);
LABEL_29:
  result = 16;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
