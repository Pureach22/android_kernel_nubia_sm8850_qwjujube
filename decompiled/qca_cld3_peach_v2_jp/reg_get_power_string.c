const char *__fastcall reg_get_power_string(unsigned int a1)
{
  if ( a1 > 3 )
    return "INVALID";
  else
    return off_9E06C8[a1];
}
