__int64 __fastcall lim_send_extended_chan_switch_action_frame(
        __int64 a1,
        const void *a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        unsigned __int8 a5,
        int a6,
        __int64 a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  char v18; // w26
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int chanwidth_from_opclass; // w8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  char v41; // w5
  char v42; // w6
  unsigned int packed_ext_channel_switch_action_frame_size; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w23
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  const char *v61; // x2
  __int64 v62; // x4
  char *v63; // x22
  void *v64; // x0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned int v73; // w9
  __int16 v74; // w9
  __int64 v75; // x5
  unsigned __int8 *v76; // x22
  unsigned int v77; // w0
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  char v94; // w21
  __int64 v95; // x4
  __int64 v96; // x5
  __int64 v97; // x6
  __int64 v98; // x7
  __int64 result; // x0
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  _QWORD *context; // x0
  int v109; // w0
  __int16 v110; // w2
  unsigned int v111; // w19
  int v112; // [xsp+8h] [xbp-A8h]
  int v113; // [xsp+10h] [xbp-A0h]
  int v114; // [xsp+18h] [xbp-98h]
  __int64 v115; // [xsp+48h] [xbp-68h] BYREF
  unsigned int v116; // [xsp+54h] [xbp-5Ch] BYREF
  int v117[2]; // [xsp+58h] [xbp-58h] BYREF
  __int16 v118; // [xsp+64h] [xbp-4Ch] BYREF
  char v119; // [xsp+66h] [xbp-4Ah]
  _QWORD v120[9]; // [xsp+68h] [xbp-48h] BYREF

  v120[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v120, 0, 64);
  *(_QWORD *)v117 = 0;
  v116 = 0;
  v115 = 0;
  v119 = 0;
  v118 = 0;
  if ( a7 )
  {
    v18 = *(_BYTE *)(a7 + 10);
    qdf_mem_set(v120, 0x40u, 0);
    v23 = *(_QWORD *)(a1 + 21552);
    LOWORD(v120[0]) = 1028;
    HIDWORD(v120[0]) = a3 | (unsigned __int16)(a4 << 8) | (a5 << 16) | (a6 << 24);
    wlan_reg_read_current_country(v23, &v118, v24, v25, v26, v27, v28, v29, v30, v31);
    chanwidth_from_opclass = (unsigned __int8)wlan_reg_dmn_get_chanwidth_from_opclass((__int64)&v118, a5, a4);
    if ( chanwidth_from_opclass == 160 || chanwidth_from_opclass == 80 )
    {
      v41 = *(_BYTE *)(a7 + 7188);
      v42 = *(_BYTE *)(a7 + 7189);
      BYTE1(v120[1]) = *(_BYTE *)(a7 + 7187);
      BYTE2(v120[1]) = v41;
      BYTE3(v120[1]) = v42;
      LOBYTE(v120[1]) = 1;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: wrapper: width:%d f0:%d f1:%d",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "lim_send_extended_chan_switch_action_frame");
    }
    if ( policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(a7 + 10)) )
      populate_dot11f_ecsa_param_set_for_ll_sap(*(_QWORD *)(a7 + 16), (char *)&v120[1] + 4);
    packed_ext_channel_switch_action_frame_size = dot11f_get_packed_ext_channel_switch_action_frame_size(
                                                    a1,
                                                    v120,
                                                    &v116);
    if ( (packed_ext_channel_switch_action_frame_size & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to get packed size for Channel Switch 0x%08x",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "lim_send_extended_chan_switch_action_frame",
        packed_ext_channel_switch_action_frame_size);
      v116 = 64;
    }
    else if ( packed_ext_channel_switch_action_frame_size )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: There were warnings while calculating the packed size for a Ext Channel Switch (0x%08x)",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "lim_send_extended_chan_switch_action_frame");
    }
    v52 = v116;
    if ( (unsigned int)cds_packet_alloc((unsigned __int16)v116 + 24, v117, &v115) )
    {
      v61 = "%s: Failed to allocate %d bytes for a Ext Channel Switch";
      v62 = v52 + 24;
LABEL_14:
      qdf_trace_msg(
        0x35u,
        2u,
        v61,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "lim_send_extended_chan_switch_action_frame",
        v62);
      goto LABEL_26;
    }
    qdf_mem_set(*(void **)v117, v52 + 24, 0);
    v63 = *(char **)v117;
    v64 = (void *)(*(_QWORD *)v117 + 4LL);
    **(_BYTE **)v117 = -48;
    qdf_mem_copy(v64, a2, 6u);
    v63[10] = *(_BYTE *)(a7 + 30);
    v63[11] = *(_BYTE *)(a7 + 31);
    v63[12] = *(_BYTE *)(a7 + 32);
    v63[13] = *(_BYTE *)(a7 + 33);
    v63[14] = *(_BYTE *)(a7 + 34);
    v63[15] = *(_BYTE *)(a7 + 35);
    qdf_mem_copy(v63 + 16, a2, 6u);
    v73 = *(unsigned __int16 *)(a1 + 21532);
    if ( v73 <= 0xFFE )
      v74 = v73 + 1;
    else
      v74 = 2048;
    *(_WORD *)(a1 + 21532) = v74;
    *((_WORD *)v63 + 11) = (16 * (v74 & 0xF)) | *((_WORD *)v63 + 11) & 0xFF0F;
    v75 = (unsigned __int8)(*(_WORD *)(a1 + 21532) >> 4);
    *((_WORD *)v63 + 11) = (16 * *(_WORD *)(a1 + 21532)) & 0xFF00 | (16 * (v74 & 0xF));
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      "lim_populate_mac_header",
      v74 & 0xF,
      v75,
      *(unsigned __int16 *)(a1 + 21532),
      0);
    v76 = *(unsigned __int8 **)v117;
    qdf_mem_copy((void *)(*(_QWORD *)v117 + 16LL), (const void *)(a7 + 24), 6u);
    lim_set_protected_bit(a1, a7, a2, v76);
    v77 = dot11f_pack_ext_channel_switch_action_frame(a1, v120, *(_QWORD *)v117 + 24LL, v116, &v116);
    if ( (v77 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to pack a Channel Switch 0x%08x",
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        "lim_send_extended_chan_switch_action_frame",
        v77);
      cds_packet_free(v115);
      goto LABEL_26;
    }
    if ( v77 )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: There were warnings while packing a Channel Switch 0x%08x",
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        "lim_send_extended_chan_switch_action_frame");
    if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 284)) && (*(_DWORD *)(a7 + 7036) & 0xFFFFFFFE) != 2 )
    {
      v94 = 0;
      if ( v76 != (unsigned __int8 *)-4LL )
        goto LABEL_24;
    }
    else
    {
      v94 = 64;
      if ( v76 != (unsigned __int8 *)-4LL )
      {
LABEL_24:
        v95 = v76[4];
        v96 = v76[5];
        v97 = v76[6];
        v98 = v76[9];
LABEL_30:
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: ECSA frame to :%02x:%02x:%02x:**:**:%02x count %d mode %d chan %d op class %d",
          v86,
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          "lim_send_extended_chan_switch_action_frame",
          v95,
          v96,
          v97,
          v98,
          HIBYTE(HIDWORD(v120[0])),
          BYTE4(v120[0]),
          BYTE6(v120[0]),
          BYTE5(v120[0]));
        qdf_trace(53, 2u, *(_WORD *)(a7 + 8), (unsigned __int8)*(_WORD *)v76 >> 4);
        context = _cds_get_context(
                    54,
                    (__int64)"lim_send_extended_chan_switch_action_frame",
                    v100,
                    v101,
                    v102,
                    v103,
                    v104,
                    v105,
                    v106,
                    v107);
        LOBYTE(v113) = v18;
        LOBYTE(v112) = v94;
        LOBYTE(v114) = 0;
        v109 = wma_tx_packet(
                 context,
                 v115,
                 v52 + 24,
                 3,
                 1,
                 7,
                 lim_tx_complete,
                 *(_QWORD *)v117,
                 lim_ecsa_confirm_tx_complete_cnf,
                 v112,
                 v113,
                 v114,
                 0,
                 12,
                 0,
                 1028);
        v110 = *(_WORD *)(a7 + 8);
        v111 = v109;
        qdf_trace(53, 5u, v110, v109);
        if ( !v111 )
        {
          result = 0;
          goto LABEL_27;
        }
        v61 = "%s: Failed to send a Ext Channel Switch %X!";
        v62 = v111;
        goto LABEL_14;
      }
    }
    v97 = 0;
    v95 = 0;
    v96 = 0;
    v98 = 0;
    goto LABEL_30;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Session entry is NULL!!!",
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    a15,
    "lim_send_extended_chan_switch_action_frame");
LABEL_26:
  result = 16;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
