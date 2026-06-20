__int64 __fastcall dp_srng_find_ring_in_mask(char a1, unsigned __int8 *a2)
{
  int v2; // w8

  v2 = 1 << a1;
  if ( ((1 << a1) & *a2) != 0 )
    return 0;
  if ( ((unsigned __int8)v2 & a2[1]) != 0 )
    return 1;
  if ( ((unsigned __int8)v2 & a2[2]) != 0 )
    return 2;
  if ( ((unsigned __int8)v2 & a2[3]) != 0 )
    return 3;
  if ( ((unsigned __int8)v2 & a2[4]) != 0 )
    return 4;
  if ( ((unsigned __int8)v2 & a2[5]) != 0 )
    return 5;
  if ( ((unsigned __int8)v2 & a2[6]) != 0 )
    return 6;
  if ( ((unsigned __int8)v2 & a2[7]) != 0 )
    return 7;
  if ( ((unsigned __int8)v2 & a2[8]) != 0 )
    return 8;
  if ( ((unsigned __int8)v2 & a2[9]) != 0 )
    return 9;
  if ( ((unsigned __int8)v2 & a2[10]) != 0 )
    return 10;
  if ( ((unsigned __int8)v2 & a2[11]) != 0 )
    return 11;
  if ( ((unsigned __int8)v2 & a2[12]) != 0 )
    return 12;
  if ( ((unsigned __int8)v2 & a2[13]) != 0 )
    return 13;
  if ( ((unsigned __int8)v2 & a2[14]) != 0 )
    return 14;
  if ( ((unsigned __int8)v2 & a2[15]) != 0 )
    return 15;
  if ( ((unsigned __int8)v2 & a2[16]) != 0 )
    return 16;
  if ( ((unsigned __int8)v2 & a2[17]) != 0 )
    return 17;
  return 4294967279LL;
}
