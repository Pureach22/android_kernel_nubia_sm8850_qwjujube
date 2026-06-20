long double ipa3_usb_device_ready_notify_cb()
{
  long double v0; // q0
  __int64 ipc_logbuf_low; // x0
  long double result; // q0
  __int64 v3; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v0 = ipc_log_string(ipc_logbuf_low, "ipa_usb %s:%d entry\n", "ipa3_usb_device_ready_notify_cb", 499);
  }
  ipa3_usb_notify_do(0, 0, v0);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v3 = ipa3_get_ipc_logbuf_low();
    return ipc_log_string(v3, "ipa_usb %s:%d exit\n", "ipa3_usb_device_ready_notify_cb", 502);
  }
  return result;
}
