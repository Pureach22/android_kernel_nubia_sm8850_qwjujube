__int64 __fastcall lim_send_channel_usage_req_action_frame(__int64 a1, __int64 a2, unsigned int a3, unsigned __int8 a4)
{
  __int64 result; // x0
  __int64 v9; // x23
  __int64 v10; // x24
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w8
  unsigned int v20; // w6
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w0
  unsigned __int8 v30; // w9
  unsigned __int8 v31; // w10
  unsigned int v32; // w23
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 chanwidth_from_opclass_auto; // x0
  int chwidth_from_bw; // w21
  unsigned int packed_channel_usage_reqSize; // w0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int v60; // w21
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned __int8 *v69; // x22
  char *v70; // x23
  const void *v71; // x23
  char *v72; // x26
  void *v73; // x0
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  unsigned int v82; // w8
  __int16 v83; // w8
  __int64 v84; // x5
  unsigned int v85; // w0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // x6
  __int64 v103; // x7
  int v104; // w8
  int v105; // w9
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  _QWORD *context; // x0
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  int v123; // [xsp+8h] [xbp-268h]
  int v124; // [xsp+10h] [xbp-260h]
  int v125; // [xsp+44h] [xbp-22Ch] BYREF
  int v126[2]; // [xsp+48h] [xbp-228h] BYREF
  __int64 v127; // [xsp+50h] [xbp-220h] BYREF
  unsigned __int8 v128[4]; // [xsp+58h] [xbp-218h] BYREF
  unsigned __int8 v129[4]; // [xsp+5Ch] [xbp-214h] BYREF
  __int16 v130; // [xsp+60h] [xbp-210h] BYREF
  char v131; // [xsp+62h] [xbp-20Eh]
  unsigned int s[129]; // [xsp+64h] [xbp-20Ch] BYREF
  __int64 v133; // [xsp+268h] [xbp-8h]

  v133 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v127 = 0;
  result = (__int64)memset(s, 0, sizeof(s));
  if ( *(_DWORD *)(a2 + 7036) != 2 )
    goto LABEL_43;
  if ( (*(_BYTE *)(a2 + 10080) & 2) != 0 )
    goto LABEL_43;
  v9 = *(_QWORD *)(*(_QWORD *)(a2 + 16) + 152LL);
  if ( !v9 )
    goto LABEL_43;
  v10 = *(_QWORD *)(v9 + 80);
  if ( !v10 )
    goto LABEL_43;
  v129[0] = 0;
  v128[0] = 0;
  *(_QWORD *)v126 = 0;
  v130 = 0;
  v131 = 0;
  v125 = 0;
  qdf_mem_set((void *)(a2 + 10096), 0x1B4u, 0);
  v19 = *(unsigned __int8 *)(a2 + 10077);
  v20 = *(unsigned __int8 *)(a2 + 10);
  *(_WORD *)(a2 + 10096) = 5386;
  if ( v19 <= 1 )
    LOBYTE(v19) = 1;
  *(_BYTE *)(a2 + 10098) = v19;
  *(_WORD *)(a2 + 10099) = 1025;
  *(_BYTE *)(a2 + 10077) = v19 + 1;
  policy_mgr_get_pcl_for_vdev_id(
    v10,
    2u,
    (__int64)s,
    &s[128],
    (__int64)&s[102],
    0x66u,
    v20,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18);
  if ( (_BYTE)a3 && a4 )
  {
    *(_BYTE *)(a2 + 10102) = a4;
    *(_BYTE *)(a2 + 10101) = 2;
    *(_BYTE *)(a2 + 10103) = a3;
    if ( wlan_reg_is_6ghz_op_class(v9, a4) )
      v29 = wlan_reg_chan_band_to_freq(v9, a3, 4u, v21, v22, v23, v24, v25, v26, v27, v28);
    else
      v29 = wlan_reg_legacy_chan_to_freq(v9, a3, v21, v22, v23, v24, v25, v26, v27, v28);
    v32 = v29;
    v129[0] = a4;
    v128[0] = a3;
LABEL_15:
    populate_dot11_supp_operating_classes(a1, a2 + 10356, a2);
    if ( v32 )
    {
      wlan_reg_read_current_country(*(_QWORD *)(a1 + 21552), &v130, v33, v34, v35, v36, v37, v38, v39, v40);
      chanwidth_from_opclass_auto = wlan_reg_dmn_get_chanwidth_from_opclass_auto(
                                      (unsigned __int8 *)&v130,
                                      v128[0],
                                      v129[0],
                                      v41,
                                      v42,
                                      v43,
                                      v44,
                                      v45,
                                      v46,
                                      v47,
                                      v48);
      chwidth_from_bw = wlan_reg_find_chwidth_from_bw(chanwidth_from_opclass_auto);
      populate_dot11f_ht_caps(a1, a2, a2 + 10408);
      if ( wlan_reg_is_5ghz_ch_freq(v32)
        || wlan_reg_is_24ghz_ch_freq(v32) && *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2671LL) == 1 )
      {
        populate_dot11f_vht_caps(a1, 0, a2 + 10392);
      }
      if ( *(_BYTE *)(a2 + 8676) == 1 )
      {
        populate_dot11f_he_caps(a1, 0, *(_DWORD *)(a2 + 7036), v32, chwidth_from_bw, a2 + 10468);
        if ( wlan_reg_is_6ghz_chan_freq(v32) )
          populate_dot11f_he_6ghz_cap(a1, 0, a2 + 10528);
      }
    }
    goto LABEL_24;
  }
  if ( s[128] )
  {
    wlan_reg_freq_to_chan_op_class(v9, s[0], 1, 1u, (__int64)v129, (__int64)v128);
    v30 = v129[0];
    v31 = v128[0];
    v32 = s[0];
    *(_BYTE *)(a2 + 10101) = 2;
    *(_BYTE *)(a2 + 10102) = v30;
    *(_BYTE *)(a2 + 10103) = v31;
    goto LABEL_15;
  }
  populate_dot11_supp_operating_classes(a1, a2 + 10356, a2);
LABEL_24:
  packed_channel_usage_reqSize = dot11f_get_packed_channel_usage_reqSize(a1, a2 + 10096, &v125);
  if ( (packed_channel_usage_reqSize & 0x10000000) != 0 )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Failed to calculate the packed size(0x%08x)",
               v52,
               v53,
               v54,
               v55,
               v56,
               v57,
               v58,
               v59,
               "lim_send_channel_usage_req_action_frame",
               packed_channel_usage_reqSize);
  }
  else
  {
    if ( packed_channel_usage_reqSize )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Warnings in calculating the packed size(0x%08x)",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "lim_send_channel_usage_req_action_frame");
    v60 = v125 + 24;
    if ( (unsigned int)cds_packet_alloc((unsigned __int16)v125 + 24, v126, &v127) || !v127 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: Failed to allocate %d bytes",
                 v61,
                 v62,
                 v63,
                 v64,
                 v65,
                 v66,
                 v67,
                 v68,
                 "lim_send_channel_usage_req_action_frame",
                 v60);
    }
    else
    {
      qdf_mem_set(*(void **)v126, v60, 0);
      v69 = *(unsigned __int8 **)v126;
      v70 = *(char **)v126;
      *(_BYTE *)(*(_QWORD *)v126 + 16LL) = *(_BYTE *)(a2 + 24);
      v71 = v70 + 16;
      v69[17] = *(_BYTE *)(a2 + 25);
      v69[18] = *(_BYTE *)(a2 + 26);
      v69[19] = *(_BYTE *)(a2 + 27);
      v69[20] = *(_BYTE *)(a2 + 28);
      v69[21] = *(_BYTE *)(a2 + 29);
      v72 = *(char **)v126;
      v73 = (void *)(*(_QWORD *)v126 + 4LL);
      **(_BYTE **)v126 = -48;
      qdf_mem_copy(v73, v71, 6u);
      v72[10] = *(_BYTE *)(a2 + 30);
      v72[11] = *(_BYTE *)(a2 + 31);
      v72[12] = *(_BYTE *)(a2 + 32);
      v72[13] = *(_BYTE *)(a2 + 33);
      v72[14] = *(_BYTE *)(a2 + 34);
      v72[15] = *(_BYTE *)(a2 + 35);
      qdf_mem_copy(v72 + 16, v71, 6u);
      v82 = *(unsigned __int16 *)(a1 + 21532);
      if ( v82 <= 0xFFE )
        v83 = v82 + 1;
      else
        v83 = 2048;
      *(_WORD *)(a1 + 21532) = v83;
      *((_WORD *)v72 + 11) = (16 * (v83 & 0xF)) | *((_WORD *)v72 + 11) & 0xFF0F;
      v84 = (unsigned __int8)(*(_WORD *)(a1 + 21532) >> 4);
      *((_WORD *)v72 + 11) = (16 * *(_WORD *)(a1 + 21532)) & 0xFF00 | (16 * (v83 & 0xF));
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        "lim_populate_mac_header",
        v83 & 0xF,
        v84,
        *(unsigned __int16 *)(a1 + 21532),
        0);
      lim_set_protected_bit(a1, a2, v71, v69);
      v85 = dot11f_pack_channel_usage_req(a1, a2 + 10096, *(_QWORD *)v126 + 24LL, v60, &v125);
      if ( (v85 & 0x10000000) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Failed to pack frame(0x%08x)",
          v86,
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          "lim_send_channel_usage_req_action_frame",
          v85);
        result = cds_packet_free(v127);
      }
      else
      {
        if ( v85 )
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: Warnings in packing frame0x%08x)",
            v86,
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            v93,
            "lim_send_channel_usage_req_action_frame");
        tx_timer_deactivate(a1 + 3720);
        if ( v71 )
        {
          v102 = v69[16];
          v103 = v69[17];
          v104 = v69[18];
          v105 = v69[21];
        }
        else
        {
          v104 = 0;
          v102 = 0;
          v103 = 0;
          v105 = 0;
        }
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: vdev %d seq num %d to %02x:%02x:%02x:**:**:%02x len %d",
          v94,
          v95,
          v96,
          v97,
          v98,
          v99,
          v100,
          v101,
          "lim_send_channel_usage_req_action_frame",
          *(unsigned __int8 *)(a2 + 10),
          *(unsigned __int16 *)(a1 + 21532),
          v102,
          v103,
          v104,
          v105,
          v60);
        context = _cds_get_context(
                    54,
                    (__int64)"lim_send_channel_usage_req_action_frame",
                    v106,
                    v107,
                    v108,
                    v109,
                    v110,
                    v111,
                    v112,
                    v113);
        LOBYTE(v124) = *(_BYTE *)(a2 + 10);
        LOBYTE(v123) = 64;
        result = wma_tx_packet(
                   context,
                   v127,
                   v60,
                   3,
                   1,
                   7,
                   lim_tx_complete,
                   *(_QWORD *)v126,
                   lim_chan_usage_req_tx_complete_cnf_handler,
                   v123,
                   v124,
                   0,
                   0,
                   12,
                   0,
                   0);
        if ( (_DWORD)result )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Failed to send chan usage req frame(0x%x)!",
            v115,
            v116,
            v117,
            v118,
            v119,
            v120,
            v121,
            v122,
            "lim_send_channel_usage_req_action_frame",
            (unsigned int)result);
          cds_packet_free(v127);
          result = lim_timer_handler(a1, 5120);
        }
      }
    }
  }
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
