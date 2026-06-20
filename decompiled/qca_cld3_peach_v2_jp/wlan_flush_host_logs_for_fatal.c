__int64 __fastcall wlan_flush_host_logs_for_fatal(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x20
  unsigned __int64 v16; // x9

  if ( !dword_76E254 )
    qdf_trace_msg(
      0x38u,
      4u,
      "%s: Flush all host logs Setting HOST_LOG_POST_MAS",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "wlan_flush_host_logs_for_fatal");
  v8 = raw_spin_lock_irqsave((char *)&qword_76E148 + 4);
  wlan_queue_logmsg_for_app();
  raw_spin_unlock_irqrestore((char *)&qword_76E148 + 4, v8);
  _X8 = &qword_76E1D0;
  __asm { PRFM            #0x11, [X8] }
  do
    v16 = __ldxr((unsigned __int64 *)&qword_76E1D0);
  while ( __stxr(v16 | 2, (unsigned __int64 *)&qword_76E1D0) );
  return _wake_up(&unk_76E180, 1, 1, 0);
}
