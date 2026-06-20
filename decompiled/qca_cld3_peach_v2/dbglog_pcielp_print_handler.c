bool __fastcall dbglog_pcielp_print_handler(
        __int64 a1,
        __int64 a2,
        int a3,
        unsigned int a4,
        unsigned int a5,
        __int64 a6)
{
  if ( a3 == 1000 )
    dbglog_sm_print(
      a4,
      a2,
      a5,
      a6,
      "PCIELP",
      dbglog_pcielp_print_handler_states,
      5,
      dbglog_pcielp_print_handler_events,
      9);
  return a3 == 1000;
}
