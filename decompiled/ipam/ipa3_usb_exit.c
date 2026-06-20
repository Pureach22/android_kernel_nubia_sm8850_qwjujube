__int64 ipa3_usb_exit()
{
  __int64 ipc_logbuf_low; // x0
  unsigned __int64 v1; // x0
  __int64 ipc_logbuf; // x0
  __int64 v4; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_usb %s:%d IPA_USB exit\n", "ipa3_usb_exit", 2767);
  }
  ipa3_deregister_client_callback(18);
  v1 = *(_QWORD *)(ipa3_usb_ctx + 1368);
  if ( v1 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_3F9D51, "ipa_usb_debugfs_remove");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa_usb %s:%d ipa_usb debugfs folder was not created\n",
        "ipa_usb_debugfs_remove",
        1907);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v4 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v4, "ipa_usb %s:%d ipa_usb debugfs folder was not created\n", "ipa_usb_debugfs_remove", 1907);
    }
  }
  else
  {
    debugfs_remove(v1);
  }
  return kfree(ipa3_usb_ctx);
}
