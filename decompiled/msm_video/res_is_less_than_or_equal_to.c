bool __fastcall res_is_less_than_or_equal_to(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // w9

  if ( a3 <= a4 )
    v4 = a4;
  else
    v4 = a3;
  return v4 >= a1 && v4 >= a2 && ((a2 + 15) >> 4) * ((a1 + 15) >> 4) <= ((a4 + 15) >> 4) * ((a3 + 15) >> 4);
}
