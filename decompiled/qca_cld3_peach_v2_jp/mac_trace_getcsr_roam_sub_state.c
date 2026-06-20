const char *__fastcall mac_trace_getcsr_roam_sub_state(unsigned __int16 a1)
{
  if ( a1 > 5u )
    return "UNKNOWN";
  else
    return off_A16558[a1];
}
