const char *__fastcall reg_get_power_string(unsigned int a1)
{
  if ( a1 > 3 )
    return "INVALID";
  else
    return off_AD2378[a1];
}
