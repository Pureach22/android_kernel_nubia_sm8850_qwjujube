const char *__fastcall device_mode_to_string_1(unsigned int a1)
{
  if ( a1 > 6 )
    return "Unknown";
  else
    return off_B32E58[a1];
}
