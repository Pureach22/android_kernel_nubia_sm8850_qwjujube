__int64 __fastcall ipa3_usb_init_teth_bridge(int a1)
{
  __int64 v1; // x9
  __int64 result; // x0
  unsigned int v3; // w19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x8
  __int64 v6; // x0

  v1 = 440;
  if ( a1 == 5 )
    v1 = 464;
  result = ipa3_teth_bridge_init(ipa3_usb_ctx + v1);
  if ( (_DWORD)result )
  {
    v3 = result;
    printk(&unk_3C2811, "ipa3_usb_init_teth_bridge");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_usb %s:%d Failed to initialize teth_bridge\n", "ipa3_usb_init_teth_bridge", 622);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    result = v3;
    if ( ipc_logbuf_low )
    {
      v6 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v6, "ipa_usb %s:%d Failed to initialize teth_bridge\n", "ipa3_usb_init_teth_bridge", 622);
      return v3;
    }
  }
  return result;
}
