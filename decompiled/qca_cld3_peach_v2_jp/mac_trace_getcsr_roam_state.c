const char *__fastcall mac_trace_getcsr_roam_state(unsigned __int16 a1)
{
  if ( a1 > 3u )
    return "UNKNOWN";
  else
    return off_A16538[a1];
}
