__int64 __fastcall set_omi_ch_width(int a1, unsigned int *a2)
{
  bool v3; // cc
  __int64 result; // x0
  unsigned int v5; // w8

  v3 = a1 <= 2;
  result = 4;
  if ( v3 )
  {
    if ( a1 )
    {
      if ( a1 == 1 )
      {
        v5 = *a2 & 0xFFFFF9FF | 0x200;
      }
      else
      {
        if ( a1 != 2 )
          return result;
        v5 = *a2 & 0xFFFFF9FF | 0x400;
      }
    }
    else
    {
      v5 = *a2 & 0xFFFFF9FF;
    }
  }
  else if ( (unsigned int)(a1 - 3) >= 2 )
  {
    if ( a1 != 7 )
      return result;
    v5 = *a2 | 0x80000;
  }
  else
  {
    v5 = *a2 | 0x600;
  }
  *a2 = v5;
  return 0;
}
