__int64 __fastcall dbglog_beacon_print_handler(
        __int64 a1,
        __int64 a2,
        int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int *a6)
{
  __int64 result; // x0

  result = 0;
  if ( a3 > 4 )
  {
    if ( a3 > 6 )
    {
      if ( a3 == 7 )
      {
        if ( (unsigned __int16)a5 == 1 )
          dbglog_printf(a4, a2, "early_rx bcn type:%d", *a6);
      }
      else
      {
        if ( a3 != 1000 )
          return result;
        dbglog_sm_print(
          a4,
          a2,
          a5,
          a6,
          "EARLY_RX",
          dbglog_beacon_print_handler_states,
          4,
          dbglog_beacon_print_handler_events,
          8);
      }
    }
    else if ( a3 == 5 )
    {
      if ( (unsigned __int16)a5 == 1 )
        dbglog_printf(a4, a2, "early_rx clk drift:%d", *a6);
    }
    else if ( (unsigned __int16)a5 == 1 )
    {
      dbglog_printf(a4, a2, "early_rx ap drift:%d", *a6);
    }
  }
  else if ( a3 > 2 )
  {
    if ( a3 == 3 )
    {
      if ( (unsigned __int16)a5 == 1 )
        dbglog_printf(a4, a2, "early_rx cont bmiss timeout,update sleep_slop:%d", *a6);
    }
    else if ( (unsigned __int16)a5 == 1 )
    {
      dbglog_printf(a4, a2, "early_rx skip bcn num:%d", *a6);
    }
  }
  else if ( a3 == 1 )
  {
    if ( (unsigned __int16)a5 == 3 )
      dbglog_printf(a4, a2, "early_rx bmiss status:rcv=%d total=%d miss=%d", *a6, a6[1], a6[2]);
  }
  else
  {
    if ( a3 != 2 )
      return result;
    if ( (unsigned __int16)a5 == 1 )
      dbglog_printf(a4, a2, "early_rx update sleep_slop:%d", *a6);
  }
  return 1;
}
