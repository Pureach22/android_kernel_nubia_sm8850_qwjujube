__int64 __fastcall ipa3_usb_check_disconnect_prot(unsigned int a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0
  __int64 v6; // x0

  if ( a1 >= 6 )
  {
    printk(&unk_3CE4F6, "ipa3_usb_check_disconnect_prot");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_usb %s:%d bad parameter\n", "ipa3_usb_check_disconnect_prot", 2005);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_usb %s:%d bad parameter\n", "ipa3_usb_check_disconnect_prot", 2005);
    }
    return 4294967282LL;
  }
  if ( *(_DWORD *)(ipa3_usb_ctx + 72LL * a1 + 56) != 1 )
  {
    printk(&unk_3E8196, "ipa3_usb_check_disconnect_prot");
    if ( ipa3_get_ipc_logbuf() )
    {
      v5 = ipa3_get_ipc_logbuf();
      ipc_log_string(v5, "ipa_usb %s:%d %s is not connected\n", "ipa3_usb_check_disconnect_prot", 2012, off_1E5248[a1]);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v6 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v6, "ipa_usb %s:%d %s is not connected\n", "ipa3_usb_check_disconnect_prot", 2012, off_1E5248[a1]);
    }
    return 4294967282LL;
  }
  return 0;
}
