__int64 __fastcall ipa_dma_gsi_irq_rx_notify_cb(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x21
  __int64 v3; // x8
  __int64 v4; // x9
  _QWORD *v5; // x8
  __int64 v6; // x11
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0

  if ( result )
  {
    v1 = result;
    if ( ipa3_ctx )
    {
      result = *(_QWORD *)(ipa3_ctx + 34160);
      if ( result )
        result = ipc_log_string(
                   result,
                   "ipa %s:%d event %d notified\n",
                   "ipa_dma_gsi_irq_rx_notify_cb",
                   6623,
                   *(_DWORD *)(v1 + 16));
    }
    v2 = *(_QWORD *)v1;
    v3 = *(_QWORD *)(*(_QWORD *)v1 + 1624LL);
    if ( *(_DWORD *)(v3 + 4) == 45 )
    {
      result = printk(&unk_3E64A5, "ipa_dma_gsi_irq_rx_notify_cb");
      v9 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v10 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v10 )
        {
          ipc_log_string(
            v10,
            "ipa %s:%d IRQ_RX Callback was called for DMA_SYNC_CONS.\n",
            "ipa_dma_gsi_irq_rx_notify_cb",
            6627);
          v9 = ipa3_ctx;
        }
        result = *(_QWORD *)(v9 + 34160);
        if ( result )
          return ipc_log_string(
                   result,
                   "ipa %s:%d IRQ_RX Callback was called for DMA_SYNC_CONS.\n",
                   "ipa_dma_gsi_irq_rx_notify_cb",
                   6627);
      }
    }
    else
    {
      *(_BYTE *)(v3 + 136) = 0;
      v4 = *(_QWORD *)(v1 + 16);
      v5 = *(_QWORD **)(v2 + 1624);
      v6 = *(_QWORD *)v1;
      v5[15] = *(_QWORD *)(v1 + 8);
      v5[16] = v4;
      v5[14] = v6;
      if ( *(_DWORD *)(v1 + 16) == 2 )
      {
        if ( !*(_DWORD *)(v2 + 4) )
        {
          gsi_config_channel_mode(*(_QWORD *)(*(_QWORD *)(v2 + 1624) + 8LL), 1);
          ipa3_inc_acquire_wakelock();
          *(_DWORD *)(v2 + 4) = 1;
          return queue_work_on(32, *(_QWORD *)(v2 + 1752), v2 + 192);
        }
      }
      else
      {
        result = printk(&unk_3ACA94, "ipa_dma_gsi_irq_rx_notify_cb");
        v11 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v12 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v12 )
          {
            ipc_log_string(
              v12,
              "ipa %s:%d received unexpected event id %d\n",
              "ipa_dma_gsi_irq_rx_notify_cb",
              6646,
              *(_DWORD *)(v1 + 16));
            v11 = ipa3_ctx;
          }
          result = *(_QWORD *)(v11 + 34160);
          if ( result )
            return ipc_log_string(
                     result,
                     "ipa %s:%d received unexpected event id %d\n",
                     "ipa_dma_gsi_irq_rx_notify_cb",
                     6646,
                     *(_DWORD *)(v1 + 16));
        }
      }
    }
  }
  else
  {
    result = printk(&unk_3DB507, "ipa_dma_gsi_irq_rx_notify_cb");
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d gsi notify is NULL.\n", "ipa_dma_gsi_irq_rx_notify_cb", 6620);
        v7 = ipa3_ctx;
      }
      result = *(_QWORD *)(v7 + 34160);
      if ( result )
        return ipc_log_string(result, "ipa %s:%d gsi notify is NULL.\n", "ipa_dma_gsi_irq_rx_notify_cb", 6620);
    }
  }
  return result;
}
