__int64 __fastcall glink_pkt_clear_queues(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x21
  __int64 v4; // x20
  int v5; // w0
  __int64 v6; // x0
  __int64 v7; // x24
  int v8; // w0
  __int64 v9; // x0
  __int64 v10; // x24
  int v11; // w0

  v2 = raw_spin_lock_irqsave(a1 + 1148);
  v3 = *(_QWORD *)(a1 + 1584);
  v4 = v2;
  if ( v3 )
  {
    if ( *(_BYTE *)(a1 + 1144) == 1 )
    {
      ipc_log_string(glink_pkt_ilctxt, "[%s]: channel:%s\n", "glink_pkt_kfree_skb", *(const char **)(a1 + 1512));
      v5 = qcom_glink_rx_done(*(_QWORD *)(*(_QWORD *)(a1 + 1136) + 968LL), *(_QWORD *)(v3 + 224));
      if ( v5 < 0 )
        ipc_log_string(
          glink_pkt_ilctxt,
          "[%s]: Failed channel:%s ret:%d\n",
          "glink_pkt_kfree_skb",
          *(const char **)(a1 + 1512),
          v5);
      *(_QWORD *)(v3 + 224) = *(_QWORD *)(v3 + 216);
    }
    sk_skb_reason_drop(0, v3, 2);
    *(_QWORD *)(a1 + 1592) = 0;
    *(_QWORD *)(a1 + 1600) = 0;
    *(_QWORD *)(a1 + 1584) = 0;
  }
  v6 = skb_dequeue(a1 + 1152);
  if ( v6 )
  {
    v7 = v6;
    do
    {
      if ( *(_BYTE *)(a1 + 1144) == 1 )
      {
        ipc_log_string(glink_pkt_ilctxt, "[%s]: channel:%s\n", "glink_pkt_kfree_skb", *(const char **)(a1 + 1512));
        v8 = qcom_glink_rx_done(*(_QWORD *)(*(_QWORD *)(a1 + 1136) + 968LL), *(_QWORD *)(v7 + 224));
        if ( v8 < 0 )
          ipc_log_string(
            glink_pkt_ilctxt,
            "[%s]: Failed channel:%s ret:%d\n",
            "glink_pkt_kfree_skb",
            *(const char **)(a1 + 1512),
            v8);
        *(_QWORD *)(v7 + 224) = *(_QWORD *)(v7 + 216);
      }
      sk_skb_reason_drop(0, v7, 2);
      v7 = skb_dequeue(a1 + 1152);
    }
    while ( v7 );
  }
  v9 = skb_dequeue(a1 + 1176);
  if ( v9 )
  {
    v10 = v9;
    do
    {
      if ( *(_BYTE *)(a1 + 1144) == 1 )
      {
        ipc_log_string(glink_pkt_ilctxt, "[%s]: channel:%s\n", "glink_pkt_kfree_skb", *(const char **)(a1 + 1512));
        v11 = qcom_glink_rx_done(*(_QWORD *)(*(_QWORD *)(a1 + 1136) + 968LL), *(_QWORD *)(v10 + 224));
        if ( v11 < 0 )
          ipc_log_string(
            glink_pkt_ilctxt,
            "[%s]: Failed channel:%s ret:%d\n",
            "glink_pkt_kfree_skb",
            *(const char **)(a1 + 1512),
            v11);
        *(_QWORD *)(v10 + 224) = *(_QWORD *)(v10 + 216);
      }
      sk_skb_reason_drop(0, v10, 2);
      v10 = skb_dequeue(a1 + 1176);
    }
    while ( v10 );
  }
  return raw_spin_unlock_irqrestore(a1 + 1148, v4);
}
