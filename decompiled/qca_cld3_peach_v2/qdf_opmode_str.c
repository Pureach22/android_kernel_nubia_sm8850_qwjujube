const char *__fastcall qdf_opmode_str(unsigned int a1)
{
  if ( a1 > 0x10 )
    return "Invalid operating mode";
  else
    return off_AD05F8[a1];
}
