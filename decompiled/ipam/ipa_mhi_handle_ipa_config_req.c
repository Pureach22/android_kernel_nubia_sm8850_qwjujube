__int64 ipa_mhi_handle_ipa_config_req()
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v2; // x0
  __int64 v3; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_handle_ipa_config_req", 2380);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_handle_ipa_config_req", 2380);
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v2 = ipa3_get_ipc_logbuf();
    ipc_log_string(v2, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_handle_ipa_config_req", 2381);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v3 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v3, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_handle_ipa_config_req", 2381);
  }
  return 0;
}
