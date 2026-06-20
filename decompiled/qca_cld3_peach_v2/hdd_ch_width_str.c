const char *__fastcall hdd_ch_width_str(unsigned int a1)
{
  if ( a1 > 7 )
    return "UNKNOWN";
  else
    return *((const char **)*(&off_AF9940 + a1) + 2);
}
