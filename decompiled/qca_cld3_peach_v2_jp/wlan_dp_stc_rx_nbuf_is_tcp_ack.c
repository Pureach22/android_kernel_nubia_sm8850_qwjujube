__int64 __fastcall wlan_dp_stc_rx_nbuf_is_tcp_ack(__int64 a1)
{
  __int64 v1; // x8
  char is_ipv4_v6_pure_tcp_ack; // w0
  __int64 v4; // x8
  char v5; // w20

  if ( (*(_BYTE *)(a1 + 72) & 2) != 0 )
  {
    v5 = 0;
  }
  else
  {
    v1 = *(_QWORD *)(a1 + 40);
    if ( v1 )
      *(_QWORD *)(a1 + 40) = v1 - 14;
    skb_push(a1, 14);
    is_ipv4_v6_pure_tcp_ack = _qdf_nbuf_is_ipv4_v6_pure_tcp_ack(a1);
    v4 = *(_QWORD *)(a1 + 40);
    v5 = is_ipv4_v6_pure_tcp_ack;
    if ( v4 )
      *(_QWORD *)(a1 + 40) = v4 + 14;
    skb_pull(a1, 14);
  }
  return v5 & 1;
}
