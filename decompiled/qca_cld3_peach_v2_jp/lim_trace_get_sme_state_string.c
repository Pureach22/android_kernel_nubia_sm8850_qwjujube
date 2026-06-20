const char *__fastcall lim_trace_get_sme_state_string(unsigned int a1)
{
  if ( a1 > 0x10 )
    return "UNKNOWN";
  else
    return off_A0A358[a1];
}
