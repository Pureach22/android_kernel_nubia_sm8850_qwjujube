const char *__fastcall ipahal_nat_type_str(unsigned int a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a1 < 4 )
    return ipahal_nat_type_to_str[a1];
  printk(&unk_3E54FB, "ipahal_nat_type_str");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipahal %s:%d requested NAT type %d is invalid\n", "ipahal_nat_type_str", 420, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d requested NAT type %d is invalid\n", "ipahal_nat_type_str", 420, a1);
  }
  return "Invalid NAT type";
}
