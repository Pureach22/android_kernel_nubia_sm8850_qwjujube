__int64 __fastcall dp_rx_deliver_special_frame(__int64 a1, __int64 *a2, __int64 a3, char a4, __int64 a5)
{
  __int64 (__fastcall *v10)(_QWORD); // x8
  unsigned int v11; // w25
  unsigned int v12; // w9
  unsigned int v13; // w24
  unsigned int v14; // w26
  unsigned int v15; // w8
  int v16; // w9
  int v17; // w9
  int v18; // w10
  int v19; // w9
  __int64 v20; // x8
  unsigned __int8 *v21; // x9
  void (__fastcall *v22)(__int64, __int64, __int64, __int64, __int64, __int64); // x8
  __int64 (__fastcall *v23)(_QWORD); // x8
  unsigned __int16 v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v34; // x2
  __int64 v35; // x1

  v10 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 536LL);
  if ( *((_DWORD *)v10 - 1) != 855462014 )
    __break(0x8228u);
  v11 = v10(a5);
  if ( (*(char *)(a3 + 84) & 0x80000000) == 0 )
  {
    v12 = *(_DWORD *)(a3 + 112);
    v13 = v11 + *(unsigned __int16 *)(a1 + 1138);
    v14 = v13 + *(unsigned __int16 *)(a3 + 60);
    v15 = v14 - v12;
    if ( v14 < v12 )
    {
      skb_trim(a3, v14);
      goto LABEL_14;
    }
    if ( *(_DWORD *)(a3 + 116) )
    {
      v15 = v14 - v12;
      if ( v14 != v12 )
      {
        v16 = 0;
        goto LABEL_11;
      }
    }
    else
    {
      v18 = *(_DWORD *)(a3 + 208);
      v17 = *(_DWORD *)(a3 + 212);
      if ( v17 - v18 < v15 )
      {
        v16 = v18 - v17;
LABEL_11:
        if ( (unsigned int)pskb_expand_head(a3, 0, v16 + v15, 2080) )
          dev_kfree_skb_any_reason(a3, 1);
      }
    }
    skb_put(a3, v14 - *(_DWORD *)(a3 + 112));
    goto LABEL_14;
  }
  v13 = v11;
LABEL_14:
  v19 = *(_DWORD *)(a3 + 48);
  v20 = *(_QWORD *)(a3 + 40);
  *(_BYTE *)(a3 + 75) = 1;
  *(_DWORD *)(a3 + 48) = v19 & 0xFFFFFF8F | (16 * (v11 & 7));
  if ( v20 )
    *(_QWORD *)(a3 + 40) = v20 + v13;
  skb_pull(a3, v13);
  if ( *a2
    && (v21 = *(unsigned __int8 **)(*a2 + 24),
        (v22 = *((void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64))v21 + 11948)) != nullptr) )
  {
    v34 = *(unsigned __int8 *)(a3 + 86);
    v35 = *v21;
    if ( *((_DWORD *)v22 - 1) != -915278510 )
      __break(0x8228u);
    v22(a1, v35, v34, a3, 1, 3);
    if ( (a4 & 1) != 0 )
    {
LABEL_19:
      if ( _qdf_nbuf_data_is_ipv4_arp_pkt(*(_QWORD *)(a3 + 224)) )
        goto LABEL_32;
    }
  }
  else if ( (a4 & 1) != 0 )
  {
    goto LABEL_19;
  }
  if ( ((a4 & 2) == 0 || !_qdf_nbuf_data_is_ipv4_dhcp_pkt(*(_QWORD *)(a3 + 224)))
    && ((a4 & 4) == 0 || !_qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(a3 + 224)))
    && ((a4 & 8) == 0 || !_qdf_nbuf_data_is_ipv6_dhcp_pkt(*(unsigned __int16 **)(a3 + 224)))
    && ((a4 & 0x10) == 0 || !_qdf_nbuf_data_is_dns_query(*(_QWORD *)(a3 + 224)))
    && ((a4 & 0x20) == 0 || !_qdf_nbuf_data_is_dns_response(*(_QWORD *)(a3 + 224)))
    && ((a4 & 0x40) == 0 || !_qdf_nbuf_is_ipv4_wapi_pkt(a3)) )
  {
    return 0;
  }
LABEL_32:
  v23 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 856LL);
  if ( *((_DWORD *)v23 - 1) != 646946022 )
    __break(0x8228u);
  v24 = v23(a5);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: special frame, mpdu sn 0x%x",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "dp_rx_deliver_special_frame",
    v24);
  *(_DWORD *)(a3 + 48) |= 0x80u;
  dp_rx_deliver_to_stack(a1, *a2, (__int64)a2, a3, 0);
  return 1;
}
