__int64 __fastcall ipa_gsi_irq_rx_notify_cb(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x9
  _QWORD *v4; // x8
  __int64 v5; // x11
  int v6; // w3
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0

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
                   "ipa_gsi_irq_rx_notify_cb",
                   6585,
                   *(_DWORD *)(v1 + 16));
    }
    v2 = *(_QWORD *)v1;
    *(_BYTE *)(*(_QWORD *)(*(_QWORD *)v1 + 1624LL) + 136LL) = 0;
    v3 = *(_QWORD *)(v1 + 16);
    v4 = *(_QWORD **)(v2 + 1624);
    v5 = *(_QWORD *)v1;
    v4[15] = *(_QWORD *)(v1 + 8);
    v4[16] = v3;
    v4[14] = v5;
    v6 = *(_DWORD *)(v1 + 16);
    if ( v6 == 4 || v6 == 2 )
    {
      *(_DWORD *)(ipa3_ctx + 31972) = 1;
      if ( !*(_DWORD *)(v2 + 4) )
      {
        gsi_config_channel_mode(*(_QWORD *)(*(_QWORD *)(v2 + 1624) + 8LL), 1);
        return _ipa_gsi_irq_rx_scedule_poll(v2);
      }
    }
    else
    {
      result = printk(&unk_3ACA94, "ipa_gsi_irq_rx_notify_cb");
      v9 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v10 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v10 )
        {
          ipc_log_string(
            v10,
            "ipa %s:%d received unexpected event id %d\n",
            "ipa_gsi_irq_rx_notify_cb",
            6611,
            *(_DWORD *)(v1 + 16));
          v9 = ipa3_ctx;
        }
        result = *(_QWORD *)(v9 + 34160);
        if ( result )
          return ipc_log_string(
                   result,
                   "ipa %s:%d received unexpected event id %d\n",
                   "ipa_gsi_irq_rx_notify_cb",
                   6611,
                   *(_DWORD *)(v1 + 16));
      }
    }
  }
  else
  {
    result = printk(&unk_3DB507, "ipa_gsi_irq_rx_notify_cb");
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d gsi notify is NULL.\n", "ipa_gsi_irq_rx_notify_cb", 6582);
        v7 = ipa3_ctx;
      }
      result = *(_QWORD *)(v7 + 34160);
      if ( result )
        return ipc_log_string(result, "ipa %s:%d gsi notify is NULL.\n", "ipa_gsi_irq_rx_notify_cb", 6582);
    }
  }
  return result;
}
