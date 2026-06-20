const char *__fastcall hc_id_to_string(unsigned int a1)
{
  if ( a1 > 0x10 )
    return "Unknown";
  else
    return off_B32E90[a1];
}
