const char *__fastcall mac_trace_get_lim_mlm_state(unsigned __int16 a1)
{
  if ( a1 > 0x16u )
    return "UNKNOWN";
  else
    return off_A16610[a1];
}
