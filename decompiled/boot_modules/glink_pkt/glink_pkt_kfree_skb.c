__int64 __fastcall glink_pkt_kfree_skb(__int64 a1, __int64 a2)
{
  int v4; // w0

  if ( *(_BYTE *)(a1 + 1144) == 1 )
  {
    ipc_log_string(glink_pkt_ilctxt, "[%s]: channel:%s\n", "glink_pkt_kfree_skb", *(const char **)(a1 + 1512));
    v4 = qcom_glink_rx_done(*(_QWORD *)(*(_QWORD *)(a1 + 1136) + 968LL), *(_QWORD *)(a2 + 224));
    if ( v4 < 0 )
      ipc_log_string(
        glink_pkt_ilctxt,
        "[%s]: Failed channel:%s ret:%d\n",
        "glink_pkt_kfree_skb",
        *(const char **)(a1 + 1512),
        v4);
    *(_QWORD *)(a2 + 224) = *(_QWORD *)(a2 + 216);
  }
  return sk_skb_reason_drop(0, a2, 2);
}
