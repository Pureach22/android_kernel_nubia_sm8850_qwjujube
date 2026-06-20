__int64 ipa3_wan_ioctl_open()
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa-wan %s:%d \n IPA A7 ipa3_wan_ioctl open OK :>>>> ", "ipa3_wan_ioctl_open", 591);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d \n IPA A7 ipa3_wan_ioctl open OK :>>>> ", "ipa3_wan_ioctl_open", 591);
  }
  return 0;
}
