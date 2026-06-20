const char *__fastcall mac_trace_get_lim_sme_state(unsigned __int16 a1)
{
  if ( a1 > 0x10u )
    return "UNKNOWN";
  else
    return off_A16588[a1];
}
