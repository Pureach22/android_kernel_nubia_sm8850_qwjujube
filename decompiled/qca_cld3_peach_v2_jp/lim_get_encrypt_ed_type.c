__int64 __fastcall lim_get_encrypt_ed_type(unsigned int a1)
{
  if ( a1 == -1 )
    return 0;
  if ( (a1 & 0x400) != 0 )
    return 8;
  if ( (a1 & 0x200) != 0 )
    return 7;
  if ( (a1 & 0x8C) != 0 )
    return 4;
  if ( (a1 & 2) != 0 )
    return 3;
  if ( (a1 & 0x140) != 0 )
    return 6;
  if ( (a1 & 0x2010) != 0 )
    return 5;
  if ( (a1 & 0x800) != 0 )
    return 9;
  if ( (a1 & 0x1000) != 0 )
    return 10;
  if ( (a1 & 0x8001) != 0 )
    return 1;
  return (a1 >> 15) & 2;
}
