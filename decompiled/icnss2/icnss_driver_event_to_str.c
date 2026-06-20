const char *__fastcall icnss_driver_event_to_str(unsigned int a1)
{
  if ( a1 > 0x12 )
    return "UNKNOWN";
  else
    return off_A8830[a1];
}
