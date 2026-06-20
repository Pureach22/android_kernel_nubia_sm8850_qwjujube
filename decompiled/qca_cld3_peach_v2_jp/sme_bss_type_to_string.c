const char *__fastcall sme_bss_type_to_string(unsigned __int8 a1)
{
  if ( a1 > 3u )
    return "unknown bss type";
  else
    return off_A17820[a1];
}
