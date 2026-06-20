__int64 __fastcall ipa_mhi_suspend_gsi_channel(__int64 a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int ep_mapping; // w0
  int v5; // w0
  __int64 v6; // x0
  const char *v7; // x4
  __int64 v8; // x0
  const char *v9; // x4
  __int64 v10; // x0
  __int64 result; // x0
  __int64 v12; // x0
  int v13; // w19
  __int64 v14; // x0
  __int64 v15; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_suspend_gsi_channel", 1078);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_suspend_gsi_channel", 1078);
  }
  ep_mapping = ipa_get_ep_mapping(*(unsigned int *)(a1 + 4));
  if ( (ep_mapping & 0x80000000) != 0 )
    return 4294967282LL;
  v5 = ipa_stop_gsi_channel(ep_mapping);
  if ( (unsigned int)(v5 + 12) >= 2 )
  {
    if ( !v5 )
      goto LABEL_9;
    v13 = v5;
    printk(&unk_3D7162, "ipa_mhi_suspend_gsi_channel");
    if ( ipa3_get_ipc_logbuf() )
    {
      v14 = ipa3_get_ipc_logbuf();
      ipc_log_string(v14, "ipa_mhi_client %s:%d GSI stop channel failed %d\n", "ipa_mhi_suspend_gsi_channel", 1086, v13);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v15 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v15, "ipa_mhi_client %s:%d GSI stop channel failed %d\n", "ipa_mhi_suspend_gsi_channel", 1086, v13);
    }
    return 4294967282LL;
  }
  *(_BYTE *)(a1 + 12) = 1;
LABEL_9:
  if ( ipa3_get_ipc_logbuf() )
  {
    v6 = ipa3_get_ipc_logbuf();
    if ( *(_BYTE *)(a1 + 12) )
      v7 = "STOP_IN_PROC";
    else
      v7 = "STOP";
    ipc_log_string(v6, "ipa_mhi_client %s:%d GSI channel is %s\n", "ipa_mhi_suspend_gsi_channel", 1095, v7);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v8 = ipa3_get_ipc_logbuf_low();
    if ( *(_BYTE *)(a1 + 12) )
      v9 = "STOP_IN_PROC";
    else
      v9 = "STOP";
    ipc_log_string(v8, "ipa_mhi_client %s:%d GSI channel is %s\n", "ipa_mhi_suspend_gsi_channel", 1095, v9);
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v10 = ipa3_get_ipc_logbuf();
    ipc_log_string(v10, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_suspend_gsi_channel", 1097);
  }
  result = ipa3_get_ipc_logbuf_low();
  if ( result )
  {
    v12 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v12, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_suspend_gsi_channel", 1097);
    return 0;
  }
  return result;
}
