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
  _BYTE *v23; // x27
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int chanwidth_from_opclass; // w8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  char v42; // w5
  char v43; // w6
  unsigned int packed_ext_channel_switch_action_frame_size; // w0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w23
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  const char *v62; // x2
  __int64 v63; // x4
  char *v64; // x22
  void *v65; // x0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned int v74; // w9
  __int16 v75; // w9
  __int64 v76; // x5
  unsigned __int8 *v77; // x22
  unsigned int v78; // w0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  char v95; // w21
  __int64 v96; // x4
  __int64 v97; // x5
  __int64 v98; // x6
  __int64 v99; // x7
  __int64 result; // x0
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  _QWORD *context; // x0
  int v110; // w0
  __int16 v111; // w2
  unsigned int v112; // w19
  int v113; // [xsp+8h] [xbp-A8h]
  int v114; // [xsp+10h] [xbp-A0h]
  int v115; // [xsp+18h] [xbp-98h]
  __int64 v116; // [xsp+48h] [xbp-68h] BYREF
  unsigned int v117; // [xsp+54h] [xbp-5Ch] BYREF
  int v118[2]; // [xsp+58h] [xbp-58h] BYREF
  __int16 v119; // [xsp+64h] [xbp-4Ch] BYREF
  char v120; // [xsp+66h] [xbp-4Ah]
  _QWORD v121[7]; // [xsp+68h] [xbp-48h] BYREF
  _QWORD v122[2]; // [xsp+A0h] [xbp-10h] BYREF

  v122[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v122[0] = 0;
  memset(v121, 0, sizeof(v121));
  *(_QWORD *)v118 = 0;
  v117 = 0;
  v116 = 0;
  v120 = 0;
  v119 = 0;
  if ( a7 )
  {
    v18 = *(_BYTE *)(a7 + 10);
    v23 = (_BYTE *)(a7 + 7189);
    qdf_mem_set(v121, 0x40u, 0);
    v24 = *(_QWORD *)(a1 + 21624);
    LOWORD(v121[0]) = 1028;
    HIDWORD(v121[0]) = a3 | (unsigned __int16)(a4 << 8) | (a5 << 16) | (a6 << 24);
    wlan_reg_read_current_country(v24, &v119, v25, v26, v27, v28, v29, v30, v31, v32);
    chanwidth_from_opclass = (unsigned __int8)wlan_reg_dmn_get_chanwidth_from_opclass((__int64)&v119, a5, a4);
    if ( chanwidth_from_opclass == 160 || chanwidth_from_opclass == 80 )
    {
      v42 = v23[1];
      v43 = v23[2];
      BYTE1(v121[1]) = *v23;
      BYTE2(v121[1]) = v42;
      BYTE3(v121[1]) = v43;
      LOBYTE(v121[1]) = 1;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: wrapper: width:%d f0:%d f1:%d",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "lim_send_extended_chan_switch_action_frame");
    }
    if ( policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a7 + 10)) )
      populate_dot11f_ecsa_param_set_for_ll_sap(*(_QWORD *)(a7 + 16), (char *)&v121[1] + 4);
    if ( v23[2882] == 1 )
      populate_dot11f_bw_ind_element(a1, a7, v122);
    packed_ext_channel_switch_action_frame_size = dot11f_get_packed_ext_channel_switch_action_frame_size(
                                                    a1,
                                                    v121,
                                                    &v117);
    if ( (packed_ext_channel_switch_action_frame_size & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to get packed size for Channel Switch 0x%08x",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "lim_send_extended_chan_switch_action_frame",
        packed_ext_channel_switch_action_frame_size);
      v117 = 64;
    }
    else if ( packed_ext_channel_switch_action_frame_size )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: There were warnings while calculating the packed size for a Ext Channel Switch (0x%08x)",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "lim_send_extended_chan_switch_action_frame");
    }
    v53 = v117;
    if ( (unsigned int)cds_packet_alloc((unsigned __int16)v117 + 24, v118, &v116) )
    {
      v62 = "%s: Failed to allocate %d bytes for a Ext Channel Switch";
      v63 = v53 + 24;
LABEL_16:
      qdf_trace_msg(
        0x35u,
        2u,
        v62,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "lim_send_extended_chan_switch_action_frame",
        v63);
      goto LABEL_28;
    }
    qdf_mem_set(*(void **)v118, v53 + 24, 0);
    v64 = *(char **)v118;
    v65 = (void *)(*(_QWORD *)v118 + 4LL);
    **(_BYTE **)v118 = -48;
    qdf_mem_copy(v65, a2, 6u);
    v64[10] = *(_BYTE *)(a7 + 30);
    v64[11] = *(_BYTE *)(a7 + 31);
    v64[12] = *(_BYTE *)(a7 + 32);
    v64[13] = *(_BYTE *)(a7 + 33);
    v64[14] = *(_BYTE *)(a7 + 34);
    v64[15] = *(_BYTE *)(a7 + 35);
    qdf_mem_copy(v64 + 16, a2, 6u);
    v74 = *(unsigned __int16 *)(a1 + 21604);
    if ( v74 <= 0xFFE )
      v75 = v74 + 1;
    else
      v75 = 2048;
    *(_WORD *)(a1 + 21604) = v75;
    *((_WORD *)v64 + 11) = (16 * (v75 & 0xF)) | *((_WORD *)v64 + 11) & 0xFF0F;
    v76 = (unsigned __int8)(*(_WORD *)(a1 + 21604) >> 4);
    *((_WORD *)v64 + 11) = (16 * *(_WORD *)(a1 + 21604)) & 0xFF00 | (16 * (v75 & 0xF));
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "lim_populate_mac_header",
      v75 & 0xF,
      v76,
      *(unsigned __int16 *)(a1 + 21604),
      0);
    v77 = *(unsigned __int8 **)v118;
    qdf_mem_copy((void *)(*(_QWORD *)v118 + 16LL), (const void *)(a7 + 24), 6u);
    lim_set_protected_bit(a1, a7, a2, v77);
    v78 = dot11f_pack_ext_channel_switch_action_frame(a1, v121, *(_QWORD *)v118 + 24LL, v117, &v117);
    if ( (v78 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to pack a Channel Switch 0x%08x",
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        "lim_send_extended_chan_switch_action_frame",
        v78);
      cds_packet_free(v116);
      goto LABEL_28;
    }
    if ( v78 )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: There were warnings while packing a Channel Switch 0x%08x",
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        "lim_send_extended_chan_switch_action_frame");
    if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 284)) && (*(_DWORD *)(a7 + 7036) & 0xFFFFFFFE) != 2 )
    {
      v95 = 0;
      if ( v77 != (unsigned __int8 *)-4LL )
        goto LABEL_26;
    }
    else
    {
      v95 = 64;
      if ( v77 != (unsigned __int8 *)-4LL )
      {
LABEL_26:
        v96 = v77[4];
        v97 = v77[5];
        v98 = v77[6];
        v99 = v77[9];
LABEL_32:
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: ECSA frame to :%02x:%02x:%02x:**:**:%02x count %d mode %d chan %d op class %d",
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          "lim_send_extended_chan_switch_action_frame",
          v96,
          v97,
          v98,
          v99,
          HIBYTE(HIDWORD(v121[0])),
          BYTE4(v121[0]),
          BYTE6(v121[0]),
          BYTE5(v121[0]));
        qdf_trace(53, 2u, *(_WORD *)(a7 + 8), (unsigned __int8)*(_WORD *)v77 >> 4);
        context = _cds_get_context(
                    54,
                    (__int64)"lim_send_extended_chan_switch_action_frame",
                    v101,
                    v102,
                    v103,
                    v104,
                    v105,
                    v106,
                    v107,
                    v108);
        LOBYTE(v114) = v18;
        LOBYTE(v113) = v95;
        LOBYTE(v115) = 0;
        v110 = wma_tx_packet(
                 context,
                 v116,
                 v53 + 24,
                 3,
                 1,
                 7,
                 lim_tx_complete,
                 *(_QWORD *)v118,
                 lim_ecsa_confirm_tx_complete_cnf,
                 v113,
                 v114,
                 v115,
                 0,
                 12,
                 0,
                 1028);
        v111 = *(_WORD *)(a7 + 8);
        v112 = v110;
        qdf_trace(53, 5u, v111, v110);
        if ( !v112 )
        {
          result = 0;
          goto LABEL_29;
        }
        v62 = "%s: Failed to send a Ext Channel Switch %X!";
        v63 = v112;
        goto LABEL_16;
      }
    }
    v98 = 0;
    v96 = 0;
    v97 = 0;
    v99 = 0;
    goto LABEL_32;
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
LABEL_28:
  result = 16;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
