const char *__fastcall ipahal_reg_name_str(unsigned int a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a1 < 0xA6 )
    return ipareg_name_to_str[a1];
  printk(&unk_3CB61F, "ipahal_reg_name_str");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipahal %s:%d requested name of invalid reg=%d\n", "ipahal_reg_name_str", 5444, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d requested name of invalid reg=%d\n", "ipahal_reg_name_str", 5444, a1);
  }
  return "Invalid Register";
}
