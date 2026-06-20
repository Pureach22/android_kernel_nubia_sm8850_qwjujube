bool __fastcall reg_is_range_overlap_2g(unsigned int a1, unsigned int a2)
{
  bool v4; // w8

  if ( a1 - 2402 < 0x5D )
    return 1;
  v4 = a1 < 0x963 || a2 < 0x9BF;
  if ( a2 >= 0x962 && v4 )
    return 1;
  return a1 < 0x9BF && a2 > 0x9BD;
}
