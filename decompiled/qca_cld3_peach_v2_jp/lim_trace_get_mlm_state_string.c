const char *__fastcall lim_trace_get_mlm_state_string(unsigned int a1)
{
  if ( a1 > 0x1C )
    return "UNKNOWN";
  else
    return off_A0A270[a1];
}
