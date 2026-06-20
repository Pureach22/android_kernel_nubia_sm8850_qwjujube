__int64 __fastcall lim_send_channel_usage_resp_action_frame(__int64 a1, __int64 a2, const void *a3)
{
  __int64 result; // x0
  char v7; // w9
  char v8; // w8
  unsigned int v9; // w6
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned __int64 v26; // x26
  __int64 v27; // x22
  __int64 v28; // x25
  int v29; // w8
  __int64 v30; // x25
  char v31; // w9
  char v32; // w10
  unsigned int packed_channel_usage_respSize; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w22
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  _BYTE *v51; // x3
  unsigned int v52; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  _QWORD *context; // x0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  int v78; // w9
  _BYTE v79[4]; // [xsp+4Ch] [xbp-234h] BYREF
  _BYTE v80[4]; // [xsp+50h] [xbp-230h] BYREF
  unsigned int v81; // [xsp+54h] [xbp-22Ch] BYREF
  int v82[2]; // [xsp+58h] [xbp-228h] BYREF
  __int64 v83; // [xsp+60h] [xbp-220h] BYREF
  __int16 v84; // [xsp+68h] [xbp-218h] BYREF
  char v85; // [xsp+6Ah] [xbp-216h]
  unsigned int s[129]; // [xsp+6Ch] [xbp-214h] BYREF
  __int64 v87; // [xsp+270h] [xbp-10h]

  v87 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v83 = 0;
  result = (__int64)memset(s, 0, sizeof(s));
  if ( *(_DWORD *)(a2 + 7036) != 3 )
    goto LABEL_36;
  if ( (*(_BYTE *)(a2 + 10080) & 2) == 0 )
    goto LABEL_36;
  if ( (*(_BYTE *)(a2 + 10101) & 1) != 0 )
    goto LABEL_36;
  v85 = 0;
  v84 = 0;
  *(_QWORD *)v82 = 0;
  v81 = 0;
  v80[0] = 0;
  v79[0] = 0;
  qdf_mem_set((void *)(a2 + 10532), 0x104u, 0);
  v7 = *(_BYTE *)(a2 + 10098);
  *(_WORD *)(a2 + 10532) = 5642;
  v8 = *(_BYTE *)(a2 + 10100);
  v9 = *(unsigned __int8 *)(a2 + 10);
  *(_BYTE *)(a2 + 10535) = 1;
  *(_BYTE *)(a2 + 10534) = v7;
  *(_BYTE *)(a2 + 10536) = v8;
  result = policy_mgr_get_pcl_for_vdev_id(
             *(_QWORD *)(a1 + 21552),
             3u,
             (__int64)s,
             &s[128],
             (__int64)&s[102],
             0x66u,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17);
  if ( !s[128] )
    goto LABEL_36;
  if ( !*(_BYTE *)(a2 + 10101) )
  {
LABEL_20:
    wlan_reg_read_current_country(*(_QWORD *)(a1 + 21552), &v84, v18, v19, v20, v21, v22, v23, v24, v25);
    v85 = 4;
    goto LABEL_21;
  }
  v26 = 0;
  v27 = a2 + 10102;
  while ( 1 )
  {
    if ( v26 >= 0xFD )
      goto LABEL_37;
    v29 = (unsigned __int16)wlan_reg_chan_opclass_to_freq(
                              *(_BYTE *)(v27 + v26 + 1),
                              *(_BYTE *)(v27 + v26),
                              1,
                              v18,
                              v19,
                              v20,
                              v21,
                              v22,
                              v23,
                              v24,
                              v25);
    if ( !v29 )
    {
      v28 = jiffies;
      if ( lim_send_channel_usage_resp_action_frame___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Invalid op_class %d",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "lim_send_channel_usage_resp_action_frame",
          *(unsigned __int8 *)(v27 + v26));
        lim_send_channel_usage_resp_action_frame___last_ticks = v28;
      }
      goto LABEL_9;
    }
    if ( s[128] )
      break;
LABEL_9:
    v26 += 2LL;
    if ( *(unsigned __int8 *)(a2 + 10101) <= (unsigned int)(unsigned __int8)v26 )
      goto LABEL_20;
  }
  v30 = 0;
  while ( 1 )
  {
    if ( v30 == 102 )
      goto LABEL_37;
    if ( s[v30] == v29 )
      break;
    if ( s[128] == ++v30 )
      goto LABEL_9;
  }
  wlan_reg_read_current_country(*(_QWORD *)(a1 + 21552), &v84, v18, v19, v20, v21, v22, v23, v24, v25);
  v85 = 4;
  if ( (unsigned __int8)v30 > 0x65u )
LABEL_37:
    __break(0x5512u);
  wlan_reg_freq_to_chan_op_class(*(_QWORD *)(*(_QWORD *)(a2 + 16) + 152LL), s[v30], 1, 1u, (__int64)v80, (__int64)v79);
  v31 = v80[0];
  v32 = v79[0];
  *(_BYTE *)(a2 + 10537) = 2;
  *(_BYTE *)(a2 + 10538) = v31;
  *(_BYTE *)(a2 + 10539) = v32;
LABEL_21:
  packed_channel_usage_respSize = dot11f_get_packed_channel_usage_respSize(a1, a2 + 10532, &v81);
  if ( (packed_channel_usage_respSize & 0x10000000) != 0 )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Failed to calculate the packed size(0x%08x)",
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               v40,
               v41,
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
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "lim_send_channel_usage_resp_action_frame");
    v42 = v81;
    if ( (unsigned int)cds_packet_alloc((unsigned __int16)v81 + 27, v82, &v83) || !v83 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: Failed to allocate %d bytes",
                 v43,
                 v44,
                 v45,
                 v46,
                 v47,
                 v48,
                 v49,
                 v50,
                 "lim_send_channel_usage_resp_action_frame",
                 v42 + 27);
    }
    else
    {
      qdf_mem_set(*(void **)v82, v42 + 27, 0);
      lim_populate_mac_header(a1, *(__int64 *)v82, 0, 13, a3, (_BYTE *)(a2 + 30));
      v51 = *(_BYTE **)v82;
      *(_BYTE *)(*(_QWORD *)v82 + 16LL) = *(_BYTE *)(a2 + 24);
      v51[17] = *(_BYTE *)(a2 + 25);
      v51[18] = *(_BYTE *)(a2 + 26);
      v51[19] = *(_BYTE *)(a2 + 27);
      v51[20] = *(_BYTE *)(a2 + 28);
      v51[21] = *(_BYTE *)(a2 + 29);
      lim_set_protected_bit(a1, a2, a3, v51);
      v52 = dot11f_pack_channel_usage_resp(a1, a2 + 10532, *(_QWORD *)v82 + 24LL, v42 + 27, &v81);
      if ( (v52 & 0x10000000) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Failed to pack frame(0x%08x)",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "lim_send_channel_usage_resp_action_frame",
          v52);
        result = cds_packet_free(v83);
      }
      else
      {
        if ( v52 )
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: Warnings in packing frame0x%08x)",
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            "lim_send_channel_usage_resp_action_frame");
        qdf_mem_copy((void *)(*(_QWORD *)v82 + v81 + 24LL), &v84, 3u);
        v61 = ((double (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(
                53,
                8,
                *(_QWORD *)v82,
                v42 + 27);
        context = _cds_get_context(
                    54,
                    (__int64)"lim_send_channel_usage_resp_action_frame",
                    v61,
                    v62,
                    v63,
                    v64,
                    v65,
                    v66,
                    v67,
                    v68);
        result = wma_tx_packet(
                   context,
                   v83,
                   v42 + 27,
                   3,
                   2,
                   7,
                   lim_tx_complete,
                   *(_QWORD *)v82,
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
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            "lim_send_channel_usage_resp_action_frame",
            (unsigned int)result);
          result = cds_packet_free(v83);
        }
        v78 = *(unsigned __int8 *)(a2 + 10537);
        *(_BYTE *)(a2 + 10080) &= ~2u;
        if ( v78 )
          result = policy_mgr_change_sap_channel_with_csa(
                     *(_QWORD *)(a1 + 21552),
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
