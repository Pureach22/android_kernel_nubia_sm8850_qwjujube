const char *__fastcall buf_region_name(char a1)
{
  if ( (a1 & 2) != 0 )
    return "NON_SECURE";
  if ( (a1 & 4) != 0 )
    return "NON_SECURE_BITSTREAM";
  if ( (a1 & 8) != 0 )
    return "NON_SECURE_PIXEL";
  if ( (a1 & 0x40) != 0 )
    return "SECURE_PIXEL";
  if ( (a1 & 0x10) != 0 )
    return "SECURE_NONPIXEL";
  if ( (a1 & 0x20) != 0 )
    return "SECURE_BITSTREAM";
  return "NONE";
}
