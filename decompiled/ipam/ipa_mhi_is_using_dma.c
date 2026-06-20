__int64 __fastcall ipa_mhi_is_using_dma(bool *a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_is_using_dma", 2388);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_is_using_dma", 2388);
  }
  if ( ipa_mhi_client_ctx )
  {
    *a1 = *(_DWORD *)(ipa_mhi_client_ctx + 1300) != 0;
    if ( ipa3_get_ipc_logbuf() )
    {
      v4 = ipa3_get_ipc_logbuf();
      ipc_log_string(v4, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_is_using_dma", 2397);
    }
    result = ipa3_get_ipc_logbuf_low();
    if ( result )
    {
      v6 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v6, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_is_using_dma", 2397);
      return 0;
    }
  }
  else
  {
    printk(&unk_3F0946, "ipa_mhi_is_using_dma");
    if ( ipa3_get_ipc_logbuf() )
    {
      v7 = ipa3_get_ipc_logbuf();
      ipc_log_string(v7, "ipa_mhi_client %s:%d not initialized\n", "ipa_mhi_is_using_dma", 2391);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v8 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v8, "ipa_mhi_client %s:%d not initialized\n", "ipa_mhi_is_using_dma", 2391);
    }
    return 0xFFFFFFFFLL;
  }
  return result;
}
