const char *__fastcall if_mgr_get_event_str(unsigned int a1)
{
  if ( a1 > 0x19 )
    return (const char *)&unk_98C763;
  if ( a1 == 25 )
    return "Unknown";
  return off_AD0918[a1];
}
