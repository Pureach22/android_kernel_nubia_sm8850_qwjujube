const char *__fastcall hdd_ch_width_str(unsigned int a1)
{
  if ( a1 > 6 )
    return "UNKNOWN";
  else
    return *((const char **)*(&off_A078F0 + a1) + 2);
}
