__int64 __fastcall init_deinit_wakeup_host_wait(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  if ( a10 )
    return qdf_event_set(a10 + 512, a10);
  else
    return qdf_trace_msg(
             0x49u,
             2u,
             "%s: psoc target_psoc_info is null in target ready",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "init_deinit_wakeup_host_wait");
}
