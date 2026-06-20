__int64 __fastcall ipa_mhi_suspend_channels(__int64 a1, int a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v6; // x19
  __int64 v7; // x0
  long double v8; // q0
  __int64 v9; // x0
  unsigned int v10; // w0
  __int64 v11; // x0
  __int64 result; // x0
  __int64 v13; // x0
  unsigned int v14; // w20
  __int64 v15; // x0
  __int64 v16; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_suspend_channels", 1486);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_suspend_channels", 1486);
  }
  if ( a2 < 1 )
  {
LABEL_16:
    if ( ipa3_get_ipc_logbuf() )
    {
      v11 = ipa3_get_ipc_logbuf();
      ipc_log_string(v11, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_suspend_channels", 1507);
    }
    result = ipa3_get_ipc_logbuf_low();
    if ( result )
    {
      v13 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v13, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_suspend_channels", 1507);
      return 0;
    }
    return result;
  }
  v6 = 0;
  while ( 1 )
  {
    if ( *(_BYTE *)a1 != 1 || *(_DWORD *)(a1 + 8) != 2 )
      goto LABEL_7;
    if ( ipa3_get_ipc_logbuf() )
    {
      v7 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v7,
        "ipa_mhi_client %s:%d suspending channel %d\n",
        "ipa_mhi_suspend_channels",
        1494,
        *(unsigned __int8 *)(a1 + 1));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v9 = ipa3_get_ipc_logbuf_low();
      v8 = ipc_log_string(
             v9,
             "ipa_mhi_client %s:%d suspending channel %d\n",
             "ipa_mhi_suspend_channels",
             1494,
             *(unsigned __int8 *)(a1 + 1));
    }
    v10 = ipa_mhi_suspend_gsi_channel(a1, v8);
    if ( v10 )
      break;
    *(_DWORD *)(a1 + 8) = 3;
LABEL_7:
    ++v6;
    a1 += 200;
    if ( a2 == v6 )
      goto LABEL_16;
  }
  v14 = v10;
  printk(&unk_3ED996, "ipa_mhi_suspend_channels");
  if ( ipa3_get_ipc_logbuf() )
  {
    v15 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v15,
      "ipa_mhi_client %s:%d failed to suspend channel %d error %d\n",
      "ipa_mhi_suspend_channels",
      1500,
      v6,
      v14);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v16 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v16,
      "ipa_mhi_client %s:%d failed to suspend channel %d error %d\n",
      "ipa_mhi_suspend_channels",
      1500,
      v6,
      v14);
  }
  return v14;
}
