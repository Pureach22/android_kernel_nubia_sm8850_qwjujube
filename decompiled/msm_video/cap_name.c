const char *__fastcall cap_name(unsigned int a1)
{
  if ( a1 <= 0xC5 )
    return cap_name_arr[a1];
  else
    return "UNKNOWN CAP";
}
