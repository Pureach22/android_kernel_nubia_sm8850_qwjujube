long double __fastcall rmnet_ipa_free_msg(const void *a1, __int64 a2, unsigned int a3)
{
  long double result; // q0
  __int64 v4; // x0
  __int64 v5; // x0
  const void *v6; // x19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x8
  __int64 v10; // x0

  if ( a1 )
  {
    if ( a3 > 0x1F || ((1 << a3) & 0xC0600000) == 0 )
    {
      v6 = a1;
      printk(&unk_3FC5A7, "rmnet_ipa_free_msg");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipa-wan %s:%d Wrong type given. buff %pK type %d\n",
          "rmnet_ipa_free_msg",
          4244,
          v6,
          a3);
      }
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      a1 = v6;
      if ( ipc_logbuf_low )
      {
        v10 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v10, "ipa-wan %s:%d Wrong type given. buff %pK type %d\n", "rmnet_ipa_free_msg", 4244, v6, a3);
        a1 = v6;
      }
    }
    kfree(a1);
  }
  else
  {
    printk(&unk_3ADDF9, "rmnet_ipa_free_msg");
    if ( ipa3_get_ipc_logbuf() )
    {
      v4 = ipa3_get_ipc_logbuf();
      ipc_log_string(v4, "ipa-wan %s:%d Null buffer\n", "rmnet_ipa_free_msg", 4235);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v5 = ipa3_get_ipc_logbuf_low();
      return ipc_log_string(v5, "ipa-wan %s:%d Null buffer\n", "rmnet_ipa_free_msg", 4235);
    }
  }
  return result;
}
