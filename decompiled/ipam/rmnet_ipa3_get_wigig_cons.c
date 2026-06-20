__int64 __fastcall rmnet_ipa3_get_wigig_cons(unsigned int a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a1 < 4 )
    return 2 * a1 + 87;
  printk(&unk_3C828A, "rmnet_ipa3_get_wigig_cons");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa-wan %s:%d invalid index %d\n", "rmnet_ipa3_get_wigig_cons", 4919, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d invalid index %d\n", "rmnet_ipa3_get_wigig_cons", 4919, a1);
  }
  return 134;
}
