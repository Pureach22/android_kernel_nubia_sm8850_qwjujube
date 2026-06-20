__int64 __fastcall hdd_convert_dot11mode_from_phymode(unsigned int a1)
{
  if ( a1 < 0x10 )
    return dword_AF8260[a1];
  if ( (a1 & 0xFFFFFFF8) == 0x10 )
    return 5;
  return 7;
}
