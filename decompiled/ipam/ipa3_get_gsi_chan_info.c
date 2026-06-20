__int64 __fastcall ipa3_get_gsi_chan_info(_QWORD *a1, __int64 a2)
{
  int channel_info; // w0
  int v5; // w19
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0

  a1[3] = 0;
  a1[4] = 0;
  a1[1] = 0;
  a1[2] = 0;
  *a1 = 0;
  channel_info = gsi_query_channel_info(a2, a1);
  if ( channel_info )
  {
    v5 = channel_info;
    printk(&unk_3F7576, "ipa3_get_gsi_chan_info");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d Error querying channel info: %d\n", "ipa3_get_gsi_chan_info", 993, v5);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(v8, "ipa %s:%d Error querying channel info: %d\n", "ipa3_get_gsi_chan_info", 993, v5);
    }
    return 4294967282LL;
  }
  if ( (a1[2] & 1) == 0 )
  {
    printk(&unk_3A6453, "ipa3_get_gsi_chan_info");
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d Event info invalid\n", "ipa3_get_gsi_chan_info", 997);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d Event info invalid\n", "ipa3_get_gsi_chan_info", 997);
    }
    return 4294967282LL;
  }
  return 0;
}
