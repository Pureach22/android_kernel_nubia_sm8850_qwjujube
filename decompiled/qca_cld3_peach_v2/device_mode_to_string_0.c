const char *__fastcall device_mode_to_string_0(unsigned int a1)
{
  if ( a1 > 6 )
    return "Unknown";
  else
    return off_AD9240[a1];
}
