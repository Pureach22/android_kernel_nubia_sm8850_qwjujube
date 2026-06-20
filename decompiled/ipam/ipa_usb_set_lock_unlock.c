__int64 __fastcall ipa_usb_set_lock_unlock(char a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_usb %s:%d entry\n", "ipa_usb_set_lock_unlock", 752);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_usb %s:%d entry\n", "ipa_usb_set_lock_unlock", 752);
  }
  v4 = ipa3_usb_ctx + 544;
  if ( (a1 & 1) == 0 )
  {
    mutex_unlock(v4);
    if ( !ipa3_get_ipc_logbuf() )
      goto LABEL_10;
    goto LABEL_9;
  }
  mutex_lock(v4);
  if ( ipa3_get_ipc_logbuf() )
  {
LABEL_9:
    v5 = ipa3_get_ipc_logbuf();
    ipc_log_string(v5, "ipa_usb %s:%d exit\n", "ipa_usb_set_lock_unlock", 757);
  }
LABEL_10:
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v6 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v6, "ipa_usb %s:%d exit\n", "ipa_usb_set_lock_unlock", 757);
  }
  return 0;
}
