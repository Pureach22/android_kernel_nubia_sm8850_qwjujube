__int64 __fastcall ipareg_parse_dummy(unsigned int a1)
{
  __int64 ipc_logbuf; // x20
  const char *v3; // x0
  long double v4; // q0
  __int64 ipc_logbuf_low; // x20
  const char *v6; // x0
  __int64 result; // x0

  ipahal_reg_name_str(a1);
  printk(&unk_3E00AD, "ipareg_parse_dummy");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    v3 = ipahal_reg_name_str(a1);
    ipc_log_string(ipc_logbuf, "ipahal %s:%d No parse function for %s\n", "ipareg_parse_dummy", 201, v3);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v6 = ipahal_reg_name_str(a1);
    v4 = ipc_log_string(ipc_logbuf_low, "ipahal %s:%d No parse function for %s\n", "ipareg_parse_dummy", 201, v6);
  }
  result = _warn_printk("invalid register operation", *(double *)&v4);
  __break(0x800u);
  return result;
}
