__int64 __fastcall reg_band_bitmap_to_band_info(char a1)
{
  __int64 result; // x0
  __int64 v3; // x9
  char v4; // w10
  int v5; // w11
  unsigned int v6; // w8

  if ( (~a1 & 7) == 0 )
    return 0;
  result = 2;
  if ( (~a1 & 6) != 0 )
  {
    v3 = a1 & 3;
    v4 = ~a1;
    v5 = v3 != 3;
    if ( (a1 & 1) == 0 )
      v5 = 2;
    if ( (a1 & 4) != 0 )
      v6 = 1;
    else
      v6 = 3;
    if ( v3 )
      v6 = v5;
    if ( (v4 & 5) != 0 )
      return v6;
    else
      return 1;
  }
  return result;
}
