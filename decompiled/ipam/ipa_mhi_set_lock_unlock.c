__int64 __fastcall ipa_mhi_set_lock_unlock(char a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x0
  __int64 v5; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d entry\n", "ipa_mhi_set_lock_unlock", 175);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d entry\n", "ipa_mhi_set_lock_unlock", 175);
  }
  if ( (a1 & 1) == 0 )
  {
    mutex_unlock(&mhi_client_general_mutex);
    if ( !ipa3_get_ipc_logbuf() )
      goto LABEL_10;
    goto LABEL_9;
  }
  mutex_lock(&mhi_client_general_mutex);
  if ( ipa3_get_ipc_logbuf() )
  {
LABEL_9:
    v4 = ipa3_get_ipc_logbuf();
    ipc_log_string(v4, "ipa_mhi_client %s:%d exit\n", "ipa_mhi_set_lock_unlock", 180);
  }
LABEL_10:
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v5 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v5, "ipa_mhi_client %s:%d exit\n", "ipa_mhi_set_lock_unlock", 180);
  }
  return 0;
}
