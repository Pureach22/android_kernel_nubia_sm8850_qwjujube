long double __fastcall ipa3_usb_gsi_chan_err_cb(__int64 a1)
{
  long double result; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 ipc_logbuf; // x0
  __int64 v5; // x0
  __int64 v6; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    result = ipc_log_string(ipc_logbuf_low, "ipa_usb %s:%d entry\n", "ipa3_usb_gsi_chan_err_cb", 973);
  }
  if ( a1 )
  {
    printk(&unk_3EAF5A, "ipa3_usb_gsi_chan_err_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_usb %s:%d Received channel error %d, description: %d\n",
        "ipa3_usb_gsi_chan_err_cb",
        977,
        *(_DWORD *)(a1 + 8),
        *(unsigned __int16 *)(a1 + 12));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v5 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v5,
        "ipa_usb %s:%d Received channel error %d, description: %d\n",
        "ipa3_usb_gsi_chan_err_cb",
        977,
        *(_DWORD *)(a1 + 8),
        *(unsigned __int16 *)(a1 + 12));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v6 = ipa3_get_ipc_logbuf_low();
      return ipc_log_string(v6, "ipa_usb %s:%d exit\n", "ipa3_usb_gsi_chan_err_cb", 978);
    }
  }
  return result;
}
