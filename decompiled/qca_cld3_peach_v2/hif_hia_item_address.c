__int64 __fastcall hif_hia_item_address(int a1, int a2)
{
  bool v3; // zf
  bool v4; // nf
  bool v5; // vf
  __int64 result; // x0

  v5 = __OFSUB__(a1, 7);
  v3 = a1 == 7;
  v4 = a1 - 7 < 0;
  result = 0;
  if ( v4 ^ v5 | v3 )
  {
    if ( a1 <= 4 )
    {
      if ( a1 == 2 )
      {
        return (unsigned int)(a2 + 5243904);
      }
      else if ( a1 == 3 )
      {
        return (unsigned int)(a2 + 5506560);
      }
    }
    else if ( a1 == 5 || a1 == 6 || a1 == 7 )
    {
      return (unsigned int)(a2 + 4196352);
    }
  }
  else
  {
    if ( a1 > 11 )
    {
      if ( a1 != 12 && a1 != 15 && a1 != 17 )
        return result;
      return (unsigned int)(a2 + 4196352);
    }
    if ( a1 == 8 || a1 == 9 )
      return (unsigned int)(a2 + 4196352);
  }
  return result;
}
