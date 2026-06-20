bool __fastcall reg_is_range_overlap_5g(unsigned int a1, unsigned int a2)
{
  bool v4; // w8

  if ( a1 - 5170 < 0x2D6 )
    return 1;
  v4 = a1 < 0x1433 || a2 >> 3 < 0x2E1;
  if ( a2 >> 1 >= 0xA19 && v4 )
    return 1;
  return a1 >> 3 < 0x2E1 && a2 > 0x1706;
}
