const char *__fastcall lim_bss_type_to_string(unsigned __int16 a1)
{
  if ( a1 > 4u )
    return "Unknown bss_type";
  else
    return off_A0A660[a1];
}
