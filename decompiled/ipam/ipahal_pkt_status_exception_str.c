const char *__fastcall ipahal_pkt_status_exception_str(unsigned int a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a1 < 0xF )
    return ipahal_pkt_status_exception_to_str[a1];
  printk(&unk_3C5DBD, "ipahal_pkt_status_exception_str");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipahal %s:%d requested string of invalid pkt_status exception=%d\n",
      "ipahal_pkt_status_exception_str",
      1978,
      a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipahal %s:%d requested string of invalid pkt_status exception=%d\n",
      "ipahal_pkt_status_exception_str",
      1978,
      a1);
  }
  return "Invalid PKT_STATUS_EXCEPTION";
}
