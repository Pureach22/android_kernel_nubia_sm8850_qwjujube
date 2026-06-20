__int64 __fastcall lim_send_channel_switch_mgmt_frame(
        __int64 a1,
        const void *a2,
        char a3,
        char a4,
        char a5,
        __int64 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  char v17; // w25
  unsigned int packed_channel_switch_size; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w23
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  const char *v39; // x2
  __int64 v40; // x4
  char *v41; // x22
  char *v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // w9
  __int16 v52; // w9
  __int64 v53; // x5
  char *v54; // x22
  unsigned int v55; // w0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  char v64; // w20
  __int64 result; // x0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  _QWORD *context; // x0
  int v75; // w0
  __int16 v76; // w2
  unsigned int v77; // w19
  __int64 v78; // [xsp+40h] [xbp-30h] BYREF
  unsigned int v79; // [xsp+4Ch] [xbp-24h] BYREF
  char *v80; // [xsp+50h] [xbp-20h] BYREF
  __int64 v81; // [xsp+58h] [xbp-18h] BYREF
  int v82; // [xsp+60h] [xbp-10h]
  __int64 v83; // [xsp+68h] [xbp-8h]

  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v82 = 0;
  v80 = nullptr;
  v81 = 0;
  v79 = 0;
  v78 = 0;
  if ( a6 )
  {
    v17 = *(_BYTE *)(a6 + 10);
    qdf_mem_set(&v81, 0xCu, 0);
    LOWORD(v81) = 1024;
    BYTE3(v81) = a3;
    BYTE4(v81) = a4;
    BYTE5(v81) = a5;
    BYTE2(v81) = 1;
    packed_channel_switch_size = dot11f_get_packed_channel_switch_size(a1, &v81, &v79);
    if ( (packed_channel_switch_size & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to calculate the packed size for a Channel Switch (0x%08x)",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "lim_send_channel_switch_mgmt_frame",
        packed_channel_switch_size);
      v79 = 12;
    }
    else if ( packed_channel_switch_size )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: There were warnings while calculating the packed size for a Channel Switch (0x%08x)",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "lim_send_channel_switch_mgmt_frame");
    }
    v30 = v79;
    if ( (unsigned int)cds_packet_alloc((unsigned __int16)v79 + 24, &v80, &v78) )
    {
      v39 = "%s: Failed to allocate %d bytes for a TPC Report";
      v40 = v30 + 24;
    }
    else
    {
      qdf_mem_set(v80, v30 + 24, 0);
      v41 = v80;
      v42 = v80 + 4;
      *v80 = -48;
      qdf_mem_copy(v42, a2, 6u);
      v41[10] = *(_BYTE *)(a6 + 30);
      v41[11] = *(_BYTE *)(a6 + 31);
      v41[12] = *(_BYTE *)(a6 + 32);
      v41[13] = *(_BYTE *)(a6 + 33);
      v41[14] = *(_BYTE *)(a6 + 34);
      v41[15] = *(_BYTE *)(a6 + 35);
      qdf_mem_copy(v41 + 16, a2, 6u);
      v51 = *(unsigned __int16 *)(a1 + 21532);
      if ( v51 <= 0xFFE )
        v52 = v51 + 1;
      else
        v52 = 2048;
      *(_WORD *)(a1 + 21532) = v52;
      *((_WORD *)v41 + 11) = (16 * (v52 & 0xF)) | *((_WORD *)v41 + 11) & 0xFF0F;
      v53 = (unsigned __int8)(*(_WORD *)(a1 + 21532) >> 4);
      *((_WORD *)v41 + 11) = (16 * *(_WORD *)(a1 + 21532)) & 0xFF00 | (16 * (v52 & 0xF));
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "lim_populate_mac_header",
        v52 & 0xF,
        v53,
        *(unsigned __int16 *)(a1 + 21532),
        0);
      v54 = v80;
      qdf_mem_copy(v80 + 16, (const void *)(a6 + 24), 6u);
      lim_set_protected_bit(a1, a6, a2, v54);
      v55 = dot11f_pack_channel_switch(a1, &v81, v80 + 24, v79, &v79);
      if ( (v55 & 0x10000000) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to pack a Channel Switch (0x%08x)",
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          "lim_send_channel_switch_mgmt_frame",
          v55);
        cds_packet_free(v78);
        goto LABEL_20;
      }
      if ( v55 )
        qdf_trace_msg(
          0x35u,
          3u,
          "%s: There were warnings while packing a Channel Switch (0x%08x)",
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          "lim_send_channel_switch_mgmt_frame");
      if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a6 + 284)) && (*(_DWORD *)(a6 + 7036) & 0xFFFFFFFE) != 2 )
        v64 = 0;
      else
        v64 = 64;
      qdf_trace(53, 2u, *(_WORD *)(a6 + 8), (unsigned __int8)*(_WORD *)v54 >> 4);
      context = _cds_get_context(
                  54,
                  (__int64)"lim_send_channel_switch_mgmt_frame",
                  v66,
                  v67,
                  v68,
                  v69,
                  v70,
                  v71,
                  v72,
                  v73);
      v75 = wma_tx_packet(context, v78, v30 + 24, 3, 1, 7, lim_tx_complete, v80, 0, v64, v17, 0, 0, 12, 0, 0);
      v76 = *(_WORD *)(a6 + 8);
      v77 = v75;
      qdf_trace(53, 5u, v76, v75);
      if ( !v77 )
      {
        result = 0;
        goto LABEL_21;
      }
      v39 = "%s: Failed to send a Channel Switch (%X)!";
      v40 = v77;
    }
    qdf_trace_msg(0x35u, 2u, v39, v31, v32, v33, v34, v35, v36, v37, v38, "lim_send_channel_switch_mgmt_frame", v40);
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Session entry is NULL!!!",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "lim_send_channel_switch_mgmt_frame");
  }
LABEL_20:
  result = 16;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
