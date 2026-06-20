unsigned __int64 __fastcall ipa_wigig_pipe_to_bit_val(int a1)
{
  char v1; // w8
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  v1 = a1 - 86;
  if ( (unsigned int)(a1 - 86) < 8 && ((0xABu >> v1) & 1) != 0 )
    return 0x1001080104010201uLL >> (8 * v1);
  printk(&unk_3F9FCB, "ipa_wigig_pipe_to_bit_val");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d invalid pipe %d\n", "ipa_wigig_pipe_to_bit_val", 607, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d invalid pipe %d\n", "ipa_wigig_pipe_to_bit_val", 607, a1);
  }
  return 1;
}
