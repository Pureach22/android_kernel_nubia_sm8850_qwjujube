const char *__fastcall icnss_soc_wake_event_to_str(unsigned int a1)
{
  if ( a1 > 2 )
    return "UNKNOWN";
  else
    return off_A88C8[a1];
}
