__int64 __fastcall ipa_mhi_destroy_channels(__int64 a1, int a2)
{
  __int64 v2; // x22
  unsigned int *i; // x23
  unsigned int v4; // w0
  unsigned int v5; // w0
  unsigned int v6; // w8
  unsigned int ep_mapping; // w19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int v11; // w19
  __int64 v12; // x0
  __int64 v13; // x0
  unsigned int v14; // w20
  __int64 v15; // x0
  __int64 v16; // x0

  if ( a2 < 1 )
    return 0;
  v2 = (unsigned int)a2;
  for ( i = (unsigned int *)(a1 + 4); ; i += 50 )
  {
    if ( *((_BYTE *)i - 4) != 1 )
      goto LABEL_5;
    v6 = i[1];
    if ( v6 )
    {
      if ( v6 == 255 )
        goto LABEL_5;
      ep_mapping = ipa_get_ep_mapping(*i);
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipa_mhi_client %s:%d disconnect pipe (ep: %d)\n",
          "ipa_mhi_destroy_channels",
          2062,
          ep_mapping);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipa_mhi_client %s:%d disconnect pipe (ep: %d)\n",
          "ipa_mhi_destroy_channels",
          2062,
          ep_mapping);
      }
      v4 = ipa_mhi_disconnect_pipe(ep_mapping);
      if ( v4 )
        break;
    }
    v5 = ((__int64 (__fastcall *)(_QWORD))ipa3_mhi_destroy_channel)(*i);
    if ( v5 )
    {
      v11 = v5;
      printk(&unk_3A52E1, "ipa_mhi_destroy_channels");
      if ( ipa3_get_ipc_logbuf() )
      {
        v12 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v12,
          "ipa_mhi_client %s:%d ipa3_mhi_destroy_channel failed %d",
          "ipa_mhi_destroy_channels",
          2075,
          v11);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v13 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v13,
          "ipa_mhi_client %s:%d ipa3_mhi_destroy_channel failed %d",
          "ipa_mhi_destroy_channels",
          2075,
          v11);
      }
      return v11;
    }
LABEL_5:
    if ( !--v2 )
      return 0;
  }
  v14 = v4;
  printk(&unk_3BC9E9, "ipa_mhi_destroy_channels");
  if ( ipa3_get_ipc_logbuf() )
  {
    v15 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v15,
      "ipa_mhi_client %s:%d failed to disconnect pipe %d, err %d\n",
      "ipa_mhi_destroy_channels",
      2067,
      ep_mapping,
      v14);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v16 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v16,
      "ipa_mhi_client %s:%d failed to disconnect pipe %d, err %d\n",
      "ipa_mhi_destroy_channels",
      2067,
      ep_mapping,
      v14);
  }
  return v14;
}
