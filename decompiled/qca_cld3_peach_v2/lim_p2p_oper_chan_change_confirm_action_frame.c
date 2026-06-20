__int64 __fastcall lim_p2p_oper_chan_change_confirm_action_frame(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  char v14; // w22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w8
  unsigned int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w23
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  const char *v42; // x2
  __int64 v43; // x4
  char *v44; // x24
  void *v45; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w9
  __int16 v55; // w9
  __int64 v56; // x5
  _WORD *v57; // x24
  unsigned int v58; // w0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  char v75; // w21
  __int64 v76; // x4
  __int64 v77; // x5
  __int64 v78; // x6
  __int64 v79; // x7
  int v80; // w8
  __int64 result; // x0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  _QWORD *context; // x0
  int v91; // w0
  __int16 v92; // w2
  unsigned int v93; // w19
  __int64 v94; // [xsp+48h] [xbp-78h] BYREF
  unsigned int v95; // [xsp+54h] [xbp-6Ch] BYREF
  int v96[2]; // [xsp+58h] [xbp-68h] BYREF
  __int64 v97; // [xsp+60h] [xbp-60h] BYREF
  _QWORD v98[7]; // [xsp+68h] [xbp-58h] BYREF
  _QWORD v99[2]; // [xsp+A0h] [xbp-20h] BYREF
  _QWORD v100[2]; // [xsp+B0h] [xbp-10h] BYREF

  v100[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v99[1] = 0;
  v100[0] = 0;
  v99[0] = 0;
  memset(v98, 0, sizeof(v98));
  *(_QWORD *)v96 = 0;
  v97 = 0;
  v95 = 0;
  v94 = 0;
  if ( a3 )
  {
    v14 = *(_BYTE *)(a3 + 10);
    qdf_mem_set(&v97, 0x58u, 0);
    LOBYTE(v97) = 127;
    qdf_mem_copy((char *)&v97 + 1, &unk_969516, 4u);
    v23 = *(unsigned __int8 *)(a3 + 155);
    *(_WORD *)((char *)&v97 + 5) = 4;
    if ( v23 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Populate HT Caps in Assoc Request",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "lim_p2p_oper_chan_change_confirm_action_frame");
      populate_dot11f_ht_caps(a1, a3, v98);
    }
    if ( *(_BYTE *)(a3 + 7170) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Populate VHT Caps in Assoc Request",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "lim_p2p_oper_chan_change_confirm_action_frame");
      populate_dot11f_vht_caps(a1, a3, (char *)v99 + 4);
      populate_dot11f_operating_mode(a1, (char *)v100 + 4, a3);
    }
    v24 = dot11f_get_packed_p2p_oper_chan_change_confirmSize(a1, &v97, &v95);
    if ( (v24 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to get packed size 0x%08x",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "lim_p2p_oper_chan_change_confirm_action_frame",
        v24);
      v95 = 88;
    }
    else if ( v24 )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: There were warnings while calculating the packed size (0x%08x)",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "lim_p2p_oper_chan_change_confirm_action_frame");
    }
    v33 = v95;
    if ( (unsigned int)cds_packet_alloc((unsigned __int16)v95 + 24, v96, &v94) )
    {
      v42 = "%s: Failed to allocate %d bytes";
      v43 = v33 + 24;
LABEL_13:
      qdf_trace_msg(
        0x35u,
        2u,
        v42,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "lim_p2p_oper_chan_change_confirm_action_frame",
        v43);
      goto LABEL_25;
    }
    qdf_mem_set(*(void **)v96, v33 + 24, 0);
    v44 = *(char **)v96;
    v45 = (void *)(*(_QWORD *)v96 + 4LL);
    **(_BYTE **)v96 = -48;
    qdf_mem_copy(v45, a2, 6u);
    v44[10] = *(_BYTE *)(a3 + 30);
    v44[11] = *(_BYTE *)(a3 + 31);
    v44[12] = *(_BYTE *)(a3 + 32);
    v44[13] = *(_BYTE *)(a3 + 33);
    v44[14] = *(_BYTE *)(a3 + 34);
    v44[15] = *(_BYTE *)(a3 + 35);
    qdf_mem_copy(v44 + 16, a2, 6u);
    v54 = *(unsigned __int16 *)(a1 + 21604);
    if ( v54 <= 0xFFE )
      v55 = v54 + 1;
    else
      v55 = 2048;
    *(_WORD *)(a1 + 21604) = v55;
    *((_WORD *)v44 + 11) = (16 * (v55 & 0xF)) | *((_WORD *)v44 + 11) & 0xFF0F;
    v56 = (unsigned __int8)(*(_WORD *)(a1 + 21604) >> 4);
    *((_WORD *)v44 + 11) = (16 * *(_WORD *)(a1 + 21604)) & 0xFF00 | (16 * (v55 & 0xF));
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "lim_populate_mac_header",
      v55 & 0xF,
      v56,
      *(unsigned __int16 *)(a1 + 21604),
      0);
    v57 = *(_WORD **)v96;
    qdf_mem_copy((void *)(*(_QWORD *)v96 + 16LL), (const void *)(a3 + 24), 6u);
    v58 = dot11f_pack_p2p_oper_chan_change_confirm(a1, &v97, *(_QWORD *)v96 + 24LL, v95, &v95);
    if ( (v58 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to pack 0x%08x",
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        "lim_p2p_oper_chan_change_confirm_action_frame",
        v58);
      cds_packet_free(v94);
      goto LABEL_25;
    }
    if ( v58 )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: There were warnings while packing 0x%08x",
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        "lim_p2p_oper_chan_change_confirm_action_frame");
    if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a3 + 284)) && (*(_DWORD *)(a3 + 7036) & 0xFFFFFFFE) != 2 )
    {
      v75 = 0;
      v76 = *(unsigned int *)(a3 + 284);
      if ( a2 )
        goto LABEL_23;
    }
    else
    {
      v75 = 64;
      v76 = *(unsigned int *)(a3 + 284);
      if ( a2 )
      {
LABEL_23:
        v77 = *a2;
        v78 = a2[1];
        v79 = a2[2];
        v80 = a2[5];
LABEL_29:
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Send frame on channel freq %d to mac %02x:%02x:%02x:**:**:%02x",
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          "lim_p2p_oper_chan_change_confirm_action_frame",
          v76,
          v77,
          v78,
          v79,
          v80);
        qdf_trace(53, 2u, *(_WORD *)(a3 + 8), (unsigned __int8)*v57 >> 4);
        context = _cds_get_context(
                    54,
                    (__int64)"lim_p2p_oper_chan_change_confirm_action_frame",
                    v82,
                    v83,
                    v84,
                    v85,
                    v86,
                    v87,
                    v88,
                    v89);
        v91 = wma_tx_packet(
                context,
                v94,
                v33 + 24,
                3,
                1,
                7,
                lim_tx_complete,
                *(_QWORD *)v96,
                lim_oper_chan_change_confirm_tx_complete_cnf,
                v75,
                v14,
                0,
                0,
                12,
                0,
                0);
        v92 = *(_WORD *)(a3 + 8);
        v93 = v91;
        qdf_trace(53, 5u, v92, v91);
        if ( !v93 )
        {
          result = 0;
          goto LABEL_26;
        }
        v42 = "%s: Failed to send status %X!";
        v43 = v93;
        goto LABEL_13;
      }
    }
    v79 = 0;
    v77 = 0;
    v78 = 0;
    v80 = 0;
    goto LABEL_29;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Session entry is NULL!!!",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "lim_p2p_oper_chan_change_confirm_action_frame");
LABEL_25:
  result = 16;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
