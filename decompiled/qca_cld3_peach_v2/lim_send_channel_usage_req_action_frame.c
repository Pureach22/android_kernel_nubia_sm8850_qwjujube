__int64 __fastcall lim_send_channel_usage_req_action_frame(__int64 a1, __int64 a2, unsigned int a3, unsigned __int8 a4)
{
  __int64 result; // x0
  _BYTE *v9; // x26
  __int64 v10; // x23
  __int64 v11; // x24
  unsigned int v12; // w8
  __int64 v13; // x6
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w0
  unsigned __int8 v23; // w9
  unsigned __int8 v24; // w10
  unsigned int v25; // w23
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 chanwidth_from_opclass_auto; // x0
  int chwidth_from_bw; // w21
  unsigned int packed_channel_usage_reqSize; // w0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w21
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned __int8 *v62; // x22
  char *v63; // x23
  const void *v64; // x23
  char *v65; // x26
  void *v66; // x0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  unsigned int v75; // w8
  __int16 v76; // w8
  __int64 v77; // x5
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
  __int64 v95; // x6
  __int64 v96; // x7
  int v97; // w8
  int v98; // w9
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  _QWORD *context; // x0
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  int v116; // [xsp+8h] [xbp-268h]
  int v117; // [xsp+10h] [xbp-260h]
  int v118; // [xsp+44h] [xbp-22Ch] BYREF
  int v119[2]; // [xsp+48h] [xbp-228h] BYREF
  __int64 v120; // [xsp+50h] [xbp-220h] BYREF
  unsigned __int8 v121[4]; // [xsp+58h] [xbp-218h] BYREF
  unsigned __int8 v122[4]; // [xsp+5Ch] [xbp-214h] BYREF
  __int16 v123; // [xsp+60h] [xbp-210h] BYREF
  char v124; // [xsp+62h] [xbp-20Eh]
  unsigned int s[129]; // [xsp+64h] [xbp-20Ch] BYREF
  __int64 v126; // [xsp+268h] [xbp-8h]

  v126 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v120 = 0;
  result = (__int64)memset(s, 0, sizeof(s));
  if ( *(_DWORD *)(a2 + 7036) != 2 )
    goto LABEL_43;
  v9 = (_BYTE *)(a2 + 13286);
  if ( (*(_BYTE *)(a2 + 13288) & 2) != 0 )
    goto LABEL_43;
  v10 = *(_QWORD *)(*(_QWORD *)(a2 + 16) + 216LL);
  if ( !v10 )
    goto LABEL_43;
  v11 = *(_QWORD *)(v10 + 80);
  if ( !v11 )
    goto LABEL_43;
  v122[0] = 0;
  v121[0] = 0;
  *(_QWORD *)v119 = 0;
  v123 = 0;
  v124 = 0;
  v118 = 0;
  qdf_mem_set((void *)(a2 + 13304), 0x1B4u, 0);
  v12 = (unsigned __int8)*v9;
  v13 = *(unsigned __int8 *)(a2 + 10);
  *(_WORD *)(a2 + 13304) = 5386;
  if ( v12 <= 1 )
    LOBYTE(v12) = 1;
  *(_BYTE *)(a2 + 13306) = v12;
  *(_WORD *)(a2 + 13307) = 1025;
  *v9 = v12 + 1;
  ((void (__fastcall *)(__int64, __int64, unsigned int *, unsigned int *, unsigned int *, __int64, __int64))policy_mgr_get_pcl_for_vdev_id)(
    v11,
    2,
    s,
    &s[128],
    &s[102],
    102,
    v13);
  if ( (_BYTE)a3 && a4 )
  {
    *(_BYTE *)(a2 + 13310) = a4;
    *(_BYTE *)(a2 + 13309) = 2;
    *(_BYTE *)(a2 + 13311) = a3;
    if ( wlan_reg_is_6ghz_op_class(v10, a4) )
      v22 = wlan_reg_chan_band_to_freq(v10, a3, 4u, v14, v15, v16, v17, v18, v19, v20, v21);
    else
      v22 = wlan_reg_legacy_chan_to_freq(v10, a3, v14, v15, v16, v17, v18, v19, v20, v21);
    v25 = v22;
    v122[0] = a4;
    v121[0] = a3;
LABEL_15:
    populate_dot11_supp_operating_classes(a1, a2 + 13564, a2);
    if ( v25 )
    {
      wlan_reg_read_current_country(*(_QWORD *)(a1 + 21624), &v123, v26, v27, v28, v29, v30, v31, v32, v33);
      chanwidth_from_opclass_auto = wlan_reg_dmn_get_chanwidth_from_opclass_auto(
                                      (unsigned __int8 *)&v123,
                                      v121[0],
                                      v122[0],
                                      v34,
                                      v35,
                                      v36,
                                      v37,
                                      v38,
                                      v39,
                                      v40,
                                      v41);
      chwidth_from_bw = wlan_reg_find_chwidth_from_bw(chanwidth_from_opclass_auto);
      populate_dot11f_ht_caps(a1, a2, a2 + 13616);
      if ( wlan_reg_is_5ghz_ch_freq(v25)
        || wlan_reg_is_24ghz_ch_freq(v25) && *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2875LL) == 1 )
      {
        populate_dot11f_vht_caps(a1, 0, a2 + 13600);
      }
      if ( *(_BYTE *)(a2 + 8676) == 1 )
      {
        populate_dot11f_he_caps(a1, 0, *(_DWORD *)(a2 + 7036), v25, chwidth_from_bw, a2 + 13676);
        if ( wlan_reg_is_6ghz_chan_freq(v25) )
          populate_dot11f_he_6ghz_cap(a1, 0, a2 + 13736);
      }
    }
    goto LABEL_24;
  }
  if ( s[128] )
  {
    wlan_reg_freq_to_chan_op_class(v10, s[0], 1, 1u, (__int64)v122, (__int64)v121);
    v23 = v122[0];
    v24 = v121[0];
    v25 = s[0];
    *(_BYTE *)(a2 + 13309) = 2;
    *(_BYTE *)(a2 + 13310) = v23;
    *(_BYTE *)(a2 + 13311) = v24;
    goto LABEL_15;
  }
  populate_dot11_supp_operating_classes(a1, a2 + 13564, a2);
LABEL_24:
  packed_channel_usage_reqSize = dot11f_get_packed_channel_usage_reqSize(a1, a2 + 13304, &v118);
  if ( (packed_channel_usage_reqSize & 0x10000000) != 0 )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Failed to calculate the packed size(0x%08x)",
               v45,
               v46,
               v47,
               v48,
               v49,
               v50,
               v51,
               v52,
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
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "lim_send_channel_usage_req_action_frame");
    v53 = v118 + 24;
    if ( (unsigned int)cds_packet_alloc((unsigned __int16)v118 + 24, v119, &v120) || !v120 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: Failed to allocate %d bytes",
                 v54,
                 v55,
                 v56,
                 v57,
                 v58,
                 v59,
                 v60,
                 v61,
                 "lim_send_channel_usage_req_action_frame",
                 v53);
    }
    else
    {
      qdf_mem_set(*(void **)v119, v53, 0);
      v62 = *(unsigned __int8 **)v119;
      v63 = *(char **)v119;
      *(_BYTE *)(*(_QWORD *)v119 + 16LL) = *(_BYTE *)(a2 + 24);
      v64 = v63 + 16;
      v62[17] = *(_BYTE *)(a2 + 25);
      v62[18] = *(_BYTE *)(a2 + 26);
      v62[19] = *(_BYTE *)(a2 + 27);
      v62[20] = *(_BYTE *)(a2 + 28);
      v62[21] = *(_BYTE *)(a2 + 29);
      v65 = *(char **)v119;
      v66 = (void *)(*(_QWORD *)v119 + 4LL);
      **(_BYTE **)v119 = -48;
      qdf_mem_copy(v66, v64, 6u);
      v65[10] = *(_BYTE *)(a2 + 30);
      v65[11] = *(_BYTE *)(a2 + 31);
      v65[12] = *(_BYTE *)(a2 + 32);
      v65[13] = *(_BYTE *)(a2 + 33);
      v65[14] = *(_BYTE *)(a2 + 34);
      v65[15] = *(_BYTE *)(a2 + 35);
      qdf_mem_copy(v65 + 16, v64, 6u);
      v75 = *(unsigned __int16 *)(a1 + 21604);
      if ( v75 <= 0xFFE )
        v76 = v75 + 1;
      else
        v76 = 2048;
      *(_WORD *)(a1 + 21604) = v76;
      *((_WORD *)v65 + 11) = (16 * (v76 & 0xF)) | *((_WORD *)v65 + 11) & 0xFF0F;
      v77 = (unsigned __int8)(*(_WORD *)(a1 + 21604) >> 4);
      *((_WORD *)v65 + 11) = (16 * *(_WORD *)(a1 + 21604)) & 0xFF00 | (16 * (v76 & 0xF));
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        "lim_populate_mac_header",
        v76 & 0xF,
        v77,
        *(unsigned __int16 *)(a1 + 21604),
        0);
      lim_set_protected_bit(a1, a2, v64, v62);
      v78 = dot11f_pack_channel_usage_req(a1, a2 + 13304, *(_QWORD *)v119 + 24LL, v53, &v118);
      if ( (v78 & 0x10000000) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Failed to pack frame(0x%08x)",
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          "lim_send_channel_usage_req_action_frame",
          v78);
        result = cds_packet_free(v120);
      }
      else
      {
        if ( v78 )
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: Warnings in packing frame0x%08x)",
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            v86,
            "lim_send_channel_usage_req_action_frame");
        tx_timer_deactivate(a1 + 3720);
        if ( v64 )
        {
          v95 = v62[16];
          v96 = v62[17];
          v97 = v62[18];
          v98 = v62[21];
        }
        else
        {
          v97 = 0;
          v95 = 0;
          v96 = 0;
          v98 = 0;
        }
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: vdev %d seq num %d to %02x:%02x:%02x:**:**:%02x len %d",
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          "lim_send_channel_usage_req_action_frame",
          *(unsigned __int8 *)(a2 + 10),
          *(unsigned __int16 *)(a1 + 21604),
          v95,
          v96,
          v97,
          v98,
          v53);
        context = _cds_get_context(
                    54,
                    (__int64)"lim_send_channel_usage_req_action_frame",
                    v99,
                    v100,
                    v101,
                    v102,
                    v103,
                    v104,
                    v105,
                    v106);
        LOBYTE(v117) = *(_BYTE *)(a2 + 10);
        LOBYTE(v116) = 64;
        result = wma_tx_packet(
                   context,
                   v120,
                   v53,
                   3,
                   1,
                   7,
                   lim_tx_complete,
                   *(_QWORD *)v119,
                   lim_chan_usage_req_tx_complete_cnf_handler,
                   v116,
                   v117,
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
            v108,
            v109,
            v110,
            v111,
            v112,
            v113,
            v114,
            v115,
            "lim_send_channel_usage_req_action_frame",
            (unsigned int)result);
          cds_packet_free(v120);
          result = lim_timer_handler(a1, 5120);
        }
      }
    }
  }
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
