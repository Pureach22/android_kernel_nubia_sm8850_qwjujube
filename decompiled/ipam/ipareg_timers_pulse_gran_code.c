__int64 __fastcall ipareg_timers_pulse_gran_code(__int64 result)
{
  int v1; // w19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( (unsigned int)result >= 8 )
  {
    v1 = result;
    printk(&unk_3BFD03, "ipareg_timers_pulse_gran_code");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d Invalid granularity %d\n", "ipareg_timers_pulse_gran_code", 1052, v1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Invalid granularity %d\n", "ipareg_timers_pulse_gran_code", 1052, v1);
    }
    return 3;
  }
  return result;
}
