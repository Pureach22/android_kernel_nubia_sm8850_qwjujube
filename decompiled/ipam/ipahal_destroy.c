__int64 ipahal_destroy()
{
  __int64 ipc_logbuf; // x0
  long double v1; // q0
  __int64 ipc_logbuf_low; // x0
  unsigned __int64 v3; // x0
  __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipahal %s:%d Entry\n", "ipahal_destroy", 2631);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v1 = ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Entry\n", "ipahal_destroy", 2631);
  }
  ipahal_fltrt_destroy(v1);
  if ( ipahal_ctx )
  {
    v3 = *(_QWORD *)(ipahal_ctx + 24);
    if ( v3 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_3DFDD4, "ipahal_debugfs_remove");
      if ( ipa3_get_ipc_logbuf() )
      {
        v5 = ipa3_get_ipc_logbuf();
        ipc_log_string(v5, "ipahal %s:%d ipahal debugfs folder was not created\n", "ipahal_debugfs_remove", 2006);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v6 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v6, "ipahal %s:%d ipahal debugfs folder was not created\n", "ipahal_debugfs_remove", 2006);
      }
    }
    else
    {
      debugfs_remove(v3);
    }
  }
  result = kfree(ipahal_ctx);
  ipahal_ctx = 0;
  return result;
}
