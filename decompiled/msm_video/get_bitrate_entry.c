__int64 __fastcall get_bitrate_entry(unsigned int a1)
{
  if ( a1 > 0x76A6FFFF )
    return 1;
  if ( a1 > 0x58FD3FFF )
    return 2;
  if ( a1 > 0x3B537FFF )
    return 3;
  if ( a1 > 0x2C7E9FFF )
    return 4;
  if ( a1 > 0x1DA9BFFF )
    return 5;
  if ( a1 > 0xED4DFFF )
    return 6;
  if ( a1 > 0x76A6FFF )
    return 7;
  if ( a1 > 0x3B537FF )
    return 8;
  return 9;
}
