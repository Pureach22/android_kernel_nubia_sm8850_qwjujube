__int64 ipa_mhi_destroy_all_channels()
{
  __int64 ipc_logbuf; // x0
  long double v1; // q0
  __int64 ipc_logbuf_low; // x0
  unsigned int v3; // w0
  __int64 v4; // x0
  long double v5; // q0
  __int64 v6; // x0
  unsigned int v7; // w0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 result; // x0
  __int64 v12; // x0
  unsigned int v13; // w19
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned int v16; // w19
  __int64 v17; // x0
  __int64 v18; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_destroy_all_channels", 2094);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v1 = ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_destroy_all_channels", 2094);
  }
  v3 = ipa_mhi_destroy_channels(ipa_mhi_client_ctx + 40, 2, v1);
  if ( v3 )
  {
    v13 = v3;
    printk(&unk_3E4E03, "ipa_mhi_destroy_all_channels");
    if ( ipa3_get_ipc_logbuf() )
    {
      v14 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v14,
        "ipa_mhi_client %s:%d ipa_mhi_destroy_channels(ul_channels) failed %d\n",
        "ipa_mhi_destroy_all_channels",
        2100,
        v13);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v15 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v15,
        "ipa_mhi_client %s:%d ipa_mhi_destroy_channels(ul_channels) failed %d\n",
        "ipa_mhi_destroy_all_channels",
        2100,
        v13);
    }
    return 0xFFFFFFFFLL;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v4 = ipa3_get_ipc_logbuf();
    ipc_log_string(v4, "ipa_mhi_client %s:%d All UL channels are disconnected\n", "ipa_mhi_destroy_all_channels", 2103);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v6 = ipa3_get_ipc_logbuf_low();
    v5 = ipc_log_string(
           v6,
           "ipa_mhi_client %s:%d All UL channels are disconnected\n",
           "ipa_mhi_destroy_all_channels",
           2103);
  }
  v7 = ipa_mhi_destroy_channels(ipa_mhi_client_ctx + 440, 4, v5);
  if ( v7 )
  {
    v16 = v7;
    printk(&unk_3BC88A, "ipa_mhi_destroy_all_channels");
    if ( ipa3_get_ipc_logbuf() )
    {
      v17 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v17,
        "ipa_mhi_client %s:%d ipa_mhi_destroy_channels(dl_channels) failed %d\n",
        "ipa_mhi_destroy_all_channels",
        2109,
        v16);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v18 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v18,
        "ipa_mhi_client %s:%d ipa_mhi_destroy_channels(dl_channels) failed %d\n",
        "ipa_mhi_destroy_all_channels",
        2109,
        v16);
    }
    return 0xFFFFFFFFLL;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v8 = ipa3_get_ipc_logbuf();
    ipc_log_string(v8, "ipa_mhi_client %s:%d All DL channels are disconnected\n", "ipa_mhi_destroy_all_channels", 2112);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v9 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v9, "ipa_mhi_client %s:%d All DL channels are disconnected\n", "ipa_mhi_destroy_all_channels", 2112);
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v10 = ipa3_get_ipc_logbuf();
    ipc_log_string(v10, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_destroy_all_channels", 2114);
  }
  result = ipa3_get_ipc_logbuf_low();
  if ( result )
  {
    v12 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v12, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_destroy_all_channels", 2114);
    return 0;
  }
  return result;
}
