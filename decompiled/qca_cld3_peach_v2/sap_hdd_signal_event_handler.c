__int64 __fastcall sap_hdd_signal_event_handler(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  if ( a1 )
    return sap_signal_hdd_event(a1, 0, *(unsigned int *)(a1 + 1616), *(unsigned int *)(a1 + 1620));
  else
    return qdf_trace_msg(
             0x39u,
             2u,
             "%s: sap context is not valid",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "sap_hdd_signal_event_handler");
}
