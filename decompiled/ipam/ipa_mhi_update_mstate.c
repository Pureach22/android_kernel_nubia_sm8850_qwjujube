__int64 __fastcall ipa_mhi_update_mstate(int a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_update_mstate", 2420);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_update_mstate", 2420);
  }
  if ( ipa_mhi_client_ctx )
  {
    if ( ipa3_get_ipc_logbuf() )
    {
      v4 = ipa3_get_ipc_logbuf();
      ipc_log_string(v4, "ipa_mhi_client %s:%d Req update mstate to %d\n", "ipa_mhi_update_mstate", 2428, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v5 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v5, "ipa_mhi_client %s:%d Req update mstate to %d\n", "ipa_mhi_update_mstate", 2428, a1);
    }
    mutex_lock(&mhi_client_general_mutex);
    *(_DWORD *)(ipa_mhi_client_ctx + 1316) = a1;
    mutex_unlock(&mhi_client_general_mutex);
    if ( ipa3_get_ipc_logbuf() )
    {
      v6 = ipa3_get_ipc_logbuf();
      ipc_log_string(v6, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_update_mstate", 2432);
    }
    result = ipa3_get_ipc_logbuf_low();
    if ( result )
    {
      v8 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v8, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_update_mstate", 2432);
      return 0;
    }
  }
  else
  {
    printk(&unk_3CE3A9, "ipa_mhi_update_mstate");
    if ( ipa3_get_ipc_logbuf() )
    {
      v9 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v9,
        "ipa_mhi_client %s:%d ipa_mhi_client_ctx not created yet %d mstate\n",
        "ipa_mhi_update_mstate",
        2424,
        a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v10 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v10,
        "ipa_mhi_client %s:%d ipa_mhi_client_ctx not created yet %d mstate\n",
        "ipa_mhi_update_mstate",
        2424,
        a1);
    }
    return 0xFFFFFFFFLL;
  }
  return result;
}
