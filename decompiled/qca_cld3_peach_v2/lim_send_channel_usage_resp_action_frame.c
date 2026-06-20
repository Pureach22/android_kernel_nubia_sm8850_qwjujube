__int64 __fastcall lim_send_channel_usage_resp_action_frame(__int64 a1, __int64 a2, const void *a3)
{
  __int64 result; // x0
  char v7; // w9
  char v8; // w8
  __int64 v9; // x6
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned __int64 v18; // x26
  __int64 v19; // x22
  __int64 v20; // x25
  int v21; // w8
  __int64 v22; // x25
  char v23; // w9
  char v24; // w10
  unsigned int packed_channel_usage_respSize; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w22
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  _BYTE *v43; // x3
  unsigned int v44; // w0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  _QWORD *context; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  int v70; // w9
  _BYTE v71[4]; // [xsp+4Ch] [xbp-234h] BYREF
  _BYTE v72[4]; // [xsp+50h] [xbp-230h] BYREF
  unsigned int v73; // [xsp+54h] [xbp-22Ch] BYREF
  int v74[2]; // [xsp+58h] [xbp-228h] BYREF
  __int64 v75; // [xsp+60h] [xbp-220h] BYREF
  __int16 v76; // [xsp+68h] [xbp-218h] BYREF
  char v77; // [xsp+6Ah] [xbp-216h]
  unsigned int s[129]; // [xsp+6Ch] [xbp-214h] BYREF
  __int64 v79; // [xsp+270h] [xbp-10h]

  v79 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v75 = 0;
  result = (__int64)memset(s, 0, sizeof(s));
  if ( *(_DWORD *)(a2 + 7036) != 3 )
    goto LABEL_36;
  if ( (*(_BYTE *)(a2 + 13288) & 2) == 0 )
    goto LABEL_36;
  if ( (*(_BYTE *)(a2 + 13309) & 1) != 0 )
    goto LABEL_36;
  v77 = 0;
  v76 = 0;
  *(_QWORD *)v74 = 0;
  v73 = 0;
  v72[0] = 0;
  v71[0] = 0;
  qdf_mem_set((void *)(a2 + 13740), 0x104u, 0);
  v7 = *(_BYTE *)(a2 + 13306);
  *(_WORD *)(a2 + 13740) = 5642;
  v8 = *(_BYTE *)(a2 + 13308);
  v9 = *(unsigned __int8 *)(a2 + 10);
  *(_BYTE *)(a2 + 13743) = 1;
  *(_BYTE *)(a2 + 13742) = v7;
  *(_BYTE *)(a2 + 13744) = v8;
  result = ((__int64 (__fastcall *)(_QWORD, __int64, unsigned int *, unsigned int *, unsigned int *, __int64, __int64))policy_mgr_get_pcl_for_vdev_id)(
             *(_QWORD *)(a1 + 21624),
             3,
             s,
             &s[128],
             &s[102],
             102,
             v9);
  if ( !s[128] )
    goto LABEL_36;
  if ( !*(_BYTE *)(a2 + 13309) )
  {
LABEL_20:
    wlan_reg_read_current_country(*(_QWORD *)(a1 + 21624), &v76, v10, v11, v12, v13, v14, v15, v16, v17);
    v77 = 4;
    goto LABEL_21;
  }
  v18 = 0;
  v19 = a2 + 13310;
  while ( 1 )
  {
    if ( v18 >= 0xFD )
      goto LABEL_37;
    v21 = (unsigned __int16)wlan_reg_chan_opclass_to_freq(
                              *(_BYTE *)(v19 + v18 + 1),
                              *(_BYTE *)(v19 + v18),
                              1,
                              v10,
                              v11,
                              v12,
                              v13,
                              v14,
                              v15,
                              v16,
                              v17);
    if ( !v21 )
    {
      v20 = jiffies;
      if ( lim_send_channel_usage_resp_action_frame___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Invalid op_class %d",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "lim_send_channel_usage_resp_action_frame",
          *(unsigned __int8 *)(v19 + v18));
        lim_send_channel_usage_resp_action_frame___last_ticks = v20;
      }
      goto LABEL_9;
    }
    if ( s[128] )
      break;
LABEL_9:
    v18 += 2LL;
    if ( *(unsigned __int8 *)(a2 + 13309) <= (unsigned int)(unsigned __int8)v18 )
      goto LABEL_20;
  }
  v22 = 0;
  while ( 1 )
  {
    if ( v22 == 102 )
      goto LABEL_37;
    if ( s[v22] == v21 )
      break;
    if ( s[128] == ++v22 )
      goto LABEL_9;
  }
  wlan_reg_read_current_country(*(_QWORD *)(a1 + 21624), &v76, v10, v11, v12, v13, v14, v15, v16, v17);
  v77 = 4;
  if ( (unsigned __int8)v22 > 0x65u )
LABEL_37:
    __break(0x5512u);
  wlan_reg_freq_to_chan_op_class(*(_QWORD *)(*(_QWORD *)(a2 + 16) + 216LL), s[v22], 1, 1u, (__int64)v72, (__int64)v71);
  v23 = v72[0];
  v24 = v71[0];
  *(_BYTE *)(a2 + 13745) = 2;
  *(_BYTE *)(a2 + 13746) = v23;
  *(_BYTE *)(a2 + 13747) = v24;
LABEL_21:
  packed_channel_usage_respSize = dot11f_get_packed_channel_usage_respSize(a1, a2 + 13740, &v73);
  if ( (packed_channel_usage_respSize & 0x10000000) != 0 )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Failed to calculate the packed size(0x%08x)",
               v26,
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               v33,
               "lim_send_channel_usage_resp_action_frame",
               packed_channel_usage_respSize);
  }
  else
  {
    if ( packed_channel_usage_respSize )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Warnings in calculating the packed size(0x%08x)",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "lim_send_channel_usage_resp_action_frame");
    v34 = v73;
    if ( (unsigned int)cds_packet_alloc((unsigned __int16)v73 + 27, v74, &v75) || !v75 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: Failed to allocate %d bytes",
                 v35,
                 v36,
                 v37,
                 v38,
                 v39,
                 v40,
                 v41,
                 v42,
                 "lim_send_channel_usage_resp_action_frame",
                 v34 + 27);
    }
    else
    {
      qdf_mem_set(*(void **)v74, v34 + 27, 0);
      lim_populate_mac_header(a1, *(__int64 *)v74, 0, 13, a3, (_BYTE *)(a2 + 30));
      v43 = *(_BYTE **)v74;
      *(_BYTE *)(*(_QWORD *)v74 + 16LL) = *(_BYTE *)(a2 + 24);
      v43[17] = *(_BYTE *)(a2 + 25);
      v43[18] = *(_BYTE *)(a2 + 26);
      v43[19] = *(_BYTE *)(a2 + 27);
      v43[20] = *(_BYTE *)(a2 + 28);
      v43[21] = *(_BYTE *)(a2 + 29);
      lim_set_protected_bit(a1, a2, a3, v43);
      v44 = dot11f_pack_channel_usage_resp(a1, a2 + 13740, *(_QWORD *)v74 + 24LL, v34 + 27, &v73);
      if ( (v44 & 0x10000000) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Failed to pack frame(0x%08x)",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "lim_send_channel_usage_resp_action_frame",
          v44);
        result = cds_packet_free(v75);
      }
      else
      {
        if ( v44 )
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: Warnings in packing frame0x%08x)",
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            "lim_send_channel_usage_resp_action_frame");
        qdf_mem_copy((void *)(*(_QWORD *)v74 + v73 + 24LL), &v76, 3u);
        v53 = ((double (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(
                53,
                8,
                *(_QWORD *)v74,
                v34 + 27);
        context = _cds_get_context(
                    54,
                    (__int64)"lim_send_channel_usage_resp_action_frame",
                    v53,
                    v54,
                    v55,
                    v56,
                    v57,
                    v58,
                    v59,
                    v60);
        result = wma_tx_packet(
                   context,
                   v75,
                   v34 + 27,
                   3,
                   2,
                   7,
                   lim_tx_complete,
                   *(_QWORD *)v74,
                   0,
                   64,
                   *(_BYTE *)(a2 + 10),
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
            "%s: Failed to send chan usage resp frame(0x%x)!",
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            "lim_send_channel_usage_resp_action_frame",
            (unsigned int)result);
          result = cds_packet_free(v75);
        }
        v70 = *(unsigned __int8 *)(a2 + 13745);
        *(_BYTE *)(a2 + 13288) &= ~2u;
        if ( v70 )
          result = policy_mgr_change_sap_channel_with_csa(
                     *(_QWORD *)(a1 + 21624),
                     *(unsigned __int8 *)(a2 + 10),
                     s[0],
                     9u,
                     1);
      }
    }
  }
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
