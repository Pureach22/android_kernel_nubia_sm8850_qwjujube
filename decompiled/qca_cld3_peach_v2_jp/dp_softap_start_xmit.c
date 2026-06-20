__int64 __fastcall dp_softap_start_xmit(__int64 a1, __int64 a2)
{
  __int64 *v4; // x19
  __int64 v5; // x26
  __int64 context; // x0
  unsigned __int64 StatusReg; // x27
  unsigned int v8; // w8
  __int64 *v9; // x23
  __int64 v10; // x22
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int *v19; // x25
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w8
  __int64 v30; // x24
  __int64 v31; // x25
  __int64 v32; // x8
  unsigned int v33; // w8
  void (__fastcall *v34)(_QWORD); // x8
  int v35; // w8
  int v36; // w9
  __int64 v37; // x8
  void (*v38)(void); // x8
  __int64 v39; // x8
  unsigned int tso_num_seg; // w0
  _QWORD *v41; // x8
  __int64 v42; // x9
  char v43; // w8
  bool is_ipv4_pkt; // w8
  __int64 v45; // x0
  char ipv4_tos; // w0
  char ipv6_tc; // w0
  __int64 v48; // x6
  __int64 v49; // x7
  __int64 v50; // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 (__fastcall *v59)(__int64, __int64, __int64); // x8
  __int64 v60; // x1
  __int64 result; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x22
  __int64 v71; // x4
  __int64 v72; // x5
  __int64 v73; // x6
  __int64 v74; // x7
  __int64 v75; // x22
  __int64 v76; // x22
  __int64 v77; // x22
  __int64 v78; // x22
  unsigned __int8 *v79; // [xsp+8h] [xbp-38h]
  __int64 v80; // [xsp+10h] [xbp-30h]
  __int64 v81; // [xsp+18h] [xbp-28h]
  __int64 v82; // [xsp+20h] [xbp-20h]
  int v83; // [xsp+28h] [xbp-18h]
  int v84; // [xsp+30h] [xbp-10h]
  __int16 v85; // [xsp+34h] [xbp-Ch]
  __int64 v86; // [xsp+38h] [xbp-8h]

  v86 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(__int64 **)(a2 + 32);
  v5 = *v4;
  context = _cds_get_context(71, "dp_softap_start_xmit");
  StatusReg = _ReadStatusReg(SP_EL0);
  v8 = *(_DWORD *)(StatusReg + 40);
  if ( v8 >= 0x20 )
    goto LABEL_75;
  v9 = (__int64 *)(a1 + 224);
  v10 = context;
  v79 = *(unsigned __int8 **)(a1 + 224);
  ++*((_DWORD *)v4 + 19 * v8 + 58);
  *((_DWORD *)v4 + 677) = 0;
  if ( (cds_get_driver_state() & 0x1E) != 0 )
  {
    v76 = jiffies;
    if ( dp_softap_validate_driver_state___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: driver is transitioning, drop pkt",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "dp_softap_validate_driver_state");
      dp_softap_validate_driver_state___last_ticks = v76;
    }
    goto LABEL_63;
  }
  if ( *((_BYTE *)v4 + 3580) == 1 )
  {
    v77 = jiffies;
    if ( dp_softap_validate_driver_state___last_ticks_24 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Softap TX blocked mask: %u",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "dp_softap_validate_driver_state");
      dp_softap_validate_driver_state___last_ticks_24 = v77;
    }
    goto LABEL_63;
  }
  wlan_dp_pkt_add_timestamp(v4, 0, a1);
  v19 = *(int **)(a1 + 224);
  v83 = 0;
  v81 = 0;
  v82 = 0;
  v80 = 0;
  v20 = _cds_get_context(71, "dp_softap_validate_peer_state");
  if ( (*(_BYTE *)(a1 + 71) & 6) == 0 )
  {
    v36 = *v19;
    v85 = *((_WORD *)v19 + 2);
    v84 = v36;
    if ( v20 && *(_QWORD *)v20 && (v37 = *(_QWORD *)(*(_QWORD *)v20 + 72LL)) != 0 )
    {
      v38 = *(void (**)(void))(v37 + 184);
      if ( v38 )
      {
        if ( *((_DWORD *)v38 - 1) != 1021873010 )
          __break(0x8228u);
        v38();
      }
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        1u,
        "%s invalid instance",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "cdp_peer_get_info_by_peer_addr");
    }
    goto LABEL_63;
  }
  v29 = *(_DWORD *)(a1 + 48);
  if ( (v29 & 1) != 0 )
  {
    *(_DWORD *)(a1 + 48) = v29 & 0xFFFFFFFE;
    goto LABEL_21;
  }
  v30 = *v4;
  if ( (*(_BYTE *)(a1 + 126) & 1) != 0 )
  {
    v31 = v4[7];
    v32 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
    if ( (unsigned __int16)*(_DWORD *)(v32 + 32) != 1
      && *(_DWORD *)(a1 + 116)
      && !*(_WORD *)(v32 + 4)
      && _qdf_nbuf_data_is_ipv4_tcp_pkt(*v9) )
    {
      *(_WORD *)(*(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212) + 4LL) = *(_WORD *)(v31 + 56)
                                                                            - *(_WORD *)(a1 + 182)
                                                                            - (((*(_WORD *)(*(_QWORD *)(a1 + 216)
                                                                                          + *(unsigned __int16 *)(a1 + 182)
                                                                                          + 12LL) >> 2)
                                                                              & 0x3C)
                                                                             - *(_WORD *)(a1 + 184));
    }
  }
  if ( (*(_BYTE *)(v30 + 24) & 1) != 0
    || (*(_BYTE *)(a1 + 126) & 1) != 0
    && (unsigned __int16)*(_DWORD *)(*(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212) + 32LL) != 1 )
  {
    v33 = *(_DWORD *)(StatusReg + 40);
    if ( v33 < 0x20 )
    {
      ++*((_DWORD *)v4 + 19 * v33 + 60);
      v34 = *(void (__fastcall **)(_QWORD))(a1 + 96);
      if ( v34 )
      {
        if ( *((_DWORD *)v34 - 1) != 303786302 )
          __break(0x8228u);
        v34(a1);
        *(_QWORD *)(a1 + 96) = 0;
        *(_QWORD *)(a1 + 24) = 0;
      }
      else if ( *(_QWORD *)(a1 + 24) )
      {
        __break(0x800u);
        v75 = jiffies;
        if ( dp_softap_validate_peer_state___last_ticks_27 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: NON-EAPOL/WAPI pkt in non-Auth state",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "dp_softap_validate_peer_state");
          dp_softap_validate_peer_state___last_ticks_27 = v75;
        }
        goto LABEL_63;
      }
      goto LABEL_21;
    }
LABEL_75:
    __break(0x5512u);
  }
LABEL_21:
  if ( !a1 )
  {
LABEL_64:
    result = 16;
    ++v4[368];
    goto LABEL_65;
  }
  if ( (*(_BYTE *)(a1 + 68) & 4) != 0 )
    v35 = *(unsigned __int16 *)(a1 + 66);
  else
    v35 = 0;
  v4[364] += (unsigned int)(*(_DWORD *)(a1 + 112) + v35);
  v39 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
  if ( *(_WORD *)(v39 + 4) && (*(_BYTE *)(v39 + 24) & 0x11) != 0 )
  {
    tso_num_seg = _qdf_nbuf_get_tso_num_seg(a1);
    v41 = v4 + 362;
    v42 = tso_num_seg;
  }
  else
  {
    v42 = 1;
    ++v4[362];
    v41 = (_QWORD *)(v5 + 864);
  }
  *v41 += v42;
  v43 = *(_BYTE *)(a1 + 71);
  *(_BYTE *)(a1 + 61) &= ~1u;
  if ( (v43 & 0x78) == 0x20 )
  {
    dp_softap_inspect_dhcp_packet(a2, a1, 0);
    v43 = *(_BYTE *)(a1 + 71);
  }
  if ( (v43 & 0x78) == 8 )
  {
    dp_softap_inspect_tx_eap_pkt(a2, a1, 0);
    dp_event_eapol_log(a1, 0);
  }
  if ( *((_BYTE *)v4 + 3656) == 1 )
  {
    is_ipv4_pkt = _qdf_nbuf_data_is_ipv4_pkt(*v9);
    v45 = *v9;
    if ( is_ipv4_pkt )
    {
      ipv4_tos = _qdf_nbuf_data_get_ipv4_tos(v45);
      if ( *((_BYTE *)v4 + 3658) != (unsigned __int8)(ipv4_tos & 0xFC) >> 2 )
        goto LABEL_51;
      _qdf_nbuf_data_set_ipv4_tos(*(_QWORD *)(a1 + 224), ipv4_tos & 3 | (4 * *((_BYTE *)v4 + 3657)));
      if ( !_qdf_nbuf_is_ipv4_last_fragment(a1) )
        goto LABEL_51;
    }
    else
    {
      if ( !_qdf_nbuf_data_is_ipv6_pkt(v45) )
        goto LABEL_51;
      ipv6_tc = _qdf_nbuf_data_get_ipv6_tc(*v9);
      if ( *((_BYTE *)v4 + 3658) != (unsigned __int8)(ipv6_tc & 0xFC) >> 2 )
        goto LABEL_51;
      _qdf_nbuf_data_set_ipv6_tc(*v9, ipv6_tc & 3 | (4 * *((_BYTE *)v4 + 3657)));
    }
    *(_BYTE *)(a1 + 71) = *(_BYTE *)(a1 + 71) & 0x87 | 0x40;
  }
LABEL_51:
  *(_WORD *)(a1 + 69) = *(_WORD *)(a1 + 69) & 0xF8FF | 0x100;
  ((void (__fastcall *)(__int64, __int64))qdf_nbuf_set_state)(a1, 11);
  qdf_dp_trace_set_track(a1, 0);
  qdf_dp_trace(a1, 0x18u, 0xFFu, a1 + 224, 8u, 0, v48, v49);
  if ( *(_DWORD *)(a1 + 116) )
  {
    v50 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
    if ( (!*(_WORD *)(v50 + 4) || (*(_BYTE *)(v50 + 24) & 0x11) == 0) && !_pskb_pull_tail(a1) )
    {
      v78 = jiffies;
      if ( dp_softap_start_xmit___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          8u,
          "%s: nbuf %pK linearize failed. drop the pkt",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "dp_softap_start_xmit",
          a1);
        dp_softap_start_xmit___last_ticks = v78;
      }
      goto LABEL_63;
    }
  }
  v59 = (__int64 (__fastcall *)(__int64, __int64, __int64))v4[8];
  v60 = *(unsigned __int8 *)(a2 + 24);
  if ( *((_DWORD *)v59 - 1) != -1980056647 )
    __break(0x8228u);
  result = v59(v10, v60, a1);
  if ( result )
  {
    v70 = jiffies;
    if ( dp_softap_start_xmit___last_ticks_15 - jiffies + 125 < 0 )
    {
      if ( v79 )
      {
        v71 = *v79;
        v72 = v79[1];
        v73 = v79[2];
        v74 = v79[5];
      }
      else
      {
        v73 = 0;
        v71 = 0;
        v72 = 0;
        v74 = 0;
      }
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Failed to send packet to txrx for sta: %02x:%02x:%02x:**:**:%02x",
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        "dp_softap_start_xmit",
        v71,
        v72,
        v73,
        v74);
      dp_softap_start_xmit___last_ticks_15 = v70;
    }
LABEL_63:
    qdf_dp_trace_data_pkt(a1, 0xFFu, 1u, 0, 0);
    sk_skb_reason_drop(0, a1, 2);
    goto LABEL_64;
  }
LABEL_65:
  _ReadStatusReg(SP_EL0);
  return result;
}
