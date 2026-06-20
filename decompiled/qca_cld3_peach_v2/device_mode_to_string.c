const char *__fastcall device_mode_to_string(unsigned int a1)
{
  if ( a1 > 6 )
    return "Unknown";
  else
    return off_AD91A0[a1];
}
